#pragma once

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
namespace SafeRegistryHandleNamespace {
using namespace Microsoft::Win32::SafeHandles;
using namespace System;
CLASS(SafeRegistryHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  public: void ctor();
  public: void ctor(IntPtr preexistingHandle, Boolean ownsHandle);
  protected: Boolean ReleaseHandle();
};
} // namespace SafeRegistryHandleNamespace
using SafeRegistryHandle = SafeRegistryHandleNamespace::SafeRegistryHandle;
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
