#include "EventPipeMetadataGenerator-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EmptyStruct-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventOpcode.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeMetadataGenerator-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeMetadataGeneratorNamespace {
using namespace System::Reflection;

void EventPipeMetadataGenerator___::ctor() {
}

Array<Byte> EventPipeMetadataGenerator___::GenerateEventMetadata(EventSource::in::EventMetadata eventMetadata) {
  Array<ParameterInfo> parameters = eventMetadata.Parameters;
  Array<EventParameterInfo> array = rt::newarr<Array<EventParameterInfo>>(parameters->get_Length());
  for (Int32 i = 0; i < parameters->get_Length(); i++) {
    TraceLoggingTypeInfo typeInfo;
    EventParameterInfo::GetTypeInfoFromType(parameters[i]->get_ParameterType(), typeInfo);
    array[i].SetInfo(parameters[i]->get_Name(), parameters[i]->get_ParameterType(), typeInfo);
  }
  return GenerateMetadata(eventMetadata.Descriptor.get_EventId(), eventMetadata.Name, eventMetadata.Descriptor.get_Keywords(), eventMetadata.Descriptor.get_Level(), eventMetadata.Descriptor.get_Version(), (EventOpcode)eventMetadata.Descriptor.get_Opcode(), array);
}

Array<Byte> EventPipeMetadataGenerator___::GenerateEventMetadata(Int32 eventId, String eventName, EventKeywords keywords, EventLevel level, UInt32 version, EventOpcode opcode, TraceLoggingEventTypes eventTypes) {
  Array<TraceLoggingTypeInfo> typeInfos = eventTypes->typeInfos;
  Array<String> paramNames = eventTypes->paramNames;
  Array<EventParameterInfo> array = rt::newarr<Array<EventParameterInfo>>(typeInfos->get_Length());
  for (Int32 i = 0; i < typeInfos->get_Length(); i++) {
    String name = String::in::Empty;
    if (paramNames != nullptr) {
      name = paramNames[i];
    }
    array[i].SetInfo(name, typeInfos[i]->get_DataType(), typeInfos[i]);
  }
  return GenerateMetadata(eventId, eventName, (Int64)keywords, (UInt32)level, version, opcode, array);
}

Array<Byte> EventPipeMetadataGenerator___::GenerateMetadata(Int32 eventId, String eventName, Int64 keywords, UInt32 level, UInt32 version, EventOpcode opcode, Array<EventParameterInfo> parameters) {
  Array<Byte> array = nullptr;
  Boolean flag = false;
  try {
    UInt32 num = (UInt32)(24 + (eventName->get_Length() + 1) * 2);
    UInt32 num2 = 0u;
    UInt32 num3 = num;
    if (parameters->get_Length() == 1 && parameters[0].ParameterType == rt::typeof<EmptyStruct>()) {
      parameters = Array<>::in::Empty<EventParameterInfo>();
    }
    Array<EventParameterInfo> array2 = parameters;
  } catch (...) {
  }
}

void EventPipeMetadataGenerator___::WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Byte* src, UInt32 srcLength) {
  for (Int32 i = 0; i < srcLength; i++) {
    (buffer + offset)[i] = src[i];
  }
  offset += srcLength;
}

void EventPipeMetadataGenerator___::cctor() {
  Instance = rt::newobj<EventPipeMetadataGenerator>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeMetadataGeneratorNamespace
