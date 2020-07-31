#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterPayload)
namespace CounterPayloadTypeNamespace {
CLASS(CounterPayloadType) : public Object::in {
  public: CounterPayload get_Payload() { return Payload; }
  public: void set_Payload(CounterPayload value) { Payload = value; }
  public: void Ctor(CounterPayload payload);
  private: CounterPayload Payload;
};
} // namespace CounterPayloadTypeNamespace
using CounterPayloadType = CounterPayloadTypeNamespace::CounterPayloadType;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
