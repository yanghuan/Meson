#include "EastAsianLunisolarCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::EastAsianLunisolarCalendarNamespace {
CalendarAlgorithmType EastAsianLunisolarCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
}

Int32 EastAsianLunisolarCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_BaseCalendarID(), GetYear(DateTime(2029, 1, 1)));
  }
  return _twoDigitYearMax;
}

void EastAsianLunisolarCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > get_MaxCalendarYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, get_MaxCalendarYear()));
  }
  _twoDigitYearMax = value;
}

Int32 EastAsianLunisolarCalendar___::GetSexagenaryYear(DateTime time) {
  CheckTicksRange(time.get_Ticks());
}

Int32 EastAsianLunisolarCalendar___::GetCelestialStem(Int32 sexagenaryYear) {
  if (sexagenaryYear < 1 || sexagenaryYear > 60) {
    rt::throw_exception<ArgumentOutOfRangeException>("sexagenaryYear", sexagenaryYear, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 60));
  }
  return (sexagenaryYear - 1) % 10 + 1;
}

Int32 EastAsianLunisolarCalendar___::GetTerrestrialBranch(Int32 sexagenaryYear) {
  if (sexagenaryYear < 1 || sexagenaryYear > 60) {
    rt::throw_exception<ArgumentOutOfRangeException>("sexagenaryYear", sexagenaryYear, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 60));
  }
  return (sexagenaryYear - 1) % 12 + 1;
}

Int32 EastAsianLunisolarCalendar___::MinEraCalendarYear(Int32 era) {
  Array<EraInfo> calEraInfo = get_CalEraInfo();
  if (calEraInfo == nullptr) {
    return get_MinCalendarYear();
  }
  if (era == 0) {
    era = get_CurrentEraValue();
  }
  if (era == GetEra(get_MinDate())) {
    return GetYear(get_MinCalendarYear(), get_MinDate());
  }
  for (Int32 i = 0; i < calEraInfo->get_Length(); i++) {
    if (era == calEraInfo[i]->era) {
      return calEraInfo[i]->minEraYear;
    }
  }
  rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
}

Int32 EastAsianLunisolarCalendar___::MaxEraCalendarYear(Int32 era) {
  Array<EraInfo> calEraInfo = get_CalEraInfo();
  if (calEraInfo == nullptr) {
    return get_MaxCalendarYear();
  }
  if (era == 0) {
    era = get_CurrentEraValue();
  }
  if (era == GetEra(get_MaxDate())) {
    return GetYear(get_MaxCalendarYear(), get_MaxDate());
  }
  for (Int32 i = 0; i < calEraInfo->get_Length(); i++) {
    if (era == calEraInfo[i]->era) {
      return calEraInfo[i]->maxEraYear;
    }
  }
  rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
}

void EastAsianLunisolarCalendar___::ctor() {
}

void EastAsianLunisolarCalendar___::CheckTicksRange(Int64 ticks) {
  if (ticks < get_MinSupportedDateTime().get_Ticks() || ticks > get_MaxSupportedDateTime().get_Ticks()) {
    rt::throw_exception<ArgumentOutOfRangeException>("time", ticks, SR::Format(CultureInfo::in::get_InvariantCulture(), SR::get_ArgumentOutOfRange_CalendarRange(), get_MinSupportedDateTime(), get_MaxSupportedDateTime()));
  }
}

void EastAsianLunisolarCalendar___::CheckEraRange(Int32 era) {
  if (era == 0) {
    era = get_CurrentEraValue();
  }
  if (era < GetEra(get_MinDate()) || era > GetEra(get_MaxDate())) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
}

Int32 EastAsianLunisolarCalendar___::CheckYearRange(Int32 year, Int32 era) {
  CheckEraRange(era);
  year = GetGregorianYear(year, era);
  if (year < get_MinCalendarYear() || year > get_MaxCalendarYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), MinEraCalendarYear(era), MaxEraCalendarYear(era)));
  }
  return year;
}

Int32 EastAsianLunisolarCalendar___::CheckYearMonthRange(Int32 year, Int32 month, Int32 era) {
  year = CheckYearRange(year, era);
  if (month == 13 && GetYearInfo(year, 0) == 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
  if (month < 1 || month > 13) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
  return year;
}

Int32 EastAsianLunisolarCalendar___::InternalGetDaysInMonth(Int32 year, Int32 month) {
  Int32 num = 32768;
  num >>= month - 1;
  if ((GetYearInfo(year, 3) & num) == 0) {
    return 29;
  }
  return 30;
}

Int32 EastAsianLunisolarCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  year = CheckYearMonthRange(year, month, era);
  return InternalGetDaysInMonth(year, month);
}

Boolean EastAsianLunisolarCalendar___::GregorianIsLeapYear(Int32 y) {
  if (y % 4 != 0) {
    return false;
  }
  if (y % 100 != 0) {
    return true;
  }
  return y % 400 == 0;
}

DateTime EastAsianLunisolarCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  year = CheckYearMonthRange(year, month, era);
  Int32 num = InternalGetDaysInMonth(year, month);
  if (day < 1 || day > num) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), num, month));
  }
}

void EastAsianLunisolarCalendar___::GregorianToLunar(Int32 solarYear, Int32 solarMonth, Int32 solarDate, Int32& lunarYear, Int32& lunarMonth, Int32& lunarDate) {
  Int32 num = GregorianIsLeapYear(solarYear) ? s_daysToMonth366[solarMonth - 1] : s_daysToMonth365[solarMonth - 1];
  num += solarDate;
  Int32 num2 = num;
  lunarYear = solarYear;
  Int32 yearInfo;
  Int32 yearInfo2;
  if (lunarYear == get_MaxCalendarYear() + 1) {
    lunarYear--;
    num2 += (GregorianIsLeapYear(lunarYear) ? 366 : 365);
    yearInfo = GetYearInfo(lunarYear, 1);
    yearInfo2 = GetYearInfo(lunarYear, 2);
  } else {
    yearInfo = GetYearInfo(lunarYear, 1);
    yearInfo2 = GetYearInfo(lunarYear, 2);
    if (solarMonth < yearInfo || (solarMonth == yearInfo && solarDate < yearInfo2)) {
      lunarYear--;
      num2 += (GregorianIsLeapYear(lunarYear) ? 366 : 365);
      yearInfo = GetYearInfo(lunarYear, 1);
      yearInfo2 = GetYearInfo(lunarYear, 2);
    }
  }
  num2 -= s_daysToMonth365[yearInfo - 1];
  num2 -= yearInfo2 - 1;
  Int32 num3 = 32768;
  Int32 yearInfo3 = GetYearInfo(lunarYear, 3);
  Int32 num4 = ((yearInfo3 & num3) != 0) ? 30 : 29;
  lunarMonth = 1;
  while (num2 > num4) {
    num2 -= num4;
    lunarMonth++;
    num3 >>= 1;
    num4 = (((yearInfo3 & num3) != 0) ? 30 : 29);
  }
  lunarDate = num2;
}

Boolean EastAsianLunisolarCalendar___::LunarToGregorian(Int32 lunarYear, Int32 lunarMonth, Int32 lunarDate, Int32& solarYear, Int32& solarMonth, Int32& solarDay) {
  if (lunarDate < 1 || lunarDate > 30) {
    solarYear = 0;
    solarMonth = 0;
    solarDay = 0;
    return false;
  }
  Int32 num = lunarDate - 1;
  for (Int32 i = 1; i < lunarMonth; i++) {
    num += InternalGetDaysInMonth(lunarYear, i);
  }
  Int32 yearInfo = GetYearInfo(lunarYear, 1);
  Int32 yearInfo2 = GetYearInfo(lunarYear, 2);
  Boolean flag = GregorianIsLeapYear(lunarYear);
  Array<Int32> array = flag ? s_daysToMonth366 : s_daysToMonth365;
  solarDay = yearInfo2;
  if (yearInfo > 1) {
    solarDay += array[yearInfo - 1];
  }
  solarDay += num;
  if (solarDay > 365 + (flag ? 1 : 0)) {
    solarYear = lunarYear + 1;
    solarDay -= 365 + (flag ? 1 : 0);
  } else {
    solarYear = lunarYear;
  }
  solarMonth = 1;
  while (solarMonth < 12 && array[solarMonth] < solarDay) {
    solarMonth++;
  }
  solarDay -= array[solarMonth - 1];
  return true;
}

DateTime EastAsianLunisolarCalendar___::LunarToTime(DateTime time, Int32 year, Int32 month, Int32 day) {
}

void EastAsianLunisolarCalendar___::TimeToLunar(DateTime time, Int32& year, Int32& month, Int32& day) {
  Calendar defaultInstance = GregorianCalendar::in::GetDefaultInstance();
  Int32 year2 = defaultInstance->GetYear(time);
  Int32 month2 = defaultInstance->GetMonth(time);
  Int32 dayOfMonth = defaultInstance->GetDayOfMonth(time);
  GregorianToLunar(year2, month2, dayOfMonth, year, month, day);
}

DateTime EastAsianLunisolarCalendar___::AddMonths(DateTime time, Int32 months) {
  if (months < -120000 || months > 120000) {
    rt::throw_exception<ArgumentOutOfRangeException>("months", months, SR::Format(SR::get_ArgumentOutOfRange_Range(), -120000, 120000));
  }
  CheckTicksRange(time.get_Ticks());
}

DateTime EastAsianLunisolarCalendar___::AddYears(DateTime time, Int32 years) {
  CheckTicksRange(time.get_Ticks());
}

Int32 EastAsianLunisolarCalendar___::GetDayOfYear(DateTime time) {
  CheckTicksRange(time.get_Ticks());
}

Int32 EastAsianLunisolarCalendar___::GetDayOfMonth(DateTime time) {
  CheckTicksRange(time.get_Ticks());
}

Int32 EastAsianLunisolarCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  year = CheckYearRange(year, era);
  Int32 num = 0;
  Int32 num2 = InternalIsLeapYear(year) ? 13 : 12;
  while (num2 != 0) {
    num += InternalGetDaysInMonth(year, num2--);
  }
  return num;
}

Int32 EastAsianLunisolarCalendar___::GetMonth(DateTime time) {
  CheckTicksRange(time.get_Ticks());
}

Int32 EastAsianLunisolarCalendar___::GetYear(DateTime time) {
  CheckTicksRange(time.get_Ticks());
}

DayOfWeek EastAsianLunisolarCalendar___::GetDayOfWeek(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 EastAsianLunisolarCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  year = CheckYearRange(year, era);
  if (!InternalIsLeapYear(year)) {
    return 12;
  }
  return 13;
}

Boolean EastAsianLunisolarCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  year = CheckYearMonthRange(year, month, era);
  Int32 num = InternalGetDaysInMonth(year, month);
  if (day < 1 || day > num) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), num, month));
  }
  Int32 yearInfo = GetYearInfo(year, 0);
  if (yearInfo != 0) {
    return month == yearInfo + 1;
  }
  return false;
}

Boolean EastAsianLunisolarCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  year = CheckYearMonthRange(year, month, era);
  Int32 yearInfo = GetYearInfo(year, 0);
  if (yearInfo != 0) {
    return month == yearInfo + 1;
  }
  return false;
}

Int32 EastAsianLunisolarCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  year = CheckYearRange(year, era);
  Int32 yearInfo = GetYearInfo(year, 0);
  if (yearInfo <= 0) {
    return 0;
  }
  return yearInfo + 1;
}

Boolean EastAsianLunisolarCalendar___::InternalIsLeapYear(Int32 year) {
  return GetYearInfo(year, 0) != 0;
}

Boolean EastAsianLunisolarCalendar___::IsLeapYear(Int32 year, Int32 era) {
  year = CheckYearRange(year, era);
  return InternalIsLeapYear(year);
}

Int32 EastAsianLunisolarCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
}

void EastAsianLunisolarCalendar___::cctor() {
  s_daysToMonth365 = rt::newarr<Array<Int32>>(12);
  s_daysToMonth366 = rt::newarr<Array<Int32>>(12);
}

} // namespace System::Private::CoreLib::System::Globalization::EastAsianLunisolarCalendarNamespace
