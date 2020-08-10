#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace WaitCallbackNamespace {
CLASS(WaitCallback) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object state);
  public: IAsyncResult BeginInvoke(Object state, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace WaitCallbackNamespace
using WaitCallback = WaitCallbackNamespace::WaitCallback;
} // namespace System::Private::CoreLib::System::Threading
