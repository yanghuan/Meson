#include "GregorianCalendarHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/InternalGlobalizationHelper-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::GregorianCalendarHelperNamespace {
Int32 GregorianCalendarHelper___::get_MaxYear() {
  return m_maxYear;
}

Array<Int32> GregorianCalendarHelper___::get_Eras() {
  if (m_eras == nullptr) {
    m_eras = rt::newarr<Array<Int32>>(m_EraInfo->get_Length());
    for (Int32 i = 0; i < m_EraInfo->get_Length(); i++) {
      m_eras[i] = m_EraInfo[i]->era;
    }
  }
  return (Array<Int32>)m_eras->Clone();
}

void GregorianCalendarHelper___::ctor(Calendar cal, Array<EraInfo> eraInfo) {
  m_Cal = cal;
  m_EraInfo = eraInfo;
  m_maxYear = m_EraInfo[0]->maxEraYear;
  m_minYear = m_EraInfo[0]->minEraYear;
}

Int32 GregorianCalendarHelper___::GetYearOffset(Int32 year, Int32 era, Boolean throwOnError) {
  if (year < 0) {
    if (throwOnError) {
      rt::throw_exception<ArgumentOutOfRangeException>("year", SR::get_ArgumentOutOfRange_NeedNonNegNum());
    }
    return -1;
  }
  if (era == 0) {
    era = m_Cal->get_CurrentEraValue();
  }
  for (Int32 i = 0; i < m_EraInfo->get_Length(); i++) {
    if (era != m_EraInfo[i]->era) {
      continue;
    }
    if (year >= m_EraInfo[i]->minEraYear) {
      if (year <= m_EraInfo[i]->maxEraYear) {
        return m_EraInfo[i]->yearOffset;
      }
      if (!LocalAppContextSwitches::get_EnforceJapaneseEraYearRanges()) {
        Int32 num = year - m_EraInfo[i]->maxEraYear;
        for (Int32 num2 = i - 1; num2 >= 0; num2--) {
          if (num <= m_EraInfo[num2]->maxEraYear) {
            return m_EraInfo[i]->yearOffset;
          }
          num -= m_EraInfo[num2]->maxEraYear;
        }
      }
    }
    if (!throwOnError) {
      break;
    }
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::Format(SR::get_ArgumentOutOfRange_Range(), m_EraInfo[i]->minEraYear, m_EraInfo[i]->maxEraYear));
  }
  if (throwOnError) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  return -1;
}

Int32 GregorianCalendarHelper___::GetGregorianYear(Int32 year, Int32 era) {
  return GetYearOffset(year, era, true) + year;
}

Boolean GregorianCalendarHelper___::IsValidYear(Int32 year, Int32 era) {
  return GetYearOffset(year, era, false) >= 0;
}

Int32 GregorianCalendarHelper___::GetDatePart(Int64 ticks, Int32 part) {
  CheckTicksRange(ticks);
  Int32 num = (Int32)(ticks / 864000000000);
  Int32 num2 = num / 146097;
  num -= num2 * 146097;
  Int32 num3 = num / 36524;
  if (num3 == 4) {
    num3 = 3;
  }
  num -= num3 * 36524;
  Int32 num4 = num / 1461;
  num -= num4 * 1461;
  Int32 num5 = num / 365;
  if (num5 == 4) {
    num5 = 3;
  }
  if (part == 0) {
    return num2 * 400 + num3 * 100 + num4 * 4 + num5 + 1;
  }
  num -= num5 * 365;
  if (part == 1) {
    return num + 1;
  }
  Array<Int32> array = ((num5 == 3 && (num4 != 24 || num3 == 3)) ? DaysToMonth366 : DaysToMonth365);
  Int32 i;
  for (i = (num >> 5) + 1; num >= array[i]; i++) {
  }
  if (part == 2) {
    return i;
  }
  return num - array[i - 1] + 1;
}

Int64 GregorianCalendarHelper___::GetAbsoluteDate(Int32 year, Int32 month, Int32 day) {
  if (year >= 1 && year <= 9999 && month >= 1 && month <= 12) {
    Array<Int32> array = ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? DaysToMonth366 : DaysToMonth365);
    if (day >= 1 && day <= array[month] - array[month - 1]) {
      Int32 num = year - 1;
      Int32 num2 = num * 365 + num / 4 - num / 100 + num / 400 + array[month - 1] + day - 1;
      return num2;
    }
  }
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
}

Int64 GregorianCalendarHelper___::DateToTicks(Int32 year, Int32 month, Int32 day) {
  return GetAbsoluteDate(year, month, day) * 864000000000;
}

Int64 GregorianCalendarHelper___::TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60) {
    if (millisecond < 0 || millisecond >= 1000) {
      rt::throw_exception<ArgumentOutOfRangeException>("millisecond", SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
    }
    return InternalGlobalizationHelper::TimeToTicks(hour, minute, second) + (Int64)millisecond * 10000;
  }
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
}

void GregorianCalendarHelper___::CheckTicksRange(Int64 ticks) {
  if (ticks < m_Cal->get_MinSupportedDateTime().get_Ticks() || ticks > m_Cal->get_MaxSupportedDateTime().get_Ticks()) {
    rt::throw_exception<ArgumentOutOfRangeException>("time", SR::Format(CultureInfo::in::get_InvariantCulture(), SR::get_ArgumentOutOfRange_CalendarRange(), m_Cal->get_MinSupportedDateTime(), m_Cal->get_MaxSupportedDateTime()));
  }
}

