#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IncrementingCounterPayload)
namespace IncrementingPollingCounterPayloadTypeNamespace {
CLASS(IncrementingPollingCounterPayloadType) : public Object::in {
  public: IncrementingCounterPayload get_Payload() { return Payload; }
  public: void set_Payload(IncrementingCounterPayload value) { Payload = value; }
  public: void Ctor(IncrementingCounterPayload payload);
  private: IncrementingCounterPayload Payload;
};
} // namespace IncrementingPollingCounterPayloadTypeNamespace
using IncrementingPollingCounterPayloadType = IncrementingPollingCounterPayloadTypeNamespace::IncrementingPollingCounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
