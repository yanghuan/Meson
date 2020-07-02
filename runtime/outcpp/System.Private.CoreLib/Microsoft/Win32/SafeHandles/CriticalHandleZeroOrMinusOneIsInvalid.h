#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace CriticalHandleZeroOrMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(CriticalHandleZeroOrMinusOneIsInvalid) {
  public: Boolean get_IsInvalid();
};
} // namespace CriticalHandleZeroOrMinusOneIsInvalidNamespace
using CriticalHandleZeroOrMinusOneIsInvalid = CriticalHandleZeroOrMinusOneIsInvalidNamespace::CriticalHandleZeroOrMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
