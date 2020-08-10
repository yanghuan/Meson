#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType;
enum class CalendarId : uint16_t;
namespace JulianCalendarNamespace {
CLASS(JulianCalendar) : public Calendar::in {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: void ctor();
  public: static void CheckEraRange(Int32 era);
  public: void CheckYearEraRange(Int32 year, Int32 era);
  public: static void CheckMonthRange(Int32 month);
  public: static void CheckDayRange(Int32 year, Int32 month, Int32 day);
  public: static Int32 GetDatePart(Int64 ticks, Int32 part);
  public: static Int64 DateToTicks(Int32 year, Int32 month, Int32 day);
  public: DateTime AddMonths(DateTime time, Int32 months);
  public: DateTime AddYears(DateTime time, Int32 years);
  public: Int32 GetDayOfMonth(DateTime time);
  public: DayOfWeek GetDayOfWeek(DateTime time);
  public: Int32 GetDayOfYear(DateTime time);
  public: Int32 GetDaysInMonth(Int32 year, Int32 month, Int32 era);
  public: Int32 GetDaysInYear(Int32 year, Int32 era);
  public: Int32 GetEra(DateTime time);
  public: Int32 GetMonth(DateTime time);
  public: Int32 GetMonthsInYear(Int32 year, Int32 era);
  public: Int32 GetYear(DateTime time);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Int32 GetLeapMonth(Int32 year, Int32 era);
  public: Boolean IsLeapMonth(Int32 year, Int32 month, Int32 era);
  public: Boolean IsLeapYear(Int32 year, Int32 era);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  public: Int32 ToFourDigitYear(Int32 year);
  private: static void ctor_static();
  public: static Int32 JulianEra;
  private: static Array<Int32> s_daysToMonth365;
  private: static Array<Int32> s_daysToMonth366;
  public: Int32 MaxYear;
};
} // namespace JulianCalendarNamespace
using JulianCalendar = JulianCalendarNamespace::JulianCalendar;
} // namespace System::Private::CoreLib::System::Globalization