DateTime GregorianCalendarHelper___::AddMonths(DateTime time, Int32 months) {
  if (months < -120000 || months > 120000) {
    rt::throw_exception<ArgumentOutOfRangeException>("months", SR::Format(SR::get_ArgumentOutOfRange_Range(), -120000, 120000));
  }
  CheckTicksRange(time.get_Ticks());
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
  Array<Int32> array = ((datePart % 4 == 0 && (datePart % 100 != 0 || datePart % 400 == 0)) ? DaysToMonth366 : DaysToMonth365);
  Int32 num3 = array[datePart2] - array[datePart2 - 1];
  if (num > num3) {
    num = num3;
  }
  Int64 ticks = DateToTicks(datePart, datePart2, num) + time.get_Ticks() % 864000000000;
  Calendar::in::CheckAddResult(ticks, m_Cal->get_MinSupportedDateTime(), m_Cal->get_MaxSupportedDateTime());
  return DateTime(ticks);
}

DateTime GregorianCalendarHelper___::AddYears(DateTime time, Int32 years) {
  return AddMonths(time, years * 12);
}

Int32 GregorianCalendarHelper___::GetDayOfMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 3);
}

DayOfWeek GregorianCalendarHelper___::GetDayOfWeek(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return (DayOfWeek)((time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 GregorianCalendarHelper___::GetDayOfYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 1);
}

Int32 GregorianCalendarHelper___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  year = GetGregorianYear(year, era);
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", SR::get_ArgumentOutOfRange_Month());
  }
  Array<Int32> array = ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? DaysToMonth366 : DaysToMonth365);
  return array[month] - array[month - 1];
}

Int32 GregorianCalendarHelper___::GetDaysInYear(Int32 year, Int32 era) {
  year = GetGregorianYear(year, era);
  if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
    return 365;
  }
  return 366;
}

Int32 GregorianCalendarHelper___::GetEra(DateTime time) {
  Int64 ticks = time.get_Ticks();
  for (Int32 i = 0; i < m_EraInfo->get_Length(); i++) {
    if (ticks >= m_EraInfo[i]->ticks) {
      return m_EraInfo[i]->era;
    }
  }
  rt::throw_exception<ArgumentOutOfRangeException>("time", SR::get_ArgumentOutOfRange_Era());
}

Int32 GregorianCalendarHelper___::GetMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 2);
}

Int32 GregorianCalendarHelper___::GetMonthsInYear(Int32 year, Int32 era) {
  ValidateYearInEra(year, era);
  return 12;
}

Int32 GregorianCalendarHelper___::GetYear(DateTime time) {
  Int64 ticks = time.get_Ticks();
  Int32 datePart = GetDatePart(ticks, 0);
  for (Int32 i = 0; i < m_EraInfo->get_Length(); i++) {
    if (ticks >= m_EraInfo[i]->ticks) {
      return datePart - m_EraInfo[i]->yearOffset;
    }
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_NoEra());
}

Int32 GregorianCalendarHelper___::GetYear(Int32 year, DateTime time) {
  Int64 ticks = time.get_Ticks();
  for (Int32 i = 0; i < m_EraInfo->get_Length(); i++) {
    if (ticks >= m_EraInfo[i]->ticks && year > m_EraInfo[i]->yearOffset) {
      return year - m_EraInfo[i]->yearOffset;
    }
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_NoEra());
}

Boolean GregorianCalendarHelper___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  if (day < 1 || day > GetDaysInMonth(year, month, era)) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, GetDaysInMonth(year, month, era)));
  }
  if (!IsLeapYear(year, era)) {
    return false;
  }
  if (month == 2 && day == 29) {
    return true;
  }
  return false;
}

void GregorianCalendarHelper___::ValidateYearInEra(Int32 year, Int32 era) {
  GetYearOffset(year, era, true);
}

Int32 GregorianCalendarHelper___::GetLeapMonth(Int32 year, Int32 era) {
  ValidateYearInEra(year, era);
  return 0;
}

Boolean GregorianCalendarHelper___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  ValidateYearInEra(year, era);
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 12));
  }
  return false;
}

Boolean GregorianCalendarHelper___::IsLeapYear(Int32 year, Int32 era) {
  year = GetGregorianYear(year, era);
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      return year % 400 == 0;
    }
    return true;
  }
  return false;
}

DateTime GregorianCalendarHelper___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  year = GetGregorianYear(year, era);
  Int64 ticks = DateToTicks(year, month, day) + TimeToTicks(hour, minute, second, millisecond);
  CheckTicksRange(ticks);
  return DateTime(ticks);
}

Int32 GregorianCalendarHelper___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  CheckTicksRange(time.get_Ticks());
  return GregorianCalendar::in::GetDefaultInstance()->GetWeekOfYear(time, rule, firstDayOfWeek);
}

Int32 GregorianCalendarHelper___::ToFourDigitYear(Int32 year, Int32 twoDigitYearMax) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (year < 100) {
    Int32 num = year % 100;
    return (twoDigitYearMax / 100 - ((num > twoDigitYearMax % 100) ? 1 : 0)) * 100 + num;
  }
  if (year < m_minYear || year > m_maxYear) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::Format(SR::get_ArgumentOutOfRange_Range(), m_minYear, m_maxYear));
  }
  return year;
}

void GregorianCalendarHelper___::cctor() {
  DaysToMonth365 = rt::newarr<Array<Int32>>(13);
  DaysToMonth366 = rt::newarr<Array<Int32>>(13);
}

} // namespace System::Private::CoreLib::System::Globalization::GregorianCalendarHelperNamespace
