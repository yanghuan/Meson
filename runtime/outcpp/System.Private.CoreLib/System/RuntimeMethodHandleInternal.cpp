#include "RuntimeMethodHandleInternal-dep.h"

#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>

namespace System::Private::CoreLib::System::RuntimeMethodHandleInternalNamespace {
RuntimeMethodHandleInternal RuntimeMethodHandleInternal::get_EmptyHandle() {
  return RuntimeMethodHandleInternal();
};

IntPtr RuntimeMethodHandleInternal::get_Value() {
  return IntPtr();
};

Boolean RuntimeMethodHandleInternal::IsNullHandle() {
  return Boolean();
};

void RuntimeMethodHandleInternal::Ctor(IntPtr value) {
};

} // namespace System::Private::CoreLib::System::RuntimeMethodHandleInternalNamespace
