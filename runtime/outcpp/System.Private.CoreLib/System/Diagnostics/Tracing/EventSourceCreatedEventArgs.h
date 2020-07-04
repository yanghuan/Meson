#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
namespace EventSourceCreatedEventArgsNamespace {
CLASS(EventSourceCreatedEventArgs) {
  public: EventSource get_EventSource() { return EventSource; }
  public: void set_EventSource(EventSource value) { EventSource = value; }
  private: EventSource EventSource;
};
} // namespace EventSourceCreatedEventArgsNamespace
using EventSourceCreatedEventArgs = EventSourceCreatedEventArgsNamespace::EventSourceCreatedEventArgs;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
