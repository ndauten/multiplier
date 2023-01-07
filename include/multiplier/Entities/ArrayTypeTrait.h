// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ArrayTypeTrait : unsigned char {
  ARRAY_RANK,
  ARRAY_EXTENT,
};

inline static const char *EnumerationName(ArrayTypeTrait) {
  return "ArrayTypeTrait";
}

inline static constexpr unsigned NumEnumerators(ArrayTypeTrait) {
  return 2;
}

const char *EnumeratorName(ArrayTypeTrait);

} // namespace mx