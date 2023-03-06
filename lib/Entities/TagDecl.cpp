// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TagDecl.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/Entities/ClassTemplateSpecializationDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/EnumDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeDecl.h>
#include <multiplier/Entities/TypedefNameDecl.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TagDecl> TagDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TagDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TagDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TagDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TagDecl> TagDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TagDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TagDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TagDecl::contains(const Decl &decl) {
  for (auto &parent : TagDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool TagDecl::contains(const Stmt &stmt) {
  for (auto &parent : TagDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<TagDecl> TagDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TagDecl> dr = TagDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TagDecl> TagDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return TagDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kTagDeclDerivedKinds[] = {
    EnumDecl::static_kind(),
    RecordDecl::static_kind(),
    CXXRecordDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<TagDecl> TagDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case EnumDecl::static_kind():
    case RecordDecl::static_kind():
    case CXXRecordDecl::static_kind():
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const TagDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TagDecl> TagDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kTagDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TagDecl> e = TagDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TagDecl> TagDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTagDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TagDecl> e = TagDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TagDecl> TagDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTagDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TagDecl> e = TagDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

TokenRange TagDecl::brace_range(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal53(), impl->reader.getVal54());
}

Token TagDecl::first_inner_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal62());
}

Token TagDecl::first_outer_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal63());
}

TagTypeKind TagDecl::tag_kind(void) const {
  return static_cast<TagTypeKind>(impl->reader.getVal74());
}

std::optional<TypedefNameDecl> TagDecl::typedef_name_for_anonymous_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal64();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TypedefNameDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool TagDecl::has_name_for_linkage(void) const {
  return impl->reader.getVal70();
}

bool TagDecl::is_being_defined(void) const {
  return impl->reader.getVal71();
}

bool TagDecl::is_class(void) const {
  return impl->reader.getVal72();
}

bool TagDecl::is_complete_definition(void) const {
  return impl->reader.getVal88();
}

bool TagDecl::is_complete_definition_required(void) const {
  return impl->reader.getVal89();
}

bool TagDecl::is_dependent_type(void) const {
  return impl->reader.getVal90();
}

bool TagDecl::is_embedded_in_declarator(void) const {
  return impl->reader.getVal91();
}

bool TagDecl::is_enum(void) const {
  return impl->reader.getVal92();
}

bool TagDecl::is_free_standing(void) const {
  return impl->reader.getVal93();
}

bool TagDecl::is_interface(void) const {
  return impl->reader.getVal94();
}

bool TagDecl::is_struct(void) const {
  return impl->reader.getVal95();
}

bool TagDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal96();
}

bool TagDecl::is_this_declaration_a_demoted_definition(void) const {
  return impl->reader.getVal97();
}

bool TagDecl::is_union(void) const {
  return impl->reader.getVal98();
}

bool TagDecl::may_have_out_of_date_definition(void) const {
  return impl->reader.getVal99();
}

std::optional<TemplateParameterList> TagDecl::nth_template_parameter_list(unsigned n) const {
  auto list = impl->reader.getVal47();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateParameterListFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateParameterList(std::move(e));
}

gap::generator<TemplateParameterList> TagDecl::template_parameter_lists(void) const & {
  auto list = impl->reader.getVal47();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d47 = ep->TemplateParameterListFor(ep, v)) {
      co_yield TemplateParameterList(std::move(d47));
    }
  }
  co_return;
}

gap::generator<Decl> TagDecl::declarations_in_context(void) const & {
  EntityProvider::Ptr ep = impl->ep;
  auto list = impl->reader.getVal48();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx