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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Attr.h"
#include "AttrKind.h"
#include "BuiltinAliasAttrSpelling.h"

namespace mx {
class Attr;
class BuiltinAliasAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BuiltinAliasAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static gap::generator<BuiltinAliasAttr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<BuiltinAliasAttr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : BuiltinAliasAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BUILTIN_ALIAS;
  }

  static std::optional<BuiltinAliasAttr> from(const TokenContext &c);
  static std::optional<BuiltinAliasAttr> from(const Attr &parent);

  inline static std::optional<BuiltinAliasAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BuiltinAliasAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  BuiltinAliasAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(BuiltinAliasAttr) == sizeof(Attr));

#endif
} // namespace mx
