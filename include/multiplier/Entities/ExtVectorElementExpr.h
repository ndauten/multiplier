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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ExtVectorElementExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExtVectorElementExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExtVectorElementExpr> in(const Fragment &frag);
  static gap::generator<ExtVectorElementExpr> in(const Index &index);
  static gap::generator<ExtVectorElementExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ExtVectorElementExpr> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
  }

  static gap::generator<ExtVectorElementExpr> containing(const Decl &decl);
  static gap::generator<ExtVectorElementExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ExtVectorElementExpr> containing(const Stmt &stmt);
  static gap::generator<ExtVectorElementExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ExtVectorElementExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ExtVectorElementExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ExtVectorElementExpr> from(const Expr &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const ValueStmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const Stmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool contains_duplicate_elements(void) const;
  Token accessor_token(void) const;
  Expr base(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ExtVectorElementExpr) == sizeof(Expr));

#endif
} // namespace mx
