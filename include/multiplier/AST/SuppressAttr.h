// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/StmtAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class StmtAttr;
class SuppressAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SuppressAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<SuppressAttr> in(const Index &index);
  static gap::generator<SuppressAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SuppressAttr> by_id(const Index &, EntityId);
  static gap::generator<SuppressAttr> in(const Fragment &frag);
  static gap::generator<SuppressAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SUPPRESS;
  }

  static std::optional<SuppressAttr> from_base(const Attr &parent);
  inline static std::optional<SuppressAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SuppressAttr> from(const std::optional<Attr> &parent);
  static std::optional<SuppressAttr> from(const Reference &r);
  static std::optional<SuppressAttr> from(const VariantEntity &e);
  static std::optional<SuppressAttr> from(const TokenContext &t);

};

static_assert(sizeof(SuppressAttr) == sizeof(StmtAttr));

#endif
} // namespace mx