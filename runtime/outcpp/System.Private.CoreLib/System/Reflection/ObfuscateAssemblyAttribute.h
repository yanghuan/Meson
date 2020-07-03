#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Reflection {
namespace ObfuscateAssemblyAttributeNamespace {
CLASS(ObfuscateAssemblyAttribute) {
  private: Boolean AssemblyIsPrivate;
  private: Boolean StripAfterObfuscation;
};
} // namespace ObfuscateAssemblyAttributeNamespace
using ObfuscateAssemblyAttribute = ObfuscateAssemblyAttributeNamespace::ObfuscateAssemblyAttribute;
} // namespace System::Private::CoreLib::System::Reflection
