#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(DateTime)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(EraInfo)
enum class CalendarId : uint16_t;
FORWARD(GregorianCalendarHelper)
namespace TaiwanLunisolarCalendarNamespace {
CLASS(TaiwanLunisolarCalendar) {
  public: DateTime get_MinSupportedDateTime();
  public: DateTime get_MaxSupportedDateTime();
  protected: Int32 get_DaysInYearBeforeMinSupportedYear();
  public: Int32 get_MinCalendarYear();
  public: Int32 get_MaxCalendarYear();
  public: DateTime get_MinDate();
  public: DateTime get_MaxDate();
  public: Array<EraInfo> get_CalEraInfo();
  public: CalendarId get_BaseCalendarID();
  public: CalendarId get_ID();
  public: Array<Int32> get_Eras();
  public: Int32 GetYearInfo(Int32 lunarYear, Int32 index);
  public: Int32 GetYear(Int32 year, DateTime time);
  public: Int32 GetGregorianYear(Int32 year, Int32 era);
  public: Int32 GetEra(DateTime time);
  private: static Array<EraInfo> s_taiwanLunisolarEraInfo;
  private: GregorianCalendarHelper _helper;
  private: static DateTime s_minDate;
  private: static DateTime s_maxDate;
  private: static Array<Int32> s_yinfo;
};
} // namespace TaiwanLunisolarCalendarNamespace
using TaiwanLunisolarCalendar = TaiwanLunisolarCalendarNamespace::TaiwanLunisolarCalendar;
} // namespace System::Private::CoreLib::System::Globalization
