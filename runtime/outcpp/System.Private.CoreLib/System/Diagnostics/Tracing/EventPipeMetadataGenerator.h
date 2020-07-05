#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventLevel;
enum class EventOpcode;
FORWARDS(EventParameterInfo)
FORWARD(TraceLoggingEventTypes)
namespace EventPipeMetadataGeneratorNamespace {
CLASS(EventPipeMetadataGenerator) {
  private: enum class MetadataTag {
    Opcode = 1,
    ParameterPayload = 2,
  };
  public: Array<Byte> GenerateEventMetadata(EventSource::in::EventMetadata eventMetadata);
  public: Array<Byte> GenerateEventMetadata(Int32 eventId, String eventName, EventKeywords keywords, EventLevel level, UInt32 version, EventOpcode opcode, TraceLoggingEventTypes eventTypes);
  public: Array<Byte> GenerateMetadata(Int32 eventId, String eventName, Int64 keywords, UInt32 level, UInt32 version, EventOpcode opcode, Array<EventParameterInfo> parameters);
  public: static void WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Byte* src, UInt32 srcLength);
  public: static EventPipeMetadataGenerator Instance;
};
} // namespace EventPipeMetadataGeneratorNamespace
using EventPipeMetadataGenerator = EventPipeMetadataGeneratorNamespace::EventPipeMetadataGenerator;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
