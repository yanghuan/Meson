#include "SafeFindHandle-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeFindHandleNamespace {
void SafeFindHandle___::ctor() {
}

Boolean SafeFindHandle___::ReleaseHandle() {
  return Interop::Kernel32::FindClose(handle);
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeFindHandleNamespace
