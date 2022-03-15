// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <algorithm>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <map>
#include <multiplier/AST.capnp.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "Context.h"
#include "Hash.h"
#include "PrintTokenGraph.h"
#include "TokenizeFile.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {
namespace {

// Find all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 private:
  std::vector<pasta::Decl> &tlds;

  // Tracks declarations for which we've seen the specializations. This is
  // to prevent us from double-adding specializations.
  std::unordered_set<pasta::Decl> seen_specs;

 public:
  virtual ~TLDFinder(void) = default;

  explicit TLDFinder(std::vector<pasta::Decl> &tlds_)
      : tlds(tlds_) {}


  void VisitDeclContext(const pasta::DeclContext &dc) {;
    for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
      Accept(decl);
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &) final {
    // Do nothing.
  }

  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &) final {
    // Do nothing.
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &decl) final {
    if (seen_specs.emplace(decl.CanonicalDeclaration()).second) {
      for (auto spec : decl.Specializations()) {

        // We should observe the explicit specializations and instantiations
        // separately.
        switch (spec.TemplateSpecializationKind()) {
          case pasta::TemplateSpecializationKind::kExplicitSpecialization:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition:
            continue;
          default:
            Accept(spec);
        }
      }
    }
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &var) final {
    // Do nothing; we will see the specializations as top-level declarations.
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &decl) final {
    if (seen_specs.emplace(decl.CanonicalDeclaration()).second) {
      for (auto spec : decl.Specializations()) {

        // We should observe the explicit specializations and instantiations
        // separately.
        switch (spec.TemplateSpecializationKind()) {
          case pasta::TemplateSpecializationKind::kExplicitSpecialization:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition:
            continue;
          default:
            Accept(spec);
        }
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    for (auto params : decl.TemplateParameterLists()) {
      if (params.NumParameters() || params.HasUnexpandedParameterPack()) {
        return;
      }
    }

    VisitDecl(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    if (!decl.IsImplicit()) {
      tlds.emplace_back(decl);
    }
  }
};

enum class EntityKind : uint16_t {
  kDeclaration,
  kStatement,
  kType
};

struct EntityId {
  mx::CodeId code_id;
  uint32_t entity_offset;  // In a list.
  uint16_t entity_kind;
  uint16_t entity_sub_kind;
};

// Labels entities (decls, stmts, types, tokens). The idea here is that in
// `ast::EntityList`, which is derived from a Cap'n Proto schema, we have a
// bunch of lists of different types of entities (decls, stmts, etc.). We index
// code at the granularity of "code chunks," which contain one or more top-level
// declarations. Each code chunk has a unique code ID, and there is an
// `ast::EntityList` associated with each code chunk. We'd like to be able to
// reference across code chunks, and to do so deterministically. The way we do
// this is that we assign IDs to each entity in a deterministic way for each
// code chunk, so then we we go and build the serialized form of a code chunk,
// then we can just use these IDs to build up the references and know that
// things will generally work out. One trick is our IDs are compound: they
// include the code chunk ID, the entity kind, the entity sub-kind, and then
// the offset in one of the many `List(...)` types inside of the
// `ast::EntityList`. This way, it's easy to identify exactly which entity we
// need to reference inside of an entity list.
class EntityLabeller final : protected pasta::DeclVisitor,
                             protected pasta::StmtVisitor,
                             protected pasta::TypeVisitor {
 private:
  mx::CodeId code_id{0u};
  std::unordered_map<const void *, EntityId> entity_id;
  std::map<std::pair<mx::CodeId, pasta::DeclKind>, uint32_t> next_decl_offset;
  std::map<std::pair<mx::CodeId, pasta::StmtKind>, uint32_t> next_stmt_offset;
//  std::map<std::pair<mx::CodeId, pasta::TypeKind>, uint32_t> next_type_offset;

  bool Label(const pasta::Decl &entity) {
    auto kind = entity.Kind();
    auto &next_offset = next_decl_offset[{code_id, kind}];
    EntityId id{
        code_id,
        next_offset,
        static_cast<uint16_t>(EntityKind::kDeclaration),
        static_cast<uint16_t>(kind)};

    if (entity_id.emplace(entity.RawDecl(), id).second) {
      ++next_offset;
      return true;
    } else {
      return false;
    }
  }

  bool Label(const pasta::Stmt &entity) {
    auto kind = entity.Kind();
    auto &next_offset = next_stmt_offset[{code_id, kind}];
    EntityId id{
        code_id,
        next_offset,
        static_cast<uint16_t>(EntityKind::kStatement),
        static_cast<uint16_t>(kind)};

    if (entity_id.emplace(entity.RawStmt(), id).second) {
      ++next_offset;
      return true;
    } else {
      return false;
    }
  }

//  bool Label(const pasta::Type &entity) {
//    auto kind = entity.Kind();
//    auto &next_offset = next_decl_offset[{code_id, kind}];
//    EntityId id{
//        code_id,
//        next_offset,
//        static_cast<uint16_t>(EntityKind::kType),
//        static_cast<uint16_t>(kind)};
//
//    if (entity_id.emplace(entity, id).second) {
//      ++next_offset;
//      return true;
//    } else {
//      return false;
//    }
//  }


  void VisitDeclContext(const pasta::DeclContext &dc) {;
    for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
      this->DeclVisitor::Accept(decl);
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    assert(false);
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    assert(false);
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    assert(false);
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    assert(false);
    VisitDeclContext(decl);
  }

  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &) final {}
  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &) final {}
  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &) final {}
  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &) final {}
  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &) final {}

  void VisitVarDecl(const pasta::VarDecl &decl) final {
    if (Label(decl)) {
      if (auto init_expr = decl.Initializer()) {
        this->StmtVisitor::Accept(*init_expr);
      }
    }
  }

  void VisitParmVarDecl(const pasta::ParmVarDecl &decl) final {
    if (Label(decl)) {
      if (!decl.HasUninstantiatedDefaultArgument() &&
          !decl.HasUnparsedDefaultArgument()) {
        if (auto init_expr = decl.DefaultArgument()) {
          this->StmtVisitor::Accept(*init_expr);
        }
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    if (Label(decl)) {
      VisitDeclContext(decl);
      for (pasta::ParmVarDecl param : decl.Parameters()) {
        this->DeclVisitor::Accept(param);
      }
      if (decl.DoesThisDeclarationHaveABody()) {
        this->StmtVisitor::Accept(decl.Body());
      }
    }
  }

  void VisitFieldDecl(const pasta::FieldDecl &decl) final {
    if (Label(decl)) {
      if (auto bit_width = decl.BitWidth()) {
        this->StmtVisitor::Accept(*bit_width);
      }
      if (auto init = decl.InClassInitializer()) {
        this->StmtVisitor::Accept(*init);
      }
    }
  }

  // Structs, unions, etc.
  void VisitRecordDecl(const pasta::RecordDecl &decl) final {
    if (Label(decl)) {
      VisitDeclContext(decl);
      for (pasta::FieldDecl field : decl.Fields()) {
        this->DeclVisitor::Accept(field);
      }
    }
  }

  void VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) final {
    if (Label(decl)) {
      if (auto init = decl.InitializerExpression()) {
        this->StmtVisitor::Accept(*init);
      }
    }
  }

  // Enumerators.
  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    if (Label(decl)) {
      VisitDeclContext(decl);
      for (pasta::EnumConstantDecl enumerator : decl.Enumerators()) {
        this->DeclVisitor::Accept(enumerator);
      }
    }
  }

  void VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) final {
    if (Label(stmt)) {
      for (auto child : stmt.InputConstraintLiterals()) {
        this->StmtVisitor::Accept(child);
      }
      for (auto child : stmt.InputExpressions()) {
        this->StmtVisitor::Accept(child);
      }
      for (auto child : stmt.OutputConstraintLiterals()) {
        this->StmtVisitor::Accept(child);
      }
      for (auto child : stmt.OutputExpressions()) {
        this->StmtVisitor::Accept(child);
      }
      for (auto child : stmt.Children()) {
        this->StmtVisitor::Accept(child);
      }
    }
  }

  void VisitMSAsmStmt(const pasta::MSAsmStmt &stmt) final {
    if (Label(stmt)) {
      for (auto child : stmt.AllExpressions()) {
        this->StmtVisitor::Accept(child);
      }
      for (auto child : stmt.InputExpressions()) {
        this->StmtVisitor::Accept(child);
      }
    }
  }

  void VisitBreakStmt(const pasta::BreakStmt &stmt) final {
    if (Label(stmt)) {
      for (auto child : stmt.Children()) {
        this->StmtVisitor::Accept(child);
      }
    }
  }

  void VisitCompoundStmt(const pasta::CompoundStmt &stmt) final {
    if (Label(stmt)) {
      for (pasta::Stmt child : stmt.Children()) {
        this->StmtVisitor::Accept(child);
      }
    }
  }

  void VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) final {
    if (Label(decl)) {
      if (auto tag = decl.AnonymousDeclarationWithTypedefName()) {
        this->DeclVisitor::Accept(*tag);
      }
    }
  }

  // Backups.
  void VisitDecl(const pasta::Decl &decl) final {
    (void) Label(decl);
  }

  void VisitStmt(const pasta::Stmt &stmt) final {
    if (Label(stmt)) {
      for (auto child : stmt.Children()) {
        Label(child);
      }
    }
  }

 public:
  virtual ~EntityLabeller(void) = default;

  void EnterCode(mx::CodeId code_id_, const std::vector<pasta::Decl> &tlds) {
    code_id = code_id_;
    for (const pasta::Decl &tld : tlds) {
      this->DeclVisitor::Accept(tld);
    }
  }
};

