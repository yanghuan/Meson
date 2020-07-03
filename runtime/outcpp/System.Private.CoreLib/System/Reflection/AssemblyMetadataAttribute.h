#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyMetadataAttributeNamespace {
CLASS(AssemblyMetadataAttribute) {
  private: String Key;
  private: String Value;
};
} // namespace AssemblyMetadataAttributeNamespace
using AssemblyMetadataAttribute = AssemblyMetadataAttributeNamespace::AssemblyMetadataAttribute;
} // namespace System::Private::CoreLib::System::Reflection
