#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(ResolveEventArgs)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
namespace ModuleResolveEventHandlerNamespace {
CLASS(ModuleResolveEventHandler) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: Module Invoke(Object sender, ResolveEventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, ResolveEventArgs e, AsyncCallback callback, Object object);
  public: Module EndInvoke(IAsyncResult result);
};
} // namespace ModuleResolveEventHandlerNamespace
using ModuleResolveEventHandler = ModuleResolveEventHandlerNamespace::ModuleResolveEventHandler;
} // namespace System::Private::CoreLib::System::Reflection
