#pragma once

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeWaitHandleNamespace {
using namespace System;
CLASS(SafeWaitHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  public: void ctor();
  public: void ctor(IntPtr existingHandle, Boolean ownsHandle);
  protected: Boolean ReleaseHandle();
};
} // namespace SafeWaitHandleNamespace
using SafeWaitHandle = SafeWaitHandleNamespace::SafeWaitHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
