#include "PunkSafeHandle-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/PunkSafeHandle-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::PunkSafeHandleNamespace {
Boolean PunkSafeHandle___::get_IsInvalid() {
  return handle == (IntPtr)0;
}

Boolean PunkSafeHandle___::ReleaseHandle() {
  m_Release(handle);
  return true;
}

void PunkSafeHandle___::cctor() {
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::PunkSafeHandleNamespace
