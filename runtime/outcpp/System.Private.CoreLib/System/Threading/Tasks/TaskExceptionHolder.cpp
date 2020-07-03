#include "TaskExceptionHolder-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::TaskExceptionHolderNamespace {
Boolean TaskExceptionHolder___::get_ContainsFaultList() {
  return Boolean();
};
void TaskExceptionHolder___::Finalize() {
};
void TaskExceptionHolder___::Add(Object exceptionObject, Boolean representsCancellation) {
};
void TaskExceptionHolder___::SetCancellationException(Object exceptionObject) {
};
void TaskExceptionHolder___::AddFaultException(Object exceptionObject) {
};
void TaskExceptionHolder___::MarkAsUnhandled() {
};
void TaskExceptionHolder___::MarkAsHandled(Boolean calledFromFinalizer) {
};
AggregateException TaskExceptionHolder___::CreateExceptionObject(Boolean calledFromFinalizer, Exception includeThisException) {
  return nullptr;
};
ReadOnlyCollection<ExceptionDispatchInfo> TaskExceptionHolder___::GetExceptionDispatchInfos() {
  return nullptr;
};
ExceptionDispatchInfo TaskExceptionHolder___::GetCancellationExceptionDispatchInfo() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskExceptionHolderNamespace
