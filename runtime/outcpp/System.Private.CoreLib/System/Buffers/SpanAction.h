#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace SpanActionNamespace {
CLASS(SpanAction, T, TArg) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Span<T> span, TArg arg);
  public: IAsyncResult BeginInvoke(Span<T> span, TArg arg, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace SpanActionNamespace
template <class T, class TArg>
using SpanAction = SpanActionNamespace::SpanAction<T, TArg>;
} // namespace System::Private::CoreLib::System::Buffers
