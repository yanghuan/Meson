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
    public: static constexpr EventTask Loop = 1;
    public: static constexpr EventTask Invoke = 2;
    public: static constexpr EventTask TaskExecute = 3;
    public: static constexpr EventTask TaskWait = 4;
    public: static constexpr EventTask ForkJoin = 5;
    public: static constexpr EventTask TaskScheduled = 6;
    public: static constexpr EventTask AwaitTaskContinuationScheduled = 7;
    public: static constexpr EventTask TraceOperation = 8;
    public: static constexpr EventTask TraceSynchronousWork = 9;
  };
  public: class Keywords {
    public: static constexpr EventKeywords TaskTransfer = 1;
    public: static constexpr EventKeywords Tasks = 2;
    public: static constexpr EventKeywords Parallel = 4;
    public: static constexpr EventKeywords AsyncCausalityOperation = 8;
    public: static constexpr EventKeywords AsyncCausalityRelation = 16;
    public: static constexpr EventKeywords AsyncCausalitySynchronousWork = 32;
    public: static constexpr EventKeywords TaskStops = 64;
    public: static constexpr EventKeywords TasksFlowActivityIds = 128;
    public: static constexpr EventKeywords AsyncMethod = 256;
    public: static constexpr EventKeywords TasksSetActivityIds = 65536;
    public: static constexpr EventKeywords Debug = 131072;
    public: static constexpr EventKeywords DebugActivityId = 262144;
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
