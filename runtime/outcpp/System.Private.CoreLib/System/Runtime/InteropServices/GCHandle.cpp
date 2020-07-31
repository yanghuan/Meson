#include "GCHandle-dep.h"

#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::GCHandleNamespace {
Object GCHandle::get_Target() {
  return nullptr;
}

void GCHandle::set_Target(Object value) {
}

Boolean GCHandle::get_IsAllocated() {
  return Boolean();
}

Object GCHandle::InternalGet(IntPtr handle) {
  return nullptr;
}

GCHandle::GCHandle(Object value, GCHandleType type) {
}

GCHandle::GCHandle(IntPtr handle) {
}

GCHandle GCHandle::Alloc(Object value) {
  return GCHandle();
}

GCHandle GCHandle::Alloc(Object value, GCHandleType type) {
  return GCHandle();
}

void GCHandle::Free() {
}

IntPtr GCHandle::AddrOfPinnedObject() {
  return IntPtr();
}

GCHandle GCHandle::op_Explicit(IntPtr value) {
  return GCHandle();
}

GCHandle GCHandle::FromIntPtr(IntPtr value) {
  return GCHandle();
}

IntPtr GCHandle::op_Explicit(GCHandle value) {
  return IntPtr();
}

IntPtr GCHandle::ToIntPtr(GCHandle value) {
  return IntPtr();
}

Int32 GCHandle::GetHashCode() {
  return Int32();
}

Boolean GCHandle::Equals(Object o) {
  return Boolean();
}

Boolean GCHandle::op_Equality(GCHandle a, GCHandle b) {
  return Boolean();
}

Boolean GCHandle::op_Inequality(GCHandle a, GCHandle b) {
  return Boolean();
}

IntPtr GCHandle::GetHandleValue(IntPtr handle) {
  return IntPtr();
}

Boolean GCHandle::IsPinned(IntPtr handle) {
  return Boolean();
}

void GCHandle::ThrowIfInvalid(IntPtr handle) {
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::GCHandleNamespace
