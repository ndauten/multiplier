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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class Type;
class TypedefNameDecl;
class TypedefType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypedefTypeRange = DerivedEntityRange<TypeIterator, TypedefType>;
using TypedefTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypedefType>;
class TypedefType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static TypedefTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypedefTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypedefType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TYPEDEF;
  }

  static std::optional<TypedefType> from(const TokenContext &c);
  static std::optional<TypedefType> from(const Type &parent);

  inline static std::optional<TypedefType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypedefType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  TypedefNameDecl declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TypedefType) == sizeof(Type));

#endif
} // namespace mx