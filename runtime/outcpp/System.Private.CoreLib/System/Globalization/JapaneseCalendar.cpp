#include "JapaneseCalendar-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Comparison-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarDataType.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarHelper-dep.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Security/SecurityException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::System::Globalization::JapaneseCalendarNamespace {
using namespace System::IO;
using namespace System::Security;

DateTime JapaneseCalendar___::get_MinSupportedDateTime() {
  return s_calendarMinValue;
}

DateTime JapaneseCalendar___::get_MaxSupportedDateTime() {
  return DateTime::MaxValue;
}

CalendarAlgorithmType JapaneseCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::SolarCalendar;
}

CalendarId JapaneseCalendar___::get_ID() {
  return CalendarId::JAPAN;
}

Array<Int32> JapaneseCalendar___::get_Eras() {
  return _helper->get_Eras();
}

Int32 JapaneseCalendar___::get_TwoDigitYearMax() {
  if (_twoDigitYearMax == -1) {
    _twoDigitYearMax = Calendar::in::GetSystemTwoDigitYearSetting(get_ID(), 99);
  }
  return _twoDigitYearMax;
}

void JapaneseCalendar___::set_TwoDigitYearMax(Int32 value) {
  VerifyWritable();
  if (value < 99 || value > _helper->get_MaxYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 99, _helper->get_MaxYear()));
  }
  _twoDigitYearMax = value;
}

Array<EraInfo> JapaneseCalendar___::GetEraInfo() {
  Object obj = s_japaneseEraInfo;
  if (obj == nullptr) {
    obj = (s_japaneseEraInfo = (GlobalizationMode::get_UseNls() ? NlsGetJapaneseEras() : IcuGetJapaneseEras()));
    if (obj == nullptr) {
      obj = rt::newarr<Array<EraInfo>>(5);
      s_japaneseEraInfo = (Array<EraInfo>)obj;
    }
  }
  return (Array<EraInfo>)obj;
}

Calendar JapaneseCalendar___::GetDefaultInstance() {
}

void JapaneseCalendar___::ctor() {
  try{
    rt::newobj<CultureInfo>("ja-JP");
  } catch (ArgumentException innerException) {
  }
  _helper = rt::newobj<GregorianCalendarHelper>((JapaneseCalendar)this, GetEraInfo());
}

DateTime JapaneseCalendar___::AddMonths(DateTime time, Int32 months) {
  return _helper->AddMonths(time, months);
}

DateTime JapaneseCalendar___::AddYears(DateTime time, Int32 years) {
  return _helper->AddYears(time, years);
}

Int32 JapaneseCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->GetDaysInMonth(year, month, era);
}

Int32 JapaneseCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return _helper->GetDaysInYear(year, era);
}

Int32 JapaneseCalendar___::GetDayOfMonth(DateTime time) {
  return _helper->GetDayOfMonth(time);
}

DayOfWeek JapaneseCalendar___::GetDayOfWeek(DateTime time) {
  return _helper->GetDayOfWeek(time);
}

Int32 JapaneseCalendar___::GetDayOfYear(DateTime time) {
  return _helper->GetDayOfYear(time);
}

Int32 JapaneseCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return _helper->GetMonthsInYear(year, era);
}

Int32 JapaneseCalendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  return _helper->GetWeekOfYear(time, rule, firstDayOfWeek);
}

Int32 JapaneseCalendar___::GetEra(DateTime time) {
  return _helper->GetEra(time);
}

Int32 JapaneseCalendar___::GetMonth(DateTime time) {
  return _helper->GetMonth(time);
}

Int32 JapaneseCalendar___::GetYear(DateTime time) {
  return _helper->GetYear(time);
}

Boolean JapaneseCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return _helper->IsLeapDay(year, month, day, era);
}

Boolean JapaneseCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return _helper->IsLeapYear(year, era);
}

Int32 JapaneseCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return _helper->GetLeapMonth(year, era);
}

Boolean JapaneseCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return _helper->IsLeapMonth(year, month, era);
}

DateTime JapaneseCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return _helper->ToDateTime(year, month, day, hour, minute, second, millisecond, era);
}

