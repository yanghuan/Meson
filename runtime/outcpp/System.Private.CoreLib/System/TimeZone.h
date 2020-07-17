#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(DaylightTime)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARDS(TimeSpan)
namespace TimeZoneNamespace {
using namespace Globalization;
CLASS(TimeZone) {
  private: static Object get_InternalSyncObject();
  public: static TimeZone get_CurrentTimeZone();
  public: String get_StandardName();
  public: String get_DaylightName();
  protected: void Ctor();
  public: static void ResetTimeZone();
  public: TimeSpan GetUtcOffset(DateTime time);
  public: DateTime ToUniversalTime(DateTime time);
  public: DateTime ToLocalTime(DateTime time);
  public: DaylightTime GetDaylightChanges(Int32 year);
  public: Boolean IsDaylightSavingTime(DateTime time);
  public: static Boolean IsDaylightSavingTime(DateTime time, DaylightTime daylightTimes);
  public: static TimeSpan CalculateUtcOffset(DateTime time, DaylightTime daylightTimes);
  private: static TimeZone currentTimeZone;
  private: static Object s_InternalSyncObject;
};
} // namespace TimeZoneNamespace
using TimeZone = TimeZoneNamespace::TimeZone;
} // namespace System::Private::CoreLib::System
