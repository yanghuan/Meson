#pragma once

namespace System::Private::CoreLib::System::Globalization {
enum class CalendarDataType {
  Uninitialized = 0,
  NativeName = 1,
  MonthDay = 2,
  ShortDates = 3,
  LongDates = 4,
  YearMonths = 5,
  DayNames = 6,
  AbbrevDayNames = 7,
  MonthNames = 8,
  AbbrevMonthNames = 9,
  SuperShortDayNames = 10,
  MonthGenitiveNames = 11,
  AbbrevMonthGenitiveNames = 12,
  EraNames = 13,
  AbbrevEraNames = 14,
};
} // namespace System::Private::CoreLib::System::Globalization
