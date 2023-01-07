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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CoreturnStmt;
class Expr;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CoreturnStmtRange = DerivedEntityRange<StmtIterator, CoreturnStmt>;
using CoreturnStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoreturnStmt>;
using CoreturnStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoreturnStmt>;

class CoreturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CoreturnStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoreturnStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CoreturnStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CORETURN_STMT;
  }

  static CoreturnStmtContainingStmtRange containing(const Decl &decl);
  static CoreturnStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoreturnStmt> from(const TokenContext &c);
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