#include "AsyncCausalitySupport-dep.h"

namespace System::Private::CoreLib::Internal::Threading::Tasks::AsyncCausalitySupportNamespace {
Boolean AsyncCausalitySupport::get_LoggingOn() {
  return Boolean();
};
void AsyncCausalitySupport::AddToActiveTasks(Task<> task) {
};
void AsyncCausalitySupport::RemoveFromActiveTasks(Task<> task) {
};
void AsyncCausalitySupport::TraceOperationCreation(Task<> task, String operationName) {
};
void AsyncCausalitySupport::TraceOperationCompletedSuccess(Task<> task) {
};
void AsyncCausalitySupport::TraceOperationCompletedError(Task<> task) {
};
} // namespace System::Private::CoreLib::Internal::Threading::Tasks::AsyncCausalitySupportNamespace
