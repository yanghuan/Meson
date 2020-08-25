#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ThreadStartNamespace {
CLASS(ThreadStart) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke();
  public: IAsyncResult BeginInvoke(AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ThreadStartNamespace
using ThreadStart = ThreadStartNamespace::ThreadStart;
} // namespace System::Private::CoreLib::System::Threading
