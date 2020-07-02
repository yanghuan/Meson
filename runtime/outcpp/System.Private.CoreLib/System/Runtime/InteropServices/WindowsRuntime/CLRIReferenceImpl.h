#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace CLRIReferenceImplNamespace {
CLASS(CLRIReferenceImpl, T) {
  public: T get_Value();
  public: String ToString();
  public: static Object UnboxHelper(Object wrapper);
  private: T _value;
};
} // namespace CLRIReferenceImplNamespace
template <class T>
using CLRIReferenceImpl = CLRIReferenceImplNamespace::CLRIReferenceImpl<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
