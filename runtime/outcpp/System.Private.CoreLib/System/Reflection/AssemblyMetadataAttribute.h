#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyMetadataAttributeNamespace {
CLASS(AssemblyMetadataAttribute) : public Attribute::in {
  public: String get_Key() { return Key; }
  public: String get_Value() { return Value; }
  public: void ctor(String key, String value);
  private: String Key;
  private: String Value;
};
} // namespace AssemblyMetadataAttributeNamespace
using AssemblyMetadataAttribute = AssemblyMetadataAttributeNamespace::AssemblyMetadataAttribute;
} // namespace System::Private::CoreLib::System::Reflection
