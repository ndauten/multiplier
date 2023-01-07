// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CommonAttrSpelling : unsigned char {
  GNU_COMMON,
  CXX11_GNU_COMMON,
  C2X_GNU_COMMON,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CommonAttrSpelling) {
  return "CommonAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CommonAttrSpelling) {
  return 4;
}

const char *EnumeratorName(CommonAttrSpelling);

} // namespace mx