#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/AwaitTaskContinuation.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace SynchronizationContextAwaitTaskContinuationNamespace {
CLASS(SynchronizationContextAwaitTaskContinuation) : public AwaitTaskContinuation::in {
  public: void ctor(SynchronizationContext context, Action<> action, Boolean flowExecutionContext);
  public: void Run(Task<> task, Boolean canInlineContinuationTask);
  private: static void PostAction(Object state);
  private: static Action<> GetActionLogDelegate(Int32 continuationId, Action<> action);
  private: static ContextCallback GetPostActionCallback();
  private: static void cctor();
  private: static SendOrPostCallback s_postCallback;
  private: static ContextCallback s_postActionCallback;
  private: SynchronizationContext m_syncContext;
};
} // namespace SynchronizationContextAwaitTaskContinuationNamespace
using SynchronizationContextAwaitTaskContinuation = SynchronizationContextAwaitTaskContinuationNamespace::SynchronizationContextAwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
