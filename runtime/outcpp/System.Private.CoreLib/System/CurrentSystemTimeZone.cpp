#include "CurrentSystemTimeZone-dep.h"

namespace System::Private::CoreLib::System::CurrentSystemTimeZoneNamespace {
String CurrentSystemTimeZone___::get_StandardName() {
  return nullptr;
}

String CurrentSystemTimeZone___::get_DaylightName() {
  return nullptr;
}

void CurrentSystemTimeZone___::Ctor() {
}

Int64 CurrentSystemTimeZone___::GetUtcOffsetFromUniversalTime(DateTime time, Boolean& isAmbiguousLocalDst) {
  return Int64();
}

DateTime CurrentSystemTimeZone___::ToLocalTime(DateTime time) {
  return DateTime();
}

DaylightTime CurrentSystemTimeZone___::GetDaylightChanges(Int32 year) {
  return nullptr;
}

DaylightTime CurrentSystemTimeZone___::CreateDaylightChanges(Int32 year) {
  return nullptr;
}

TimeSpan CurrentSystemTimeZone___::GetUtcOffset(DateTime time) {
  return TimeSpan();
}

DaylightTime CurrentSystemTimeZone___::GetCachedDaylightChanges(Int32 year) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::CurrentSystemTimeZoneNamespace
