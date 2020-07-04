#include "TplEventSource-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::TplEventSourceNamespace {
void TplEventSource___::OnEventCommand(EventCommandEventArgs command) {
};
void TplEventSource___::TaskScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Int32 CreatingTaskID, Int32 TaskCreationOptions, Int32 appDomain) {
};
void TplEventSource___::TaskStarted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID) {
};
void TplEventSource___::TaskCompleted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Boolean IsExceptional) {
};
void TplEventSource___::TaskWaitBegin(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, TaskWaitBehavior Behavior, Int32 ContinueWithTaskID) {
};
void TplEventSource___::TaskWaitEnd(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID) {
};
void TplEventSource___::TaskWaitContinuationComplete(Int32 TaskID) {
};
void TplEventSource___::TaskWaitContinuationStarted(Int32 TaskID) {
};
void TplEventSource___::AwaitTaskContinuationScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 ContinueWithTaskId) {
};
void TplEventSource___::TraceOperationBegin(Int32 TaskID, String OperationName, Int64 RelatedContext) {
};
void TplEventSource___::TraceOperationRelation(Int32 TaskID, CausalityRelation Relation) {
};
void TplEventSource___::TraceOperationEnd(Int32 TaskID, AsyncCausalityStatus Status) {
};
void TplEventSource___::TraceSynchronousWorkBegin(Int32 TaskID, CausalitySynchronousWork Work) {
};
void TplEventSource___::TraceSynchronousWorkEnd(CausalitySynchronousWork Work) {
};
void TplEventSource___::RunningContinuationList(Int32 TaskID, Int32 Index, Object Object) {
};
void TplEventSource___::RunningContinuationList(Int32 TaskID, Int32 Index, Int64 Object) {
};
void TplEventSource___::DebugFacilityMessage(String Facility, String Message) {
};
void TplEventSource___::DebugFacilityMessage1(String Facility, String Message, String Value1) {
};
void TplEventSource___::SetActivityId(Guid NewId) {
};
void TplEventSource___::NewID(Int32 TaskID) {
};
void TplEventSource___::IncompleteAsyncMethod(IAsyncStateMachineBox stateMachineBox) {
};
void TplEventSource___::IncompleteAsyncMethod(String stateMachineDescription) {
};
Guid TplEventSource___::CreateGuidForTaskID(Int32 taskID) {
  return Guid();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::TplEventSourceNamespace
