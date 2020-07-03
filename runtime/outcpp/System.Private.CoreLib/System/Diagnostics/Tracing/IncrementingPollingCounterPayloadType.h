#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IncrementingCounterPayload)
namespace IncrementingPollingCounterPayloadTypeNamespace {
CLASS(IncrementingPollingCounterPayloadType) {
  private: IncrementingCounterPayload Payload;
};
} // namespace IncrementingPollingCounterPayloadTypeNamespace
using IncrementingPollingCounterPayloadType = IncrementingPollingCounterPayloadTypeNamespace::IncrementingPollingCounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
