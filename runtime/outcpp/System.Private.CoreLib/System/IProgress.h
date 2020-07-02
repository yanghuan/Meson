#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace IProgressNamespace {
CLASS(IProgress, T) {
  public: void Report(T value);
};
} // namespace IProgressNamespace
template <class T>
using IProgress = IProgressNamespace::IProgress<T>;
} // namespace System::Private::CoreLib::System
