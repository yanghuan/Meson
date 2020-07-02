#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARD(AsyncCallback)
FORWARD(Object)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(NativeOverlapped)
namespace IOCompletionCallbackNamespace {
CLASS(IOCompletionCallback) {
  public: void Invoke(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP);
  public: IAsyncResult BeginInvoke(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace IOCompletionCallbackNamespace
using IOCompletionCallback = IOCompletionCallbackNamespace::IOCompletionCallback;
} // namespace System::Private::CoreLib::System::Threading
