#include "DynamicDependencyAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis::DynamicDependencyAttributeNamespace {
void DynamicDependencyAttribute___::ctor(String memberSignature) {
  MemberSignature = memberSignature;
}

void DynamicDependencyAttribute___::ctor(String memberSignature, System::Type type) {
  MemberSignature = memberSignature;
  Type = type;
}

void DynamicDependencyAttribute___::ctor(String memberSignature, String typeName, String assemblyName) {
  MemberSignature = memberSignature;
  TypeName = typeName;
  AssemblyName = assemblyName;
}

void DynamicDependencyAttribute___::ctor(DynamicallyAccessedMemberTypes memberTypes, System::Type type) {
  MemberTypes = memberTypes;
  Type = type;
}

void DynamicDependencyAttribute___::ctor(DynamicallyAccessedMemberTypes memberTypes, String typeName, String assemblyName) {
  MemberTypes = memberTypes;
  TypeName = typeName;
  AssemblyName = assemblyName;
}

} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis::DynamicDependencyAttributeNamespace
