#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Delegate)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
namespace TaskContinuationNamespace {
CLASS(TaskContinuation) : public object {
  public: void Run(Task<> completedTask, Boolean canInlineContinuationTask);
  protected: static void InlineIfPossibleOrElseQueue(Task<> task, Boolean needsProtection);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  public: void ctor();
};
} // namespace TaskContinuationNamespace
using TaskContinuation = TaskContinuationNamespace::TaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
