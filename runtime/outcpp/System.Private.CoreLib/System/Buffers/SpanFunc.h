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
namespace SpanFuncNamespace {
CLASS(SpanFunc, TSpan, T1, T2, T3, TResult) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: TResult Invoke(Span<TSpan> span, T1 arg1, T2 arg2, T3 arg3);
  public: IAsyncResult BeginInvoke(Span<TSpan> span, T1 arg1, T2 arg2, T3 arg3, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
};
} // namespace SpanFuncNamespace
template <class TSpan, class T1, class T2, class T3, class TResult>
using SpanFunc = SpanFuncNamespace::SpanFunc<TSpan, T1, T2, T3, TResult>;
} // namespace System::Private::CoreLib::System::Buffers
