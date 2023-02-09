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
#include "SourceLocExprIdentKind.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class SourceLocExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SourceLocExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<SourceLocExpr> in(const Fragment &frag);
  static gap::generator<SourceLocExpr> in(const Index &index);
  static gap::generator<SourceLocExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<SourceLocExpr> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SOURCE_LOC_EXPR;
  }

  static gap::generator<SourceLocExpr> containing(const Decl &decl);
  static gap::generator<SourceLocExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<SourceLocExpr> containing(const Stmt &stmt);
  static gap::generator<SourceLocExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<SourceLocExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<SourceLocExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<SourceLocExpr> from(const Expr &parent);

  inline static std::optional<SourceLocExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return SourceLocExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SourceLocExpr> from(const ValueStmt &parent);

  inline static std::optional<SourceLocExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return SourceLocExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SourceLocExpr> from(const Stmt &parent);

  inline static std::optional<SourceLocExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SourceLocExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view builtin_string(void) const;
  SourceLocExprIdentKind identifier_kind(void) const;
  Token token(void) const;
  bool is_int_type(void) const;
};

static_assert(sizeof(SourceLocExpr) == sizeof(Expr));

#endif
} // namespace mx
