// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDynamicCastExpr.h>

#include <multiplier/Entities/CXXNamedCastExpr.h>
#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ExplicitCastExpr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDynamicCastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDynamicCastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDynamicCastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDynamicCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDynamicCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDynamicCastExpr::contains(const Decl &decl) {
  for (auto &parent : CXXDynamicCastExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXDynamicCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXDynamicCastExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXDynamicCastExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXDynamicCastExprDerivedKinds[] = {
    CXXDynamicCastExpr::static_kind(),
};

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXDynamicCastExpr::static_kind():
      return reinterpret_cast<const CXXDynamicCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXDynamicCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXDynamicCastExpr> e = CXXDynamicCastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXDynamicCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXDynamicCastExpr> e = CXXDynamicCastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDynamicCastExpr> CXXDynamicCastExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXDynamicCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXDynamicCastExpr> e = CXXDynamicCastExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

bool CXXDynamicCastExpr::is_always_null(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx