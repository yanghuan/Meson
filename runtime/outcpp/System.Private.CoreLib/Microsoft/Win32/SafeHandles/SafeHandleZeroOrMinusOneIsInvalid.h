#pragma once

#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeHandleZeroOrMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(SafeHandleZeroOrMinusOneIsInvalid) : public SafeHandle::in {
  public: Boolean get_IsInvalid();
  protected: void ctor(Boolean ownsHandle);
};
} // namespace SafeHandleZeroOrMinusOneIsInvalidNamespace
using SafeHandleZeroOrMinusOneIsInvalid = SafeHandleZeroOrMinusOneIsInvalidNamespace::SafeHandleZeroOrMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
