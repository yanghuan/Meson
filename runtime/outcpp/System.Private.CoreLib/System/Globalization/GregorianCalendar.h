#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType : int32_t;
enum class CalendarId : uint16_t;
enum class GregorianCalendarTypes : int32_t;
namespace GregorianCalendarNamespace {
CLASS(GregorianCalendar) : public Calendar::in {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: GregorianCalendarTypes get_CalendarType();
  public: void set_CalendarType(GregorianCalendarTypes value);
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: static Calendar GetDefaultInstance();
  public: void ctor();
  public: void ctor(GregorianCalendarTypes type);
  public: static Int64 GetAbsoluteDate(Int32 year, Int32 month, Int32 day);
  public: Int64 DateToTicks(Int32 year, Int32 month, Int32 day);
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
  public: Boolean IsValidYear(Int32 year, Int32 era);
  public: Boolean IsValidDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Int32 GetLeapMonth(Int32 year, Int32 era);
  public: Boolean IsLeapMonth(Int32 year, Int32 month, Int32 era);
  public: Boolean IsLeapYear(Int32 year, Int32 era);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  public: Boolean TryToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era, DateTime& result);
  public: Int32 ToFourDigitYear(Int32 year);
  public: static void cctor();
  public: static constexpr Int32 ADEra = 1;
  private: GregorianCalendarTypes _type;
  private: static Array<Int32> DaysToMonth365;
  private: static Array<Int32> DaysToMonth366;
  private: static Calendar s_defaultInstance;
};
} // namespace GregorianCalendarNamespace
using GregorianCalendar = GregorianCalendarNamespace::GregorianCalendar;
} // namespace System::Private::CoreLib::System::Globalization
