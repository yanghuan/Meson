#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CustomConstantAttributeNamespace {
CLASS(CustomConstantAttribute) {
  public: Object get_Value();
};
} // namespace CustomConstantAttributeNamespace
using CustomConstantAttribute = CustomConstantAttributeNamespace::CustomConstantAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
