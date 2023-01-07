// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Decl.h"
#include "DeclKind.h"
#include "ObjCPropertyImplDeclKind.h"

namespace mx {
class Decl;
class Expr;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCPropertyImplDeclRange = DerivedEntityRange<DeclIterator, ObjCPropertyImplDecl>;
using ObjCPropertyImplDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCPropertyImplDecl>;
using ObjCPropertyImplDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCPropertyImplDecl>;

class ObjCPropertyImplDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ObjCPropertyImplDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCPropertyImplDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCPropertyImplDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_PROPERTY_IMPL;
  }

  static ObjCPropertyImplDeclContainingDeclRange containing(const Decl &decl);
  static ObjCPropertyImplDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCPropertyImplDecl> from(const TokenContext &c);
  static std::optional<ObjCPropertyImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCPropertyImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCPropertyImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr getter_cxx_constructor(void) const;
  ObjCMethodDecl getter_method_declaration(void) const;
  ObjCPropertyDecl property_declaration(void) const;
  ObjCPropertyImplDeclKind property_implementation(void) const;
  ObjCIvarDecl property_instance_variable_declaration(void) const;
  Token property_instance_variable_declaration_token(void) const;
  Expr setter_cxx_assignment(void) const;
  ObjCMethodDecl setter_method_declaration(void) const;
  bool is_instance_variable_name_specified(void) const;
};

static_assert(sizeof(ObjCPropertyImplDecl) == sizeof(Decl));

#endif
} // namespace mx