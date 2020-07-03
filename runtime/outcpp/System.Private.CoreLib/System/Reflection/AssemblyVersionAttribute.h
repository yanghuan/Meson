#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyVersionAttributeNamespace {
CLASS(AssemblyVersionAttribute) {
  private: String Version;
};
} // namespace AssemblyVersionAttributeNamespace
using AssemblyVersionAttribute = AssemblyVersionAttributeNamespace::AssemblyVersionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
