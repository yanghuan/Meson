#include "EventInfo-dep.h"

#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MulticastDelegate-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::EventInfoNamespace {
MemberTypes EventInfo___::get_MemberType() {
  return MemberTypes::Event;
}

Boolean EventInfo___::get_IsSpecialName() {
  return (get_Attributes() & EventAttributes::SpecialName) != 0;
}

MethodInfo EventInfo___::get_AddMethod() {
  return GetAddMethod(true);
}

MethodInfo EventInfo___::get_RemoveMethod() {
  return GetRemoveMethod(true);
}

MethodInfo EventInfo___::get_RaiseMethod() {
  return GetRaiseMethod(true);
}

Boolean EventInfo___::get_IsMulticast() {
  Type eventHandlerType = get_EventHandlerType();
  Type typeFromHandle = typeof<MulticastDelegate>();
  return typeFromHandle->IsAssignableFrom(eventHandlerType);
}

Type EventInfo___::get_EventHandlerType() {
  MethodInfo addMethod = GetAddMethod(true);
  Array<ParameterInfo> parametersNoCopy = addMethod->GetParametersNoCopy();
  Type typeFromHandle = typeof<Delegate>();
  for (Int32 i = 0; i < parametersNoCopy->get_Length(); i++) {
    Type parameterType = parametersNoCopy[i]->get_ParameterType();
    if (parameterType->IsSubclassOf(typeFromHandle)) {
      return parameterType;
    }
  }
  return nullptr;
}

void EventInfo___::ctor() {
}

Array<MethodInfo> EventInfo___::GetOtherMethods() {
  return GetOtherMethods(false);
}

Array<MethodInfo> EventInfo___::GetOtherMethods(Boolean nonPublic) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

MethodInfo EventInfo___::GetAddMethod() {
  return GetAddMethod(false);
}

MethodInfo EventInfo___::GetRemoveMethod() {
  return GetRemoveMethod(false);
}

MethodInfo EventInfo___::GetRaiseMethod() {
  return GetRaiseMethod(false);
}

void EventInfo___::AddEventHandler(Object target, Delegate handler) {
  MethodInfo addMethod = GetAddMethod(false);
  if (addMethod == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NoPublicAddMethod());
  }
  addMethod->Invoke(target, rt::newarr<Array<Object>>(1));
}

void EventInfo___::RemoveEventHandler(Object target, Delegate handler) {
  MethodInfo removeMethod = GetRemoveMethod(false);
  if (removeMethod == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NoPublicRemoveMethod());
  }
  removeMethod->Invoke(target, rt::newarr<Array<Object>>(1));
}

Boolean EventInfo___::Equals(Object obj) {
  return MemberInfo::in::Equals(obj);
}

Int32 EventInfo___::GetHashCode() {
  return MemberInfo::in::GetHashCode();
}

Boolean EventInfo___::op_Equality(EventInfo left, EventInfo right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  if ((Object)left != nullptr) {
    return left->Equals(right);
  }
  return false;
}

Boolean EventInfo___::op_Inequality(EventInfo left, EventInfo right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Reflection::EventInfoNamespace
