#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(IntPtr)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventTags;
FORWARD(EventProvider)
FORWARD(TraceLoggingEventHandleTable)
FORWARDS(EventDescriptor)
FORWARD(TraceLoggingEventTypes)
namespace NameInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(NameInfo) {
  public: static void ReserveEventIDsBelow(Int32 eventId);
  public: Int32 Compare(NameInfo other);
  public: Int32 Compare(KeyValuePair<String, EventTags> key);
  private: Int32 Compare(String otherName, EventTags otherTags);
  public: IntPtr GetOrCreateEventHandle(EventProvider provider, TraceLoggingEventHandleTable eventHandleTable, EventDescriptor descriptor, TraceLoggingEventTypes eventTypes);
  private: static Int32 lastIdentity;
  public: String name;
  public: EventTags tags;
  public: Int32 identity;
  public: Array<Byte> nameMetadata;
};
} // namespace NameInfoNamespace
using NameInfo = NameInfoNamespace::NameInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
