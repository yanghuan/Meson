#include "CurrentSystemTimeZone-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/Globalization/DaylightTime-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>

namespace System::Private::CoreLib::System::CurrentSystemTimeZoneNamespace {
using namespace System::Collections;
using namespace System::Globalization;

String CurrentSystemTimeZone___::get_StandardName() {
  return m_standardName;
}

String CurrentSystemTimeZone___::get_DaylightName() {
  return m_daylightName;
}

void CurrentSystemTimeZone___::ctor() {
  m_CachedDaylightChanges = rt::newobj<Hashtable>();
  TimeZone::in::ctor();
  TimeZoneInfo local = TimeZoneInfo::in::get_Local();
  m_ticksOffset = local->get_BaseUtcOffset().get_Ticks();
  m_standardName = local->get_StandardName();
  m_daylightName = local->get_DaylightName();
}

Int64 CurrentSystemTimeZone___::GetUtcOffsetFromUniversalTime(DateTime time, Boolean& isAmbiguousLocalDst) {
  TimeSpan t = TimeSpan(m_ticksOffset);
  DaylightTime daylightChanges = GetDaylightChanges(time.get_Year());
  isAmbiguousLocalDst = false;
  if (daylightChanges == nullptr || daylightChanges->get_Delta().get_Ticks() == 0) {
    return t.get_Ticks();
  }
  DateTime dateTime = daylightChanges->get_Start() - t;
  DateTime dateTime2 = daylightChanges->get_End() - t - daylightChanges->get_Delta();
  DateTime t2;
  DateTime t3;
  if (daylightChanges->get_Delta().get_Ticks() > 0) {
    t2 = dateTime2 - daylightChanges->get_Delta();
    t3 = dateTime2;
  } else {
    t2 = dateTime;
    t3 = dateTime - daylightChanges->get_Delta();
  }
  if ((!(dateTime > dateTime2)) ? (Boolean)(time >= dateTime && time < dateTime2) : (Boolean)(time < dateTime2 || time >= dateTime)) {
    t += daylightChanges->get_Delta();
    if (time >= t2 && time < t3) {
      isAmbiguousLocalDst = true;
    }
  }
  return t.get_Ticks();
}

DateTime CurrentSystemTimeZone___::ToLocalTime(DateTime time) {
  if (time.get_Kind() == DateTimeKind::Local) {
    return time;
  }
  Boolean isAmbiguousLocalDst = false;
  Int64 utcOffsetFromUniversalTime = GetUtcOffsetFromUniversalTime(time, isAmbiguousLocalDst);
  Int64 num = time.get_Ticks() + utcOffsetFromUniversalTime;
  if (num > 3155378975999999999) {
    return DateTime(3155378975999999999, DateTimeKind::Local);
  }
  if (num < 0) {
    return DateTime(0, DateTimeKind::Local);
  }
  return DateTime(num, DateTimeKind::Local, isAmbiguousLocalDst);
}

DaylightTime CurrentSystemTimeZone___::GetDaylightChanges(Int32 year) {
  if (year < 1 || year > 9999) {
    rt::throw_exception<ArgumentOutOfRangeException>("year", SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 9999));
  }
  return GetCachedDaylightChanges(year);
}

DaylightTime CurrentSystemTimeZone___::CreateDaylightChanges(Int32 year) {
  DateTime start = DateTime::MinValue;
  DateTime end = DateTime::MinValue;
  TimeSpan delta = TimeSpan::Zero;
  if (TimeZoneInfo::in::get_Local()->get_SupportsDaylightSavingTime()) {
    Array<TimeZoneInfo::in::AdjustmentRule> adjustmentRules = TimeZoneInfo::in::get_Local()->GetAdjustmentRules();
    for (TimeZoneInfo::in::AdjustmentRule&& adjustmentRule : *adjustmentRules) {
      if (adjustmentRule->get_DateStart().get_Year() <= year && adjustmentRule->get_DateEnd().get_Year() >= year && adjustmentRule->get_DaylightDelta() != TimeSpan::Zero) {
        start = TimeZoneInfo::in::TransitionTimeToDateTime(year, adjustmentRule->get_DaylightTransitionStart());
        end = TimeZoneInfo::in::TransitionTimeToDateTime(year, adjustmentRule->get_DaylightTransitionEnd());
        delta = adjustmentRule->get_DaylightDelta();
        break;
      }
    }
  }
  return rt::newobj<DaylightTime>(start, end, delta);
}

TimeSpan CurrentSystemTimeZone___::GetUtcOffset(DateTime time) {
  if (time.get_Kind() == DateTimeKind::Utc) {
    return TimeSpan::Zero;
  }
  return TimeSpan(TimeZone::in::CalculateUtcOffset(time, GetDaylightChanges(time.get_Year())).get_Ticks() + m_ticksOffset);
}

DaylightTime CurrentSystemTimeZone___::GetCachedDaylightChanges(Int32 year) {
  Object key = year;
  if (!m_CachedDaylightChanges->Contains(key)) {
    DaylightTime value = CreateDaylightChanges(year);
    {
      rt::lock(m_CachedDaylightChanges);
      if (!m_CachedDaylightChanges->Contains(key)) {
        m_CachedDaylightChanges->Add(key, value);
      }
    }
  }
  return (DaylightTime)m_CachedDaylightChanges[key];
}

} // namespace System::Private::CoreLib::System::CurrentSystemTimeZoneNamespace
