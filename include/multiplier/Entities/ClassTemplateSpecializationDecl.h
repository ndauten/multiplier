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

#include "CXXRecordDecl.h"
#include "DeclKind.h"
#include "TemplateSpecializationKind.h"

namespace mx {
class CXXRecordDecl;
class ClassTemplateDecl;
class ClassTemplateSpecializationDecl;
class Decl;
class NamedDecl;
class RecordDecl;
class TagDecl;
class TemplateArgument;
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ClassTemplateSpecializationDecl : public CXXRecordDecl {
 private:
  friend class FragmentImpl;
  friend class CXXRecordDecl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ClassTemplateSpecializationDecl> in(const Fragment &frag);
  static gap::generator<ClassTemplateSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE_SPECIALIZATION;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<ClassTemplateSpecializationDecl> containing(const Decl &decl);
  static gap::generator<ClassTemplateSpecializationDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ClassTemplateSpecializationDecl> redeclarations(void) const;
  inline static std::optional<ClassTemplateSpecializationDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ClassTemplateSpecializationDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ClassTemplateSpecializationDecl> from(const CXXRecordDecl &parent);

  inline static std::optional<ClassTemplateSpecializationDecl> from(const std::optional<CXXRecordDecl> &parent) {
    if (parent) {
      return ClassTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateSpecializationDecl> from(const RecordDecl &parent);

  inline static std::optional<ClassTemplateSpecializationDecl> from(const std::optional<RecordDecl> &parent) {
    if (parent) {
      return ClassTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateSpecializationDecl> from(const TagDecl &parent);

  inline static std::optional<ClassTemplateSpecializationDecl> from(const std::optional<TagDecl> &parent) {
    if (parent) {
      return ClassTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateSpecializationDecl> from(const TypeDecl &parent);

  inline static std::optional<ClassTemplateSpecializationDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return ClassTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateSpecializationDecl> from(const NamedDecl &parent);

  inline static std::optional<ClassTemplateSpecializationDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ClassTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateSpecializationDecl> from(const Decl &parent);

  inline static std::optional<ClassTemplateSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token extern_token(void) const;
  Token point_of_instantiation(void) const;
  TemplateSpecializationKind specialization_kind(void) const;
  ClassTemplateDecl specialized_template(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  gap::generator<TemplateArgument> template_arguments(void) const;
  std::optional<TemplateArgument> nth_template_instantiation_argument(unsigned n) const;
  gap::generator<TemplateArgument> template_instantiation_arguments(void) const;
  Token template_keyword_token(void) const;
  std::optional<Type> type_as_written(void) const;
  bool is_class_scope_explicit_specialization(void) const;
  bool is_explicit_instantiation_or_specialization(void) const;
  bool is_explicit_specialization(void) const;
};

static_assert(sizeof(ClassTemplateSpecializationDecl) == sizeof(CXXRecordDecl));

#endif
} // namespace mx
