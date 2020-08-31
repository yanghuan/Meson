#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DynamicInterfaceCastableImplementationAttributeNamespace {
CLASS(DynamicInterfaceCastableImplementationAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace DynamicInterfaceCastableImplementationAttributeNamespace
using DynamicInterfaceCastableImplementationAttribute = DynamicInterfaceCastableImplementationAttributeNamespace::DynamicInterfaceCastableImplementationAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
