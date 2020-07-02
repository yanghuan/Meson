#include "ExecutionContext-dep.h"

#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>

namespace System::Private::CoreLib::System::Threading::ExecutionContextNamespace {
Boolean ExecutionContext___::get_HasChangeNotifications() {
  return Boolean();
};
Boolean ExecutionContext___::get_IsDefault() {
  return Boolean();
};
void ExecutionContext___::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
ExecutionContext ExecutionContext___::Capture() {
  return nullptr;
};
ExecutionContext ExecutionContext___::ShallowClone(Boolean isFlowSuppressed) {
  return nullptr;
};
AsyncFlowControl ExecutionContext___::SuppressFlow() {
  return AsyncFlowControl();
};
void ExecutionContext___::RestoreFlow() {
  return void();
};
Boolean ExecutionContext___::IsFlowSuppressed() {
  return Boolean();
};
void ExecutionContext___::Run(ExecutionContext executionContext, ContextCallback<> callback, Object state) {
  return void();
};
void ExecutionContext___::RunInternal(ExecutionContext executionContext, ContextCallback<> callback, Object state) {
  return void();
};
void ExecutionContext___::RunFromThreadPoolDispatchLoop(Thread threadPoolThread, ExecutionContext executionContext, ContextCallback<> callback, Object state) {
  return void();
};
void ExecutionContext___::RestoreChangedContextToThread(Thread currentThread, ExecutionContext contextToRestore, ExecutionContext currentContext) {
  return void();
};
void ExecutionContext___::ResetThreadPoolThread(Thread currentThread) {
  return void();
};
void ExecutionContext___::OnValuesChanged(ExecutionContext previousExecutionCtx, ExecutionContext nextExecutionCtx) {
  return void();
};
void ExecutionContext___::ThrowNullContext() {
  return void();
};
Object ExecutionContext___::GetLocalValue(IAsyncLocal local) {
  return nullptr;
};
void ExecutionContext___::SetLocalValue(IAsyncLocal local, Object newValue, Boolean needChangeNotifications) {
  return void();
};
ExecutionContext ExecutionContext___::CreateCopy() {
  return nullptr;
};
void ExecutionContext___::Dispose() {
  return void();
};
} // namespace System::Private::CoreLib::System::Threading::ExecutionContextNamespace
