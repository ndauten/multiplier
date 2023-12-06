// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class OpenCLGlobalHostAddressSpaceAttr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OpenCLGlobalHostAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLGlobalHostAddressSpaceAttr> in(const Index &index);
  static gap::generator<OpenCLGlobalHostAddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLGlobalHostAddressSpaceAttr> by_id(const Index &, EntityId);
  static gap::generator<OpenCLGlobalHostAddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<OpenCLGlobalHostAddressSpaceAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE;
  }

  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from_base(const Attr &parent);
  inline static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const std::optional<Attr> &parent);
  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const Reference &r);
  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const VariantEntity &e);
  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const TokenContext &t);

};

static_assert(sizeof(OpenCLGlobalHostAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx