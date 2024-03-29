#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ConcurrentSetItem.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventTags : int32_t;
FORWARDS(EventDescriptor)
FORWARD(EventProvider)
FORWARD(TraceLoggingEventHandleTable)
FORWARD(TraceLoggingEventTypes)
namespace NameInfoNamespace {
using namespace System::Collections::Generic;
CLASS(NameInfo) : public ConcurrentSetItem<KeyValuePair<String, EventTags>, NameInfo>::in {
  public: static void ReserveEventIDsBelow(Int32 eventId);
  public: void ctor(String name, EventTags tags, Int32 typeMetadataSize);
  public: Int32 Compare(NameInfo other);
  public: Int32 Compare(KeyValuePair<String, EventTags> key);
  private: Int32 Compare(String otherName, EventTags otherTags);
  public: IntPtr GetOrCreateEventHandle(EventProvider provider, TraceLoggingEventHandleTable eventHandleTable, EventDescriptor descriptor, TraceLoggingEventTypes eventTypes);
  public: static void cctor();
  private: static Int32 lastIdentity;
  public: String name;
  public: EventTags tags;
  public: Int32 identity;
  public: Array<Byte> nameMetadata;
};
} // namespace NameInfoNamespace
using NameInfo = NameInfoNamespace::NameInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
