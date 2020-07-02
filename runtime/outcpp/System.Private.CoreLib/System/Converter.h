#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(Object)
FORWARD(IAsyncResult)
namespace ConverterNamespace {
CLASS(Converter, TInput, TOutput) {
  public: TOutput Invoke(TInput input);
  public: IAsyncResult BeginInvoke(TInput input, AsyncCallback callback, Object object);
  public: TOutput EndInvoke(IAsyncResult result);
};
} // namespace ConverterNamespace
template <class TInput, class TOutput>
using Converter = ConverterNamespace::Converter<TInput, TOutput>;
} // namespace System::Private::CoreLib::System