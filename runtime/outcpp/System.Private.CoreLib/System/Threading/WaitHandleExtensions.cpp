#include "WaitHandleExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Threading::WaitHandleExtensionsNamespace {
SafeWaitHandle WaitHandleExtensions::GetSafeWaitHandle(WaitHandle waitHandle) {
  if (waitHandle == nullptr) {
    rt::throw_exception<ArgumentNullException>("waitHandle");
  }
  return waitHandle->get_SafeWaitHandle();
}

void WaitHandleExtensions::SetSafeWaitHandle(WaitHandle waitHandle, SafeWaitHandle value) {
  if (waitHandle == nullptr) {
    rt::throw_exception<ArgumentNullException>("waitHandle");
  }
  waitHandle->set_SafeWaitHandle(value);
}

} // namespace System::Private::CoreLib::System::Threading::WaitHandleExtensionsNamespace
