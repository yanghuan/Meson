#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::Internal::Threading::Tasks {
namespace AsyncCausalitySupportNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
class AsyncCausalitySupport {
  public: static Boolean get_LoggingOn();
  public: static void AddToActiveTasks(Task<> task);
  public: static void RemoveFromActiveTasks(Task<> task);
  public: static void TraceOperationCreation(Task<> task, String operationName);
  public: static void TraceOperationCompletedSuccess(Task<> task);
  public: static void TraceOperationCompletedError(Task<> task);
};
} // namespace AsyncCausalitySupportNamespace
using AsyncCausalitySupport = AsyncCausalitySupportNamespace::AsyncCausalitySupport;
} // namespace System::Private::CoreLib::Internal::Threading::Tasks
