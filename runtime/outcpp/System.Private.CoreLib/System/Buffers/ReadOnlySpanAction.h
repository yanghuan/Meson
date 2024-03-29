#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace ReadOnlySpanActionNamespace {
CLASS(ReadOnlySpanAction, T, TArg) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(ReadOnlySpan<T> span, TArg arg);
  public: IAsyncResult BeginInvoke(ReadOnlySpan<T> span, TArg arg, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ReadOnlySpanActionNamespace
template <class T, class TArg>
using ReadOnlySpanAction = ReadOnlySpanActionNamespace::ReadOnlySpanAction<T, TArg>;
} // namespace System::Private::CoreLib::System::Buffers
