#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterPayload)
namespace PollingPayloadTypeNamespace {
CLASS(PollingPayloadType) : public Object::in {
  public: CounterPayload get_Payload() { return Payload; }
  public: void set_Payload(CounterPayload value) { Payload = value; }
  public: void ctor(CounterPayload payload);
  private: CounterPayload Payload;
};
} // namespace PollingPayloadTypeNamespace
using PollingPayloadType = PollingPayloadTypeNamespace::PollingPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
