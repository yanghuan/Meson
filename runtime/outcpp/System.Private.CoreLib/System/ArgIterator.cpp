#include "ArgIterator-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::ArgIteratorNamespace {
ArgIterator::ArgIterator(RuntimeArgumentHandle arglist) {
}

ArgIterator::ArgIterator(RuntimeArgumentHandle arglist, void* ptr) {
}

TypedReference ArgIterator::GetNextArg() {
  TypedReference result = rt::default__;
  FCallGetNextArg(&result);
  return result;
}

TypedReference ArgIterator::GetNextArg(RuntimeTypeHandle rth) {
  if (sigPtr != IntPtr::Zero) {
    return GetNextArg();
  }
  if (ArgPtr == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>();
  }
  TypedReference result = rt::default__;
  InternalGetNextArg(&result, rth.GetRuntimeType());
  return result;
}

void ArgIterator::End() {
}

RuntimeTypeHandle ArgIterator::GetNextArgType() {
  return RuntimeTypeHandle(Type::in::GetTypeFromHandleUnsafe((IntPtr)_GetNextArgType()));
}

Int32 ArgIterator::GetHashCode() {
  return ValueType::in::GetHashCodeOfPtr(ArgCookie);
}

Boolean ArgIterator::Equals(Object o) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NYI());
}

} // namespace System::Private::CoreLib::System::ArgIteratorNamespace
