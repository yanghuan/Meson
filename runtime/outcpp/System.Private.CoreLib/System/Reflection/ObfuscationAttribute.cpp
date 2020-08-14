#include "ObfuscationAttribute-dep.h"

namespace System::Private::CoreLib::System::Reflection::ObfuscationAttributeNamespace {
void ObfuscationAttribute___::ctor() {
  StripAfterObfuscation = true;
  Exclude = true;
  ApplyToMembers = true;
  Feature = "all";
  Attribute::ctor();
}

} // namespace System::Private::CoreLib::System::Reflection::ObfuscationAttributeNamespace
