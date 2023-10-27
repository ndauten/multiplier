// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class CxxStructDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class CxxStructDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CXXSTRUCT;
  }

  static std::optional<CxxStructDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<CxxStructDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CxxStructDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region bases(void) const;
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(CxxStructDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl