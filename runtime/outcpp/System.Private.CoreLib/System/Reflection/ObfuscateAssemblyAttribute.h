#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Reflection {
namespace ObfuscateAssemblyAttributeNamespace {
CLASS(ObfuscateAssemblyAttribute) : public Attribute::in {
  public: Boolean get_AssemblyIsPrivate() { return AssemblyIsPrivate; }
  public: Boolean get_StripAfterObfuscation() { return StripAfterObfuscation; }
  public: void set_StripAfterObfuscation(Boolean value) { StripAfterObfuscation = value; }
  public: void ctor(Boolean assemblyIsPrivate);
  private: Boolean AssemblyIsPrivate;
  private: Boolean StripAfterObfuscation;
};
} // namespace ObfuscateAssemblyAttributeNamespace
using ObfuscateAssemblyAttribute = ObfuscateAssemblyAttributeNamespace::ObfuscateAssemblyAttribute;
} // namespace System::Private::CoreLib::System::Reflection
