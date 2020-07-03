#include "AsyncCausalityTracer-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::AsyncCausalityTracerNamespace {
Boolean AsyncCausalityTracer::get_LoggingOn() {
  return Boolean();
};
void AsyncCausalityTracer::EnableToETW(Boolean enabled) {
};
void AsyncCausalityTracer::TracingStatusChangedHandler(Object sender, TracingStatusChangedEventArgs args) {
};
void AsyncCausalityTracer::TraceOperationCreation(Task<> task, String operationName) {
};
void AsyncCausalityTracer::TraceOperationCompletion(Task<> task, AsyncCausalityStatus status) {
};
void AsyncCausalityTracer::TraceOperationRelation(Task<> task, CausalityRelation relation) {
};
void AsyncCausalityTracer::TraceSynchronousWorkStart(Task<> task, CausalitySynchronousWork work) {
};
void AsyncCausalityTracer::TraceSynchronousWorkCompletion(CausalitySynchronousWork work) {
};
void AsyncCausalityTracer::LogAndDisable(Exception ex) {
};
UInt64 AsyncCausalityTracer::GetOperationId(UInt32 taskId) {
  return UInt64();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::AsyncCausalityTracerNamespace
