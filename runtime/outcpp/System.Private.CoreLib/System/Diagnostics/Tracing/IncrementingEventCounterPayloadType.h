#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IncrementingCounterPayload)
namespace IncrementingEventCounterPayloadTypeNamespace {
CLASS(IncrementingEventCounterPayloadType) {
  public: IncrementingCounterPayload get_Payload() { return Payload; }
  public: void set_Payload(IncrementingCounterPayload value) { Payload = value; }
  public: void Ctor(IncrementingCounterPayload payload);
  private: IncrementingCounterPayload Payload;
};
} // namespace IncrementingEventCounterPayloadTypeNamespace
using IncrementingEventCounterPayloadType = IncrementingEventCounterPayloadTypeNamespace::IncrementingEventCounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
