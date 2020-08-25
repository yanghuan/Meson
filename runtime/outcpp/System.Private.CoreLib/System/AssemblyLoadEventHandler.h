#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AssemblyLoadEventArgs)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace AssemblyLoadEventHandlerNamespace {
CLASS(AssemblyLoadEventHandler) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object sender, AssemblyLoadEventArgs args);
  public: IAsyncResult BeginInvoke(Object sender, AssemblyLoadEventArgs args, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace AssemblyLoadEventHandlerNamespace
using AssemblyLoadEventHandler = AssemblyLoadEventHandlerNamespace::AssemblyLoadEventHandler;
} // namespace System::Private::CoreLib::System
