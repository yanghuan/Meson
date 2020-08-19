#include "AsyncVoidMethodBuilder-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncVoidMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncVoidMethodBuilderNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;

Object AsyncVoidMethodBuilder::get_ObjectIdForDebugger() {
  return _builder.get_ObjectIdForDebugger();
}

AsyncVoidMethodBuilder AsyncVoidMethodBuilder::Create() {
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  auto& default = current;
  default == nullptr ? nullptr : default->OperationStarted();
  AsyncVoidMethodBuilder result = AsyncVoidMethodBuilder();
  result._synchronizationContext = current;
  return result;
}

void AsyncVoidMethodBuilder::SetStateMachine(IAsyncStateMachine stateMachine) {
  _builder.SetStateMachine(stateMachine);
}

void AsyncVoidMethodBuilder::SetResult() {
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  _builder.SetResult();
  if (_synchronizationContext != nullptr) {
    NotifySynchronizationContextOfCompletion();
  }
}

void AsyncVoidMethodBuilder::SetException(Exception exception) {
  if (exception == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::exception);
  }
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
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
