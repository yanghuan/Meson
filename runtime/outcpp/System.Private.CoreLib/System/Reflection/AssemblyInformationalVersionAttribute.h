#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyInformationalVersionAttributeNamespace {
CLASS(AssemblyInformationalVersionAttribute) {
  private: String InformationalVersion;
};
} // namespace AssemblyInformationalVersionAttributeNamespace
using AssemblyInformationalVersionAttribute = AssemblyInformationalVersionAttributeNamespace::AssemblyInformationalVersionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
