#include "EastAsianLunisolarCalendar-dep.h"

namespace System::Private::CoreLib::System::Globalization::EastAsianLunisolarCalendarNamespace {
CalendarAlgorithmType EastAsianLunisolarCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
};

Int32 EastAsianLunisolarCalendar___::get_TwoDigitYearMax() {
  return Int32();
};

void EastAsianLunisolarCalendar___::set_TwoDigitYearMax(Int32 value) {
};

Int32 EastAsianLunisolarCalendar___::GetSexagenaryYear(DateTime time) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetCelestialStem(Int32 sexagenaryYear) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetTerrestrialBranch(Int32 sexagenaryYear) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::MinEraCalendarYear(Int32 era) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::MaxEraCalendarYear(Int32 era) {
  return Int32();
};

void EastAsianLunisolarCalendar___::CheckTicksRange(Int64 ticks) {
};

void EastAsianLunisolarCalendar___::CheckEraRange(Int32 era) {
};

Int32 EastAsianLunisolarCalendar___::CheckYearRange(Int32 year, Int32 era) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::CheckYearMonthRange(Int32 year, Int32 month, Int32 era) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::InternalGetDaysInMonth(Int32 year, Int32 month) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return Int32();
};

Boolean EastAsianLunisolarCalendar___::GregorianIsLeapYear(Int32 y) {
  return Boolean();
};

DateTime EastAsianLunisolarCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return DateTime();
};

void EastAsianLunisolarCalendar___::GregorianToLunar(Int32 solarYear, Int32 solarMonth, Int32 solarDate, Int32& lunarYear, Int32& lunarMonth, Int32& lunarDate) {
};

Boolean EastAsianLunisolarCalendar___::LunarToGregorian(Int32 lunarYear, Int32 lunarMonth, Int32 lunarDate, Int32& solarYear, Int32& solarMonth, Int32& solarDay) {
  return Boolean();
};

DateTime EastAsianLunisolarCalendar___::LunarToTime(DateTime time, Int32 year, Int32 month, Int32 day) {
  return DateTime();
};

void EastAsianLunisolarCalendar___::TimeToLunar(DateTime time, Int32& year, Int32& month, Int32& day) {
};

DateTime EastAsianLunisolarCalendar___::AddMonths(DateTime time, Int32 months) {
  return DateTime();
};

DateTime EastAsianLunisolarCalendar___::AddYears(DateTime time, Int32 years) {
  return DateTime();
};

Int32 EastAsianLunisolarCalendar___::GetDayOfYear(DateTime time) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetDayOfMonth(DateTime time) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetMonth(DateTime time) {
  return Int32();
};

Int32 EastAsianLunisolarCalendar___::GetYear(DateTime time) {
  return Int32();
};

DayOfWeek EastAsianLunisolarCalendar___::GetDayOfWeek(DateTime time) {
  return DayOfWeek::Saturday;
};

Int32 EastAsianLunisolarCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return Int32();
};

Boolean EastAsianLunisolarCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};

Boolean EastAsianLunisolarCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
};

Int32 EastAsianLunisolarCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
};

Boolean EastAsianLunisolarCalendar___::InternalIsLeapYear(Int32 year) {
  return Boolean();
};

Boolean EastAsianLunisolarCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return Boolean();
};

Int32 EastAsianLunisolarCalendar___::ToFourDigitYear(Int32 year) {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Globalization::EastAsianLunisolarCalendarNamespace
