#include "PropertyInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::PropertyInfoNamespace {
MemberTypes PropertyInfo___::get_MemberType() {
  return MemberTypes::All;
};
Boolean PropertyInfo___::get_IsSpecialName() {
  return Boolean();
};
MethodInfo PropertyInfo___::get_GetMethod() {
  return nullptr;
};
MethodInfo PropertyInfo___::get_SetMethod() {
  return nullptr;
};
Array<MethodInfo> PropertyInfo___::GetAccessors() {
  return Array<MethodInfo>();
};
MethodInfo PropertyInfo___::GetGetMethod() {
  return nullptr;
};
MethodInfo PropertyInfo___::GetSetMethod() {
  return nullptr;
};
Array<Type> PropertyInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
};
Array<Type> PropertyInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
};
Object PropertyInfo___::GetValue(Object obj) {
  return nullptr;
};
Object PropertyInfo___::GetValue(Object obj, Array<Object> index) {
  return nullptr;
};
Object PropertyInfo___::GetConstantValue() {
  return nullptr;
};
Object PropertyInfo___::GetRawConstantValue() {
  return nullptr;
};
void PropertyInfo___::SetValue(Object obj, Object value) {
};
void PropertyInfo___::SetValue(Object obj, Object value, Array<Object> index) {
};
Boolean PropertyInfo___::Equals(Object obj) {
  return Boolean();
};
Int32 PropertyInfo___::GetHashCode() {
  return Int32();
};
Boolean PropertyInfo___::op_Equality(PropertyInfo left, PropertyInfo right) {
  return Boolean();
};
Boolean PropertyInfo___::op_Inequality(PropertyInfo left, PropertyInfo right) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Reflection::PropertyInfoNamespace
