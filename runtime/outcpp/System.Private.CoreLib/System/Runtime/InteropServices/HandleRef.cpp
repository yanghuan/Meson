#include "HandleRef-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::HandleRefNamespace {
Object HandleRef::get_Wrapper() {
  return _wrapper;
}

IntPtr HandleRef::get_Handle() {
  return _handle;
}

HandleRef::HandleRef(Object wrapper, IntPtr handle) {
  _wrapper = wrapper;
  _handle = handle;
}

IntPtr HandleRef::op_Explicit(HandleRef value) {
  return value._handle;
}

IntPtr HandleRef::ToIntPtr(HandleRef value) {
  return value._handle;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::HandleRefNamespace
