#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(AssemblyLoadEventArgs)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
namespace AssemblyLoadEventHandlerNamespace {
CLASS(AssemblyLoadEventHandler) {
  public: void Invoke(Object sender, AssemblyLoadEventArgs args);
  public: IAsyncResult BeginInvoke(Object sender, AssemblyLoadEventArgs args, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace AssemblyLoadEventHandlerNamespace
using AssemblyLoadEventHandler = AssemblyLoadEventHandlerNamespace::AssemblyLoadEventHandler;
} // namespace System::Private::CoreLib::System
