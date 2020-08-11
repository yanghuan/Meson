#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ClassInterfaceType : int32_t;
namespace ClassInterfaceAttributeNamespace {
CLASS(ClassInterfaceAttribute) : public Attribute::in {
  public: ClassInterfaceType get_Value() { return Value; }
  public: void ctor(ClassInterfaceType classInterfaceType);
  public: void ctor(Int16 classInterfaceType);
  private: ClassInterfaceType Value;
};
} // namespace ClassInterfaceAttributeNamespace
using ClassInterfaceAttribute = ClassInterfaceAttributeNamespace::ClassInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
