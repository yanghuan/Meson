#pragma once

namespace System::Private::CoreLib::System::Globalization {
enum class DateTimeStyles {
  None = 0,
  AllowLeadingWhite = 1,
  AllowTrailingWhite = 2,
  AllowInnerWhite = 4,
  AllowWhiteSpaces = 7,
  NoCurrentDateDefault = 8,
  AdjustToUniversal = 16,
  AssumeLocal = 32,
  AssumeUniversal = 64,
  RoundtripKind = 128,
};
} // namespace System::Private::CoreLib::System::Globalization
