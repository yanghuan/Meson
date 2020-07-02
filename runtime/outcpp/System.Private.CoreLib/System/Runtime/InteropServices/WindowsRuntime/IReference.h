#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IReferenceNamespace {
CLASS(IReference, T) {
  public: T get_Value();
};
} // namespace IReferenceNamespace
template <class T>
using IReference = IReferenceNamespace::IReference<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
