// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SubstTemplateTypeParmType.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/TemplateTypeParmDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SubstTemplateTypeParmType> SubstTemplateTypeParmType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SubstTemplateTypeParmType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SubstTemplateTypeParmType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SubstTemplateTypeParmType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kSubstTemplateTypeParmTypeDerivedKinds[] = {
    SubstTemplateTypeParmType::static_kind(),
};

}  // namespace

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case SubstTemplateTypeParmType::static_kind():
      return reinterpret_cast<const SubstTemplateTypeParmType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SubstTemplateTypeParmType> SubstTemplateTypeParmType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kSubstTemplateTypeParmTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<SubstTemplateTypeParmType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const Reference &r) {
  return SubstTemplateTypeParmType::from(r.as_type());
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type SubstTemplateTypeParmType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Decl SubstTemplateTypeParmType::associated_declaration(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Decl(impl->ep->DeclFor(impl->ep, eid));
}

std::optional<uint32_t> SubstTemplateTypeParmType::pack_index(void) const {
  if (!impl->reader.getVal20()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal24());
  }
  return std::nullopt;
}

TemplateTypeParmDecl SubstTemplateTypeParmType::replaced_parameter(void) const {
  RawEntityId eid = impl->reader.getVal25();
  return TemplateTypeParmDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Type SubstTemplateTypeParmType::replacement_type(void) const {
  RawEntityId eid = impl->reader.getVal26();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool SubstTemplateTypeParmType::is_sugared(void) const {
  return impl->reader.getVal21();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx