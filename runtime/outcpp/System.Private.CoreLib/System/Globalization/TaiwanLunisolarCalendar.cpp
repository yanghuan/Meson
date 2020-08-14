#include "TaiwanLunisolarCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarHelper-dep.h>
#include <System.Private.CoreLib/System/Globalization/TaiwanLunisolarCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::TaiwanLunisolarCalendarNamespace {
DateTime TaiwanLunisolarCalendar___::get_MinSupportedDateTime() {
  return s_minDate;
}

DateTime TaiwanLunisolarCalendar___::get_MaxSupportedDateTime() {
  return s_maxDate;
}

Int32 TaiwanLunisolarCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 384;
}

Int32 TaiwanLunisolarCalendar___::get_MinCalendarYear() {
  return 1912;
}

Int32 TaiwanLunisolarCalendar___::get_MaxCalendarYear() {
  return 2050;
}

DateTime TaiwanLunisolarCalendar___::get_MinDate() {
  return s_minDate;
}

DateTime TaiwanLunisolarCalendar___::get_MaxDate() {
  return s_maxDate;
}

Array<EraInfo> TaiwanLunisolarCalendar___::get_CalEraInfo() {
  return s_taiwanLunisolarEraInfo;
}

CalendarId TaiwanLunisolarCalendar___::get_BaseCalendarID() {
  return CalendarId::TAIWAN;
}

CalendarId TaiwanLunisolarCalendar___::get_ID() {
  return CalendarId::TAIWANLUNISOLAR;
}

Array<Int32> TaiwanLunisolarCalendar___::get_Eras() {
  return _helper->get_Eras();
}

Int32 TaiwanLunisolarCalendar___::GetYearInfo(Int32 lunarYear, Int32 index) {
  if (lunarYear < 1912 || lunarYear > 2050) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", lunarYear, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1912, 2050));
  }
  return s_yinfo[lunarYear - 1912, index];
}

Int32 TaiwanLunisolarCalendar___::GetYear(Int32 year, DateTime time) {
  return _helper->GetYear(year, time);
}

Int32 TaiwanLunisolarCalendar___::GetGregorianYear(Int32 year, Int32 era) {
  return _helper->GetGregorianYear(year, era);
}

void TaiwanLunisolarCalendar___::ctor() {
  _helper = rt::newobj<GregorianCalendarHelper>((TaiwanLunisolarCalendar)this, s_taiwanLunisolarEraInfo);
}

Int32 TaiwanLunisolarCalendar___::GetEra(DateTime time) {
  return _helper->GetEra(time);
}

void TaiwanLunisolarCalendar___::cctor() {
  s_taiwanLunisolarEraInfo = rt::newarr<Array<EraInfo>>(1);
  s_minDate = DateTime(1912, 2, 18);
  s_maxDate = DateTime(DateTime(2051, 2, 10, 23, 59, 59, 999).get_Ticks() + 9999);
  s_yinfo = rt::newarr<Array<Int32>>(139);
}

} // namespace System::Private::CoreLib::System::Globalization::TaiwanLunisolarCalendarNamespace
