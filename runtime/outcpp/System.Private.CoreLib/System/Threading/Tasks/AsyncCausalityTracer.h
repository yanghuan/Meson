#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace AsyncCausalityTracerNamespace {
class AsyncCausalityTracer : public Object::in {
  public: static Boolean get_LoggingOn();
};
} // namespace AsyncCausalityTracerNamespace
using AsyncCausalityTracer = AsyncCausalityTracerNamespace::AsyncCausalityTracer;
} // namespace System::Private::CoreLib::System::Threading::Tasks
