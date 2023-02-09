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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CoreturnStmt;
class Expr;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CoreturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CoreturnStmt> in(const Fragment &frag);
  static gap::generator<CoreturnStmt> in(const Index &index);
  static gap::generator<CoreturnStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CoreturnStmt> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CORETURN_STMT;
  }

  static gap::generator<CoreturnStmt> containing(const Decl &decl);
  static gap::generator<CoreturnStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CoreturnStmt> containing(const Stmt &stmt);
  static gap::generator<CoreturnStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CoreturnStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CoreturnStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CoreturnStmt> from(const Stmt &parent);

  inline static std::optional<CoreturnStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CoreturnStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token keyword_token(void) const;
  Expr operand(void) const;
  Expr promise_call(void) const;
  bool is_implicit(void) const;
};

static_assert(sizeof(CoreturnStmt) == sizeof(Stmt));

#endif
} // namespace mx
