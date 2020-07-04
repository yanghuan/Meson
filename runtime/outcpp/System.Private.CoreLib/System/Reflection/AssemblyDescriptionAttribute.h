#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDescriptionAttributeNamespace {
CLASS(AssemblyDescriptionAttribute) {
  public: String get_Description() { return Description; }
  private: String Description;
};
} // namespace AssemblyDescriptionAttributeNamespace
using AssemblyDescriptionAttribute = AssemblyDescriptionAttributeNamespace::AssemblyDescriptionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
