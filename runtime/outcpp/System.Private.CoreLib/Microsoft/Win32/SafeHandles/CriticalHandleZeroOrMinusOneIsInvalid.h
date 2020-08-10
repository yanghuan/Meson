#pragma once

#include <System.Private.CoreLib/System/Runtime/InteropServices/CriticalHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace CriticalHandleZeroOrMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(CriticalHandleZeroOrMinusOneIsInvalid) : public CriticalHandle::in {
  public: Boolean get_IsInvalid();
  protected: void ctor();
};
} // namespace CriticalHandleZeroOrMinusOneIsInvalidNamespace
using CriticalHandleZeroOrMinusOneIsInvalid = CriticalHandleZeroOrMinusOneIsInvalidNamespace::CriticalHandleZeroOrMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
