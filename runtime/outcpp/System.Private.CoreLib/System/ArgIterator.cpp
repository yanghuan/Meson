#include "ArgIterator-dep.h"

namespace System::Private::CoreLib::System::ArgIteratorNamespace {
ArgIterator::ArgIterator(RuntimeArgumentHandle arglist) {
}

ArgIterator::ArgIterator(RuntimeArgumentHandle arglist, void* ptr) {
}

TypedReference ArgIterator::GetNextArg() {
  return TypedReference();
}

TypedReference ArgIterator::GetNextArg(RuntimeTypeHandle rth) {
  return TypedReference();
}

void ArgIterator::End() {
}

RuntimeTypeHandle ArgIterator::GetNextArgType() {
  return RuntimeTypeHandle();
}

Int32 ArgIterator::GetHashCode() {
  return Int32();
}

Boolean ArgIterator::Equals(Object o) {
  return Boolean();
}

} // namespace System::Private::CoreLib::System::ArgIteratorNamespace
