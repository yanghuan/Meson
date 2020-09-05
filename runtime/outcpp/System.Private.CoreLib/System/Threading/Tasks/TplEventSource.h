#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventCommandEventArgs)
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class AsyncCausalityStatus : int32_t;
enum class CausalityRelation : int32_t;
enum class CausalitySynchronousWork : int32_t;
namespace TplEventSourceNamespace {
using namespace System::Diagnostics::Tracing;
using namespace System::Runtime::CompilerServices;
CLASS(TplEventSource) : public EventSource::in {
  public: enum class TaskWaitBehavior : int32_t {
    Synchronous = 1,
    Asynchronous = 2,
  };
  public: class Tasks {
  };
  public: class Keywords {
  };
  protected: void OnEventCommand(EventCommandEventArgs command);
  public: void ctor();
  public: void TaskScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Int32 CreatingTaskID, Int32 TaskCreationOptions, Int32 appDomain = 1);
  public: void TaskStarted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID);
  public: void TaskCompleted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Boolean IsExceptional);
  public: void TaskWaitBegin(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, TaskWaitBehavior Behavior, Int32 ContinueWithTaskID);
  public: void TaskWaitEnd(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID);
  public: void TaskWaitContinuationComplete(Int32 TaskID);
  public: void TaskWaitContinuationStarted(Int32 TaskID);
  public: void AwaitTaskContinuationScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 ContinueWithTaskId);
  public: void TraceOperationBegin(Int32 TaskID, String OperationName, Int64 RelatedContext);
  public: void TraceOperationRelation(Int32 TaskID, CausalityRelation Relation);
  public: void TraceOperationEnd(Int32 TaskID, AsyncCausalityStatus Status);
  public: void TraceSynchronousWorkBegin(Int32 TaskID, CausalitySynchronousWork Work);
  public: void TraceSynchronousWorkEnd(CausalitySynchronousWork Work);
  public: void RunningContinuationList(Int32 TaskID, Int32 Index, Object Object);
  public: void RunningContinuationList(Int32 TaskID, Int32 Index, Int64 Object);
  public: void DebugFacilityMessage(String Facility, String Message);
  public: void DebugFacilityMessage1(String Facility, String Message, String Value1);
  public: void SetActivityId(Guid NewId);
  public: void NewID(Int32 TaskID);
  public: void IncompleteAsyncMethod(IAsyncStateMachineBox stateMachineBox);
  private: void IncompleteAsyncMethod(String stateMachineDescription);
  public: static Guid CreateGuidForTaskID(Int32 taskID);
  public: static void cctor();
  public: Boolean TasksSetActivityIds;
  public: Boolean Debug;
  private: Boolean DebugActivityId;
  public: static TplEventSource Log;
};
} // namespace TplEventSourceNamespace
using TplEventSource = TplEventSourceNamespace::TplEventSource;
} // namespace System::Private::CoreLib::System::Threading::Tasks
