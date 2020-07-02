#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeFileHandleNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(SafeFileHandle) {
  public: Nullable<Boolean> get_IsAsync();
  public: void set_IsAsync(Nullable<Boolean> value);
  protected: Boolean ReleaseHandle();
  private: Nullable<Boolean> _isAsync;
};
} // namespace SafeFileHandleNamespace
using SafeFileHandle = SafeFileHandleNamespace::SafeFileHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
