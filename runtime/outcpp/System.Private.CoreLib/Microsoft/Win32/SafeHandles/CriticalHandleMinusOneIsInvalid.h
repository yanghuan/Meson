#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace CriticalHandleMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(CriticalHandleMinusOneIsInvalid) {
  public: Boolean get_IsInvalid();
};
} // namespace CriticalHandleMinusOneIsInvalidNamespace
using CriticalHandleMinusOneIsInvalid = CriticalHandleMinusOneIsInvalidNamespace::CriticalHandleMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
