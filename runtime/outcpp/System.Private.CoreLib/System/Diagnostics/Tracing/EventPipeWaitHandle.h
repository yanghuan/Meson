#pragma once

#include <System.Private.CoreLib/System/Threading/WaitHandle.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeWaitHandleNamespace {
using namespace System::Threading;
CLASS(EventPipeWaitHandle) : public WaitHandle::in {
  public: void ctor();
};
} // namespace EventPipeWaitHandleNamespace
using EventPipeWaitHandle = EventPipeWaitHandleNamespace::EventPipeWaitHandle;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
