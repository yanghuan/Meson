#include "TaiwanCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/EraInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarHelper-dep.h>
#include <System.Private.CoreLib/System/Globalization/TaiwanCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TypeInitializationException-dep.h>

namespace System::Private::CoreLib::System::Globalization::TaiwanCalendarNamespace {
DateTime TaiwanCalendar___::get_MinSupportedDateTime() {
  return s_calendarMinValue;
}

DateTime TaiwanCalendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType TaiwanCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

CalendarId TaiwanCalendar___::get_ID() {
  return CalendarId::TAIWAN;
}

Array<Int32> TaiwanCalendar___::get_Eras() {
  return _helper->get_Eras();
}

Int32 TaiwanCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 99);
  }
  return _twoDigitYearMax;
}

void TaiwanCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > _helper->get_MaxYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, _helper->get_MaxYear()));
  }
  _twoDigitYearMax = value;
}

Calendar TaiwanCalendar___::GetDefaultInstance() {
  Calendar as = s_defaultInstance;
  return as != nullptr ? as : (s_defaultInstance = rt::newobj<TaiwanCalendar>());
}

void TaiwanCalendar___::ctor() {
  try {
    rt::newobj<CultureInfo>("zh-TW");
  } catch (ArgumentException innerException) {
    rt::throw_exception<TypeInitializationException>(GetType()->ToString(), innerException);
  }
  _helper = rt::newobj<GregorianCalendarHelper>((TaiwanCalendar)this, s_taiwanEraInfo);
}

DateTime TaiwanCalendar___::AddMonths(DateTime time, Int32 months) {
  return _helper->AddMonths(time, months);
}

DateTime TaiwanCalendar___::AddYears(DateTime time, Int32 years) {
  return _helper->AddYears(time, years);
}

Int32 TaiwanCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->GetDaysInMonth(year, month, era);
}

Int32 TaiwanCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return _helper->GetDaysInYear(year, era);
}

Int32 TaiwanCalendar___::GetDayOfMonth(DateTime time) {
  return _helper->GetDayOfMonth(time);
}

DayOfWeek TaiwanCalendar___::GetDayOfWeek(DateTime time) {
  return _helper->GetDayOfWeek(time);
}

Int32 TaiwanCalendar___::GetDayOfYear(DateTime time) {
  return _helper->GetDayOfYear(time);
}

Int32 TaiwanCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return _helper->GetMonthsInYear(year, era);
}

Int32 TaiwanCalendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  return _helper->GetWeekOfYear(time, rule, firstDayOfWeek);
}

Int32 TaiwanCalendar___::GetEra(DateTime time) {
  return _helper->GetEra(time);
}

Int32 TaiwanCalendar___::GetMonth(DateTime time) {
  return _helper->GetMonth(time);
}

Int32 TaiwanCalendar___::GetYear(DateTime time) {
  return _helper->GetYear(time);
}

Boolean TaiwanCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return _helper->IsLeapDay(year, month, day, era);
}

Boolean TaiwanCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return _helper->IsLeapYear(year, era);
}

Int32 TaiwanCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return _helper->GetLeapMonth(year, era);
}

Boolean TaiwanCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->IsLeapMonth(year, month, era);
}

DateTime TaiwanCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return _helper->ToDateTime(year, month, day, hour, minute, second, millisecond, era);
}

Int32 TaiwanCalendar___::ToFourDigitYear(Int32 year) {
  if (year <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (year > _helper->get_MaxYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, _helper->get_MaxYear()));
  }
  return year;
}

void TaiwanCalendar___::cctor() {
  s_taiwanEraInfo = rt::newarr<Array<EraInfo>>(1);
  s_calendarMinValue = DateTime(1912, 1, 1);
}

} // namespace System::Private::CoreLib::System::Globalization::TaiwanCalendarNamespace
