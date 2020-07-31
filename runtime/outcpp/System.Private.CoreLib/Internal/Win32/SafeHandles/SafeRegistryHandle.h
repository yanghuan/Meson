#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
namespace SafeRegistryHandleNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
using namespace ::System::Private::CoreLib::System;
CLASS(SafeRegistryHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  public: void Ctor();
  public: void Ctor(IntPtr preexistingHandle, Boolean ownsHandle);
  protected: Boolean ReleaseHandle();
};
} // namespace SafeRegistryHandleNamespace
using SafeRegistryHandle = SafeRegistryHandleNamespace::SafeRegistryHandle;
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
