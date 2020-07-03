#include "Calendar-dep.h"

#include <System.Private.CoreLib/System/Globalization/Calendar-dep.h>

namespace System::Private::CoreLib::System::Globalization::CalendarNamespace {
DateTime Calendar___::get_MinSupportedDateTime() {
  return DateTime();
};
DateTime Calendar___::get_MaxSupportedDateTime() {
  return DateTime();
};
CalendarAlgorithmType Calendar___::get_AlgorithmType() {
  return CalendarAlgorithmType();
};
CalendarId Calendar___::get_ID() {
  return CalendarId();
};
CalendarId Calendar___::get_BaseCalendarID() {
  return CalendarId();
};
Boolean Calendar___::get_IsReadOnly() {
  return Boolean();
};
Int32 Calendar___::get_CurrentEraValue() {
  return Int32();
};
Int32 Calendar___::get_DaysInYearBeforeMinSupportedYear() {
  return Int32();
};
Int32 Calendar___::get_TwoDigitYearMax() {
  return Int32();
};
void Calendar___::set_TwoDigitYearMax(Int32 value) {
};
Object Calendar___::Clone() {
  return nullptr;
};
Calendar Calendar___::ReadOnly(Calendar calendar) {
  return nullptr;
};
void Calendar___::VerifyWritable() {
};
void Calendar___::SetReadOnlyState(Boolean readOnly) {
};
void Calendar___::CheckAddResult(Int64 ticks, DateTime minValue, DateTime maxValue) {
};
DateTime Calendar___::Add(DateTime time, Double value, Int32 scale) {
  return DateTime();
};
DateTime Calendar___::AddMilliseconds(DateTime time, Double milliseconds) {
  return DateTime();
};
DateTime Calendar___::AddDays(DateTime time, Int32 days) {
  return DateTime();
};
DateTime Calendar___::AddHours(DateTime time, Int32 hours) {
  return DateTime();
};
DateTime Calendar___::AddMinutes(DateTime time, Int32 minutes) {
  return DateTime();
};
DateTime Calendar___::AddSeconds(DateTime time, Int32 seconds) {
  return DateTime();
};
DateTime Calendar___::AddWeeks(DateTime time, Int32 weeks) {
  return DateTime();
};
Int32 Calendar___::GetDaysInMonth(Int32 year, Int32 month) {
  return Int32();
};
Int32 Calendar___::GetDaysInYear(Int32 year) {
  return Int32();
};
Int32 Calendar___::GetHour(DateTime time) {
  return Int32();
};
Double Calendar___::GetMilliseconds(DateTime time) {
  return Double();
};
Int32 Calendar___::GetMinute(DateTime time) {
  return Int32();
};
Int32 Calendar___::GetMonthsInYear(Int32 year) {
  return Int32();
};
Int32 Calendar___::GetSecond(DateTime time) {
  return Int32();
};
Int32 Calendar___::GetFirstDayWeekOfYear(DateTime time, Int32 firstDayOfWeek) {
  return Int32();
};
Int32 Calendar___::GetWeekOfYearFullDays(DateTime time, Int32 firstDayOfWeek, Int32 fullDays) {
  return Int32();
};
Int32 Calendar___::GetWeekOfYearOfMinSupportedDateTime(Int32 firstDayOfWeek, Int32 minimumDaysInFirstWeek) {
  return Int32();
};
Int32 Calendar___::GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) {
  return Int32();
};
Boolean Calendar___::IsLeapDay(Int32 year, Int32 month, Int32 day) {
  return Boolean();
};
Boolean Calendar___::IsLeapMonth(Int32 year, Int32 month) {
  return Boolean();
};
Int32 Calendar___::GetLeapMonth(Int32 year) {
  return Int32();
};
Int32 Calendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
};
Boolean Calendar___::IsLeapYear(Int32 year) {
  return Boolean();
};
DateTime Calendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  return DateTime();
};
Boolean Calendar___::TryToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era, DateTime& result) {
  return Boolean();
};
Boolean Calendar___::IsValidYear(Int32 year, Int32 era) {
  return Boolean();
};
Boolean Calendar___::IsValidMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
};
Boolean Calendar___::IsValidDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};
Int32 Calendar___::ToFourDigitYear(Int32 year) {
  return Int32();
};
Int64 Calendar___::TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  return Int64();
};
Int32 Calendar___::GetSystemTwoDigitYearSetting(CalendarId CalID, Int32 defaultYearValue) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Globalization::CalendarNamespace
