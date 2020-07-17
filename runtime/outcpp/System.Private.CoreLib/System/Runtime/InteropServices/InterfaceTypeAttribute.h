#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComInterfaceType;
namespace InterfaceTypeAttributeNamespace {
CLASS(InterfaceTypeAttribute) {
  public: ComInterfaceType get_Value() { return Value; }
  public: void Ctor(ComInterfaceType interfaceType);
  public: void Ctor(Int16 interfaceType);
  private: ComInterfaceType Value;
};
} // namespace InterfaceTypeAttributeNamespace
using InterfaceTypeAttribute = InterfaceTypeAttributeNamespace::InterfaceTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
