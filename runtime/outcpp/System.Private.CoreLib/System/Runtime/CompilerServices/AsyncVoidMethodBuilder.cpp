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
  return void();
};
void AsyncVoidMethodBuilder::SetResult() {
  return void();
};
void AsyncVoidMethodBuilder::SetException(Exception exception) {
  return void();
};
void AsyncVoidMethodBuilder::NotifySynchronizationContextOfCompletion() {
  return void();
};
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncVoidMethodBuilderNamespace
