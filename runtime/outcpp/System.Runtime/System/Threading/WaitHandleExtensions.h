#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Runtime::System::Threading {
namespace WaitHandleExtensionsNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
using namespace ::System::Private::CoreLib::System::Threading;
class WaitHandleExtensions {
  public: static SafeWaitHandle GetSafeWaitHandle(WaitHandle waitHandle);
  public: static void SetSafeWaitHandle(WaitHandle waitHandle, SafeWaitHandle value);
};
} // namespace WaitHandleExtensionsNamespace
using WaitHandleExtensions = WaitHandleExtensionsNamespace::WaitHandleExtensions;
} // namespace System::Runtime::System::Threading