// Find all top-level declarations.
static std::vector<pasta::Decl> FindTLDs(pasta::TranslationUnitDecl tu) {
  std::vector<pasta::Decl> tlds;
  TLDFinder tld_finder(tlds);
  tld_finder.VisitTranslationUnitDecl(tu);
  return tlds;
}

// Return `true` of `tok` is in the context of `decl`.
static bool TokenIsInContextOfDecl(const pasta::Token &tok,
                                   const pasta::Decl &decl) {
  auto cdecl = decl.CanonicalDeclaration();
  for (auto context = tok.Context(); context; context = context->Parent()) {
    if (auto maybe_decl = pasta::Decl::From(*context)) {
      if (*maybe_decl == cdecl) {
        return true;
      }
    }
  }
  return false;
}

// Print a declaration; useful for error reporting.
static std::string DeclToString(const pasta::Decl &decl) {
  std::stringstream ss;
  auto sep = "";
  for (auto ptok : pasta::PrintedTokenRange::Create(decl)) {
    ss << sep << ptok.Data();
    sep = " ";
  }
  return ss.str();
}

// Return the name of a declaration with a leading `prefix`, or nothing.
static std::string PrefixedName(const pasta::Decl &decl,
                                const char *prefix=" ") {
  if (auto nd = pasta::NamedDecl::From(decl)) {
    auto name = nd->Name();
    if (!name.empty()) {
      return prefix + name;
    }
  }
  return "";
}

