#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARDS(Byte)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipePayloadDecoderNamespace {
class EventPipePayloadDecoder {
  public: static Array<Object> DecodePayload(EventSource::in::EventMetadata& metadata, ReadOnlySpan<Byte> payload);
};
} // namespace EventPipePayloadDecoderNamespace
using EventPipePayloadDecoder = EventPipePayloadDecoderNamespace::EventPipePayloadDecoder;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
