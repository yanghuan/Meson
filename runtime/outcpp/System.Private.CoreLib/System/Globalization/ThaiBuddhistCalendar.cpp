#include "ThaiBuddhistCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/EraInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarHelper-dep.h>
#include <System.Private.CoreLib/System/Globalization/ThaiBuddhistCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::ThaiBuddhistCalendarNamespace {
DateTime ThaiBuddhistCalendar___::get_MinSupportedDateTime() {
  return DateTime::MinValue;
}

DateTime ThaiBuddhistCalendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType ThaiBuddhistCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

CalendarId ThaiBuddhistCalendar___::get_ID() {
  return CalendarId::THAI;
}

Array<Int32> ThaiBuddhistCalendar___::get_Eras() {
  return _helper->get_Eras();
}

Int32 ThaiBuddhistCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 2572);
  }
  return _twoDigitYearMax;
}

void ThaiBuddhistCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > _helper->get_MaxYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, _helper->get_MaxYear()));
  }
  _twoDigitYearMax = value;
}

void ThaiBuddhistCalendar___::ctor() {
  _helper = rt::newobj<GregorianCalendarHelper>((ThaiBuddhistCalendar)this, s_thaiBuddhistEraInfo);
}

DateTime ThaiBuddhistCalendar___::AddMonths(DateTime time, Int32 months) {
  return _helper->AddMonths(time, months);
}

DateTime ThaiBuddhistCalendar___::AddYears(DateTime time, Int32 years) {
  return _helper->AddYears(time, years);
}

Int32 ThaiBuddhistCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->GetDaysInMonth(year, month, era);
}

Int32 ThaiBuddhistCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return _helper->GetDaysInYear(year, era);
}

Int32 ThaiBuddhistCalendar___::GetDayOfMonth(DateTime time) {
  return _helper->GetDayOfMonth(time);
}

DayOfWeek ThaiBuddhistCalendar___::GetDayOfWeek(DateTime time) {
  return _helper->GetDayOfWeek(time);
}

Int32 ThaiBuddhistCalendar___::GetDayOfYear(DateTime time) {
  return _helper->GetDayOfYear(time);
}

Int32 ThaiBuddhistCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return _helper->GetMonthsInYear(year, era);
}

Int32 ThaiBuddhistCalendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  return _helper->GetWeekOfYear(time, rule, firstDayOfWeek);
}

Int32 ThaiBuddhistCalendar___::GetEra(DateTime time) {
  return _helper->GetEra(time);
}

Int32 ThaiBuddhistCalendar___::GetMonth(DateTime time) {
  return _helper->GetMonth(time);
}

Int32 ThaiBuddhistCalendar___::GetYear(DateTime time) {
  return _helper->GetYear(time);
}

Boolean ThaiBuddhistCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return _helper->IsLeapDay(year, month, day, era);
}

Boolean ThaiBuddhistCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return _helper->IsLeapYear(year, era);
}

Int32 ThaiBuddhistCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return _helper->GetLeapMonth(year, era);
}

Boolean ThaiBuddhistCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->IsLeapMonth(year, month, era);
}

DateTime ThaiBuddhistCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return _helper->ToDateTime(year, month, day, hour, minute, second, millisecond, era);
}

Int32 ThaiBuddhistCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return _helper->ToFourDigitYear(year, get_TwoDigitYearMax());
}

void ThaiBuddhistCalendar___::cctor() {
  s_thaiBuddhistEraInfo = rt::newarr<Array<EraInfo>>(1);
}

} // namespace System::Private::CoreLib::System::Globalization::ThaiBuddhistCalendarNamespace
