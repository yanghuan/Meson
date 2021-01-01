#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AwaitTaskContinuation.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace SynchronizationContextAwaitTaskContinuationNamespace {
CLASS(SynchronizationContextAwaitTaskContinuation) : public AwaitTaskContinuation::in {
  private: CLASS(__c__DisplayClass6_0) : public object {
    public: void ctor();
    public: void _GetActionLogDelegate_b__0();
    public: Int32 continuationId;
    public: Action<> action;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__8_0(Object state);
    public: static __c __9;
  };
  public: void ctor(SynchronizationContext context, Action<> action, Boolean flowExecutionContext);
  public: void Run(Task<> task, Boolean canInlineContinuationTask);
  private: static void PostAction(Object state);
  private: static Action<> GetActionLogDelegate(Int32 continuationId, Action<> action);
  private: static ContextCallback<> GetPostActionCallback();
  public: static void cctor();
  private: static SendOrPostCallback s_postCallback;
  private: static ContextCallback<> s_postActionCallback;
  private: SynchronizationContext m_syncContext;
};
} // namespace SynchronizationContextAwaitTaskContinuationNamespace
using SynchronizationContextAwaitTaskContinuation = SynchronizationContextAwaitTaskContinuationNamespace::SynchronizationContextAwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
