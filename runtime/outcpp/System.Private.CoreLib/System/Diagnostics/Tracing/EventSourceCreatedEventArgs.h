#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
namespace EventSourceCreatedEventArgsNamespace {
CLASS(EventSourceCreatedEventArgs) {
  private: EventSource EventSource;
};
} // namespace EventSourceCreatedEventArgsNamespace
using EventSourceCreatedEventArgs = EventSourceCreatedEventArgsNamespace::EventSourceCreatedEventArgs;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
