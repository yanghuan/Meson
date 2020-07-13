#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType;
enum class CalendarId : uint16_t;
namespace UmAlQuraCalendarNamespace {
CLASS(UmAlQuraCalendar) {
  private: struct DateMapping {
    public: Int32 HijriMonthsLengthFlags;
    public: DateTime GregorianDate;
  };
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_BaseCalendarID();
  public: CalendarId get_ID();
  protected: Int32 get_DaysInYearBeforeMinSupportedYear();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  private: static Array<DateMapping> InitDateMapping();
  private: static void ConvertHijriToGregorian(Int32 HijriYear, Int32 HijriMonth, Int32 HijriDay, Int32& yg, Int32& mg, Int32& dg);
  private: static Int64 GetAbsoluteDateUmAlQura(Int32 year, Int32 month, Int32 day);
  public: static void CheckTicksRange(Int64 ticks);
  public: static void CheckEraRange(Int32 era);
  public: static void CheckYearRange(Int32 year, Int32 era);
  public: static void CheckYearMonthRange(Int32 year, Int32 month, Int32 era);
  private: static void ConvertGregorianToHijri(DateTime time, Int32& HijriYear, Int32& HijriMonth, Int32& HijriDay);
  private: Int32 GetDatePart(DateTime time, Int32 part);
  public: DateTime AddMonths(DateTime time, Int32 months);
  public: DateTime AddYears(DateTime time, Int32 years);
  public: Int32 GetDayOfMonth(DateTime time);
  public: DayOfWeek GetDayOfWeek(DateTime time);
  public: Int32 GetDayOfYear(DateTime time);
  public: Int32 GetDaysInMonth(Int32 year, Int32 month, Int32 era);
  public: static Int32 RealGetDaysInYear(Int32 year);
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
  private: static Array<DateMapping> s_hijriYearInfo;
  public: static constexpr Int32 UmAlQuraEra = 1;
  private: static DateTime s_minDate;
  private: static DateTime s_maxDate;
};
} // namespace UmAlQuraCalendarNamespace
using UmAlQuraCalendar = UmAlQuraCalendarNamespace::UmAlQuraCalendar;
} // namespace System::Private::CoreLib::System::Globalization
