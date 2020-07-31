#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventPipeConfiguration)
namespace EventPipeNamespace {
class EventPipe : public Object::in {
  public: static void Enable(EventPipeConfiguration configuration);
  public: static void Disable();
  private: static UInt64 s_sessionID;
};
} // namespace EventPipeNamespace
using EventPipe = EventPipeNamespace::EventPipe;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
