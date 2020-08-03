#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CustomConstantAttributeNamespace {
CLASS(CustomConstantAttribute) : public Attribute::in {
  public: Object get_Value();
  protected: void Ctor();
};
} // namespace CustomConstantAttributeNamespace
using CustomConstantAttribute = CustomConstantAttributeNamespace::CustomConstantAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
