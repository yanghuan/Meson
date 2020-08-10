#include "UmAlQuraCalendar-dep.h"

#include <System.Private.CoreLib/System/Globalization/UmAlQuraCalendar-dep.h>

namespace System::Private::CoreLib::System::Globalization::UmAlQuraCalendarNamespace {
UmAlQuraCalendar___::DateMapping::DateMapping(Int32 MonthsLengthFlags, Int32 GYear, Int32 GMonth, Int32 GDay) {
}

DateTime UmAlQuraCalendar___::get_MinSupportedDateTime() {
  return DateTime();
}

DateTime UmAlQuraCalendar___::get_MaxSupportedDateTime() {
  return DateTime();
}

CalendarAlgorithmType UmAlQuraCalendar___::get_AlgorithmType() {
  return CalendarAlgorithmType::LunisolarCalendar;
}

CalendarId UmAlQuraCalendar___::get_BaseCalendarID() {
  return CalendarId::LAST_CALENDAR;
}

CalendarId UmAlQuraCalendar___::get_ID() {
  return CalendarId::LAST_CALENDAR;
}

Int32 UmAlQuraCalendar___::get_DaysInYearBeforeMinSupportedYear() {
  return Int32();
}

Array<Int32> UmAlQuraCalendar___::get_Eras() {
  return Array<Int32>();
}

Int32 UmAlQuraCalendar___::get_TwoDigitYearMax() {
  return Int32();
}

void UmAlQuraCalendar___::set_TwoDigitYearMax(Int32 value) {
}

Array<UmAlQuraCalendar::in::DateMapping> UmAlQuraCalendar___::InitDateMapping() {
  return Array<UmAlQuraCalendar::in::DateMapping>();
}

void UmAlQuraCalendar___::ctor() {
}

void UmAlQuraCalendar___::ConvertHijriToGregorian(Int32 HijriYear, Int32 HijriMonth, Int32 HijriDay, Int32& yg, Int32& mg, Int32& dg) {
}

Int64 UmAlQuraCalendar___::GetAbsoluteDateUmAlQura(Int32 year, Int32 month, Int32 day) {
  return Int64();
}

void UmAlQuraCalendar___::CheckTicksRange(Int64 ticks) {
}

void UmAlQuraCalendar___::CheckEraRange(Int32 era) {
}

void UmAlQuraCalendar___::CheckYearRange(Int32 year, Int32 era) {
}

void UmAlQuraCalendar___::CheckYearMonthRange(Int32 year, Int32 month, Int32 era) {
}

void UmAlQuraCalendar___::ConvertGregorianToHijri(DateTime time, Int32& HijriYear, Int32& HijriMonth, Int32& HijriDay) {
}

Int32 UmAlQuraCalendar___::GetDatePart(DateTime time, Int32 part) {
  return Int32();
}

DateTime UmAlQuraCalendar___::AddMonths(DateTime time, Int32 months) {
  return DateTime();
}

DateTime UmAlQuraCalendar___::AddYears(DateTime time, Int32 years) {
  return DateTime();
}

Int32 UmAlQuraCalendar___::GetDayOfMonth(DateTime time) {
  return Int32();
}

DayOfWeek UmAlQuraCalendar___::GetDayOfWeek(DateTime time) {
  return DayOfWeek::Saturday;
}

Int32 UmAlQuraCalendar___::GetDayOfYear(DateTime time) {
  return Int32();
}

Int32 UmAlQuraCalendar___::GetDaysInMonth(Int32 year, Int32 month, Int32 era) {
  return Int32();
}

Int32 UmAlQuraCalendar___::RealGetDaysInYear(Int32 year) {
  return Int32();
}

Int32 UmAlQuraCalendar___::GetDaysInYear(Int32 year, Int32 era) {
  return Int32();
}

Int32 UmAlQuraCalendar___::GetEra(DateTime time) {
  return Int32();
}

Int32 UmAlQuraCalendar___::GetMonth(DateTime time) {
  return Int32();
}

Int32 UmAlQuraCalendar___::GetMonthsInYear(Int32 year, Int32 era) {
  return Int32();
}

Int32 UmAlQuraCalendar___::GetYear(DateTime time) {
  return Int32();
}

Boolean UmAlQuraCalendar___::IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era) {
  return Boolean();
}

Int32 UmAlQuraCalendar___::GetLeapMonth(Int32 year, Int32 era) {
  return Int32();
}

Boolean UmAlQuraCalendar___::IsLeapMonth(Int32 year, Int32 month, Int32 era) {
  return Boolean();
}

Boolean UmAlQuraCalendar___::IsLeapYear(Int32 year, Int32 era) {
  return Boolean();
}

DateTime UmAlQuraCalendar___::ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era) {
  return DateTime();
}

Int32 UmAlQuraCalendar___::ToFourDigitYear(Int32 year) {
  return Int32();
}

void UmAlQuraCalendar___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Globalization::UmAlQuraCalendarNamespace
