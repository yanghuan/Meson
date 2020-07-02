#include "AsyncCausalitySupport-dep.h"

namespace System::Private::CoreLib::Internal::Threading::Tasks::AsyncCausalitySupportNamespace {
Boolean AsyncCausalitySupport::get_LoggingOn() {
  return Boolean();
};
void AsyncCausalitySupport::AddToActiveTasks(Task<> task) {
  return void();
};
void AsyncCausalitySupport::RemoveFromActiveTasks(Task<> task) {
  return void();
};
void AsyncCausalitySupport::TraceOperationCreation(Task<> task, String operationName) {
  return void();
};
void AsyncCausalitySupport::TraceOperationCompletedSuccess(Task<> task) {
  return void();
};
void AsyncCausalitySupport::TraceOperationCompletedError(Task<> task) {
  return void();
};
} // namespace System::Private::CoreLib::Internal::Threading::Tasks::AsyncCausalitySupportNamespace
