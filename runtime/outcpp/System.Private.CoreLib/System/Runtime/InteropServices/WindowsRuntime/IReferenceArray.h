#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IReferenceArrayNamespace {
CLASS(IReferenceArray, T) {
  public: Array<T> get_Value();
};
} // namespace IReferenceArrayNamespace
template <class T>
using IReferenceArray = IReferenceArrayNamespace::IReferenceArray<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
