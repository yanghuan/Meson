#include "NameInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/NameInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NameInfoNamespace {
using namespace System::Threading;

void NameInfo___::ReserveEventIDsBelow(Int32 eventId) {
  Int32 num;
  Int32 val;
}

void NameInfo___::ctor(String name, EventTags tags, Int32 typeMetadataSize) {
  this->name = name;
  this->tags = (tags & (EventTags)268435455);
  identity = Interlocked::Increment(lastIdentity);
  Int32 pos = 0;
  Statics::EncodeTags((Int32)this->tags, pos, nullptr);
  nameMetadata = Statics::MetadataForString(name, pos, 0, typeMetadataSize);
  pos = 2;
  Statics::EncodeTags((Int32)this->tags, pos, nameMetadata);
}

Int32 NameInfo___::Compare(NameInfo other) {
  return Compare(other->name, other->tags);
}

Int32 NameInfo___::Compare(KeyValuePair<String, EventTags> key) {
  return Compare(key.get_Key(), key.get_Value() & (EventTags)268435455);
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
