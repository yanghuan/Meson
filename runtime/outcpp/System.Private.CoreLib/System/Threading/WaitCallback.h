#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace WaitCallbackNamespace {
CLASS(WaitCallback) {
  public: void Invoke(Object state);
  public: IAsyncResult BeginInvoke(Object state, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace WaitCallbackNamespace
using WaitCallback = WaitCallbackNamespace::WaitCallback;
} // namespace System::Private::CoreLib::System::Threading