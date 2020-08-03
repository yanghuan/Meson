#pragma once

#include <System.Private.CoreLib/System/Globalization/Calendar.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(DateTime)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType;
enum class CalendarId : uint16_t;
namespace HebrewCalendarNamespace {
CLASS(HebrewCalendar) : public Calendar::in {
  public: CLASS(DateBuffer) : public Object::in {
    public: void Ctor();
    public: Int32 year;
    public: Int32 month;
    public: Int32 day;
  };
  private: static ReadOnlySpan<Byte> get_HebrewTable();
  private: static ReadOnlySpan<Byte> get_LunarMonthLen();
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  public: CalendarAlgorithmType get_AlgorithmType();
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 get_TwoDigitYearMax();
  public: void set_TwoDigitYearMax(Int32 value);
  public: void Ctor();
  private: static void CheckHebrewYearValue(Int32 y, Int32 era, String varName);
  private: void CheckHebrewMonthValue(Int32 year, Int32 month, Int32 era);
  private: void CheckHebrewDayValue(Int32 year, Int32 month, Int32 day, Int32 era);
  private: static void CheckEraRange(Int32 era);
  private: static void CheckTicksRange(Int64 ticks);
  private: static Int32 GetResult(DateBuffer result, Int32 part);
  public: static Int32 GetLunarMonthDay(Int32 gregorianYear, DateBuffer lunarDate);
  public: Int32 GetDatePart(Int64 ticks, Int32 part);
  public: DateTime AddMonths(DateTime time, Int32 months);
  public: DateTime AddYears(DateTime time, Int32 years);
  public: Int32 GetDayOfMonth(DateTime time);
  public: DayOfWeek GetDayOfWeek(DateTime time);
  public: static Int32 GetHebrewYearType(Int32 year, Int32 era);
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
  private: static Int32 GetDayDifference(Int32 lunarYearType, Int32 month1, Int32 day1, Int32 month2, Int32 day2);
  private: static DateTime HebrewToGregorian(Int32 hebrewYear, Int32 hebrewMonth, Int32 hebrewDay, Int32 hour, Int32 minute, Int32 second, Int32 millisecond);
  public: DateTime ToDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Int32 era);
  public: Int32 ToFourDigitYear(Int32 year);
  private: static void SCtor();
  public: static Int32 HebrewEra;
  private: static DateTime s_calendarMinValue;
  private: static DateTime s_calendarMaxValue;
};
} // namespace HebrewCalendarNamespace
using HebrewCalendar = HebrewCalendarNamespace::HebrewCalendar;
} // namespace System::Private::CoreLib::System::Globalization
