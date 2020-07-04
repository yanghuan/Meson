#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace RuntimeEventSourceHelperNamespace {
class RuntimeEventSourceHelper {
  public: static Int32 GetCpuUsage();
  private: static Int64 s_prevProcUserTime;
  private: static Int64 s_prevProcKernelTime;
  private: static Int64 s_prevSystemUserTime;
  private: static Int64 s_prevSystemKernelTime;
};
} // namespace RuntimeEventSourceHelperNamespace
using RuntimeEventSourceHelper = RuntimeEventSourceHelperNamespace::RuntimeEventSourceHelper;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
