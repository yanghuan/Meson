#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipePayloadDecoderNamespace {
class EventPipePayloadDecoder : public Object::in {
  public: static Array<Object> DecodePayload(EventSource::in::EventMetadata& metadata, ReadOnlySpan<Byte> payload);
};
} // namespace EventPipePayloadDecoderNamespace
using EventPipePayloadDecoder = EventPipePayloadDecoderNamespace::EventPipePayloadDecoder;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