// Return the location of a declaration with a leading `prefix`, or nothing.
static std::string PrefixedLocation(const pasta::Decl &decl,
                                    const char *prefix=" ") {
  auto ft = decl.Token().FileLocation();
  if (!ft) {
    for (auto tok : decl.TokenRange()) {
      ft = decl.Token().FileLocation();
      if (ft) {
        break;
      }
    }
  }
  if (ft) {
    auto file = pasta::File::Containing(*ft);
    std::stringstream ss;
    ss << prefix << file.Path().generic_string()
       << ':' << ft->Line() << ':' << ft->Column();
    return ss.str();
  }
  return "";
}

// Can we elide this token from the beginning or end of a top-level
// declaration's range of tokens?
static bool CanElideTokenFromTLD(pasta::Token tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:
      return true;

    case pasta::TokenRole::kFileToken:
      switch (tok.Kind()) {
        case pasta::TokenKind::kComment:
        case pasta::TokenKind::kEndOfFile:
        case pasta::TokenKind::kEndOfDirective:
        case pasta::TokenKind::kCodeCompletion:
          return true;
        case pasta::TokenKind::kUnknown:
          return IsWhitespaceOrEmpty(tok.Data());
        default:
          return false;
      }
    default:
      return false;
  }
}

// Do some minor stuff to find begin/ending tokens.
static std::pair<uint64_t, uint64_t> BaselineDeclRange(
    const pasta::Decl &decl, pasta::Token tok, std::string_view main_file_path) {
  DCHECK(tok);  // Make sure we're dealing with a valid token.

  auto decl_range = decl.TokenRange();
  const auto tok_index = tok.Index();
  auto begin_tok_index = tok_index;
  auto end_tok_index = tok_index;

  if (decl_range.Size()) {
    begin_tok_index = decl_range.begin()->Index();
    end_tok_index = (--decl_range.end())->Index();

    // NOTE(pag): This is more of an indication that we probably need to fix
    //            something in PASTA.
    if (!(begin_tok_index <= tok_index && tok_index <= end_tok_index)) {
      DLOG(ERROR)
          << "Location of " << decl.KindName()
          << " declaration: " << DeclToString(decl)
          << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path
          << " is not within declaration bounds";
    }
  }

  return {begin_tok_index, end_tok_index};
}

