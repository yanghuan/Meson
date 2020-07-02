#include "AsyncCausalityTracer-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::AsyncCausalityTracerNamespace {
Boolean AsyncCausalityTracer::get_LoggingOn() {
  return Boolean();
};
void AsyncCausalityTracer::EnableToETW(Boolean enabled) {
  return void();
};
void AsyncCausalityTracer::TracingStatusChangedHandler(Object sender, TracingStatusChangedEventArgs args) {
  return void();
};
void AsyncCausalityTracer::TraceOperationCreation(Task<> task, String operationName) {
  return void();
};
void AsyncCausalityTracer::TraceOperationCompletion(Task<> task, AsyncCausalityStatus status) {
  return void();
};
void AsyncCausalityTracer::TraceOperationRelation(Task<> task, CausalityRelation relation) {
  return void();
};
void AsyncCausalityTracer::TraceSynchronousWorkStart(Task<> task, CausalitySynchronousWork work) {
  return void();
};
void AsyncCausalityTracer::TraceSynchronousWorkCompletion(CausalitySynchronousWork work) {
  return void();
};
void AsyncCausalityTracer::LogAndDisable(Exception ex) {
  return void();
};
UInt64 AsyncCausalityTracer::GetOperationId(UInt32 taskId) {
  return UInt64();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::AsyncCausalityTracerNamespace
