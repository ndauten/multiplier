// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

namespace mx {
namespace ir {
enum class AttributeKind : unsigned {
  UNKNOWN,
  BUILTIN_TYPED,
  BUILTIN_ELEMENTS,
  BUILTIN_AFFINE_MAP,
  BUILTIN_ARRAY,
  BUILTIN_DENSE_ARRAY,
  BUILTIN_DENSE_INT_OR_FP_ELEMENTS,
  BUILTIN_DENSE_RESOURCE_ELEMENTS,
  BUILTIN_DENSE_STRING_ELEMENTS,
  BUILTIN_DICTIONARY,
  BUILTIN_FLOAT,
  BUILTIN_INTEGER,
  BUILTIN_INTEGER_SET,
  BUILTIN_OPAQUE,
  BUILTIN_SPARSE_ELEMENTS,
  BUILTIN_STRING,
  BUILTIN_SYMBOL_REF,
  BUILTIN_TYPE,
  BUILTIN_UNIT,
  BUILTIN_STRIDED_LAYOUT,
  BUILTIN_BOOL,
  BUILTIN_FLAT_SYMBOL_REF,
  BUILTIN_DENSE_INT_ELEMENTS,
  LLVM_C_CONV,
  LLVM_COMDAT,
  LLVM_ACCESS_GROUP,
  LLVM_ALIAS_SCOPE,
  LLVM_ALIAS_SCOPE_DOMAIN,
  LLVM_DI_BASIC_TYPE,
  LLVM_DI_COMPILE_UNIT,
  LLVM_DI_COMPOSITE_TYPE,
  LLVM_DI_DERIVED_TYPE,
  LLVM_DI_FILE,
  LLVM_DI_LABEL,
  LLVM_DI_LEXICAL_BLOCK,
  LLVM_DI_LEXICAL_BLOCK_FILE,
  LLVM_DI_LOCAL_VARIABLE,
  LLVM_DI_NAMESPACE,
  LLVM_DI_NULL_TYPE,
  LLVM_DI_SUBPROGRAM,
  LLVM_DI_SUBRANGE,
  LLVM_DI_SUBROUTINE_TYPE,
  LLVM_FASTMATH_FLAGS,
  LLVM_MEMORY_EFFECTS,
  LLVM_TBAA_MEMBER,
  LLVM_TBAA_ROOT,
  LLVM_TBAA_TAG,
  LLVM_TBAA_TYPE_DESCRIPTOR,
  LLVM_LINKAGE,
  LLVM_LOOP_ANNOTATION,
  LLVM_LOOP_DISTRIBUTE,
  LLVM_LOOP_INTERLEAVE,
  LLVM_LOOP_LICM,
  LLVM_LOOP_PEELED,
  LLVM_LOOP_PIPELINE,
  LLVM_LOOP_UNROLL_AND_JAM,
  LLVM_LOOP_UNROLL,
  LLVM_LOOP_UNSWITCH,
  LLVM_LOOP_VECTORIZE,
  HL_ALLOC_ALIGN,
  HL_ALLOC_SIZE,
  HL_ANNOTATION,
  HL_ASM_LABEL,
  HL_BUILTIN,
  HL_CV_QUALIFIERS,
  HL_CVR_QUALIFIERS,
  HL_CONST,
  HL_FORMAT,
  HL_LOADER_UNINITIALIZED,
  HL_MODE,
  HL_NO_INSTRUMENT_FUNCTION,
  HL_NO_THROW,
  HL_NON_NULL,
  HL_PACKED,
  HL_PURE,
  HL_RESTRICT,
  HL_SECTION,
  HL_UCV_QUALIFIERS,
  HL_WARN_UNUSED_RESULT,
  CORE_BOOLEAN,
  CORE_FLOAT,
  CORE_INTEGER,
  CORE_SOURCE_LANGUAGE,
  CORE_STRING_LITERAL,
  CORE_VOID,
  META_IDENTIFIER,
};

}  // namespace ir

inline static const char *EnumerationName(ir::AttributeKind) {
  return "AttributeKind";
}

inline static constexpr unsigned NumEnumerators(ir::AttributeKind) {
  return 85;
}

MX_EXPORT const char *EnumeratorName(ir::AttributeKind);

MX_EXPORT bool IsBuiltinAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsLLVMIRAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsMemRefAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsABIAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsLowLevelAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsHighLevelAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsCoreAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsMetaAttributeKind(ir::AttributeKind);

MX_EXPORT bool IsUnsupportedAttributeKind(ir::AttributeKind);

}  // namespace mx