// Find the range of tokens of this decl.
static std::pair<uint64_t, uint64_t> FindDeclRange(
    const pasta::TokenRange &range, pasta::Decl decl, pasta::Token tok,
    std::string_view main_file_path) {

  auto [begin_tok_index, end_tok_index] = BaselineDeclRange(decl, tok,
                                                            main_file_path);

  const auto max_tok_index = range.Size();

  // We should always at least hit the end of file marker token first.
  CHECK_LT(end_tok_index, max_tok_index);

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the ranges returns
  tok = range[begin_tok_index];
  bool in_macro = false;
  while (tok.Role() == pasta::TokenRole::kMacroExpansionToken) {
    tok = range[--begin_tok_index];
    in_macro = true;
  }
  if (!in_macro) {
    // Strip leading whitespace and comments.
    while (begin_tok_index < end_tok_index &&
           CanElideTokenFromTLD(range[begin_tok_index])) {
      ++begin_tok_index;
    }
  }

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the ranges returns
  tok = range[end_tok_index];
  in_macro = false;
  while (tok.Role() == pasta::TokenRole::kMacroExpansionToken) {
    tok = range[++end_tok_index];
    in_macro = true;
  }

  if (!in_macro) {
    // Strip trailing whitespace and comments.
    while (end_tok_index > begin_tok_index &&
           CanElideTokenFromTLD(range[end_tok_index])) {
      --end_tok_index;
    }
  }

  return {begin_tok_index, end_tok_index};
}

// Returns `true` if `decl` is probably a compiler-built-in declaration. It's
// not possible to get location information for these, unless we first printed
// out the compiler builtins to a file and then introduced those as a special
// preamble.
static bool IsProbablyABuiltinDecl(const pasta::Decl &decl) {
  if (decl.IsImplicit()) {
    return true;
  } else if (auto nd = pasta::NamedDecl::From(decl)) {
    if (nd->Name().starts_with("__")) {
      return true;
    }
  }
  return false;
}

// Should we even expect to find this declaration in the token contexts? There
// are cases where we shouldn't, e.g. with template instantiations, because the
// token contexts will just end up being associated with the templates
// themselves.
static bool ShouldFindDeclInTokenContexts(const pasta::Decl &decl) {
  auto tsk = pasta::TemplateSpecializationKind::kUndeclared;
  bool has_partial_or_tpl = true;

  if (auto csd = pasta::ClassTemplateSpecializationDecl::From(decl)) {
    tsk = csd->TemplateSpecializationKind();
    has_partial_or_tpl = !csd->SpecializedTemplateOrPartial().index();

  } else if (auto vsd = pasta::VarTemplateSpecializationDecl::From(decl)) {
    tsk = vsd->TemplateSpecializationKind();
    has_partial_or_tpl = !vsd->SpecializedTemplateOrPartial().index();

  } else if (auto fd = pasta::FunctionDecl::From(decl)) {
    tsk = fd->TemplateSpecializationKind();

  } else if (auto vd = pasta::VarDecl::From(decl)) {
    tsk = vd->TemplateSpecializationKind();

  } else if (auto ta = pasta::TypeAliasDecl::From(decl)) {
    if (ta->DescribedAliasTemplate()) {
      tsk = pasta::TemplateSpecializationKind::kImplicitInstantiation;  // Fake.
    }
  }

  if (tsk == pasta::TemplateSpecializationKind::kExplicitSpecialization) {
    return true;

  // NOTE(pag): Have observed situations where `ClassTemplateSpecialization`
  //            will report `kUndeclared`.
  } else if (tsk == pasta::TemplateSpecializationKind::kUndeclared) {
    return has_partial_or_tpl;

  } else {
    return false;
  }
}

}  // namespace

