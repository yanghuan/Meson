#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType : int32_t;
enum class CalendarId : uint16_t;
namespace PersianCalendarNamespace {
CLASS(PersianCalendar) : public Calendar::in {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_BaseCalendarID();
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: void ctor();
  private: Int64 GetAbsoluteDatePersian(Int32 year, Int32 month, Int32 day);
  public: static void CheckTicksRange(Int64 ticks);
  public: static void CheckEraRange(Int32 era);
  public: static void CheckYearRange(Int32 year, Int32 era);
  public: static void CheckYearMonthRange(Int32 year, Int32 month, Int32 era);
  private: static Int32 MonthFromOrdinalDay(Int32 ordinalDay);
  private: static Int32 DaysInPreviousMonths(Int32 month);
  public: Int32 GetDatePart(Int64 ticks, Int32 part);
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
  public: static Int32 PersianEra;
  private: static Int64 s_persianEpoch;
  private: static Array<Int32> s_daysToMonth;
  private: static DateTime s_minDate;
  private: static DateTime s_maxDate;
};
} // namespace PersianCalendarNamespace
using PersianCalendar = PersianCalendarNamespace::PersianCalendar;
} // namespace System::Private::CoreLib::System::Globalization
