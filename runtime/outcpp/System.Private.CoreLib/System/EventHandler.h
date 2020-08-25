#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(EventArgs)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace EventHandlerNamespace {
CLASS_FORWARD(EventHandler, T1, T2)
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
template <class T1 = void, class T2 = void>
using EventHandler = EventHandlerNamespace::EventHandler<T1, T2>;
} // namespace System::Private::CoreLib::System
