#include "EventSource-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/Microsoft/Reflection/ReflectionExtensions-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IList.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Collections/ObjectModel/ReadOnlyCollection-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ActivityTracker-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DataCollector-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EmptyStruct-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventChannel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventManifestOptions.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventOpcode.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeInternal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeMetadataGenerator-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceOptions-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventTask.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventWrittenEventArgs-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ManifestBuilder-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ManifestEnvelope-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NameInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/SimpleEventTypes-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingEventHandleTable-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceNamespace {
using namespace Microsoft::Reflection;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

IntPtr EventSource___::EventData::get_DataPointer() {
  return (IntPtr)(void*)m_Ptr;
}

void EventSource___::EventData::set_DataPointer(IntPtr value) {
  m_Ptr = (UInt64)(void*)value;
}

Int32 EventSource___::EventData::get_Size() {
  return m_Size;
}

void EventSource___::EventData::set_Size(Int32 value) {
  m_Size = value;
}

void EventSource___::EventData::set_Reserved(Int32 value) {
  m_Reserved = value;
}

void EventSource___::EventData::SetMetadata(Byte* pointer, Int32 size, Int32 reserved) {
  m_Ptr = (UInt64)pointer;
  m_Size = size;
  m_Reserved = reserved;
}

void EventSource___::Sha1ForNonSecretPurposes::Start() {
  if (w == nullptr) {
    w = rt::newarr<Array<UInt32>>(85);
  }
  length = 0;
  pos = 0;
  w[80] = 1732584193u;
  w[81] = 4023233417u;
  w[82] = 2562383102u;
  w[83] = 271733878u;
  w[84] = 3285377520u;
}

void EventSource___::Sha1ForNonSecretPurposes::Append(Byte input) {
}

void EventSource___::Sha1ForNonSecretPurposes::Append(ReadOnlySpan<Byte> input) {
  ReadOnlySpan<Byte> readOnlySpan = input;
}

void EventSource___::Sha1ForNonSecretPurposes::Finish(Array<Byte> output) {
  Int64 num = length + 8 * pos;
  Append(128);
  while (pos != 56) {
    Append(0);
  }
  Append((Byte)(num >> 56));
  Append((Byte)(num >> 48));
  Append((Byte)(num >> 40));
  Append((Byte)(num >> 32));
  Append((Byte)(num >> 24));
  Append((Byte)(num >> 16));
  Append((Byte)(num >> 8));
  Append((Byte)num);
  Int32 num2 = (output->get_Length() < 20) ? output->get_Length() : 20;
  for (Int32 i = 0; i != num2; i++) {
    UInt32 num3 = w[80 + i / 4];
    output[i] = (Byte)(num3 >> 24);
    w[80 + i / 4] = num3 << 8;
  }
}

void EventSource___::Sha1ForNonSecretPurposes::Drain() {
  for (Int32 i = 16; i != 80; i++) {
  }
  UInt32 num = w[80];
  UInt32 num2 = w[81];
  UInt32 num3 = w[82];
  UInt32 num4 = w[83];
  UInt32 num5 = w[84];
  for (Int32 j = 0; j != 20; j++) {
  }
  for (Int32 k = 20; k != 40; k++) {
  }
  for (Int32 l = 40; l != 60; l++) {
  }
  for (Int32 m = 60; m != 80; m++) {
  }
  w[80] += num;
  w[81] += num2;
  w[82] += num3;
  w[83] += num4;
  w[84] += num5;
  length += 512;
  pos = 0;
}

void EventSource___::OverideEventProvider___::ctor(EventSource eventSource, EventProviderType providerType) {
  m_eventSource = eventSource;
  m_eventProviderType = providerType;
}

void EventSource___::OverideEventProvider___::OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 perEventSourceSessionId, Int32 etwSessionId) {
  EventListener listener = nullptr;
}

String EventSource___::get_Name() {
  return m_name;
}

Guid EventSource___::get_Guid() {
  return m_guid;
}

EventSourceSettings EventSource___::get_Settings() {
  return m_config;
}

Exception EventSource___::get_ConstructionException() {
  return m_constructionException;
}

Guid EventSource___::get_CurrentThreadActivityId() {
  Guid ActivityId = Guid();
  Interop::Advapi32::EventActivityIdControl(Interop::Advapi32::ActivityControl::EVENT_ACTIVITY_CTRL_GET_ID, ActivityId);
  return ActivityId;
}

Boolean EventSource___::get_IsDisposed() {
  return m_eventSourceDisposed;
}

Boolean EventSource___::get_ThrowOnEventWriteErrors() {
}

Boolean EventSource___::get_SelfDescribingEvents() {
}

Boolean EventSource___::IsEnabled() {
  return m_eventSourceEnabled;
}

Boolean EventSource___::IsEnabled(EventLevel level, EventKeywords keywords) {
  return IsEnabled(level, keywords, EventChannel::None);
}

Boolean EventSource___::IsEnabled(EventLevel level, EventKeywords keywords, EventChannel channel) {
  if (!m_eventSourceEnabled) {
    return false;
  }
  if (!IsEnabledCommon(m_eventSourceEnabled, m_level, m_matchAnyKeyword, level, keywords, channel)) {
    return false;
  }
  return true;
}

Guid EventSource___::GetGuid(Type eventSourceType) {
  if (eventSourceType == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSourceType");
  }
}

String EventSource___::GetName(Type eventSourceType) {
  return GetName(eventSourceType, EventManifestOptions::None);
}

String EventSource___::GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest) {
  return GenerateManifest(eventSourceType, assemblyPathToIncludeInManifest, EventManifestOptions::None);
}

String EventSource___::GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest, EventManifestOptions flags) {
  if (eventSourceType == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSourceType");
  }
  Array<Byte> array = CreateManifestAndDescriptors(eventSourceType, assemblyPathToIncludeInManifest, nullptr, flags);
  if (array != nullptr) {
    return Encoding::in::get_UTF8()->GetString(array, 0, array->get_Length());
  }
  return nullptr;
}

IEnumerable<EventSource> EventSource___::GetSources() {
  List<EventSource> list = rt::newobj<List<EventSource>>();
}

void EventSource___::SendCommand(EventSource eventSource, EventCommand command, IDictionary<String, String> commandArguments) {
  if (eventSource == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSource");
  }
  if (command <= EventCommand::Update && command != EventCommand::SendManifest) {
    rt::throw_exception<ArgumentException>(SR::get_EventSource_InvalidCommand(), "command");
  }
  eventSource->SendCommand(nullptr, EventProviderType::ETW, 0, 0, command, true, EventLevel::LogAlways, EventKeywords::None, commandArguments);
}

String EventSource___::GetTrait(String key) {
  if (m_traits != nullptr) {
    for (Int32 i = 0; i < m_traits->get_Length() - 1; i += 2) {
      if (m_traits[i] == key) {
        return m_traits[i + 1];
      }
    }
  }
  return nullptr;
}

String EventSource___::ToString() {
  return SR::Format(SR::get_EventSource_ToString(), get_Name(), get_Guid());
}

void EventSource___::SetCurrentThreadActivityId(Guid activityId) {
  if (TplEventSource::in::Log != nullptr) {
    TplEventSource::in::Log->SetActivityId(activityId);
  }
  EventPipeInternal::EventActivityIdControl(2u, activityId);
  Interop::Advapi32::EventActivityIdControl(Interop::Advapi32::ActivityControl::EVENT_ACTIVITY_CTRL_SET_ID, activityId);
}

void EventSource___::SetCurrentThreadActivityId(Guid activityId, Guid& oldActivityThatWillContinue) {
  oldActivityThatWillContinue = activityId;
  EventPipeInternal::EventActivityIdControl(2u, oldActivityThatWillContinue);
  Interop::Advapi32::EventActivityIdControl(Interop::Advapi32::ActivityControl::EVENT_ACTIVITY_CTRL_GET_SET_ID, oldActivityThatWillContinue);
  if (TplEventSource::in::Log != nullptr) {
    TplEventSource::in::Log->SetActivityId(activityId);
  }
}

void EventSource___::ctor() {
}

void EventSource___::ctor(Boolean throwOnEventWriteErrors) {
}

void EventSource___::ctor(EventSourceSettings settings) {
}

void EventSource___::ctor(EventSourceSettings settings, Array<String> traits) {
  m_createEventLock = rt::newobj<Object>();
  m_writeEventStringEventHandle = IntPtr::Zero;
  m_eventHandleTable = rt::newobj<TraceLoggingEventHandleTable>();
}

void EventSource___::DefineEventPipeEvents() {
  if (get_SelfDescribingEvents()) {
    return;
  }
  Int32 num = m_eventData->get_Length();
  for (Int32 i = 0; i < num; i++) {
    UInt32 eventId = (UInt32)m_eventData[i].Descriptor.get_EventId();
    if (eventId != 0) {
      Array<Byte> array = EventPipeMetadataGenerator::in::Instance->GenerateEventMetadata(m_eventData[i]);
      UInt32 metadataLength = (UInt32)((array != nullptr) ? array->get_Length() : 0);
      String name = m_eventData[i].Name;
      Int64 keywords = m_eventData[i].Descriptor.get_Keywords();
      UInt32 version = m_eventData[i].Descriptor.get_Version();
      UInt32 level = m_eventData[i].Descriptor.get_Level();
      {
        Byte* pMetadata = array;
        IntPtr eventHandle = m_eventPipeProvider->m_eventProvider->DefineEventHandle(eventId, name, keywords, version, level, pMetadata, metadataLength);
        m_eventData[i].EventHandle = eventHandle;
      }
    }
  }
}

void EventSource___::GetMetadata(Guid& eventSourceGuid, String& eventSourceName, Array<EventMetadata>& eventData, Array<Byte>& manifestBytes) {
  eventSourceGuid = Guid::Empty;
  eventSourceName = nullptr;
  eventData = nullptr;
  manifestBytes = nullptr;
}

void EventSource___::OnEventCommand(EventCommandEventArgs command) {
}

