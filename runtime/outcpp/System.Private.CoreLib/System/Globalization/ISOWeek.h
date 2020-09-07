#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARDS(DateTime)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace ISOWeekNamespace {
class ISOWeek {
  public: static Int32 GetWeekOfYear(DateTime date);
  public: static Int32 GetYear(DateTime date);
  public: static DateTime GetYearStart(Int32 year);
  public: static DateTime GetYearEnd(Int32 year);
  public: static Int32 GetWeeksInYear(Int32 year);
  public: static DateTime ToDateTime(Int32 year, Int32 week, DayOfWeek dayOfWeek);
  private: static Int32 GetWeekNumber(DateTime date);
  private: static Int32 GetWeekday(DayOfWeek dayOfWeek);
  public: static Int32 _GetWeeksInYear_g__P8_0(Int32 y);
};
} // namespace ISOWeekNamespace
using ISOWeek = ISOWeekNamespace::ISOWeek;
} // namespace System::Private::CoreLib::System::Globalization
