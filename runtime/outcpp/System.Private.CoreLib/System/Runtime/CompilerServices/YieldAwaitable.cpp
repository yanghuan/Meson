#include "YieldAwaitable-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/YieldAwaitable-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

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
}

Action<> YieldAwaitable::YieldAwaiter::OutputCorrelationEtwEvent(Action<> continuation) {
  Int32 num = Task::in::NewId();
  Task internalCurrent = Task::in::get_InternalCurrent();
}

void YieldAwaitable::YieldAwaiter::RunAction(Object state) {
  ((Action)state)();
}

void YieldAwaitable::YieldAwaiter::GetResult() {
}

void YieldAwaitable::YieldAwaiter::cctor() {
  s_waitCallbackRunAction = RunAction;
  s_sendOrPostCallbackRunAction = RunAction;
}

YieldAwaitable::YieldAwaiter YieldAwaitable::GetAwaiter() {
  return YieldAwaiter();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace
