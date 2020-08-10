#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/ConstrainedExecution/CriticalFinalizerObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
namespace RegisteredWaitHandleSafeNamespace {
using namespace Runtime::ConstrainedExecution;
using namespace Runtime::InteropServices;
CLASS(RegisteredWaitHandleSafe) : public CriticalFinalizerObject::in {
  private: static IntPtr get_InvalidHandle();
  public: IntPtr GetHandle();
  public: void SetHandle(IntPtr handle);
  public: void SetWaitObject(WaitHandle waitObject);
  public: Boolean Unregister(WaitHandle waitObject);
  private: Boolean ValidHandle();
  protected: void Finalize();
  private: static void WaitHandleCleanupNative(IntPtr handle);
  private: static Boolean UnregisterWaitNative(IntPtr handle, SafeHandle waitObject);
  public: void ctor();
  private: IntPtr registeredWaitHandle;
  private: WaitHandle m_internalWaitObject;
  private: Boolean bReleaseNeeded;
  private: Int32 m_lock;
};
} // namespace RegisteredWaitHandleSafeNamespace
using RegisteredWaitHandleSafe = RegisteredWaitHandleSafeNamespace::RegisteredWaitHandleSafe;
} // namespace System::Private::CoreLib::System::Threading
