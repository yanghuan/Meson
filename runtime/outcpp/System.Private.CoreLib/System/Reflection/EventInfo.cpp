#include "EventInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::EventInfoNamespace {
MemberTypes EventInfo___::get_MemberType() {
  return MemberTypes::All;
};

Boolean EventInfo___::get_IsSpecialName() {
  return Boolean();
};

MethodInfo EventInfo___::get_AddMethod() {
  return nullptr;
};

MethodInfo EventInfo___::get_RemoveMethod() {
  return nullptr;
};

MethodInfo EventInfo___::get_RaiseMethod() {
  return nullptr;
};

Boolean EventInfo___::get_IsMulticast() {
  return Boolean();
};

Type EventInfo___::get_EventHandlerType() {
  return nullptr;
};

Array<MethodInfo> EventInfo___::GetOtherMethods() {
  return Array<MethodInfo>();
};

Array<MethodInfo> EventInfo___::GetOtherMethods(Boolean nonPublic) {
  return Array<MethodInfo>();
};

MethodInfo EventInfo___::GetAddMethod() {
  return nullptr;
};

MethodInfo EventInfo___::GetRemoveMethod() {
  return nullptr;
};

MethodInfo EventInfo___::GetRaiseMethod() {
  return nullptr;
};

void EventInfo___::AddEventHandler(Object target, Delegate handler) {
};

void EventInfo___::RemoveEventHandler(Object target, Delegate handler) {
};

Boolean EventInfo___::Equals(Object obj) {
  return Boolean();
};

Int32 EventInfo___::GetHashCode() {
  return Int32();
};

Boolean EventInfo___::op_Equality(EventInfo left, EventInfo right) {
  return Boolean();
};

Boolean EventInfo___::op_Inequality(EventInfo left, EventInfo right) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Reflection::EventInfoNamespace
