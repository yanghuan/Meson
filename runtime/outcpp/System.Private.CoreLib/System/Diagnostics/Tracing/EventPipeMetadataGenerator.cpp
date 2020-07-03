#include "EventPipeMetadataGenerator-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeMetadataGeneratorNamespace {
Array<Byte> EventPipeMetadataGenerator___::GenerateEventMetadata(EventSource::in::EventMetadata eventMetadata) {
  return Array<Byte>();
};
Array<Byte> EventPipeMetadataGenerator___::GenerateEventMetadata(Int32 eventId, String eventName, EventKeywords keywords, EventLevel level, UInt32 version, TraceLoggingEventTypes eventTypes) {
  return Array<Byte>();
};
Array<Byte> EventPipeMetadataGenerator___::GenerateMetadata(Int32 eventId, String eventName, Int64 keywords, UInt32 level, UInt32 version, Array<EventParameterInfo> parameters) {
  return Array<Byte>();
};
void EventPipeMetadataGenerator___::WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Byte* src, UInt32 srcLength) {
};
void EventPipeMetadataGenerator___::WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, UInt32 value) {
};
void EventPipeMetadataGenerator___::WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Int64 value) {
};
void EventPipeMetadataGenerator___::WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Char value) {
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeMetadataGeneratorNamespace
