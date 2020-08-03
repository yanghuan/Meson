#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(NativeOverlapped)
namespace IOCompletionCallbackNamespace {
CLASS(IOCompletionCallback) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: void Invoke(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP);
  public: IAsyncResult BeginInvoke(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace IOCompletionCallbackNamespace
using IOCompletionCallback = IOCompletionCallbackNamespace::IOCompletionCallback;
} // namespace System::Private::CoreLib::System::Threading
