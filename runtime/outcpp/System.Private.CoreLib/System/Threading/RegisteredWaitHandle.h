#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
FORWARD(RegisteredWaitHandleSafe)
namespace RegisteredWaitHandleNamespace {
CLASS(RegisteredWaitHandle) {
  public: void SetHandle(IntPtr handle);
  public: void SetWaitObject(WaitHandle waitObject);
  public: Boolean Unregister(WaitHandle waitObject);
  private: RegisteredWaitHandleSafe internalRegisteredWait;
};
} // namespace RegisteredWaitHandleNamespace
using RegisteredWaitHandle = RegisteredWaitHandleNamespace::RegisteredWaitHandle;
} // namespace System::Private::CoreLib::System::Threading
