#include "EnumBuilder-dep.h"

#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EnumBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolType-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldAttributes.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::EnumBuilderNamespace {
TypeToken EnumBuilder___::get_TypeToken() {
  return m_typeBuilder->get_TypeToken();
}

FieldBuilder EnumBuilder___::get_UnderlyingField() {
  return m_underlyingField;
}

String EnumBuilder___::get_Name() {
  return m_typeBuilder->get_Name();
}

Guid EnumBuilder___::get_GUID() {
  return m_typeBuilder->get_GUID();
}

Module EnumBuilder___::get_Module() {
  return m_typeBuilder->get_Module();
}

Assembly EnumBuilder___::get_Assembly() {
  return m_typeBuilder->get_Assembly();
}

RuntimeTypeHandle EnumBuilder___::get_TypeHandle() {
  return m_typeBuilder->get_TypeHandle();
}

String EnumBuilder___::get_FullName() {
  return m_typeBuilder->get_FullName();
}

String EnumBuilder___::get_AssemblyQualifiedName() {
  return m_typeBuilder->get_AssemblyQualifiedName();
}

String EnumBuilder___::get_Namespace() {
  return m_typeBuilder->get_Namespace();
}

Type EnumBuilder___::get_BaseType() {
  return m_typeBuilder->get_BaseType();
}

Boolean EnumBuilder___::get_IsByRefLike() {
  return false;
}

Boolean EnumBuilder___::get_IsTypeDefinition() {
  return true;
}

Boolean EnumBuilder___::get_IsSZArray() {
  return false;
}

Boolean EnumBuilder___::get_IsConstructedGenericType() {
  return false;
}

Type EnumBuilder___::get_UnderlyingSystemType() {
  return GetEnumUnderlyingType();
}

Type EnumBuilder___::get_DeclaringType() {
  return m_typeBuilder->get_DeclaringType();
}

Type EnumBuilder___::get_ReflectedType() {
  return m_typeBuilder->get_ReflectedType();
}

Boolean EnumBuilder___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

FieldBuilder EnumBuilder___::DefineLiteral(String literalName, Object literalValue) {
}

TypeInfo EnumBuilder___::CreateTypeInfo() {
  return m_typeBuilder->CreateTypeInfo();
}

Type EnumBuilder___::CreateType() {
  return m_typeBuilder->CreateType();
}

Object EnumBuilder___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  return m_typeBuilder->InvokeMember(name, invokeAttr, binder, target, args, modifiers, culture, namedParameters);
}

ConstructorInfo EnumBuilder___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return m_typeBuilder->GetConstructor(bindingAttr, binder, callConvention, types, modifiers);
}

Array<ConstructorInfo> EnumBuilder___::GetConstructors(BindingFlags bindingAttr) {
  return m_typeBuilder->GetConstructors(bindingAttr);
}

MethodInfo EnumBuilder___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (types == nullptr) {
    return m_typeBuilder->GetMethod(name, bindingAttr);
  }
  return m_typeBuilder->GetMethod(name, bindingAttr, binder, callConvention, types, modifiers);
}

Array<MethodInfo> EnumBuilder___::GetMethods(BindingFlags bindingAttr) {
  return m_typeBuilder->GetMethods(bindingAttr);
}

FieldInfo EnumBuilder___::GetField(String name, BindingFlags bindingAttr) {
  return m_typeBuilder->GetField(name, bindingAttr);
}

Array<FieldInfo> EnumBuilder___::GetFields(BindingFlags bindingAttr) {
  return m_typeBuilder->GetFields(bindingAttr);
}

Type EnumBuilder___::GetInterface(String name, Boolean ignoreCase) {
  return m_typeBuilder->GetInterface(name, ignoreCase);
}

Array<Type> EnumBuilder___::GetInterfaces() {
  return m_typeBuilder->GetInterfaces();
}

EventInfo EnumBuilder___::GetEvent(String name, BindingFlags bindingAttr) {
  return m_typeBuilder->GetEvent(name, bindingAttr);
}

Array<EventInfo> EnumBuilder___::GetEvents() {
  return m_typeBuilder->GetEvents();
}

PropertyInfo EnumBuilder___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<PropertyInfo> EnumBuilder___::GetProperties(BindingFlags bindingAttr) {
  return m_typeBuilder->GetProperties(bindingAttr);
}

Array<Type> EnumBuilder___::GetNestedTypes(BindingFlags bindingAttr) {
  return m_typeBuilder->GetNestedTypes(bindingAttr);
}

Type EnumBuilder___::GetNestedType(String name, BindingFlags bindingAttr) {
  return m_typeBuilder->GetNestedType(name, bindingAttr);
}

Array<MemberInfo> EnumBuilder___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  return m_typeBuilder->GetMember(name, type, bindingAttr);
}

Array<MemberInfo> EnumBuilder___::GetMembers(BindingFlags bindingAttr) {
  return m_typeBuilder->GetMembers(bindingAttr);
}

InterfaceMapping EnumBuilder___::GetInterfaceMap(Type interfaceType) {
  return m_typeBuilder->GetInterfaceMap(interfaceType);
}

Array<EventInfo> EnumBuilder___::GetEvents(BindingFlags bindingAttr) {
  return m_typeBuilder->GetEvents(bindingAttr);
}

TypeAttributes EnumBuilder___::GetAttributeFlagsImpl() {
  return m_typeBuilder->get_Attributes();
}

Boolean EnumBuilder___::IsArrayImpl() {
  return false;
}

Boolean EnumBuilder___::IsPrimitiveImpl() {
  return false;
}

Boolean EnumBuilder___::IsValueTypeImpl() {
  return true;
}

Boolean EnumBuilder___::IsByRefImpl() {
  return false;
}

Boolean EnumBuilder___::IsPointerImpl() {
  return false;
}

Boolean EnumBuilder___::IsCOMObjectImpl() {
  return false;
}

Type EnumBuilder___::GetElementType() {
  return m_typeBuilder->GetElementType();
}

Boolean EnumBuilder___::HasElementTypeImpl() {
  return m_typeBuilder->get_HasElementType();
}

Type EnumBuilder___::GetEnumUnderlyingType() {
  return m_underlyingField->get_FieldType();
}

Array<Object> EnumBuilder___::GetCustomAttributes(Boolean inherit) {
  return m_typeBuilder->GetCustomAttributes(inherit);
}

Array<Object> EnumBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_typeBuilder->GetCustomAttributes(attributeType, inherit);
}

void EnumBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  m_typeBuilder->SetCustomAttribute(con, binaryAttribute);
}

void EnumBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  m_typeBuilder->SetCustomAttribute(customBuilder);
}

Boolean EnumBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return m_typeBuilder->IsDefined(attributeType, inherit);
}

Type EnumBuilder___::MakePointerType() {
  return SymbolType::in::FormCompoundType("*", (EnumBuilder)this, 0);
}

Type EnumBuilder___::MakeByRefType() {
  return SymbolType::in::FormCompoundType("&", (EnumBuilder)this, 0);
}

Type EnumBuilder___::MakeArrayType() {
  return SymbolType::in::FormCompoundType("[]", (EnumBuilder)this, 0);
}

Type EnumBuilder___::MakeArrayType(Int32 rank) {
  String rankString = TypeInfo::in::GetRankString(rank);
  return SymbolType::in::FormCompoundType(rankString, (EnumBuilder)this, 0);
}

void EnumBuilder___::ctor(String name, Type underlyingType, TypeAttributes visibility, ModuleBuilder module) {
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::EnumBuilderNamespace
