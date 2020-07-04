#include "MethodInfo-dep.h"

#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::MethodInfoNamespace {
MemberTypes MethodInfo___::get_MemberType() {
  return MemberTypes::All;
};
ParameterInfo MethodInfo___::get_ReturnParameter() {
  return nullptr;
};
Type MethodInfo___::get_ReturnType() {
  return nullptr;
};
Int32 MethodInfo___::get_GenericParameterCount() {
  return Int32();
};
Array<Type> MethodInfo___::GetGenericArguments() {
  return Array<Type>();
};
MethodInfo MethodInfo___::GetGenericMethodDefinition() {
  return nullptr;
};
MethodInfo MethodInfo___::MakeGenericMethod(Array<Type> typeArguments) {
  return nullptr;
};
Delegate MethodInfo___::CreateDelegate(Type delegateType) {
  return nullptr;
};
Delegate MethodInfo___::CreateDelegate(Type delegateType, Object target) {
  return nullptr;
};
Boolean MethodInfo___::Equals(Object obj) {
  return Boolean();
};
Int32 MethodInfo___::GetHashCode() {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Reflection::MethodInfoNamespace
