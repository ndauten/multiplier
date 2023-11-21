// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/MemorySpaceCastOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<MemorySpaceCastOp> MemorySpaceCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_MEMORY_SPACE_CAST) {
    return reinterpret_cast<const MemorySpaceCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemorySpaceCastOp> MemorySpaceCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::MemorySpaceCastOp MemorySpaceCastOp::underlying_op(void) const noexcept {
  return ::mlir::memref::MemorySpaceCastOp(this->Operation::op_);
}

}  // namespace mx::ir::memref