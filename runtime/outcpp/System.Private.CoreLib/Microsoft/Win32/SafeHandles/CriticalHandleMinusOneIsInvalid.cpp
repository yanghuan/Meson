#include "CriticalHandleMinusOneIsInvalid-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::CriticalHandleMinusOneIsInvalidNamespace {
using namespace System;

Boolean CriticalHandleMinusOneIsInvalid___::get_IsInvalid() {
  return handle == IntPtr((Int32)-1);
}

void CriticalHandleMinusOneIsInvalid___::ctor() {
}

} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles::CriticalHandleMinusOneIsInvalidNamespace
