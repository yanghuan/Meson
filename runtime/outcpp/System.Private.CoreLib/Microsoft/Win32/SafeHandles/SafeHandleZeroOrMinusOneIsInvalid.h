#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeHandleZeroOrMinusOneIsInvalidNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeHandleZeroOrMinusOneIsInvalid) {
  public: Boolean get_IsInvalid();
};
} // namespace SafeHandleZeroOrMinusOneIsInvalidNamespace
using SafeHandleZeroOrMinusOneIsInvalid = SafeHandleZeroOrMinusOneIsInvalidNamespace::SafeHandleZeroOrMinusOneIsInvalid;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
