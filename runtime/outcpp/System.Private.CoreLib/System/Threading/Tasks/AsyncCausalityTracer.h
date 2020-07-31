#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace AsyncCausalityTracerNamespace {
class AsyncCausalityTracer {
  public: static Boolean get_LoggingOn();
};
} // namespace AsyncCausalityTracerNamespace
using AsyncCausalityTracer = AsyncCausalityTracerNamespace::AsyncCausalityTracer;
} // namespace System::Private::CoreLib::System::Threading::Tasks
