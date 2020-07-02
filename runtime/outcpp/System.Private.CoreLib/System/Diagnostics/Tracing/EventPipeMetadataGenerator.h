#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(Int64)
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventLevel;
FORWARD(TraceLoggingEventTypes)
FORWARDS(EventParameterInfo)
namespace EventPipeMetadataGeneratorNamespace {
CLASS(EventPipeMetadataGenerator) {
  public: Array<Byte> GenerateEventMetadata(EventSource::in::EventMetadata eventMetadata);
  public: Array<Byte> GenerateEventMetadata(Int32 eventId, String eventName, EventKeywords keywords, EventLevel level, UInt32 version, TraceLoggingEventTypes eventTypes);
  private: Array<Byte> GenerateMetadata(Int32 eventId, String eventName, Int64 keywords, UInt32 level, UInt32 version, Array<EventParameterInfo> parameters);
  public: static void WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Byte* src, UInt32 srcLength);
  public: static void WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, UInt32 value);
  public: static void WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Int64 value);
  public: static void WriteToBuffer(Byte* buffer, UInt32 bufferLength, UInt32& offset, Char value);
  public: static EventPipeMetadataGenerator Instance;
};
} // namespace EventPipeMetadataGeneratorNamespace
using EventPipeMetadataGenerator = EventPipeMetadataGeneratorNamespace::EventPipeMetadataGenerator;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
