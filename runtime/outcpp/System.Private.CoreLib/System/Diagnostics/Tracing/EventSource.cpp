#include "EventSource-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IList.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Collections/ObjectModel/ReadOnlyCollection-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Decimal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Debugger-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ActivityTracker-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DataCollector-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EmptyStruct-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventChannel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventManifestOptions.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventOpcode.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPayload-dep.h>
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
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NonEventAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/SessionMask-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/SimpleEventTypes-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataCollector-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingEventHandleTable-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/EventHandler-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeData-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeNamedArgument-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceManager-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/WeakReference-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceNamespace {
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace System::Globalization;
using namespace System::Numerics;
using namespace System::Reflection;
using namespace System::Resources;
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
  w[pos / 4] = ((w[pos / 4] << 8) | input);
  if (64 == ++pos) {
    Drain();
  }
}

void EventSource___::Sha1ForNonSecretPurposes::Append(ReadOnlySpan<Byte> input) {
  ReadOnlySpan<Byte> readOnlySpan = input;
  for (Byte&& input2 : *readOnlySpan) {
    Append(input2);
  }
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
    w[i] = BitOperations::RotateLeft(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
  }
  UInt32 num = w[80];
  UInt32 num2 = w[81];
  UInt32 num3 = w[82];
  UInt32 num4 = w[83];
  UInt32 num5 = w[84];
  for (Int32 j = 0; j != 20; j++) {
    UInt32 num6 = (num2 & num3) | (~num2 & num4);
    UInt32 num7 = BitOperations::RotateLeft(num, 5) + num6 + num5 + 1518500249 + w[j];
    num5 = num4;
    num4 = num3;
    num3 = BitOperations::RotateLeft(num2, 30);
    num2 = num;
    num = num7;
  }
  for (Int32 k = 20; k != 40; k++) {
    UInt32 num8 = num2 ^ num3 ^ num4;
    UInt32 num9 = BitOperations::RotateLeft(num, 5) + num8 + num5 + 1859775393 + w[k];
    num5 = num4;
    num4 = num3;
    num3 = BitOperations::RotateLeft(num2, 30);
    num2 = num;
    num = num9;
  }
  for (Int32 l = 40; l != 60; l++) {
    UInt32 num10 = (num2 & num3) | (num2 & num4) | (num3 & num4);
    UInt32 num11 = (UInt32)((Int32)(BitOperations::RotateLeft(num, 5) + num10 + num5) + -1894007588) + w[l];
    num5 = num4;
    num4 = num3;
    num3 = BitOperations::RotateLeft(num2, 30);
    num2 = num;
    num = num11;
  }
  for (Int32 m = 60; m != 80; m++) {
    UInt32 num12 = num2 ^ num3 ^ num4;
    UInt32 num13 = (UInt32)((Int32)(BitOperations::RotateLeft(num, 5) + num12 + num5) + -899497514) + w[m];
    num5 = num4;
    num4 = num3;
    num3 = BitOperations::RotateLeft(num2, 30);
    num2 = num;
    num = num13;
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
  m_eventSource->SendCommand(listener, m_eventProviderType, perEventSourceSessionId, etwSessionId, (EventCommand)command, IsEnabled(), EventProvider::in::get_Level(), EventProvider::in::get_MatchAnyKeyword(), arguments);
}

Boolean EventSource___::get_IsSupported() {
  return IsSupported;
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
  if (!IsSupported) {
    return rt::default__;
  }
  Guid ActivityId;
  Interop::Advapi32::EventActivityIdControl(Interop::Advapi32::ActivityControl::EVENT_ACTIVITY_CTRL_GET_ID, ActivityId);
  return ActivityId;
}

Boolean EventSource___::get_IsDisposed() {
  return m_eventSourceDisposed;
}

Boolean EventSource___::get_ThrowOnEventWriteErrors() {
  return (m_config & EventSourceSettings::ThrowOnEventWriteErrors) != 0;
}

Boolean EventSource___::get_SelfDescribingEvents() {
  return (m_config & EventSourceSettings::EtwSelfDescribingEventFormat) != 0;
}

Boolean EventSource___::InitializeIsSupported() {
  Boolean isEnabled;
  if (!AppContext::TryGetSwitch("System.Diagnostics.Tracing.EventSource.IsSupported", isEnabled)) {
    return true;
  }
  return isEnabled;
}

Boolean EventSource___::IsEnabled() {
  return m_eventSourceEnabled;
}

Boolean EventSource___::IsEnabled(EventLevel level, EventKeywords keywords) {
  return IsEnabled(level, keywords, EventChannel::None);
}

Boolean EventSource___::IsEnabled(EventLevel level, EventKeywords keywords, EventChannel channel) {
  if (!IsEnabled()) {
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
  EventSourceAttribute eventSourceAttribute = (EventSourceAttribute)GetCustomAttributeHelper(eventSourceType, typeof<EventSourceAttribute>());
  String name = eventSourceType->get_Name();
  if (eventSourceAttribute != nullptr) {
    Guid result;
    if (eventSourceAttribute->get_Guid() != nullptr && Guid::TryParse(eventSourceAttribute->get_Guid(), result)) {
      return result;
    }
    if (eventSourceAttribute->get_Name() != nullptr) {
      name = eventSourceAttribute->set_Name();
    }
  }
  if (name == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidTypeName(), "eventSourceType");
  }
  return GenerateGuidFromName(name->ToUpperInvariant());
}

String EventSource___::GetName(Type eventSourceType) {
  return GetName(eventSourceType, EventManifestOptions::None);
}

String EventSource___::GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest) {
  return GenerateManifest(eventSourceType, assemblyPathToIncludeInManifest, EventManifestOptions::None);
}

String EventSource___::GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest, EventManifestOptions flags) {
  if (!IsSupported) {
    return nullptr;
  }
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
  if (!IsSupported) {
    return Array<>::in::Empty<EventSource>();
  }
  List<EventSource> list = rt::newobj<List<EventSource>>();
  {
    rt::lock(EventListener::in::get_EventListenersLock());
    for (WeakReference<EventSource>&& s_EventSource : *EventListener::in::s_EventSources) {
      EventSource target;
      if (s_EventSource->TryGetTarget(target) && !target->get_IsDisposed()) {
        list->Add(target);
      }
    }
    return list;
  }
}

void EventSource___::SendCommand(EventSource eventSource, EventCommand command, IDictionary<String, String> commandArguments) {
  if (IsSupported) {
    if (eventSource == nullptr) {
      rt::throw_exception<ArgumentNullException>("eventSource");
    }
    if (command <= EventCommand::Update && command != EventCommand::SendManifest) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_InvalidCommand(), "command");
    }
    eventSource->SendCommand(nullptr, EventProviderType::ETW, 0, 0, command, true, EventLevel::LogAlways, EventKeywords::None, commandArguments);
  }
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
  if (IsSupported) {
    if (TplEventSource::in::Log != nullptr) {
      TplEventSource::in::Log->SetActivityId(activityId);
    }
    EventPipeInternal::EventActivityIdControl(2u, activityId);
    Interop::Advapi32::EventActivityIdControl(Interop::Advapi32::ActivityControl::EVENT_ACTIVITY_CTRL_SET_ID, activityId);
  }
}

