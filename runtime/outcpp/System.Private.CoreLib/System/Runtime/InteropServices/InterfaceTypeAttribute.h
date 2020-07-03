#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComInterfaceType;
namespace InterfaceTypeAttributeNamespace {
CLASS(InterfaceTypeAttribute) {
  private: ComInterfaceType Value;
};
} // namespace InterfaceTypeAttributeNamespace
using InterfaceTypeAttribute = InterfaceTypeAttributeNamespace::InterfaceTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