IndexCompileJobAction::~IndexCompileJobAction(void) {}

IndexCompileJobAction::IndexCompileJobAction(
    std::shared_ptr<IndexingContext> context_,
    pasta::FileManager file_manager_,
    pasta::CompileJob job_)
    : context(std::move(context_)),
      file_manager(std::move(file_manager_)),
      job(std::move(job_)) {}

// Look through all files referenced by the AST get their unique IDs. If this
// is the first time seeing a file, then tokenize the file.
void IndexCompileJobAction::MaybeTokenizeFile(
    const mx::Executor &exe, pasta::File file) {
  if (file.WasParsed()) {
    auto maybe_data = file.Data();
    auto file_path = file.Path();
    if (maybe_data.Succeeded()) {
      auto file_hash = FileHash(maybe_data.TakeValue());
      auto [file_id, is_new_file_id] = context->GetOrCreateFileId(
          file_path, file_hash);
      if (is_new_file_id) {
        exe.EmplaceAction<TokenizeFileAction>(
            context, file_id, file_hash, file);
      }

      file_ids.emplace(file, file_id);
      file_hashes.emplace(file, std::move(file_hash));

    } else {
      LOG(ERROR)
          << "Unable to get data for file '" << file_path.generic_string()
          << ": " << maybe_data.TakeError().message();
    }
  }
}

