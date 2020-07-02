#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableIterator)
namespace IBindableIterableNamespace {
CLASS(IBindableIterable) {
  public: IBindableIterator First();
};
} // namespace IBindableIterableNamespace
using IBindableIterable = IBindableIterableNamespace::IBindableIterable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
