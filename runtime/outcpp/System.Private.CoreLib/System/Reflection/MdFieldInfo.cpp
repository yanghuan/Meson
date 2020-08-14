#include "MdFieldInfo-dep.h"

#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/FieldAccessException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/ConstArray-dep.h>
#include <System.Private.CoreLib/System/Reflection/MdConstant-dep.h>
#include <System.Private.CoreLib/System/Reflection/MdFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Signature-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::MdFieldInfoNamespace {
String MdFieldInfo___::get_Name() {
}

Int32 MdFieldInfo___::get_MetadataToken() {
  return m_tkField;
}

RuntimeFieldHandle MdFieldInfo___::get_FieldHandle() {
  rt::throw_exception<NotSupportedException>();
}

FieldAttributes MdFieldInfo___::get_Attributes() {
  return m_fieldAttributes;
}

Boolean MdFieldInfo___::get_IsSecurityCritical() {
  return get_DeclaringType()->get_IsSecurityCritical();
}

Boolean MdFieldInfo___::get_IsSecuritySafeCritical() {
  return get_DeclaringType()->get_IsSecuritySafeCritical();
}

Boolean MdFieldInfo___::get_IsSecurityTransparent() {
  return get_DeclaringType()->get_IsSecurityTransparent();
}

Type MdFieldInfo___::get_FieldType() {
  if (m_fieldType == nullptr) {
    ConstArray sigOfFieldDef = GetRuntimeModule()->get_MetadataImport().GetSigOfFieldDef(m_tkField);
    m_fieldType = rt::newobj<Signature>(sigOfFieldDef.get_Signature().ToPointer(), sigOfFieldDef.get_Length(), m_declaringType)->get_FieldType();
  }
  return m_fieldType;
}

void MdFieldInfo___::ctor(Int32 tkField, FieldAttributes fieldAttributes, RuntimeTypeHandle declaringTypeHandle, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, BindingFlags bindingFlags) {
  m_tkField = tkField;
  m_name = nullptr;
  m_fieldAttributes = fieldAttributes;
}

Boolean MdFieldInfo___::CacheEquals(Object o) {
  MdFieldInfo mdFieldInfo = rt::as<MdFieldInfo>(o);
  if ((Object)mdFieldInfo != nullptr && mdFieldInfo->m_tkField == m_tkField) {
    return m_declaringType->GetTypeHandleInternal().GetModuleHandle().Equals(mdFieldInfo->m_declaringType->GetTypeHandleInternal().GetModuleHandle());
  }
  return false;
}

RuntimeModule MdFieldInfo___::GetRuntimeModule() {
  return m_declaringType->GetRuntimeModule();
}

Object MdFieldInfo___::GetValueDirect(TypedReference obj) {
  return GetValue(nullptr);
}

void MdFieldInfo___::SetValueDirect(TypedReference obj, Object value) {
  rt::throw_exception<FieldAccessException>(SR::get_Acc_ReadOnly());
}

Object MdFieldInfo___::GetValue(Object obj) {
  return GetValue(false);
}

Object MdFieldInfo___::GetRawConstantValue() {
  return GetValue(true);
}

Object MdFieldInfo___::GetValue(Boolean raw) {
  Object value = MdConstant::GetValue(GetRuntimeModule()->get_MetadataImport(), m_tkField, get_FieldType()->GetTypeHandleInternal(), raw);
  if (value == DBNull::in::Value) {
    rt::throw_exception<NotSupportedException>(SR::get_Arg_EnumLitValueNotFound());
  }
  return value;
}

void MdFieldInfo___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
  rt::throw_exception<FieldAccessException>(SR::get_Acc_ReadOnly());
}

Array<Type> MdFieldInfo___::GetRequiredCustomModifiers() {
  return Array<>::in::Empty<Type>();
}

Array<Type> MdFieldInfo___::GetOptionalCustomModifiers() {
  return Array<>::in::Empty<Type>();
}

} // namespace System::Private::CoreLib::System::Reflection::MdFieldInfoNamespace
