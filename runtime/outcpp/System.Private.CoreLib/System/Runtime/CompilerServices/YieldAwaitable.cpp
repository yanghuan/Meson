#include "YieldAwaitable-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/YieldAwaitable-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;

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

Action<> YieldAwaitable::YieldAwaiter::OutputCorrelationEtwEvent(Action<> continuation) {
  Int32 num = Task<>::in::NewId();
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  TplEventSource::in::Log->AwaitTaskContinuationScheduled(TaskScheduler::in::get_Current()->get_Id(), (internalCurrent != nullptr) ? internalCurrent->get_Id() : 0, num);
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
