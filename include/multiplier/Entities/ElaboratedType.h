// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclUseSelector.h"
#include "TypeKind.h"
#include "TypeWithKeyword.h"

namespace mx {
class ElaboratedType;
class TagDecl;
class Type;
class TypeWithKeyword;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ElaboratedTypeRange = DerivedEntityRange<TypeIterator, ElaboratedType>;
using ElaboratedTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ElaboratedType>;
class ElaboratedType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  inline static ElaboratedTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ElaboratedTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ElaboratedType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ELABORATED;
  }

  static std::optional<ElaboratedType> from(const TokenContext &c);
  static std::optional<ElaboratedType> from(const TypeWithKeyword &parent);

  inline static std::optional<ElaboratedType> from(const std::optional<TypeWithKeyword> &parent) {
    if (parent) {
      return ElaboratedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElaboratedType> from(const Type &parent);

  inline static std::optional<ElaboratedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ElaboratedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type named_type(void) const;
  std::optional<TagDecl> owned_tag_declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ElaboratedType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx