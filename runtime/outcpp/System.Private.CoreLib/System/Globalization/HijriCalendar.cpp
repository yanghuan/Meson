#include "HijriCalendar-dep.h"

#include <System.Private.CoreLib/Internal/Win32/Registry-dep.h>
#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::Globalization::HijriCalendarNamespace {
using namespace Internal::Win32;

DateTime HijriCalendar___::get_MinSupportedDateTime() {
  return s_calendarMinValue;
}

DateTime HijriCalendar___::get_MaxSupportedDateTime() {
  return s_calendarMaxValue;
}

CalendarAlgorithmType HijriCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunarCalendar;
}

CalendarId HijriCalendar___::get_ID() {
  return CalendarId::HIJRI;
}

Int32 HijriCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 354;
}

Int32 HijriCalendar___::get_HijriAdjustment() {
  if (_hijriAdvance == Int32::MinValue) {
    _hijriAdvance = GetHijriDateAdjustment();
  }
  return _hijriAdvance;
}

void HijriCalendar___::set_HijriAdjustment(Int32 value) {
  if (value < -2 || value > 2) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), -2, 2));
  }
  VerifyWritable();
  _hijriAdvance = value;
}

Array<Int32> HijriCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 HijriCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 1451);
  }
  return _twoDigitYearMax;
}

void HijriCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > 9666) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, 9666));
  }
  _twoDigitYearMax = value;
}

void HijriCalendar___::ctor() {
  _hijriAdvance = Int32::MinValue;
  Calendar::in::ctor();
}

Int64 HijriCalendar___::GetAbsoluteDateHijri(Int32 y, Int32 m, Int32 d) {
  return DaysUpToHijriYear(y) + s_hijriMonthDays[m - 1] + d - 1 - get_HijriAdjustment();
}

Int64 HijriCalendar___::DaysUpToHijriYear(Int32 HijriYear) {
  Int32 num = (HijriYear - 1) / 30 * 30;
  Int32 num2 = HijriYear - num - 1;
  Int64 num3 = (Int64)num * 10631 / 30 + 227013;
  while (num2 > 0) {
    num3 += 354 + (IsLeapYear(num2, 0) ? 1 : 0);
    num2--;
  }
  return num3;
}

void HijriCalendar___::CheckTicksRange(Int64 ticks) {
  if (ticks < s_calendarMinValue.get_Ticks() || ticks > s_calendarMaxValue.get_Ticks()) {
    rt::throw_exception<ArgumentOutOfRangeException>("time", ticks, SR::Format(CultureInfo::in::get_InvariantCulture(), SR::get_ArgumentOutOfRange_CalendarRange(), s_calendarMinValue, s_calendarMaxValue));
  }
}

void HijriCalendar___::CheckEraRange(Int32 era) {
  if (era != 0 && era != HijriEra) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
}

void HijriCalendar___::CheckYearRange(Int32 year, Int32 era) {
  CheckEraRange(era);
  if (year < 1 || year > 9666) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9666));
  }
}

void HijriCalendar___::CheckYearMonthRange(Int32 year, Int32 month, Int32 era) {
  CheckYearRange(year, era);
  if (year == 9666 && month > 4) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 4));
  }
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::get_ArgumentOutOfRange_Month());
  }
}

Int32 HijriCalendar___::GetDatePart(Int64 ticks, Int32 part) {
  CheckTicksRange(ticks);
  Int64 num = ticks / 864000000000 + 1;
  num += get_HijriAdjustment();
  Int32 num2 = (Int32)((num - 227013) * 30 / 10631) + 1;
  Int64 num3 = DaysUpToHijriYear(num2);
  Int64 num4 = GetDaysInYear(num2, 0);
  if (num < num3) {
    num3 -= num4;
    num2--;
  } else if (num == num3) {
    num2--;
    num3 -= GetDaysInYear(num2, 0);
  } else if (num > num3 + num4) {
    num3 += num4;
    num2++;
  }


  if (part == 0) {
    return num2;
  }
  Int32 i = 1;
  num -= num3;
  if (part == 1) {
    return (Int32)num;
  }
  for (; i <= 12 && num > s_hijriMonthDays[i - 1]; i++) {
  }
  i--;
  if (part == 2) {
    return i;
  }
  Int32 result = (Int32)(num - s_hijriMonthDays[i - 1]);
  if (part == 3) {
    return result;
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_DateTimeParsing());
}

DateTime HijriCalendar___::AddMonths(DateTime time, Int32 months) {
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
  Int64 ticks = GetAbsoluteDateHijri(datePart, datePart2, num) * 864000000000 + time.get_Ticks() % 864000000000;
  Calendar::in::CheckAddResult(ticks, get_MinSupportedDateTime(), get_MaxSupportedDateTime());
  return DateTime(ticks);
}

DateTime HijriCalendar___::AddYears(DateTime time, Int32 years) {
  return AddMonths(time, years * 12);
}

Int32 HijriCalendar___::GetDayOfMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 3);
}

DayOfWeek HijriCalendar___::GetDayOfWeek(DateTime time) {
  return (DayOfWeek)((Int32)(time.get_Ticks() / 864000000000 + 1) % 7);
}

Int32 HijriCalendar___::GetDayOfYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 1);
}

Int32 HijriCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearMonthRange(year, month, era);
  if (month == 12) {
    if (!IsLeapYear(year, 0)) {
      return 29;
    }
    return 30;
  }
  if (month % 2 != 1) {
    return 29;
  }
  return 30;
}

Int32 HijriCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  if (!IsLeapYear(year, 0)) {
    return 354;
  }
  return 355;
}

Int32 HijriCalendar___::GetEra(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return HijriEra;
}

Int32 HijriCalendar___::GetMonth(DateTime time) {
  return GetDatePart(time.get_Ticks(), 2);
}

Int32 HijriCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return 12;
}

Int32 HijriCalendar___::GetYear(DateTime time) {
  return GetDatePart(time.get_Ticks(), 0);
}

Boolean HijriCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  Int32 daysInMonth = GetDaysInMonth(year, month, era);
  if (day < 1 || day > daysInMonth) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), daysInMonth, month));
  }
  if (IsLeapYear(year, era) && month == 12) {
    return day == 30;
  }
  return false;
}

Int32 HijriCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return 0;
}

Boolean HijriCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  CheckYearMonthRange(year, month, era);
  return false;
}

Boolean HijriCalendar___::IsLeapYear(Int32 year, Int32 era) {
  CheckYearRange(year, era);
  return (year * 11 + 14) % 30 < 11;
}

DateTime HijriCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  Int32 daysInMonth = GetDaysInMonth(year, month, era);
  if (day < 1 || day > daysInMonth) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", day, SR::Format(SR::get_ArgumentOutOfRange_Day(), daysInMonth, month));
  }
  Int64 absoluteDateHijri = GetAbsoluteDateHijri(year, month, day);
  if (absoluteDateHijri < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
  }
  return DateTime(absoluteDateHijri * 864000000000 + Calendar::in::TimeToTicks(hour, minute, second, millisecond));
}

Int32 HijriCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (year < 100) {
    return Calendar::in::ToFourDigitYear(year);
  }
  if (year > 9666) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9666));
  }
  return year;
}

Int32 HijriCalendar___::GetHijriDateAdjustment() {
  if (_hijriAdvance == Int32::MinValue) {
    _hijriAdvance = GetAdvanceHijriDate();
  }
  return _hijriAdvance;
}

Int32 HijriCalendar___::GetAdvanceHijriDate() {
  {
    RegistryKey registryKey = Registry::CurrentUser->OpenSubKey("Control Panel\\International");
    rt::Using(registryKey);
    if (registryKey == nullptr) {
      return 0;
    }
    Object value = registryKey->GetValue("AddHijriDate");
    if (value == nullptr) {
      return 0;
    }
    Int32 result = 0;
    String text = value->ToString();
    if (String::in::Compare(text, 0, "AddHijriDate", 0, "AddHijriDate"->get_Length(), StringComparison::OrdinalIgnoreCase) == 0) {
      if (text->get_Length() == "AddHijriDate"->get_Length()) {
        result = -1;
      } else {
        try {
          Int32 num = Int32::Parse(MemoryExtensions::AsSpan(text, "AddHijriDate"->get_Length()), NumberStyles::Integer, CultureInfo::in::get_InvariantCulture());
          if (num >= -2 && num <= 2) {
            result = num;
          }
        } catch (ArgumentException) {
        } catch (FormatException) {
        } catch (OverflowException) {
        }
      }
    }
    return result;
  }
}

void HijriCalendar___::cctor() {
  HijriEra = 1;
  s_hijriMonthDays = rt::newarr<Array<Int32>>(13);
  s_calendarMinValue = DateTime(622, 7, 18);
  s_calendarMaxValue = DateTime::MaxValue;
}

} // namespace System::Private::CoreLib::System::Globalization::HijriCalendarNamespace
