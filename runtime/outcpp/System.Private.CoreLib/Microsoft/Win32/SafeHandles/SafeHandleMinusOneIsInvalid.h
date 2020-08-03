#pragma once

#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeHandleMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(SafeHandleMinusOneIsInvalid) : public SafeHandle::in {
  public: Boolean get_IsInvalid();
  protected: void Ctor(Boolean ownsHandle);
};
} // namespace SafeHandleMinusOneIsInvalidNamespace
using SafeHandleMinusOneIsInvalid = SafeHandleMinusOneIsInvalidNamespace::SafeHandleMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
