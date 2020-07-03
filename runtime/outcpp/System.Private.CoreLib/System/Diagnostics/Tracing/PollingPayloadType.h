#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterPayload)
namespace PollingPayloadTypeNamespace {
CLASS(PollingPayloadType) {
  private: CounterPayload Payload;
};
} // namespace PollingPayloadTypeNamespace
using PollingPayloadType = PollingPayloadTypeNamespace::PollingPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
