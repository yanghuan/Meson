#include "FieldOnTypeBuilderInstantiation-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotImplementedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldOnTypeBuilderInstantiation-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::FieldOnTypeBuilderInstantiationNamespace {
FieldInfo FieldOnTypeBuilderInstantiation___::get_FieldInfo() {
  return m_field;
}

MemberTypes FieldOnTypeBuilderInstantiation___::get_MemberType() {
  return MemberTypes::Field;
}

String FieldOnTypeBuilderInstantiation___::get_Name() {
  return m_field->get_Name();
}

Type FieldOnTypeBuilderInstantiation___::get_DeclaringType() {
  return m_type;
}

Type FieldOnTypeBuilderInstantiation___::get_ReflectedType() {
  return m_type;
}

Int32 FieldOnTypeBuilderInstantiation___::get_MetadataTokenInternal() {
  FieldBuilder fieldBuilder = rt::as<FieldBuilder>(m_field);
  if (fieldBuilder != nullptr) {
    return fieldBuilder->get_MetadataTokenInternal();
  }
  return m_field->get_MetadataToken();
}

Module FieldOnTypeBuilderInstantiation___::get_Module() {
  return m_field->get_Module();
}

RuntimeFieldHandle FieldOnTypeBuilderInstantiation___::get_FieldHandle() {
  rt::throw_exception<NotImplementedException>();
}

Type FieldOnTypeBuilderInstantiation___::get_FieldType() {
  rt::throw_exception<NotImplementedException>();
}

FieldAttributes FieldOnTypeBuilderInstantiation___::get_Attributes() {
  return m_field->get_Attributes();
}

FieldInfo FieldOnTypeBuilderInstantiation___::GetField(FieldInfo Field, TypeBuilderInstantiation type) {
  FieldInfo fieldInfo;
  if (type->m_hashtable->Contains(Field)) {
    fieldInfo = (rt::as<FieldInfo>(type->m_hashtable[Field]));
  } else {
    fieldInfo = rt::newobj<FieldOnTypeBuilderInstantiation>(Field, type);
    type->m_hashtable[Field] = fieldInfo;
  }
  return fieldInfo;
}

void FieldOnTypeBuilderInstantiation___::ctor(FieldInfo field, TypeBuilderInstantiation type) {
  m_field = field;
  m_type = type;
}

Array<Object> FieldOnTypeBuilderInstantiation___::GetCustomAttributes(Boolean inherit) {
  return m_field->GetCustomAttributes(inherit);
}

Array<Object> FieldOnTypeBuilderInstantiation___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_field->GetCustomAttributes(attributeType, inherit);
}

Boolean FieldOnTypeBuilderInstantiation___::IsDefined(Type attributeType, Boolean inherit) {
  return m_field->IsDefined(attributeType, inherit);
}

Array<Type> FieldOnTypeBuilderInstantiation___::GetRequiredCustomModifiers() {
  return m_field->GetRequiredCustomModifiers();
}

Array<Type> FieldOnTypeBuilderInstantiation___::GetOptionalCustomModifiers() {
  return m_field->GetOptionalCustomModifiers();
}

void FieldOnTypeBuilderInstantiation___::SetValueDirect(TypedReference obj, Object value) {
  rt::throw_exception<NotImplementedException>();
}

Object FieldOnTypeBuilderInstantiation___::GetValueDirect(TypedReference obj) {
  rt::throw_exception<NotImplementedException>();
}

Object FieldOnTypeBuilderInstantiation___::GetValue(Object obj) {
  rt::throw_exception<InvalidOperationException>();
}

void FieldOnTypeBuilderInstantiation___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
  rt::throw_exception<InvalidOperationException>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::FieldOnTypeBuilderInstantiationNamespace
