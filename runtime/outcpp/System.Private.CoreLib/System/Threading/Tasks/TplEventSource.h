#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventTask;
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
namespace TplEventSourceNamespace {
using namespace Diagnostics::Tracing;
using namespace Runtime::CompilerServices;
CLASS(TplEventSource) {
  public: enum class TaskWaitBehavior {
    Synchronous = 1,
    Asynchronous = 2,
  };
  public: class Tasks {
    public: static EventTask Loop;
    public: static EventTask Invoke;
    public: static EventTask TaskExecute;
    public: static EventTask TaskWait;
    public: static EventTask ForkJoin;
    public: static EventTask TaskScheduled;
    public: static EventTask AwaitTaskContinuationScheduled;
    public: static EventTask TraceOperation;
    public: static EventTask TraceSynchronousWork;
  };
  public: class Keywords {
    public: static EventKeywords TaskTransfer;
    public: static EventKeywords Tasks;
    public: static EventKeywords Parallel;
    public: static EventKeywords AsyncCausalityOperation;
    public: static EventKeywords AsyncCausalityRelation;
    public: static EventKeywords AsyncCausalitySynchronousWork;
    public: static EventKeywords TaskStops;
    public: static EventKeywords TasksFlowActivityIds;
    public: static EventKeywords AsyncMethod;
    public: static EventKeywords TasksSetActivityIds;
    public: static EventKeywords Debug;
    public: static EventKeywords DebugActivityId;
  };
  protected: void OnEventCommand(EventCommandEventArgs command);
  public: void TaskScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Int32 CreatingTaskID, Int32 TaskCreationOptions, Int32 appDomain);
  public: void TaskStarted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID);
  public: void TaskCompleted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Boolean IsExceptional);
  public: void TaskWaitBegin(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, TaskWaitBehavior Behavior, Int32 ContinueWithTaskID);
  public: void TaskWaitEnd(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID);
  public: void TaskWaitContinuationComplete(Int32 TaskID);
  public: void TaskWaitContinuationStarted(Int32 TaskID);
  public: void AwaitTaskContinuationScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 ContinueWithTaskId);
  public: void RunningContinuationList(Int32 TaskID, Int32 Index, Object Object);
  public: void RunningContinuationList(Int32 TaskID, Int32 Index, Int64 Object);
  public: void DebugFacilityMessage(String Facility, String Message);
  public: void DebugFacilityMessage1(String Facility, String Message, String Value1);
  public: void SetActivityId(Guid NewId);
  public: void NewID(Int32 TaskID);
  public: void IncompleteAsyncMethod(IAsyncStateMachineBox stateMachineBox);
  private: void IncompleteAsyncMethod(String stateMachineDescription);
  public: static Guid CreateGuidForTaskID(Int32 taskID);
  public: Boolean TasksSetActivityIds;
  public: Boolean Debug;
  private: Boolean DebugActivityId;
  public: static TplEventSource Log;
};
} // namespace TplEventSourceNamespace
using TplEventSource = TplEventSourceNamespace::TplEventSource;
} // namespace System::Private::CoreLib::System::Threading::Tasks
