#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ContextCallbackNamespace {
CLASS_FORWARD(ContextCallback)
CLASS_(ContextCallback) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object state);
  public: IAsyncResult BeginInvoke(Object state, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(ContextCallback, TState) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(TState& state);
  public: IAsyncResult BeginInvoke(TState& state, AsyncCallback callback, Object object);
  public: void EndInvoke(TState& state, IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ContextCallbackNamespace
template <class ...T>
using ContextCallback = ContextCallbackNamespace::ContextCallback<T...>;
} // namespace System::Private::CoreLib::System::Threading
