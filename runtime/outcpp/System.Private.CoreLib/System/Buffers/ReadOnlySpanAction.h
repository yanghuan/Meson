#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace ReadOnlySpanActionNamespace {
CLASS(ReadOnlySpanAction, T, TArg) {
  public: void Invoke(ReadOnlySpan<T> span, TArg arg);
  public: IAsyncResult BeginInvoke(ReadOnlySpan<T> span, TArg arg, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace ReadOnlySpanActionNamespace
template <class T, class TArg>
using ReadOnlySpanAction = ReadOnlySpanActionNamespace::ReadOnlySpanAction<T, TArg>;
} // namespace System::Private::CoreLib::System::Buffers
