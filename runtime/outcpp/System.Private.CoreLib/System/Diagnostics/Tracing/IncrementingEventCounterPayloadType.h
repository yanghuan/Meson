#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IncrementingCounterPayload)
namespace IncrementingEventCounterPayloadTypeNamespace {
CLASS(IncrementingEventCounterPayloadType) {
  private: IncrementingCounterPayload Payload;
};
} // namespace IncrementingEventCounterPayloadTypeNamespace
using IncrementingEventCounterPayloadType = IncrementingEventCounterPayloadTypeNamespace::IncrementingEventCounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
