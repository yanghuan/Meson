#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
FORWARD(UnhandledExceptionEventArgs)
namespace UnhandledExceptionEventHandlerNamespace {
CLASS(UnhandledExceptionEventHandler) {
  public: void Invoke(Object sender, UnhandledExceptionEventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, UnhandledExceptionEventArgs e, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace UnhandledExceptionEventHandlerNamespace
using UnhandledExceptionEventHandler = UnhandledExceptionEventHandlerNamespace::UnhandledExceptionEventHandler;
} // namespace System::Private::CoreLib::System
