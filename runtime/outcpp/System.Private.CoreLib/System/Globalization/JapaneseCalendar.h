#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType : int32_t;
enum class CalendarId : uint16_t;
enum class CalendarWeekRule : int32_t;
FORWARD(EraInfo)
FORWARD(GregorianCalendarHelper)
namespace JapaneseCalendarNamespace {
CLASS(JapaneseCalendar) : public Calendar::in {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: static Array<EraInfo> GetEraInfo();
  public: static Calendar GetDefaultInstance();
  public: void ctor();
  public: DateTime AddMonths(DateTime time, Int32 months);
  public: DateTime AddYears(DateTime time, Int32 years);
  public: Int32 GetDaysInMonth(Int32 year, Int32 month, Int32 era);
  public: Int32 GetDaysInYear(Int32 year, Int32 era);
  public: Int32 GetDayOfMonth(DateTime time);
  public: DayOfWeek GetDayOfWeek(DateTime time);
  public: Int32 GetDayOfYear(DateTime time);
  public: Int32 GetMonthsInYear(Int32 year, Int32 era);
  public: Int32 GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek);
  public: Int32 GetEra(DateTime time);
  public: Int32 GetMonth(DateTime time);
  public: Int32 GetYear(DateTime time);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Boolean IsLeapYear(Int32 year, Int32 era);
  public: Int32 GetLeapMonth(Int32 year, Int32 era);
  public: Boolean IsLeapMonth(Int32 year, Int32 month, Int32 era);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  public: Int32 ToFourDigitYear(Int32 year);
  public: static Array<String> EraNames();
  public: static Array<String> AbbrevEraNames();
  public: static Array<String> EnglishEraNames();
  public: Boolean IsValidYear(Int32 year, Int32 era);
  private: static Array<EraInfo> IcuGetJapaneseEras();
  private: static String GetAbbreviatedEraName(Array<String> eraNames, Int32 eraIndex);
  private: static Boolean GetJapaneseEraStartDate(Int32 era, DateTime& dateTime);
  private: static Array<EraInfo> NlsGetJapaneseEras();
  private: static Int32 CompareEraRanges(EraInfo a, EraInfo b);
  private: static EraInfo GetEraFromValue(String value, String data);
  public: static void cctor();
  private: static DateTime s_calendarMinValue;
  private: static Array<EraInfo> s_japaneseEraInfo;
  public: static Calendar s_defaultInstance;
  public: GregorianCalendarHelper _helper;
};
} // namespace JapaneseCalendarNamespace
using JapaneseCalendar = JapaneseCalendarNamespace::JapaneseCalendar;
} // namespace System::Private::CoreLib::System::Globalization
