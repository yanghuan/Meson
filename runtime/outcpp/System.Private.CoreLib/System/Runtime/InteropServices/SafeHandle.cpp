#include "SafeHandle-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

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
  do {
    state = _state;
    if (((UInt32)state & (true ? 1u : 0u)) != 0) {
      rt::throw_exception<ObjectDisposedException>("SafeHandle", SR::get_ObjectDisposed_SafeHandleClosed());
    }
    value = state + 4;
  } while (Interlocked::CompareExchange(_state, value, state) != state);
  success = true;
}

void SafeHandle___::DangerousRelease() {
  InternalRelease(false);
}

void SafeHandle___::InternalRelease(Boolean disposeOrFinalizeOperation) {
  Boolean flag = false;
  Int32 state;
  Int32 num;
  do {
    state = _state;
    if (disposeOrFinalizeOperation && ((UInt32)state & 2u) != 0) {
      return;
    }
    if ((state & -4) == 0) {
      rt::throw_exception<ObjectDisposedException>("SafeHandle", SR::get_ObjectDisposed_SafeHandleClosed());
    }
    flag = (state & -3) == 4 && _ownsHandle && !get_IsInvalid();
    num = state - 4;
    if ((state & -4) == 4) {
      num |= 1;
    }
    if (disposeOrFinalizeOperation) {
      num |= 2;
    }
  } while (Interlocked::CompareExchange(_state, num, state) != state);
  if (flag) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    ReleaseHandle();
    Marshal::SetLastWin32Error(lastWin32Error);
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeHandleNamespace
