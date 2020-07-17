#include "ExecutionContext-dep.h"

#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>

namespace System::Private::CoreLib::System::Threading::ExecutionContextNamespace {
Boolean ExecutionContext___::get_HasChangeNotifications() {
  return Boolean();
};

Boolean ExecutionContext___::get_IsDefault() {
  return Boolean();
};

void ExecutionContext___::Ctor(Boolean isDefault) {
};

void ExecutionContext___::Ctor(IAsyncLocalValueMap localValues, Array<IAsyncLocal> localChangeNotifications, Boolean isFlowSuppressed) {
};

void ExecutionContext___::GetObjectData(SerializationInfo info, StreamingContext context) {
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
};

Boolean ExecutionContext___::IsFlowSuppressed() {
  return Boolean();
};

void ExecutionContext___::Run(ExecutionContext executionContext, ContextCallback<> callback, Object state) {
};

void ExecutionContext___::RunInternal(ExecutionContext executionContext, ContextCallback<> callback, Object state) {
};

void ExecutionContext___::RunFromThreadPoolDispatchLoop(Thread threadPoolThread, ExecutionContext executionContext, ContextCallback<> callback, Object state) {
};

void ExecutionContext___::RestoreChangedContextToThread(Thread currentThread, ExecutionContext contextToRestore, ExecutionContext currentContext) {
};

void ExecutionContext___::ResetThreadPoolThread(Thread currentThread) {
};

void ExecutionContext___::OnValuesChanged(ExecutionContext previousExecutionCtx, ExecutionContext nextExecutionCtx) {
};

void ExecutionContext___::ThrowNullContext() {
};

Object ExecutionContext___::GetLocalValue(IAsyncLocal local) {
  return nullptr;
};

void ExecutionContext___::SetLocalValue(IAsyncLocal local, Object newValue, Boolean needChangeNotifications) {
};

ExecutionContext ExecutionContext___::CreateCopy() {
  return nullptr;
};

void ExecutionContext___::Dispose() {
};

void ExecutionContext___::SCtor() {
};

} // namespace System::Private::CoreLib::System::Threading::ExecutionContextNamespace
