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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableAttr.h"
#include "SwiftNewTypeAttrNewtypeKind.h"
#include "SwiftNewTypeAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class SwiftNewTypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftNewTypeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftNewTypeAttr> in(const Fragment &frag);
  static gap::generator<SwiftNewTypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_NEW_TYPE;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<SwiftNewTypeAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<SwiftNewTypeAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<SwiftNewTypeAttr> from(const InheritableAttr &parent);

  inline static std::optional<SwiftNewTypeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return SwiftNewTypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftNewTypeAttr> from(const Attr &parent);

  inline static std::optional<SwiftNewTypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftNewTypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  SwiftNewTypeAttrNewtypeKind newtype_kind(void) const;
  SwiftNewTypeAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(SwiftNewTypeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
