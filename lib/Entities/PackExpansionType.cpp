// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PackExpansionType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<PackExpansionType> PackExpansionType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PackExpansionType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PackExpansionType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PackExpansionType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<PackExpansionType> PackExpansionType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return PackExpansionType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kPackExpansionTypeDerivedKinds[] = {
    PackExpansionType::static_kind(),
};

std::optional<PackExpansionType> PackExpansionType::from(const Type &parent) {
  switch (parent.kind()) {
    case PackExpansionType::static_kind():
      return reinterpret_cast<const PackExpansionType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PackExpansionType> PackExpansionType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kPackExpansionTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<PackExpansionType> e = PackExpansionType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PackExpansionType> PackExpansionType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kPackExpansionTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<PackExpansionType> e = PackExpansionType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PackExpansionType> PackExpansionType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kPackExpansionTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<PackExpansionType> e = PackExpansionType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type PackExpansionType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal291();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<unsigned> PackExpansionType::num_expansions(void) const {
  if (!impl->reader.getVal293()) {
    return std::nullopt;
  } else {
    return static_cast<unsigned>(impl->reader.getVal298());
  }
  return std::nullopt;
}

Type PackExpansionType::pattern(void) const {
  RawEntityId eid = impl->reader.getVal292();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool PackExpansionType::is_sugared(void) const {
  return impl->reader.getVal294();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx