#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace AsyncCallbackNamespace {
CLASS(AsyncCallback) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(IAsyncResult ar);
  public: IAsyncResult BeginInvoke(IAsyncResult ar, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace AsyncCallbackNamespace
using AsyncCallback = AsyncCallbackNamespace::AsyncCallback;
} // namespace System::Private::CoreLib::System
