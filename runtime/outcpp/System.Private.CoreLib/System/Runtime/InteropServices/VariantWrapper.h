#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace VariantWrapperNamespace {
CLASS(VariantWrapper) {
  public: Object get_WrappedObject() { return WrappedObject; }
  public: void Ctor(Object obj);
  private: Object WrappedObject;
};
} // namespace VariantWrapperNamespace
using VariantWrapper = VariantWrapperNamespace::VariantWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
