#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(EventArgs)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace EventHandlerNamespace {
CLASS_FORWARD(EventHandler)
CLASS_(EventHandler) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object sender, EventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, EventArgs e, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(EventHandler, TEventArgs) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object sender, TEventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, TEventArgs e, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace EventHandlerNamespace
template <class ...T>
using EventHandler = EventHandlerNamespace::EventHandler<T...>;
} // namespace System::Private::CoreLib::System
