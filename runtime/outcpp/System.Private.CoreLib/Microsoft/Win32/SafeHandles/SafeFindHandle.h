#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeFindHandleNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeFindHandle) {
  protected: Boolean ReleaseHandle();
};
} // namespace SafeFindHandleNamespace
using SafeFindHandle = SafeFindHandleNamespace::SafeFindHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles