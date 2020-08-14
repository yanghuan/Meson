#include "DependentHandle-dep.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::DependentHandleNamespace {
Boolean DependentHandle::get_IsAllocated() {
  return _handle != IntPtr::Zero;
}

DependentHandle::DependentHandle(Object primary, Object secondary) {
  _handle = nInitialize(primary, secondary);
}

Object DependentHandle::GetPrimary() {
  return nGetPrimary(_handle);
}

Object DependentHandle::GetPrimaryAndSecondary(Object& secondary) {
  return nGetPrimaryAndSecondary(_handle, secondary);
}

void DependentHandle::SetPrimary(Object primary) {
  nSetPrimary(_handle, primary);
}

void DependentHandle::SetSecondary(Object secondary) {
  nSetSecondary(_handle, secondary);
}

void DependentHandle::Free() {
  if (_handle != IntPtr::Zero) {
    IntPtr handle = _handle;
    _handle = IntPtr::Zero;
    nFree(handle);
  }
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::DependentHandleNamespace
