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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXPseudoDestructorExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXPseudoDestructorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXPseudoDestructorExpr> in(const Fragment &frag);
  static gap::generator<CXXPseudoDestructorExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<CXXPseudoDestructorExpr> containing(const Decl &decl);
  static gap::generator<CXXPseudoDestructorExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXPseudoDestructorExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXPseudoDestructorExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXPseudoDestructorExpr> from(const Expr &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXPseudoDestructorExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXPseudoDestructorExpr> from(const Stmt &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Token colon_colon_token(void) const;
  Type destroyed_type(void) const;
  Token destroyed_type_token(void) const;
  Token operator_token(void) const;
  std::optional<Type> scope_type(void) const;
  Token tilde_token(void) const;
  bool has_qualifier(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(CXXPseudoDestructorExpr) == sizeof(Expr));

#endif
} // namespace mx
