#include "PunkSafeHandle-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/PunkSafeHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::PunkSafeHandleNamespace {
using namespace System::Runtime::InteropServices;

Boolean PunkSafeHandle___::get_IsInvalid() {
  return handle == (IntPtr)(Int32)0;
}

Boolean PunkSafeHandle___::ReleaseHandle() {
  m_Release(handle);
  return true;
}

void PunkSafeHandle___::cctor() {
  m_Release = (DRelease)Marshal::GetDelegateForFunctionPointer(nGetDReleaseTarget(), typeof<DRelease>());
  m_Release((IntPtr)(Int32)0);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::PunkSafeHandleNamespace
