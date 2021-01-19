#include "FieldBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::FieldBuilderNamespace {
using namespace System::Runtime::CompilerServices;

Int32 FieldBuilder___::get_MetadataTokenInternal() {
  return m_fieldTok;
}

Module FieldBuilder___::get_Module() {
  return m_typeBuilder->get_Module();
}

String FieldBuilder___::get_Name() {
  return m_fieldName;
}

Type FieldBuilder___::get_DeclaringType() {
  if (m_typeBuilder->m_isHiddenGlobalType) {
    return nullptr;
  }
  return m_typeBuilder;
}

Type FieldBuilder___::get_ReflectedType() {
  if (m_typeBuilder->m_isHiddenGlobalType) {
    return nullptr;
  }
  return m_typeBuilder;
}

Type FieldBuilder___::get_FieldType() {
  return m_fieldType;
}

RuntimeFieldHandle FieldBuilder___::get_FieldHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

FieldAttributes FieldBuilder___::get_Attributes() {
  return m_Attributes;
}

void FieldBuilder___::ctor(TypeBuilder typeBuilder, String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes) {
  if (fieldName == nullptr) {
    rt::throw_exception<ArgumentNullException>("fieldName");
  }
  if (fieldName->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "fieldName");
  }
  if (fieldName[0] == '\0') {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IllegalName(), "fieldName");
  }
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (type == typeof<void>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadFieldType());
  }
  m_fieldName = fieldName;
  m_typeBuilder = typeBuilder;
  m_fieldType = type;
  m_Attributes = attributes & ~FieldAttributes::ReservedMask;
  SignatureHelper fieldSigHelper = SignatureHelper::in::GetFieldSigHelper(m_typeBuilder->get_Module());
  fieldSigHelper->AddArgument(type, requiredCustomModifiers, optionalCustomModifiers);
  Int32 length;
  Array<Byte> signature = fieldSigHelper->InternalGetSignature(length);
  ModuleBuilder module = m_typeBuilder->GetModuleBuilder();
  m_fieldTok = TypeBuilder::in::DefineField(QCallModule(module), typeBuilder->get_TypeToken().get_Token(), fieldName, signature, length, m_Attributes);
  m_tkField = FieldToken(m_fieldTok, type);
}

void FieldBuilder___::SetData(Array<Byte> data, Int32 size) {
  ModuleBuilder module = m_typeBuilder->GetModuleBuilder();
  ModuleBuilder::in::SetFieldRVAContent(QCallModule(module), m_tkField.get_Token(), data, size);
}

Object FieldBuilder___::GetValue(Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

void FieldBuilder___::SetValue(Object obj, Object val, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<Object> FieldBuilder___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<Object> FieldBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Boolean FieldBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

FieldToken FieldBuilder___::GetToken() {
  return m_tkField;
}

void FieldBuilder___::SetOffset(Int32 iOffset) {
  m_typeBuilder->ThrowIfCreated();
  ModuleBuilder module = m_typeBuilder->GetModuleBuilder();
  TypeBuilder::in::SetFieldLayoutOffset(QCallModule(module), GetToken().get_Token(), iOffset);
}

void FieldBuilder___::SetConstant(Object defaultValue) {
  m_typeBuilder->ThrowIfCreated();
  if (defaultValue == nullptr && m_fieldType->get_IsValueType() && (!m_fieldType->get_IsGenericType() || !(m_fieldType->GetGenericTypeDefinition() == typeof<Nullable<T>>()))) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ConstantNull());
  }
  TypeBuilder::in::SetConstantValue(m_typeBuilder->GetModuleBuilder(), GetToken().get_Token(), m_fieldType, defaultValue);
}

void FieldBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  ModuleBuilder moduleBuilder = rt::as<ModuleBuilder>(m_typeBuilder->get_Module());
  m_typeBuilder->ThrowIfCreated();
  TypeBuilder::in::DefineCustomAttribute(moduleBuilder, m_tkField.get_Token(), moduleBuilder->GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
}

void FieldBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  m_typeBuilder->ThrowIfCreated();
  ModuleBuilder mod = rt::as<ModuleBuilder>(m_typeBuilder->get_Module());
  customBuilder->CreateCustomAttribute(mod, m_tkField.get_Token());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::FieldBuilderNamespace
