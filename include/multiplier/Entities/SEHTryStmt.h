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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CompoundStmt;
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHTryStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SEHTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SEHTryStmt> in(const Fragment &frag);
  static gap::generator<SEHTryStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_TRY_STMT;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<SEHTryStmt> containing(const Decl &decl);
  static gap::generator<SEHTryStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<SEHTryStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<SEHTryStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<SEHTryStmt> from(const Stmt &parent);

  inline static std::optional<SEHTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SEHTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  SEHExceptStmt except_handler(void) const;
  SEHFinallyStmt finally_handler(void) const;
  Stmt handler(void) const;
  bool is_cxx_try(void) const;
  CompoundStmt try_block(void) const;
  Token try_token(void) const;
};

static_assert(sizeof(SEHTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
