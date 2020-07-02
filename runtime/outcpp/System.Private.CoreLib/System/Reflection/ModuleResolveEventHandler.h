#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
FORWARD(ResolveEventArgs)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
namespace ModuleResolveEventHandlerNamespace {
CLASS(ModuleResolveEventHandler) {
  public: Module Invoke(Object sender, ResolveEventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, ResolveEventArgs e, AsyncCallback callback, Object object);
  public: Module EndInvoke(IAsyncResult result);
};
} // namespace ModuleResolveEventHandlerNamespace
using ModuleResolveEventHandler = ModuleResolveEventHandlerNamespace::ModuleResolveEventHandler;
} // namespace System::Private::CoreLib::System::Reflection
