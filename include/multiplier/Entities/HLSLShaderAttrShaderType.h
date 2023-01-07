// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class HLSLShaderAttrShaderType : unsigned char {
  PIXEL,
  VERTEX,
  GEOMETRY,
  HULL,
  DOMAIN_,
  COMPUTE,
  RAY_GENERATION,
  INTERSECTION,
  ANY_HIT,
  CLOSEST_HIT,
  MISS,
  CALLABLE,
  MESH,
  AMPLIFICATION,
};

inline static const char *EnumerationName(HLSLShaderAttrShaderType) {
  return "HLSLShaderAttrShaderType";
}

inline static constexpr unsigned NumEnumerators(HLSLShaderAttrShaderType) {
  return 14;
}

const char *EnumeratorName(HLSLShaderAttrShaderType);

} // namespace mx