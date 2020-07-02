#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Char)
FORWARDS(IntPtr)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarId : uint16_t;
namespace CalendarDataNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(CalendarData) {
  private: struct EnumData {
    public: String userOverride;
    public: List<String> strings;
  };
  private: struct EnumCalendarsData {
    public: Int32 userOverride;
    public: List<Int32> calendars;
  };
  private: static CalendarData CreateInvariant();
  private: void InitializeEraNames(String localeName, CalendarId calendarId);
  private: void InitializeAbbreviatedEraNames(String localeName, CalendarId calendarId);
  public: static CalendarData GetCalendarData(CalendarId calendarId);
  private: static String CalendarIdToCultureName(CalendarId calendarId);
  private: Boolean LoadCalendarDataFromSystem(String localeName, CalendarId calendarId);
  public: static Int32 GetTwoDigitYearMax(CalendarId calendarId);
  public: static Int32 GetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars);
  private: static Boolean SystemSupportsTaiwaneseCalendar();
  private: static void CheckSpecialCalendar(CalendarId& calendar, String& localeName);
  private: static Boolean CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, Int32& data);
  private: static Boolean CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, String& data);
  private: static Interop::BOOL EnumCalendarInfoCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr pReserved, void* lParam);
  private: static Boolean CallEnumCalendarInfo(String localeName, CalendarId calendar, UInt32 calType, UInt32 lcType, Array<String>& data);
  private: static Boolean GetCalendarDayInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings);
  private: static Boolean GetCalendarMonthInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings);
  private: static Interop::BOOL EnumCalendarsCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr reserved, void* lParam);
  private: static String GetUserDefaultLocaleName();
  public: String sNativeName;
  public: Array<String> saShortDates;
  public: Array<String> saYearMonths;
  public: Array<String> saLongDates;
  public: String sMonthDay;
  public: Array<String> saEraNames;
  public: Array<String> saAbbrevEraNames;
  public: Array<String> saAbbrevEnglishEraNames;
  public: Array<String> saDayNames;
  public: Array<String> saAbbrevDayNames;
  public: Array<String> saSuperShortDayNames;
  public: Array<String> saMonthNames;
  public: Array<String> saAbbrevMonthNames;
  public: Array<String> saMonthGenitiveNames;
  public: Array<String> saAbbrevMonthGenitiveNames;
  public: Array<String> saLeapYearMonthNames;
  public: Int32 iTwoDigitYearMax;
  public: Int32 iCurrentEra;
  public: Boolean bUseUserOverrides;
  public: static CalendarData Invariant;
};
} // namespace CalendarDataNamespace
using CalendarData = CalendarDataNamespace::CalendarData;
} // namespace System::Private::CoreLib::System::Globalization
