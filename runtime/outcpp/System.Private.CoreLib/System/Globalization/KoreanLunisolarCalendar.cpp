#include "KoreanLunisolarCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::KoreanLunisolarCalendarNamespace {
DateTime KoreanLunisolarCalendar___::get_MinSupportedDateTime() {
  return s_minDate;
}

DateTime KoreanLunisolarCalendar___::get_MaxSupportedDateTime() {
  return s_maxDate;
}

Int32 KoreanLunisolarCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 384;
}

Int32 KoreanLunisolarCalendar___::get_MinCalendarYear() {
  return 918;
}

Int32 KoreanLunisolarCalendar___::get_MaxCalendarYear() {
  return 2050;
}

DateTime KoreanLunisolarCalendar___::get_MinDate() {
  return s_minDate;
}

DateTime KoreanLunisolarCalendar___::get_MaxDate() {
  return s_maxDate;
}

Array<EraInfo> KoreanLunisolarCalendar___::get_CalEraInfo() {
  return nullptr;
}

CalendarId KoreanLunisolarCalendar___::get_BaseCalendarID() {
  return CalendarId::KOREA;
}

CalendarId KoreanLunisolarCalendar___::get_ID() {
  return CalendarId::KOREANLUNISOLAR;
}

Array<Int32> KoreanLunisolarCalendar___::get_Eras() {
  return rt::newarr<Array<Int32>>(1);
}

Int32 KoreanLunisolarCalendar___::GetYearInfo(Int32 lunarYear, Int32 index) {
  if (lunarYear < 918 || lunarYear > 2050) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", lunarYear, SR::Format(SR::get_ArgumentOutOfRange_Range(), 918, 2050));
  }
  return s_yinfo[lunarYear - 918, index];
}

Int32 KoreanLunisolarCalendar___::GetYear(Int32 year, DateTime time) {
  return year;
}

Int32 KoreanLunisolarCalendar___::GetGregorianYear(Int32 year, Int32 era) {
  if (era != 0 && era != 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
  }
  if (year < 918 || year > 2050) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 918, 2050));
  }
  return year;
}

void KoreanLunisolarCalendar___::ctor() {
}

Int32 KoreanLunisolarCalendar___::GetEra(DateTime time) {
  CheckTicksRange(time.get_Ticks());
  return 1;
}

void KoreanLunisolarCalendar___::cctor() {
  s_minDate = DateTime(918, 2, 19);
  s_maxDate = DateTime(DateTime(2051, 2, 10, 23, 59, 59, 999).get_Ticks() + 9999);
  s_yinfo = rt::newarr<Array<Int32>>(1133);
}

} // namespace System::Private::CoreLib::System::Globalization::KoreanLunisolarCalendarNamespace
