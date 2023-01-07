// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class GuardedVarAttrSpelling : unsigned char {
  GNU_GUARDED_VARIABLE,
  CXX11_CLANG_GUARDED_VARIABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(GuardedVarAttrSpelling) {
  return "GuardedVarAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(GuardedVarAttrSpelling) {
  return 3;
}

const char *EnumeratorName(GuardedVarAttrSpelling);

} // namespace mx