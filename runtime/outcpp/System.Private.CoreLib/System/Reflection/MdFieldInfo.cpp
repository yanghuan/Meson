#include "MdFieldInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::MdFieldInfoNamespace {
String MdFieldInfo___::get_Name() {
  return nullptr;
};

Int32 MdFieldInfo___::get_MetadataToken() {
  return Int32();
};

RuntimeFieldHandle MdFieldInfo___::get_FieldHandle() {
  return RuntimeFieldHandle();
};

FieldAttributes MdFieldInfo___::get_Attributes() {
  return FieldAttributes::ReservedMask;
};

Boolean MdFieldInfo___::get_IsSecurityCritical() {
  return Boolean();
};

Boolean MdFieldInfo___::get_IsSecuritySafeCritical() {
  return Boolean();
};

Boolean MdFieldInfo___::get_IsSecurityTransparent() {
  return Boolean();
};

Type MdFieldInfo___::get_FieldType() {
  return nullptr;
};

void MdFieldInfo___::Ctor(Int32 tkField, FieldAttributes fieldAttributes, RuntimeTypeHandle declaringTypeHandle, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, BindingFlags bindingFlags) {
};

Boolean MdFieldInfo___::CacheEquals(Object o) {
  return Boolean();
};

RuntimeModule MdFieldInfo___::GetRuntimeModule() {
  return nullptr;
};

Object MdFieldInfo___::GetValueDirect(TypedReference obj) {
  return nullptr;
};

void MdFieldInfo___::SetValueDirect(TypedReference obj, Object value) {
};

Object MdFieldInfo___::GetValue(Object obj) {
  return nullptr;
};

Object MdFieldInfo___::GetRawConstantValue() {
  return nullptr;
};

Object MdFieldInfo___::GetValue(Boolean raw) {
  return nullptr;
};

void MdFieldInfo___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
};

Array<Type> MdFieldInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
};

Array<Type> MdFieldInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
};

} // namespace System::Private::CoreLib::System::Reflection::MdFieldInfoNamespace
