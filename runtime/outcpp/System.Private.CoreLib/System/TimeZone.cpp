#include "TimeZone-dep.h"

#include <System.Private.CoreLib/System/TimeZone-dep.h>

namespace System::Private::CoreLib::System::TimeZoneNamespace {
Object TimeZone___::get_InternalSyncObject() {
  return nullptr;
};

TimeZone TimeZone___::get_CurrentTimeZone() {
  return nullptr;
};

void TimeZone___::Ctor() {
};

void TimeZone___::ResetTimeZone() {
};

DateTime TimeZone___::ToUniversalTime(DateTime time) {
  return DateTime();
};

DateTime TimeZone___::ToLocalTime(DateTime time) {
  return DateTime();
};

Boolean TimeZone___::IsDaylightSavingTime(DateTime time) {
  return Boolean();
};

Boolean TimeZone___::IsDaylightSavingTime(DateTime time, DaylightTime daylightTimes) {
  return Boolean();
};

TimeSpan TimeZone___::CalculateUtcOffset(DateTime time, DaylightTime daylightTimes) {
  return TimeSpan();
};

} // namespace System::Private::CoreLib::System::TimeZoneNamespace
