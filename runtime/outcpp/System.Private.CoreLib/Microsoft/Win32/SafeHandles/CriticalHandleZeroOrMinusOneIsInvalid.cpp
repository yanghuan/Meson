#include "CriticalHandleZeroOrMinusOneIsInvalid-dep.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::CriticalHandleZeroOrMinusOneIsInvalidNamespace {
using namespace System;

Boolean CriticalHandleZeroOrMinusOneIsInvalid___::get_IsInvalid() {
  if (!(handle == IntPtr::Zero)) {
    return handle == IntPtr(-1);
  }
  return true;
}

void CriticalHandleZeroOrMinusOneIsInvalid___::ctor() {
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::CriticalHandleZeroOrMinusOneIsInvalidNamespace
