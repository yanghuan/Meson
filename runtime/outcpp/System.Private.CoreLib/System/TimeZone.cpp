#include "TimeZone-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/CurrentSystemTimeZone-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/TimeZone-dep.h>

namespace System::Private::CoreLib::System::TimeZoneNamespace {
using namespace System::Threading;

Object TimeZone___::get_InternalSyncObject() {
  if (s_InternalSyncObject == nullptr) {
    Object value = rt::newobj<Object>();
    Interlocked::CompareExchange<Object>(s_InternalSyncObject, value, (Object)nullptr);
  }
  return s_InternalSyncObject;
}

TimeZone TimeZone___::get_CurrentTimeZone() {
  TimeZone timeZone = currentTimeZone;
  if (timeZone == nullptr) {
    {
      rt::lock(get_InternalSyncObject());
      if (currentTimeZone == nullptr) {
        currentTimeZone = rt::newobj<CurrentSystemTimeZone>();
      }
      return currentTimeZone;
    }
  }
  return timeZone;
}

void TimeZone___::ctor() {
}

void TimeZone___::ResetTimeZone() {
  if (currentTimeZone != nullptr) {
    {
      rt::lock(get_InternalSyncObject());
      currentTimeZone = nullptr;
    }
  }
}

DateTime TimeZone___::ToUniversalTime(DateTime time) {
  if (time.get_Kind() == DateTimeKind::Utc) {
    return time;
  }
  Int64 num = time.get_Ticks() - GetUtcOffset(time).get_Ticks();
  if (num > 3155378975999999999) {
    return DateTime(3155378975999999999, DateTimeKind::Utc);
  }
  if (num < 0) {
    return DateTime(0, DateTimeKind::Utc);
  }
  return DateTime(num, DateTimeKind::Utc);
}

DateTime TimeZone___::ToLocalTime(DateTime time) {
  if (time.get_Kind() == DateTimeKind::Local) {
    return time;
  }
  Boolean isAmbiguousLocalDst = false;
  Int64 utcOffsetFromUniversalTime = ((CurrentSystemTimeZone)get_CurrentTimeZone())->GetUtcOffsetFromUniversalTime(time, isAmbiguousLocalDst);
  return DateTime(time.get_Ticks() + utcOffsetFromUniversalTime, DateTimeKind::Local, isAmbiguousLocalDst);
}

Boolean TimeZone___::IsDaylightSavingTime(DateTime time) {
  return IsDaylightSavingTime(time, GetDaylightChanges(time.get_Year()));
}

Boolean TimeZone___::IsDaylightSavingTime(DateTime time, DaylightTime daylightTimes) {
  return CalculateUtcOffset(time, daylightTimes) != TimeSpan::Zero;
}

TimeSpan TimeZone___::CalculateUtcOffset(DateTime time, DaylightTime daylightTimes) {
  if (daylightTimes == nullptr) {
    return TimeSpan::Zero;
  }
  DateTimeKind kind = time.get_Kind();
  if (kind == DateTimeKind::Utc) {
    return TimeSpan::Zero;
  }
  DateTime dateTime = daylightTimes->get_Start() + daylightTimes->get_Delta();
  DateTime end = daylightTimes->get_End();
  DateTime t;
  DateTime t2;
  if (daylightTimes->get_Delta().get_Ticks() > 0) {
    t = end - daylightTimes->get_Delta();
    t2 = end;
  } else {
    t = dateTime;
    t2 = dateTime - daylightTimes->get_Delta();
  }
  Boolean flag = false;
  if (dateTime > end) {
    if (time >= dateTime || time < end) {
      flag = true;
    }
  } else if (time >= dateTime && time < end) {
    flag = true;
  }

  if (flag && time >= t && time < t2) {
    flag = time.IsAmbiguousDaylightSavingTime();
  }
  if (flag) {
    return daylightTimes->get_Delta();
  }
  return TimeSpan::Zero;
}

} // namespace System::Private::CoreLib::System::TimeZoneNamespace
