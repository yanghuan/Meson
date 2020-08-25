#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace VariantWrapperNamespace {
CLASS(VariantWrapper) : public object {
  public: Object get_WrappedObject() { return WrappedObject; }
  public: void ctor(Object obj);
  private: Object WrappedObject;
};
} // namespace VariantWrapperNamespace
using VariantWrapper = VariantWrapperNamespace::VariantWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
