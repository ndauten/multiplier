// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class PackedAttrSpelling : unsigned char {
  GNU_PACKED,
  CXX11_GNU_PACKED,
  C23_GNU_PACKED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PackedAttrSpelling) {
  return "PackedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PackedAttrSpelling) {
  return 4;
}

const char *EnumeratorName(PackedAttrSpelling);

} // namespace mx
