#include "ThreadHandle-dep.h"

namespace System::Private::CoreLib::System::Threading::ThreadHandleNamespace {
ThreadHandle::ThreadHandle(IntPtr pThread) {
  _ptr = pThread;
}

} // namespace System::Private::CoreLib::System::Threading::ThreadHandleNamespace
