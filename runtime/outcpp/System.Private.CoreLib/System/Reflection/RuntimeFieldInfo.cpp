#include "RuntimeFieldInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeFieldInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeFieldInfoNamespace {
BindingFlags RuntimeFieldInfo___::get_BindingFlags() {
  return m_bindingFlags;
}

RuntimeType RuntimeFieldInfo___::get_ReflectedTypeInternal() {
  return m_reflectedTypeCache->GetRuntimeType();
}

MemberTypes RuntimeFieldInfo___::get_MemberType() {
  return MemberTypes::Field;
}

Type RuntimeFieldInfo___::get_ReflectedType() {
  if (!m_reflectedTypeCache->get_IsGlobal()) {
    return get_ReflectedTypeInternal();
  }
  return nullptr;
}

Type RuntimeFieldInfo___::get_DeclaringType() {
  if (!m_reflectedTypeCache->get_IsGlobal()) {
    return m_declaringType;
  }
  return nullptr;
}

Module RuntimeFieldInfo___::get_Module() {
  return GetRuntimeModule();
}

Boolean RuntimeFieldInfo___::get_IsCollectible() {
  return m_declaringType->get_IsCollectible();
}

void RuntimeFieldInfo___::ctor(RuntimeType::in::RuntimeTypeCache reflectedTypeCache, RuntimeType declaringType, BindingFlags bindingFlags) {
  m_bindingFlags = bindingFlags;
  m_declaringType = declaringType;
  m_reflectedTypeCache = reflectedTypeCache;
}

RuntimeType RuntimeFieldInfo___::GetDeclaringTypeInternal() {
  return m_declaringType;
}

RuntimeType RuntimeFieldInfo___::GetRuntimeType() {
  return m_declaringType;
}

Boolean RuntimeFieldInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return HasSameMetadataDefinitionAsCore<RuntimeFieldInfo>(other);
}

String RuntimeFieldInfo___::ToString() {
  return get_FieldType()->FormatTypeName() + " " + get_Name();
}

Array<Object> RuntimeFieldInfo___::GetCustomAttributes(Boolean inherit) {
  return CustomAttribute::GetCustomAttributes((RuntimeFieldInfo)this, rt::as<RuntimeType>(typeof<Object>()));
}

Array<Object> RuntimeFieldInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeFieldInfo)this, runtimeType);
}

Boolean RuntimeFieldInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeFieldInfo)this, runtimeType);
}

IList<CustomAttributeData> RuntimeFieldInfo___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeFieldInfo)this);
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeFieldInfoNamespace
