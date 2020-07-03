#include "AsyncVoidMethodBuilder-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncVoidMethodBuilder-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncVoidMethodBuilderNamespace {
Task<> AsyncVoidMethodBuilder::get_Task() {
  return nullptr;
};
Object AsyncVoidMethodBuilder::get_ObjectIdForDebugger() {
  return nullptr;
};
AsyncVoidMethodBuilder AsyncVoidMethodBuilder::Create() {
  return AsyncVoidMethodBuilder();
};
void AsyncVoidMethodBuilder::SetStateMachine(IAsyncStateMachine stateMachine) {
};
void AsyncVoidMethodBuilder::SetResult() {
};
void AsyncVoidMethodBuilder::SetException(Exception exception) {
};
void AsyncVoidMethodBuilder::NotifySynchronizationContextOfCompletion() {
};
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncVoidMethodBuilderNamespace
