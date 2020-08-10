#include "RuntimePropertyInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::RuntimePropertyInfoNamespace {
Signature RuntimePropertyInfo___::get_Signature() {
  return nullptr;
}

BindingFlags RuntimePropertyInfo___::get_BindingFlags() {
  return BindingFlags::DoNotWrapExceptions;
}

MemberTypes RuntimePropertyInfo___::get_MemberType() {
  return MemberTypes::All;
}

String RuntimePropertyInfo___::get_Name() {
  return nullptr;
}

Type RuntimePropertyInfo___::get_DeclaringType() {
  return nullptr;
}

Type RuntimePropertyInfo___::get_ReflectedType() {
  return nullptr;
}

RuntimeType RuntimePropertyInfo___::get_ReflectedTypeInternal() {
  return nullptr;
}

Int32 RuntimePropertyInfo___::get_MetadataToken() {
  return Int32();
}

Module RuntimePropertyInfo___::get_Module() {
  return nullptr;
}

Boolean RuntimePropertyInfo___::get_IsCollectible() {
  return Boolean();
}

Type RuntimePropertyInfo___::get_PropertyType() {
  return nullptr;
}

PropertyAttributes RuntimePropertyInfo___::get_Attributes() {
  return PropertyAttributes::ReservedMask;
}

Boolean RuntimePropertyInfo___::get_CanRead() {
  return Boolean();
}

Boolean RuntimePropertyInfo___::get_CanWrite() {
  return Boolean();
}

void RuntimePropertyInfo___::ctor(Int32 tkProperty, RuntimeType declaredType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, Boolean& isPrivate) {
}

Boolean RuntimePropertyInfo___::CacheEquals(Object o) {
  return Boolean();
}

Boolean RuntimePropertyInfo___::EqualsSig(RuntimePropertyInfo target) {
  return Boolean();
}

String RuntimePropertyInfo___::ToString() {
  return nullptr;
}

Array<Object> RuntimePropertyInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
}

Array<Object> RuntimePropertyInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
}

Boolean RuntimePropertyInfo___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
}

IList<CustomAttributeData> RuntimePropertyInfo___::GetCustomAttributesData() {
  return nullptr;
}

Boolean RuntimePropertyInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return Boolean();
}

RuntimeModule RuntimePropertyInfo___::GetRuntimeModule() {
  return nullptr;
}

Array<Type> RuntimePropertyInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
}

Array<Type> RuntimePropertyInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
}

Object RuntimePropertyInfo___::GetConstantValue(Boolean raw) {
  return nullptr;
}

Object RuntimePropertyInfo___::GetConstantValue() {
  return nullptr;
}

Object RuntimePropertyInfo___::GetRawConstantValue() {
  return nullptr;
}

Array<MethodInfo> RuntimePropertyInfo___::GetAccessors(Boolean nonPublic) {
  return Array<MethodInfo>();
}

MethodInfo RuntimePropertyInfo___::GetGetMethod(Boolean nonPublic) {
  return nullptr;
}

MethodInfo RuntimePropertyInfo___::GetSetMethod(Boolean nonPublic) {
  return nullptr;
}

Array<ParameterInfo> RuntimePropertyInfo___::GetIndexParameters() {
  return Array<ParameterInfo>();
}

Array<ParameterInfo> RuntimePropertyInfo___::GetIndexParametersNoCopy() {
  return Array<ParameterInfo>();
}

Object RuntimePropertyInfo___::GetValue(Object obj, Array<Object> index) {
  return nullptr;
}

Object RuntimePropertyInfo___::GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  return nullptr;
}

void RuntimePropertyInfo___::SetValue(Object obj, Object value, Array<Object> index) {
}

void RuntimePropertyInfo___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimePropertyInfoNamespace
