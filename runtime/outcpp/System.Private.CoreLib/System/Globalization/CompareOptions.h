#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions : int32_t {
  None = 0,
  IgnoreCase = 1,
  IgnoreNonSpace = 2,
  IgnoreSymbols = 4,
  IgnoreKanaType = 8,
  IgnoreWidth = 16,
  OrdinalIgnoreCase = 268435456,
  StringSort = 536870912,
  Ordinal = 1073741824,
};
} // namespace System::Private::CoreLib::System::Globalization
