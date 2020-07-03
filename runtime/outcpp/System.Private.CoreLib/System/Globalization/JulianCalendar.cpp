#include "JulianCalendar-dep.h"

namespace System::Private::CoreLib::System::Globalization::JulianCalendarNamespace {
DateTime JulianCalendar___::get_MinSupportedDateTime() {
  return DateTime();
};
DateTime JulianCalendar___::get_MaxSupportedDateTime() {
  return DateTime();
};
CalendarAlgorithmType JulianCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType();
};
CalendarId JulianCalendar___::get_ID() {
  return CalendarId();
};
Array<Int32> JulianCalendar___::get_Eras() {
  return Array<Int32>();
};
Int32 JulianCalendar___::get_TwoDigitYearMax() {
  return Int32();
};
void JulianCalendar___::set_TwoDigitYearMax(Int32 value) {
};
void JulianCalendar___::CheckEraRange(Int32 era) {
};
void JulianCalendar___::CheckYearEraRange(Int32 year, Int32 era) {
};
void JulianCalendar___::CheckMonthRange(Int32 month) {
};
void JulianCalendar___::CheckDayRange(Int32 year, Int32 month, Int32 day) {
};
Int32 JulianCalendar___::GetDatePart(Int64 ticks, Int32 part) {
  return Int32();
};
Int64 JulianCalendar___::DateToTicks(Int32 year, Int32 month, Int32 day) {
  return Int64();
};
DateTime JulianCalendar___::AddMonths(DateTime time, Int32 months) {
  return DateTime();
};
DateTime JulianCalendar___::AddYears(DateTime time, Int32 years) {
  return DateTime();
};
Int32 JulianCalendar___::GetDayOfMonth(DateTime time) {
  return Int32();
};
DayOfWeek JulianCalendar___::GetDayOfWeek(DateTime time) {
  return DayOfWeek();
};
Int32 JulianCalendar___::GetDayOfYear(DateTime time) {
  return Int32();
};
Int32 JulianCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return Int32();
};
Int32 JulianCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return Int32();
};
Int32 JulianCalendar___::GetEra(DateTime time) {
  return Int32();
};
Int32 JulianCalendar___::GetMonth(DateTime time) {
  return Int32();
};
Int32 JulianCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return Int32();
};
Int32 JulianCalendar___::GetYear(DateTime time) {
  return Int32();
};
Boolean JulianCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};
Int32 JulianCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
};
Boolean JulianCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
};
Boolean JulianCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return Boolean();
};
DateTime JulianCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return DateTime();
};
Int32 JulianCalendar___::ToFourDigitYear(Int32 year) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Globalization::JulianCalendarNamespace
