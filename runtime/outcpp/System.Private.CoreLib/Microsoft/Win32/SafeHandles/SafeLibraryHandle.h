#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeLibraryHandleNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeLibraryHandle) {
  protected: Boolean ReleaseHandle();
};
} // namespace SafeLibraryHandleNamespace
using SafeLibraryHandle = SafeLibraryHandleNamespace::SafeLibraryHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