// Build and index the AST.
void IndexCompileJobAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  mx::ProgressBarWork progress_tracker(context->ast_progress.get());

  auto main_file_path = job.SourceFile().Path().generic_string();
  auto maybe_ast = job.Run();
  if (!maybe_ast.Succeeded()) {
    LOG(ERROR)
        << "Error building AST for command " << job.Arguments().Join()
        << " on main file " << main_file_path
        << "; error was: " << maybe_ast.TakeError();
    return;
  }

  auto ast = maybe_ast.TakeValue();
  for (pasta::File file : ast.ParsedFiles()) {
    MaybeTokenizeFile(exe, std::move(file));
  }

  using DeclRange = std::tuple<pasta::Decl, uint64_t, uint64_t>;
  std::vector<DeclRange> decl_ranges;
  decl_ranges.reserve(8192u);

  // TODO(pag): Handle top-level statements, e.g. `asm`, `static_assert`, etc.
  pasta::TokenRange tok_range = ast.Tokens();
  auto tlds = FindTLDs(ast.TranslationUnit());
  for (pasta::Decl decl : tlds) {
    if (decl.Kind() == pasta::DeclKind::kEmpty) {
      continue;
    }

    auto tok = decl.Token();

    // These are probably part of the preamble of compiler-provided builtin
    // declarations.
    if (!tok) {
      LOG_IF(WARNING, !IsProbablyABuiltinDecl(decl))
          << "Could not find location of " << decl.KindName()
          << " declaration: " << DeclToString(decl)
          << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;

    } else {

      // This suggests an error in PASTA, usually related to token alignment
      // against printed tokens. That process tries to "align" pretty-printed
      // decl tokens, which are full of contextual information, with parsed
      // tokens, which have no contextual information. We do this so that we
      // can get the contextual information from parsed tokens, which is often
      // more useful.
      LOG_IF(FATAL, ShouldFindDeclInTokenContexts(decl) &&
                    !TokenIsInContextOfDecl(tok, decl) &&
                    !IsProbablyABuiltinDecl(decl))
          << "Could not find location of " << decl.KindName()
          << " declaration: " << DeclToString(decl)
          << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;

      auto [begin_index, end_index] = FindDeclRange(tok_range, decl, tok,
                                                    main_file_path);

      // There should always be at least two tokens in any top-level decl.
      LOG_IF(ERROR, begin_index == end_index)
          << "Only found one token " << tok.Data() << " for: "
          << DeclToString(decl) << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;

      decl_ranges.emplace_back(decl, begin_index, end_index);
    }
  }

  // It's possible that we have two-or-more things that appear to be top-level
  // decls, but really we're only dealing with one top-level decl. This happens
  // with things like `typedef`s in Clang when the referenced type of a typedef
  // is defined within the typedef (e.g. a union/struct/enum type). In these
  // cases, Clang places the definition of the referenced type before the
  // typedef inside of the `DeclContext`, and so the referenced type appears
  // as its own top-level declaration, despite it being logically nested inside
  // of another top-level declaration.

  std::stable_sort(decl_ranges.begin(), decl_ranges.end(),
                   [] (const DeclRange &a, const DeclRange &b) {
                     auto a_begin = std::get<1>(a);
                     auto b_begin = std::get<1>(b);
                     if (a_begin < b_begin) {
                       return true;
                     } else if (a_begin > b_begin) {
                       return false;
                     } else {
                       return std::get<2>(a) < std::get<2>(b);
                     }
                   });

  EntityLabeller labeller;

  // Summary information about a group of top-level declarations that are
  // somehow lexically/syntactically "stuck together" and thus serialized
  // together. For example, `int optind, opterr, optopt;` is one example of
  // being syntactically stuck together. Another example would be a C macro
  // that expands into two separate top-level declarations. We don't want to
  // break this macro expansion into two, as in the original source file it
  // represents a single logical thing.
  struct CodeChunk {
    mx::CodeId code_id;
    std::vector<pasta::Decl> decls;
    uint64_t begin_index;
    uint64_t end_index;
  };

  std::vector<pasta::Decl> decls_for_chunk;
  std::vector<CodeChunk> code_chunks;

  for (size_t i = 0u, max_i = decl_ranges.size(); i < max_i; ) {
    auto [decl, begin_index, end_index] = std::move(decl_ranges[i++]);
    decls_for_chunk.clear();
    decls_for_chunk.push_back(decl);

    // Try to accumulate the nearby top-level declarations whose token ranges
    // overlap with `decl` into `decls_for_chunk`. For example, this process
    // will accumulate three `VarDecl`s into `decls_for_chunk` in the following
    // case:
    //
    //      int optind, opterr, optopt;
    //
    // This also happens when multiplier declarations are defined by macros,
    // as well as for template specializations.
    for (; i < max_i; ++i) {
      if (std::get<1>(decl_ranges[i]) <= end_index) {
        auto next_decl = std::get<0>(decl_ranges[i]);
        auto next_end = std::get<2>(decl_ranges[i]);

        if (next_decl == decl) {
          DLOG(FATAL)
              << "Declaration of " << decl.KindName()
              << PrefixedName(decl) << PrefixedLocation(decl, " at or near ")
              << " is repeated in top-level decl list for job on file "
              << " on main job file " << main_file_path;
        } else {
          decls_for_chunk.push_back(std::move(next_decl));
        }

        // Make sure we definitely enclose over the next decl.
        end_index = std::max(end_index, next_end);

      // Doesn't close over.
      } else {
        break;
      }
    }

    // Don't create token `decls_for_chunk` if the decl is already seen. This
    // means it's already been indexed.
    auto [code_id, is_new] = context->GetOrCreateCodeId(
        CodeHash(file_hashes, decls_for_chunk, tok_range,
                 begin_index, end_index));

    // We always need to enter the code for a chunk, regardless of if it
    // `is_new`. This is because each chunk might have arbitrary references to
    // other declarations. We need to be able to form cross-chunk references
    // when serializing things, so we use the labeller to assign IDs to entities
    // (decls, statements, etc.) in a uniform and deterministic way so that
    // other threads doing similar indexing will form identically labelled
    // chunks for the same logical entities.
    labeller.EnterCode(code_id, decls_for_chunk);

    if (is_new) {
      CodeChunk tree;
      tree.code_id = code_id;
      tree.decls = std::move(decls_for_chunk);
      tree.begin_index = begin_index;
      tree.end_index = end_index;
      code_chunks.emplace_back(std::move(tree));
    }
  }

  // Serialize the new code chunks.
  for (const CodeChunk &chunk : code_chunks) {
    const auto &[code_id, decls, begin_index, end_index] = chunk;
    const pasta::Decl &leader_decl = decls[0];
    mx::Result<TokenTree, std::string> maybe_tt = TokenTree::Create(
        tok_range, begin_index, end_index);
    if (maybe_tt.Succeeded()) {

    } else {
      LOG(ERROR)
          << maybe_tt.TakeError() << " for top-level declaration "
          << DeclToString(leader_decl)
          << PrefixedLocation(leader_decl, " at or near ")
          << " on main job file " << main_file_path;
    }
  }
}

}  // namespace indexer
