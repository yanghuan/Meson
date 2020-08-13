#include "RuntimeFieldHandleInternal-dep.h"

namespace System::Private::CoreLib::System::RuntimeFieldHandleInternalNamespace {
IntPtr RuntimeFieldHandleInternal::get_Value() {
  return m_handle;
}

RuntimeFieldHandleInternal::RuntimeFieldHandleInternal(IntPtr value) {
  m_handle = value;
}

} // namespace System::Private::CoreLib::System::RuntimeFieldHandleInternalNamespace
