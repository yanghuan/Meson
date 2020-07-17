#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ThreadStartNamespace {
CLASS(ThreadStart) {
  public: void Ctor(Object object, IntPtr method);
  public: void Invoke();
  public: IAsyncResult BeginInvoke(AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace ThreadStartNamespace
using ThreadStart = ThreadStartNamespace::ThreadStart;
} // namespace System::Private::CoreLib::System::Threading
