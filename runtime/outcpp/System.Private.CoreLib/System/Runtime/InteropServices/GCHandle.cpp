#include "GCHandle-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::GCHandleNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;

Object GCHandle::get_Target() {
  IntPtr handle = _handle;
  ThrowIfInvalid(handle);
  return InternalGet(GetHandleValue(handle));
}

void GCHandle::set_Target(Object value) {
  IntPtr handle = _handle;
  ThrowIfInvalid(handle);
  if (IsPinned(handle) && !Marshal::IsPinnable(value)) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentException_NotIsomorphic(), "value");
  }
  InternalSet(GetHandleValue(handle), value);
}

Boolean GCHandle::get_IsAllocated() {
  return _handle != IntPtr::Zero;
}

Object GCHandle::InternalGet(IntPtr handle) {
  return Unsafe::As<IntPtr, Object>(*(IntPtr*)(void*)handle);
}

GCHandle::GCHandle(Object value, GCHandleType type) {
  switch (type) {
    default:
      rt::throw_exception<ArgumentOutOfRangeException>("type", SR::get_ArgumentOutOfRange_Enum());
    case GCHandleType::Pinned:
      if (!Marshal::IsPinnable(value)) {
        rt::throw_exception<ArgumentException>(SR::get_ArgumentException_NotIsomorphic(), "value");
      }
      break;
    case GCHandleType::Weak:
    case GCHandleType::WeakTrackResurrection:
    case GCHandleType::Normal:
      break;
  }
  IntPtr intPtr = InternalAlloc(value, type);
  if (type == GCHandleType::Pinned) {
    intPtr = (IntPtr)(void*)((Int64)intPtr | 1);
  }
  _handle = intPtr;
}

GCHandle::GCHandle(IntPtr handle) {
  _handle = handle;
}

GCHandle GCHandle::Alloc(Object value) {
  return GCHandle(value, GCHandleType::Normal);
}

GCHandle GCHandle::Alloc(Object value, GCHandleType type) {
  return GCHandle(value, type);
}

void GCHandle::Free() {
  IntPtr handle = Interlocked::Exchange(_handle, IntPtr::Zero);
  ThrowIfInvalid(handle);
  InternalFree(GetHandleValue(handle));
}

IntPtr GCHandle::AddrOfPinnedObject() {
  IntPtr handle = _handle;
  ThrowIfInvalid(handle);
  if (!IsPinned(handle)) {
    ThrowHelper::ThrowInvalidOperationException_HandleIsNotPinned();
  }
  Object obj = InternalGet(GetHandleValue(handle));
  if (obj == nullptr) {
    return (IntPtr)0;
  }
  if (RuntimeHelpers::ObjectHasComponentSize(obj)) {
    if (obj->GetType() == typeof<String>()) {
      return (IntPtr)Unsafe::AsPointer(Unsafe::As<String>(obj)->GetRawStringData());
    }
    return (IntPtr)Unsafe::AsPointer(RuntimeHelpers::GetRawArrayData(Unsafe::As<Array<>>(obj)));
  }
  return (IntPtr)Unsafe::AsPointer(RuntimeHelpers::GetRawData(obj));
}

GCHandle GCHandle::op_Explicit(IntPtr value) {
  return FromIntPtr(value);
}

GCHandle GCHandle::FromIntPtr(IntPtr value) {
  ThrowIfInvalid(value);
  return GCHandle(value);
}

IntPtr GCHandle::op_Explicit(GCHandle value) {
  return ToIntPtr(value);
}

IntPtr GCHandle::ToIntPtr(GCHandle value) {
  return value._handle;
}

Int32 GCHandle::GetHashCode() {
  return _handle.GetHashCode();
}

Boolean GCHandle::Equals(Object o) {
  if (rt::is<GCHandle>(o)) {
    return _handle == ((GCHandle)o)._handle;
  }
  return false;
}

Boolean GCHandle::op_Equality(GCHandle a, GCHandle b) {
  return a._handle == b._handle;
}

Boolean GCHandle::op_Inequality(GCHandle a, GCHandle b) {
  return a._handle != b._handle;
}

IntPtr GCHandle::GetHandleValue(IntPtr handle) {
  return IntPtr((Int64)(IntPtr)(void*)((Int64)handle & (Int64)(IntPtr)(void*)(~1)));
}

Boolean GCHandle::IsPinned(IntPtr handle) {
  return (IntPtr)(void*)((Int64)handle & 1) != (IntPtr)0;
}

void GCHandle::ThrowIfInvalid(IntPtr handle) {
  if (handle == IntPtr::Zero) {
    ThrowHelper::ThrowInvalidOperationException_HandleIsNotInitialized();
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::GCHandleNamespace
