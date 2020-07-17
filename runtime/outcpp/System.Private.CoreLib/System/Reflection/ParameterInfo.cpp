#include "ParameterInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::ParameterInfoNamespace {
ParameterAttributes ParameterInfo___::get_Attributes() {
  return ParameterAttributes::ReservedMask;
};

MemberInfo ParameterInfo___::get_Member() {
  return nullptr;
};

String ParameterInfo___::get_Name() {
  return nullptr;
};

Type ParameterInfo___::get_ParameterType() {
  return nullptr;
};

Int32 ParameterInfo___::get_Position() {
  return Int32();
};

Boolean ParameterInfo___::get_IsIn() {
  return Boolean();
};

Boolean ParameterInfo___::get_IsLcid() {
  return Boolean();
};

Boolean ParameterInfo___::get_IsOptional() {
  return Boolean();
};

Boolean ParameterInfo___::get_IsOut() {
  return Boolean();
};

Boolean ParameterInfo___::get_IsRetval() {
  return Boolean();
};

Object ParameterInfo___::get_DefaultValue() {
  return nullptr;
};

Object ParameterInfo___::get_RawDefaultValue() {
  return nullptr;
};

Boolean ParameterInfo___::get_HasDefaultValue() {
  return Boolean();
};

IEnumerable<CustomAttributeData> ParameterInfo___::get_CustomAttributes() {
  return nullptr;
};

Int32 ParameterInfo___::get_MetadataToken() {
  return Int32();
};

void ParameterInfo___::Ctor() {
};

Boolean ParameterInfo___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};

IList<CustomAttributeData> ParameterInfo___::GetCustomAttributesData() {
  return nullptr;
};

Array<Object> ParameterInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};

Array<Object> ParameterInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};

Array<Type> ParameterInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
};

Array<Type> ParameterInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
};

Object ParameterInfo___::GetRealObject(StreamingContext context) {
  return nullptr;
};

String ParameterInfo___::ToString() {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Reflection::ParameterInfoNamespace
