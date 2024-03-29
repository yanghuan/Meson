#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadExceptionEventArgs)
namespace ThreadExceptionEventHandlerNamespace {
CLASS(ThreadExceptionEventHandler) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object sender, ThreadExceptionEventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, ThreadExceptionEventArgs e, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ThreadExceptionEventHandlerNamespace
using ThreadExceptionEventHandler = ThreadExceptionEventHandlerNamespace::ThreadExceptionEventHandler;
} // namespace System::Private::CoreLib::System::Threading
