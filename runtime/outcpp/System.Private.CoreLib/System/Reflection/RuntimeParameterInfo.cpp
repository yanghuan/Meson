#include "RuntimeParameterInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::RuntimeParameterInfoNamespace {
Type RuntimeParameterInfo___::get_ParameterType() {
  return nullptr;
}

String RuntimeParameterInfo___::get_Name() {
  return nullptr;
}

Boolean RuntimeParameterInfo___::get_HasDefaultValue() {
  return Boolean();
}

Object RuntimeParameterInfo___::get_DefaultValue() {
  return nullptr;
}

Object RuntimeParameterInfo___::get_RawDefaultValue() {
  return nullptr;
}

Int32 RuntimeParameterInfo___::get_MetadataToken() {
  return Int32();
}

Array<ParameterInfo> RuntimeParameterInfo___::GetParameters(IRuntimeMethodInfo method, MemberInfo member, Signature sig) {
  return Array<ParameterInfo>();
}

ParameterInfo RuntimeParameterInfo___::GetReturnParameter(IRuntimeMethodInfo method, MemberInfo member, Signature sig) {
  return nullptr;
}

Array<ParameterInfo> RuntimeParameterInfo___::GetParameters(IRuntimeMethodInfo methodHandle, MemberInfo member, Signature sig, ParameterInfo& returnParameter, Boolean fetchReturnParameter) {
  return Array<ParameterInfo>();
}

void RuntimeParameterInfo___::SetName(String name) {
}

void RuntimeParameterInfo___::SetAttributes(ParameterAttributes attributes) {
}

void RuntimeParameterInfo___::ctor(RuntimeParameterInfo accessor, RuntimePropertyInfo property) {
}

void RuntimeParameterInfo___::ctor(RuntimeParameterInfo accessor, MemberInfo member) {
}

void RuntimeParameterInfo___::ctor(Signature signature, MetadataImport scope, Int32 tkParamDef, Int32 position, ParameterAttributes attributes, MemberInfo member) {
}

void RuntimeParameterInfo___::ctor(MethodInfo owner, String name, Type parameterType, Int32 position) {
}

Object RuntimeParameterInfo___::GetDefaultValue(Boolean raw) {
  return nullptr;
}

Object RuntimeParameterInfo___::GetDefaultValueInternal(Boolean raw) {
  return nullptr;
}

Decimal RuntimeParameterInfo___::GetRawDecimalConstant(CustomAttributeData attr) {
  return Decimal();
}

DateTime RuntimeParameterInfo___::GetRawDateTimeConstant(CustomAttributeData attr) {
  return DateTime();
}

Object RuntimeParameterInfo___::GetRawConstant(CustomAttributeData attr) {
  return nullptr;
}

RuntimeModule RuntimeParameterInfo___::GetRuntimeModule() {
  return nullptr;
}

Array<Type> RuntimeParameterInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
}

Array<Type> RuntimeParameterInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
}

Array<Object> RuntimeParameterInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
}

Array<Object> RuntimeParameterInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
}

Boolean RuntimeParameterInfo___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
}

IList<CustomAttributeData> RuntimeParameterInfo___::GetCustomAttributesData() {
  return nullptr;
}

void RuntimeParameterInfo___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeParameterInfoNamespace
