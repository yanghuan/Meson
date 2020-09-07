#include "Pointer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Pointer-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::PointerNamespace {
void Pointer___::ctor(void* ptr, Type ptrType) {
  _ptr = ptr;
  _ptrType = ptrType;
}

Object Pointer___::Box(void* ptr, Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (!type->get_IsPointer()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePointer(), "ptr");
  }
  if (!type->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "ptr");
  }
  return rt::newobj<Pointer>(ptr, type);
}

void* Pointer___::Unbox(Object ptr) {
  if (!rt::is<Pointer>(ptr)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePointer(), "ptr");
  }
  return ((Pointer)ptr)->_ptr;
}

void Pointer___::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Type Pointer___::GetPointerType() {
  return _ptrType;
}

IntPtr Pointer___::GetPointerValue() {
  return (IntPtr)_ptr;
}

} // namespace System::Private::CoreLib::System::Reflection::PointerNamespace
