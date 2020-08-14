#include "SafeHandle-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeHandle-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeHandleNamespace {
using namespace System::Threading;

Boolean SafeHandle___::get_IsClosed() {
  return (_state & 1) == 1;
}

void SafeHandle___::ctor(IntPtr invalidHandleValue, Boolean ownsHandle) {
  handle = invalidHandleValue;
  _state = 4;
  _ownsHandle = ownsHandle;
  if (!ownsHandle) {
    GC::SuppressFinalize((SafeHandle)this);
  }
  _fullyInitialized = true;
}

void SafeHandle___::Finalize() {
  if (_fullyInitialized) {
    Dispose(false);
  }
}

void SafeHandle___::SetHandle(IntPtr handle) {
  this->handle = handle;
}

IntPtr SafeHandle___::DangerousGetHandle() {
  return handle;
}

void SafeHandle___::Close() {
  Dispose();
}

void SafeHandle___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((SafeHandle)this);
}

void SafeHandle___::Dispose(Boolean disposing) {
  InternalRelease(true);
}

void SafeHandle___::SetHandleAsInvalid() {
  Interlocked::Or(_state, 1);
  GC::SuppressFinalize((SafeHandle)this);
}

void SafeHandle___::DangerousAddRef(Boolean& success) {
  Int32 state;
  Int32 value;
}

void SafeHandle___::DangerousRelease() {
  InternalRelease(false);
}

void SafeHandle___::InternalRelease(Boolean disposeOrFinalizeOperation) {
  Boolean flag = false;
  Int32 state;
  Int32 num;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeHandleNamespace
