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
namespace TplEventSourceNamespace {
using namespace Diagnostics::Tracing;
using namespace Runtime::CompilerServices;
CLASS(TplEventSource) : public EventSource::in {
  public: enum class TaskWaitBehavior {
    Synchronous = 1,
    Asynchronous = 2,
  };
  public: class Tasks {
  };
  public: class Keywords {
  };
  protected: void OnEventCommand(EventCommandEventArgs command);
  private: void Ctor();
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
  private: static void SCtor();
  public: Boolean TasksSetActivityIds;
  public: Boolean Debug;
  private: Boolean DebugActivityId;
  public: static TplEventSource Log;
};
} // namespace TplEventSourceNamespace
using TplEventSource = TplEventSourceNamespace::TplEventSource;
} // namespace System::Private::CoreLib::System::Threading::Tasks
