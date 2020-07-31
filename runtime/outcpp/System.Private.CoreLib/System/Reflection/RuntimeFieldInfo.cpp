#include "RuntimeFieldInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::RuntimeFieldInfoNamespace {
BindingFlags RuntimeFieldInfo___::get_BindingFlags() {
  return BindingFlags::DoNotWrapExceptions;
}

RuntimeType RuntimeFieldInfo___::get_ReflectedTypeInternal() {
  return nullptr;
}

MemberTypes RuntimeFieldInfo___::get_MemberType() {
  return MemberTypes::All;
}

Type RuntimeFieldInfo___::get_ReflectedType() {
  return nullptr;
}

Type RuntimeFieldInfo___::get_DeclaringType() {
  return nullptr;
}

Module RuntimeFieldInfo___::get_Module() {
  return nullptr;
}

Boolean RuntimeFieldInfo___::get_IsCollectible() {
  return Boolean();
}

void RuntimeFieldInfo___::Ctor(RuntimeType::in::RuntimeTypeCache reflectedTypeCache, RuntimeType declaringType, BindingFlags bindingFlags) {
}

RuntimeType RuntimeFieldInfo___::GetDeclaringTypeInternal() {
  return nullptr;
}

RuntimeType RuntimeFieldInfo___::GetRuntimeType() {
  return nullptr;
}

Boolean RuntimeFieldInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return Boolean();
}

String RuntimeFieldInfo___::ToString() {
  return nullptr;
}

Array<Object> RuntimeFieldInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
}

Array<Object> RuntimeFieldInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
}

Boolean RuntimeFieldInfo___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
}

IList<CustomAttributeData> RuntimeFieldInfo___::GetCustomAttributesData() {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeFieldInfoNamespace
