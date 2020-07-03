#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyKeyNameAttributeNamespace {
CLASS(AssemblyKeyNameAttribute) {
  private: String KeyName;
};
} // namespace AssemblyKeyNameAttributeNamespace
using AssemblyKeyNameAttribute = AssemblyKeyNameAttributeNamespace::AssemblyKeyNameAttribute;
} // namespace System::Private::CoreLib::System::Reflection
