#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
namespace WaitHandleExtensionsNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
class WaitHandleExtensions {
  public: static SafeWaitHandle GetSafeWaitHandle(WaitHandle waitHandle);
  public: static void SetSafeWaitHandle(WaitHandle waitHandle, SafeWaitHandle value);
};
} // namespace WaitHandleExtensionsNamespace
using WaitHandleExtensions = WaitHandleExtensionsNamespace::WaitHandleExtensions;
} // namespace System::Private::CoreLib::System::Threading
