#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterPayload)
namespace CounterPayloadTypeNamespace {
CLASS(CounterPayloadType) {
  private: CounterPayload Payload;
};
} // namespace CounterPayloadTypeNamespace
using CounterPayloadType = CounterPayloadTypeNamespace::CounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
