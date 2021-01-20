#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType : int32_t;
FORWARD(EraInfo)
namespace EastAsianLunisolarCalendarNamespace {
CLASS(EastAsianLunisolarCalendar) : public Calendar::in {
  public: CalendarAlgorithmType get_AlgorithmType();
  public: Int32 get_MinCalendarYear();
  public: Int32 get_MaxCalendarYear();
  public: Array<EraInfo> get_CalEraInfo();
  public: DateTime get_MinDate();
  public: DateTime get_MaxDate();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: Int32 GetSexagenaryYear(DateTime time);
  public: Int32 GetCelestialStem(Int32 sexagenaryYear);
  public: Int32 GetTerrestrialBranch(Int32 sexagenaryYear);
  public: Int32 GetYearInfo(Int32 LunarYear, Int32 Index);
  public: Int32 GetYear(Int32 year, DateTime time);
  public: Int32 GetGregorianYear(Int32 year, Int32 era);
  public: Int32 MinEraCalendarYear(Int32 era);
  public: Int32 MaxEraCalendarYear(Int32 era);
  public: void ctor();
  public: void CheckTicksRange(Int64 ticks);
  public: void CheckEraRange(Int32 era);
  public: Int32 CheckYearRange(Int32 year, Int32 era);
  public: Int32 CheckYearMonthRange(Int32 year, Int32 month, Int32 era);
  public: Int32 InternalGetDaysInMonth(Int32 year, Int32 month);
  public: Int32 GetDaysInMonth(Int32 year, Int32 month, Int32 era);
  private: static Boolean GregorianIsLeapYear(Int32 y);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  private: void GregorianToLunar(Int32 solarYear, Int32 solarMonth, Int32 solarDate, Int32& lunarYear, Int32& lunarMonth, Int32& lunarDate);
  private: Boolean LunarToGregorian(Int32 lunarYear, Int32 lunarMonth, Int32 lunarDate, Int32& solarYear, Int32& solarMonth, Int32& solarDay);
  private: DateTime LunarToTime(DateTime time, Int32 year, Int32 month, Int32 day);
  private: void TimeToLunar(DateTime time, Int32& year, Int32& month, Int32& day);
  public: DateTime AddMonths(DateTime time, Int32 months);
  public: DateTime AddYears(DateTime time, Int32 years);
  public: Int32 GetDayOfYear(DateTime time);
  public: Int32 GetDayOfMonth(DateTime time);
  public: Int32 GetDaysInYear(Int32 year, Int32 era);
  public: Int32 GetMonth(DateTime time);
  public: Int32 GetYear(DateTime time);
  public: DayOfWeek GetDayOfWeek(DateTime time);
  public: Int32 GetMonthsInYear(Int32 year, Int32 era);
  public: Boolean IsLeapDay(Int32 year, Int32 month, Int32 day, Int32 era);
  public: Boolean IsLeapMonth(Int32 year, Int32 month, Int32 era);
  public: Int32 GetLeapMonth(Int32 year, Int32 era);
  public: Boolean InternalIsLeapYear(Int32 year);
  public: Boolean IsLeapYear(Int32 year, Int32 era);
  public: Int32 ToFourDigitYear(Int32 year);
  public: static void cctor();
  private: static Array<Int32> s_daysToMonth365;
  private: static Array<Int32> s_daysToMonth366;
};
} // namespace EastAsianLunisolarCalendarNamespace
using EastAsianLunisolarCalendar = EastAsianLunisolarCalendarNamespace::EastAsianLunisolarCalendar;
} // namespace System::Private::CoreLib::System::Globalization
