#include "GenericTypeParameterBuilder-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericTypeParameterBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::GenericTypeParameterBuilderNamespace {
Type GenericTypeParameterBuilder___::get_DeclaringType() {
  return m_type->get_DeclaringType();
}

Type GenericTypeParameterBuilder___::get_ReflectedType() {
  return m_type->get_ReflectedType();
}

String GenericTypeParameterBuilder___::get_Name() {
  return m_type->get_Name();
}

Module GenericTypeParameterBuilder___::get_Module() {
  return m_type->get_Module();
}

Boolean GenericTypeParameterBuilder___::get_IsByRefLike() {
  return false;
}

Int32 GenericTypeParameterBuilder___::get_MetadataTokenInternal() {
  return m_type->get_MetadataTokenInternal();
}

Guid GenericTypeParameterBuilder___::get_GUID() {
  rt::throw_exception<NotSupportedException>();
}

Assembly GenericTypeParameterBuilder___::get_Assembly() {
  return m_type->get_Assembly();
}

RuntimeTypeHandle GenericTypeParameterBuilder___::get_TypeHandle() {
  rt::throw_exception<NotSupportedException>();
}

String GenericTypeParameterBuilder___::get_FullName() {
  return nullptr;
}

String GenericTypeParameterBuilder___::get_Namespace() {
  return nullptr;
}

String GenericTypeParameterBuilder___::get_AssemblyQualifiedName() {
  return nullptr;
}

Type GenericTypeParameterBuilder___::get_BaseType() {
  return m_type->get_BaseType();
}

Boolean GenericTypeParameterBuilder___::get_IsTypeDefinition() {
  return false;
}

Boolean GenericTypeParameterBuilder___::get_IsSZArray() {
  return false;
}

Type GenericTypeParameterBuilder___::get_UnderlyingSystemType() {
  return (GenericTypeParameterBuilder)this;
}

Boolean GenericTypeParameterBuilder___::get_IsGenericTypeDefinition() {
  return false;
}

Boolean GenericTypeParameterBuilder___::get_IsGenericType() {
  return false;
}

Boolean GenericTypeParameterBuilder___::get_IsGenericParameter() {
  return true;
}

Boolean GenericTypeParameterBuilder___::get_IsConstructedGenericType() {
  return false;
}

Int32 GenericTypeParameterBuilder___::get_GenericParameterPosition() {
  return m_type->get_GenericParameterPosition();
}

Boolean GenericTypeParameterBuilder___::get_ContainsGenericParameters() {
  return m_type->get_ContainsGenericParameters();
}

GenericParameterAttributes GenericTypeParameterBuilder___::get_GenericParameterAttributes() {
  return m_type->get_GenericParameterAttributes();
}

MethodBase GenericTypeParameterBuilder___::get_DeclaringMethod() {
  return m_type->get_DeclaringMethod();
}

Boolean GenericTypeParameterBuilder___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

void GenericTypeParameterBuilder___::ctor(TypeBuilder type) {
  m_type = type;
}

String GenericTypeParameterBuilder___::ToString() {
  return m_type->get_Name();
}

Boolean GenericTypeParameterBuilder___::Equals(Object o) {
  GenericTypeParameterBuilder genericTypeParameterBuilder = rt::as<GenericTypeParameterBuilder>(o);
  if (genericTypeParameterBuilder == nullptr) {
    return false;
  }
  return (Object)genericTypeParameterBuilder->m_type == m_type;
}

Int32 GenericTypeParameterBuilder___::GetHashCode() {
  return m_type->GetHashCode();
}

Type GenericTypeParameterBuilder___::MakePointerType() {
  return SymbolType::in::FormCompoundType("*", (GenericTypeParameterBuilder)this, 0);
}

Type GenericTypeParameterBuilder___::MakeByRefType() {
  return SymbolType::in::FormCompoundType("&", (GenericTypeParameterBuilder)this, 0);
}

Type GenericTypeParameterBuilder___::MakeArrayType() {
  return SymbolType::in::FormCompoundType("[]", (GenericTypeParameterBuilder)this, 0);
}

Type GenericTypeParameterBuilder___::MakeArrayType(Int32 rank) {
  String rankString = TypeInfo::in::GetRankString(rank);
  return rt::as<SymbolType>(SymbolType::in::FormCompoundType(rankString, (GenericTypeParameterBuilder)this, 0));
}