void EventSource___::WriteEvent(Int32 eventId) {
  WriteEventCore(eventId, 0, nullptr);
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1) {
  if (m_eventSourceEnabled) {
    EventData default[1] = {};
    EventData* ptr = default;
    ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
    ptr->set_Size = 4;
    ptr->set_Reserved = 0;
    WriteEventCore(eventId, 1, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2) {
  if (m_eventSourceEnabled) {
    EventData default[2] = {};
    EventData* ptr = default;
    ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
    ptr->set_Size = 4;
    ptr->set_Reserved = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)(&arg2);
    ptr[1].set_Size = 4;
    ptr[1].set_Reserved = 0;
    WriteEventCore(eventId, 2, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2, Int32 arg3) {
  if (m_eventSourceEnabled) {
    EventData default[3] = {};
    EventData* ptr = default;
    ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
    ptr->set_Size = 4;
    ptr->set_Reserved = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)(&arg2);
    ptr[1].set_Size = 4;
    ptr[1].set_Reserved = 0;
    ptr[2].set_DataPointer = (IntPtr)(void*)(&arg3);
    ptr[2].set_Size = 4;
    ptr[2].set_Reserved = 0;
    WriteEventCore(eventId, 3, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1) {
  if (m_eventSourceEnabled) {
    EventData default[1] = {};
    EventData* ptr = default;
    ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
    ptr->set_Size = 8;
    ptr->set_Reserved = 0;
    WriteEventCore(eventId, 1, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2) {
  if (m_eventSourceEnabled) {
    EventData default[2] = {};
    EventData* ptr = default;
    ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
    ptr->set_Size = 8;
    ptr->set_Reserved = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)(&arg2);
    ptr[1].set_Size = 8;
    ptr[1].set_Reserved = 0;
    WriteEventCore(eventId, 2, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2, Int64 arg3) {
  if (m_eventSourceEnabled) {
    EventData default[3] = {};
    EventData* ptr = default;
    ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
    ptr->set_Size = 8;
    ptr->set_Reserved = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)(&arg2);
    ptr[1].set_Size = 8;
    ptr[1].set_Reserved = 0;
    ptr[2].set_DataPointer = (IntPtr)(void*)(&arg3);
    ptr[2].set_Size = 8;
    ptr[2].set_Reserved = 0;
    WriteEventCore(eventId, 3, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1) {
  if (m_eventSourceEnabled) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData default[1] = {};
      EventData* ptr2 = default;
      ptr2->set_DataPointer = (IntPtr)(void*)value;
      ptr2->set_Size = (arg1->get_Length() + 1) * 2;
      ptr2->set_Reserved = 0;
      WriteEventCore(eventId, 1, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, String arg2) {
  if (!m_eventSourceEnabled) {
    return;
  }
  if (arg1 == nullptr) {
    arg1 = "";
  }
  if (arg2 == nullptr) {
    arg2 = "";
  }
  {
    Char* ptr = arg1;
    Char* value = ptr;
    {
      Char* ptr2 = arg2;
      Char* value2 = ptr2;
      EventData default[2] = {};
      EventData* ptr3 = default;
      ptr3->set_DataPointer = (IntPtr)(void*)value;
      ptr3->set_Size = (arg1->get_Length() + 1) * 2;
      ptr3->set_Reserved = 0;
      ptr3[1].set_DataPointer = (IntPtr)(void*)value2;
      ptr3[1].set_Size = (arg2->get_Length() + 1) * 2;
      ptr3[1].set_Reserved = 0;
      WriteEventCore(eventId, 2, ptr3);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, String arg2, String arg3) {
  if (!m_eventSourceEnabled) {
    return;
  }
  if (arg1 == nullptr) {
    arg1 = "";
  }
  if (arg2 == nullptr) {
    arg2 = "";
  }
  if (arg3 == nullptr) {
    arg3 = "";
  }
  {
    Char* ptr = arg1;
    Char* value = ptr;
    {
      Char* ptr2 = arg2;
      Char* value2 = ptr2;
      {
        Char* ptr3 = arg3;
        Char* value3 = ptr3;
        EventData default[3] = {};
        EventData* ptr4 = default;
        ptr4->set_DataPointer = (IntPtr)(void*)value;
        ptr4->set_Size = (arg1->get_Length() + 1) * 2;
        ptr4->set_Reserved = 0;
        ptr4[1].set_DataPointer = (IntPtr)(void*)value2;
        ptr4[1].set_Size = (arg2->get_Length() + 1) * 2;
        ptr4[1].set_Reserved = 0;
        ptr4[2].set_DataPointer = (IntPtr)(void*)value3;
        ptr4[2].set_Size = (arg3->get_Length() + 1) * 2;
        ptr4[2].set_Reserved = 0;
        WriteEventCore(eventId, 3, ptr4);
      }
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, Int32 arg2) {
  if (m_eventSourceEnabled) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData default[2] = {};
      EventData* ptr2 = default;
      ptr2->set_DataPointer = (IntPtr)(void*)value;
      ptr2->set_Size = (arg1->get_Length() + 1) * 2;
      ptr2->set_Reserved = 0;
      ptr2[1].set_DataPointer = (IntPtr)(void*)(&arg2);
      ptr2[1].set_Size = 4;
      ptr2[1].set_Reserved = 0;
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, Int32 arg2, Int32 arg3) {
  if (m_eventSourceEnabled) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData default[3] = {};
      EventData* ptr2 = default;
      ptr2->set_DataPointer = (IntPtr)(void*)value;
      ptr2->set_Size = (arg1->get_Length() + 1) * 2;
      ptr2->set_Reserved = 0;
      ptr2[1].set_DataPointer = (IntPtr)(void*)(&arg2);
      ptr2[1].set_Size = 4;
      ptr2[1].set_Reserved = 0;
      ptr2[2].set_DataPointer = (IntPtr)(void*)(&arg3);
      ptr2[2].set_Size = 4;
      ptr2[2].set_Reserved = 0;
      WriteEventCore(eventId, 3, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, Int64 arg2) {
  if (m_eventSourceEnabled) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData default[2] = {};
      EventData* ptr2 = default;
      ptr2->set_DataPointer = (IntPtr)(void*)value;
      ptr2->set_Size = (arg1->get_Length() + 1) * 2;
      ptr2->set_Reserved = 0;
      ptr2[1].set_DataPointer = (IntPtr)(void*)(&arg2);
      ptr2[1].set_Size = 8;
      ptr2[1].set_Reserved = 0;
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, String arg2) {
  if (m_eventSourceEnabled) {
    if (arg2 == nullptr) {
      arg2 = "";
    }
    {
      Char* ptr = arg2;
      Char* value = ptr;
      EventData default[2] = {};
      EventData* ptr2 = default;
      ptr2->set_DataPointer = (IntPtr)(void*)(&arg1);
      ptr2->set_Size = 8;
      ptr2->set_Reserved = 0;
      ptr2[1].set_DataPointer = (IntPtr)(void*)value;
      ptr2[1].set_Size = (arg2->get_Length() + 1) * 2;
      ptr2[1].set_Reserved = 0;
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, String arg2) {
  if (m_eventSourceEnabled) {
    if (arg2 == nullptr) {
      arg2 = "";
    }
    {
      Char* ptr = arg2;
      Char* value = ptr;
      EventData default[2] = {};
      EventData* ptr2 = default;
      ptr2->set_DataPointer = (IntPtr)(void*)(&arg1);
      ptr2->set_Size = 4;
      ptr2->set_Reserved = 0;
      ptr2[1].set_DataPointer = (IntPtr)(void*)value;
      ptr2[1].set_Size = (arg2->get_Length() + 1) * 2;
      ptr2[1].set_Reserved = 0;
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, Array<Byte> arg1) {
  if (!m_eventSourceEnabled) {
    return;
  }
  EventData default[2] = {};
  EventData* ptr = default;
  if (arg1 == nullptr || arg1->get_Length() == 0) {
    Int32 num = 0;
    ptr->set_DataPointer = (IntPtr)(void*)(&num);
    ptr->set_Size = 4;
    ptr->set_Reserved = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)(&num);
    ptr[1].set_Size = 0;
    ptr[1].set_Reserved = 0;
    WriteEventCore(eventId, 2, ptr);
    return;
  }
  Int32 size = arg1->get_Length();
  {
    Byte* value = &arg1[0];
    ptr->set_DataPointer = (IntPtr)(void*)(&size);
    ptr->set_Size = 4;
    ptr->set_Reserved = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)value;
    ptr[1].set_Size = size;
    ptr[1].set_Reserved = 0;
    WriteEventCore(eventId, 2, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Array<Byte> arg2) {
  if (!m_eventSourceEnabled) {
    return;
  }
  EventData default[3] = {};
  EventData* ptr = default;
  ptr->set_DataPointer = (IntPtr)(void*)(&arg1);
  ptr->set_Size = 8;
  ptr->set_Reserved = 0;
  if (arg2 == nullptr || arg2->get_Length() == 0) {
    Int32 num = 0;
    ptr[1].set_DataPointer = (IntPtr)(void*)(&num);
    ptr[1].set_Size = 4;
    ptr[1].set_Reserved = 0;
    ptr[2].set_DataPointer = (IntPtr)(void*)(&num);
    ptr[2].set_Size = 0;
    ptr[2].set_Reserved = 0;
    WriteEventCore(eventId, 3, ptr);
    return;
  }
  Int32 size = arg2->get_Length();
  {
    Byte* value = &arg2[0];
    ptr[1].set_DataPointer = (IntPtr)(void*)(&size);
    ptr[1].set_Size = 4;
    ptr[1].set_Reserved = 0;
    ptr[2].set_DataPointer = (IntPtr)(void*)value;
    ptr[2].set_Size = size;
    ptr[2].set_Reserved = 0;
    WriteEventCore(eventId, 3, ptr);
  }
}

void EventSource___::WriteEventCore(Int32 eventId, Int32 eventDataCount, EventData* data) {
  WriteEventWithRelatedActivityIdCore(eventId, nullptr, eventDataCount, data);
}

void EventSource___::WriteEventWithRelatedActivityIdCore(Int32 eventId, Guid* relatedActivityId, Int32 eventDataCount, EventData* data) {
  if (!m_eventSourceEnabled) {
    return;
  }
  try{
    if (relatedActivityId != nullptr) {
      ValidateEventOpcodeForTransfer(m_eventData[eventId], m_eventData[eventId].Name);
    }
    EventOpcode opcode = (EventOpcode)m_eventData[eventId].Descriptor.get_Opcode();
    EventActivityOptions activityOptions = m_eventData[eventId].ActivityOptions;
    Guid* activityID = nullptr;
    Guid activityId = Guid::Empty;
    Guid relatedActivityId2 = Guid::Empty;
  } catch (Exception ex) {
  }
}

void EventSource___::WriteEvent(Int32 eventId, Array<Object> args) {
  WriteEventVarargs(eventId, nullptr, args);
}

void EventSource___::WriteEventWithRelatedActivityId(Int32 eventId, Guid relatedActivityId, Array<Object> args) {
  WriteEventVarargs(eventId, &relatedActivityId, args);
}

void EventSource___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((EventSource)this);
}

void EventSource___::Dispose(Boolean disposing) {
  if (disposing) {
    if (m_eventSourceEnabled) {
      try{
        SendManifest(m_rawManifest);
      } catch (...) {
      }
      m_eventSourceEnabled = false;
    }
    if (m_etwProvider != nullptr) {
      m_etwProvider->Dispose();
      m_etwProvider = nullptr;
    }
    if (m_eventPipeProvider != nullptr) {
      m_eventPipeProvider->Dispose();
      m_eventPipeProvider = nullptr;
    }
  }
  m_eventSourceEnabled = false;
  m_eventSourceDisposed = true;
}

void EventSource___::Finalize() {
  Dispose(false);
}

void EventSource___::WriteEventRaw(String eventName, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data) {
  Boolean flag = true;
  flag &= (m_etwProvider == nullptr);
  if (m_etwProvider != nullptr && !m_etwProvider->WriteEventRaw(eventDescriptor, eventHandle, activityID, relatedActivityID, dataCount, data)) {
    ThrowEventSourceException(eventName);
  }
  flag &= (m_eventPipeProvider == nullptr);
  if (m_eventPipeProvider != nullptr && !m_eventPipeProvider->WriteEventRaw(eventDescriptor, eventHandle, activityID, relatedActivityID, dataCount, data)) {
    ThrowEventSourceException(eventName);
  }
  if (flag) {
    ThrowEventSourceException(eventName);
  }
}

void EventSource___::ctor(Guid eventSourceGuid, String eventSourceName) {
}

void EventSource___::ctor(Guid eventSourceGuid, String eventSourceName, EventSourceSettings settings, Array<String> traits) {
  m_createEventLock = rt::newobj<Object>();
  m_writeEventStringEventHandle = IntPtr::Zero;
  m_eventHandleTable = rt::newobj<TraceLoggingEventHandleTable>();
}

void EventSource___::Initialize(Guid eventSourceGuid, String eventSourceName, Array<String> traits) {
  try{
    m_traits = traits;
    if (m_traits != nullptr && m_traits->get_Length() % 2 != 0) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_TraitEven(), "traits");
    }
    if (eventSourceGuid == Guid::Empty) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_NeedGuid());
    }
    if (eventSourceName == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_NeedName());
    }
    m_name = eventSourceName;
    m_guid = eventSourceGuid;
    m_activityTracker = ActivityTracker::in::get_Instance();
    InitializeProviderMetadata();
    OverideEventProvider overideEventProvider = rt::newobj<OverideEventProvider>((EventSource)this, EventProviderType::ETW);
    overideEventProvider->Register((EventSource)this);
    OverideEventProvider overideEventProvider2 = rt::newobj<OverideEventProvider>((EventSource)this, EventProviderType::EventPipe);
  } catch (Exception ex) {
  }
}

String EventSource___::GetName(Type eventSourceType, EventManifestOptions flags) {
  if (eventSourceType == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSourceType");
  }
}

Guid EventSource___::GenerateGuidFromName(String name) {
  ReadOnlySpan<Byte> input = rt::newarr<Array<Byte>>(16);
  Array<Byte> array = Encoding::in::get_BigEndianUnicode()->GetBytes(name);
  Sha1ForNonSecretPurposes sha1ForNonSecretPurposes = Sha1ForNonSecretPurposes();
  sha1ForNonSecretPurposes.Start();
  sha1ForNonSecretPurposes.Append(input);
  sha1ForNonSecretPurposes.Append(array);
  Array<>::in::Resize(array, 16);
  sha1ForNonSecretPurposes.Finish(array);
}

Object EventSource___::DecodeObject(Int32 eventId, Int32 parameterId, EventData*& data) {
  IntPtr dataPointer = data->get_DataPointer();
  data++;
  Type type = GetDataType(m_eventData[eventId], parameterId);
  while (true) {
  }
  return nullptr;
}

EventDispatcher EventSource___::GetDispatcher(EventListener listener) {
  EventDispatcher eventDispatcher;
  for (eventDispatcher = m_Dispatchers; eventDispatcher != nullptr; eventDispatcher = eventDispatcher->m_Next) {
    if (eventDispatcher->m_Listener == listener) {
      return eventDispatcher;
    }
  }
  return eventDispatcher;
}

void EventSource___::WriteEventVarargs(Int32 eventId, Guid* childActivityID, Array<Object> args) {
  if (!m_eventSourceEnabled) {
    return;
  }
  try{
    if (childActivityID != nullptr) {
      ValidateEventOpcodeForTransfer(m_eventData[eventId], m_eventData[eventId].Name);
      if (!m_eventData[eventId].HasRelatedActivityID) {
        rt::throw_exception<ArgumentException>(SR::get_EventSource_NoRelatedActivityId());
      }
    }
    LogEventArgsMismatches(eventId, args);
    Guid* activityID = nullptr;
    Guid activityId = Guid::Empty;
    Guid relatedActivityId = Guid::Empty;
    EventOpcode opcode = (EventOpcode)m_eventData[eventId].Descriptor.get_Opcode();
    EventActivityOptions activityOptions = m_eventData[eventId].ActivityOptions;
  } catch (Exception ex) {
  }
}

Array<Object> EventSource___::SerializeEventArgs(Int32 eventId, Array<Object> args) {
  TraceLoggingEventTypes traceLoggingEventTypes = m_eventData[eventId].TraceLoggingEventTypes;
  if (traceLoggingEventTypes == nullptr) {
    traceLoggingEventTypes = rt::newobj<TraceLoggingEventTypes>(m_eventData[eventId].Name, EventTags::None, m_eventData[eventId].Parameters);
    Interlocked::CompareExchange(m_eventData[eventId].TraceLoggingEventTypes, traceLoggingEventTypes, nullptr);
  }
  Int32 num = Math::Min(traceLoggingEventTypes->typeInfos->get_Length(), args->get_Length());
  Array<Object> array = rt::newarr<Array<Object>>(traceLoggingEventTypes->typeInfos->get_Length());
  for (Int32 i = 0; i < num; i++) {
    array[i] = traceLoggingEventTypes->typeInfos[i]->GetData(args[i]);
  }
  return array;
}

void EventSource___::LogEventArgsMismatches(Int32 eventId, Array<Object> args) {
  Array<ParameterInfo> parameters = m_eventData[eventId].Parameters;
  if (args->get_Length() != parameters->get_Length()) {
    ReportOutOfBandMessage(SR::Format(SR::get_EventSource_EventParametersMismatch(), eventId, args->get_Length(), parameters->get_Length()));
    return;
  }
  for (Int32 i = 0; i < args->get_Length(); i++) {
    Type parameterType = parameters[i]->get_ParameterType();
    Object obj = args[i];
  }
}

void EventSource___::WriteToAllListeners(Int32 eventId, Guid* activityID, Guid* childActivityID, Int32 eventDataCount, EventData* data) {
  Int32 num = GetParameterCount(m_eventData[eventId]);
  Int32 num2 = 0;
  for (Int32 i = 0; i < num; i++) {
    Type dataType = GetDataType(m_eventData[eventId], i);
  }
  if (eventDataCount != num2) {
    ReportOutOfBandMessage(SR::Format(SR::get_EventSource_EventParametersMismatch(), eventId, eventDataCount, num));
    num = Math::Min(num, eventDataCount);
  }
  Array<Object> array = rt::newarr<Array<Object>>(num);
  EventData* data2 = data;
  for (Int32 j = 0; j < num; j++) {
    array[j] = DecodeObject(eventId, j, data2);
  }
  WriteToAllListeners(eventId, nullptr, nullptr, activityID, childActivityID, rt::newarr<Array<Object>>(1, array));
}

void EventSource___::WriteToAllListeners(Int32 eventId, UInt32* osThreadId, DateTime* timeStamp, Guid* activityID, Guid* childActivityID, Array<Object> args) {
  EventWrittenEventArgs eventWrittenEventArgs = rt::newobj<EventWrittenEventArgs>((EventSource)this);
  eventWrittenEventArgs->set_EventId = eventId;
  if (osThreadId != nullptr) {
    eventWrittenEventArgs->set_OSThreadId = (Int32)(*osThreadId);
  }
  if (timeStamp != nullptr) {
    eventWrittenEventArgs->set_TimeStamp = *timeStamp;
  }
  if (activityID != nullptr) {
    eventWrittenEventArgs->set_ActivityId = *activityID;
  }
  if (childActivityID != nullptr) {
    eventWrittenEventArgs->set_RelatedActivityId = *childActivityID;
  }
  eventWrittenEventArgs->set_EventName = m_eventData[eventId].Name;
  eventWrittenEventArgs->set_Message = m_eventData[eventId].Message;
  eventWrittenEventArgs->set_Payload = rt::newobj<ReadOnlyCollection<Object>>(args);
  DispatchToAllListeners(eventId, eventWrittenEventArgs);
}

void EventSource___::DispatchToAllListeners(Int32 eventId, EventWrittenEventArgs eventCallbackArgs) {
  Exception ex = nullptr;
  for (EventDispatcher eventDispatcher = m_Dispatchers; eventDispatcher != nullptr; eventDispatcher = eventDispatcher->m_Next) {
    if (eventId == -1 || eventDispatcher->m_EventEnabled[eventId]) {
      try{
        eventDispatcher->m_Listener->OnEventWritten(eventCallbackArgs);
      } catch (Exception ex2) {
      }
    }
  }
  if (ex != nullptr) {
    rt::throw_exception<EventSourceException>(ex);
  }
}

void EventSource___::WriteEventString(String msgString) {
  Boolean flag = true;
  flag &= (m_etwProvider == nullptr);
}

void EventSource___::WriteStringToAllListeners(String eventName, String msg) {
  EventWrittenEventArgs eventWrittenEventArgs = rt::newobj<EventWrittenEventArgs>((EventSource)this);
  eventWrittenEventArgs->set_EventId = 0;
  eventWrittenEventArgs->set_Message = msg;
  eventWrittenEventArgs->set_Payload = rt::newobj<ReadOnlyCollection<Object>>(rt::newobj<List<Object>>());
  eventWrittenEventArgs->set_PayloadNames = rt::newobj<ReadOnlyCollection<String>>(rt::newobj<List<String>>());
  eventWrittenEventArgs->set_EventName = eventName;
  for (EventDispatcher eventDispatcher = m_Dispatchers; eventDispatcher != nullptr; eventDispatcher = eventDispatcher->m_Next) {
    Boolean flag = false;
    if (eventDispatcher->m_EventEnabled == nullptr) {
      flag = true;
    } else {
      for (Int32 i = 0; i < eventDispatcher->m_EventEnabled->get_Length(); i++) {
        if (eventDispatcher->m_EventEnabled[i]) {
          flag = true;
          break;
        }
      }
    }
    try{
      if (flag) {
        eventDispatcher->m_Listener->OnEventWritten(eventWrittenEventArgs);
      }
    } catch (...) {
    }
  }
}

Boolean EventSource___::IsEnabledByDefault(Int32 eventNum, Boolean enable, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword) {
  if (!enable) {
    return false;
  }
  EventLevel level = (EventLevel)m_eventData[eventNum].Descriptor.get_Level();
}

Boolean EventSource___::IsEnabledCommon(Boolean enabled, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword, EventLevel eventLevel, EventKeywords eventKeywords, EventChannel eventChannel) {
  if (!enabled) {
    return false;
  }
  if (currentLevel != 0 && currentLevel < eventLevel) {
    return false;
  }
  if (currentMatchAnyKeyword != EventKeywords::None && eventKeywords != EventKeywords::None) {
  }
  return true;
}

void EventSource___::ThrowEventSourceException(String eventName, Exception innerEx) {
  if (m_EventSourceExceptionRecurenceCount > 0) {
    return;
  }
  try{
    m_EventSourceExceptionRecurenceCount++;
    String text = "EventSourceException";
    if (eventName != nullptr) {
      text = text + " while processing event "" + eventName + """;
    }
    switch (EventProvider::in::GetLastWriteEventError()) {
      case EventProvider::in::WriteEventErrorCode::EventTooBig:
        ReportOutOfBandMessage(text + ": " + SR::get_EventSource_EventTooBig());
        if (get_ThrowOnEventWriteErrors()) {
          rt::throw_exception<EventSourceException>(SR::get_EventSource_EventTooBig(), innerEx);
        }
        return;
      case EventProvider::in::WriteEventErrorCode::NoFreeBuffers:
        ReportOutOfBandMessage(text + ": " + SR::get_EventSource_NoFreeBuffers());
        if (get_ThrowOnEventWriteErrors()) {
          rt::throw_exception<EventSourceException>(SR::get_EventSource_NoFreeBuffers(), innerEx);
        }
        return;
      case EventProvider::in::WriteEventErrorCode::NullInput:
        ReportOutOfBandMessage(text + ": " + SR::get_EventSource_NullInput());
        if (get_ThrowOnEventWriteErrors()) {
          rt::throw_exception<EventSourceException>(SR::get_EventSource_NullInput(), innerEx);
        }
        return;
      case EventProvider::in::WriteEventErrorCode::TooManyArgs:
        ReportOutOfBandMessage(text + ": " + SR::get_EventSource_TooManyArgs());
        if (get_ThrowOnEventWriteErrors()) {
          rt::throw_exception<EventSourceException>(SR::get_EventSource_TooManyArgs(), innerEx);
        }
        return;
    }
    if (innerEx != nullptr) {
      innerEx = innerEx->GetBaseException();
    } else {
      ReportOutOfBandMessage(text);
    }
    if (get_ThrowOnEventWriteErrors()) {
      rt::throw_exception<EventSourceException>(innerEx);
    }
  } finally: {
    m_EventSourceExceptionRecurenceCount--;
  }
}

void EventSource___::ValidateEventOpcodeForTransfer(EventMetadata& eventData, String eventName) {
  if (eventData.Descriptor.get_Opcode() != 9 && eventData.Descriptor.get_Opcode() != 240 && eventData.Descriptor.get_Opcode() != 1) {
    ThrowEventSourceException(eventName);
  }
}

EventOpcode EventSource___::GetOpcodeWithDefault(EventOpcode opcode, String eventName) {
  if (opcode == EventOpcode::Info && eventName != nullptr) {
    if (eventName->EndsWith("Start", StringComparison::Ordinal)) {
      return EventOpcode::Start;
    }
    if (eventName->EndsWith("Stop", StringComparison::Ordinal)) {
      return EventOpcode::Stop;
    }
  }
  return opcode;
}

Int32 EventSource___::GetParameterCount(EventMetadata eventData) {
  return eventData.Parameters->get_Length();
}

Type EventSource___::GetDataType(EventMetadata eventData, Int32 parameterId) {
  return eventData.Parameters[parameterId]->get_ParameterType();
}

void EventSource___::SendCommand(EventListener listener, EventProviderType eventProviderType, Int32 perEventSourceSessionId, Int32 etwSessionId, EventCommand command, Boolean enable, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> commandArguments) {
  EventCommandEventArgs eventCommandEventArgs = rt::newobj<EventCommandEventArgs>(command, commandArguments, (EventSource)this, listener, eventProviderType, perEventSourceSessionId, etwSessionId, enable, level, matchAnyKeyword);
}

void EventSource___::DoCommand(EventCommandEventArgs commandArgs) {
  if (m_etwProvider == nullptr || m_eventPipeProvider == nullptr) {
    return;
  }
  m_outOfBandMessageCount = 0;
  try{
    EnsureDescriptorsInitialized();
    commandArgs->dispatcher = GetDispatcher(commandArgs->listener);
    if (commandArgs->dispatcher == nullptr && commandArgs->listener != nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_ListenerNotFound());
    }
    if (commandArgs->get_Arguments() == nullptr) {
      IDictionary<String, String> dictionary2 = commandArgs->set_Arguments = rt::newobj<Dictionary<String, String>>();
    }
    if (commandArgs->get_Command() == EventCommand::Update) {
      for (Int32 i = 0; i < m_eventData->get_Length(); i++) {
        EnableEventForDispatcher(commandArgs->dispatcher, commandArgs->eventProviderType, i, IsEnabledByDefault(i, commandArgs->enable, commandArgs->level, commandArgs->matchAnyKeyword));
      }
      if (commandArgs->enable) {
        if (!m_eventSourceEnabled) {
          m_level = commandArgs->level;
          m_matchAnyKeyword = commandArgs->matchAnyKeyword;
        } else {
          if (commandArgs->level > m_level) {
            m_level = commandArgs->level;
          }
          if (commandArgs->matchAnyKeyword == EventKeywords::None) {
            m_matchAnyKeyword = EventKeywords::None;
          } else if (m_matchAnyKeyword != EventKeywords::None) {
            m_matchAnyKeyword |= commandArgs->matchAnyKeyword;
          }

        }
      }
      Boolean flag = commandArgs->perEventSourceSessionId >= 0;
      if (commandArgs->perEventSourceSessionId == 0 && !commandArgs->enable) {
        flag = false;
      }
      if (commandArgs->listener == nullptr) {
        if (!flag) {
        }
        commandArgs->perEventSourceSessionId--;
      }
      commandArgs->set_Command = (flag ? EventCommand::Enable : EventCommand::Disable);
      if (flag && commandArgs->dispatcher == nullptr && !get_SelfDescribingEvents()) {
        SendManifest(m_rawManifest);
      }
      if (commandArgs->enable) {
        m_eventSourceEnabled = true;
      }
      OnEventCommand(commandArgs);
    }
    if (commandArgs->get_Command() == EventCommand::SendManifest && m_rawManifest != nullptr) {
      SendManifest(m_rawManifest);
    }
    OnEventCommand(commandArgs);
  } catch (Exception ex) {
  }
}

Boolean EventSource___::EnableEventForDispatcher(EventDispatcher dispatcher, EventProviderType eventProviderType, Int32 eventId, Boolean value) {
  if (dispatcher == nullptr) {
    if (eventId >= m_eventData->get_Length()) {
      return false;
    }
    if (m_etwProvider != nullptr && eventProviderType == EventProviderType::ETW) {
      m_eventData[eventId].EnabledForETW = value;
    }
    if (m_eventPipeProvider != nullptr && eventProviderType == EventProviderType::EventPipe) {
      m_eventData[eventId].EnabledForEventPipe = value;
    }
  } else {
    if (eventId >= dispatcher->m_EventEnabled->get_Length()) {
      return false;
    }
    dispatcher->m_EventEnabled[eventId] = value;
    if (value) {
      m_eventData[eventId].EnabledForAnyListener = true;
    }
  }
  return true;
}

Boolean EventSource___::AnyEventEnabled() {
  for (Int32 i = 0; i < m_eventData->get_Length(); i++) {
    if (m_eventData[i].EnabledForETW || m_eventData[i].EnabledForAnyListener || m_eventData[i].EnabledForEventPipe) {
      return true;
    }
  }
  return false;
}

void EventSource___::EnsureDescriptorsInitialized() {
  if (m_eventData == nullptr) {
    Guid eventSourceGuid = Guid::Empty;
  }
  if (s_currentPid == 0) {
    s_currentPid = Interop::GetCurrentProcessId();
  }
}

void EventSource___::SendManifest(Array<Byte> rawManifest) {
  if (rawManifest == nullptr) {
    return;
  }
  {
    Byte* ptr2 = rawManifest;
    EventDescriptor eventDescriptor = EventDescriptor(65534, 1, 0, 0, 254, 65534, 72057594037927935);
    ManifestEnvelope manifestEnvelope = ManifestEnvelope();
    manifestEnvelope.Format = ManifestEnvelope::ManifestFormats::SimpleXmlFormat;
    manifestEnvelope.MajorVersion = 1;
    manifestEnvelope.MinorVersion = 0;
    manifestEnvelope.Magic = 91;
    Int32 num = rawManifest->get_Length();
    manifestEnvelope.ChunkNumber = 0;
    EventProvider::in::EventData default[2] = {};
    EventProvider::in::EventData* ptr = default;
    ptr->Ptr = (UInt64)(&manifestEnvelope);
    ptr->Size = (UInt32)sizeof(ManifestEnvelope);
    ptr->Reserved = 0u;
    ptr[1].Ptr = (UInt64)ptr2;
    ptr[1].Reserved = 0u;
    Int32 num2 = 65280;
    while (true) {
    }
  }
}

Attribute EventSource___::GetCustomAttributeHelper(MemberInfo member, Type attributeType, EventManifestOptions flags) {
}

Boolean EventSource___::AttributeTypeNamesMatch(Type attributeType, Type reflectedAttributeType) {
  if (!(attributeType == reflectedAttributeType) && !String::in::Equals(attributeType->get_FullName(), reflectedAttributeType->get_FullName(), StringComparison::Ordinal)) {
    if (String::in::Equals(attributeType->get_Name(), reflectedAttributeType->get_Name(), StringComparison::Ordinal) && attributeType->get_Namespace()->EndsWith("Diagnostics.Tracing", StringComparison::Ordinal)) {
      return reflectedAttributeType->get_Namespace()->EndsWith("Diagnostics.Tracing", StringComparison::Ordinal);
    }
    return false;
  }
  return true;
}

Type EventSource___::GetEventSourceBaseType(Type eventSourceType, Boolean allowEventSourceOverride, Boolean reflectionOnly) {
  Type type = eventSourceType;
  if (ReflectionExtensions::BaseType(type) == nullptr) {
    return nullptr;
  }
}

Array<Byte> EventSource___::CreateManifestAndDescriptors(Type eventSourceType, String eventSourceDllName, EventSource source, EventManifestOptions flags) {
  ManifestBuilder manifestBuilder = nullptr;
  Boolean flag = source == nullptr || !source->get_SelfDescribingEvents();
  Exception ex = nullptr;
  Array<Byte> result = nullptr;
}

Boolean EventSource___::RemoveFirstArgIfRelatedActivityId(Array<ParameterInfo>& args) {
}

void EventSource___::AddProviderEnumKind(ManifestBuilder manifest, FieldInfo staticField, String providerEnumKind) {
  Boolean flag = ReflectionExtensions::ReflectionOnly(staticField->get_Module()->get_Assembly());
  Type fieldType = staticField->get_FieldType();
}

void EventSource___::AddEventDescriptor(Array<EventMetadata>& eventData, String eventName, EventAttribute eventAttribute, Array<ParameterInfo> eventParameters, Boolean hasRelatedActivityID) {
  if (eventData->get_Length() <= eventAttribute->get_EventId()) {
    Array<EventMetadata> array = rt::newarr<Array<EventMetadata>>(Math::Max(eventData->get_Length() + 16, eventAttribute->get_EventId() + 1));
    Array<>::in::Copy(eventData, array, eventData->get_Length());
    eventData = array;
  }
}

void EventSource___::TrimEventDescriptors(Array<EventMetadata>& eventData) {
  Int32 num = eventData->get_Length();
  while (0 < num) {
    num--;
    if (eventData[num].Descriptor.get_EventId() != 0) {
      break;
    }
  }
  if (eventData->get_Length() - num > 2) {
    Array<EventMetadata> array = rt::newarr<Array<EventMetadata>>(num + 1);
    Array<>::in::Copy(eventData, array, array->get_Length());
    eventData = array;
  }
}

void EventSource___::AddListener(EventListener listener) {
}

void EventSource___::DebugCheckEvent(Dictionary<String, String>& eventsByName, Array<EventMetadata> eventData, MethodInfo method, EventAttribute eventAttribute, ManifestBuilder manifest, EventManifestOptions options) {
  Int32 eventId = eventAttribute->get_EventId();
  String name = method->get_Name();
  Int32 helperCallFirstArg = GetHelperCallFirstArg(method);
  if (helperCallFirstArg >= 0 && eventId != helperCallFirstArg) {
    manifest->ManifestError(SR::Format(SR::get_EventSource_MismatchIdToWriteEvent(), name, eventId, helperCallFirstArg), true);
  }
  if (eventId < eventData->get_Length() && eventData[eventId].Descriptor.get_EventId() != 0) {
    manifest->ManifestError(SR::Format(SR::get_EventSource_EventIdReused(), name, eventId, eventData[eventId].Name), true);
  }
  for (Int32 i = 0; i < eventData->get_Length(); i++) {
    if (eventData[i].Name != nullptr && eventData[i].Descriptor.get_Task() == (Int32)eventAttribute->get_Task() && (EventOpcode)eventData[i].Descriptor.get_Opcode() == eventAttribute->get_Opcode()) {
      manifest->ManifestError(SR::Format(SR::get_EventSource_TaskOpcodePairReused(), rt::newarr<Array<Object>>(4, name, eventId, eventData[i].Name, i)));
    }
  }
  if (eventAttribute->get_Opcode() != 0) {
    Boolean flag = false;
    if (eventAttribute->get_Task() == EventTask::None) {
      flag = true;
    } else {
      EventTask eventTask = (EventTask)(65534 - eventId);
      if (eventAttribute->get_Opcode() != EventOpcode::Start && eventAttribute->get_Opcode() != EventOpcode::Stop && eventAttribute->get_Task() == eventTask) {
        flag = true;
      }
    }
    if (flag) {
      manifest->ManifestError(SR::Format(SR::get_EventSource_EventMustHaveTaskIfNonDefaultOpcode(), name, eventId));
    }
  }
  if (eventsByName == nullptr) {
    eventsByName = rt::newobj<Dictionary<String, String>>();
  }
  if (eventsByName->ContainsKey(name)) {
    manifest->ManifestError(SR::Format(SR::get_EventSource_EventNameReused(), name), true);
  }
  eventsByName[name] = name;
}

Int32 EventSource___::GetHelperCallFirstArg(MethodInfo method) {
  Array<Byte> iLAsByteArray = method->GetMethodBody()->GetILAsByteArray();
  Int32 num = -1;
  for (Int32 i = 0; i < iLAsByteArray->get_Length(); i++) {
  }
  return -1;
}

void EventSource___::ReportOutOfBandMessage(String msg) {
  try{
  } catch (...) {
  }
}

EventSourceSettings EventSource___::ValidateSettings(EventSourceSettings settings) {
}

void EventSource___::ctor(String eventSourceName) {
}

void EventSource___::ctor(String eventSourceName, EventSourceSettings config) {
}

void EventSource___::ctor(String eventSourceName, EventSourceSettings config, Array<String> traits) {
  if (eventSourceName == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSourceName");
  }
}

void EventSource___::Write(String eventName) {
  if (IsEnabled()) {
    EventSourceOptions options = EventSourceOptions();
    WriteImpl(eventName, options, nullptr, nullptr, nullptr, SimpleEventTypes<EmptyStruct>::get_Instance());
  }
}

void EventSource___::Write(String eventName, EventSourceOptions options) {
  if (IsEnabled()) {
    WriteImpl(eventName, options, nullptr, nullptr, nullptr, SimpleEventTypes<EmptyStruct>::get_Instance());
  }
}

void EventSource___::WriteMultiMerge(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values) {
  if (IsEnabled()) {
  }
}

void EventSource___::WriteMultiMergeInner(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values) {
  Int32 num = 0;
}

void EventSource___::WriteMultiMerge(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, EventData* data) {
  if (!IsEnabled()) {
    return;
  }
  {
    EventSourceOptions* ptr2 = &options;
    EventDescriptor descriptor;
    NameInfo nameInfo = UpdateDescriptor(eventName, eventTypes, options, descriptor);
    if (nameInfo == nullptr) {
      return;
    }
    IntPtr orCreateEventHandle = nameInfo->GetOrCreateEventHandle(m_eventPipeProvider, m_eventHandleTable, descriptor, eventTypes);
    Int32 num = eventTypes->dataCount + eventTypes->typeInfos->get_Length() * 2 + 3;
    EventData default[num] = {};
    EventData* ptr = default;
    for (Int32 i = 0; i < num; i++) {
      ptr[i] = EventData();
    }
    {
      Byte* pointer = providerMetadata;
      {
        Byte* pointer2 = nameInfo->nameMetadata;
        {
          Byte* pointer3 = eventTypes->typeMetadata;
          ptr->SetMetadata(pointer, providerMetadata->get_Length(), 2);
          ptr[1].SetMetadata(pointer2, nameInfo->nameMetadata->get_Length(), 1);
          ptr[2].SetMetadata(pointer3, eventTypes->typeMetadata->get_Length(), 1);
          Int32 num2 = 3;
          for (Int32 j = 0; j < eventTypes->typeInfos->get_Length(); j++) {
            ptr[num2].m_Ptr = data[j].m_Ptr;
            ptr[num2].m_Size = data[j].m_Size;
          }
          WriteEventRaw(eventName, descriptor, orCreateEventHandle, activityID, childActivityID, num2, (IntPtr)(void*)ptr);
        }
      }
    }
  }
}

void EventSource___::WriteImpl(String eventName, EventSourceOptions& options, Object data, Guid* pActivityId, Guid* pRelatedActivityId, TraceLoggingEventTypes eventTypes) {
  try{
    try{
      {
        EventSourceOptions* ptr3 = &options;
        options.set_Opcode = (options.get_IsOpcodeSet() ? options.get_Opcode() : GetOpcodeWithDefault(options.get_Opcode(), eventName));
        EventDescriptor descriptor;
        NameInfo nameInfo = UpdateDescriptor(eventName, eventTypes, options, descriptor);
        if (nameInfo == nullptr) {
          return;
        }
        IntPtr orCreateEventHandle = nameInfo->GetOrCreateEventHandle(m_eventPipeProvider, m_eventHandleTable, descriptor, eventTypes);
        Int32 pinCount = eventTypes->pinCount;
        Byte default[(Int32)(UInt32)eventTypes->scratchSize] = {};
        Byte* scratch = default;
        EventData extern[eventTypes->dataCount + 3] = {};
        EventData* ptr = extern;
        for (Int32 i = 0; i < eventTypes->dataCount + 3; i++) {
          ptr[i] = EventData();
        }
        GCHandle ref[pinCount] = {};
        GCHandle* ptr2 = ref;
        for (Int32 j = 0; j < pinCount; j++) {
          ptr2[j] = GCHandle();
        }
        try{
          {
            Byte* pointer = providerMetadata;
            {
              Byte* pointer2 = nameInfo->nameMetadata;
              {
                Byte* pointer3 = eventTypes->typeMetadata;
                ptr->SetMetadata(pointer, providerMetadata->get_Length(), 2);
                ptr[1].SetMetadata(pointer2, nameInfo->nameMetadata->get_Length(), 1);
                ptr[2].SetMetadata(pointer3, eventTypes->typeMetadata->get_Length(), 1);
                RuntimeHelpers::PrepareConstrainedRegions();
                EventOpcode opcode = (EventOpcode)descriptor.get_Opcode();
                Guid activityId = Guid::Empty;
                Guid relatedActivityId = Guid::Empty;
              }
            }
          }
        } finally: {
        }
      }
    } finally: {
    }
  } catch (Exception ex2) {
  }
}

void EventSource___::WriteToAllListeners(String eventName, EventDescriptor& eventDescriptor, EventTags tags, Guid* pActivityId, Guid* pChildActivityId, EventPayload payload) {
  EventWrittenEventArgs eventWrittenEventArgs = rt::newobj<EventWrittenEventArgs>((EventSource)this);
  eventWrittenEventArgs->set_EventName = eventName;
  eventWrittenEventArgs->m_level = (EventLevel)eventDescriptor.get_Level();
  eventWrittenEventArgs->m_keywords = (EventKeywords)eventDescriptor.get_Keywords();
  eventWrittenEventArgs->m_opcode = (EventOpcode)eventDescriptor.get_Opcode();
  eventWrittenEventArgs->m_tags = tags;
  eventWrittenEventArgs->set_EventId = -1;
  if (pActivityId != nullptr) {
    eventWrittenEventArgs->set_ActivityId = *pActivityId;
  }
  if (pChildActivityId != nullptr) {
    eventWrittenEventArgs->set_RelatedActivityId = *pChildActivityId;
  }
  if (payload != nullptr) {
    eventWrittenEventArgs->set_Payload = rt::newobj<ReadOnlyCollection<Object>>((IList<Object>)payload->get_Values());
    eventWrittenEventArgs->set_PayloadNames = rt::newobj<ReadOnlyCollection<String>>((IList<String>)payload->get_Keys());
  }
  DispatchToAllListeners(-1, eventWrittenEventArgs);
}

void EventSource___::WriteCleanup(GCHandle* pPins, Int32 cPins) {
  DataCollector::ThreadInstance.Disable();
  for (Int32 i = 0; i < cPins; i++) {
    if (pPins[i].get_IsAllocated()) {
      pPins[i].Free();
    }
  }
}

void EventSource___::InitializeProviderMetadata() {
  if (m_traits != nullptr) {
    List<Byte> list = rt::newobj<List<Byte>>(100);
    for (Int32 i = 0; i < m_traits->get_Length() - 1; i += 2) {
      if (!m_traits[i]->StartsWith("ETW_", StringComparison::Ordinal)) {
      }
      String text = m_traits[i]->Substring(4);
    }
    providerMetadata = Statics::MetadataForString(get_Name(), 0, list->get_Count(), 0);
    Int32 num2 = providerMetadata->get_Length() - list->get_Count();
  } else {
    providerMetadata = Statics::MetadataForString(get_Name(), 0, 0, 0);
  }
}

Int32 EventSource___::AddValueToMetaData(List<Byte> metaData, String value) {
  if (value->get_Length() == 0) {
    return 0;
  }
  Int32 count = metaData->get_Count();
  Char c = value[0];
  switch (c.get()) {
    case 64:
      metaData->AddRange(Encoding::in::get_UTF8()->GetBytes(value->Substring(1)));
      break;
    case 123:
      metaData->AddRange(Guid(value).ToByteArray());
      break;
    case 35:
      {
        for (Int32 i = 1; i < value->get_Length(); i++) {
          if (value[i] != 32) {
            if (i + 1 >= value->get_Length()) {
              rt::throw_exception<ArgumentException>(SR::get_EventSource_EvenHexDigits(), "traits");
            }
            metaData->Add((Byte)(HexDigit(value[i]) * 16 + HexDigit(value[i + 1])));
            i++;
          }
        }
        break;
      }default:
      if (65 <= c || 32 == c) {
        metaData->AddRange(Encoding::in::get_UTF8()->GetBytes(value));
        break;
      }
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_IllegalValue(), value), "traits");
  }
  return metaData->get_Count() - count;
}

Int32 EventSource___::HexDigit(Char c) {
  if (48 <= c && c <= 57) {
    return c - 48;
  }
  if (97 <= c) {
    c = (Char)(c - 32);
  }
  if (65 <= c && c <= 70) {
    return c - 65 + 10;
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_BadHexDigit(), c), "traits");
}

NameInfo EventSource___::UpdateDescriptor(String name, TraceLoggingEventTypes eventInfo, EventSourceOptions& options, EventDescriptor& descriptor) {
  NameInfo nameInfo = nullptr;
  Int32 traceloggingId = 0;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceNamespace
