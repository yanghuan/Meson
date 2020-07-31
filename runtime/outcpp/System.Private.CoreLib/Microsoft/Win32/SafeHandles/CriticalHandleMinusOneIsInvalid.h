#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CriticalHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace CriticalHandleMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(CriticalHandleMinusOneIsInvalid) : public CriticalHandle::in {
  public: Boolean get_IsInvalid();
  protected: void Ctor();
};
} // namespace CriticalHandleMinusOneIsInvalidNamespace
using CriticalHandleMinusOneIsInvalid = CriticalHandleMinusOneIsInvalidNamespace::CriticalHandleMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
