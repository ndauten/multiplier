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
class SEHLeaveStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SEHLeaveStmtRange = DerivedEntityRange<StmtIterator, SEHLeaveStmt>;
using SEHLeaveStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SEHLeaveStmt>;
using SEHLeaveStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SEHLeaveStmt>;

class SEHLeaveStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SEHLeaveStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SEHLeaveStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SEHLeaveStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_LEAVE_STMT;
  }

  static SEHLeaveStmtContainingStmtRange containing(const Decl &decl);
  static SEHLeaveStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHLeaveStmt> from(const TokenContext &c);
  static std::optional<SEHLeaveStmt> from(const Stmt &parent);

  inline static std::optional<SEHLeaveStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SEHLeaveStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token leave_token(void) const;
};

static_assert(sizeof(SEHLeaveStmt) == sizeof(Stmt));

#endif
} // namespace mx