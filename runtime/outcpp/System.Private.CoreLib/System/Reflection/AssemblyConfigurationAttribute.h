#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyConfigurationAttributeNamespace {
CLASS(AssemblyConfigurationAttribute) : public Attribute::in {
  public: String get_Configuration() { return Configuration; }
  public: void ctor(String configuration);
  private: String Configuration;
};
} // namespace AssemblyConfigurationAttributeNamespace
using AssemblyConfigurationAttribute = AssemblyConfigurationAttributeNamespace::AssemblyConfigurationAttribute;
} // namespace System::Private::CoreLib::System::Reflection
