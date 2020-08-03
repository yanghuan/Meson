#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading {
namespace ThreadHandleNamespace {
struct ThreadHandle : public valueType<ThreadHandle> {
  public: explicit ThreadHandle(IntPtr pThread);
  public: explicit ThreadHandle() {}
  private: IntPtr _ptr;
};
} // namespace ThreadHandleNamespace
using ThreadHandle = ThreadHandleNamespace::ThreadHandle;
} // namespace System::Private::CoreLib::System::Threading
