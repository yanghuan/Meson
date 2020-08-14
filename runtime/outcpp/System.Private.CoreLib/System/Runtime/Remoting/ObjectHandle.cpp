#include "ObjectHandle-dep.h"

namespace System::Private::CoreLib::System::Runtime::Remoting::ObjectHandleNamespace {
void ObjectHandle___::ctor(Object o) {
  _wrappedObject = o;
}

Object ObjectHandle___::Unwrap() {
  return _wrappedObject;
}

} // namespace System::Private::CoreLib::System::Runtime::Remoting::ObjectHandleNamespace
