#include "TaskExceptionHolder-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::TaskExceptionHolderNamespace {
Boolean TaskExceptionHolder___::get_ContainsFaultList() {
  return Boolean();
};
void TaskExceptionHolder___::Finalize() {
  return void();
};
void TaskExceptionHolder___::Add(Object exceptionObject, Boolean representsCancellation) {
  return void();
};
void TaskExceptionHolder___::SetCancellationException(Object exceptionObject) {
  return void();
};
void TaskExceptionHolder___::AddFaultException(Object exceptionObject) {
  return void();
};
void TaskExceptionHolder___::MarkAsUnhandled() {
  return void();
};
void TaskExceptionHolder___::MarkAsHandled(Boolean calledFromFinalizer) {
  return void();
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
