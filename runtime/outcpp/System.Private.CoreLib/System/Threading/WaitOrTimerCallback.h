#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace WaitOrTimerCallbackNamespace {
CLASS(WaitOrTimerCallback) {
  public: void Invoke(Object state, Boolean timedOut);
  public: IAsyncResult BeginInvoke(Object state, Boolean timedOut, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace WaitOrTimerCallbackNamespace
using WaitOrTimerCallback = WaitOrTimerCallbackNamespace::WaitOrTimerCallback;
} // namespace System::Private::CoreLib::System::Threading
