// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MinSizeAttrSpelling : unsigned char {
  GNU_MINSIZE,
  CXX11_CLANG_MINSIZE,
  C2X_CLANG_MINSIZE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MinSizeAttrSpelling) {
  return "MinSizeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MinSizeAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MinSizeAttrSpelling);

} // namespace mx