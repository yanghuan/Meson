#include "HandleRef-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::HandleRefNamespace {
Object HandleRef::get_Wrapper() {
  return nullptr;
};

IntPtr HandleRef::get_Handle() {
  return IntPtr();
};

void HandleRef::Ctor(Object wrapper, IntPtr handle) {
};

IntPtr HandleRef::op_Explicit(HandleRef value) {
  return IntPtr();
};

IntPtr HandleRef::ToIntPtr(HandleRef value) {
  return IntPtr();
};

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::HandleRefNamespace
