#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComDefaultInterfaceAttributeNamespace {
CLASS(ComDefaultInterfaceAttribute) {
  public: Type get_Value() { return Value; }
  private: Type Value;
};
} // namespace ComDefaultInterfaceAttributeNamespace
using ComDefaultInterfaceAttribute = ComDefaultInterfaceAttributeNamespace::ComDefaultInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
