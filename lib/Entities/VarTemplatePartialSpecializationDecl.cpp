// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VarTemplatePartialSpecializationDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Entities/VarTemplateSpecializationDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VarTemplatePartialSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VarTemplatePartialSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VarTemplatePartialSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplatePartialSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplatePartialSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool VarTemplatePartialSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : VarTemplatePartialSpecializationDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool VarTemplatePartialSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : VarTemplatePartialSpecializationDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<VarTemplatePartialSpecializationDecl> dr = VarTemplatePartialSpecializationDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return VarTemplatePartialSpecializationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kVarTemplatePartialSpecializationDeclDerivedKinds[] = {
    VarTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case VarTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const VarTemplatePartialSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kVarTemplatePartialSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<VarTemplatePartialSpecializationDecl> e = VarTemplatePartialSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kVarTemplatePartialSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<VarTemplatePartialSpecializationDecl> e = VarTemplatePartialSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kVarTemplatePartialSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<VarTemplatePartialSpecializationDecl> e = VarTemplatePartialSpecializationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

VarTemplatePartialSpecializationDecl VarTemplatePartialSpecializationDecl::instantiated_from_member(void) const {
  RawEntityId eid = impl->reader.getVal129();
  return VarTemplatePartialSpecializationDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

TemplateParameterList VarTemplatePartialSpecializationDecl::template_parameters(void) const {
  RawEntityId eid = impl->reader.getVal137();
  return TemplateParameterList(impl->ep->TemplateParameterListFor(impl->ep, eid));
}

bool VarTemplatePartialSpecializationDecl::has_associated_constraints(void) const {
  return impl->reader.getVal133();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx