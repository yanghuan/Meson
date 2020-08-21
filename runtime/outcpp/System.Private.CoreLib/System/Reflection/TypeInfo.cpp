#include "TypeInfo-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/IntrospectionExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/TypeInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::TypeInfoNamespace {
Array<Type> TypeInfo___::get_GenericTypeParameters() {
  if (!get_IsGenericTypeDefinition()) {
    return Type::in::EmptyTypes;
  }
  return GetGenericArguments();
}

IEnumerable<ConstructorInfo> TypeInfo___::get_DeclaredConstructors() {
  return GetConstructors(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<EventInfo> TypeInfo___::get_DeclaredEvents() {
  return GetEvents(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<FieldInfo> TypeInfo___::get_DeclaredFields() {
  return GetFields(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<MemberInfo> TypeInfo___::get_DeclaredMembers() {
  return GetMembers(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<MethodInfo> TypeInfo___::get_DeclaredMethods() {
  return GetMethods(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<TypeInfo> TypeInfo___::get_DeclaredNestedTypes() {
  Array<Type> nestedTypes = GetNestedTypes(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<PropertyInfo> TypeInfo___::get_DeclaredProperties() {
  return GetProperties(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<Type> TypeInfo___::get_ImplementedInterfaces() {
  return GetInterfaces();
}

void TypeInfo___::ctor() {
}

Type TypeInfo___::AsType() {
  return (TypeInfo)this;
}

EventInfo TypeInfo___::GetDeclaredEvent(String name) {
  return GetEvent(name, BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

FieldInfo TypeInfo___::GetDeclaredField(String name) {
  return GetField(name, BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

MethodInfo TypeInfo___::GetDeclaredMethod(String name) {
  return GetMethod(name, BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

TypeInfo TypeInfo___::GetDeclaredNestedType(String name) {
  Type nestedType = GetNestedType(name, BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
  if ((Object)nestedType == nullptr) {
    return nullptr;
  }
  return IntrospectionExtensions::GetTypeInfo(nestedType);
}

PropertyInfo TypeInfo___::GetDeclaredProperty(String name) {
  return GetProperty(name, BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<MethodInfo> TypeInfo___::GetDeclaredMethods(String name) {
  Array<MethodInfo> methods = GetMethods(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

Boolean TypeInfo___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  if ((TypeInfo)this == typeInfo) {
    return true;
  }
  if (typeInfo->IsSubclassOf((TypeInfo)this)) {
    return true;
  }
  if (Type::in::get_IsInterface()) {
    return typeInfo->ImplementInterface((TypeInfo)this);
  }
  if (get_IsGenericParameter()) {
    Array<Type> genericParameterConstraints = GetGenericParameterConstraints();
    for (Int32 i = 0; i < genericParameterConstraints->get_Length(); i++) {
      if (!genericParameterConstraints[i]->IsAssignableFrom(typeInfo)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

String TypeInfo___::GetRankString(Int32 rank) {
  if (rank <= 0) {
    rt::throw_exception<IndexOutOfRangeException>();
  }
  if (rank != 1) {
    return "[" + rt::newobj<String>(44, rank - 1) + "]";
  }
  return "[*]";
}

} // namespace System::Private::CoreLib::System::Reflection::TypeInfoNamespace
