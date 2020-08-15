#include "HebrewCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewCalendar-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::HebrewCalendarNamespace {
void HebrewCalendar___::DateBuffer___::ctor() {
}

ReadOnlySpan<Byte> HebrewCalendar___::get_HebrewTable() {
  return rt::newarr<Array<Byte>>(1316);
}

ReadOnlySpan<Byte> HebrewCalendar___::get_LunarMonthLen() {
  return rt::newarr<Array<Byte>>(98);
}

DateTime HebrewCalendar___::get_MinSupportedDateTime() {
  return s_calendarMinValue;
}

DateTime HebrewCalendar___::get_MaxSupportedDateTime() {
  return s_calendarMaxValue;
}

CalendarAlgorithmType HebrewCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
}

CalendarId HebrewCalendar___::get_ID() {
  return CalendarId::HEBREW;
}

Array<Int32> HebrewCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 HebrewCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 5790);
  }
  return _twoDigitYearMax;
}

void HebrewCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value != 99) {
    CheckHebrewYearValue(value, HebrewEra, "value");
  }
  _twoDigitYearMax = value;
}

void HebrewCalendar___::ctor() {
}

void HebrewCalendar___::CheckHebrewYearValue(Int32 y, Int32 era, String varName) {
  CheckEraRange(era);
  if (y > 5999 || y < 5343) {
    rt::throw_exception<ArgumentOutOfRangeException>(varName, y, SR::Format(SR::get_ArgumentOutOfRange_Range(), 5343, 5999));
  }
}

void HebrewCalendar___::CheckHebrewMonthValue(Int32 year, Int32 month, Int32 era) {
  Int32 monthsInYear = GetMonthsInYear(year, era);
  if (month < 1 || month > monthsInYear) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, monthsInYear));
  }
}

void HebrewCalendar___::CheckHebrewDayValue(Int32 year, Int32 month, Int32 day, Int32 era) {
  Int32 daysInMonth = GetDaysInMonth(year, month, era);
  if (day < 1 || day > daysInMonth) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, daysInMonth));
  }
}

void HebrewCalendar___::CheckEraRange(Int32 era) {
  if (era != 0 && era != HebrewEra) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
}

void HebrewCalendar___::CheckTicksRange(Int64 ticks) {
  if (ticks < s_calendarMinValue.get_Ticks() || ticks > s_calendarMaxValue.get_Ticks()) {
    rt::throw_exception<ArgumentOutOfRangeException>("time", ticks, SR::Format(CultureInfo::in::get_InvariantCulture(), SR::get_ArgumentOutOfRange_CalendarRange(), s_calendarMinValue, s_calendarMaxValue));
  }
}

Int32 HebrewCalendar___::GetResult(DateBuffer result, Int32 part) {
  switch (part.get()) {
    case 0:
      return result->year;
    case 2:
      return result->month;
    case 3:
      return result->day;
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_DateTimeParsing());
  }
}

Int32 HebrewCalendar___::GetLunarMonthDay(Int32 gregorianYear, DateBuffer lunarDate) {
  Int32 num = gregorianYear - 1583;
  if (num < 0 || num > 656) {
    rt::throw_exception<ArgumentOutOfRangeException>("gregorianYear");
  }
  num *= 2;
  lunarDate->day = get_HebrewTable()[num];
  Int32 result = get_HebrewTable()[num + 1];
  switch (lunarDate->day.get()) {
    case 0:
      lunarDate->month = 5;
      lunarDate->day = 1;
      break;
    case 30:
      lunarDate->month = 3;
      break;
    case 31:
      lunarDate->month = 5;
      lunarDate->day = 2;
      break;
    case 32:
      lunarDate->month = 5;
      lunarDate->day = 3;
      break;
    case 33:
      lunarDate->month = 3;
      lunarDate->day = 29;
      break;
    default:
      lunarDate->month = 4;
      break;
  }
  return result;
}

