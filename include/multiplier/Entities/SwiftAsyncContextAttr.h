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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "ParameterABIAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class SwiftAsyncContextAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAsyncContextAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncContextAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncContextAttr> in(const Index &index);
  static gap::generator<SwiftAsyncContextAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<SwiftAsyncContextAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC_CONTEXT;
  }

  inline static std::optional<SwiftAsyncContextAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<SwiftAsyncContextAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<SwiftAsyncContextAttr> from(const ParameterABIAttr &parent);

  inline static std::optional<SwiftAsyncContextAttr> from(const std::optional<ParameterABIAttr> &parent) {
    if (parent) {
      return SwiftAsyncContextAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAsyncContextAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<SwiftAsyncContextAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return SwiftAsyncContextAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAsyncContextAttr> from(const InheritableAttr &parent);

  inline static std::optional<SwiftAsyncContextAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return SwiftAsyncContextAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAsyncContextAttr> from(const Attr &parent);

  inline static std::optional<SwiftAsyncContextAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftAsyncContextAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(SwiftAsyncContextAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