Int32 JapaneseCalendar___::ToFourDigitYear(Int32 year) {
  if (year <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (year > _helper->get_MaxYear()) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", year, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, _helper->get_MaxYear()));
  }
  return year;
}

Array<String> JapaneseCalendar___::EraNames() {
  Array<EraInfo> eraInfo = GetEraInfo();
  Array<String> array = rt::newarr<Array<String>>(eraInfo->get_Length());
  for (Int32 i = 0; i < eraInfo->get_Length(); i++) {
    array[i] = eraInfo[eraInfo->get_Length() - i - 1]->eraName;
  }
  return array;
}

Array<String> JapaneseCalendar___::AbbrevEraNames() {
  Array<EraInfo> eraInfo = GetEraInfo();
  Array<String> array = rt::newarr<Array<String>>(eraInfo->get_Length());
  for (Int32 i = 0; i < eraInfo->get_Length(); i++) {
    array[i] = eraInfo[eraInfo->get_Length() - i - 1]->abbrevEraName;
  }
  return array;
}

Array<String> JapaneseCalendar___::EnglishEraNames() {
  Array<EraInfo> eraInfo = GetEraInfo();
  Array<String> array = rt::newarr<Array<String>>(eraInfo->get_Length());
  for (Int32 i = 0; i < eraInfo->get_Length(); i++) {
    array[i] = eraInfo[eraInfo->get_Length() - i - 1]->englishEraName;
  }
  return array;
}

Boolean JapaneseCalendar___::IsValidYear(Int32 year, Int32 era) {
  return _helper->IsValidYear(year, era);
}

Array<EraInfo> JapaneseCalendar___::IcuGetJapaneseEras() {
  if (GlobalizationMode::get_Invariant()) {
    return nullptr;
  }
}

String JapaneseCalendar___::GetAbbreviatedEraName(Array<String> eraNames, Int32 eraIndex) {
  return eraNames[eraIndex]->Substring(0, 1);
}

Boolean JapaneseCalendar___::GetJapaneseEraStartDate(Int32 era, DateTime& dateTime) {
  dateTime = DateTime();
  Int32 startYear;
  Int32 startMonth;
  Int32 startDay;
  Boolean japaneseEraStartDate = Interop::Globalization::GetJapaneseEraStartDate(era, startYear, startMonth, startDay);
  if (japaneseEraStartDate) {
    dateTime = DateTime(startYear, startMonth, startDay);
  }
  return japaneseEraStartDate;
}

Array<EraInfo> JapaneseCalendar___::NlsGetJapaneseEras() {
  Int32 num = 0;
  Array<EraInfo> array = nullptr;
  try{
  } catch (SecurityException) {
  } catch (IOException) {
  } catch (UnauthorizedAccessException) {
  }
  if (num < 4) {
    return nullptr;
  }
  Array<>::in::Resize(array, num);
  Array<>::in::Sort(array, rt::newobj<Comparison<EraInfo>>(&CompareEraRanges));
  for (Int32 j = 0; j < array->get_Length(); j++) {
    array[j]->era = array->get_Length() - j;
    if (j == 0) {
      array[0]->maxEraYear = 9999 - array[0]->yearOffset;
    } else {
      array[j]->maxEraYear = array[j - 1]->yearOffset + 1 - array[j]->yearOffset;
    }
  }
  return array;
}

Int32 JapaneseCalendar___::CompareEraRanges(EraInfo a, EraInfo b) {
  return b->ticks.CompareTo(a->ticks);
}

EraInfo JapaneseCalendar___::GetEraFromValue(String value, String data) {
  if (value == nullptr || data == nullptr) {
    return nullptr;
  }
  if (value->get_Length() != 10) {
    return nullptr;
  }
  ReadOnlySpan<Char> readOnlySpan = MemoryExtensions::AsSpan(value);
}

void JapaneseCalendar___::cctor() {
  s_calendarMinValue = DateTime(1868, 9, 8);
}

} // namespace System::Private::CoreLib::System::Globalization::JapaneseCalendarNamespace
