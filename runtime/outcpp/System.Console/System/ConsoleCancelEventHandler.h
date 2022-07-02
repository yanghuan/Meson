#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Console::System {
FORWARD(ConsoleCancelEventArgs)
namespace ConsoleCancelEventHandlerNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(ConsoleCancelEventHandler) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object sender, ConsoleCancelEventArgs e);
  public: IAsyncResult BeginInvoke(Object sender, ConsoleCancelEventArgs e, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ConsoleCancelEventHandlerNamespace
using ConsoleCancelEventHandler = ConsoleCancelEventHandlerNamespace::ConsoleCancelEventHandler;
} // namespace System::Console::System
