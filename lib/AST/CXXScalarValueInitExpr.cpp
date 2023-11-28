// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXScalarValueInitExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXScalarValueInitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXScalarValueInitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXScalarValueInitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXScalarValueInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXScalarValueInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXScalarValueInitExpr::contains(const Decl &decl) {
  for (auto &parent : CXXScalarValueInitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXScalarValueInitExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXScalarValueInitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXScalarValueInitExprDerivedKinds[] = {
    CXXScalarValueInitExpr::static_kind(),
};

}  // namespace

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXScalarValueInitExpr::static_kind():
      return reinterpret_cast<const CXXScalarValueInitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXScalarValueInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXScalarValueInitExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXScalarValueInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXScalarValueInitExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXScalarValueInitExpr> CXXScalarValueInitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXScalarValueInitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXScalarValueInitExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const Reference &r) {
  return CXXScalarValueInitExpr::from(r.as_statement());
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token CXXScalarValueInitExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