void EventSource___::SetCurrentThreadActivityId(Guid activityId, Guid& oldActivityThatWillContinue) {
  if (!IsSupported) {
    oldActivityThatWillContinue = rt::default__;
    return;
  }
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
  Object::in::ctor();
  if (IsSupported) {
    m_eventHandleTable = rt::newobj<TraceLoggingEventHandleTable>();
    m_config = ValidateSettings(settings);
    Type type = GetType();
    Guid guid = GetGuid(type);
    String name = GetName(type);
    Initialize(guid, name, traits);
  }
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

void EventSource___::OnEventCommand(EventCommandEventArgs command) {
}

void EventSource___::WriteEvent(Int32 eventId) {
  WriteEventCore(eventId, 0, nullptr);
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1) {
  if (IsEnabled()) {
    EventData as[1] = {};
    EventData* ptr = as;
    ptr->set_DataPointer((IntPtr)(void*)(&arg1));
    ptr->set_Size(4);
    ptr->set_Reserved(0);
    WriteEventCore(eventId, 1, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2) {
  if (IsEnabled()) {
    EventData as[2] = {};
    EventData* ptr = as;
    ptr->set_DataPointer((IntPtr)(void*)(&arg1));
    ptr->set_Size(4);
    ptr->set_Reserved(0);
    ptr[1].set_DataPointer((IntPtr)(void*)(&arg2));
    ptr[1].set_Size(4);
    ptr[1].set_Reserved(0);
    WriteEventCore(eventId, 2, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2, Int32 arg3) {
  if (IsEnabled()) {
    EventData as[3] = {};
    EventData* ptr = as;
    ptr->set_DataPointer((IntPtr)(void*)(&arg1));
    ptr->set_Size(4);
    ptr->set_Reserved(0);
    ptr[1].set_DataPointer((IntPtr)(void*)(&arg2));
    ptr[1].set_Size(4);
    ptr[1].set_Reserved(0);
    ptr[2].set_DataPointer((IntPtr)(void*)(&arg3));
    ptr[2].set_Size(4);
    ptr[2].set_Reserved(0);
    WriteEventCore(eventId, 3, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1) {
  if (IsEnabled()) {
    EventData as[1] = {};
    EventData* ptr = as;
    ptr->set_DataPointer((IntPtr)(void*)(&arg1));
    ptr->set_Size(8);
    ptr->set_Reserved(0);
    WriteEventCore(eventId, 1, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2) {
  if (IsEnabled()) {
    EventData as[2] = {};
    EventData* ptr = as;
    ptr->set_DataPointer((IntPtr)(void*)(&arg1));
    ptr->set_Size(8);
    ptr->set_Reserved(0);
    ptr[1].set_DataPointer((IntPtr)(void*)(&arg2));
    ptr[1].set_Size(8);
    ptr[1].set_Reserved(0);
    WriteEventCore(eventId, 2, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2, Int64 arg3) {
  if (IsEnabled()) {
    EventData as[3] = {};
    EventData* ptr = as;
    ptr->set_DataPointer((IntPtr)(void*)(&arg1));
    ptr->set_Size(8);
    ptr->set_Reserved(0);
    ptr[1].set_DataPointer((IntPtr)(void*)(&arg2));
    ptr[1].set_Size(8);
    ptr[1].set_Reserved(0);
    ptr[2].set_DataPointer((IntPtr)(void*)(&arg3));
    ptr[2].set_Size(8);
    ptr[2].set_Reserved(0);
    WriteEventCore(eventId, 3, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1) {
  if (IsEnabled()) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData as[1] = {};
      EventData* ptr2 = as;
      ptr2->set_DataPointer((IntPtr)(void*)value);
      ptr2->set_Size((arg1->get_Length() + 1) * 2);
      ptr2->set_Reserved(0);
      WriteEventCore(eventId, 1, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, String arg2) {
  if (!IsEnabled()) {
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
      EventData as[2] = {};
      EventData* ptr3 = as;
      ptr3->set_DataPointer((IntPtr)(void*)value);
      ptr3->set_Size((arg1->get_Length() + 1) * 2);
      ptr3->set_Reserved(0);
      ptr3[1].set_DataPointer((IntPtr)(void*)value2);
      ptr3[1].set_Size((arg2->get_Length() + 1) * 2);
      ptr3[1].set_Reserved(0);
      WriteEventCore(eventId, 2, ptr3);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, String arg2, String arg3) {
  if (!IsEnabled()) {
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
        EventData as[3] = {};
        EventData* ptr4 = as;
        ptr4->set_DataPointer((IntPtr)(void*)value);
        ptr4->set_Size((arg1->get_Length() + 1) * 2);
        ptr4->set_Reserved(0);
        ptr4[1].set_DataPointer((IntPtr)(void*)value2);
        ptr4[1].set_Size((arg2->get_Length() + 1) * 2);
        ptr4[1].set_Reserved(0);
        ptr4[2].set_DataPointer((IntPtr)(void*)value3);
        ptr4[2].set_Size((arg3->get_Length() + 1) * 2);
        ptr4[2].set_Reserved(0);
        WriteEventCore(eventId, 3, ptr4);
      }
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, Int32 arg2) {
  if (IsEnabled()) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData as[2] = {};
      EventData* ptr2 = as;
      ptr2->set_DataPointer((IntPtr)(void*)value);
      ptr2->set_Size((arg1->get_Length() + 1) * 2);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)(&arg2));
      ptr2[1].set_Size(4);
      ptr2[1].set_Reserved(0);
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, Int32 arg2, Int32 arg3) {
  if (IsEnabled()) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData as[3] = {};
      EventData* ptr2 = as;
      ptr2->set_DataPointer((IntPtr)(void*)value);
      ptr2->set_Size((arg1->get_Length() + 1) * 2);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)(&arg2));
      ptr2[1].set_Size(4);
      ptr2[1].set_Reserved(0);
      ptr2[2].set_DataPointer((IntPtr)(void*)(&arg3));
      ptr2[2].set_Size(4);
      ptr2[2].set_Reserved(0);
      WriteEventCore(eventId, 3, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, String arg1, Int64 arg2) {
  if (IsEnabled()) {
    if (arg1 == nullptr) {
      arg1 = "";
    }
    {
      Char* ptr = arg1;
      Char* value = ptr;
      EventData as[2] = {};
      EventData* ptr2 = as;
      ptr2->set_DataPointer((IntPtr)(void*)value);
      ptr2->set_Size((arg1->get_Length() + 1) * 2);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)(&arg2));
      ptr2[1].set_Size(8);
      ptr2[1].set_Reserved(0);
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, String arg2) {
  if (IsEnabled()) {
    if (arg2 == nullptr) {
      arg2 = "";
    }
    {
      Char* ptr = arg2;
      Char* value = ptr;
      EventData as[2] = {};
      EventData* ptr2 = as;
      ptr2->set_DataPointer((IntPtr)(void*)(&arg1));
      ptr2->set_Size(8);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)value);
      ptr2[1].set_Size((arg2->get_Length() + 1) * 2);
      ptr2[1].set_Reserved(0);
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, String arg2) {
  if (IsEnabled()) {
    if (arg2 == nullptr) {
      arg2 = "";
    }
    {
      Char* ptr = arg2;
      Char* value = ptr;
      EventData as[2] = {};
      EventData* ptr2 = as;
      ptr2->set_DataPointer((IntPtr)(void*)(&arg1));
      ptr2->set_Size(4);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)value);
      ptr2[1].set_Size((arg2->get_Length() + 1) * 2);
      ptr2[1].set_Reserved(0);
      WriteEventCore(eventId, 2, ptr2);
    }
  }
}

void EventSource___::WriteEvent(Int32 eventId, Array<Byte> arg1) {
  if (!IsEnabled()) {
    return;
  }
  EventData as[2] = {};
  EventData* ptr = as;
  if (arg1 == nullptr || arg1->get_Length() == 0) {
    Int32 num = 0;
    ptr->set_DataPointer((IntPtr)(void*)(&num));
    ptr->set_Size(4);
    ptr->set_Reserved(0);
    ptr[1].set_DataPointer((IntPtr)(void*)(&num));
    ptr[1].set_Size(0);
    ptr[1].set_Reserved(0);
    WriteEventCore(eventId, 2, ptr);
    return;
  }
  Int32 size = arg1->get_Length();
  {
    Byte* value = &arg1[0];
    ptr->set_DataPointer((IntPtr)(void*)(&size));
    ptr->set_Size(4);
    ptr->set_Reserved(0);
    ptr[1].set_DataPointer((IntPtr)(void*)value);
    ptr[1].set_Size(size);
    ptr[1].set_Reserved(0);
    WriteEventCore(eventId, 2, ptr);
  }
}

void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Array<Byte> arg2) {
  if (!IsEnabled()) {
    return;
  }
  EventData as[3] = {};
  EventData* ptr = as;
  ptr->set_DataPointer((IntPtr)(void*)(&arg1));
  ptr->set_Size(8);
  ptr->set_Reserved(0);
  if (arg2 == nullptr || arg2->get_Length() == 0) {
    Int32 num = 0;
    ptr[1].set_DataPointer((IntPtr)(void*)(&num));
    ptr[1].set_Size(4);
    ptr[1].set_Reserved(0);
    ptr[2].set_DataPointer((IntPtr)(void*)(&num));
    ptr[2].set_Size(0);
    ptr[2].set_Reserved(0);
    WriteEventCore(eventId, 3, ptr);
    return;
  }
  Int32 size = arg2->get_Length();
  {
    Byte* value = &arg2[0];
    ptr[1].set_DataPointer((IntPtr)(void*)(&size));
    ptr[1].set_Size(4);
    ptr[1].set_Reserved(0);
    ptr[2].set_DataPointer((IntPtr)(void*)value);
    ptr[2].set_Size(size);
    ptr[2].set_Reserved(0);
    WriteEventCore(eventId, 3, ptr);
  }
}

void EventSource___::WriteEventCore(Int32 eventId, Int32 eventDataCount, EventData* data) {
  WriteEventWithRelatedActivityIdCore(eventId, nullptr, eventDataCount, data);
}

void EventSource___::WriteEventWithRelatedActivityIdCore(Int32 eventId, Guid* relatedActivityId, Int32 eventDataCount, EventData* data) {
  if (!IsEnabled()) {
    return;
  }
  try {
    EventOpcode opcode = (EventOpcode)m_eventData[eventId].Descriptor.get_Opcode();
    EventActivityOptions activityOptions = m_eventData[eventId].ActivityOptions;
    Guid* activityID = nullptr;
    Guid activityId = Guid::Empty;
    Guid relatedActivityId2 = Guid::Empty;
    if (opcode != 0 && relatedActivityId == nullptr && (activityOptions & EventActivityOptions::Disable) == 0) {
      switch (opcode) {
        case EventOpcode::Start:
          m_activityTracker->OnStart(m_name, m_eventData[eventId].Name, m_eventData[eventId].Descriptor.get_Task(), activityId, relatedActivityId2, m_eventData[eventId].ActivityOptions);
          break;
        case EventOpcode::Stop:
          m_activityTracker->OnStop(m_name, m_eventData[eventId].Name, m_eventData[eventId].Descriptor.get_Task(), activityId);
          break;
      }
      if (activityId != Guid::Empty) {
        activityID = &activityId;
      }
      if (relatedActivityId2 != Guid::Empty) {
        relatedActivityId = &relatedActivityId2;
      }
    }
    if (m_eventData[eventId].EnabledForETW || m_eventData[eventId].EnabledForEventPipe) {
      if (!get_SelfDescribingEvents()) {
        if (!m_etwProvider->WriteEvent(m_eventData[eventId].Descriptor, m_eventData[eventId].EventHandle, activityID, relatedActivityId, eventDataCount, (IntPtr)(void*)data)) {
          ThrowEventSourceException(m_eventData[eventId].Name);
        }
        if (!m_eventPipeProvider->WriteEvent(m_eventData[eventId].Descriptor, m_eventData[eventId].EventHandle, activityID, relatedActivityId, eventDataCount, (IntPtr)(void*)data)) {
          ThrowEventSourceException(m_eventData[eventId].Name);
        }
      } else {
        TraceLoggingEventTypes traceLoggingEventTypes = m_eventData[eventId].TraceLoggingEventTypes;
        if (traceLoggingEventTypes == nullptr) {
          traceLoggingEventTypes = rt::newobj<TraceLoggingEventTypes>(m_eventData[eventId].Name, m_eventData[eventId].Tags, m_eventData[eventId].Parameters);
          Interlocked::CompareExchange(m_eventData[eventId].TraceLoggingEventTypes, traceLoggingEventTypes, (TraceLoggingEventTypes)nullptr);
        }
        EventSourceOptions eventSourceOptions;
        eventSourceOptions.set_Keywords((EventKeywords)m_eventData[eventId].Descriptor.get_Keywords());
        eventSourceOptions.set_Level((EventLevel)m_eventData[eventId].Descriptor.get_Level());
        eventSourceOptions.set_Opcode((EventOpcode)m_eventData[eventId].Descriptor.get_Opcode());
        EventSourceOptions options = eventSourceOptions;
        WriteMultiMerge(m_eventData[eventId].Name, options, traceLoggingEventTypes, activityID, relatedActivityId, data);
      }
    }
    if (m_Dispatchers != nullptr && m_eventData[eventId].EnabledForAnyListener) {
      WriteToAllListeners(eventId, activityID, relatedActivityId, eventDataCount, data);
    }
  } catch (Exception ex) {
    if (rt::is<EventSourceException>(ex)) {
      throw;
    }
    ThrowEventSourceException(m_eventData[eventId].Name, ex);
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
  if (!IsSupported) {
    return;
  }
  if (disposing) {
    if (m_eventSourceEnabled) {
      try {
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
  Object::in::ctor();
  if (IsSupported) {
    m_eventHandleTable = rt::newobj<TraceLoggingEventHandleTable>();
    m_config = ValidateSettings(settings);
    Initialize(eventSourceGuid, eventSourceName, traits);
  }
}

void EventSource___::Initialize(Guid eventSourceGuid, String eventSourceName, Array<String> traits) {
  try {
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
    {
      rt::lock(EventListener::in::get_EventListenersLock());
      overideEventProvider2->Register((EventSource)this);
    }
    EventListener::in::AddEventSource((EventSource)this);
    m_etwProvider = overideEventProvider;
    if (get_Name() != "System.Diagnostics.Eventing.FrameworkEventSource" || Environment::get_IsWindows8OrAbove()) {
      GCHandle gCHandle = GCHandle::Alloc(providerMetadata, GCHandleType::Pinned);
      IntPtr data = gCHandle.AddrOfPinnedObject();
      Int32 num = m_etwProvider->SetInformation(Interop::Advapi32::EVENT_INFO_CLASS::SetTraits, data, (UInt32)providerMetadata->get_Length());
      gCHandle.Free();
    }
    m_eventPipeProvider = overideEventProvider2;
    m_completelyInited = true;
  } catch (Exception ex) {
    if (m_constructionException == nullptr) {
      m_constructionException = ex;
    }
    ReportOutOfBandMessage("ERROR: Exception during construction of EventSource " + get_Name() + ": " + ex->get_Message());
  }
  {
    rt::lock(EventListener::in::get_EventListenersLock());
    for (EventCommandEventArgs eventCommandEventArgs = m_deferredCommands; eventCommandEventArgs != nullptr; eventCommandEventArgs = eventCommandEventArgs->nextCommand) {
      DoCommand(eventCommandEventArgs);
    }
  }
}

String EventSource___::GetName(Type eventSourceType, EventManifestOptions flags) {
  if (eventSourceType == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSourceType");
  }
  EventSourceAttribute eventSourceAttribute = (EventSourceAttribute)GetCustomAttributeHelper(eventSourceType, typeof<EventSourceAttribute>(), flags);
  if (eventSourceAttribute != nullptr && eventSourceAttribute->get_Name() != nullptr) {
    return eventSourceAttribute->get_Name();
  }
  return eventSourceType->get_Name();
}

Guid EventSource___::GenerateGuidFromName(String name) {
  ReadOnlySpan<Byte> input = rt::newarr<Array<Byte>>(16);
  Array<Byte> array = Encoding::in::get_BigEndianUnicode()->GetBytes(name);
  Sha1ForNonSecretPurposes sha1ForNonSecretPurposes;
  sha1ForNonSecretPurposes.Start();
  sha1ForNonSecretPurposes.Append(input);
  sha1ForNonSecretPurposes.Append(array);
  Array<>::in::Resize(array, 16);
  sha1ForNonSecretPurposes.Finish(array);
  array[7] = (Byte)((array[7] & 15) | 80);
  return Guid(array);
}

Object EventSource___::DecodeObject(Int32 eventId, Int32 parameterId, EventData*& data) {
  IntPtr dataPointer = data->get_DataPointer();
  data++;
  Type type = GetDataType(m_eventData[eventId], parameterId);
  while (true) {
    if (type == typeof<IntPtr>()) {
      return *(IntPtr*)(void*)dataPointer;
    }
    if (type == typeof<Int32>()) {
      return *(Int32*)(void*)dataPointer;
    }
    if (type == typeof<UInt32>()) {
      return *(UInt32*)(void*)dataPointer;
    }
    if (type == typeof<Int64>()) {
      return *(Int64*)(void*)dataPointer;
    }
    if (type == typeof<UInt64>()) {
      return (UInt64)(*(Int64*)(void*)dataPointer);
    }
    if (type == typeof<Byte>()) {
      return *(Byte*)(void*)dataPointer;
    }
    if (type == typeof<SByte>()) {
      return *(SByte*)(void*)dataPointer;
    }
    if (type == typeof<Int16>()) {
      return *(Int16*)(void*)dataPointer;
    }
    if (type == typeof<UInt16>()) {
      return *(UInt16*)(void*)dataPointer;
    }
    if (type == typeof<Single>()) {
      return *(Single*)(void*)dataPointer;
    }
    if (type == typeof<Double>()) {
      return *(Double*)(void*)dataPointer;
    }
    if (type == typeof<Decimal>()) {
      return *(Decimal*)(void*)dataPointer;
    }
    if (type == typeof<Boolean>()) {
      return *(Int32*)(void*)dataPointer == 1;
    }
    if (type == typeof<Guid>()) {
      return *(Guid*)(void*)dataPointer;
    }
    if (type == typeof<Char>()) {
      return (Char)(*(UInt16*)(void*)dataPointer);
    }
    if (type == typeof<DateTime>()) {
      Int64 fileTime = *(Int64*)(void*)dataPointer;
      return DateTime::FromFileTimeUtc(fileTime);
    }
    if (type == typeof<Array<Byte>>()) {
      Int32 num = *(Int32*)(void*)dataPointer;
      Array<Byte> array = rt::newarr<Array<Byte>>(num);
      dataPointer = data->set_DataPointer();
      data++;
      for (Int32 i = 0; i < num; i++) {
        array[i] = *(Byte*)(void*)(dataPointer + i);
      }
      return array;
    }
    if (type == typeof<Byte*>()) {
      break;
    }
    try {
      m_EventSourceInDecodeObject = true;
      if (type->get_IsEnum()) {
        type = Enum::in::GetUnderlyingType(type);
        Int32 num2 = Marshal::SizeOf(type);
        if (num2 < 4) {
          type = typeof<Int32>();
        }
        continue;
      }
      if (dataPointer == IntPtr::Zero) {
        return nullptr;
      }
      return rt::newstr<String>((Char*)(void*)dataPointer);
    } catch (...) {
    } finally: {
      m_EventSourceInDecodeObject = false;
    }
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
  if (!IsEnabled()) {
    return;
  }
  try {
    if (childActivityID != nullptr && !m_eventData[eventId].HasRelatedActivityID) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_NoRelatedActivityId());
    }
    LogEventArgsMismatches(eventId, args);
    Guid* activityID = nullptr;
    Guid activityId = Guid::Empty;
    Guid relatedActivityId = Guid::Empty;
    EventOpcode opcode = (EventOpcode)m_eventData[eventId].Descriptor.get_Opcode();
    EventActivityOptions activityOptions = m_eventData[eventId].ActivityOptions;
    if (childActivityID == nullptr && (activityOptions & EventActivityOptions::Disable) == 0) {
      switch (opcode) {
        case EventOpcode::Start:
          m_activityTracker->OnStart(m_name, m_eventData[eventId].Name, m_eventData[eventId].Descriptor.get_Task(), activityId, relatedActivityId, m_eventData[eventId].ActivityOptions);
          break;
        case EventOpcode::Stop:
          m_activityTracker->OnStop(m_name, m_eventData[eventId].Name, m_eventData[eventId].Descriptor.get_Task(), activityId);
          break;
      }
      if (activityId != Guid::Empty) {
        activityID = &activityId;
      }
      if (relatedActivityId != Guid::Empty) {
        childActivityID = &relatedActivityId;
      }
    }
    if (m_eventData[eventId].EnabledForETW || m_eventData[eventId].EnabledForEventPipe) {
      if (!get_SelfDescribingEvents()) {
        if (!m_etwProvider->WriteEvent(m_eventData[eventId].Descriptor, m_eventData[eventId].EventHandle, activityID, childActivityID, args)) {
          ThrowEventSourceException(m_eventData[eventId].Name);
        }
        if (!m_eventPipeProvider->WriteEvent(m_eventData[eventId].Descriptor, m_eventData[eventId].EventHandle, activityID, childActivityID, args)) {
          ThrowEventSourceException(m_eventData[eventId].Name);
        }
      } else {
        TraceLoggingEventTypes traceLoggingEventTypes = m_eventData[eventId].TraceLoggingEventTypes;
        if (traceLoggingEventTypes == nullptr) {
          traceLoggingEventTypes = rt::newobj<TraceLoggingEventTypes>(m_eventData[eventId].Name, EventTags::None, m_eventData[eventId].Parameters);
          Interlocked::CompareExchange(m_eventData[eventId].TraceLoggingEventTypes, traceLoggingEventTypes, (TraceLoggingEventTypes)nullptr);
        }
        EventSourceOptions eventSourceOptions;
        eventSourceOptions.set_Keywords((EventKeywords)m_eventData[eventId].Descriptor.get_Keywords());
        eventSourceOptions.set_Level((EventLevel)m_eventData[eventId].Descriptor.get_Level());
        eventSourceOptions.set_Opcode((EventOpcode)m_eventData[eventId].Descriptor.get_Opcode());
        EventSourceOptions options = eventSourceOptions;
        WriteMultiMerge(m_eventData[eventId].Name, options, traceLoggingEventTypes, activityID, childActivityID, args);
      }
    }
    if (m_Dispatchers != nullptr && m_eventData[eventId].EnabledForAnyListener) {
      if (LocalAppContextSwitches::get_PreserveEventListnerObjectIdentity()) {
        WriteToAllListeners(eventId, nullptr, nullptr, activityID, childActivityID, args);
        return;
      }
      Array<Object> args2 = SerializeEventArgs(eventId, args);
      WriteToAllListeners(eventId, nullptr, nullptr, activityID, childActivityID, args2);
    }
  } catch (Exception ex) {
    if (rt::is<EventSourceException>(ex)) {
      throw;
    }
    ThrowEventSourceException(m_eventData[eventId].Name, ex);
  }
}

Array<Object> EventSource___::SerializeEventArgs(Int32 eventId, Array<Object> args) {
  TraceLoggingEventTypes traceLoggingEventTypes = m_eventData[eventId].TraceLoggingEventTypes;
  if (traceLoggingEventTypes == nullptr) {
    traceLoggingEventTypes = rt::newobj<TraceLoggingEventTypes>(m_eventData[eventId].Name, EventTags::None, m_eventData[eventId].Parameters);
    Interlocked::CompareExchange(m_eventData[eventId].TraceLoggingEventTypes, traceLoggingEventTypes, (TraceLoggingEventTypes)nullptr);
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
    if ((obj != nullptr && !parameterType->IsAssignableFrom(obj->GetType())) || (obj == nullptr && parameterType->get_IsValueType() && (!parameterType->get_IsGenericType() || !(parameterType->GetGenericTypeDefinition() == typeof<Nullable<T>>())))) {
      ReportOutOfBandMessage(SR::Format(SR::get_EventSource_VarArgsParameterMismatch(), eventId, parameters[i]->get_Name()));
      break;
    }
  }
}

void EventSource___::WriteToAllListeners(Int32 eventId, Guid* activityID, Guid* childActivityID, Int32 eventDataCount, EventData* data) {
  Int32 num = GetParameterCount(m_eventData[eventId]);
  Int32 num2 = 0;
  for (Int32 i = 0; i < num; i++) {
    Type dataType = GetDataType(m_eventData[eventId], i);
    num2 = ((!(dataType == typeof<Array<Byte>>())) ? (num2 + 1) : (num2 + 2));
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
  WriteToAllListeners(eventId, nullptr, nullptr, activityID, childActivityID, array);
}

void EventSource___::WriteToAllListeners(Int32 eventId, UInt32* osThreadId, DateTime* timeStamp, Guid* activityID, Guid* childActivityID, Array<Object> args) {
  EventWrittenEventArgs eventWrittenEventArgs = rt::newobj<EventWrittenEventArgs>((EventSource)this);
  eventWrittenEventArgs->set_EventId(eventId);
  if (osThreadId != nullptr) {
    eventWrittenEventArgs->set_OSThreadId((Int32)(*osThreadId));
  }
  if (timeStamp != nullptr) {
    eventWrittenEventArgs->set_TimeStamp(*timeStamp);
  }
  if (activityID != nullptr) {
    eventWrittenEventArgs->set_ActivityId(*activityID);
  }
  if (childActivityID != nullptr) {
    eventWrittenEventArgs->set_RelatedActivityId(*childActivityID);
  }
  eventWrittenEventArgs->set_EventName(m_eventData[eventId].Name);
  eventWrittenEventArgs->set_Message(m_eventData[eventId].Message);
  eventWrittenEventArgs->set_Payload(rt::newobj<ReadOnlyCollection<Object>>(args));
  DispatchToAllListeners(eventId, eventWrittenEventArgs);
}

void EventSource___::DispatchToAllListeners(Int32 eventId, EventWrittenEventArgs eventCallbackArgs) {
  Exception ex = nullptr;
  for (EventDispatcher eventDispatcher = m_Dispatchers; eventDispatcher != nullptr; eventDispatcher = eventDispatcher->m_Next) {
    if (eventId == -1 || eventDispatcher->m_EventEnabled[eventId]) {
      try {
        eventDispatcher->m_Listener->OnEventWritten(eventCallbackArgs);
      } catch (Exception ex2) {
        ReportOutOfBandMessage("ERROR: Exception during EventSource.OnEventWritten: " + ex2->get_Message());
        ex = ex2;
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
  if (flag & (m_eventPipeProvider == nullptr)) {
    return;
  }
  EventLevel eventLevel = EventLevel::LogAlways;
  Int64 keywords = -1;
  if (get_SelfDescribingEvents()) {
    EventSourceOptions eventSourceOptions;
    eventSourceOptions.set_Keywords((EventKeywords)keywords);
    eventSourceOptions.set_Level(eventLevel);
    EventSourceOptions options = eventSourceOptions;
    TraceLoggingEventTypes eventTypes = rt::newobj<TraceLoggingEventTypes>("EventSourceMessage", EventTags::None, typeof<String>());
    WriteMultiMergeInner("EventSourceMessage", options, eventTypes, nullptr, nullptr, msgString);
    return;
  }
  if (m_rawManifest == nullptr && m_outOfBandMessageCount == 1) {
    ManifestBuilder manifestBuilder = rt::newobj<ManifestBuilder>(get_Name(), get_Guid(), get_Name(), nullptr, EventManifestOptions::None);
    manifestBuilder->StartEvent("EventSourceMessage", rt::newobj<EventAttribute>(0));
    manifestBuilder->AddEventParameter(typeof<String>(), "message");
    manifestBuilder->EndEvent();
    SendManifest(manifestBuilder->CreateManifest());
  }
  {
    Char* ptr = msgString;
    Char* ptr2 = ptr;
    EventDescriptor eventDescriptor = EventDescriptor(0, 0, 0, (Byte)eventLevel, 0, 0, keywords);
    EventProvider::in::EventData eventData;
    eventData.Ptr = (UInt64)ptr2;
    eventData.Size = (UInt32)(2 * (msgString->get_Length() + 1));
    eventData.Reserved = 0u;
    if (m_etwProvider != nullptr) {
      m_etwProvider->WriteEvent(eventDescriptor, IntPtr::Zero, nullptr, nullptr, 1, (IntPtr)(void*)(&eventData));
    }
    if (m_eventPipeProvider == nullptr) {
      return;
    }
    if (m_writeEventStringEventHandle == IntPtr::Zero) {
      {
        rt::lock(m_createEventLock);
        if (m_writeEventStringEventHandle == IntPtr::Zero) {
          String eventName = "EventSourceMessage";
          EventParameterInfo eventParameterInfo;
          eventParameterInfo.SetInfo("message", typeof<String>());
          Array<Byte> array = EventPipeMetadataGenerator::in::Instance->GenerateMetadata(0, eventName, keywords, (UInt32)eventLevel, 0u, EventOpcode::Info, rt::newarr<Array<EventParameterInfo>>(1));
          UInt32 metadataLength = (UInt32)((array != nullptr) ? array->get_Length() : 0);
          {
            Byte* pMetadata = array;
            m_writeEventStringEventHandle = m_eventPipeProvider->m_eventProvider->DefineEventHandle(0u, eventName, keywords, 0u, (UInt32)eventLevel, pMetadata, metadataLength);
          }
        }
      }
    }
    m_eventPipeProvider->WriteEvent(eventDescriptor, m_writeEventStringEventHandle, nullptr, nullptr, 1, (IntPtr)(void*)(&eventData));
  }
}

void EventSource___::WriteStringToAllListeners(String eventName, String msg) {
  EventWrittenEventArgs eventWrittenEventArgs = rt::newobj<EventWrittenEventArgs>((EventSource)this);
  eventWrittenEventArgs->set_EventId(0);
  eventWrittenEventArgs->set_Message(msg);
  eventWrittenEventArgs->set_Payload(rt::newobj<ReadOnlyCollection<Object>>(rt::newobj<List<Object>>()));
  eventWrittenEventArgs->set_PayloadNames(rt::newobj<ReadOnlyCollection<String>>(rt::newobj<List<String>>()));
  eventWrittenEventArgs->set_EventName(eventName);
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
    try {
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
  EventKeywords eventKeywords = (EventKeywords)(m_eventData[eventNum].Descriptor.get_Keywords() & (Int64)(~SessionMask::get_All().ToEventKeywords()));
  EventChannel channel = (EventChannel)m_eventData[eventNum].Descriptor.get_Channel();
  return IsEnabledCommon(enable, currentLevel, currentMatchAnyKeyword, level, eventKeywords, channel);
}

Boolean EventSource___::IsEnabledCommon(Boolean enabled, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword, EventLevel eventLevel, EventKeywords eventKeywords, EventChannel eventChannel) {
  if (!enabled) {
    return false;
  }
  if (currentLevel != 0 && currentLevel < eventLevel) {
    return false;
  }
  if (currentMatchAnyKeyword != EventKeywords::None && eventKeywords != EventKeywords::None) {
    if (eventChannel != 0 && m_channelData != nullptr && m_channelData->get_Length() > (Int32)eventChannel) {
      EventKeywords eventKeywords2 = (EventKeywords)((Int64)m_channelData[(UInt32)eventChannel] | (Int64)eventKeywords);
      if (eventKeywords2 != EventKeywords::None && (eventKeywords2 & currentMatchAnyKeyword) == EventKeywords::None) {
        return false;
      }
    } else if ((eventKeywords & currentMatchAnyKeyword) == EventKeywords::None) {
      return false;
    }

  }
  return true;
}

void EventSource___::ThrowEventSourceException(String eventName, Exception innerEx) {
  if (m_EventSourceExceptionRecurenceCount > 0) {
    return;
  }
  try {
    m_EventSourceExceptionRecurenceCount++;
    String text = "EventSourceException";
    if (eventName != nullptr) {
      text = text + " while processing event \"" + eventName + "\"";
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
      Array<String> obj = rt::newarr<Array<String>>(5);
      Type type = innerEx->GetType();
      obj[2] = (((Object)type != nullptr) ? type->ToString() : nullptr);
      obj[3] = ":";
      obj[4] = innerEx->get_Message();
      ReportOutOfBandMessage(String::in::Concat(obj));
    } else {
      ReportOutOfBandMessage(text);
    }
    if (get_ThrowOnEventWriteErrors()) {
      rt::throw_exception<EventSourceException>(innerEx);
    }
  } catch (...) {
  } finally: {
    m_EventSourceExceptionRecurenceCount--;
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
  if (!IsSupported) {
    return;
  }
  EventCommandEventArgs eventCommandEventArgs = rt::newobj<EventCommandEventArgs>(command, commandArguments, (EventSource)this, listener, eventProviderType, perEventSourceSessionId, etwSessionId, enable, level, matchAnyKeyword);
  {
    rt::lock(EventListener::in::get_EventListenersLock());
    if (m_completelyInited) {
      m_deferredCommands = nullptr;
      DoCommand(eventCommandEventArgs);
      return;
    }
    if (m_deferredCommands == nullptr) {
      m_deferredCommands = eventCommandEventArgs;
      return;
    }
    EventCommandEventArgs eventCommandEventArgs2 = m_deferredCommands;
    while (eventCommandEventArgs2->nextCommand != nullptr) {
      eventCommandEventArgs2 = eventCommandEventArgs2->nextCommand;
    }
    eventCommandEventArgs2->nextCommand = eventCommandEventArgs;
  }
}

void EventSource___::DoCommand(EventCommandEventArgs commandArgs) {
  if (!IsSupported || m_etwProvider == nullptr || m_eventPipeProvider == nullptr) {
    return;
  }
  m_outOfBandMessageCount = 0;
  try {
    EnsureDescriptorsInitialized();
    commandArgs->dispatcher = GetDispatcher(commandArgs->listener);
    if (commandArgs->dispatcher == nullptr && commandArgs->listener != nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_EventSource_ListenerNotFound());
    }
    if (commandArgs->get_Arguments() == nullptr) {
      IDictionary<String, String> dictionary2 = commandArgs->set_Arguments(rt::newobj<Dictionary<String, String>>());
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
          commandArgs->perEventSourceSessionId = -commandArgs->perEventSourceSessionId;
        }
        commandArgs->perEventSourceSessionId--;
      }
      commandArgs->set_Command((flag ? EventCommand::Enable : EventCommand::Disable));
      if (flag && commandArgs->dispatcher == nullptr && !get_SelfDescribingEvents()) {
        SendManifest(m_rawManifest);
      }
      if (commandArgs->enable) {
        m_eventSourceEnabled = true;
      }
      OnEventCommand(commandArgs);
      EventHandler<EventCommandEventArgs> eventCommandExecuted = m_eventCommandExecuted;
      if (eventCommandExecuted != nullptr) {
        eventCommandExecuted((EventSource)this, commandArgs);
      }
      if (commandArgs->enable) {
        return;
      }
      for (Int32 j = 0; j < m_eventData->get_Length(); j++) {
        Boolean enabledForAnyListener = false;
        for (EventDispatcher eventDispatcher = m_Dispatchers; eventDispatcher != nullptr; eventDispatcher = eventDispatcher->m_Next) {
          if (eventDispatcher->m_EventEnabled[j]) {
            enabledForAnyListener = true;
            break;
          }
        }
        m_eventData[j].EnabledForAnyListener = enabledForAnyListener;
      }
      if (!AnyEventEnabled()) {
        m_level = EventLevel::LogAlways;
        m_matchAnyKeyword = EventKeywords::None;
        m_eventSourceEnabled = false;
      }
      return;
    }
    if (commandArgs->get_Command() == EventCommand::SendManifest && m_rawManifest != nullptr) {
      SendManifest(m_rawManifest);
    }
    OnEventCommand(commandArgs);
    EventHandler<EventCommandEventArgs> eventCommandExecuted2 = m_eventCommandExecuted;
    if (eventCommandExecuted2 != nullptr) {
      eventCommandExecuted2((EventSource)this, commandArgs);
    }
  } catch (Exception ex) {
    ReportOutOfBandMessage("ERROR: Exception in Command Processing for EventSource " + get_Name() + ": " + ex->get_Message());
  }
}

Boolean EventSource___::EnableEventForDispatcher(EventDispatcher dispatcher, EventProviderType eventProviderType, Int32 eventId, Boolean value) {
  if (!IsSupported) {
    return false;
  }
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
  if (m_eventData != nullptr) {
    return;
  }
  m_rawManifest = CreateManifestAndDescriptors(GetType(), get_Name(), (EventSource)this);
  for (WeakReference<EventSource>&& s_EventSource : *EventListener::in::s_EventSources) {
    EventSource target;
    if (s_EventSource->TryGetTarget(target) && target->get_Guid() == m_guid && !target->get_IsDisposed() && target != (EventSource)this) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_EventSourceGuidInUse(), m_guid));
    }
  }
  for (EventDispatcher eventDispatcher = m_Dispatchers; eventDispatcher != nullptr; eventDispatcher = eventDispatcher->m_Next) {
    EventDispatcher eventDispatcher2 = eventDispatcher;
    if (eventDispatcher2->m_EventEnabled == nullptr) {
      eventDispatcher2->m_EventEnabled = rt::newarr<Array<Boolean>>(m_eventData->get_Length());
    }
  }
  DefineEventPipeEvents();
}

void EventSource___::SendManifest(Array<Byte> rawManifest) {
  if (rawManifest == nullptr) {
    return;
  }
  {
    Byte* ptr2 = rawManifest;
    EventDescriptor eventDescriptor = EventDescriptor(65534, 1, 0, 0, 254, 65534, 72057594037927935);
    ManifestEnvelope manifestEnvelope;
    manifestEnvelope.Format = ManifestEnvelope::ManifestFormats::SimpleXmlFormat;
    manifestEnvelope.MajorVersion = 1;
    manifestEnvelope.MinorVersion = 0;
    manifestEnvelope.Magic = 91;
    Int32 num = rawManifest->get_Length();
    manifestEnvelope.ChunkNumber = 0;
    EventProvider::in::EventData as[2] = {};
    EventProvider::in::EventData* ptr = as;
    ptr->Ptr = (UInt64)(&manifestEnvelope);
    ptr->Size = (UInt32)sizeof(ManifestEnvelope);
    ptr->Reserved = 0u;
    ptr[1].Ptr = (UInt64)ptr2;
    ptr[1].Reserved = 0u;
    Int32 num2 = 65280;
    while (true) {

    IL_00c7:
      manifestEnvelope.TotalChunks = (UInt16)((num + (num2 - 1)) / num2);
      while (num > 0) {
        ptr[1].Size = (UInt32)Math::Min(num, num2);
        if (m_etwProvider != nullptr && !m_etwProvider->WriteEvent(eventDescriptor, IntPtr::Zero, nullptr, nullptr, 2, (IntPtr)(void*)ptr)) {
          if (EventProvider::in::GetLastWriteEventError() == EventProvider::in::WriteEventErrorCode::EventTooBig && manifestEnvelope.ChunkNumber == 0 && num2 > 256) {
            num2 /= 2;
            goto IL_00c7;
          }
          if (get_ThrowOnEventWriteErrors()) {
            ThrowEventSourceException("SendManifest");
          }
          break;
        }
        num -= num2;
        ptr[1].Ptr += (UInt32)num2;
        manifestEnvelope.ChunkNumber++;
        if ((Int32)manifestEnvelope.ChunkNumber % 5 == 0) {
          Thread::in::Sleep(15);
        }
      }
      break;
    }
  }
}

Attribute EventSource___::GetCustomAttributeHelper(MemberInfo member, Type attributeType, EventManifestOptions flags) {
  if (!member->get_Module()->get_Assembly()->get_ReflectionOnly() && (flags & EventManifestOptions::AllowEventSourceOverride) == 0) {
    Attribute result = nullptr;
    Array<Object> customAttributes = member->GetCustomAttributes(attributeType, false);
    Int32 num = 0;
    if (num < customAttributes->get_Length()) {
      Object obj = customAttributes[num];
      result = (Attribute)obj;
    }
    return result;
  }
  for (CustomAttributeData&& customAttribute : *CustomAttributeData::in::GetCustomAttributes(member)) {
    if (!AttributeTypeNamesMatch(attributeType, customAttribute->get_Constructor()->get_ReflectedType())) {
      continue;
    }
    Attribute attribute = nullptr;
    if (customAttribute->get_ConstructorArguments()->get_Count() == 1) {
      attribute = (Attribute)Activator::CreateInstance(attributeType, customAttribute->get_ConstructorArguments()[0].get_Value());
    } else if (customAttribute->get_ConstructorArguments()->get_Count() == 0) {
      attribute = (Attribute)Activator::CreateInstance(attributeType);
    }

    if (attribute == nullptr) {
      continue;
    }
    for (CustomAttributeNamedArgument&& namedArgument : *customAttribute->get_NamedArguments()) {
      PropertyInfo property = attributeType->GetProperty(namedArgument.get_MemberInfo()->get_Name(), BindingFlags::Instance | BindingFlags::Public);
      Object obj2 = namedArgument.get_TypedValue().get_Value();
      if (property->get_PropertyType()->get_IsEnum()) {
        String value = obj2->ToString();
        obj2 = Enum::in::Parse(property->get_PropertyType(), value);
      }
      property->SetValue(attribute, obj2, nullptr);
    }
    return attribute;
  }
  return nullptr;
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
  if (type->get_BaseType() == nullptr) {
    return nullptr;
  }
  do {
    type = type->get_BaseType();
  } while (type != nullptr && type->get_IsAbstract());
  if (type != nullptr) {
    if (!allowEventSourceOverride) {
      if ((reflectionOnly && type->get_FullName() != typeof<EventSource>()->get_FullName()) || (!reflectionOnly && type != typeof<EventSource>())) {
        return nullptr;
      }
    } else if (type->get_Name() != "EventSource") {
      return nullptr;
    }

  }
  return type;
}

Array<Byte> EventSource___::CreateManifestAndDescriptors(Type eventSourceType, String eventSourceDllName, EventSource source, EventManifestOptions flags) {
  ManifestBuilder manifestBuilder = nullptr;
  Boolean flag = source == nullptr || !source->get_SelfDescribingEvents();
  Exception ex = nullptr;
  Array<Byte> result = nullptr;
  if (eventSourceType->get_IsAbstract() && (flags & EventManifestOptions::Strict) == 0) {
    return nullptr;
  }
  try {
    Array<MethodInfo> methods = eventSourceType->GetMethods(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
    Int32 num = 1;
    Array<EventMetadata> eventData = nullptr;
    Dictionary<String, String> eventsByName = nullptr;
    if (source != nullptr || (flags & EventManifestOptions::Strict) != 0) {
      eventData = rt::newarr<Array<EventMetadata>>(methods->get_Length() + 1);
      eventData[0].Name = "";
    }
    ResourceManager resources = nullptr;
    EventSourceAttribute eventSourceAttribute = (EventSourceAttribute)GetCustomAttributeHelper(eventSourceType, typeof<EventSourceAttribute>(), flags);
    if (eventSourceAttribute != nullptr && eventSourceAttribute->get_LocalizationResources() != nullptr) {
      resources = rt::newobj<ResourceManager>(eventSourceAttribute->get_LocalizationResources(), eventSourceType->get_Assembly());
    }
    manifestBuilder = rt::newobj<ManifestBuilder>(GetName(eventSourceType, flags), GetGuid(eventSourceType), eventSourceDllName, resources, flags);
    manifestBuilder->StartEvent("EventSourceMessage", rt::newobj<EventAttribute>(0));
    manifestBuilder->AddEventParameter(typeof<String>(), "message");
    manifestBuilder->EndEvent();
    if ((flags & EventManifestOptions::Strict) != 0) {
      if (!(GetEventSourceBaseType(eventSourceType, (flags & EventManifestOptions::AllowEventSourceOverride) != 0, eventSourceType->get_Assembly()->get_ReflectionOnly()) != nullptr)) {
        manifestBuilder->ManifestError(SR::get_EventSource_TypeMustDeriveFromEventSource());
      }
      if (!eventSourceType->get_IsAbstract() && !eventSourceType->get_IsSealed()) {
        manifestBuilder->ManifestError(SR::get_EventSource_TypeMustBeSealedOrAbstract());
      }
    }
    Array<String> array = rt::newarr<Array<String>>(3);
    for (String&& text : *array) {
      Type nestedType = eventSourceType->GetNestedType(text);
      if (!(nestedType != nullptr)) {
        continue;
      }
      if (eventSourceType->get_IsAbstract()) {
        manifestBuilder->ManifestError(SR::Format(SR::get_EventSource_AbstractMustNotDeclareKTOC(), nestedType->get_Name()));
        continue;
      }
      Array<FieldInfo> fields = nestedType->GetFields(BindingFlags::DeclaredOnly | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
      for (FieldInfo&& staticField : *fields) {
        AddProviderEnumKind(manifestBuilder, staticField, text);
      }
    }
    manifestBuilder->AddKeyword("Session3", 17592186044416);
    manifestBuilder->AddKeyword("Session2", 35184372088832);
    manifestBuilder->AddKeyword("Session1", 70368744177664);
    manifestBuilder->AddKeyword("Session0", 140737488355328);
    if (eventSourceType != typeof<EventSource>()) {
      for (MethodInfo&& methodInfo : *methods) {
        Array<ParameterInfo> args = methodInfo->GetParameters();
        EventAttribute eventAttribute = (EventAttribute)GetCustomAttributeHelper(methodInfo, typeof<EventAttribute>(), flags);
        if (methodInfo->get_IsStatic()) {
          continue;
        }
        if (eventSourceType->get_IsAbstract()) {
          if (eventAttribute != nullptr) {
            manifestBuilder->ManifestError(SR::Format(SR::get_EventSource_AbstractMustNotDeclareEventMethods(), methodInfo->get_Name(), eventAttribute->get_EventId()));
          }
          continue;
        }
        if (eventAttribute == nullptr) {
          if (methodInfo->get_ReturnType() != typeof<void>() || methodInfo->get_IsVirtual() || GetCustomAttributeHelper(methodInfo, typeof<NonEventAttribute>(), flags) != nullptr) {
            continue;
          }
          EventAttribute eventAttribute2 = rt::newobj<EventAttribute>(num);
          eventAttribute = eventAttribute2;
        } else if (eventAttribute->get_EventId() <= 0) {
          manifestBuilder->ManifestError(SR::Format(SR::get_EventSource_NeedPositiveId(), methodInfo->get_Name()), true);
          continue;
        }

        if (methodInfo->get_Name()->LastIndexOf('.') >= 0) {
          manifestBuilder->ManifestError(SR::Format(SR::get_EventSource_EventMustNotBeExplicitImplementation(), methodInfo->get_Name(), eventAttribute->get_EventId()));
        }
        num++;
        String name = methodInfo->get_Name();
        if (eventAttribute->get_Opcode() == EventOpcode::Info) {
          Boolean flag2 = eventAttribute->get_Task() == EventTask::None;
          if (flag2) {
            eventAttribute->set_Task((EventTask)(65534 - eventAttribute->get_EventId()));
          }
          if (!eventAttribute->get_IsOpcodeSet()) {
            eventAttribute->set_Opcode(GetOpcodeWithDefault(EventOpcode::Info, name));
          }
          if (flag2) {
            if (eventAttribute->get_Opcode() == EventOpcode::Start) {
              String text2 = name->Substring(0, name->get_Length() - "Start"->get_Length());
              if (String::in::Compare(name, 0, text2, 0, text2->get_Length()) == 0 && String::in::Compare(name, text2->get_Length(), "Start", 0, Math::Max(name->get_Length() - text2->get_Length(), "Start"->get_Length())) == 0) {
                manifestBuilder->AddTask(text2, (Int32)eventAttribute->get_Task());
              }
            } else if (eventAttribute->get_Opcode() == EventOpcode::Stop) {
              Int32 num2 = eventAttribute->get_EventId() - 1;
              if (eventData != nullptr && num2 < eventData->get_Length()) {
                EventMetadata eventMetadata = eventData[num2];
                String text3 = name->Substring(0, name->get_Length() - "Stop"->get_Length());
                if (eventMetadata.Descriptor.get_Opcode() == 1 && String::in::Compare(eventMetadata.Name, 0, text3, 0, text3->get_Length()) == 0 && String::in::Compare(eventMetadata.Name, text3->get_Length(), "Start", 0, Math::Max(eventMetadata.Name->get_Length() - text3->get_Length(), "Start"->get_Length())) == 0) {
                  eventAttribute->set_Task((EventTask)eventMetadata.Descriptor.get_Task());
                  flag2 = false;
                }
              }
              if (flag2 && (flags & EventManifestOptions::Strict) != 0) {
                rt::throw_exception<ArgumentException>(SR::get_EventSource_StopsFollowStarts());
              }
            }

          }
        }
        Boolean hasRelatedActivityID = RemoveFirstArgIfRelatedActivityId(args);
        if (source == nullptr || !source->get_SelfDescribingEvents()) {
          manifestBuilder->StartEvent(name, eventAttribute);
          for (Int32 l = 0; l < args->get_Length(); l++) {
            manifestBuilder->AddEventParameter(args[l]->get_ParameterType(), args[l]->get_Name());
          }
          manifestBuilder->EndEvent();
        }
        if (source != nullptr || (flags & EventManifestOptions::Strict) != 0) {
          DebugCheckEvent(eventsByName, eventData, methodInfo, eventAttribute, manifestBuilder, flags);
          if (eventAttribute->get_Channel() != 0) {
            eventAttribute->set_Keywords((EventKeywords)manifestBuilder->GetChannelKeyword(eventAttribute->get_Channel(), (UInt64)eventAttribute->get_Keywords()));
          }
          String key = "event_" + name;
          String localizedMessage = manifestBuilder->GetLocalizedMessage(key, CultureInfo::in::get_CurrentUICulture(), false);
          if (localizedMessage != nullptr) {
            eventAttribute->set_Message(localizedMessage);
          }
          AddEventDescriptor(eventData, name, eventAttribute, args, hasRelatedActivityID);
        }
      }
    }
    NameInfo::in::ReserveEventIDsBelow(num);
    if (source != nullptr) {
      TrimEventDescriptors(eventData);
      source->m_eventData = eventData;
      source->m_channelData = manifestBuilder->GetChannelData();
    }
    if (!eventSourceType->get_IsAbstract() && (source == nullptr || !source->get_SelfDescribingEvents())) {
      flag = ((flags & EventManifestOptions::OnlyIfNeededForRegistration) == 0 || manifestBuilder->GetChannelData()->get_Length() != 0);
      if (!flag && (flags & EventManifestOptions::Strict) == 0) {
        return nullptr;
      }
      result = manifestBuilder->CreateManifest();
    }
  } catch (Exception ex2) {
    if ((flags & EventManifestOptions::Strict) == 0) {
      throw;
    }
    ex = ex2;
  }
  if ((flags & EventManifestOptions::Strict) != 0 && ((manifestBuilder != nullptr && manifestBuilder->get_Errors()->get_Count() > 0) || ex != nullptr)) {
    String text4 = String::in::Empty;
    if (manifestBuilder != nullptr && manifestBuilder->get_Errors()->get_Count() > 0) {
      Boolean flag3 = true;
      for (String&& error : *manifestBuilder->get_Errors()) {
        if (!flag3) {
          text4 += Environment::get_NewLine();
        }
        flag3 = false;
        text4 += error;
      }
    } else {
      text4 = "Unexpected error: " + ex->get_Message();
    }
    rt::throw_exception<ArgumentException>(text4, ex);
  }
  if (!flag) {
    return nullptr;
  }
  return result;
}

Boolean EventSource___::RemoveFirstArgIfRelatedActivityId(Array<ParameterInfo>& args) {
  if (args->get_Length() != 0 && args[0]->get_ParameterType() == typeof<Guid>() && String::in::Equals(args[0]->get_Name(), "relatedActivityId", StringComparison::OrdinalIgnoreCase)) {
    Array<ParameterInfo> array = rt::newarr<Array<ParameterInfo>>(args->get_Length() - 1);
    Array<>::in::Copy(args, 1, array, 0, args->get_Length() - 1);
    args = array;
    return true;
  }
  return false;
}

void EventSource___::AddProviderEnumKind(ManifestBuilder manifest, FieldInfo staticField, String providerEnumKind) {
  Boolean reflectionOnly = staticField->get_Module()->get_Assembly()->get_ReflectionOnly();
  Type fieldType = staticField->get_FieldType();
  if ((!reflectionOnly && fieldType == typeof<EventOpcode>()) || AttributeTypeNamesMatch(fieldType, typeof<EventOpcode>())) {
    if (!(providerEnumKind != "Opcodes")) {
      Int32 value = (Int32)staticField->GetRawConstantValue();
      manifest->AddOpcode(staticField->get_Name(), value);
      return;
    }
  } else if ((!reflectionOnly && fieldType == typeof<EventTask>()) || AttributeTypeNamesMatch(fieldType, typeof<EventTask>())) {
    if (!(providerEnumKind != "Tasks")) {
      Int32 value2 = (Int32)staticField->GetRawConstantValue();
      manifest->AddTask(staticField->get_Name(), value2);
      return;
    }
  } else {
    if ((reflectionOnly || !(fieldType == typeof<EventKeywords>())) && !AttributeTypeNamesMatch(fieldType, typeof<EventKeywords>())) {
      return;
    }
    if (!(providerEnumKind != "Keywords")) {
      UInt64 value3 = (UInt64)(Int64)staticField->GetRawConstantValue();
      manifest->AddKeyword(staticField->get_Name(), value3);
      return;
    }
  }

  manifest->ManifestError(SR::Format(SR::get_EventSource_EnumKindMismatch(), staticField->get_Name(), staticField->get_FieldType()->get_Name(), providerEnumKind));
}

void EventSource___::AddEventDescriptor(Array<EventMetadata>& eventData, String eventName, EventAttribute eventAttribute, Array<ParameterInfo> eventParameters, Boolean hasRelatedActivityID) {
  if (eventData->get_Length() <= eventAttribute->get_EventId()) {
    Array<EventMetadata> array = rt::newarr<Array<EventMetadata>>(Math::Max(eventData->get_Length() + 16, eventAttribute->get_EventId() + 1));
    Array<>::in::Copy(eventData, array, eventData->get_Length());
    eventData = array;
  }
  eventData[eventAttribute->get_EventId()].Descriptor = EventDescriptor(eventAttribute->get_EventId(), eventAttribute->get_Version(), (Byte)eventAttribute->get_Channel(), (Byte)eventAttribute->get_Level(), (Byte)eventAttribute->get_Opcode(), (Int32)eventAttribute->get_Task(), (Int64)eventAttribute->get_Keywords() | (Int64)SessionMask::get_All().ToEventKeywords());
  eventData[eventAttribute->get_EventId()].Tags = eventAttribute->set_Tags();
  eventData[eventAttribute->get_EventId()].Name = eventName;
  eventData[eventAttribute->get_EventId()].Parameters = eventParameters;
  eventData[eventAttribute->get_EventId()].Message = eventAttribute->set_Message();
  eventData[eventAttribute->get_EventId()].ActivityOptions = eventAttribute->set_ActivityOptions();
  eventData[eventAttribute->get_EventId()].HasRelatedActivityID = hasRelatedActivityID;
  eventData[eventAttribute->get_EventId()].EventHandle = IntPtr::Zero;
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
  {
    rt::lock(EventListener::in::get_EventListenersLock());
    Array<Boolean> eventEnabled = nullptr;
    if (m_eventData != nullptr) {
      eventEnabled = rt::newarr<Array<Boolean>>(m_eventData->get_Length());
    }
    m_Dispatchers = rt::newobj<EventDispatcher>(m_Dispatchers, eventEnabled, listener);
    listener->OnEventSourceCreated((EventSource)this);
  }
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
      if ((options & EventManifestOptions::Strict) == 0) {
        break;
      }
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
    switch (iLAsByteArray[i].get()) {
      case 14:
      case 16:
        i++;
        continue;
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
      case 29:
      case 30:
        if (i > 0 && iLAsByteArray[i - 1] == 2) {
          num = iLAsByteArray[i] - 22;
        }
        continue;
      case 31:
        if (i > 0 && iLAsByteArray[i - 1] == 2) {
          num = iLAsByteArray[i + 1];
        }
        i++;
        continue;
      case 32:
        i += 4;
        continue;
      case 40:
        i += 4;
        if (num >= 0) {
          for (Int32 j = i + 1; j < iLAsByteArray->get_Length(); j++) {
            if (iLAsByteArray[j] == 42) {
              return num;
            }
            if (iLAsByteArray[j] != 0) {
              break;
            }
          }
        }
        num = -1;
        continue;
      case 44:
      case 45:
        num = -1;
        i++;
        continue;
      case 57:
      case 58:
        num = -1;
        i += 4;
        continue;
      case 140:
      case 141:
        i += 4;
        continue;
      case 254:
        i++;
        if (i < iLAsByteArray->get_Length() && iLAsByteArray[i] < 6) {
          continue;
        }
        break;
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 20:
      case 37:
      case 103:
      case 104:
      case 105:
      case 106:
      case 109:
      case 110:
      case 162:
        continue;
    }
    return -1;
  }
  return -1;
}

void EventSource___::ReportOutOfBandMessage(String msg) {
  try {
    if (m_outOfBandMessageCount < 15) {
      m_outOfBandMessageCount++;
      goto IL_0036;
    }
    if (m_outOfBandMessageCount == 16) {
      return;
    }
    m_outOfBandMessageCount = 16;
    msg = "Reached message limit.   End of EventSource error messages.";
    goto IL_0036;

  IL_0036:
    Debugger::Log(0, nullptr, String::in::Format("EventSource Error: {0}{1}", msg, Environment::get_NewLine()));
    WriteEventString(msg);
    WriteStringToAllListeners("EventSourceMessage", msg);
  } catch (...) {
  }
}

EventSourceSettings EventSource___::ValidateSettings(EventSourceSettings settings) {
  if ((settings & (EventSourceSettings::EtwManifestEventFormat | EventSourceSettings::EtwSelfDescribingEventFormat)) == (EventSourceSettings::EtwManifestEventFormat | EventSourceSettings::EtwSelfDescribingEventFormat)) {
    rt::throw_exception<ArgumentException>(SR::get_EventSource_InvalidEventFormat(), "settings");
  }
  if ((settings & (EventSourceSettings::EtwManifestEventFormat | EventSourceSettings::EtwSelfDescribingEventFormat)) == 0) {
    settings |= EventSourceSettings::EtwSelfDescribingEventFormat;
  }
  return settings;
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
    EventSourceOptions options;
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
    Byte level = ((options.valuesSet & 4) != 0) ? options.level : eventTypes->level;
    EventKeywords keywords = ((options.valuesSet & 1) != 0) ? options.keywords : eventTypes->keywords;
    if (IsEnabled((EventLevel)level, keywords)) {
      WriteMultiMergeInner(eventName, options, eventTypes, activityID, childActivityID, values);
    }
  }
}

void EventSource___::WriteMultiMergeInner(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values) {
  Int32 num = 0;
  Byte level = ((options.valuesSet & 4) != 0) ? options.level : eventTypes->level;
  Byte opcode = ((options.valuesSet & 8) != 0) ? options.opcode : eventTypes->opcode;
  EventTags tags = ((options.valuesSet & 2) != 0) ? options.tags : eventTypes->get_Tags();
  EventKeywords keywords = ((options.valuesSet & 1) != 0) ? options.keywords : eventTypes->keywords;
  String as = eventName;
  NameInfo nameInfo = eventTypes->GetNameInfo(as != nullptr ? as : eventTypes->get_Name(), tags);
  if (nameInfo == nullptr) {
    return;
  }
  num = nameInfo->identity;
  EventDescriptor eventDescriptor = EventDescriptor(num, level, opcode, (Int64)keywords);
  IntPtr orCreateEventHandle = nameInfo->GetOrCreateEventHandle(m_eventPipeProvider, m_eventHandleTable, eventDescriptor, eventTypes);
  Int32 pinCount = eventTypes->pinCount;
  Byte is[(Int32)(UInt32)eventTypes->scratchSize] = {};
  Byte* scratch = is;
  EventData in[eventTypes->dataCount + 3] = {};
  EventData* ptr = in;
  for (Int32 i = 0; i < eventTypes->dataCount + 3; i++) {
    *(ptr + i) = rt::default__;
  }
  GCHandle ref[pinCount] = {};
  GCHandle* ptr2 = ref;
  for (Int32 j = 0; j < pinCount; j++) {
    *(ptr2 + j) = rt::default__;
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
        try {
          DataCollector::ThreadInstance.Enable(scratch, eventTypes->scratchSize, ptr + 3, eventTypes->dataCount, ptr2, pinCount);
          for (Int32 k = 0; k < eventTypes->typeInfos->get_Length(); k++) {
            TraceLoggingTypeInfo traceLoggingTypeInfo = eventTypes->typeInfos[k];
            traceLoggingTypeInfo->WriteData(TraceLoggingDataCollector::in::Instance, traceLoggingTypeInfo->get_PropertyValueFactory()(values[k]));
          }
          WriteEventRaw(eventName, eventDescriptor, orCreateEventHandle, activityID, childActivityID, (Int32)(DataCollector::ThreadInstance.Finish() - ptr), (IntPtr)(void*)ptr);
        } catch (...) {
        } finally: {
          WriteCleanup(ptr2, pinCount);
        }
      }
    }
  }
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
    EventData as[num] = {};
    EventData* ptr = as;
    for (Int32 i = 0; i < num; i++) {
      *(ptr + i) = rt::default__;
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
            *(ptr + num2).m_Ptr = *(data + j).m_Ptr;
            *(ptr + num2).m_Size = *(data + j).m_Size;
            if (*(data + j).m_Size == 4 && eventTypes->typeInfos[j]->get_DataType() == typeof<Boolean>()) {
              *(ptr + num2).m_Size = 1;
            }
            num2++;
          }
          WriteEventRaw(eventName, descriptor, orCreateEventHandle, activityID, childActivityID, num2, (IntPtr)(void*)ptr);
        }
      }
    }
  }
}

void EventSource___::WriteImpl(String eventName, EventSourceOptions& options, Object data, Guid* pActivityId, Guid* pRelatedActivityId, TraceLoggingEventTypes eventTypes) {
  try {
    try {
      {
        EventSourceOptions* ptr3 = &options;
        options.set_Opcode((options.get_IsOpcodeSet() ? options.get_Opcode() : GetOpcodeWithDefault(options.get_Opcode(), eventName)));
        EventDescriptor descriptor;
        NameInfo nameInfo = UpdateDescriptor(eventName, eventTypes, options, descriptor);
        if (nameInfo == nullptr) {
          return;
        }
        IntPtr orCreateEventHandle = nameInfo->GetOrCreateEventHandle(m_eventPipeProvider, m_eventHandleTable, descriptor, eventTypes);
        Int32 pinCount = eventTypes->pinCount;
        Byte as[(Int32)(UInt32)eventTypes->scratchSize] = {};
        Byte* scratch = as;
        EventData is[eventTypes->dataCount + 3] = {};
        EventData* ptr = is;
        for (Int32 i = 0; i < eventTypes->dataCount + 3; i++) {
          *(ptr + i) = rt::default__;
        }
        GCHandle in[pinCount] = {};
        GCHandle* ptr2 = in;
        for (Int32 j = 0; j < pinCount; j++) {
          *(ptr2 + j) = rt::default__;
        }
        try {
          {
            Byte* pointer = providerMetadata;
            {
              Byte* pointer2 = nameInfo->nameMetadata;
              {
                Byte* pointer3 = eventTypes->typeMetadata;
                ptr->SetMetadata(pointer, providerMetadata->get_Length(), 2);
                ptr[1].SetMetadata(pointer2, nameInfo->nameMetadata->get_Length(), 1);
                ptr[2].SetMetadata(pointer3, eventTypes->typeMetadata->get_Length(), 1);
                EventOpcode opcode = (EventOpcode)descriptor.get_Opcode();
                Guid activityId = Guid::Empty;
                Guid relatedActivityId = Guid::Empty;
                if (pActivityId == nullptr && pRelatedActivityId == nullptr && (options.get_ActivityOptions() & EventActivityOptions::Disable) == 0) {
                  switch (opcode) {
                    case EventOpcode::Start:
                      m_activityTracker->OnStart(m_name, eventName, 0, activityId, relatedActivityId, options.get_ActivityOptions());
                      break;
                    case EventOpcode::Stop:
                      m_activityTracker->OnStop(m_name, eventName, 0, activityId);
                      break;
                  }
                  if (activityId != Guid::Empty) {
                    pActivityId = &activityId;
                  }
                  if (relatedActivityId != Guid::Empty) {
                    pRelatedActivityId = &relatedActivityId;
                  }
                }
                try {
                  DataCollector::ThreadInstance.Enable(scratch, eventTypes->scratchSize, ptr + 3, eventTypes->dataCount, ptr2, pinCount);
                  TraceLoggingTypeInfo traceLoggingTypeInfo = eventTypes->typeInfos[0];
                  traceLoggingTypeInfo->WriteData(TraceLoggingDataCollector::in::Instance, traceLoggingTypeInfo->get_PropertyValueFactory()(data));
                  WriteEventRaw(eventName, descriptor, orCreateEventHandle, pActivityId, pRelatedActivityId, (Int32)(DataCollector::ThreadInstance.Finish() - ptr), (IntPtr)(void*)ptr);
                  if (m_Dispatchers != nullptr) {
                    EventPayload payload = (EventPayload)eventTypes->typeInfos[0]->GetData(data);
                    WriteToAllListeners(eventName, descriptor, nameInfo->tags, pActivityId, pRelatedActivityId, payload);
                  }
                } catch (Exception ex) {
                  if (rt::is<EventSourceException>(ex)) {
                    throw;
                  }
                  ThrowEventSourceException(eventName, ex);
                } finally: {
                  WriteCleanup(ptr2, pinCount);
                }
              }
            }
          }
        } catch (...) {
        } finally: {
        }
      }
    } catch (...) {
    } finally: {
    }
  } catch (Exception ex2) {
    if (rt::is<EventSourceException>(ex2)) {
      throw;
    }
    ThrowEventSourceException(eventName, ex2);
  }
}

void EventSource___::WriteToAllListeners(String eventName, EventDescriptor& eventDescriptor, EventTags tags, Guid* pActivityId, Guid* pChildActivityId, EventPayload payload) {
  EventWrittenEventArgs eventWrittenEventArgs = rt::newobj<EventWrittenEventArgs>((EventSource)this);
  eventWrittenEventArgs->set_EventName(eventName);
  eventWrittenEventArgs->m_level = (EventLevel)eventDescriptor.get_Level();
  eventWrittenEventArgs->m_keywords = (EventKeywords)eventDescriptor.get_Keywords();
  eventWrittenEventArgs->m_opcode = (EventOpcode)eventDescriptor.get_Opcode();
  eventWrittenEventArgs->m_tags = tags;
  eventWrittenEventArgs->set_EventId(-1);
  if (pActivityId != nullptr) {
    eventWrittenEventArgs->set_ActivityId(*pActivityId);
  }
  if (pChildActivityId != nullptr) {
    eventWrittenEventArgs->set_RelatedActivityId(*pChildActivityId);
  }
  if (payload != nullptr) {
    eventWrittenEventArgs->set_Payload(rt::newobj<ReadOnlyCollection<Object>>((IList<Object>)payload->get_Values()));
    eventWrittenEventArgs->set_PayloadNames(rt::newobj<ReadOnlyCollection<String>>((IList<String>)payload->get_Keys()));
  }
  DispatchToAllListeners(-1, eventWrittenEventArgs);
}

void EventSource___::WriteCleanup(GCHandle* pPins, Int32 cPins) {
  DataCollector::ThreadInstance.Disable();
  for (Int32 i = 0; i < cPins; i++) {
    if (*(pPins + i).get_IsAllocated()) {
      *(pPins + i).Free();
    }
  }
}

void EventSource___::InitializeProviderMetadata() {
  if (m_traits != nullptr) {
    List<Byte> list = rt::newobj<List<Byte>>(100);
    for (Int32 i = 0; i < m_traits->get_Length() - 1; i += 2) {
      if (!m_traits[i]->StartsWith("ETW_", StringComparison::Ordinal)) {
        continue;
      }
      String text = m_traits[i]->Substring(4);
      Byte result;
      if (!Byte::TryParse(text, result)) {
        if (!(text == "GROUP")) {
          rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_UnknownEtwTrait(), text), "traits");
        }
        result = 1;
      }
      String value = m_traits[i + 1];
      Int32 count = list->get_Count();
      list->Add(0);
      list->Add(0);
      list->Add(result);
      Int32 num = AddValueToMetaData(list, value) + 3;
      list[count] = (Byte)num;
      list[count + 1] = (Byte)(num >> 8);
    }
    providerMetadata = Statics::MetadataForString(get_Name(), 0, list->get_Count(), 0);
    Int32 num2 = providerMetadata->get_Length() - list->get_Count();
    for (Byte&& item : *list) {
      providerMetadata[num2++] = item;
    }
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
    case '@':
      metaData->AddRange(Encoding::in::get_UTF8()->GetBytes(value->Substring(1)));
      break;
    case '{':
      metaData->AddRange(Guid(value).ToByteArray());
      break;
    case '#':
      {
        for (Int32 i = 1; i < value->get_Length(); i++) {
          if (value[i] != ' ') {
            if (i + 1 >= value->get_Length()) {
              rt::throw_exception<ArgumentException>(SR::get_EventSource_EvenHexDigits(), "traits");
            }
            metaData->Add((Byte)(HexDigit(value[i]) * 16 + HexDigit(value[i + 1])));
            i++;
          }
        }
        break;
      }default:
      if ('A' <= c || ' ' == c) {
        metaData->AddRange(Encoding::in::get_UTF8()->GetBytes(value));
        break;
      }
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_IllegalValue(), value), "traits");
  }
  return metaData->get_Count() - count;
}

Int32 EventSource___::HexDigit(Char c) {
  if ('0' <= c && c <= '9') {
    return c - 48;
  }
  if ('a' <= c) {
    c = (Char)(c - 32);
  }
  if ('A' <= c && c <= 'F') {
    return c - 65 + 10;
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_BadHexDigit(), c), "traits");
}

NameInfo EventSource___::UpdateDescriptor(String name, TraceLoggingEventTypes eventInfo, EventSourceOptions& options, EventDescriptor& descriptor) {
  NameInfo nameInfo = nullptr;
  Int32 traceloggingId = 0;
  Byte level = ((options.valuesSet & 4) != 0) ? options.level : eventInfo->level;
  Byte opcode = ((options.valuesSet & 8) != 0) ? options.opcode : eventInfo->opcode;
  EventTags tags = ((options.valuesSet & 2) != 0) ? options.tags : eventInfo->get_Tags();
  EventKeywords keywords = ((options.valuesSet & 1) != 0) ? options.keywords : eventInfo->keywords;
  if (IsEnabled((EventLevel)level, keywords)) {
    String as = name;
    nameInfo = eventInfo->GetNameInfo(as != nullptr ? as : eventInfo->get_Name(), tags);
    traceloggingId = nameInfo->identity;
  }
  descriptor = EventDescriptor(traceloggingId, level, opcode, (Int64)keywords);
  return nameInfo;
}

void EventSource___::cctor() {
  IsSupported = InitializeIsSupported();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceNamespace
