#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
namespace ComparisonNamespace {
CLASS(Comparison, T) {
  public: void Ctor(Object object, IntPtr method);
  public: Int32 Invoke(T x, T y);
  public: IAsyncResult BeginInvoke(T x, T y, AsyncCallback callback, Object object);
  public: Int32 EndInvoke(IAsyncResult result);
};
} // namespace ComparisonNamespace
template <class T>
using Comparison = ComparisonNamespace::Comparison<T>;
} // namespace System::Private::CoreLib::System
