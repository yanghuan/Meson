#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek;
FORWARDS(DateTime)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace ISOWeekNamespace {
class ISOWeek : public Object::in {
  public: static Int32 GetWeekOfYear(DateTime date);
  public: static Int32 GetYear(DateTime date);
  public: static DateTime GetYearStart(Int32 year);
  public: static DateTime GetYearEnd(Int32 year);
  public: static Int32 GetWeeksInYear(Int32 year);
  public: static DateTime ToDateTime(Int32 year, Int32 week, DayOfWeek dayOfWeek);
  private: static Int32 GetWeekNumber(DateTime date);
  private: static Int32 GetWeekday(DayOfWeek dayOfWeek);
};
} // namespace ISOWeekNamespace
using ISOWeek = ISOWeekNamespace::ISOWeek;
} // namespace System::Private::CoreLib::System::Globalization
