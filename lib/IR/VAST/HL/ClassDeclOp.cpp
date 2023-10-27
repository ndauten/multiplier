// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/ClassDeclOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<ClassDeclOp> ClassDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CLASS) {
    return reinterpret_cast<const ClassDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<ClassDeclOp> ClassDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ClassDeclOp ClassDeclOp::underlying_op(void) const noexcept {
  return ::vast::hl::ClassDeclOp(this->Operation::op_);
}

::mx::ir::Region ClassDeclOp::bases(void) const {
  auto &val = underlying_op().getBases();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region ClassDeclOp::fields(void) const {
  auto &val = underlying_op().getFields();
  return ::mx::ir::Region(module_, val);
}

std::string_view ClassDeclOp::name(void) const {
  auto val = underlying_op().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::hl