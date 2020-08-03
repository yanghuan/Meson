#pragma once

#include <System.Private.CoreLib/System/Threading/EventWaitHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ManualResetEventNamespace {
CLASS(ManualResetEvent) : public EventWaitHandle::in {
  public: void Ctor(Boolean initialState);
};
} // namespace ManualResetEventNamespace
using ManualResetEvent = ManualResetEventNamespace::ManualResetEvent;
} // namespace System::Private::CoreLib::System::Threading
