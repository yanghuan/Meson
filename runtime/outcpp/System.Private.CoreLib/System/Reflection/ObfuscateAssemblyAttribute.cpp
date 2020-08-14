#include "ObfuscateAssemblyAttribute-dep.h"

namespace System::Private::CoreLib::System::Reflection::ObfuscateAssemblyAttributeNamespace {
void ObfuscateAssemblyAttribute___::ctor(Boolean assemblyIsPrivate) {
  StripAfterObfuscation = true;
  Attribute::ctor();
  AssemblyIsPrivate = assemblyIsPrivate;
}

} // namespace System::Private::CoreLib::System::Reflection::ObfuscateAssemblyAttributeNamespace
