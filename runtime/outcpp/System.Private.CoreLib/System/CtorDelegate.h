#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace CtorDelegateNamespace {
CLASS(CtorDelegate) {
  public: void Ctor(Object object, IntPtr method);
  public: void Invoke(Object instance);
  public: IAsyncResult BeginInvoke(Object instance, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace CtorDelegateNamespace
using CtorDelegate = CtorDelegateNamespace::CtorDelegate;
} // namespace System::Private::CoreLib::System
