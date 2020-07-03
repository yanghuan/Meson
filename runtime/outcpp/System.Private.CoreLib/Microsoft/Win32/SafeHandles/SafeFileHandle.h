#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadPoolBoundHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeFileHandleNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(SafeFileHandle) {
  public: Nullable<Boolean> get_IsAsync();
  public: void set_IsAsync(Nullable<Boolean> value);
  protected: Boolean ReleaseHandle();
  private: Nullable<Boolean> _isAsync;
  private: ThreadPoolBoundHandle ThreadPoolBinding;
};
} // namespace SafeFileHandleNamespace
using SafeFileHandle = SafeFileHandleNamespace::SafeFileHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
