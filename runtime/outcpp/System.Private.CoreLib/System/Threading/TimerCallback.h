#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace TimerCallbackNamespace {
CLASS(TimerCallback) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: void Invoke(Object state);
  public: IAsyncResult BeginInvoke(Object state, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace TimerCallbackNamespace
using TimerCallback = TimerCallbackNamespace::TimerCallback;
} // namespace System::Private::CoreLib::System::Threading
