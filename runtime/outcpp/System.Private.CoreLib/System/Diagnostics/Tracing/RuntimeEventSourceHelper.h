#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace RuntimeEventSourceHelperNamespace {
CLASS(RuntimeEventSourceHelper) {
  public: static Int32 GetCpuUsage();
  private: static Int64 prevProcUserTime;
  private: static Int64 prevProcKernelTime;
  private: static Int64 prevSystemUserTime;
  private: static Int64 prevSystemKernelTime;
};
} // namespace RuntimeEventSourceHelperNamespace
using RuntimeEventSourceHelper = RuntimeEventSourceHelperNamespace::RuntimeEventSourceHelper;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
