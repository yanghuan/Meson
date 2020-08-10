#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComInterfaceType;
namespace InterfaceTypeAttributeNamespace {
CLASS(InterfaceTypeAttribute) : public Attribute::in {
  public: ComInterfaceType get_Value() { return Value; }
  public: void ctor(ComInterfaceType interfaceType);
  public: void ctor(Int16 interfaceType);
  private: ComInterfaceType Value;
};
} // namespace InterfaceTypeAttributeNamespace
using InterfaceTypeAttribute = InterfaceTypeAttributeNamespace::InterfaceTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
