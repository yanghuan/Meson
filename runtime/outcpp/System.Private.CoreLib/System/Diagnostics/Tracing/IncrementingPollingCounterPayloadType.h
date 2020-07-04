#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IncrementingCounterPayload)
namespace IncrementingPollingCounterPayloadTypeNamespace {
CLASS(IncrementingPollingCounterPayloadType) {
  public: IncrementingCounterPayload get_Payload() { return Payload; }
  public: void set_Payload(IncrementingCounterPayload value) { Payload = value; }
  private: IncrementingCounterPayload Payload;
};
} // namespace IncrementingPollingCounterPayloadTypeNamespace
using IncrementingPollingCounterPayloadType = IncrementingPollingCounterPayloadTypeNamespace::IncrementingPollingCounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
