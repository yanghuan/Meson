#pragma once

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadPoolBoundHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
namespace SafeFileHandleNamespace {
using namespace System;
using namespace System::Threading;
CLASS(SafeFileHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  public: Nullable<Boolean> get_IsAsync();
  public: void set_IsAsync(Nullable<Boolean> value);
  public: ThreadPoolBoundHandle get_ThreadPoolBinding() { return ThreadPoolBinding; }
  public: void set_ThreadPoolBinding(ThreadPoolBoundHandle value) { ThreadPoolBinding = value; }
  public: void ctor();
  public: void ctor(IntPtr preexistingHandle, Boolean ownsHandle);
  protected: Boolean ReleaseHandle();
  private: Nullable<Boolean> _isAsync;
  private: ThreadPoolBoundHandle ThreadPoolBinding;
};
} // namespace SafeFileHandleNamespace
using SafeFileHandle = SafeFileHandleNamespace::SafeFileHandle;
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
