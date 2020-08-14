#include "KoreanCalendar-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/EraInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarHelper-dep.h>
#include <System.Private.CoreLib/System/Globalization/KoreanCalendar-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::KoreanCalendarNamespace {
DateTime KoreanCalendar___::get_MinSupportedDateTime() {
  return DateTime::MinValue;
}

DateTime KoreanCalendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType KoreanCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

CalendarId KoreanCalendar___::get_ID() {
  return CalendarId::KOREA;
}

Array<Int32> KoreanCalendar___::get_Eras() {
  return _helper->get_Eras();
}

Int32 KoreanCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 4362);
  }
  return _twoDigitYearMax;
}

void KoreanCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > _helper->get_MaxYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, _helper->get_MaxYear()));
  }
  _twoDigitYearMax = value;
}

void KoreanCalendar___::ctor() {
  try{
    rt::newobj<CultureInfo>("ko-KR");
  } catch (ArgumentException innerException) {
  }
  _helper = rt::newobj<GregorianCalendarHelper>((KoreanCalendar)this, s_koreanEraInfo);
}

DateTime KoreanCalendar___::AddMonths(DateTime time, Int32 months) {
  return _helper->AddMonths(time, months);
}

DateTime KoreanCalendar___::AddYears(DateTime time, Int32 years) {
  return _helper->AddYears(time, years);
}

Int32 KoreanCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->GetDaysInMonth(year, month, era);
}

Int32 KoreanCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return _helper->GetDaysInYear(year, era);
}

Int32 KoreanCalendar___::GetDayOfMonth(DateTime time) {
  return _helper->GetDayOfMonth(time);
}

DayOfWeek KoreanCalendar___::GetDayOfWeek(DateTime time) {
  return _helper->GetDayOfWeek(time);
}

Int32 KoreanCalendar___::GetDayOfYear(DateTime time) {
  return _helper->GetDayOfYear(time);
}

Int32 KoreanCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return _helper->GetMonthsInYear(year, era);
}

Int32 KoreanCalendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  return _helper->GetWeekOfYear(time, rule, firstDayOfWeek);
}

Int32 KoreanCalendar___::GetEra(DateTime time) {
  return _helper->GetEra(time);
}

Int32 KoreanCalendar___::GetMonth(DateTime time) {
  return _helper->GetMonth(time);
}

Int32 KoreanCalendar___::GetYear(DateTime time) {
  return _helper->GetYear(time);
}

Boolean KoreanCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return _helper->IsLeapDay(year, month, day, era);
}

Boolean KoreanCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return _helper->IsLeapYear(year, era);
}

Int32 KoreanCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return _helper->GetLeapMonth(year, era);
}

Boolean KoreanCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->IsLeapMonth(year, month, era);
}

DateTime KoreanCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return _helper->ToDateTime(year, month, day, hour, minute, second, millisecond, era);
}

Int32 KoreanCalendar___::ToFourDigitYear(Int32 year) {
  if (year < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return _helper->ToFourDigitYear(year, get_TwoDigitYearMax());
}

void KoreanCalendar___::cctor() {
  s_koreanEraInfo = rt::newarr<Array<EraInfo>>(1);
}

} // namespace System::Private::CoreLib::System::Globalization::KoreanCalendarNamespace
