#include "TypeInfo-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/IntrospectionExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/TypeInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::TypeInfoNamespace {
MethodInfo TypeInfo___::_GetDeclaredMethods_d__10___::get_CurrentOfMethodInfo() {
  return __2__current;
}

Object TypeInfo___::_GetDeclaredMethods_d__10___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void TypeInfo___::_GetDeclaredMethods_d__10___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void TypeInfo___::_GetDeclaredMethods_d__10___::DisposeOfIDisposable() {
}

Boolean TypeInfo___::_GetDeclaredMethods_d__10___::MoveNext() {
  Int32 num = __1__state;
  TypeInfo typeInfo = __4__this;
  if (num != 0) {
    if (num != 1) {
      return false;
    }
    __1__state = -1;
    goto IL_006d;
  }
  __1__state = -1;
  __7__wrap1 = typeInfo->GetMethods(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
  __7__wrap2 = 0;
  goto IL_007b;

IL_006d:
  __7__wrap2++;
  goto IL_007b;

IL_007b:
  if (__7__wrap2 < __7__wrap1->get_Length()) {
    MethodInfo methodInfo = __7__wrap1[__7__wrap2];
    if (methodInfo->get_Name() == name) {
      __2__current = methodInfo;
      __1__state = 1;
      return true;
    }
    goto IL_006d;
  }
  __7__wrap1 = nullptr;
  return false;
}

void TypeInfo___::_GetDeclaredMethods_d__10___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<MethodInfo> TypeInfo___::_GetDeclaredMethods_d__10___::GetEnumeratorOfMethodInfo() {
  _GetDeclaredMethods_d__10 _GetDeclaredMethods_d__;
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    _GetDeclaredMethods_d__ = (_GetDeclaredMethods_d__10)this;
  } else {
    _GetDeclaredMethods_d__ = rt::newobj<_GetDeclaredMethods_d__10>(0);
  }
  _GetDeclaredMethods_d__->name = __3__name;
  return _GetDeclaredMethods_d__;
}

IEnumerator_ TypeInfo___::_GetDeclaredMethods_d__10___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<MethodInfo>)(_GetDeclaredMethods_d__10)this)->GetEnumerator();
}

TypeInfo TypeInfo___::_get_DeclaredNestedTypes_d__22___::get_CurrentOfTypeInfo() {
  return __2__current;
}

Object TypeInfo___::_get_DeclaredNestedTypes_d__22___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void TypeInfo___::_get_DeclaredNestedTypes_d__22___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void TypeInfo___::_get_DeclaredNestedTypes_d__22___::DisposeOfIDisposable() {
}

Boolean TypeInfo___::_get_DeclaredNestedTypes_d__22___::MoveNext() {
  Int32 num = __1__state;
  TypeInfo typeInfo = __4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      __1__state = -1;
      __7__wrap1 = typeInfo->GetNestedTypes(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
      __7__wrap2 = 0;
      break;
    case 1:
      __1__state = -1;
      __7__wrap2++;
      break;
  }
  if (__7__wrap2 < __7__wrap1->get_Length()) {
    Type type = __7__wrap1[__7__wrap2];
    __2__current = IntrospectionExtensions::GetTypeInfo(type);
    __1__state = 1;
    return true;
  }
  __7__wrap1 = nullptr;
  return false;
}

void TypeInfo___::_get_DeclaredNestedTypes_d__22___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<TypeInfo> TypeInfo___::_get_DeclaredNestedTypes_d__22___::GetEnumeratorOfTypeInfo() {
  _get_DeclaredNestedTypes_d__22 result;
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    result = (_get_DeclaredNestedTypes_d__22)this;
  } else {
    result = rt::newobj<_get_DeclaredNestedTypes_d__22>(0);
  }
  return result;
}

IEnumerator_ TypeInfo___::_get_DeclaredNestedTypes_d__22___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<TypeInfo>)(_get_DeclaredNestedTypes_d__22)this)->GetEnumerator();
}

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
  for (Type&& type : *nestedTypes) {
  }
}

IEnumerable<PropertyInfo> TypeInfo___::get_DeclaredProperties() {
  return GetProperties(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
}

IEnumerable<Type> TypeInfo___::get_ImplementedInterfaces() {
  return GetInterfaces();
}

void TypeInfo___::ctor() {
}

TypeInfo TypeInfo___::GetTypeInfoOfIReflectableType() {
  return (TypeInfo)this;
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
  for (MethodInfo&& methodInfo : *methods) {
    if (methodInfo->get_Name() == name) {
    }
  }
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
    return "[" + rt::newstr<String>(',', rank - 1) + "]";
  }
  return "[*]";
}

} // namespace System::Private::CoreLib::System::Reflection::TypeInfoNamespace
