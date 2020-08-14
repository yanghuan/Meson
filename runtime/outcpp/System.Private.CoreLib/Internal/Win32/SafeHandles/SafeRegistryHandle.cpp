#include "SafeRegistryHandle-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>

namespace System::Private::CoreLib::Internal::Win32::SafeHandles::SafeRegistryHandleNamespace {
void SafeRegistryHandle___::ctor() {
}

void SafeRegistryHandle___::ctor(IntPtr preexistingHandle, Boolean ownsHandle) {
  SetHandle(preexistingHandle);
}

Boolean SafeRegistryHandle___::ReleaseHandle() {
  return Interop::Advapi32::RegCloseKey(handle) == 0;
}

} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles::SafeRegistryHandleNamespace
