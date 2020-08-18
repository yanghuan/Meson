#include "RuntimeEventSourceHelper-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::RuntimeEventSourceHelperNamespace {
Int32 RuntimeEventSourceHelper::GetCpuUsage() {
  Int64 creation;
  Int64 exit;
  Int64 kernel;
  Int64 user;
  if (!Interop::Kernel32::GetProcessTimes(Interop::Kernel32::GetCurrentProcess(), creation, exit, kernel, user)) {
    return 0;
  }
  Int64 kernel2;
  Int64 user2;
  if (!Interop::Kernel32::GetSystemTimes(exit, kernel2, user2)) {
    return 0;
  }
  Int32 result;
  if (s_prevSystemUserTime == 0 && s_prevSystemKernelTime == 0) {
    result = 0;
  } else {
    Int64 num = user - s_prevProcUserTime + (kernel - s_prevProcKernelTime);
    Int64 num2 = kernel2 - s_prevSystemUserTime + (user2 - s_prevSystemKernelTime);
    result = (Int32)(num * 100 / num2);
  }
  s_prevProcUserTime = user;
  s_prevProcKernelTime = kernel;
  s_prevSystemUserTime = kernel2;
  s_prevSystemKernelTime = user2;
  return result;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::RuntimeEventSourceHelperNamespace
