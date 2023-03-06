// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RecordType.h>

#include <multiplier/Entities/TagType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<RecordType> RecordType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RecordType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RecordType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RecordType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<RecordType> RecordType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return RecordType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kRecordTypeDerivedKinds[] = {
    RecordType::static_kind(),
};

std::optional<RecordType> RecordType::from(const Type &parent) {
  switch (parent.kind()) {
    case RecordType::static_kind():
      return reinterpret_cast<const RecordType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RecordType> RecordType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kRecordTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<RecordType> e = RecordType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecordType> RecordType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kRecordTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<RecordType> e = RecordType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecordType> RecordType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kRecordTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<RecordType> e = RecordType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type RecordType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal292();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool RecordType::has_const_fields(void) const {
  return impl->reader.getVal294();
}

bool RecordType::is_sugared(void) const {
  return impl->reader.getVal295();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx