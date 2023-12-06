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
enum class ExternalSourceSymbolAttrSpelling : unsigned char {
  GNU_EXTERNAL_SOURCE_SYMBOL,
  CXX11_CLANG_EXTERNAL_SOURCE_SYMBOL,
  C2X_CLANG_EXTERNAL_SOURCE_SYMBOL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ExternalSourceSymbolAttrSpelling) {
  return "ExternalSourceSymbolAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ExternalSourceSymbolAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ExternalSourceSymbolAttrSpelling);

} // namespace mx