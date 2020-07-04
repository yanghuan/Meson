#include "HebrewCalendar-dep.h"

namespace System::Private::CoreLib::System::Globalization::HebrewCalendarNamespace {
DateTime HebrewCalendar___::get_MinSupportedDateTime() {
  return DateTime();
};
DateTime HebrewCalendar___::get_MaxSupportedDateTime() {
  return DateTime();
};
CalendarAlgorithmType HebrewCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
};
CalendarId HebrewCalendar___::get_ID() {
  return CalendarId::LAST_CALENDAR;
};
Array<Int32> HebrewCalendar___::get_Eras() {
  return Array<Int32>();
};
Int32 HebrewCalendar___::get_TwoDigitYearMax() {
  return Int32();
};
void HebrewCalendar___::set_TwoDigitYearMax(Int32 value) {
};
void HebrewCalendar___::CheckHebrewYearValue(Int32 y, Int32 era, String varName) {
};
void HebrewCalendar___::CheckHebrewMonthValue(Int32 year, Int32 month, Int32 era) {
};
void HebrewCalendar___::CheckHebrewDayValue(Int32 year, Int32 month, Int32 day, Int32 era) {
};
void HebrewCalendar___::CheckEraRange(Int32 era) {
};
void HebrewCalendar___::CheckTicksRange(Int64 ticks) {
};
Int32 HebrewCalendar___::GetResult(DateBuffer result, Int32 part) {
  return Int32();
};
Int32 HebrewCalendar___::GetLunarMonthDay(Int32 gregorianYear, DateBuffer lunarDate) {
  return Int32();
};
Int32 HebrewCalendar___::GetDatePart(Int64 ticks, Int32 part) {
  return Int32();
};
DateTime HebrewCalendar___::AddMonths(DateTime time, Int32 months) {
  return DateTime();
};
DateTime HebrewCalendar___::AddYears(DateTime time, Int32 years) {
  return DateTime();
};
Int32 HebrewCalendar___::GetDayOfMonth(DateTime time) {
  return Int32();
};
DayOfWeek HebrewCalendar___::GetDayOfWeek(DateTime time) {
  return DayOfWeek::Saturday;
};
Int32 HebrewCalendar___::GetHebrewYearType(Int32 year, Int32 era) {
  return Int32();
};
Int32 HebrewCalendar___::GetDayOfYear(DateTime time) {
  return Int32();
};
Int32 HebrewCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return Int32();
};
Int32 HebrewCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return Int32();
};
Int32 HebrewCalendar___::GetEra(DateTime time) {
  return Int32();
};
Int32 HebrewCalendar___::GetMonth(DateTime time) {
  return Int32();
};
Int32 HebrewCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return Int32();
};
Int32 HebrewCalendar___::GetYear(DateTime time) {
  return Int32();
};
Boolean HebrewCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};
Int32 HebrewCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
};
Boolean HebrewCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
};
Boolean HebrewCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return Boolean();
};
Int32 HebrewCalendar___::GetDayDifference(Int32 lunarYearType, Int32 month1, Int32 day1, Int32 month2, Int32 day2) {
  return Int32();
};
DateTime HebrewCalendar___::HebrewToGregorian(Int32 hebrewYear, Int32 hebrewMonth, Int32 hebrewDay, Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  return DateTime();
};
DateTime HebrewCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return DateTime();
};
Int32 HebrewCalendar___::ToFourDigitYear(Int32 year) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Globalization::HebrewCalendarNamespace
