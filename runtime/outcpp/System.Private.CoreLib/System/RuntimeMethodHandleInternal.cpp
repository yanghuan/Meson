#include "RuntimeMethodHandleInternal-dep.h"

#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>

namespace System::Private::CoreLib::System::RuntimeMethodHandleInternalNamespace {
RuntimeMethodHandleInternal RuntimeMethodHandleInternal::get_EmptyHandle() {
  return rt::default__;
}

IntPtr RuntimeMethodHandleInternal::get_Value() {
  return m_handle;
}

Boolean RuntimeMethodHandleInternal::IsNullHandle() {
  return m_handle == IntPtr::Zero;
}

RuntimeMethodHandleInternal::RuntimeMethodHandleInternal(IntPtr value) {
  m_handle = value;
}

} // namespace System::Private::CoreLib::System::RuntimeMethodHandleInternalNamespace
