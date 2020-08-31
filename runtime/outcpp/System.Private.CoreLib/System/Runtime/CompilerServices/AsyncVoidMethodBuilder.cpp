#include "AsyncVoidMethodBuilder-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncVoidMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncVoidMethodBuilderNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;

Task<> AsyncVoidMethodBuilder::get_Task() {
  return _builder.get_Task();
}

Object AsyncVoidMethodBuilder::get_ObjectIdForDebugger() {
  return _builder.get_ObjectIdForDebugger();
}

AsyncVoidMethodBuilder AsyncVoidMethodBuilder::Create() {
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  if (current != nullptr) {
    current->OperationStarted();
  }
  AsyncVoidMethodBuilder result = AsyncVoidMethodBuilder();
  result._synchronizationContext = current;
  return result;
}

void AsyncVoidMethodBuilder::SetStateMachine(IAsyncStateMachine stateMachine) {
  _builder.SetStateMachine(stateMachine);
}

void AsyncVoidMethodBuilder::SetResult() {
  if (TplEventSource::in::Log->IsEnabled()) {
    TplEventSource::in::Log->TraceOperationEnd(get_Task()->get_Id(), AsyncCausalityStatus::Completed);
  }
  _builder.SetResult();
  if (_synchronizationContext != nullptr) {
    NotifySynchronizationContextOfCompletion();
  }
}

void AsyncVoidMethodBuilder::SetException(Exception exception) {
  if (exception == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::exception);
  }
  if (TplEventSource::in::Log->IsEnabled()) {
    TplEventSource::in::Log->TraceOperationEnd(get_Task()->get_Id(), AsyncCausalityStatus::Error);
  }
  if (_synchronizationContext != nullptr) {
    try {
      Task<>::in::ThrowAsync(exception, _synchronizationContext);
    } catch (...) {
    } finally: {
      NotifySynchronizationContextOfCompletion();
    }
  } else {
    Task<>::in::ThrowAsync(exception, nullptr);
  }
  _builder.SetResult();
}

void AsyncVoidMethodBuilder::NotifySynchronizationContextOfCompletion() {
  try {
    _synchronizationContext->OperationCompleted();
  } catch (Exception exception) {
  }
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncVoidMethodBuilderNamespace
