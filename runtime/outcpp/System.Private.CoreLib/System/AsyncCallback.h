#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncResult)
FORWARD(Object)
namespace AsyncCallbackNamespace {
CLASS(AsyncCallback) {
  public: void Invoke(IAsyncResult ar);
  public: IAsyncResult BeginInvoke(IAsyncResult ar, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace AsyncCallbackNamespace
using AsyncCallback = AsyncCallbackNamespace::AsyncCallback;
} // namespace System::Private::CoreLib::System
