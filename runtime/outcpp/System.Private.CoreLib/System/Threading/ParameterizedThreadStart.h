#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ParameterizedThreadStartNamespace {
CLASS(ParameterizedThreadStart) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object obj);
  public: IAsyncResult BeginInvoke(Object obj, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ParameterizedThreadStartNamespace
using ParameterizedThreadStart = ParameterizedThreadStartNamespace::ParameterizedThreadStart;
} // namespace System::Private::CoreLib::System::Threading
