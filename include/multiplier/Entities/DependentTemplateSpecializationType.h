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

#include "TypeKind.h"
#include "TypeWithKeyword.h"

namespace mx {
class DependentTemplateSpecializationType;
class TemplateArgument;
class Type;
class TypeWithKeyword;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentTemplateSpecializationType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  static gap::generator<DependentTemplateSpecializationType> in(const Fragment &frag);
  static gap::generator<DependentTemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION;
  }

  static gap::generator<TypeKind> derived_kinds(void);
  inline static std::optional<DependentTemplateSpecializationType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<DependentTemplateSpecializationType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<DependentTemplateSpecializationType> from(const TypeWithKeyword &parent);

  inline static std::optional<DependentTemplateSpecializationType> from(const std::optional<TypeWithKeyword> &parent) {
    if (parent) {
      return DependentTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentTemplateSpecializationType> from(const Type &parent);

  inline static std::optional<DependentTemplateSpecializationType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  gap::generator<TemplateArgument> template_arguments(void) const;
};

static_assert(sizeof(DependentTemplateSpecializationType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
