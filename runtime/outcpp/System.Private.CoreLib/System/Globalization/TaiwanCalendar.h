#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType;
enum class CalendarId : uint16_t;
enum class CalendarWeekRule;
FORWARD(EraInfo)
FORWARD(GregorianCalendarHelper)
namespace TaiwanCalendarNamespace {
CLASS(TaiwanCalendar) : public Calendar::in {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: static Calendar GetDefaultInstance();
  public: void Ctor();
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
  private: static void SCtor();
  private: static Array<EraInfo> s_taiwanEraInfo;
  private: static Calendar s_defaultInstance;
  private: GregorianCalendarHelper _helper;
  private: static DateTime s_calendarMinValue;
};
} // namespace TaiwanCalendarNamespace
using TaiwanCalendar = TaiwanCalendarNamespace::TaiwanCalendar;
} // namespace System::Private::CoreLib::System::Globalization
