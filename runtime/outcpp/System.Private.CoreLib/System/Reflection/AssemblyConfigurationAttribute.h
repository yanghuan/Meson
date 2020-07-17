#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyConfigurationAttributeNamespace {
CLASS(AssemblyConfigurationAttribute) {
  public: String get_Configuration() { return Configuration; }
  public: void Ctor(String configuration);
  private: String Configuration;
};
} // namespace AssemblyConfigurationAttributeNamespace
using AssemblyConfigurationAttribute = AssemblyConfigurationAttributeNamespace::AssemblyConfigurationAttribute;
} // namespace System::Private::CoreLib::System::Reflection
