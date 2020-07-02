#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IIterator, T)
namespace IIterableNamespace {
CLASS(IIterable, T) {
  public: IIterator<T> First();
};
} // namespace IIterableNamespace
template <class T>
using IIterable = IIterableNamespace::IIterable<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
