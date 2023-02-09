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

#include "OMPLoopTransformationDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class OMPTileDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTileDirective : public OMPLoopTransformationDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopTransformationDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTileDirective> in(const Fragment &frag);
  static gap::generator<OMPTileDirective> in(const Index &index);
  static gap::generator<OMPTileDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<OMPTileDirective> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TILE_DIRECTIVE;
  }

  static gap::generator<OMPTileDirective> containing(const Decl &decl);
  static gap::generator<OMPTileDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTileDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTileDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPTileDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPTileDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPTileDirective> from(const OMPLoopTransformationDirective &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<OMPLoopTransformationDirective> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTileDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTileDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTileDirective> from(const Stmt &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTileDirective) == sizeof(OMPLoopTransformationDirective));

#endif
} // namespace mx
