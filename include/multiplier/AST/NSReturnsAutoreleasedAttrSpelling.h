// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NSReturnsAutoreleasedAttrSpelling : unsigned char {
  GNU_NS_RETURNS_AUTORELEASED,
  CXX11_CLANG_NS_RETURNS_AUTORELEASED,
  C2X_CLANG_NS_RETURNS_AUTORELEASED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NSReturnsAutoreleasedAttrSpelling) {
  return "NSReturnsAutoreleasedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NSReturnsAutoreleasedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NSReturnsAutoreleasedAttrSpelling);

} // namespace mx
