#include "TypeBuilderInstantiation-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericTypeParameterBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolType-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeNameBuilder-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::TypeBuilderInstantiationNamespace {
using namespace System::Collections;

Type TypeBuilderInstantiation___::get_DeclaringType() {
  return m_type->get_DeclaringType();
}

Type TypeBuilderInstantiation___::get_ReflectedType() {
  return m_type->get_ReflectedType();
}

String TypeBuilderInstantiation___::get_Name() {
  return m_type->get_Name();
}

Module TypeBuilderInstantiation___::get_Module() {
  return m_type->get_Module();
}

Guid TypeBuilderInstantiation___::get_GUID() {
  rt::throw_exception<NotSupportedException>();
}

Assembly TypeBuilderInstantiation___::get_Assembly() {
  return m_type->get_Assembly();
}

RuntimeTypeHandle TypeBuilderInstantiation___::get_TypeHandle() {
  rt::throw_exception<NotSupportedException>();
}

String TypeBuilderInstantiation___::get_FullName() {
  String as = m_strFullQualName;
  return as != nullptr ? as : (m_strFullQualName = TypeNameBuilder::in::ToString((TypeBuilderInstantiation)this, TypeNameBuilder::in::Format::FullName));
}

String TypeBuilderInstantiation___::get_Namespace() {
  return m_type->get_Namespace();
}

String TypeBuilderInstantiation___::get_AssemblyQualifiedName() {
  return TypeNameBuilder::in::ToString((TypeBuilderInstantiation)this, TypeNameBuilder::in::Format::AssemblyQualifiedName);
}

Type TypeBuilderInstantiation___::get_BaseType() {
  Type baseType = m_type->get_BaseType();
  if (baseType == nullptr) {
    return nullptr;
  }
  TypeBuilderInstantiation typeBuilderInstantiation = rt::as<TypeBuilderInstantiation>(baseType);
  if (typeBuilderInstantiation == nullptr) {
    return baseType;
  }
  return typeBuilderInstantiation->Substitute(GetGenericArguments());
}

Boolean TypeBuilderInstantiation___::get_IsTypeDefinition() {
  return false;
}

Boolean TypeBuilderInstantiation___::get_IsSZArray() {
  return false;
}

Type TypeBuilderInstantiation___::get_UnderlyingSystemType() {
  return (TypeBuilderInstantiation)this;
}

Boolean TypeBuilderInstantiation___::get_IsGenericTypeDefinition() {
  return false;
}

Boolean TypeBuilderInstantiation___::get_IsGenericType() {
  return true;
}

Boolean TypeBuilderInstantiation___::get_IsConstructedGenericType() {
  return true;
}

Boolean TypeBuilderInstantiation___::get_IsGenericParameter() {
  return false;
}

Int32 TypeBuilderInstantiation___::get_GenericParameterPosition() {
  rt::throw_exception<InvalidOperationException>();
}

Boolean TypeBuilderInstantiation___::get_ContainsGenericParameters() {
  for (Int32 i = 0; i < m_inst->get_Length(); i++) {
    if (m_inst[i]->get_ContainsGenericParameters()) {
      return true;
    }
  }
  return false;
}

MethodBase TypeBuilderInstantiation___::get_DeclaringMethod() {
  return nullptr;
}

Boolean TypeBuilderInstantiation___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

Type TypeBuilderInstantiation___::MakeGenericType(Type type, Array<Type> typeArguments) {
  if (!type->get_IsGenericTypeDefinition()) {
    rt::throw_exception<InvalidOperationException>();
  }
  if (typeArguments == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeArguments");
  }
  for (Type&& left : *typeArguments) {
    if (left == nullptr) {
      rt::throw_exception<ArgumentNullException>("typeArguments");
    }
  }
  return rt::newobj<TypeBuilderInstantiation>(type, typeArguments);
}

void TypeBuilderInstantiation___::ctor(Type type, Array<Type> inst) {
  m_type = type;
  m_inst = inst;
  m_hashtable = rt::newobj<Hashtable>();
}

String TypeBuilderInstantiation___::ToString() {
  return TypeNameBuilder::in::ToString((TypeBuilderInstantiation)this, TypeNameBuilder::in::Format::ToString);
}

Type TypeBuilderInstantiation___::MakePointerType() {
  return SymbolType::in::FormCompoundType("*", (TypeBuilderInstantiation)this, 0);
}

Type TypeBuilderInstantiation___::MakeByRefType() {
  return SymbolType::in::FormCompoundType("&", (TypeBuilderInstantiation)this, 0);
}

Type TypeBuilderInstantiation___::MakeArrayType() {
  return SymbolType::in::FormCompoundType("[]", (TypeBuilderInstantiation)this, 0);
}

Type TypeBuilderInstantiation___::MakeArrayType(Int32 rank) {
  if (rank <= 0) {
    rt::throw_exception<IndexOutOfRangeException>();
  }
  String format = ((rank == 1) ? "[]" : ("[" + rt::newstr<String>(u',', rank - 1) + "]"));
  return SymbolType::in::FormCompoundType(format, (TypeBuilderInstantiation)this, 0);
}

Object TypeBuilderInstantiation___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  rt::throw_exception<NotSupportedException>();
}

Type TypeBuilderInstantiation___::Substitute(Array<Type> substitutes) {
  Array<Type> genericArguments = GetGenericArguments();
  Array<Type> array = rt::newarr<Array<Type>>(genericArguments->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    Type type = genericArguments[i];
    TypeBuilderInstantiation typeBuilderInstantiation = rt::as<TypeBuilderInstantiation>(type);
    if ((Object)typeBuilderInstantiation != nullptr) {
      array[i] = typeBuilderInstantiation->Substitute(substitutes);
    } else if (rt::is<GenericTypeParameterBuilder>(type)) {
      array[i] = substitutes[type->get_GenericParameterPosition()];
    } else {
      array[i] = type;
    }

  }
  return GetGenericTypeDefinition()->MakeGenericType(array);
}

ConstructorInfo TypeBuilderInstantiation___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<ConstructorInfo> TypeBuilderInstantiation___::GetConstructors(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

MethodInfo TypeBuilderInstantiation___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<MethodInfo> TypeBuilderInstantiation___::GetMethods(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

FieldInfo TypeBuilderInstantiation___::GetField(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<FieldInfo> TypeBuilderInstantiation___::GetFields(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Type TypeBuilderInstantiation___::GetInterface(String name, Boolean ignoreCase) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> TypeBuilderInstantiation___::GetInterfaces() {
  rt::throw_exception<NotSupportedException>();
}

EventInfo TypeBuilderInstantiation___::GetEvent(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<EventInfo> TypeBuilderInstantiation___::GetEvents() {
  rt::throw_exception<NotSupportedException>();
}

PropertyInfo TypeBuilderInstantiation___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<PropertyInfo> TypeBuilderInstantiation___::GetProperties(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> TypeBuilderInstantiation___::GetNestedTypes(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Type TypeBuilderInstantiation___::GetNestedType(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<MemberInfo> TypeBuilderInstantiation___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

InterfaceMapping TypeBuilderInstantiation___::GetInterfaceMap(Type interfaceType) {
  rt::throw_exception<NotSupportedException>();
}

Array<EventInfo> TypeBuilderInstantiation___::GetEvents(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

Array<MemberInfo> TypeBuilderInstantiation___::GetMembers(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>();
}

TypeAttributes TypeBuilderInstantiation___::GetAttributeFlagsImpl() {
  return m_type->get_Attributes();
}

Boolean TypeBuilderInstantiation___::IsArrayImpl() {
  return false;
}

Boolean TypeBuilderInstantiation___::IsByRefImpl() {
  return false;
}

Boolean TypeBuilderInstantiation___::IsPointerImpl() {
  return false;
}

Boolean TypeBuilderInstantiation___::IsPrimitiveImpl() {
  return false;
}

Boolean TypeBuilderInstantiation___::IsCOMObjectImpl() {
  return false;
}

Type TypeBuilderInstantiation___::GetElementType() {
  rt::throw_exception<NotSupportedException>();
}

Boolean TypeBuilderInstantiation___::HasElementTypeImpl() {
  return false;
}

Array<Type> TypeBuilderInstantiation___::GetGenericArguments() {
  return m_inst;
}

Boolean TypeBuilderInstantiation___::IsValueTypeImpl() {
  return m_type->get_IsValueType();
}

Type TypeBuilderInstantiation___::GetGenericTypeDefinition() {
  return m_type;
}

Type TypeBuilderInstantiation___::MakeGenericType(Array<Type> inst) {
  rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_NotGenericTypeDefinition(), (TypeBuilderInstantiation)this));
}

Boolean TypeBuilderInstantiation___::IsAssignableFrom(Type c) {
  rt::throw_exception<NotSupportedException>();
}

Boolean TypeBuilderInstantiation___::IsSubclassOf(Type c) {
  rt::throw_exception<NotSupportedException>();
}

Array<Object> TypeBuilderInstantiation___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>();
}

Array<Object> TypeBuilderInstantiation___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>();
}

Boolean TypeBuilderInstantiation___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::TypeBuilderInstantiationNamespace
