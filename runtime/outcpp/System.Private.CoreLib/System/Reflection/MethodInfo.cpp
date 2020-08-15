#include "MethodInfo-dep.h"

#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::MethodInfoNamespace {
MemberTypes MethodInfo___::get_MemberType() {
  return MemberTypes::Method;
}

ParameterInfo MethodInfo___::get_ReturnParameter() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Type MethodInfo___::get_ReturnType() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 MethodInfo___::get_GenericParameterCount() {
  return GetGenericArguments()->get_Length();
}

void MethodInfo___::ctor() {
}

Array<Type> MethodInfo___::GetGenericArguments() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

MethodInfo MethodInfo___::GetGenericMethodDefinition() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

MethodInfo MethodInfo___::MakeGenericMethod(Array<Type> typeArguments) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Delegate MethodInfo___::CreateDelegate(Type delegateType) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Delegate MethodInfo___::CreateDelegate(Type delegateType, Object target) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Boolean MethodInfo___::Equals(Object obj) {
  return MethodBase::Equals(obj);
}

Int32 MethodInfo___::GetHashCode() {
  return MethodBase::GetHashCode();
}

Boolean MethodInfo___::op_Equality(MethodInfo left, MethodInfo right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  auto& default = left;
  auto& extern = default == nullptr ? nullptr : default->Equals(right);
  return extern != nullptr ? extern : false;
}

Boolean MethodInfo___::op_Inequality(MethodInfo left, MethodInfo right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Reflection::MethodInfoNamespace