Int32 HebrewCalendar___::GetDatePart(Int64 ticks, Int32 part) {
  CheckTicksRange(ticks);
  Int32 year;
  Int32 month;
  Int32 day;
  DateTime(ticks).GetDate(year, month, day);
  DateBuffer dateBuffer = rt::newobj<DateBuffer>();
  dateBuffer->year = year + 3760;
  Int32 num = GetLunarMonthDay(year, dateBuffer);
  DateBuffer dateBuffer2 = rt::newobj<DateBuffer>();
  dateBuffer2->year = dateBuffer->year;
  dateBuffer2->month = dateBuffer->month;
  dateBuffer2->day = dateBuffer->day;
  Int64 absoluteDate = GregorianCalendar::in::GetAbsoluteDate(year, month, day);
  if (month == 1 && day == 1) {
    return GetResult(dateBuffer2, part);
  }
  Int64 num2 = absoluteDate - GregorianCalendar::in::GetAbsoluteDate(year, 1, 1);
  if (num2 + dateBuffer->day <= get_LunarMonthLen()[num * 14 + dateBuffer->month]) {
    dateBuffer2->day += (Int32)num2;
    return GetResult(dateBuffer2, part);
  }
  dateBuffer2->month++;
  dateBuffer2->day = 1;
  num2 -= get_LunarMonthLen()[num * 14 + dateBuffer->month] - dateBuffer->day;
  if (num2 > 1) {
    while (num2 > get_LunarMonthLen()[num * 14 + dateBuffer2->month]) {
      num2 -= get_LunarMonthLen()[num * 14 + dateBuffer2->month++];
      if (dateBuffer2->month > 13 || get_LunarMonthLen()[num * 14 + dateBuffer2->month] == 0) {
        dateBuffer2->year++;
        num = get_HebrewTable()[(year + 1 - 1583) * 2 + 1];
        dateBuffer2->month = 1;
      }
    }
    dateBuffer2->day += (Int32)(num2 - 1);
  }
  return GetResult(dateBuffer2, part);
}

DateTime HebrewCalendar___::AddMonths(DateTime time, Int32 months) {
  try {
    Int32 num = GetDatePart(time.get_Ticks(), 0);
    Int32 datePart = GetDatePart(time.get_Ticks(), 2);
    Int32 num2 = GetDatePart(time.get_Ticks(), 3);
    Int32 num3;
    if (months >= 0) {
      Int32 monthsInYear;
      for (num3 = datePart + months; num3 > (monthsInYear = GetMonthsInYear(num, 0)); num3 -= monthsInYear) {
        num++;
      }
    } else if ((num3 = datePart + months) <= 0) {
      months = -months;
      months -= datePart;
      num--;
      Int32 monthsInYear;
      while (months > (monthsInYear = GetMonthsInYear(num, 0))) {
        num--;
        months -= monthsInYear;
      }
      monthsInYear = GetMonthsInYear(num, 0);
      num3 = monthsInYear - months;
    }

    Int32 daysInMonth = GetDaysInMonth(num, num3);
    if (num2 > daysInMonth) {
      num2 = daysInMonth;
    }
    return DateTime(ToDateTime(num, num3, num2, 0, 0, 0, 0).get_Ticks() + time.get_Ticks() % 864000000000);
  } catch (ArgumentException) {
  }
}

DateTime HebrewCalendar___::AddYears(DateTime time, Int32 years) {
  Int32 datePart = GetDatePart(time.get_Ticks(), 0);
  Int32 num = GetDatePart(time.get_Ticks(), 2);
  Int32 num2 = GetDatePart(time.get_Ticks(), 3);
  datePart += years;
  CheckHebrewYearValue(datePart, 0, "years");
  Int32 monthsInYear = GetMonthsInYear(datePart, 0);
  if (num > monthsInYear) {
    num = monthsInYear;
  }
  Int32 daysInMonth = GetDaysInMonth(datePart, num);
  if (num2 > daysInMonth) {
    num2 = daysInMonth;
  }
  Int64 ticks = ToDateTime(datePart, num, num2, 0, 0, 0, 0).get_Ticks() + time.get_Ticks() % 864000000000;
  Calendar::in::CheckAddResult(ticks, get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return DateTime(ticks);
}

Int32 HebrewCalendar___::GetDayOfMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 3);
}

