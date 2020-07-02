#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace WindowsFoundationEventHandlerNamespace {
CLASS(WindowsFoundationEventHandler, T) {
  public: void Invoke(Object sender, T args);
  public: IAsyncResult BeginInvoke(Object sender, T args, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace WindowsFoundationEventHandlerNamespace
template <class T>
using WindowsFoundationEventHandler = WindowsFoundationEventHandlerNamespace::WindowsFoundationEventHandler<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
