#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ClassInterfaceType;
namespace ClassInterfaceAttributeNamespace {
CLASS(ClassInterfaceAttribute) {
  private: ClassInterfaceType Value;
};
} // namespace ClassInterfaceAttributeNamespace
using ClassInterfaceAttribute = ClassInterfaceAttributeNamespace::ClassInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
