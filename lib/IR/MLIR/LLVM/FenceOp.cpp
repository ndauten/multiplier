// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/FenceOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<FenceOp> FenceOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FENCE) {
    return reinterpret_cast<const FenceOp &>(that);
  }
  return std::nullopt;
}

std::optional<FenceOp> FenceOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FenceOp FenceOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::FenceOp(this->Operation::op_);
}

std::string_view FenceOp::syncscope(void) const {
  auto val = underlying_op().getSyncscope();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::llvm