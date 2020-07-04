#include "JapaneseCalendar-dep.h"

namespace System::Private::CoreLib::System::Globalization::JapaneseCalendarNamespace {
DateTime JapaneseCalendar___::get_MinSupportedDateTime() {
  return DateTime();
};
DateTime JapaneseCalendar___::get_MaxSupportedDateTime() {
  return DateTime();
};
CalendarAlgorithmType JapaneseCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
};
CalendarId JapaneseCalendar___::get_ID() {
  return CalendarId::LAST_CALENDAR;
};
Array<Int32> JapaneseCalendar___::get_Eras() {
  return Array<Int32>();
};
Int32 JapaneseCalendar___::get_TwoDigitYearMax() {
  return Int32();
};
void JapaneseCalendar___::set_TwoDigitYearMax(Int32 value) {
};
Array<EraInfo> JapaneseCalendar___::GetEraInfo() {
  return Array<EraInfo>();
};
Calendar JapaneseCalendar___::GetDefaultInstance() {
  return nullptr;
};
DateTime JapaneseCalendar___::AddMonths(DateTime time, Int32 months) {
  return DateTime();
};
DateTime JapaneseCalendar___::AddYears(DateTime time, Int32 years) {
  return DateTime();
};
Int32 JapaneseCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return Int32();
};
Int32 JapaneseCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return Int32();
};
Int32 JapaneseCalendar___::GetDayOfMonth(DateTime time) {
  return Int32();
};
DayOfWeek JapaneseCalendar___::GetDayOfWeek(DateTime time) {
  return DayOfWeek::Saturday;
};
Int32 JapaneseCalendar___::GetDayOfYear(DateTime time) {
  return Int32();
};
Int32 JapaneseCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return Int32();
};
Int32 JapaneseCalendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  return Int32();
};
Int32 JapaneseCalendar___::GetEra(DateTime time) {
  return Int32();
};
Int32 JapaneseCalendar___::GetMonth(DateTime time) {
  return Int32();
};
Int32 JapaneseCalendar___::GetYear(DateTime time) {
  return Int32();
};
Boolean JapaneseCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};
Boolean JapaneseCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return Boolean();
};
Int32 JapaneseCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
};
Boolean JapaneseCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
};
DateTime JapaneseCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return DateTime();
};
Int32 JapaneseCalendar___::ToFourDigitYear(Int32 year) {
  return Int32();
};
Array<String> JapaneseCalendar___::EraNames() {
  return Array<String>();
};
Array<String> JapaneseCalendar___::AbbrevEraNames() {
  return Array<String>();
};
Array<String> JapaneseCalendar___::EnglishEraNames() {
  return Array<String>();
};
Boolean JapaneseCalendar___::IsValidYear(Int32 year, Int32 era) {
  return Boolean();
};
Array<EraInfo> JapaneseCalendar___::IcuGetJapaneseEras() {
  return Array<EraInfo>();
};
String JapaneseCalendar___::GetAbbreviatedEraName(Array<String> eraNames, Int32 eraIndex) {
  return nullptr;
};
Boolean JapaneseCalendar___::GetJapaneseEraStartDate(Int32 era, DateTime& dateTime) {
  return Boolean();
};
Array<EraInfo> JapaneseCalendar___::NlsGetJapaneseEras() {
  return Array<EraInfo>();
};
Int32 JapaneseCalendar___::CompareEraRanges(EraInfo a, EraInfo b) {
  return Int32();
};
EraInfo JapaneseCalendar___::GetEraFromValue(String value, String data) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Globalization::JapaneseCalendarNamespace
