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
enum class AssumeAlignedAttrSpelling : unsigned char {
  GNU_ASSUME_ALIGNED,
  CXX11_GNU_ASSUME_ALIGNED,
  C2X_GNU_ASSUME_ALIGNED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AssumeAlignedAttrSpelling) {
  return "AssumeAlignedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AssumeAlignedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AssumeAlignedAttrSpelling);

} // namespace mx