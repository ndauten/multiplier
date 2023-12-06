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
enum class IdentifierInfoFlag : unsigned char {
  ZERO_ARGUMENT,
  ONE_ARGUMENT,
  MULTI_ARGUMENT,
  // Skipped repeat pasta::kArgumentFlags
};

inline static const char *EnumerationName(IdentifierInfoFlag) {
  return "IdentifierInfoFlag";
}

inline static constexpr unsigned NumEnumerators(IdentifierInfoFlag) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(IdentifierInfoFlag);

} // namespace mx