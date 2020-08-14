#include "JapaneseLunisolarCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarHelper-dep.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseLunisolarCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::JapaneseLunisolarCalendarNamespace {
DateTime JapaneseLunisolarCalendar___::get_MinSupportedDateTime() {
  return s_minDate;
}

DateTime JapaneseLunisolarCalendar___::get_MaxSupportedDateTime() {
  return s_maxDate;
}

Int32 JapaneseLunisolarCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return 354;
}

Int32 JapaneseLunisolarCalendar___::get_MinCalendarYear() {
  return 1960;
}

Int32 JapaneseLunisolarCalendar___::get_MaxCalendarYear() {
  return 2049;
}

DateTime JapaneseLunisolarCalendar___::get_MinDate() {
  return s_minDate;
}

DateTime JapaneseLunisolarCalendar___::get_MaxDate() {
  return s_maxDate;
}

Array<EraInfo> JapaneseLunisolarCalendar___::get_CalEraInfo() {
  return JapaneseCalendar::in::GetEraInfo();
}

CalendarId JapaneseLunisolarCalendar___::get_BaseCalendarID() {
  return CalendarId::JAPAN;
}

CalendarId JapaneseLunisolarCalendar___::get_ID() {
  return CalendarId::JAPANESELUNISOLAR;
}

Array<Int32> JapaneseLunisolarCalendar___::get_Eras() {
  return _helper->get_Eras();
}

Int32 JapaneseLunisolarCalendar___::GetYearInfo(Int32 lunarYear, Int32 index) {
  if (lunarYear < 1960 || lunarYear > 2049) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", lunarYear, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1960, 2049));
  }
  return s_yinfo[lunarYear - 1960, index];
}

Int32 JapaneseLunisolarCalendar___::GetYear(Int32 year, DateTime time) {
  return _helper->GetYear(year, time);
}

Int32 JapaneseLunisolarCalendar___::GetGregorianYear(Int32 year, Int32 era) {
  return _helper->GetGregorianYear(year, era);
}

Array<EraInfo> JapaneseLunisolarCalendar___::TrimEras(Array<EraInfo> baseEras) {
  Array<EraInfo> array = rt::newarr<Array<EraInfo>>(baseEras->get_Length());
  Int32 num = 0;
  for (Int32 i = 0; i < baseEras->get_Length(); i++) {
    if (baseEras[i]->yearOffset + baseEras[i]->minEraYear < 2049) {
      if (baseEras[i]->yearOffset + baseEras[i]->maxEraYear < 1960) {
        break;
      }
      array[num] = baseEras[i];
      num++;
    }
  }
  if (num == 0) {
    return baseEras;
  }
  Array<>::in::Resize(array, num);
  return array;
}

void JapaneseLunisolarCalendar___::ctor() {
  _helper = rt::newobj<GregorianCalendarHelper>((JapaneseLunisolarCalendar)this, TrimEras(JapaneseCalendar::in::GetEraInfo()));
}

Int32 JapaneseLunisolarCalendar___::GetEra(DateTime time) {
  return _helper->GetEra(time);
}

void JapaneseLunisolarCalendar___::cctor() {
  s_minDate = DateTime(1960, 1, 28);
  s_maxDate = DateTime(DateTime(2050, 1, 22, 23, 59, 59, 999).get_Ticks() + 9999);
  s_yinfo = rt::newarr<Array<Int32>>(90);
}

} // namespace System::Private::CoreLib::System::Globalization::JapaneseLunisolarCalendarNamespace
