#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(DateTime)
enum class DayOfWeek;
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarWeekRule;
FORWARD(Calendar)
FORWARD(EraInfo)
namespace GregorianCalendarHelperNamespace {
CLASS(GregorianCalendarHelper) {
  public: Int32 get_MaxYear();
  public: Array<Int32> get_Eras();
  private: Int32 GetYearOffset(Int32 year, Int32 era, Boolean throwOnError);
  public: Int32 GetGregorianYear(Int32 year, Int32 era);
  public: Boolean IsValidYear(Int32 year, Int32 era);
  public: Int32 GetDatePart(Int64 ticks, Int32 part);
  public: static Int64 GetAbsoluteDate(Int32 year, Int32 month, Int32 day);
  public: static Int64 DateToTicks(Int32 year, Int32 month, Int32 day);
  public: static Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 millisecond);
  public: void CheckTicksRange(Int64 ticks);
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
  public: Int32 GetYear(Int32 year, DateTime time);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Int32 GetLeapMonth(Int32 year, Int32 era);
  public: Boolean IsLeapMonth(Int32 year, Int32 month, Int32 era);
  public: Boolean IsLeapYear(Int32 year, Int32 era);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  public: Int32 GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek);
  public: Int32 ToFourDigitYear(Int32 year, Int32 twoDigitYearMax);
  public: static Array<Int32> DaysToMonth365;
  public: static Array<Int32> DaysToMonth366;
  public: Int32 m_maxYear;
  public: Int32 m_minYear;
  public: Calendar m_Cal;
  public: Array<EraInfo> m_EraInfo;
  public: Array<Int32> m_eras;
};
} // namespace GregorianCalendarHelperNamespace
using GregorianCalendarHelper = GregorianCalendarHelperNamespace::GregorianCalendarHelper;
} // namespace System::Private::CoreLib::System::Globalization