Object GenericTypeParameterBuilder___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  rt::throw_exception<NotSupportedException>();
}

ConstructorInfo GenericTypeParameterBuilder___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<ConstructorInfo> GenericTypeParameterBuilder___::GetConstructors(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

MethodInfo GenericTypeParameterBuilder___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<MethodInfo> GenericTypeParameterBuilder___::GetMethods(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

FieldInfo GenericTypeParameterBuilder___::GetField(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<FieldInfo> GenericTypeParameterBuilder___::GetFields(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Type GenericTypeParameterBuilder___::GetInterface(String name, Boolean ignoreCase) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> GenericTypeParameterBuilder___::GetInterfaces() {
  rt::throw_exception<NotSupportedException>();
}

EventInfo GenericTypeParameterBuilder___::GetEvent(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<EventInfo> GenericTypeParameterBuilder___::GetEvents() {
  rt::throw_exception<NotSupportedException>();
}

PropertyInfo GenericTypeParameterBuilder___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<PropertyInfo> GenericTypeParameterBuilder___::GetProperties(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> GenericTypeParameterBuilder___::GetNestedTypes(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Type GenericTypeParameterBuilder___::GetNestedType(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<MemberInfo> GenericTypeParameterBuilder___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

InterfaceMapping GenericTypeParameterBuilder___::GetInterfaceMap(Type interfaceType) {
  rt::throw_exception<NotSupportedException>();
}

Array<EventInfo> GenericTypeParameterBuilder___::GetEvents(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<MemberInfo> GenericTypeParameterBuilder___::GetMembers(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

TypeAttributes GenericTypeParameterBuilder___::GetAttributeFlagsImpl() {
  return TypeAttributes::Public;
}

Boolean GenericTypeParameterBuilder___::IsArrayImpl() {
  return false;
}

Boolean GenericTypeParameterBuilder___::IsByRefImpl() {
  return false;
}

Boolean GenericTypeParameterBuilder___::IsPointerImpl() {
  return false;
}

Boolean GenericTypeParameterBuilder___::IsPrimitiveImpl() {
  return false;
}

Boolean GenericTypeParameterBuilder___::IsCOMObjectImpl() {
  return false;
}

Type GenericTypeParameterBuilder___::GetElementType() {
  rt::throw_exception<NotSupportedException>();
}

Boolean GenericTypeParameterBuilder___::HasElementTypeImpl() {
  return false;
}

Array<Type> GenericTypeParameterBuilder___::GetGenericArguments() {
  rt::throw_exception<InvalidOperationException>();
}

Type GenericTypeParameterBuilder___::GetGenericTypeDefinition() {
  rt::throw_exception<InvalidOperationException>();
}

Type GenericTypeParameterBuilder___::MakeGenericType(Array<Type> typeArguments) {
  rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_NotGenericTypeDefinition(), (GenericTypeParameterBuilder)this));
}

Boolean GenericTypeParameterBuilder___::IsValueTypeImpl() {
  return false;
}

Boolean GenericTypeParameterBuilder___::IsAssignableFrom(Type c) {
  rt::throw_exception<NotSupportedException>();
}

Boolean GenericTypeParameterBuilder___::IsSubclassOf(Type c) {
  rt::throw_exception<NotSupportedException>();
}

Array<Object> GenericTypeParameterBuilder___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>();
}

Array<Object> GenericTypeParameterBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>();
}

Boolean GenericTypeParameterBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>();
}

void GenericTypeParameterBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  m_type->SetGenParamCustomAttribute(con, binaryAttribute);
}

void GenericTypeParameterBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  m_type->SetGenParamCustomAttribute(customBuilder);
}

void GenericTypeParameterBuilder___::SetBaseTypeConstraint(Type baseTypeConstraint) {
  m_type->CheckContext(baseTypeConstraint);
  m_type->SetParent(baseTypeConstraint);
}

void GenericTypeParameterBuilder___::SetInterfaceConstraints(Array<Type> interfaceConstraints) {
  m_type->CheckContext(interfaceConstraints);
  m_type->SetInterfaces(interfaceConstraints);
}

void GenericTypeParameterBuilder___::SetGenericParameterAttributes(GenericParameterAttributes genericParameterAttributes) {
  m_type->SetGenParamAttributes(genericParameterAttributes);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::GenericTypeParameterBuilderNamespace
