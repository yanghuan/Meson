#pragma once

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeFindHandleNamespace {
using namespace System;
CLASS(SafeFindHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  public: void ctor();
  protected: Boolean ReleaseHandle();
};
} // namespace SafeFindHandleNamespace
using SafeFindHandle = SafeFindHandleNamespace::SafeFindHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
