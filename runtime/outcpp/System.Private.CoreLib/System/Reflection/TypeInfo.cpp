#include "TypeInfo-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/TypeInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::TypeInfoNamespace {
Array<Type> TypeInfo___::get_GenericTypeParameters() {
  if (!get_IsGenericTypeDefinition()) {
    return Type::in::EmptyTypes;
  }
  return GetGenericArguments();
}

IEnumerable<ConstructorInfo> TypeInfo___::get_DeclaredConstructors() {
}

IEnumerable<EventInfo> TypeInfo___::get_DeclaredEvents() {
}

IEnumerable<FieldInfo> TypeInfo___::get_DeclaredFields() {
}

IEnumerable<MemberInfo> TypeInfo___::get_DeclaredMembers() {
}

IEnumerable<MethodInfo> TypeInfo___::get_DeclaredMethods() {
}

IEnumerable<TypeInfo> TypeInfo___::get_DeclaredNestedTypes() {
}

IEnumerable<PropertyInfo> TypeInfo___::get_DeclaredProperties() {
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
}

FieldInfo TypeInfo___::GetDeclaredField(String name) {
}

MethodInfo TypeInfo___::GetDeclaredMethod(String name) {
}

TypeInfo TypeInfo___::GetDeclaredNestedType(String name) {
}

PropertyInfo TypeInfo___::GetDeclaredProperty(String name) {
}

IEnumerable<MethodInfo> TypeInfo___::GetDeclaredMethods(String name) {
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
