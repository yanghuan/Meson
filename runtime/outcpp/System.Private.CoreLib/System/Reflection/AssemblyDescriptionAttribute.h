#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDescriptionAttributeNamespace {
CLASS(AssemblyDescriptionAttribute) {
  private: String Description;
};
} // namespace AssemblyDescriptionAttributeNamespace
using AssemblyDescriptionAttribute = AssemblyDescriptionAttributeNamespace::AssemblyDescriptionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
