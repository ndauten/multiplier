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
#include "InheritableParamAttr.h"

namespace mx {
class AnnotateAttr;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnnotateAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AnnotateAttr> in(const Fragment &frag);
  static gap::generator<AnnotateAttr> in(const Index &index);
  static gap::generator<AnnotateAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<AnnotateAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANNOTATE;
  }

  inline static std::optional<AnnotateAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AnnotateAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AnnotateAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<AnnotateAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return AnnotateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AnnotateAttr> from(const InheritableAttr &parent);

  inline static std::optional<AnnotateAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AnnotateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AnnotateAttr> from(const Attr &parent);

  inline static std::optional<AnnotateAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AnnotateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view annotation(void) const;
};

static_assert(sizeof(AnnotateAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
