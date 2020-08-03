#pragma once

#include <System.Private.CoreLib/System/Threading/EventWaitHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace AutoResetEventNamespace {
CLASS(AutoResetEvent) : public EventWaitHandle::in {
  public: void Ctor(Boolean initialState);
};
} // namespace AutoResetEventNamespace
using AutoResetEvent = AutoResetEventNamespace::AutoResetEvent;
} // namespace System::Private::CoreLib::System::Threading
