#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeWaitHandleNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeWaitHandle) {
  protected: Boolean ReleaseHandle();
};
} // namespace SafeWaitHandleNamespace
using SafeWaitHandle = SafeWaitHandleNamespace::SafeWaitHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
