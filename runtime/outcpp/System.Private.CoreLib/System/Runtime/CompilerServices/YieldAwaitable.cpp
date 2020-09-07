#include "YieldAwaitable-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachineBox.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/YieldAwaitable-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace {
using namespace System::Diagnostics::Tracing;
using namespace System::Threading;
using namespace System::Threading::Tasks;

void YieldAwaitable::YieldAwaiter::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void YieldAwaitable::YieldAwaiter::__c___::ctor() {
}

void YieldAwaitable::YieldAwaiter::__c___::_SystemRuntimeCompilerServicesIStateMachineBoxAwareAwaiterAwaitUnsafeOnCompleted_b__5_0(Object s) {
  ((IAsyncStateMachineBox)s)->MoveNext();
}

void YieldAwaitable::YieldAwaiter::__c___::_SystemRuntimeCompilerServicesIStateMachineBoxAwareAwaiterAwaitUnsafeOnCompleted_b__5_1(Object s) {
  ((IAsyncStateMachineBox)s)->MoveNext();
}

void YieldAwaitable::YieldAwaiter::__c___::_OutputCorrelationEtwEvent_b__6_0(Action<> innerContinuation, Task<> continuationIdTask) {
  TplEventSource log = TplEventSource::in::Log;
  log->TaskWaitContinuationStarted(((Task<Int32>)continuationIdTask)->get_Result());
  Guid oldActivityThatWillContinue;
  if (log->TasksSetActivityIds) {
    EventSource::in::SetCurrentThreadActivityId(TplEventSource::in::CreateGuidForTaskID(((Task<Int32>)continuationIdTask)->get_Result()), oldActivityThatWillContinue);
  }
  innerContinuation();
  if (log->TasksSetActivityIds) {
    EventSource::in::SetCurrentThreadActivityId(oldActivityThatWillContinue);
  }
  log->TaskWaitContinuationComplete(((Task<Int32>)continuationIdTask)->get_Result());
}

Boolean YieldAwaitable::YieldAwaiter::get_IsCompleted() {
  return false;
}

void YieldAwaitable::YieldAwaiter::OnCompleted(Action<> continuation) {
  QueueContinuation(continuation, true);
}

void YieldAwaitable::YieldAwaiter::UnsafeOnCompleted(Action<> continuation) {
  QueueContinuation(continuation, false);
}

void YieldAwaitable::YieldAwaiter::QueueContinuation(Action<> continuation, Boolean flowContext) {
  if (continuation == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuation");
  }
  if (TplEventSource::in::Log->IsEnabled()) {
    continuation = OutputCorrelationEtwEvent(continuation);
  }
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  if (current != nullptr && current->GetType() != typeof<SynchronizationContext>()) {
    current->Post(s_sendOrPostCallbackRunAction, continuation);
    return;
  }
  TaskScheduler current2 = TaskScheduler::in::get_Current();
  if (current2 == TaskScheduler::in::get_Default()) {
    if (flowContext) {
      ThreadPool::QueueUserWorkItem(s_waitCallbackRunAction, continuation);
    } else {
      ThreadPool::UnsafeQueueUserWorkItem(s_waitCallbackRunAction, continuation);
    }
  } else {
    Task<>::in::get_Factory()->StartNew(continuation, rt::default__, TaskCreationOptions::PreferFairness, current2);
  }
}

void YieldAwaitable::YieldAwaiter::AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box) {
  if (TplEventSource::in::Log->IsEnabled()) {
    QueueContinuation(box->get_MoveNextAction(), false);
    return;
  }
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  if (current != nullptr && current->GetType() != typeof<SynchronizationContext>()) {
    SendOrPostCallback as = __c::in::__9__5_0;
    current->Post(as != nullptr ? as : (__c::in::__9__5_0 = &__c::in::__9->_SystemRuntimeCompilerServicesIStateMachineBoxAwareAwaiterAwaitUnsafeOnCompleted_b__5_0), box);
    return;
  }
  TaskScheduler current2 = TaskScheduler::in::get_Current();
  if (current2 == TaskScheduler::in::get_Default()) {
    ThreadPool::UnsafeQueueUserWorkItemInternal(box, false);
  } else {
    Action<Object> as = __c::in::__9__5_1;
    Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__5_1 = &__c::in::__9->_SystemRuntimeCompilerServicesIStateMachineBoxAwareAwaiterAwaitUnsafeOnCompleted_b__5_1), box, rt::default__, TaskCreationOptions::PreferFairness, current2);
  }
}

Action<> YieldAwaitable::YieldAwaiter::OutputCorrelationEtwEvent(Action<> continuation) {
  Int32 num = Task<>::in::NewId();
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  TplEventSource::in::Log->AwaitTaskContinuationScheduled(TaskScheduler::in::get_Current()->get_Id(), (internalCurrent != nullptr) ? internalCurrent->get_Id() : 0, num);
  Action<Action<>, Task<>> as = __c::in::__9__6_0;
  return AsyncMethodBuilderCore::CreateContinuationWrapper(continuation, as != nullptr ? as : (__c::in::__9__6_0 = &__c::in::__9->_OutputCorrelationEtwEvent_b__6_0), Task<>::in::FromResult(num));
}

void YieldAwaitable::YieldAwaiter::RunAction(Object state) {
  ((Action<>)state)();
}

void YieldAwaitable::YieldAwaiter::GetResult() {
}

void YieldAwaitable::YieldAwaiter::cctor() {
  s_waitCallbackRunAction = &RunAction;
  s_sendOrPostCallbackRunAction = &RunAction;
}

YieldAwaitable::YieldAwaiter YieldAwaitable::GetAwaiter() {
  return rt::default__;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace
