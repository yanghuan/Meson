#include "ISOWeek-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/DayOfWeek.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::ISOWeekNamespace {
Int32 ISOWeek::GetWeekOfYear(DateTime date) {
  Int32 weekNumber = GetWeekNumber(date);
  if (weekNumber < 1) {
    return GetWeeksInYear(date.get_Year() - 1);
  }
  if (weekNumber > GetWeeksInYear(date.get_Year())) {
    return 1;
  }
  return weekNumber;
}

Int32 ISOWeek::GetYear(DateTime date) {
  Int32 weekNumber = GetWeekNumber(date);
  if (weekNumber < 1) {
    return date.get_Year() - 1;
  }
  if (weekNumber > GetWeeksInYear(date.get_Year())) {
    return date.get_Year() + 1;
  }
  return date.get_Year();
}

DateTime ISOWeek::GetYearStart(Int32 year) {
  return ToDateTime(year, 1, DayOfWeek::Monday);
}

DateTime ISOWeek::GetYearEnd(Int32 year) {
  return ToDateTime(year, GetWeeksInYear(year), DayOfWeek::Sunday);
}

Int32 ISOWeek::GetWeeksInYear(Int32 year) {
  auto P = [](Int32 y) -> Int32 {
    return (y + y / 4 - y / 100 + y / 400) % 7;
  };
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::get_ArgumentOutOfRange_Year());
  }
  if (P(year) == 4 || P(year - 1) == 3) {
    return 53;
  }
  return 52;
}

DateTime ISOWeek::ToDateTime(Int32 year, Int32 week, DayOfWeek dayOfWeek) {
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::get_ArgumentOutOfRange_Year());
  }
  if (week < 1 || week > 53) {
    rt::throw_exception<ArgumentOutOfRangeException>("week", SR::get_ArgumentOutOfRange_Week_ISO());
  }
  if (dayOfWeek < DayOfWeek::Sunday || dayOfWeek > (DayOfWeek)7) {
    rt::throw_exception<ArgumentOutOfRangeException>("dayOfWeek", SR::get_ArgumentOutOfRange_DayOfWeek());
  }
  Int32 num = GetWeekday(DateTime(year, 1, 4).get_DayOfWeek()) + 3;
  Int32 num2 = week * 7 + GetWeekday(dayOfWeek) - num;
  return DateTime(year, 1, 1).AddDays(num2 - 1);
}

Int32 ISOWeek::GetWeekNumber(DateTime date) {
  return (date.get_DayOfYear() - GetWeekday(date.get_DayOfWeek()) + 10) / 7;
}

Int32 ISOWeek::GetWeekday(DayOfWeek dayOfWeek) {
  if (dayOfWeek != 0) {
    return (Int32)dayOfWeek;
  }
  return 7;
}

} // namespace System::Private::CoreLib::System::Globalization::ISOWeekNamespace
