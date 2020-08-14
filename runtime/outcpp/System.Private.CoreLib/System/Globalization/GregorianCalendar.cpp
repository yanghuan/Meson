#include "GregorianCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::GregorianCalendarNamespace {
DateTime GregorianCalendar___::get_MinSupportedDateTime() {
  return DateTime::MinValue;
}

DateTime GregorianCalendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType GregorianCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

GregorianCalendarTypes GregorianCalendar___::get_CalendarType() {
  return _type;
}

void GregorianCalendar___::set_CalendarType(GregorianCalendarTypes value) {
  VerifyWritable();
  if (value < GregorianCalendarTypes::Localized || value > GregorianCalendarTypes::TransliteratedFrench) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), GregorianCalendarTypes::Localized, GregorianCalendarTypes::TransliteratedFrench));
  }
  _type = value;
}

CalendarId GregorianCalendar___::get_ID() {
  return (CalendarId)_type;
}

Array<Int32> GregorianCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 GregorianCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 2029);
  }
  return _twoDigitYearMax;
}

void GregorianCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, 9999));
  }
  _twoDigitYearMax = value;
}

Calendar GregorianCalendar___::GetDefaultInstance() {
  auto default = s_defaultInstance;
  if (default != nullptr) default = (s_defaultInstance = rt::newobj<GregorianCalendar>());

  return default;
}

void GregorianCalendar___::ctor() {
}

void GregorianCalendar___::ctor(GregorianCalendarTypes type) {
  if (type < GregorianCalendarTypes::Localized || type > GregorianCalendarTypes::TransliteratedFrench) {
    rt::throw_exception<ArgumentOutOfRangeException>("type", type, SR::Format(SR::get_ArgumentOutOfRange_Range(), GregorianCalendarTypes::Localized, GregorianCalendarTypes::TransliteratedFrench));
  }
  _type = type;
}

Int64 GregorianCalendar___::GetAbsoluteDate(Int32 year, Int32 month, Int32 day) {
  if (year >= 1 && year <= 9999 && month >= 1 && month <= 12) {
    Array<Int32> array = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? DaysToMonth366 : DaysToMonth365;
    if (day >= 1 && day <= array[month] - array[month - 1]) {
      Int32 num = year - 1;
      return num * 365 + num / 4 - num / 100 + num / 400 + array[month - 1] + day - 1;
    }
  }
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
}

Int64 GregorianCalendar___::DateToTicks(Int32 year, Int32 month, Int32 day) {
  return GetAbsoluteDate(year, month, day) * 864000000000;
}

DateTime GregorianCalendar___::AddMonths(DateTime time, Int32 months) {
  if (months < -120000 || months > 120000) {
    rt::throw_exception<ArgumentOutOfRangeException>("months", months, SR::Format(SR::get_ArgumentOutOfRange_Range(), -120000, 120000));
  }
  Int32 year;
  Int32 month;
  Int32 day;
  time.GetDate(year, month, day);
  Int32 num = month - 1 + months;
  if (num >= 0) {
    month = num % 12 + 1;
    year += num / 12;
  } else {
    month = 12 + (num + 1) % 12;
    year += (num - 11) / 12;
  }
  Array<Int32> array = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? DaysToMonth366 : DaysToMonth365;
  Int32 num2 = array[month] - array[month - 1];
  if (day > num2) {
    day = num2;
  }
  Int64 ticks = DateToTicks(year, month, day) + time.get_Ticks() % 864000000000;
  Calendar::in::CheckAddResult(ticks, get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return DateTime(ticks);
}

DateTime GregorianCalendar___::AddYears(DateTime time, Int32 years) {
  return AddMonths(time, years * 12);
}

Int32 GregorianCalendar___::GetDayOfMonth(DateTime time) {
  return time.get_Day();
}

DayOfWeek GregorianCalendar___::GetDayOfWeek(DateTime time) {
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 GregorianCalendar___::GetDayOfYear(DateTime time) {
  return time.get_DayOfYear();
}

Int32 GregorianCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
  Array<Int32> array = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? DaysToMonth366 : DaysToMonth365;
  return array[month] - array[month - 1];
}

Int32 GregorianCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
    return 365;
  }
  return 366;
}

Int32 GregorianCalendar___::GetEra(DateTime time) {
  return 1;
}

Int32 GregorianCalendar___::GetMonth(DateTime time) {
  return time.get_Month();
}

Int32 GregorianCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  return 12;
}

Int32 GregorianCalendar___::GetYear(DateTime time) {
  return time.get_Year();
}

Boolean GregorianCalendar___::IsValidYear(Int32 year, Int32 era) {
  if (year >= 1) {
    return year <= 9999;
  }
  return false;
}

Boolean GregorianCalendar___::IsValidDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  if ((era != 0 && era != 1) || year < 1 || year > 9999 || month < 1 || month > 12 || day < 1) {
    return false;
  }
  Array<Int32> array = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? DaysToMonth366 : DaysToMonth365;
  return day <= array[month] - array[month - 1];
}

Boolean GregorianCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 12));
  }
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  if (day < 1 || day > GetDaysInMonth(year, month)) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, GetDaysInMonth(year, month)));
  }
  if (IsLeapYear(year) && month == 2) {
    return day == 29;
  }
  return false;
}

Int32 GregorianCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  return 0;
}

Boolean GregorianCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 12));
  }
  return false;
}

Boolean GregorianCalendar___::IsLeapYear(Int32 year, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      return year % 400 == 0;
    }
    return true;
  }
  return false;
}

DateTime GregorianCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  return DateTime(year, month, day, hour, minute, second, millisecond);
}

Boolean GregorianCalendar___::TryToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era, DateTime& result) {
  if (era != 0 && era != 1) {
    result = DateTime::MinValue;
    return false;
  }
  return DateTime::TryCreate(year, month, day, hour, minute, second, millisecond, result);
}

Int32 GregorianCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  return Calendar::ToFourDigitYear(year);
}

void GregorianCalendar___::cctor() {
  DaysToMonth365 = rt::newarr<Array<Int32>>(13);
  DaysToMonth366 = rt::newarr<Array<Int32>>(13);
}

} // namespace System::Private::CoreLib::System::Globalization::GregorianCalendarNamespace
