#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Char)
FORWARDS(IntPtr)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(SpanFunc, TSpan, T1, T2, T3, TResult)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarDataType : int32_t;
enum class CalendarId : uint16_t;
namespace CalendarDataNamespace {
using namespace System::Buffers;
using namespace System::Collections::Generic;
using namespace System::Text;
CLASS(CalendarData) : public object {
  private: struct IcuEnumCalendarsData : public valueType<IcuEnumCalendarsData> {
    public: List<String> Results;
    public: Boolean DisallowDuplicates;
  };
  private: struct EnumData : public valueType<EnumData> {
    public: String userOverride;
    public: List<String> strings;
  };
  public: struct NlsEnumCalendarsData : public valueType<NlsEnumCalendarsData> {
    public: Int32 userOverride;
    public: List<Int32> calendars;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: Interop::Globalization::ResultCode _GetCalendarInfo_b__33_0(Span<Char> buffer, String locale, CalendarId id, CalendarDataType type);
    public: static __c __9;
    public: static SpanFunc<Char, String, CalendarId, CalendarDataType, Interop::Globalization::ResultCode> __9__33_0;
  };
  public: void ctor();
  private: static CalendarData CreateInvariant();
  public: void ctor(String localeName, CalendarId calendarId, Boolean bUseUserOverrides);
  private: void InitializeEraNames(String localeName, CalendarId calendarId);
  private: void InitializeAbbreviatedEraNames(String localeName, CalendarId calendarId);
  public: static CalendarData GetCalendarData(CalendarId calendarId);
  private: static String CalendarIdToCultureName(CalendarId calendarId);
  private: Boolean SystemSupportsTaiwaneseCalendar();
  private: Boolean IcuLoadCalendarDataFromSystem(String localeName, CalendarId calendarId);
  public: static Int32 IcuGetTwoDigitYearMax(CalendarId calendarId);
  public: static Int32 IcuGetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars);
  private: static Boolean IcuSystemSupportsTaiwaneseCalendar();
  private: static Boolean GetCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, String& calendarString);
  private: static Boolean EnumDatePatterns(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& datePatterns);
  private: static void FixDefaultShortDatePattern(List<String> shortDatePatterns);
  private: static String NormalizeDatePattern(String input);
  private: static void NormalizeDayOfWeek(String input, StringBuilder destination, Int32& index);
  private: static Int32 CountOccurrences(String input, Char value, Int32& index);
  private: static Boolean EnumMonthNames(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& monthNames, String& leapHebrewMonthName);
  private: static Boolean EnumEraNames(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& eraNames);
  public: static Boolean EnumCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& calendarData);
  private: static Boolean EnumCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, IcuEnumCalendarsData& callbackContext);
  private: static void EnumCalendarInfoCallback(String calendarString, IntPtr context);
  private: Boolean NlsLoadCalendarDataFromSystem(String localeName, CalendarId calendarId);
  public: static Int32 NlsGetTwoDigitYearMax(CalendarId calendarId);
  public: static Int32 NlsGetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars);
  private: static Boolean NlsSystemSupportsTaiwaneseCalendar();
  private: static void CheckSpecialCalendar(CalendarId& calendar, String& localeName);
  private: static Boolean CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, Int32& data);
  private: static Boolean CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, String& data);
  private: static Interop::BOOL EnumCalendarInfoCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr pReserved, void* lParam);
  private: static Boolean CallEnumCalendarInfo(String localeName, CalendarId calendar, UInt32 calType, UInt32 lcType, Array<String>& data);
  private: static Boolean GetCalendarDayInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings);
  private: static Boolean GetCalendarMonthInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings);
  private: static Interop::BOOL EnumCalendarsCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr reserved, void* lParam);
  private: static String GetUserDefaultLocaleName();
  public: static void cctor();
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
