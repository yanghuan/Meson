#include "SafeHandleZeroOrMinusOneIsInvalid-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeHandleZeroOrMinusOneIsInvalidNamespace {
using namespace System;

Boolean SafeHandleZeroOrMinusOneIsInvalid___::get_IsInvalid() {
  if (!(handle == IntPtr::Zero)) {
    return handle == IntPtr((Int32)-1);
  }
  return true;
}

void SafeHandleZeroOrMinusOneIsInvalid___::ctor(Boolean ownsHandle) {
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeHandleZeroOrMinusOneIsInvalidNamespace
