#include "UmAlQuraCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/UmAlQuraCalendar-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::Globalization::UmAlQuraCalendarNamespace {
UmAlQuraCalendar___::DateMapping::DateMapping(Int32 MonthsLengthFlags, Int32 GYear, Int32 GMonth, Int32 GDay) {
  HijriMonthsLengthFlags = MonthsLengthFlags;
  GregorianDate = DateTime(GYear, GMonth, GDay);
}

DateTime UmAlQuraCalendar___::get_MinSupportedDateTime() {
  return s_minDate;
}

DateTime UmAlQuraCalendar___::get_MaxSupportedDateTime() {
  return s_maxDate;
}

CalendarAlgorithmType UmAlQuraCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunarCalendar;
}

CalendarId UmAlQuraCalendar___::get_BaseCalendarID() {
  return CalendarId::HIJRI;
}

CalendarId UmAlQuraCalendar___::get_ID() {
  return CalendarId::UMALQURA;
}

Int32 UmAlQuraCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 355;
}

Array<Int32> UmAlQuraCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 UmAlQuraCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 1451);
  }
  return _twoDigitYearMax;
}

void UmAlQuraCalendar___::set_TwoDigitYearMax(Int32 value) {
  if (value != 99 && (value < 1318 || value > 1500)) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1318, 1500));
  }
  VerifyWritable();
  _twoDigitYearMax = value;
}

Array<UmAlQuraCalendar::in::DateMapping> UmAlQuraCalendar___::InitDateMapping() {
  Array<Int16> array = rt::newarr<Array<Int16>>(736);
  Array<DateMapping> array2 = rt::newarr<Array<DateMapping>>(array->get_Length() / 4);
  for (Int32 i = 0; i < array2->get_Length(); i++) {
    array2[i] = DateMapping(array[i * 4], array[i * 4 + 1], array[i * 4 + 2], array[i * 4 + 3]);
  }
  return array2;
}

void UmAlQuraCalendar___::ctor() {
}

void UmAlQuraCalendar___::ConvertHijriToGregorian(Int32 HijriYear, Int32 HijriMonth, Int32 HijriDay, Int32& yg, Int32& mg, Int32& dg) {
  Int32 num = HijriDay - 1;
  Int32 num2 = HijriYear - 1318;
  DateTime gregorianDate = s_hijriYearInfo[num2].GregorianDate;
  Int32 num3 = s_hijriYearInfo[num2].HijriMonthsLengthFlags;
  for (Int32 i = 1; i < HijriMonth; i++) {
  }
  gregorianDate.AddDays(num).GetDate(yg, mg, dg);
}

Int64 UmAlQuraCalendar___::GetAbsoluteDateUmAlQura(Int32 year, Int32 month, Int32 day) {
}

void UmAlQuraCalendar___::CheckTicksRange(Int64 ticks) {
  if (ticks < s_minDate.get_Ticks() || ticks > s_maxDate.get_Ticks()) {
    rt::throw_exception<ArgumentOutOfRangeException>("time", ticks, SR::Format(CultureInfo::in::get_InvariantCulture(), SR::get_ArgumentOutOfRange_CalendarRange(), s_minDate, s_maxDate));
  }
}

void UmAlQuraCalendar___::CheckEraRange(Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
}

void UmAlQuraCalendar___::CheckYearRange(Int32 year, Int32 era) {
  CheckEraRange(era);
  if (year < 1318 || year > 1500) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1318, 1500));
  }
}

void UmAlQuraCalendar___::CheckYearMonthRange(Int32 year, Int32 month, Int32 era) {
  CheckYearRange(year, era);
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
}

void UmAlQuraCalendar___::ConvertGregorianToHijri(DateTime time, Int32& HijriYear, Int32& HijriMonth, Int32& HijriDay) {
  Int32 num = (Int32)((time.get_Ticks() - s_minDate.get_Ticks()) / 864000000000) / 355;
  while (time.CompareTo(s_hijriYearInfo[++num].GregorianDate) > 0) {
  }
  if (time.CompareTo(s_hijriYearInfo[num].GregorianDate) != 0) {
    num--;
  }
  TimeSpan timeSpan = time.Subtract(s_hijriYearInfo[num].GregorianDate);
  Int32 num2 = num + 1318;
  Int32 num3 = 1;
  Int32 num4 = 1;
  Double num5 = timeSpan.get_TotalDays();
  Int32 num6 = s_hijriYearInfo[num].HijriMonthsLengthFlags;
}

Int32 UmAlQuraCalendar___::GetDatePart(DateTime time, Int32 part) {
  Int64 ticks = time.get_Ticks();
  CheckTicksRange(ticks);
}

DateTime UmAlQuraCalendar___::AddMonths(DateTime time, Int32 months) {
  if (months < -120000 || months > 120000) {
    rt::throw_exception<ArgumentOutOfRangeException>("months", months, SR::Format(SR::get_ArgumentOutOfRange_Range(), -120000, 120000));
  }
  Int32 datePart = GetDatePart(time, 0);
  Int32 datePart2 = GetDatePart(time, 2);
  Int32 num = GetDatePart(time, 3);
  Int32 num2 = datePart2 - 1 + months;
  if (num2 >= 0) {
    datePart2 = num2 % 12 + 1;
    datePart += num2 / 12;
  } else {
    datePart2 = 12 + (num2 + 1) % 12;
    datePart += (num2 - 11) / 12;
  }
  if (num > 29) {
    Int32 daysInMonth = GetDaysInMonth(datePart, datePart2);
    if (num > daysInMonth) {
      num = daysInMonth;
    }
  }
  CheckYearRange(datePart, 1);
  DateTime result = DateTime(GetAbsoluteDateUmAlQura(datePart, datePart2, num) * 864000000000 + time.get_Ticks() % 864000000000);
  Calendar::in::CheckAddResult(result.get_Ticks(), get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return result;
}

DateTime UmAlQuraCalendar___::AddYears(DateTime time, Int32 years) {
  return AddMonths(time, years * 12);
}

Int32 UmAlQuraCalendar___::GetDayOfMonth(DateTime time) {
  return GetDatePart(time, 3);
}

DayOfWeek UmAlQuraCalendar___::GetDayOfWeek(DateTime time) {
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 UmAlQuraCalendar___::GetDayOfYear(DateTime time) {
  return GetDatePart(time, 1);
}

Int32 UmAlQuraCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearMonthRange(year, month, era);
}

Int32 UmAlQuraCalendar___::RealGetDaysInYear(Int32 year) {
  Int32 num = 0;
  Int32 num2 = s_hijriYearInfo[year - 1318].HijriMonthsLengthFlags;
  for (Int32 i = 1; i <= 12; i++) {
  }
  return num;
}

Int32 UmAlQuraCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return RealGetDaysInYear(year);
}

Int32 UmAlQuraCalendar___::GetEra(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return 1;
}

Int32 UmAlQuraCalendar___::GetMonth(DateTime time) {
  return GetDatePart(time, 2);
}

Int32 UmAlQuraCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return 12;
}

Int32 UmAlQuraCalendar___::GetYear(DateTime time) {
  return GetDatePart(time, 0);
}

Boolean UmAlQuraCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  if (day >= 1 && day <= 29) {
    CheckYearMonthRange(year, month, era);
    return false;
  }
  Int32 daysInMonth = GetDaysInMonth(year, month, era);
  if (day < 1 || day > daysInMonth) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), daysInMonth, month));
  }
  return false;
}

Int32 UmAlQuraCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return 0;
}

Boolean UmAlQuraCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearMonthRange(year, month, era);
  return false;
}

Boolean UmAlQuraCalendar___::IsLeapYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return RealGetDaysInYear(year) == 355;
}

DateTime UmAlQuraCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  if (day >= 1 && day <= 29) {
    CheckYearMonthRange(year, month, era);
  } else {
    Int32 daysInMonth = GetDaysInMonth(year, month, era);
    if (day < 1 || day > daysInMonth) {
      rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), daysInMonth, month));
    }
  }
  Int64 absoluteDateUmAlQura = GetAbsoluteDateUmAlQura(year, month, day);
  if (absoluteDateUmAlQura < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
  }
  return DateTime(absoluteDateUmAlQura * 864000000000 + Calendar::in::TimeToTicks(hour, minute, second, millisecond));
}

Int32 UmAlQuraCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year < 100) {
  }
  if (year < 1318 || year > 1500) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1318, 1500));
  }
  return year;
}

void UmAlQuraCalendar___::cctor() {
  s_hijriYearInfo = InitDateMapping();
  s_minDate = DateTime(1900, 4, 30);
  s_maxDate = DateTime(DateTime(2077, 11, 16, 23, 59, 59, 999).get_Ticks() + 9999);
}

} // namespace System::Private::CoreLib::System::Globalization::UmAlQuraCalendarNamespace
