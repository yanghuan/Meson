#pragma once

namespace System::Private::CoreLib::System::Globalization {
enum class DateTimeFormatFlags {
  None = 0,
  UseGenitiveMonth = 1,
  UseLeapYearMonth = 2,
  UseSpacesInMonthNames = 4,
  UseHebrewRule = 8,
  UseSpacesInDayNames = 16,
  UseDigitPrefixInTokens = 32,
  NotInitialized = -1,
};
} // namespace System::Private::CoreLib::System::Globalization
