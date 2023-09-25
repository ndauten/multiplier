// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class StmtKind : unsigned char {
  GCC_ASM_STMT,
  MS_ASM_STMT,
  BREAK_STMT,
  CXX_CATCH_STMT,
  CXX_FOR_RANGE_STMT,
  CXX_TRY_STMT,
  CAPTURED_STMT,
  COMPOUND_STMT,
  CONTINUE_STMT,
  CORETURN_STMT,
  COROUTINE_BODY_STMT,
  DECL_STMT,
  DO_STMT,
  FOR_STMT,
  GOTO_STMT,
  IF_STMT,
  INDIRECT_GOTO_STMT,
  MS_DEPENDENT_EXISTS_STMT,
  NULL_STMT,
  OMP_CANONICAL_LOOP,
  OMP_ATOMIC_DIRECTIVE,
  OMP_BARRIER_DIRECTIVE,
  OMP_CANCEL_DIRECTIVE,
  OMP_CANCELLATION_POINT_DIRECTIVE,
  OMP_CRITICAL_DIRECTIVE,
  OMP_DEPOBJ_DIRECTIVE,
  OMP_DISPATCH_DIRECTIVE,
  OMP_ERROR_DIRECTIVE,
  OMP_FLUSH_DIRECTIVE,
  OMP_INTEROP_DIRECTIVE,
  OMP_DISTRIBUTE_DIRECTIVE,
  OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_FOR_DIRECTIVE,
  OMP_FOR_SIMD_DIRECTIVE,
  OMP_GENERIC_LOOP_DIRECTIVE,
  OMP_MASKED_TASK_LOOP_DIRECTIVE,
  OMP_MASKED_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_MASTER_TASK_LOOP_DIRECTIVE,
  OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_PARALLEL_FOR_DIRECTIVE,
  OMP_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_PARALLEL_GENERIC_LOOP_DIRECTIVE,
  OMP_PARALLEL_MASKED_TASK_LOOP_DIRECTIVE,
  OMP_PARALLEL_MASKED_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE,
  OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_SIMD_DIRECTIVE,
  OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TARGET_PARALLEL_GENERIC_LOOP_DIRECTIVE,
  OMP_TARGET_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_GENERIC_LOOP_DIRECTIVE,
  OMP_TASK_LOOP_DIRECTIVE,
  OMP_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_TEAMS_GENERIC_LOOP_DIRECTIVE,
  OMP_TILE_DIRECTIVE,
  OMP_UNROLL_DIRECTIVE,
  OMP_MASKED_DIRECTIVE,
  OMP_MASTER_DIRECTIVE,
  OMP_META_DIRECTIVE,
  OMP_ORDERED_DIRECTIVE,
  OMP_PARALLEL_DIRECTIVE,
  OMP_PARALLEL_MASKED_DIRECTIVE,
  OMP_PARALLEL_MASTER_DIRECTIVE,
  OMP_PARALLEL_SECTIONS_DIRECTIVE,
  OMP_SCAN_DIRECTIVE,
  OMP_SCOPE_DIRECTIVE,
  OMP_SECTION_DIRECTIVE,
  OMP_SECTIONS_DIRECTIVE,
  OMP_SINGLE_DIRECTIVE,
  OMP_TARGET_DATA_DIRECTIVE,
  OMP_TARGET_DIRECTIVE,
  OMP_TARGET_ENTER_DATA_DIRECTIVE,
  OMP_TARGET_EXIT_DATA_DIRECTIVE,
  OMP_TARGET_PARALLEL_DIRECTIVE,
  OMP_TARGET_PARALLEL_FOR_DIRECTIVE,
  OMP_TARGET_TEAMS_DIRECTIVE,
  OMP_TARGET_UPDATE_DIRECTIVE,
  OMP_TASK_DIRECTIVE,
  OMP_TASKGROUP_DIRECTIVE,
  OMP_TASKWAIT_DIRECTIVE,
  OMP_TASKYIELD_DIRECTIVE,
  OMP_TEAMS_DIRECTIVE,
  OBJ_C_AT_CATCH_STMT,
  OBJ_C_AT_FINALLY_STMT,
  OBJ_C_AT_SYNCHRONIZED_STMT,
  OBJ_C_AT_THROW_STMT,
  OBJ_C_AT_TRY_STMT,
  OBJ_C_AUTORELEASE_POOL_STMT,
  OBJ_C_FOR_COLLECTION_STMT,
  RETURN_STMT,
  SEH_EXCEPT_STMT,
  SEH_FINALLY_STMT,
  SEH_LEAVE_STMT,
  SEH_TRY_STMT,
  CASE_STMT,
  DEFAULT_STMT,
  SWITCH_STMT,
  ATTRIBUTED_STMT,
  BINARY_CONDITIONAL_OPERATOR,
  CONDITIONAL_OPERATOR,
  ADDR_LABEL_EXPR,
  ARRAY_INIT_INDEX_EXPR,
  ARRAY_INIT_LOOP_EXPR,
  ARRAY_SUBSCRIPT_EXPR,
  ARRAY_TYPE_TRAIT_EXPR,
  AS_TYPE_EXPR,
  ATOMIC_EXPR,
  BINARY_OPERATOR,
  COMPOUND_ASSIGN_OPERATOR,
  BLOCK_EXPR,
  CXX_BIND_TEMPORARY_EXPR,
  CXX_BOOL_LITERAL_EXPR,
  CXX_CONSTRUCT_EXPR,
  CXX_TEMPORARY_OBJECT_EXPR,
  CXX_DEFAULT_ARG_EXPR,
  CXX_DEFAULT_INIT_EXPR,
  CXX_DELETE_EXPR,
  CXX_DEPENDENT_SCOPE_MEMBER_EXPR,
  CXX_FOLD_EXPR,
  CXX_INHERITED_CTOR_INIT_EXPR,
  CXX_NEW_EXPR,
  CXX_NOEXCEPT_EXPR,
  CXX_NULL_PTR_LITERAL_EXPR,
  CXX_PAREN_LIST_INIT_EXPR,
  CXX_PSEUDO_DESTRUCTOR_EXPR,
  CXX_REWRITTEN_BINARY_OPERATOR,
  CXX_SCALAR_VALUE_INIT_EXPR,
  CXX_STD_INITIALIZER_LIST_EXPR,
  CXX_THIS_EXPR,
  CXX_THROW_EXPR,
  CXX_TYPEID_EXPR,
  CXX_UNRESOLVED_CONSTRUCT_EXPR,
  CXX_UUIDOF_EXPR,
  CALL_EXPR,
  CUDA_KERNEL_CALL_EXPR,
  CXX_MEMBER_CALL_EXPR,
  CXX_OPERATOR_CALL_EXPR,
  USER_DEFINED_LITERAL,
  BUILTIN_BIT_CAST_EXPR,
  C_STYLE_CAST_EXPR,
  CXX_FUNCTIONAL_CAST_EXPR,
  CXX_ADDRSPACE_CAST_EXPR,
  CXX_CONST_CAST_EXPR,
  CXX_DYNAMIC_CAST_EXPR,
  CXX_REINTERPRET_CAST_EXPR,
  CXX_STATIC_CAST_EXPR,
  OBJ_C_BRIDGED_CAST_EXPR,
  IMPLICIT_CAST_EXPR,
  CHARACTER_LITERAL,
  CHOOSE_EXPR,
  COMPOUND_LITERAL_EXPR,
  CONCEPT_SPECIALIZATION_EXPR,
  CONVERT_VECTOR_EXPR,
  COAWAIT_EXPR,
  COYIELD_EXPR,
  DECL_REF_EXPR,
  DEPENDENT_COAWAIT_EXPR,
  DEPENDENT_SCOPE_DECL_REF_EXPR,
  DESIGNATED_INIT_EXPR,
  DESIGNATED_INIT_UPDATE_EXPR,
  EXPRESSION_TRAIT_EXPR,
  EXT_VECTOR_ELEMENT_EXPR,
  FIXED_POINT_LITERAL,
  FLOATING_LITERAL,
  CONSTANT_EXPR,
  EXPR_WITH_CLEANUPS,
  FUNCTION_PARM_PACK_EXPR,
  GNU_NULL_EXPR,
  GENERIC_SELECTION_EXPR,
  IMAGINARY_LITERAL,
  IMPLICIT_VALUE_INIT_EXPR,
  INIT_LIST_EXPR,
  INTEGER_LITERAL,
  LAMBDA_EXPR,
  MS_PROPERTY_REF_EXPR,
  MS_PROPERTY_SUBSCRIPT_EXPR,
  MATERIALIZE_TEMPORARY_EXPR,
  MATRIX_SUBSCRIPT_EXPR,
  MEMBER_EXPR,
  NO_INIT_EXPR,
  OMP_ARRAY_SECTION_EXPR,
  OMP_ARRAY_SHAPING_EXPR,
  OMP_ITERATOR_EXPR,
  OBJ_C_ARRAY_LITERAL,
  OBJ_C_AVAILABILITY_CHECK_EXPR,
  OBJ_C_BOOL_LITERAL_EXPR,
  OBJ_C_BOXED_EXPR,
  OBJ_C_DICTIONARY_LITERAL,
  OBJ_C_ENCODE_EXPR,
  OBJ_C_INDIRECT_COPY_RESTORE_EXPR,
  OBJ_C_ISA_EXPR,
  OBJ_C_IVAR_REF_EXPR,
  OBJ_C_MESSAGE_EXPR,
  OBJ_C_PROPERTY_REF_EXPR,
  OBJ_C_PROTOCOL_EXPR,
  OBJ_C_SELECTOR_EXPR,
  OBJ_C_STRING_LITERAL,
  OBJ_C_SUBSCRIPT_REF_EXPR,
  OFFSET_OF_EXPR,
  OPAQUE_VALUE_EXPR,
  UNRESOLVED_LOOKUP_EXPR,
  UNRESOLVED_MEMBER_EXPR,
  PACK_EXPANSION_EXPR,
  PAREN_EXPR,
  PAREN_LIST_EXPR,
  PREDEFINED_EXPR,
  PSEUDO_OBJECT_EXPR,
  RECOVERY_EXPR,
  REQUIRES_EXPR,
  SYCL_UNIQUE_STABLE_NAME_EXPR,
  SHUFFLE_VECTOR_EXPR,
  SIZE_OF_PACK_EXPR,
  SOURCE_LOC_EXPR,
  STMT_EXPR,
  STRING_LITERAL,
  SUBST_NON_TYPE_TEMPLATE_PARM_EXPR,
  SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR,
  TYPE_TRAIT_EXPR,
  TYPO_EXPR,
  UNARY_EXPR_OR_TYPE_TRAIT_EXPR,
  UNARY_OPERATOR,
  VA_ARG_EXPR,
  LABEL_STMT,
  WHILE_STMT,
};

inline static const char *EnumerationName(StmtKind) {
  return "StmtKind";
}

inline static constexpr unsigned NumEnumerators(StmtKind) {
  return 234;
}

const char *EnumeratorName(StmtKind);

} // namespace mx
