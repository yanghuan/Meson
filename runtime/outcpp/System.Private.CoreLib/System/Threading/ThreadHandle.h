#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Threading {
namespace ThreadHandleNamespace {
struct ThreadHandle {
  private: IntPtr _ptr;
};
} // namespace ThreadHandleNamespace
using ThreadHandle = ThreadHandleNamespace::ThreadHandle;
} // namespace System::Private::CoreLib::System::Threading
