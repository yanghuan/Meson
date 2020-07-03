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
Boolean CalendarData___::LoadCalendarDataFromSystem(String localeName, CalendarId calendarId) {
  return Boolean();
};
Int32 CalendarData___::GetTwoDigitYearMax(CalendarId calendarId) {
  return Int32();
};
Int32 CalendarData___::GetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars) {
  return Int32();
};
Boolean CalendarData___::SystemSupportsTaiwaneseCalendar() {
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
  return Interop::BOOL();
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
  return Interop::BOOL();
};
String CalendarData___::GetUserDefaultLocaleName() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Globalization::CalendarDataNamespace
