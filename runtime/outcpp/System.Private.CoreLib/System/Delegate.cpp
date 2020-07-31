#include "Delegate-dep.h"

#include <System.Private.CoreLib/System/Delegate-dep.h>

namespace System::Private::CoreLib::System::DelegateNamespace {
Object Delegate___::get_Target() {
  return nullptr;
}

MethodInfo Delegate___::get_Method() {
  return nullptr;
}

void Delegate___::Ctor(Object target, String method) {
}

void Delegate___::Ctor(Type target, String method) {
}

Object Delegate___::DynamicInvokeImpl(Array<Object> args) {
  return nullptr;
}

Boolean Delegate___::Equals(Object obj) {
  return Boolean();
}

Int32 Delegate___::GetHashCode() {
  return Int32();
}

MethodInfo Delegate___::GetMethodImpl() {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Object target, String method, Boolean ignoreCase, Boolean throwOnBindFailure) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Type target, String method, Boolean ignoreCase, Boolean throwOnBindFailure) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, MethodInfo method, Boolean throwOnBindFailure) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Object firstArgument, MethodInfo method, Boolean throwOnBindFailure) {
  return nullptr;
}

Delegate Delegate___::CreateDelegateNoSecurityCheck(Type type, Object target, RuntimeMethodHandle method) {
  return nullptr;
}

Delegate Delegate___::CreateDelegateInternal(RuntimeType rtType, RuntimeMethodInfo rtMethod, Object firstArgument, DelegateBindingFlags flags) {
  return nullptr;
}

Object Delegate___::GetTarget() {
  return nullptr;
}

Object Delegate___::Clone() {
  return nullptr;
}

Delegate Delegate___::Combine(Delegate a, Delegate b) {
  return nullptr;
}

Delegate Delegate___::Combine(Array<Delegate> delegates) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Object firstArgument, MethodInfo method) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, MethodInfo method) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Object target, String method) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Object target, String method, Boolean ignoreCase) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Type target, String method) {
  return nullptr;
}

Delegate Delegate___::CreateDelegate(Type type, Type target, String method, Boolean ignoreCase) {
  return nullptr;
}

Delegate Delegate___::CombineImpl(Delegate d) {
  return nullptr;
}

Delegate Delegate___::RemoveImpl(Delegate d) {
  return nullptr;
}

Array<Delegate> Delegate___::GetInvocationList() {
  return Array<Delegate>();
}

Object Delegate___::DynamicInvoke(Array<Object> args) {
  return nullptr;
}

void Delegate___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

Delegate Delegate___::Remove(Delegate source, Delegate value) {
  return nullptr;
}

Delegate Delegate___::RemoveAll(Delegate source, Delegate value) {
  return nullptr;
}

Boolean Delegate___::op_Equality(Delegate d1, Delegate d2) {
  return Boolean();
}

Boolean Delegate___::op_Inequality(Delegate d1, Delegate d2) {
  return Boolean();
}

} // namespace System::Private::CoreLib::System::DelegateNamespace
