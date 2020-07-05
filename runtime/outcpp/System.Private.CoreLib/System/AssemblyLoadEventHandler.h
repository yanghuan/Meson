#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AssemblyLoadEventArgs)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
namespace AssemblyLoadEventHandlerNamespace {
CLASS(AssemblyLoadEventHandler) {
  public: void Invoke(Object sender, AssemblyLoadEventArgs args);
  public: IAsyncResult BeginInvoke(Object sender, AssemblyLoadEventArgs args, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace AssemblyLoadEventHandlerNamespace
using AssemblyLoadEventHandler = AssemblyLoadEventHandlerNamespace::AssemblyLoadEventHandler;
} // namespace System::Private::CoreLib::System
