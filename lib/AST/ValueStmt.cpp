// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/AddrLabelExpr.h>
#include <multiplier/AST/ArrayInitIndexExpr.h>
#include <multiplier/AST/ArrayInitLoopExpr.h>
#include <multiplier/AST/ArraySubscriptExpr.h>
#include <multiplier/AST/ArrayTypeTraitExpr.h>
#include <multiplier/AST/AsTypeExpr.h>
#include <multiplier/AST/AtomicExpr.h>
#include <multiplier/AST/AttributedStmt.h>
#include <multiplier/AST/BinaryConditionalOperator.h>
#include <multiplier/AST/BinaryOperator.h>
#include <multiplier/AST/BlockExpr.h>
#include <multiplier/AST/BuiltinBitCastExpr.h>
#include <multiplier/AST/CStyleCastExpr.h>
#include <multiplier/AST/CUDAKernelCallExpr.h>
#include <multiplier/AST/CXXAddrspaceCastExpr.h>
#include <multiplier/AST/CXXBindTemporaryExpr.h>
#include <multiplier/AST/CXXBoolLiteralExpr.h>
#include <multiplier/AST/CXXConstCastExpr.h>
#include <multiplier/AST/CXXConstructExpr.h>
#include <multiplier/AST/CXXDefaultArgExpr.h>
#include <multiplier/AST/CXXDefaultInitExpr.h>
#include <multiplier/AST/CXXDeleteExpr.h>
#include <multiplier/AST/CXXDependentScopeMemberExpr.h>
#include <multiplier/AST/CXXDynamicCastExpr.h>
#include <multiplier/AST/CXXFoldExpr.h>
#include <multiplier/AST/CXXFunctionalCastExpr.h>
#include <multiplier/AST/CXXInheritedCtorInitExpr.h>
#include <multiplier/AST/CXXMemberCallExpr.h>
#include <multiplier/AST/CXXNewExpr.h>
#include <multiplier/AST/CXXNoexceptExpr.h>
#include <multiplier/AST/CXXNullPtrLiteralExpr.h>
#include <multiplier/AST/CXXOperatorCallExpr.h>
#include <multiplier/AST/CXXParenListInitExpr.h>
#include <multiplier/AST/CXXPseudoDestructorExpr.h>
#include <multiplier/AST/CXXReinterpretCastExpr.h>
#include <multiplier/AST/CXXRewrittenBinaryOperator.h>
#include <multiplier/AST/CXXScalarValueInitExpr.h>
#include <multiplier/AST/CXXStaticCastExpr.h>
#include <multiplier/AST/CXXStdInitializerListExpr.h>
#include <multiplier/AST/CXXTemporaryObjectExpr.h>
#include <multiplier/AST/CXXThisExpr.h>
#include <multiplier/AST/CXXThrowExpr.h>
#include <multiplier/AST/CXXTypeidExpr.h>
#include <multiplier/AST/CXXUnresolvedConstructExpr.h>
#include <multiplier/AST/CXXUuidofExpr.h>
#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/CharacterLiteral.h>
#include <multiplier/AST/ChooseExpr.h>
#include <multiplier/AST/CoawaitExpr.h>
#include <multiplier/AST/CompoundAssignOperator.h>
#include <multiplier/AST/CompoundLiteralExpr.h>
#include <multiplier/AST/ConceptSpecializationExpr.h>
#include <multiplier/AST/ConditionalOperator.h>
#include <multiplier/AST/ConstantExpr.h>
#include <multiplier/AST/ConvertVectorExpr.h>
#include <multiplier/AST/CoyieldExpr.h>
#include <multiplier/AST/DeclRefExpr.h>
#include <multiplier/AST/DependentCoawaitExpr.h>
#include <multiplier/AST/DependentScopeDeclRefExpr.h>
#include <multiplier/AST/DesignatedInitExpr.h>
#include <multiplier/AST/DesignatedInitUpdateExpr.h>
#include <multiplier/AST/ExprWithCleanups.h>
#include <multiplier/AST/ExpressionTraitExpr.h>
#include <multiplier/AST/ExtVectorElementExpr.h>
#include <multiplier/AST/FixedPointLiteral.h>
#include <multiplier/AST/FloatingLiteral.h>
#include <multiplier/AST/FunctionParmPackExpr.h>
#include <multiplier/AST/GNUNullExpr.h>
#include <multiplier/AST/GenericSelectionExpr.h>
#include <multiplier/AST/ImaginaryLiteral.h>
#include <multiplier/AST/ImplicitCastExpr.h>
#include <multiplier/AST/ImplicitValueInitExpr.h>
#include <multiplier/AST/InitListExpr.h>
#include <multiplier/AST/IntegerLiteral.h>
#include <multiplier/AST/LabelStmt.h>
#include <multiplier/AST/LambdaExpr.h>
#include <multiplier/AST/MSPropertyRefExpr.h>
#include <multiplier/AST/MSPropertySubscriptExpr.h>
#include <multiplier/AST/MaterializeTemporaryExpr.h>
#include <multiplier/AST/MatrixSubscriptExpr.h>
#include <multiplier/AST/MemberExpr.h>
#include <multiplier/AST/NoInitExpr.h>
#include <multiplier/AST/OMPArraySectionExpr.h>
#include <multiplier/AST/OMPArrayShapingExpr.h>
#include <multiplier/AST/OMPIteratorExpr.h>
#include <multiplier/AST/ObjCArrayLiteral.h>
#include <multiplier/AST/ObjCAvailabilityCheckExpr.h>
#include <multiplier/AST/ObjCBoolLiteralExpr.h>
#include <multiplier/AST/ObjCBoxedExpr.h>
#include <multiplier/AST/ObjCBridgedCastExpr.h>
#include <multiplier/AST/ObjCDictionaryLiteral.h>
#include <multiplier/AST/ObjCEncodeExpr.h>
#include <multiplier/AST/ObjCIndirectCopyRestoreExpr.h>
#include <multiplier/AST/ObjCIsaExpr.h>
#include <multiplier/AST/ObjCIvarRefExpr.h>
#include <multiplier/AST/ObjCMessageExpr.h>
#include <multiplier/AST/ObjCPropertyRefExpr.h>
#include <multiplier/AST/ObjCProtocolExpr.h>
#include <multiplier/AST/ObjCSelectorExpr.h>
#include <multiplier/AST/ObjCStringLiteral.h>
#include <multiplier/AST/ObjCSubscriptRefExpr.h>
#include <multiplier/AST/OffsetOfExpr.h>
#include <multiplier/AST/OpaqueValueExpr.h>
#include <multiplier/AST/PackExpansionExpr.h>
#include <multiplier/AST/ParenExpr.h>
#include <multiplier/AST/ParenListExpr.h>
#include <multiplier/AST/PredefinedExpr.h>
#include <multiplier/AST/PseudoObjectExpr.h>
#include <multiplier/AST/RecoveryExpr.h>
#include <multiplier/AST/RequiresExpr.h>
#include <multiplier/AST/SYCLUniqueStableNameExpr.h>
#include <multiplier/AST/ShuffleVectorExpr.h>
#include <multiplier/AST/SizeOfPackExpr.h>
#include <multiplier/AST/SourceLocExpr.h>
#include <multiplier/AST/StmtExpr.h>
#include <multiplier/AST/StringLiteral.h>
#include <multiplier/AST/SubstNonTypeTemplateParmExpr.h>
#include <multiplier/AST/SubstNonTypeTemplateParmPackExpr.h>
#include <multiplier/AST/TypeTraitExpr.h>
#include <multiplier/AST/TypoExpr.h>
#include <multiplier/AST/UnaryExprOrTypeTraitExpr.h>
#include <multiplier/AST/UnaryOperator.h>
#include <multiplier/AST/UnresolvedLookupExpr.h>
#include <multiplier/AST/UnresolvedMemberExpr.h>
#include <multiplier/AST/UserDefinedLiteral.h>
#include <multiplier/AST/VAArgExpr.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ValueStmt> ValueStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ValueStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ValueStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ValueStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ValueStmt> ValueStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ValueStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ValueStmt> ValueStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ValueStmt> ValueStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ValueStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ValueStmt> ValueStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ValueStmt::contains(const Decl &decl) {
  for (auto &parent : ValueStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ValueStmt::contains(const Stmt &stmt) {
  for (auto &parent : ValueStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ValueStmt> ValueStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ValueStmt> ValueStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kValueStmtDerivedKinds[] = {
    AttributedStmt::static_kind(),
    LabelStmt::static_kind(),
    ExpressionTraitExpr::static_kind(),
    ExtVectorElementExpr::static_kind(),
    FixedPointLiteral::static_kind(),
    FloatingLiteral::static_kind(),
    FunctionParmPackExpr::static_kind(),
    GNUNullExpr::static_kind(),
    GenericSelectionExpr::static_kind(),
    ImaginaryLiteral::static_kind(),
    ImplicitValueInitExpr::static_kind(),
    InitListExpr::static_kind(),
    IntegerLiteral::static_kind(),
    LambdaExpr::static_kind(),
    MSPropertyRefExpr::static_kind(),
    MSPropertySubscriptExpr::static_kind(),
    MaterializeTemporaryExpr::static_kind(),
    MatrixSubscriptExpr::static_kind(),
    MemberExpr::static_kind(),
    NoInitExpr::static_kind(),
    OMPArraySectionExpr::static_kind(),
    OMPArrayShapingExpr::static_kind(),
    OMPIteratorExpr::static_kind(),
    ObjCArrayLiteral::static_kind(),
    ObjCAvailabilityCheckExpr::static_kind(),
    ObjCBoolLiteralExpr::static_kind(),
    ObjCBoxedExpr::static_kind(),
    ObjCDictionaryLiteral::static_kind(),
    ObjCEncodeExpr::static_kind(),
    ObjCIndirectCopyRestoreExpr::static_kind(),
    ObjCIsaExpr::static_kind(),
    ObjCIvarRefExpr::static_kind(),
    ObjCMessageExpr::static_kind(),
    ObjCPropertyRefExpr::static_kind(),
    ObjCProtocolExpr::static_kind(),
    ObjCSelectorExpr::static_kind(),
    ObjCStringLiteral::static_kind(),
    ObjCSubscriptRefExpr::static_kind(),
    OffsetOfExpr::static_kind(),
    OpaqueValueExpr::static_kind(),
    PackExpansionExpr::static_kind(),
    ParenExpr::static_kind(),
    ParenListExpr::static_kind(),
    PredefinedExpr::static_kind(),
    PseudoObjectExpr::static_kind(),
    RecoveryExpr::static_kind(),
    RequiresExpr::static_kind(),
    SYCLUniqueStableNameExpr::static_kind(),
    ShuffleVectorExpr::static_kind(),
    SizeOfPackExpr::static_kind(),
    SourceLocExpr::static_kind(),
    StmtExpr::static_kind(),
    StringLiteral::static_kind(),
    SubstNonTypeTemplateParmExpr::static_kind(),
    SubstNonTypeTemplateParmPackExpr::static_kind(),
    TypeTraitExpr::static_kind(),
    TypoExpr::static_kind(),
    UnaryExprOrTypeTraitExpr::static_kind(),
    UnaryOperator::static_kind(),
    VAArgExpr::static_kind(),
    AddrLabelExpr::static_kind(),
    ArrayInitIndexExpr::static_kind(),
    ArrayInitLoopExpr::static_kind(),
    ArraySubscriptExpr::static_kind(),
    ArrayTypeTraitExpr::static_kind(),
    AsTypeExpr::static_kind(),
    AtomicExpr::static_kind(),
    BinaryOperator::static_kind(),
    BlockExpr::static_kind(),
    CXXBindTemporaryExpr::static_kind(),
    CXXBoolLiteralExpr::static_kind(),
    CXXConstructExpr::static_kind(),
    CXXDefaultArgExpr::static_kind(),
    CXXDefaultInitExpr::static_kind(),
    CXXDeleteExpr::static_kind(),
    CXXDependentScopeMemberExpr::static_kind(),
    CXXFoldExpr::static_kind(),
    CXXInheritedCtorInitExpr::static_kind(),
    CXXNewExpr::static_kind(),
    CXXNoexceptExpr::static_kind(),
    CXXNullPtrLiteralExpr::static_kind(),
    CXXParenListInitExpr::static_kind(),
    CXXPseudoDestructorExpr::static_kind(),
    CXXRewrittenBinaryOperator::static_kind(),
    CXXScalarValueInitExpr::static_kind(),
    CXXStdInitializerListExpr::static_kind(),
    CXXThisExpr::static_kind(),
    CXXThrowExpr::static_kind(),
    CXXTypeidExpr::static_kind(),
    CXXUnresolvedConstructExpr::static_kind(),
    CXXUuidofExpr::static_kind(),
    CallExpr::static_kind(),
    CharacterLiteral::static_kind(),
    ChooseExpr::static_kind(),
    CompoundLiteralExpr::static_kind(),
    ConceptSpecializationExpr::static_kind(),
    ConvertVectorExpr::static_kind(),
    DeclRefExpr::static_kind(),
    DependentCoawaitExpr::static_kind(),
    DependentScopeDeclRefExpr::static_kind(),
    DesignatedInitExpr::static_kind(),
    DesignatedInitUpdateExpr::static_kind(),
    ConstantExpr::static_kind(),
    ExprWithCleanups::static_kind(),
    UnresolvedLookupExpr::static_kind(),
    UnresolvedMemberExpr::static_kind(),
    BinaryConditionalOperator::static_kind(),
    ConditionalOperator::static_kind(),
    CompoundAssignOperator::static_kind(),
    CXXTemporaryObjectExpr::static_kind(),
    UserDefinedLiteral::static_kind(),
    CUDAKernelCallExpr::static_kind(),
    CXXMemberCallExpr::static_kind(),
    CXXOperatorCallExpr::static_kind(),
    ImplicitCastExpr::static_kind(),
    CoyieldExpr::static_kind(),
    CoawaitExpr::static_kind(),
    ObjCBridgedCastExpr::static_kind(),
    BuiltinBitCastExpr::static_kind(),
    CStyleCastExpr::static_kind(),
    CXXFunctionalCastExpr::static_kind(),
    CXXReinterpretCastExpr::static_kind(),
    CXXStaticCastExpr::static_kind(),
    CXXAddrspaceCastExpr::static_kind(),
    CXXConstCastExpr::static_kind(),
    CXXDynamicCastExpr::static_kind(),
};

}  // namespace

std::optional<ValueStmt> ValueStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case AttributedStmt::static_kind():
    case LabelStmt::static_kind():
    case ExpressionTraitExpr::static_kind():
    case ExtVectorElementExpr::static_kind():
    case FixedPointLiteral::static_kind():
    case FloatingLiteral::static_kind():
    case FunctionParmPackExpr::static_kind():
    case GNUNullExpr::static_kind():
    case GenericSelectionExpr::static_kind():
    case ImaginaryLiteral::static_kind():
    case ImplicitValueInitExpr::static_kind():
    case InitListExpr::static_kind():
    case IntegerLiteral::static_kind():
    case LambdaExpr::static_kind():
    case MSPropertyRefExpr::static_kind():
    case MSPropertySubscriptExpr::static_kind():
    case MaterializeTemporaryExpr::static_kind():
    case MatrixSubscriptExpr::static_kind():
    case MemberExpr::static_kind():
    case NoInitExpr::static_kind():
    case OMPArraySectionExpr::static_kind():
    case OMPArrayShapingExpr::static_kind():
    case OMPIteratorExpr::static_kind():
    case ObjCArrayLiteral::static_kind():
    case ObjCAvailabilityCheckExpr::static_kind():
    case ObjCBoolLiteralExpr::static_kind():
    case ObjCBoxedExpr::static_kind():
    case ObjCDictionaryLiteral::static_kind():
    case ObjCEncodeExpr::static_kind():
    case ObjCIndirectCopyRestoreExpr::static_kind():
    case ObjCIsaExpr::static_kind():
    case ObjCIvarRefExpr::static_kind():
    case ObjCMessageExpr::static_kind():
    case ObjCPropertyRefExpr::static_kind():
    case ObjCProtocolExpr::static_kind():
    case ObjCSelectorExpr::static_kind():
    case ObjCStringLiteral::static_kind():
    case ObjCSubscriptRefExpr::static_kind():
    case OffsetOfExpr::static_kind():
    case OpaqueValueExpr::static_kind():
    case PackExpansionExpr::static_kind():
    case ParenExpr::static_kind():
    case ParenListExpr::static_kind():
    case PredefinedExpr::static_kind():
    case PseudoObjectExpr::static_kind():
    case RecoveryExpr::static_kind():
    case RequiresExpr::static_kind():
    case SYCLUniqueStableNameExpr::static_kind():
    case ShuffleVectorExpr::static_kind():
    case SizeOfPackExpr::static_kind():
    case SourceLocExpr::static_kind():
    case StmtExpr::static_kind():
    case StringLiteral::static_kind():
    case SubstNonTypeTemplateParmExpr::static_kind():
    case SubstNonTypeTemplateParmPackExpr::static_kind():
    case TypeTraitExpr::static_kind():
    case TypoExpr::static_kind():
    case UnaryExprOrTypeTraitExpr::static_kind():
    case UnaryOperator::static_kind():
    case VAArgExpr::static_kind():
    case AddrLabelExpr::static_kind():
    case ArrayInitIndexExpr::static_kind():
    case ArrayInitLoopExpr::static_kind():
    case ArraySubscriptExpr::static_kind():
    case ArrayTypeTraitExpr::static_kind():
    case AsTypeExpr::static_kind():
    case AtomicExpr::static_kind():
    case BinaryOperator::static_kind():
    case BlockExpr::static_kind():
    case CXXBindTemporaryExpr::static_kind():
    case CXXBoolLiteralExpr::static_kind():
    case CXXConstructExpr::static_kind():
    case CXXDefaultArgExpr::static_kind():
    case CXXDefaultInitExpr::static_kind():
    case CXXDeleteExpr::static_kind():
    case CXXDependentScopeMemberExpr::static_kind():
    case CXXFoldExpr::static_kind():
    case CXXInheritedCtorInitExpr::static_kind():
    case CXXNewExpr::static_kind():
    case CXXNoexceptExpr::static_kind():
    case CXXNullPtrLiteralExpr::static_kind():
    case CXXParenListInitExpr::static_kind():
    case CXXPseudoDestructorExpr::static_kind():
    case CXXRewrittenBinaryOperator::static_kind():
    case CXXScalarValueInitExpr::static_kind():
    case CXXStdInitializerListExpr::static_kind():
    case CXXThisExpr::static_kind():
    case CXXThrowExpr::static_kind():
    case CXXTypeidExpr::static_kind():
    case CXXUnresolvedConstructExpr::static_kind():
    case CXXUuidofExpr::static_kind():
    case CallExpr::static_kind():
    case CharacterLiteral::static_kind():
    case ChooseExpr::static_kind():
    case CompoundLiteralExpr::static_kind():
    case ConceptSpecializationExpr::static_kind():
    case ConvertVectorExpr::static_kind():
    case DeclRefExpr::static_kind():
    case DependentCoawaitExpr::static_kind():
    case DependentScopeDeclRefExpr::static_kind():
    case DesignatedInitExpr::static_kind():
    case DesignatedInitUpdateExpr::static_kind():
    case ConstantExpr::static_kind():
    case ExprWithCleanups::static_kind():
    case UnresolvedLookupExpr::static_kind():
    case UnresolvedMemberExpr::static_kind():
    case BinaryConditionalOperator::static_kind():
    case ConditionalOperator::static_kind():
    case CompoundAssignOperator::static_kind():
    case CXXTemporaryObjectExpr::static_kind():
    case UserDefinedLiteral::static_kind():
    case CUDAKernelCallExpr::static_kind():
    case CXXMemberCallExpr::static_kind():
    case CXXOperatorCallExpr::static_kind():
    case ImplicitCastExpr::static_kind():
    case CoyieldExpr::static_kind():
    case CoawaitExpr::static_kind():
    case ObjCBridgedCastExpr::static_kind():
    case BuiltinBitCastExpr::static_kind():
    case CStyleCastExpr::static_kind():
    case CXXFunctionalCastExpr::static_kind():
    case CXXReinterpretCastExpr::static_kind():
    case CXXStaticCastExpr::static_kind():
    case CXXAddrspaceCastExpr::static_kind():
    case CXXConstCastExpr::static_kind():
    case CXXDynamicCastExpr::static_kind():
      return reinterpret_cast<const ValueStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ValueStmt> ValueStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kValueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ValueStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueStmt> ValueStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kValueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ValueStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueStmt> ValueStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kValueStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ValueStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ValueStmt> ValueStmt::from(const Reference &r) {
  return ValueStmt::from(r.as_statement());
}

std::optional<ValueStmt> ValueStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ValueStmt> ValueStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> ValueStmt::expression_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx