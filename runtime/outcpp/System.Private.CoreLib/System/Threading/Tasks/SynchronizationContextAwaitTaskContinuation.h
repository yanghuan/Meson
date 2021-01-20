#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AwaitTaskContinuation.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
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
  private: static ContextCallback GetPostActionCallback();
  public: static void cctor();
  private: static SendOrPostCallback s_postCallback;
  private: static ContextCallback s_postActionCallback;
  private: SynchronizationContext m_syncContext;
};
} // namespace SynchronizationContextAwaitTaskContinuationNamespace
using SynchronizationContextAwaitTaskContinuation = SynchronizationContextAwaitTaskContinuationNamespace::SynchronizationContextAwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
