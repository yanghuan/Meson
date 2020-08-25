#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterPayload)
namespace CounterPayloadTypeNamespace {
CLASS(CounterPayloadType) : public object {
  public: CounterPayload get_Payload() { return Payload; }
  public: void set_Payload(CounterPayload value) { Payload = value; }
  public: void ctor(CounterPayload payload);
  private: CounterPayload Payload;
};
} // namespace CounterPayloadTypeNamespace
using CounterPayloadType = CounterPayloadTypeNamespace::CounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
