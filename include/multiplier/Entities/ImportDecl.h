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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class Decl;
class ImportDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ImportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ImportDecl> in(const Fragment &frag);
  static gap::generator<ImportDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::IMPORT;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<ImportDecl> containing(const Decl &decl);
  static gap::generator<ImportDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ImportDecl> redeclarations(void) const;
  inline static std::optional<ImportDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ImportDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ImportDecl> from(const Decl &parent);

  inline static std::optional<ImportDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ImportDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Token> nth_identifier_token(unsigned n) const;
  gap::generator<Token> identifier_tokens(void) const;
};

static_assert(sizeof(ImportDecl) == sizeof(Decl));

#endif
} // namespace mx
