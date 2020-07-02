#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(DaylightTime)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(DateTime)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(TimeSpan)
namespace CurrentSystemTimeZoneNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(CurrentSystemTimeZone) {
  public: String get_StandardName();
  public: String get_DaylightName();
  public: Int64 GetUtcOffsetFromUniversalTime(DateTime time, Boolean& isAmbiguousLocalDst);
  public: DateTime ToLocalTime(DateTime time);
  public: DaylightTime GetDaylightChanges(Int32 year);
  private: static DaylightTime CreateDaylightChanges(Int32 year);
  public: TimeSpan GetUtcOffset(DateTime time);
  private: DaylightTime GetCachedDaylightChanges(Int32 year);
  private: Int64 m_ticksOffset;
  private: String m_standardName;
  private: String m_daylightName;
  private: Hashtable m_CachedDaylightChanges;
};
} // namespace CurrentSystemTimeZoneNamespace
using CurrentSystemTimeZone = CurrentSystemTimeZoneNamespace::CurrentSystemTimeZone;
} // namespace System::Private::CoreLib::System
