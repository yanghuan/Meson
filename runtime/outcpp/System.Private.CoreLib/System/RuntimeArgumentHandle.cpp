#include "RuntimeArgumentHandle-dep.h"

namespace System::Private::CoreLib::System::RuntimeArgumentHandleNamespace {
IntPtr RuntimeArgumentHandle::get_Value() {
  return m_ptr;
}

} // namespace System::Private::CoreLib::System::RuntimeArgumentHandleNamespace
