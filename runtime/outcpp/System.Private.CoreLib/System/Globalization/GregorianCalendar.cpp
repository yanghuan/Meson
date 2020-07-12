#include "GregorianCalendar-dep.h"

namespace System::Private::CoreLib::System::Globalization::GregorianCalendarNamespace {
DateTime GregorianCalendar___::get_MinSupportedDateTime() {
  return DateTime();
};

DateTime GregorianCalendar___::get_MaxSupportedDateTime() {
  return DateTime();
};

CalendarAlgorithmType GregorianCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
};

GregorianCalendarTypes GregorianCalendar___::get_CalendarType() {
  return GregorianCalendarTypes::TransliteratedFrench;
};

void GregorianCalendar___::set_CalendarType(GregorianCalendarTypes value) {
};

CalendarId GregorianCalendar___::get_ID() {
  return CalendarId::LAST_CALENDAR;
};

Array<Int32> GregorianCalendar___::get_Eras() {
  return Array<Int32>();
};

Int32 GregorianCalendar___::get_TwoDigitYearMax() {
  return Int32();
};

void GregorianCalendar___::set_TwoDigitYearMax(Int32 value) {
};

Calendar GregorianCalendar___::GetDefaultInstance() {
  return nullptr;
};

Int64 GregorianCalendar___::GetAbsoluteDate(Int32 year, Int32 month, Int32 day) {
  return Int64();
};

Int64 GregorianCalendar___::DateToTicks(Int32 year, Int32 month, Int32 day) {
  return Int64();
};

DateTime GregorianCalendar___::AddMonths(DateTime time, Int32 months) {
  return DateTime();
};

DateTime GregorianCalendar___::AddYears(DateTime time, Int32 years) {
  return DateTime();
};

Int32 GregorianCalendar___::GetDayOfMonth(DateTime time) {
  return Int32();
};

DayOfWeek GregorianCalendar___::GetDayOfWeek(DateTime time) {
  return DayOfWeek::Saturday;
};

Int32 GregorianCalendar___::GetDayOfYear(DateTime time) {
  return Int32();
};

Int32 GregorianCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return Int32();
};

Int32 GregorianCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return Int32();
};

Int32 GregorianCalendar___::GetEra(DateTime time) {
  return Int32();
};

Int32 GregorianCalendar___::GetMonth(DateTime time) {
  return Int32();
};

Int32 GregorianCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return Int32();
};

Int32 GregorianCalendar___::GetYear(DateTime time) {
  return Int32();
};

Boolean GregorianCalendar___::IsValidYear(Int32 year, Int32 era) {
  return Boolean();
};

Boolean GregorianCalendar___::IsValidDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};

Boolean GregorianCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
};

Int32 GregorianCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
};

Boolean GregorianCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
};

Boolean GregorianCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return Boolean();
};

DateTime GregorianCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return DateTime();
};

Boolean GregorianCalendar___::TryToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era, DateTime& result) {
  return Boolean();
};

Int32 GregorianCalendar___::ToFourDigitYear(Int32 year) {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Globalization::GregorianCalendarNamespace
