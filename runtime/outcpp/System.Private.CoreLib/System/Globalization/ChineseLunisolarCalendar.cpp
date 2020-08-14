#include "ChineseLunisolarCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::ChineseLunisolarCalendarNamespace {
DateTime ChineseLunisolarCalendar___::get_MinSupportedDateTime() {
  return s_minDate;
}

DateTime ChineseLunisolarCalendar___::get_MaxSupportedDateTime() {
  return s_maxDate;
}

Int32 ChineseLunisolarCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 384;
}

Int32 ChineseLunisolarCalendar___::get_MinCalendarYear() {
  return 1901;
}

Int32 ChineseLunisolarCalendar___::get_MaxCalendarYear() {
  return 2100;
}

DateTime ChineseLunisolarCalendar___::get_MinDate() {
  return s_minDate;
}

DateTime ChineseLunisolarCalendar___::get_MaxDate() {
  return s_maxDate;
}

Array<EraInfo> ChineseLunisolarCalendar___::get_CalEraInfo() {
  return nullptr;
}

CalendarId ChineseLunisolarCalendar___::get_ID() {
  return CalendarId::CHINESELUNISOLAR;
}

CalendarId ChineseLunisolarCalendar___::get_BaseCalendarID() {
  return CalendarId::GREGORIAN;
}

Array<Int32> ChineseLunisolarCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 ChineseLunisolarCalendar___::GetYearInfo(Int32 lunarYear, Int32 index) {
  if (lunarYear < 1901 || lunarYear > 2100) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", lunarYear, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1901, 2100));
  }
  return s_yinfo[lunarYear - 1901, index];
}

Int32 ChineseLunisolarCalendar___::GetYear(Int32 year, DateTime time) {
  return year;
}

Int32 ChineseLunisolarCalendar___::GetGregorianYear(Int32 year, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 1901 || year > 2100) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1901, 2100));
  }
  return year;
}

void ChineseLunisolarCalendar___::ctor() {
}

Int32 ChineseLunisolarCalendar___::GetEra(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return 1;
}

void ChineseLunisolarCalendar___::cctor() {
  s_minDate = DateTime(1901, 2, 19);
  s_maxDate = DateTime(DateTime(2101, 1, 28, 23, 59, 59, 999).get_Ticks() + 9999);
  s_yinfo = rt::newarr<Array<Int32>>(200);
}

} // namespace System::Private::CoreLib::System::Globalization::ChineseLunisolarCalendarNamespace
