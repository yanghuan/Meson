#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventPipeConfiguration)
namespace EventPipeNamespace {
class EventPipe {
  public: static void Enable(EventPipeConfiguration configuration);
  public: static void Disable();
  private: static UInt64 s_sessionID;
};
} // namespace EventPipeNamespace
using EventPipe = EventPipeNamespace::EventPipe;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
