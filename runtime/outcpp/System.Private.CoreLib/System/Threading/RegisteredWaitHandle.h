#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(RegisteredWaitHandleSafe)
FORWARD(WaitHandle)
namespace RegisteredWaitHandleNamespace {
CLASS(RegisteredWaitHandle) : public MarshalByRefObject::in {
  public: void Ctor();
  public: void SetHandle(IntPtr handle);
  public: void SetWaitObject(WaitHandle waitObject);
  public: Boolean Unregister(WaitHandle waitObject);
  private: RegisteredWaitHandleSafe internalRegisteredWait;
};
} // namespace RegisteredWaitHandleNamespace
using RegisteredWaitHandle = RegisteredWaitHandleNamespace::RegisteredWaitHandle;
} // namespace System::Private::CoreLib::System::Threading
