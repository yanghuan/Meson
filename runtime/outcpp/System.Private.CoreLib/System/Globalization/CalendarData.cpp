#include "CalendarData-dep.h"

#include <System.Private.CoreLib/System/Globalization/CalendarData-dep.h>

namespace System::Private::CoreLib::System::Globalization::CalendarDataNamespace {
CalendarData CalendarData___::CreateInvariant() {
  return nullptr;
};
void CalendarData___::InitializeEraNames(String localeName, CalendarId calendarId) {
};
void CalendarData___::InitializeAbbreviatedEraNames(String localeName, CalendarId calendarId) {
};
CalendarData CalendarData___::GetCalendarData(CalendarId calendarId) {
  return nullptr;
};
String CalendarData___::CalendarIdToCultureName(CalendarId calendarId) {
  return nullptr;
};
Boolean CalendarData___::SystemSupportsTaiwaneseCalendar() {
  return Boolean();
};
Boolean CalendarData___::IcuLoadCalendarDataFromSystem(String localeName, CalendarId calendarId) {
  return Boolean();
};
Int32 CalendarData___::IcuGetTwoDigitYearMax(CalendarId calendarId) {
  return Int32();
};
Int32 CalendarData___::IcuGetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars) {
  return Int32();
};
Boolean CalendarData___::IcuSystemSupportsTaiwaneseCalendar() {
  return Boolean();
};
Boolean CalendarData___::GetCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, String& calendarString) {
  return Boolean();
};
Boolean CalendarData___::EnumDatePatterns(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& datePatterns) {
  return Boolean();
};
void CalendarData___::FixDefaultShortDatePattern(List<String> shortDatePatterns) {
};
String CalendarData___::NormalizeDatePattern(String input) {
  return nullptr;
};
void CalendarData___::NormalizeDayOfWeek(String input, StringBuilder destination, Int32& index) {
};
Int32 CalendarData___::CountOccurrences(String input, Char value, Int32& index) {
  return Int32();
};
Boolean CalendarData___::EnumMonthNames(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& monthNames, String& leapHebrewMonthName) {
  return Boolean();
};
Boolean CalendarData___::EnumEraNames(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& eraNames) {
  return Boolean();
};
Boolean CalendarData___::EnumCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& calendarData) {
  return Boolean();
};
Boolean CalendarData___::EnumCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, IcuEnumCalendarsData& callbackContext) {
  return Boolean();
};
void CalendarData___::EnumCalendarInfoCallback(String calendarString, IntPtr context) {
};
Boolean CalendarData___::NlsLoadCalendarDataFromSystem(String localeName, CalendarId calendarId) {
  return Boolean();
};
Int32 CalendarData___::NlsGetTwoDigitYearMax(CalendarId calendarId) {
  return Int32();
};
Int32 CalendarData___::NlsGetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars) {
  return Int32();
};
Boolean CalendarData___::NlsSystemSupportsTaiwaneseCalendar() {
  return Boolean();
};
void CalendarData___::CheckSpecialCalendar(CalendarId& calendar, String& localeName) {
};
Boolean CalendarData___::CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, Int32& data) {
  return Boolean();
};
Boolean CalendarData___::CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, String& data) {
  return Boolean();
};
Interop::BOOL CalendarData___::EnumCalendarInfoCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr pReserved, void* lParam) {
  return Interop::BOOL::TRUE;
};
Boolean CalendarData___::CallEnumCalendarInfo(String localeName, CalendarId calendar, UInt32 calType, UInt32 lcType, Array<String>& data) {
  return Boolean();
};
Boolean CalendarData___::GetCalendarDayInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings) {
  return Boolean();
};
Boolean CalendarData___::GetCalendarMonthInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings) {
  return Boolean();
};
Interop::BOOL CalendarData___::EnumCalendarsCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr reserved, void* lParam) {
  return Interop::BOOL::TRUE;
};
String CalendarData___::GetUserDefaultLocaleName() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Globalization::CalendarDataNamespace
