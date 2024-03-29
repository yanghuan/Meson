#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace ConverterNamespace {
CLASS(Converter, TInput, TOutput) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TOutput Invoke(TInput input);
  public: IAsyncResult BeginInvoke(TInput input, AsyncCallback callback, Object object);
  public: TOutput EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace ConverterNamespace
template <class TInput, class TOutput>
using Converter = ConverterNamespace::Converter<TInput, TOutput>;
} // namespace System::Private::CoreLib::System
