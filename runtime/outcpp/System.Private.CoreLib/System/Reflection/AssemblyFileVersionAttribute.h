#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyFileVersionAttributeNamespace {
CLASS(AssemblyFileVersionAttribute) {
  private: String Version;
};
} // namespace AssemblyFileVersionAttributeNamespace
using AssemblyFileVersionAttribute = AssemblyFileVersionAttributeNamespace::AssemblyFileVersionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
