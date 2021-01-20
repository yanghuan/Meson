#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipePayloadDecoderNamespace {
class EventPipePayloadDecoder {
  public: static Array<Object> DecodePayload(EventSource::in::EventMetadata& metadata, ReadOnlySpan<Byte> payload);
};
} // namespace EventPipePayloadDecoderNamespace
using EventPipePayloadDecoder = EventPipePayloadDecoderNamespace::EventPipePayloadDecoder;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
