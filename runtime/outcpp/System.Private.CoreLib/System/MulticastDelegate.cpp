#include "MulticastDelegate-dep.h"

#include <System.Private.CoreLib/System/MulticastDelegate-dep.h>

namespace System::Private::CoreLib::System::MulticastDelegateNamespace {
void MulticastDelegate___::Ctor(Object target, String method) {
}

void MulticastDelegate___::Ctor(Type target, String method) {
}

Boolean MulticastDelegate___::IsUnmanagedFunctionPtr() {
  return Boolean();
}

Boolean MulticastDelegate___::InvocationListLogicallyNull() {
  return Boolean();
}

void MulticastDelegate___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

Boolean MulticastDelegate___::Equals(Object obj) {
  return Boolean();
}

Boolean MulticastDelegate___::InvocationListEquals(MulticastDelegate d) {
  return Boolean();
}

Boolean MulticastDelegate___::TrySetSlot(Array<Object> a, Int32 index, Object o) {
  return Boolean();
}

MulticastDelegate MulticastDelegate___::NewMulticastDelegate(Array<Object> invocationList, Int32 invocationCount, Boolean thisIsMultiCastAlready) {
  return nullptr;
}

MulticastDelegate MulticastDelegate___::NewMulticastDelegate(Array<Object> invocationList, Int32 invocationCount) {
  return nullptr;
}

void MulticastDelegate___::StoreDynamicMethod(MethodInfo dynamicMethod) {
}

Delegate MulticastDelegate___::CombineImpl(Delegate follow) {
  return nullptr;
}

Array<Object> MulticastDelegate___::DeleteFromInvocationList(Array<Object> invocationList, Int32 invocationCount, Int32 deleteIndex, Int32 deleteCount) {
  return Array<Object>();
}

Boolean MulticastDelegate___::EqualInvocationLists(Array<Object> a, Array<Object> b, Int32 start, Int32 count) {
  return Boolean();
}

Delegate MulticastDelegate___::RemoveImpl(Delegate value) {
  return nullptr;
}

Array<Delegate> MulticastDelegate___::GetInvocationList() {
  return Array<Delegate>();
}

Boolean MulticastDelegate___::op_Equality(MulticastDelegate d1, MulticastDelegate d2) {
  return Boolean();
}

Boolean MulticastDelegate___::op_Inequality(MulticastDelegate d1, MulticastDelegate d2) {
  return Boolean();
}

Int32 MulticastDelegate___::GetHashCode() {
  return Int32();
}

Object MulticastDelegate___::GetTarget() {
  return nullptr;
}

MethodInfo MulticastDelegate___::GetMethodImpl() {
  return nullptr;
}

void MulticastDelegate___::ThrowNullThisInDelegateToInstance() {
}

void MulticastDelegate___::CtorClosed(Object target, IntPtr methodPtr) {
}

void MulticastDelegate___::CtorClosedStatic(Object target, IntPtr methodPtr) {
}

void MulticastDelegate___::CtorRTClosed(Object target, IntPtr methodPtr) {
}

void MulticastDelegate___::CtorOpened(Object target, IntPtr methodPtr, IntPtr shuffleThunk) {
}

void MulticastDelegate___::CtorVirtualDispatch(Object target, IntPtr methodPtr, IntPtr shuffleThunk) {
}

void MulticastDelegate___::CtorCollectibleClosedStatic(Object target, IntPtr methodPtr, IntPtr gchandle) {
}

void MulticastDelegate___::CtorCollectibleOpened(Object target, IntPtr methodPtr, IntPtr shuffleThunk, IntPtr gchandle) {
}

void MulticastDelegate___::CtorCollectibleVirtualDispatch(Object target, IntPtr methodPtr, IntPtr shuffleThunk, IntPtr gchandle) {
}

} // namespace System::Private::CoreLib::System::MulticastDelegateNamespace
