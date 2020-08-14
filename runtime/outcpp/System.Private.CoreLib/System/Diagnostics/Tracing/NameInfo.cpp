#include "NameInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/NameInfo-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NameInfoNamespace {
void NameInfo___::ReserveEventIDsBelow(Int32 eventId) {
  Int32 num;
  Int32 val;
}

void NameInfo___::ctor(String name, EventTags tags, Int32 typeMetadataSize) {
  this->name = name;
}

Int32 NameInfo___::Compare(NameInfo other) {
  return Compare(other->name, other->tags);
}

Int32 NameInfo___::Compare(KeyValuePair<String, EventTags> key) {
}

Int32 NameInfo___::Compare(String otherName, EventTags otherTags) {
  Int32 num = StringComparer::in::get_Ordinal()->Compare(name, otherName);
  if (num == 0 && tags != otherTags) {
    num = ((tags >= otherTags) ? 1 : (-1));
  }
  return num;
}

IntPtr NameInfo___::GetOrCreateEventHandle(EventProvider provider, TraceLoggingEventHandleTable eventHandleTable, EventDescriptor descriptor, TraceLoggingEventTypes eventTypes) {
  IntPtr result;
  if ((result = eventHandleTable[descriptor.get_EventId()]) == IntPtr::Zero) {
  }
  return result;
}

void NameInfo___::cctor() {
  lastIdentity = 184549376;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::NameInfoNamespace
