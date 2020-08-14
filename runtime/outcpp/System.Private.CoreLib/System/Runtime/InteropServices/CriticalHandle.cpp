#include "CriticalHandle-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CriticalHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CriticalHandleNamespace {
Boolean CriticalHandle___::get_IsClosed() {
  return _isClosed;
}

void CriticalHandle___::ctor(IntPtr invalidHandleValue) {
  handle = invalidHandleValue;
}

void CriticalHandle___::Finalize() {
  Dispose(false);
}

void CriticalHandle___::Cleanup() {
  if (!get_IsClosed()) {
    _isClosed = true;
    if (!get_IsInvalid()) {
      Int32 lastWin32Error = Marshal::GetLastWin32Error();
      ReleaseHandle();
      Marshal::SetLastWin32Error(lastWin32Error);
      GC::SuppressFinalize((CriticalHandle)this);
    }
  }
}

void CriticalHandle___::SetHandle(IntPtr handle) {
  this->handle = handle;
}

void CriticalHandle___::Close() {
  Dispose(true);
}

void CriticalHandle___::Dispose() {
  Dispose(true);
}

void CriticalHandle___::Dispose(Boolean disposing) {
  Cleanup();
}

void CriticalHandle___::SetHandleAsInvalid() {
  _isClosed = true;
  GC::SuppressFinalize((CriticalHandle)this);
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CriticalHandleNamespace
