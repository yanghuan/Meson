#include "Calendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/Calendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarData-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/InternalGlobalizationHelper-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::CalendarNamespace {
DateTime Calendar___::get_MinSupportedDateTime() {
  return DateTime::MinValue;
}

DateTime Calendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType Calendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::Unknown;
}

CalendarId Calendar___::get_ID() {
  return CalendarId::UNINITIALIZED_VALUE;
}

CalendarId Calendar___::get_BaseCalendarID() {
  return get_ID();
}

Boolean Calendar___::get_IsReadOnly() {
  return _isReadOnly;
}

Int32 Calendar___::get_CurrentEraValue() {
  if (_currentEraValue == -1) {
    _currentEraValue = CalendarData::in::GetCalendarData(get_BaseCalendarID())->iCurrentEra;
  }
  return _currentEraValue;
}

Int32 Calendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 365;
}

Int32 Calendar___::get_TwoDigitYearMax() {
  return _twoDigitYearMax;
}

void Calendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  _twoDigitYearMax = value;
}

void Calendar___::ctor() {
  _currentEraValue = -1;
  _twoDigitYearMax = -1;
  Object::in::ctor();
}

Object Calendar___::Clone() {
  Object obj = MemberwiseClone();
  ((Calendar)obj)->SetReadOnlyState(false);
  return obj;
}

Calendar Calendar___::ReadOnly(Calendar calendar) {
  if (calendar == nullptr) {
    rt::throw_exception<ArgumentNullException>("calendar");
  }
  if (calendar->get_IsReadOnly()) {
    return calendar;
  }
  Calendar calendar2 = (Calendar)calendar->MemberwiseClone();
  calendar2->SetReadOnlyState(true);
  return calendar2;
}

void Calendar___::VerifyWritable() {
  if (_isReadOnly) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
}

void Calendar___::SetReadOnlyState(Boolean readOnly) {
  _isReadOnly = readOnly;
}

void Calendar___::CheckAddResult(Int64 ticks, DateTime minValue, DateTime maxValue) {
  if (ticks < minValue.get_Ticks() || ticks > maxValue.get_Ticks()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResultCalendarRange(), minValue, maxValue));
  }
}

DateTime Calendar___::Add(DateTime time, Double value, Int32 scale) {
  Double num = value * (Double)scale + ((value >= 0) ? 0.5 : (-0.5));
  if (!(num > -315537897600000) || !(num < 315537897600000)) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::get_ArgumentOutOfRange_AddValue());
  }
  Int64 num2 = (Int64)num;
  Int64 ticks = time.get_Ticks() + num2 * 10000;
  CheckAddResult(ticks, get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return DateTime(ticks);
}

DateTime Calendar___::AddMilliseconds(DateTime time, Double milliseconds) {
  return Add(time, milliseconds, 1);
}

DateTime Calendar___::AddDays(DateTime time, Int32 days) {
  return Add(time, days, 86400000);
}

DateTime Calendar___::AddHours(DateTime time, Int32 hours) {
  return Add(time, hours, 3600000);
}

DateTime Calendar___::AddMinutes(DateTime time, Int32 minutes) {
  return Add(time, minutes, 60000);
}

DateTime Calendar___::AddSeconds(DateTime time, Int32 seconds) {
  return Add(time, seconds, 1000);
}

DateTime Calendar___::AddWeeks(DateTime time, Int32 weeks) {
  return AddDays(time, weeks * 7);
}

Int32 Calendar___::GetDaysInMonth(Int32 year, Int32 month) {
  return GetDaysInMonth(year, month, 0);
}

Int32 Calendar___::GetDaysInYear(Int32 year) {
  return GetDaysInYear(year, 0);
}

Int32 Calendar___::GetHour(DateTime time) {
  return (Int32)(time.get_Ticks() / 36000000000 % 24);
}

Double Calendar___::GetMilliseconds(DateTime time) {
  return time.get_Ticks() / 10000 % 1000;
}

Int32 Calendar___::GetMinute(DateTime time) {
  return (Int32)(time.get_Ticks() / 600000000 % 60);
}

Int32 Calendar___::GetMonthsInYear(Int32 year) {
  return GetMonthsInYear(year, 0);
}

Int32 Calendar___::GetSecond(DateTime time) {
  return (Int32)(time.get_Ticks() / 10000000 % 60);
}

Int32 Calendar___::GetFirstDayWeekOfYear(DateTime time, Int32 firstDayOfWeek) {
  Int32 num = GetDayOfYear(time) - 1;
  Int32 num2 = (Int32)(GetDayOfWeek(time) - num % 7);
  Int32 num3 = (num2 - firstDayOfWeek + 14) % 7;
  return (num + num3) / 7 + 1;
}