DayOfWeek HebrewCalendar___::GetDayOfWeek(DateTime time) {
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 HebrewCalendar___::GetHebrewYearType(Int32 year, Int32 era) {
  CheckHebrewYearValue(year, era, "year");
  return get_HebrewTable()[(year - 3760 - 1583) * 2 + 1];
}

Int32 HebrewCalendar___::GetDayOfYear(DateTime time) {
  Int32 year = GetYear(time);
  DateTime dateTime = (year != 5343) ? ToDateTime(year, 1, 1, 0, 0, 0, 0, 0) : DateTime(1582, 9, 27);
  return (Int32)((time.get_Ticks() - dateTime.get_Ticks()) / 864000000000) + 1;
}

Int32 HebrewCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  CheckEraRange(era);
  Int32 hebrewYearType = GetHebrewYearType(year, era);
  CheckHebrewMonthValue(year, month, era);
  Int32 num = get_LunarMonthLen()[hebrewYearType * 14 + month];
  if (num == 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
  return num;
}

Int32 HebrewCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  CheckEraRange(era);
  Int32 hebrewYearType = GetHebrewYearType(year, era);
  if (hebrewYearType < 4) {
    return 352 + hebrewYearType;
  }
  return 382 + (hebrewYearType - 3);
}

Int32 HebrewCalendar___::GetEra(DateTime time) {
  return HebrewEra;
}

Int32 HebrewCalendar___::GetMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 2);
}

Int32 HebrewCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  if (!IsLeapYear(year, era)) {
    return 12;
  }
  return 13;
}

Int32 HebrewCalendar___::GetYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 0);
}

Boolean HebrewCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  if (IsLeapMonth(year, month, era)) {
    CheckHebrewDayValue(year, month, day, era);
    return true;
  }
  if (IsLeapYear(year, 0) && month == 6 && day == 30) {
    return true;
  }
  CheckHebrewDayValue(year, month, day, era);
  return false;
}

Int32 HebrewCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  if (IsLeapYear(year, era)) {
    return 7;
  }
  return 0;
}

Boolean HebrewCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  Boolean flag = IsLeapYear(year, era);
  CheckHebrewMonthValue(year, month, era);
  if (flag) {
    return month == 7;
  }
  return false;
}

Boolean HebrewCalendar___::IsLeapYear(Int32 year, Int32 era) {
  CheckHebrewYearValue(year, era, "year");
  return (7 * (Int64)year + 1) % 19 < 7;
}

Int32 HebrewCalendar___::GetDayDifference(Int32 lunarYearType, Int32 month1, Int32 day1, Int32 month2, Int32 day2) {
  if (month1 == month2) {
    return day1 - day2;
  }
  Boolean flag = month1 > month2;
  if (flag) {
    Int32 num = month1;
    Int32 num2 = day1;
    month1 = month2;
    day1 = day2;
    month2 = num;
    day2 = num2;
  }
  Int32 num3 = get_LunarMonthLen()[lunarYearType * 14 + month1] - day1;
  month1++;
  while (month1 < month2) {
    num3 += get_LunarMonthLen()[lunarYearType * 14 + month1++];
  }
  num3 += day2;
  if (!flag) {
    return -num3;
  }
  return num3;
}

DateTime HebrewCalendar___::HebrewToGregorian(Int32 hebrewYear, Int32 hebrewMonth, Int32 hebrewDay, Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  Int32 num = hebrewYear - 3760;
  DateBuffer dateBuffer = rt::newobj<DateBuffer>();
  Int32 lunarMonthDay = GetLunarMonthDay(num, dateBuffer);
  if (hebrewMonth == dateBuffer->month && hebrewDay == dateBuffer->day) {
    return DateTime(num, 1, 1, hour, minute, second, millisecond);
  }
  Int32 dayDifference = GetDayDifference(lunarMonthDay, hebrewMonth, hebrewDay, dateBuffer->month, dateBuffer->day);
  return DateTime(DateTime(num, 1, 1).get_Ticks() + dayDifference * 864000000000 + Calendar::in::TimeToTicks(hour, minute, second, millisecond));
}

DateTime HebrewCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  CheckHebrewYearValue(year, era, "year");
  CheckHebrewMonthValue(year, month, era);
  CheckHebrewDayValue(year, month, day, era);
  DateTime result = HebrewToGregorian(year, month, day, hour, minute, second, millisecond);
  CheckTicksRange(result.get_Ticks());
  return result;
}

Int32 HebrewCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year < 100) {
    return Calendar::in::ToFourDigitYear(year);
  }
  if (year > 5999 || year < 5343) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 5343, 5999));
  }
  return year;
}

void HebrewCalendar___::cctor() {
  HebrewEra = 1;
  s_calendarMinValue = DateTime(1583, 1, 1);
  s_calendarMaxValue = DateTime(DateTime(2239, 9, 29, 23, 59, 59, 999).get_Ticks() + 9999);
}

} // namespace System::Private::CoreLib::System::Globalization::HebrewCalendarNamespace
