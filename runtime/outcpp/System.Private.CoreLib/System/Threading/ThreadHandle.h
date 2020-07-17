#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Threading {
namespace ThreadHandleNamespace {
struct ThreadHandle {
  public: void Ctor(IntPtr pThread);
  public: void Ctor();
  private: IntPtr _ptr;
};
} // namespace ThreadHandleNamespace
using ThreadHandle = ThreadHandleNamespace::ThreadHandle;
} // namespace System::Private::CoreLib::System::Threading
