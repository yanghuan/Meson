#include "SafeHandleMinusOneIsInvalid-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeHandleMinusOneIsInvalidNamespace {
using namespace System;

Boolean SafeHandleMinusOneIsInvalid___::get_IsInvalid() {
  return handle == IntPtr((Int32)-1);
}

void SafeHandleMinusOneIsInvalid___::ctor(Boolean ownsHandle) {
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::SafeHandleMinusOneIsInvalidNamespace
