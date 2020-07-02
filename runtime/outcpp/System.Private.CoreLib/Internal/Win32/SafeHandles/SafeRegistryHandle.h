#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
namespace SafeRegistryHandleNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeRegistryHandle) {
  protected: Boolean ReleaseHandle();
};
} // namespace SafeRegistryHandleNamespace
using SafeRegistryHandle = SafeRegistryHandleNamespace::SafeRegistryHandle;
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
