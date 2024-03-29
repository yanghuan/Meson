#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(ResolveEventArgs)
namespace ResolveEventHandlerNamespace {
using namespace System::Reflection;
CLASS(ResolveEventHandler) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: Assembly Invoke(Object sender, ResolveEventArgs args);
  public: IAsyncResult BeginInvoke(Object sender, ResolveEventArgs args, AsyncCallback callback, Object object);
  public: Assembly EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ResolveEventHandlerNamespace
using ResolveEventHandler = ResolveEventHandlerNamespace::ResolveEventHandler;
} // namespace System::Private::CoreLib::System
