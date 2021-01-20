#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARD_(Array)
FORWARDS(DateTime)
FORWARDS(Double)
FORWARD(ICloneable)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType : int32_t;
enum class CalendarId : uint16_t;
enum class CalendarWeekRule : int32_t;
namespace CalendarNamespace {
CLASS(Calendar) : public object {
  public: using interface = rt::TypeList<ICloneable>;
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_ID();
  public: CalendarId get_BaseCalendarID();
  public: Boolean get_IsReadOnly();
  public: Int32 get_CurrentEraValue();
  public: Array<Int32> get_Eras();
  protected: Int32 get_DaysInYearBeforeMinSupportedYear();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: void ctor();
  public: Object Clone();
  public: static Calendar ReadOnly(Calendar calendar);
  public: void VerifyWritable();
  public: void SetReadOnlyState(Boolean readOnly);
  public: static void CheckAddResult(Int64 ticks, DateTime minValue, DateTime maxValue);
  public: DateTime Add(DateTime time, Double value, Int32 scale);
  public: DateTime AddMilliseconds(DateTime time, Double milliseconds);
  public: DateTime AddDays(DateTime time, Int32 days);
  public: DateTime AddHours(DateTime time, Int32 hours);
  public: DateTime AddMinutes(DateTime time, Int32 minutes);
  public: DateTime AddMonths(DateTime time, Int32 months);
  public: DateTime AddSeconds(DateTime time, Int32 seconds);
  public: DateTime AddWeeks(DateTime time, Int32 weeks);
  public: DateTime AddYears(DateTime time, Int32 years);
  public: Int32 GetDayOfMonth(DateTime time);
  public: DayOfWeek GetDayOfWeek(DateTime time);
  public: Int32 GetDayOfYear(DateTime time);
  public: Int32 GetDaysInMonth(Int32 year, Int32 month);
  public: Int32 GetDaysInMonth(Int32 year, Int32 month, Int32 era);
  public: Int32 GetDaysInYear(Int32 year);
  public: Int32 GetDaysInYear(Int32 year, Int32 era);
  public: Int32 GetEra(DateTime time);
  public: Int32 GetHour(DateTime time);
  public: Double GetMilliseconds(DateTime time);
  public: Int32 GetMinute(DateTime time);
  public: Int32 GetMonth(DateTime time);
  public: Int32 GetMonthsInYear(Int32 year);
  public: Int32 GetMonthsInYear(Int32 year, Int32 era);
  public: Int32 GetSecond(DateTime time);
  public: Int32 GetFirstDayWeekOfYear(DateTime time, Int32 firstDayOfWeek);
  private: Int32 GetWeekOfYearFullDays(DateTime time, Int32 firstDayOfWeek, Int32 fullDays);
  private: Int32 GetWeekOfYearOfMinSupportedDateTime(Int32 firstDayOfWeek, Int32 minimumDaysInFirstWeek);
  public: Int32 GetWeekOfYear(DateTime time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek);
  public: Int32 GetYear(DateTime time);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Boolean IsLeapMonth(Int32 year, Int32 month);
  public: Boolean IsLeapMonth(Int32 year, Int32 month, Int32 era);
  public: Int32 GetLeapMonth(Int32 year);
  public: Int32 GetLeapMonth(Int32 year, Int32 era);
  public: Boolean IsLeapYear(Int32 year);
  public: Boolean IsLeapYear(Int32 year, Int32 era);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  public: Boolean TryToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era, DateTime& result);
  public: Boolean IsValidYear(Int32 year, Int32 era);
  public: Boolean IsValidMonth(Int32 year, Int32 month, Int32 era);
  public: Boolean IsValidDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Int32 ToFourDigitYear(Int32 year);
  public: static Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 millisecond);
  public: static Int32 GetSystemTwoDigitYearSetting(CalendarId CalID, Int32 defaultYearValue);
  private: Int32 _currentEraValue;
  private: Boolean _isReadOnly;
  public: static constexpr Int32 CurrentEra = 0;
  public: Int32 _twoDigitYearMax;
};
} // namespace CalendarNamespace
using Calendar = CalendarNamespace::Calendar;
} // namespace System::Private::CoreLib::System::Globalization
