#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ClassInterfaceType;
namespace ClassInterfaceAttributeNamespace {
CLASS(ClassInterfaceAttribute) : public Attribute::in {
  public: ClassInterfaceType get_Value() { return Value; }
  public: void Ctor(ClassInterfaceType classInterfaceType);
  public: void Ctor(Int16 classInterfaceType);
  private: ClassInterfaceType Value;
};
} // namespace ClassInterfaceAttributeNamespace
using ClassInterfaceAttribute = ClassInterfaceAttributeNamespace::ClassInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
