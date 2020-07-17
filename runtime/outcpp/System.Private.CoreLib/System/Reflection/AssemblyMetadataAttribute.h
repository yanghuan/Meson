#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyMetadataAttributeNamespace {
CLASS(AssemblyMetadataAttribute) {
  public: String get_Key() { return Key; }
  public: String get_Value() { return Value; }
  public: void Ctor(String key, String value);
  private: String Key;
  private: String Value;
};
} // namespace AssemblyMetadataAttributeNamespace
using AssemblyMetadataAttribute = AssemblyMetadataAttributeNamespace::AssemblyMetadataAttribute;
} // namespace System::Private::CoreLib::System::Reflection
