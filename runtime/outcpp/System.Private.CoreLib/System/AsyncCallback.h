#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace AsyncCallbackNamespace {
CLASS(AsyncCallback) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: void Invoke(IAsyncResult ar);
  public: IAsyncResult BeginInvoke(IAsyncResult ar, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace AsyncCallbackNamespace
using AsyncCallback = AsyncCallbackNamespace::AsyncCallback;
} // namespace System::Private::CoreLib::System
