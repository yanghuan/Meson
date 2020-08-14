#include "PersianCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendricalCalculationsHelper-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::PersianCalendarNamespace {
DateTime PersianCalendar___::get_MinSupportedDateTime() {
  return s_minDate;
}

DateTime PersianCalendar___::get_MaxSupportedDateTime() {
  return s_maxDate;
}

CalendarAlgorithmType PersianCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

CalendarId PersianCalendar___::get_BaseCalendarID() {
  return CalendarId::GREGORIAN;
}

CalendarId PersianCalendar___::get_ID() {
  return CalendarId::PERSIAN;
}

Array<Int32> PersianCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 PersianCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 1410);
  }
  return _twoDigitYearMax;
}

void PersianCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > 9378) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, 9378));
  }
  _twoDigitYearMax = value;
}

void PersianCalendar___::ctor() {
}

Int64 PersianCalendar___::GetAbsoluteDatePersian(Int32 year, Int32 month, Int32 day) {
  if (year < 1 || year > 9378 || month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
  }
  Int32 num = DaysInPreviousMonths(month) + day - 1;
  Int32 num2 = (Int32)(365.242189 * (Double)(year - 1));
  Int64 num3 = CalendricalCalculationsHelper::PersianNewYearOnOrBefore(s_persianEpoch + num2 + 180);
  return num3 + num;
}

void PersianCalendar___::CheckTicksRange(Int64 ticks) {
  if (ticks < s_minDate.get_Ticks() || ticks > s_maxDate.get_Ticks()) {
    rt::throw_exception<ArgumentOutOfRangeException>("time", ticks, SR::Format(SR::get_ArgumentOutOfRange_CalendarRange(), s_minDate, s_maxDate));
  }
}

void PersianCalendar___::CheckEraRange(Int32 era) {
  if (era != 0 && era != PersianEra) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
}

void PersianCalendar___::CheckYearRange(Int32 year, Int32 era) {
  CheckEraRange(era);
  if (year < 1 || year > 9378) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9378));
  }
}

void PersianCalendar___::CheckYearMonthRange(Int32 year, Int32 month, Int32 era) {
  CheckYearRange(year, era);
  if (year == 9378 && month > 10) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 10));
  }
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
}

Int32 PersianCalendar___::MonthFromOrdinalDay(Int32 ordinalDay) {
  Int32 i;
  for (i = 0; ordinalDay > s_daysToMonth[i]; i++) {
  }
  return i;
}

Int32 PersianCalendar___::DaysInPreviousMonths(Int32 month) {
  month--;
  return s_daysToMonth[month];
}

Int32 PersianCalendar___::GetDatePart(Int64 ticks, Int32 part) {
  CheckTicksRange(ticks);
  Int64 num = ticks / 864000000000 + 1;
  Int64 num2 = CalendricalCalculationsHelper::PersianNewYearOnOrBefore(num);
  Int32 num3 = (Int32)Math::Floor((Double)(num2 - s_persianEpoch) / 365.242189 + 0.5) + 1;
  if (part == 0) {
    return num3;
  }
  Int32 num4 = (Int32)(num - CalendricalCalculationsHelper::GetNumberOfDays(ToDateTime(num3, 1, 1, 0, 0, 0, 0, 1)));
  if (part == 1) {
    return num4;
  }
  Int32 num5 = MonthFromOrdinalDay(num4);
  if (part == 2) {
    return num5;
  }
  Int32 result = num4 - DaysInPreviousMonths(num5);
  if (part == 3) {
    return result;
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_DateTimeParsing());
}

DateTime PersianCalendar___::AddMonths(DateTime time, Int32 months) {
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
  Int32 daysInMonth = GetDaysInMonth(datePart, datePart2);
  if (num > daysInMonth) {
    num = daysInMonth;
  }
  Int64 ticks = GetAbsoluteDatePersian(datePart, datePart2, num) * 864000000000 + time.get_Ticks() % 864000000000;
  Calendar::in::CheckAddResult(ticks, get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return DateTime(ticks);
}

DateTime PersianCalendar___::AddYears(DateTime time, Int32 years) {
  return AddMonths(time, years * 12);
}

Int32 PersianCalendar___::GetDayOfMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 3);
}

DayOfWeek PersianCalendar___::GetDayOfWeek(DateTime time) {
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 PersianCalendar___::GetDayOfYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 1);
}

Int32 PersianCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearMonthRange(year, month, era);
  if (month == 10 && year == 9378) {
    return 13;
  }
  Int32 num = s_daysToMonth[month] - s_daysToMonth[month - 1];
  if (month == 12 && !IsLeapYear(year)) {
    num--;
  }
  return num;
}

Int32 PersianCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  if (year == 9378) {
    return s_daysToMonth[9] + 13;
  }
  if (!IsLeapYear(year, 0)) {
    return 365;
  }
  return 366;
}

Int32 PersianCalendar___::GetEra(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return PersianEra;
}

Int32 PersianCalendar___::GetMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 2);
}

Int32 PersianCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  if (year == 9378) {
    return 10;
  }
  return 12;
}

Int32 PersianCalendar___::GetYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 0);
}

Boolean PersianCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  Int32 daysInMonth = GetDaysInMonth(year, month, era);
  if (day < 1 || day > daysInMonth) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), daysInMonth, month));
  }
  if (IsLeapYear(year, era) && month == 12) {
    return day == 30;
  }
  return false;
}

Int32 PersianCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return 0;
}

Boolean PersianCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearMonthRange(year, month, era);
  return false;
}

Boolean PersianCalendar___::IsLeapYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  if (year == 9378) {
    return false;
  }
  return GetAbsoluteDatePersian(year + 1, 1, 1) - GetAbsoluteDatePersian(year, 1, 1) == 366;
}

DateTime PersianCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  Int32 daysInMonth = GetDaysInMonth(year, month, era);
  if (day < 1 || day > daysInMonth) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), daysInMonth, month));
  }
  Int64 absoluteDatePersian = GetAbsoluteDatePersian(year, month, day);
  if (absoluteDatePersian < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
  }
  return DateTime(absoluteDatePersian * 864000000000 + Calendar::in::TimeToTicks(hour, minute, second, millisecond));
}

Int32 PersianCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year < 100) {
  }
  if (year > 9378) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9378));
  }
  return year;
}

void PersianCalendar___::cctor() {
  PersianEra = 1;
  s_persianEpoch = DateTime(622, 3, 22).get_Ticks() / 864000000000;
  s_daysToMonth = rt::newarr<Array<Int32>>(13);
  s_minDate = DateTime(622, 3, 22);
  s_maxDate = DateTime::MaxValue;
}

} // namespace System::Private::CoreLib::System::Globalization::PersianCalendarNamespace
