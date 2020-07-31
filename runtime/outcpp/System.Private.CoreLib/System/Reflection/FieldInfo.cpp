#include "FieldInfo-dep.h"

#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::FieldInfoNamespace {
MemberTypes FieldInfo___::get_MemberType() {
  return MemberTypes::All;
}

Boolean FieldInfo___::get_IsInitOnly() {
  return Boolean();
}

Boolean FieldInfo___::get_IsLiteral() {
  return Boolean();
}

Boolean FieldInfo___::get_IsNotSerialized() {
  return Boolean();
}

Boolean FieldInfo___::get_IsPinvokeImpl() {
  return Boolean();
}

Boolean FieldInfo___::get_IsSpecialName() {
  return Boolean();
}

Boolean FieldInfo___::get_IsStatic() {
  return Boolean();
}

Boolean FieldInfo___::get_IsAssembly() {
  return Boolean();
}

Boolean FieldInfo___::get_IsFamily() {
  return Boolean();
}

Boolean FieldInfo___::get_IsFamilyAndAssembly() {
  return Boolean();
}

Boolean FieldInfo___::get_IsFamilyOrAssembly() {
  return Boolean();
}

Boolean FieldInfo___::get_IsPrivate() {
  return Boolean();
}

Boolean FieldInfo___::get_IsPublic() {
  return Boolean();
}

Boolean FieldInfo___::get_IsSecurityCritical() {
  return Boolean();
}

Boolean FieldInfo___::get_IsSecuritySafeCritical() {
  return Boolean();
}

Boolean FieldInfo___::get_IsSecurityTransparent() {
  return Boolean();
}

FieldInfo FieldInfo___::GetFieldFromHandle(RuntimeFieldHandle handle) {
  return nullptr;
}

FieldInfo FieldInfo___::GetFieldFromHandle(RuntimeFieldHandle handle, RuntimeTypeHandle declaringType) {
  return nullptr;
}

void FieldInfo___::Ctor() {
}

Boolean FieldInfo___::Equals(Object obj) {
  return Boolean();
}

Int32 FieldInfo___::GetHashCode() {
  return Int32();
}

Boolean FieldInfo___::op_Equality(FieldInfo left, FieldInfo right) {
  return Boolean();
}

Boolean FieldInfo___::op_Inequality(FieldInfo left, FieldInfo right) {
  return Boolean();
}

void FieldInfo___::SetValue(Object obj, Object value) {
}

void FieldInfo___::SetValueDirect(TypedReference obj, Object value) {
}

Object FieldInfo___::GetValueDirect(TypedReference obj) {
  return nullptr;
}

Object FieldInfo___::GetRawConstantValue() {
  return nullptr;
}

Array<Type> FieldInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
}

Array<Type> FieldInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
}

} // namespace System::Private::CoreLib::System::Reflection::FieldInfoNamespace
