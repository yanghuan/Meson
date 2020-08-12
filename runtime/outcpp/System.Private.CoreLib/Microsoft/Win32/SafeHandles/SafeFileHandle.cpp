#include "SafeFileHandle-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandleNamespace {
Nullable<Boolean> SafeFileHandle___::get_IsAsync() {
  return _isAsync;
}

void SafeFileHandle___::set_IsAsync(Nullable<Boolean> value) {
  _isAsync = value;
}

void SafeFileHandle___::ctor() {
  _isAsync = nullptr;
}

void SafeFileHandle___::ctor(IntPtr preexistingHandle, Boolean ownsHandle) {
  SetHandle(preexistingHandle);
  _isAsync = nullptr;
}

Boolean SafeFileHandle___::ReleaseHandle() {
  return Interop::Kernel32::CloseHandle(handle);
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandleNamespace
