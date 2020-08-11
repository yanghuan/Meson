#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles : int32_t {
  None = 0,
  AllowLeadingWhite = 1,
  AllowTrailingWhite = 2,
  AllowLeadingSign = 4,
  AllowTrailingSign = 8,
  AllowParentheses = 16,
  AllowDecimalPoint = 32,
  AllowThousands = 64,
  AllowExponent = 128,
  AllowCurrencySymbol = 256,
  AllowHexSpecifier = 512,
  Integer = 7,
  HexNumber = 515,
  Number = 111,
  Float = 167,
  Currency = 383,
  Any = 511,
};
} // namespace System::Private::CoreLib::System::Globalization
