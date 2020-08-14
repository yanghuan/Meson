#include "RegisteredWaitHandleSafe-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Threading::RegisteredWaitHandleSafeNamespace {
IntPtr RegisteredWaitHandleSafe___::get_InvalidHandle() {
  return IntPtr(-1);
}

IntPtr RegisteredWaitHandleSafe___::GetHandle() {
  return registeredWaitHandle;
}

void RegisteredWaitHandleSafe___::SetHandle(IntPtr handle) {
  registeredWaitHandle = handle;
}

void RegisteredWaitHandleSafe___::SetWaitObject(WaitHandle waitObject) {
  m_internalWaitObject = waitObject;
  if (waitObject != nullptr) {
    m_internalWaitObject->get_SafeWaitHandle()->DangerousAddRef(bReleaseNeeded);
  }
}

Boolean RegisteredWaitHandleSafe___::Unregister(WaitHandle waitObject) {
  Boolean flag = false;
  Boolean flag2 = false;
}

Boolean RegisteredWaitHandleSafe___::ValidHandle() {
  if (registeredWaitHandle != get_InvalidHandle()) {
    return registeredWaitHandle != IntPtr::Zero;
  }
  return false;
}

void RegisteredWaitHandleSafe___::Finalize() {
  if (Interlocked::CompareExchange(m_lock, 1, 0) != 0) {
    return;
  }
  try{
    if (ValidHandle()) {
      WaitHandleCleanupNative(registeredWaitHandle);
      if (bReleaseNeeded) {
        m_internalWaitObject->get_SafeWaitHandle()->DangerousRelease();
        bReleaseNeeded = false;
      }
      SetHandle(get_InvalidHandle());
      m_internalWaitObject = nullptr;
    }
  } finally: {
    m_lock = 0;
  }
}

void RegisteredWaitHandleSafe___::ctor() {
  registeredWaitHandle = get_InvalidHandle();
}

} // namespace System::Private::CoreLib::System::Threading::RegisteredWaitHandleSafeNamespace
