#include "TypeDelegator-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>

namespace System::Private::CoreLib::System::Reflection::TypeDelegatorNamespace {
Guid TypeDelegator___::get_GUID() {
  return typeImpl->get_GUID();
}

Int32 TypeDelegator___::get_MetadataToken() {
  return typeImpl->get_MetadataToken();
}

Module TypeDelegator___::get_Module() {
  return typeImpl->get_Module();
}

Assembly TypeDelegator___::get_Assembly() {
  return typeImpl->get_Assembly();
}

RuntimeTypeHandle TypeDelegator___::get_TypeHandle() {
  return typeImpl->get_TypeHandle();
}

String TypeDelegator___::get_Name() {
  return typeImpl->get_Name();
}

String TypeDelegator___::get_FullName() {
  return typeImpl->get_FullName();
}

String TypeDelegator___::get_Namespace() {
  return typeImpl->get_Namespace();
}

String TypeDelegator___::get_AssemblyQualifiedName() {
  return typeImpl->get_AssemblyQualifiedName();
}

Type TypeDelegator___::get_BaseType() {
  return typeImpl->get_BaseType();
}

Boolean TypeDelegator___::get_IsTypeDefinition() {
  return typeImpl->get_IsTypeDefinition();
}

Boolean TypeDelegator___::get_IsSZArray() {
  return typeImpl->get_IsSZArray();
}

Boolean TypeDelegator___::get_IsVariableBoundArray() {
  return typeImpl->get_IsVariableBoundArray();
}

Boolean TypeDelegator___::get_IsGenericTypeParameter() {
  return typeImpl->get_IsGenericTypeParameter();
}

Boolean TypeDelegator___::get_IsGenericMethodParameter() {
  return typeImpl->get_IsGenericMethodParameter();
}

Boolean TypeDelegator___::get_IsByRefLike() {
  return typeImpl->get_IsByRefLike();
}

Boolean TypeDelegator___::get_IsConstructedGenericType() {
  return typeImpl->get_IsConstructedGenericType();
}

Boolean TypeDelegator___::get_IsCollectible() {
  return typeImpl->get_IsCollectible();
}

Type TypeDelegator___::get_UnderlyingSystemType() {
  return typeImpl->get_UnderlyingSystemType();
}

Boolean TypeDelegator___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

void TypeDelegator___::ctor() {
}

void TypeDelegator___::ctor(Type delegatingType) {
  if ((Object)delegatingType == nullptr) {
    rt::throw_exception<ArgumentNullException>("delegatingType");
  }
  typeImpl = delegatingType;
}

Object TypeDelegator___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  return typeImpl->InvokeMember(name, invokeAttr, binder, target, args, modifiers, culture, namedParameters);
}

ConstructorInfo TypeDelegator___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return typeImpl->GetConstructor(bindingAttr, binder, callConvention, types, modifiers);
}

Array<ConstructorInfo> TypeDelegator___::GetConstructors(BindingFlags bindingAttr) {
  return typeImpl->GetConstructors(bindingAttr);
}

MethodInfo TypeDelegator___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (types == nullptr) {
    return typeImpl->GetMethod(name, bindingAttr);
  }
  return typeImpl->GetMethod(name, bindingAttr, binder, callConvention, types, modifiers);
}

Array<MethodInfo> TypeDelegator___::GetMethods(BindingFlags bindingAttr) {
  return typeImpl->GetMethods(bindingAttr);
}

FieldInfo TypeDelegator___::GetField(String name, BindingFlags bindingAttr) {
  return typeImpl->GetField(name, bindingAttr);
}

Array<FieldInfo> TypeDelegator___::GetFields(BindingFlags bindingAttr) {
  return typeImpl->GetFields(bindingAttr);
}

Type TypeDelegator___::GetInterface(String name, Boolean ignoreCase) {
  return typeImpl->GetInterface(name, ignoreCase);
}

Array<Type> TypeDelegator___::GetInterfaces() {
  return typeImpl->GetInterfaces();
}

EventInfo TypeDelegator___::GetEvent(String name, BindingFlags bindingAttr) {
  return typeImpl->GetEvent(name, bindingAttr);
}

Array<EventInfo> TypeDelegator___::GetEvents() {
  return typeImpl->GetEvents();
}

PropertyInfo TypeDelegator___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (returnType == nullptr && types == nullptr) {
    return typeImpl->GetProperty(name, bindingAttr);
  }
  return typeImpl->GetProperty(name, bindingAttr, binder, returnType, types, modifiers);
}

Array<PropertyInfo> TypeDelegator___::GetProperties(BindingFlags bindingAttr) {
  return typeImpl->GetProperties(bindingAttr);
}

Array<EventInfo> TypeDelegator___::GetEvents(BindingFlags bindingAttr) {
  return typeImpl->GetEvents(bindingAttr);
}

Array<Type> TypeDelegator___::GetNestedTypes(BindingFlags bindingAttr) {
  return typeImpl->GetNestedTypes(bindingAttr);
}

Type TypeDelegator___::GetNestedType(String name, BindingFlags bindingAttr) {
  return typeImpl->GetNestedType(name, bindingAttr);
}

Array<MemberInfo> TypeDelegator___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  return typeImpl->GetMember(name, type, bindingAttr);
}

Array<MemberInfo> TypeDelegator___::GetMembers(BindingFlags bindingAttr) {
  return typeImpl->GetMembers(bindingAttr);
}

TypeAttributes TypeDelegator___::GetAttributeFlagsImpl() {
  return typeImpl->get_Attributes();
}

Boolean TypeDelegator___::IsArrayImpl() {
  return typeImpl->get_IsArray();
}

Boolean TypeDelegator___::IsPrimitiveImpl() {
  return typeImpl->get_IsPrimitive();
}

Boolean TypeDelegator___::IsByRefImpl() {
  return typeImpl->get_IsByRef();
}

Boolean TypeDelegator___::IsPointerImpl() {
  return typeImpl->get_IsPointer();
}

Boolean TypeDelegator___::IsValueTypeImpl() {
  return typeImpl->get_IsValueType();
}

Boolean TypeDelegator___::IsCOMObjectImpl() {
  return typeImpl->get_IsCOMObject();
}

Type TypeDelegator___::GetElementType() {
  return typeImpl->GetElementType();
}

Boolean TypeDelegator___::HasElementTypeImpl() {
  return typeImpl->get_HasElementType();
}

Array<Object> TypeDelegator___::GetCustomAttributes(Boolean inherit) {
  return typeImpl->GetCustomAttributes(inherit);
}

Array<Object> TypeDelegator___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return typeImpl->GetCustomAttributes(attributeType, inherit);
}

Boolean TypeDelegator___::IsDefined(Type attributeType, Boolean inherit) {
  return typeImpl->IsDefined(attributeType, inherit);
}

InterfaceMapping TypeDelegator___::GetInterfaceMap(Type interfaceType) {
  return typeImpl->GetInterfaceMap(interfaceType);
}

} // namespace System::Private::CoreLib::System::Reflection::TypeDelegatorNamespace
