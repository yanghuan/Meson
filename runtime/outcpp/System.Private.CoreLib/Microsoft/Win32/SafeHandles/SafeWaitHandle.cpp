#include "SafeWaitHandle-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandleNamespace {
void SafeWaitHandle___::ctor() {
}

void SafeWaitHandle___::ctor(IntPtr existingHandle, Boolean ownsHandle) {
  SetHandle(existingHandle);
}

Boolean SafeWaitHandle___::ReleaseHandle() {
  return Interop::Kernel32::CloseHandle(handle);
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandleNamespace
