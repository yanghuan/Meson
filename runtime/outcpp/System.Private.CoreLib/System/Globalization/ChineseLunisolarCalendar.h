#pragma once

#include <System.Private.CoreLib/System/Globalization/EastAsianLunisolarCalendar.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(DateTime)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarId : uint16_t;
FORWARD(EraInfo)
namespace ChineseLunisolarCalendarNamespace {
CLASS(ChineseLunisolarCalendar) : public EastAsianLunisolarCalendar::in {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  protected: Int32 get_DaysInYearBeforeMinSupportedYear();
  public: Int32 get_MinCalendarYear();
  public: Int32 get_MaxCalendarYear();
  public: DateTime get_MinDate();
  public: DateTime get_MaxDate();
  public: Array<EraInfo> get_CalEraInfo();
  public: CalendarId get_ID();
  public: CalendarId get_BaseCalendarID();
  public: Array<Int32> get_Eras();
  public: Int32 GetYearInfo(Int32 lunarYear, Int32 index);
  public: Int32 GetYear(Int32 year, DateTime time);
  public: Int32 GetGregorianYear(Int32 year, Int32 era);
  public: void ctor();
  public: Int32 GetEra(DateTime time);
  public: static void cctor();
  public: static constexpr Int32 ChineseEra = 1;
  private: static DateTime s_minDate;
  private: static DateTime s_maxDate;
  private: static Array<Int32> s_yinfo;
};
} // namespace ChineseLunisolarCalendarNamespace
using ChineseLunisolarCalendar = ChineseLunisolarCalendarNamespace::ChineseLunisolarCalendar;
} // namespace System::Private::CoreLib::System::Globalization
