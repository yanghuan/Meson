#include "JulianCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::Globalization::JulianCalendarNamespace {
DateTime JulianCalendar___::get_MinSupportedDateTime() {
  return DateTime::MinValue;
}

DateTime JulianCalendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType JulianCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

CalendarId JulianCalendar___::get_ID() {
  return CalendarId::JULIAN;
}

Array<Int32> JulianCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 JulianCalendar___::get_TwoDigitYearMax() {
  return _twoDigitYearMax;
}

void JulianCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > MaxYear) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, MaxYear));
  }
  _twoDigitYearMax = value;
}

void JulianCalendar___::ctor() {
  MaxYear = 9999;
}

void JulianCalendar___::CheckEraRange(Int32 era) {
  if (era != 0 && era != JulianEra) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
}

void JulianCalendar___::CheckYearEraRange(Int32 year, Int32 era) {
  CheckEraRange(era);
  if (year <= 0 || year > MaxYear) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, MaxYear));
  }
}

void JulianCalendar___::CheckMonthRange(Int32 month) {
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
}

void JulianCalendar___::CheckDayRange(Int32 year, Int32 month, Int32 day) {
  if (year == 1 && month == 1 && day < 3) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
  }
  Array<Int32> array = (year % 4 == 0) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 num = array[month] - array[month - 1];
  if (day < 1 || day > num) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, num));
  }
}

Int32 JulianCalendar___::GetDatePart(Int64 ticks, Int32 part) {
  Int64 num = ticks + 1728000000000;
  Int32 num2 = (Int32)(num / 864000000000);
  Int32 num3 = num2 / 1461;
  num2 -= num3 * 1461;
  Int32 num4 = num2 / 365;
  if (num4 == 4) {
    num4 = 3;
  }
  if (part == 0) {
    return num3 * 4 + num4 + 1;
  }
  num2 -= num4 * 365;
  if (part == 1) {
    return num2 + 1;
  }
  Array<Int32> array = (num4 == 3) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 i;
  for (i = (num2 >> 5) + 1; num2 >= array[i]; i++) {
  }
  if (part == 2) {
    return i;
  }
  return num2 - array[i - 1] + 1;
}

Int64 JulianCalendar___::DateToTicks(Int32 year, Int32 month, Int32 day) {
  Array<Int32> array = (year % 4 == 0) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 num = year - 1;
  Int32 num2 = num * 365 + num / 4 + array[month - 1] + day - 1;
  return (num2 - 2) * 864000000000;
}

DateTime JulianCalendar___::AddMonths(DateTime time, Int32 months) {
  if (months < -120000 || months > 120000) {
    rt::throw_exception<ArgumentOutOfRangeException>("months", months, SR::Format(SR::get_ArgumentOutOfRange_Range(), -120000, 120000));
  }
  Int32 datePart = GetDatePart(time.get_Ticks(), 0);
  Int32 datePart2 = GetDatePart(time.get_Ticks(), 2);
  Int32 num = GetDatePart(time.get_Ticks(), 3);
  Int32 num2 = datePart2 - 1 + months;
  if (num2 >= 0) {
    datePart2 = num2 % 12 + 1;
    datePart += num2 / 12;
  } else {
    datePart2 = 12 + (num2 + 1) % 12;
    datePart += (num2 - 11) / 12;
  }
  Array<Int32> array = (datePart % 4 == 0 && (datePart % 100 != 0 || datePart % 400 == 0)) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 num3 = array[datePart2] - array[datePart2 - 1];
  if (num > num3) {
    num = num3;
  }
  Int64 ticks = DateToTicks(datePart, datePart2, num) + time.get_Ticks() % 864000000000;
  Calendar::in::CheckAddResult(ticks, get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return DateTime(ticks);
}

DateTime JulianCalendar___::AddYears(DateTime time, Int32 years) {
  return AddMonths(time, years * 12);
}

Int32 JulianCalendar___::GetDayOfMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 3);
}

DayOfWeek JulianCalendar___::GetDayOfWeek(DateTime time) {
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 JulianCalendar___::GetDayOfYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 1);
}

Int32 JulianCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearEraRange(year, era);
  CheckMonthRange(month);
  Array<Int32> array = (year % 4 == 0) ? s_daysToMonth366 : s_daysToMonth365;
  return array[month] - array[month - 1];
}

Int32 JulianCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  if (!IsLeapYear(year, era)) {
    return 365;
  }
  return 366;
}

Int32 JulianCalendar___::GetEra(DateTime time) {
  return JulianEra;
}

Int32 JulianCalendar___::GetMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 2);
}

Int32 JulianCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  CheckYearEraRange(year, era);
  return 12;
}

Int32 JulianCalendar___::GetYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 0);
}

Boolean JulianCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  CheckMonthRange(month);
  if (IsLeapYear(year, era)) {
    CheckDayRange(year, month, day);
    if (month == 2) {
      return day == 29;
    }
    return false;
  }
  CheckDayRange(year, month, day);
  return false;
}

Int32 JulianCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  CheckYearEraRange(year, era);
  return 0;
}

Boolean JulianCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearEraRange(year, era);
  CheckMonthRange(month);
  return false;
}

Boolean JulianCalendar___::IsLeapYear(Int32 year, Int32 era) {
  CheckYearEraRange(year, era);
  return year % 4 == 0;
}

DateTime JulianCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  CheckYearEraRange(year, era);
  CheckMonthRange(month);
  CheckDayRange(year, month, day);
  if (millisecond < 0 || millisecond >= 1000) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecond", millisecond, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
  }
  if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
  }
  return DateTime(DateToTicks(year, month, day) + TimeSpan(0, hour, minute, second, millisecond).get_Ticks());
}

Int32 JulianCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year > MaxYear) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), 1, MaxYear));
  }
}

void JulianCalendar___::cctor() {
  JulianEra = 1;
  s_daysToMonth365 = rt::newarr<Array<Int32>>(13);
  s_daysToMonth366 = rt::newarr<Array<Int32>>(13);
}

} // namespace System::Private::CoreLib::System::Globalization::JulianCalendarNamespace
