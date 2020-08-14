#include "SafeHandleCleanupWorkListElement-dep.h"

#include <System.Private.CoreLib/System/StubHelpers/StubHelpers-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::SafeHandleCleanupWorkListElementNamespace {
void SafeHandleCleanupWorkListElement___::ctor(SafeHandle handle) {
  m_handle = handle;
}

void SafeHandleCleanupWorkListElement___::DestroyCore() {
  if (m_owned) {
    StubHelpers::SafeHandleRelease(m_handle);
  }
}

IntPtr SafeHandleCleanupWorkListElement___::AddRef() {
  return StubHelpers::SafeHandleAddRef(m_handle, m_owned);
}

} // namespace System::Private::CoreLib::System::StubHelpers::SafeHandleCleanupWorkListElementNamespace
