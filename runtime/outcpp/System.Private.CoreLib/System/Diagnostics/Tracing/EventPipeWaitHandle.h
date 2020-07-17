#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeWaitHandleNamespace {
CLASS(EventPipeWaitHandle) {
  public: void Ctor();
};
} // namespace EventPipeWaitHandleNamespace
using EventPipeWaitHandle = EventPipeWaitHandleNamespace::EventPipeWaitHandle;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