Int32 Calendar___::GetWeekOfYearFullDays(DateTime time, Int32 firstDayOfWeek, Int32 fullDays) {
  Int32 num = GetDayOfYear(time) - 1;
  Int32 num2 = (Int32)(GetDayOfWeek(time) - num % 7);
  Int32 num3 = (firstDayOfWeek - num2 + 14) % 7;
  if (num3 != 0 && num3 >= fullDays) {
    num3 -= 7;
  }
  Int32 num4 = num - num3;
  if (num4 >= 0) {
    return num4 / 7 + 1;
  }
  if (time <= get_MinSupportedDateTime().AddDays(num)) {
    return GetWeekOfYearOfMinSupportedDateTime(firstDayOfWeek, fullDays);
  }
  return GetWeekOfYearFullDays(time.AddDays(-(num + 1)), firstDayOfWeek, fullDays);
}

Int32 Calendar___::GetWeekOfYearOfMinSupportedDateTime(Int32 firstDayOfWeek, Int32 minimumDaysInFirstWeek) {
  Int32 num = GetDayOfYear(get_MinSupportedDateTime()) - 1;
  Int32 num2 = (Int32)(GetDayOfWeek(get_MinSupportedDateTime()) - num % 7);
  Int32 num3 = (firstDayOfWeek + 7 - num2) % 7;
  if (num3 == 0 || num3 >= minimumDaysInFirstWeek) {
    return 1;
  }
  Int32 num4 = get_DaysInYearBeforeMinSupportedYear() - 1;
  Int32 num5 = num2 - 1 - num4 % 7;
  Int32 num6 = (firstDayOfWeek - num5 + 14) % 7;
  Int32 num7 = num4 - num6;
  if (num6 >= minimumDaysInFirstWeek) {
    num7 += 7;
  }
  return num7 / 7 + 1;
}

Int32 Calendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  if (firstDayOfWeek < DayOfWeek::Sunday || firstDayOfWeek > DayOfWeek::Saturday) {
    rt::throw_exception<ArgumentOutOfRangeException>("firstDayOfWeek", firstDayOfWeek, SR::Format(SR::get_ArgumentOutOfRange_Range(), DayOfWeek::Sunday, DayOfWeek::Saturday));
  }
}

Boolean Calendar___::IsLeapDay(Int32 year, Int32 month, Int32 day) {
  return IsLeapDay(year, month, day, 0);
}

Boolean Calendar___::IsLeapMonth(Int32 year, Int32 month) {
  return IsLeapMonth(year, month, 0);
}

Int32 Calendar___::GetLeapMonth(Int32 year) {
  return GetLeapMonth(year, 0);
}

Int32 Calendar___::GetLeapMonth(Int32 year, Int32 era) {
  if (!IsLeapYear(year, era)) {
    return 0;
  }
  Int32 monthsInYear = GetMonthsInYear(year, era);
  for (Int32 i = 1; i <= monthsInYear; i++) {
    if (IsLeapMonth(year, i, era)) {
      return i;
    }
  }
  return 0;
}

Boolean Calendar___::IsLeapYear(Int32 year) {
  return IsLeapYear(year, 0);
}

DateTime Calendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  return ToDateTime(year, month, day, hour, minute, second, millisecond, 0);
}

Boolean Calendar___::TryToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era, DateTime& result) {
  result = DateTime::MinValue;
  try {
    result = ToDateTime(year, month, day, hour, minute, second, millisecond, era);
    return true;
  } catch (ArgumentException) {
    return false;
  }
}

Boolean Calendar___::IsValidYear(Int32 year, Int32 era) {
  if (year >= GetYear(get_MinSupportedDateTime())) {
    return year <= GetYear(get_MaxSupportedDateTime());
  }
  return false;
}

Boolean Calendar___::IsValidMonth(Int32 year, Int32 month, Int32 era) {
  if (IsValidYear(year, era) && month >= 1) {
    return month <= GetMonthsInYear(year, era);
  }
  return false;
}

Boolean Calendar___::IsValidDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  if (IsValidMonth(year, month, era) && day >= 1) {
    return day <= GetDaysInMonth(year, month, era);
  }
  return false;
}

Int32 Calendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year < 100) {
    return (get_TwoDigitYearMax() / 100 - ((year > get_TwoDigitYearMax() % 100) ? 1 : 0)) * 100 + year;
  }
  return year;
}

Int64 Calendar___::TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
  }
  if (millisecond < 0 || millisecond >= 1000) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecond", millisecond, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
  }
  return InternalGlobalizationHelper::TimeToTicks(hour, minute, second) + (Int64)millisecond * 10000;
}

Int32 Calendar___::GetSystemTwoDigitYearSetting(CalendarId CalID, Int32 defaultYearValue) {
  Int32 num = (GlobalizationMode::get_UseNls() ? CalendarData::in::NlsGetTwoDigitYearMax(CalID) : CalendarData::in::IcuGetTwoDigitYearMax(CalID));
  if (num < 0) {
    return defaultYearValue;
  }
  return num;
}

} // namespace System::Private::CoreLib::System::Globalization::CalendarNamespace
