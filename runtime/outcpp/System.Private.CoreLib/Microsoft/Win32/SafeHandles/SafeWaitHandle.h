#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeWaitHandleNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeWaitHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  private: void Ctor();
  public: void Ctor(IntPtr existingHandle, Boolean ownsHandle);
  protected: Boolean ReleaseHandle();
};
} // namespace SafeWaitHandleNamespace
using SafeWaitHandle = SafeWaitHandleNamespace::SafeWaitHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
