// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/FPExtOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<FPExtOp> FPExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FPEXT) {
    return reinterpret_cast<const FPExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<FPExtOp> FPExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FPExtOp FPExtOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::FPExtOp(this->Operation::op_);
}

::mx::ir::Value FPExtOp::arg(void) const {
  auto val = underlying_op().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPExtOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm