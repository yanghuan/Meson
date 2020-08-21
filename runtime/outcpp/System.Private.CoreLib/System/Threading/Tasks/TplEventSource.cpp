#include "TplEventSource-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ActivityTracker-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachine.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TplEventSourceNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Diagnostics::Tracing;
using namespace System::Runtime::CompilerServices;

void TplEventSource___::OnEventCommand(EventCommandEventArgs command) {
  if (command->get_Command() != EventCommand::Enable) {
    EventCommand command2 = command->get_Command();
    Int32 num = -3;
  }
  if (IsEnabled(EventLevel::Informational, (EventKeywords)128)) {
    ActivityTracker::in::get_Instance()->Enable();
  } else {
    TasksSetActivityIds = IsEnabled(EventLevel::Informational, (EventKeywords)65536);
  }
  Debug = IsEnabled(EventLevel::Informational, (EventKeywords)131072);
  DebugActivityId = IsEnabled(EventLevel::Informational, (EventKeywords)262144);
}

void TplEventSource___::ctor() {
}

void TplEventSource___::TaskScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Int32 CreatingTaskID, Int32 TaskCreationOptions, Int32 appDomain) {
  if (IsEnabled() && IsEnabled(EventLevel::Informational, (EventKeywords)3)) {
    EventSource::in::EventData as[6] = {};
    EventSource::in::EventData* ptr = as;
    ptr->set_Size(4);
    ptr->set_DataPointer((IntPtr)(void*)(&OriginatingTaskSchedulerID));
    ptr->set_Reserved(0);
    ptr[1].set_Size(4);
    ptr[1].set_DataPointer((IntPtr)(void*)(&OriginatingTaskID));
    ptr[1].set_Reserved(0);
    ptr[2].set_Size(4);
    ptr[2].set_DataPointer((IntPtr)(void*)(&TaskID));
    ptr[2].set_Reserved(0);
    ptr[3].set_Size(4);
    ptr[3].set_DataPointer((IntPtr)(void*)(&CreatingTaskID));
    ptr[3].set_Reserved(0);
    ptr[4].set_Size(4);
    ptr[4].set_DataPointer((IntPtr)(void*)(&TaskCreationOptions));
    ptr[4].set_Reserved(0);
    ptr[5].set_Size(4);
    ptr[5].set_DataPointer((IntPtr)(void*)(&appDomain));
    ptr[5].set_Reserved(0);
    if (TasksSetActivityIds) {
      Guid guid = CreateGuidForTaskID(TaskID);
      WriteEventWithRelatedActivityIdCore(7, &guid, 6, ptr);
    } else {
      WriteEventCore(7, 6, ptr);
    }
  }
}

void TplEventSource___::TaskStarted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID) {
  if (IsEnabled(EventLevel::Informational, (EventKeywords)2)) {
    WriteEvent(8, OriginatingTaskSchedulerID, OriginatingTaskID, TaskID);
  }
}

void TplEventSource___::TaskCompleted(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, Boolean IsExceptional) {
  if (IsEnabled(EventLevel::Informational, (EventKeywords)2)) {
    EventSource::in::EventData as[4] = {};
    EventSource::in::EventData* ptr = as;
    Int32 num = IsExceptional ? 1 : 0;
    ptr->set_Size(4);
    ptr->set_DataPointer((IntPtr)(void*)(&OriginatingTaskSchedulerID));
    ptr->set_Reserved(0);
    ptr[1].set_Size(4);
    ptr[1].set_DataPointer((IntPtr)(void*)(&OriginatingTaskID));
    ptr[1].set_Reserved(0);
    ptr[2].set_Size(4);
    ptr[2].set_DataPointer((IntPtr)(void*)(&TaskID));
    ptr[2].set_Reserved(0);
    ptr[3].set_Size(4);
    ptr[3].set_DataPointer((IntPtr)(void*)(&num));
    ptr[3].set_Reserved(0);
    WriteEventCore(9, 4, ptr);
  }
}

void TplEventSource___::TaskWaitBegin(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID, TaskWaitBehavior Behavior, Int32 ContinueWithTaskID) {
  if (IsEnabled() && IsEnabled(EventLevel::Informational, (EventKeywords)3)) {
    EventSource::in::EventData as[5] = {};
    EventSource::in::EventData* ptr = as;
    ptr->set_Size(4);
    ptr->set_DataPointer((IntPtr)(void*)(&OriginatingTaskSchedulerID));
    ptr->set_Reserved(0);
    ptr[1].set_Size(4);
    ptr[1].set_DataPointer((IntPtr)(void*)(&OriginatingTaskID));
    ptr[1].set_Reserved(0);
    ptr[2].set_Size(4);
    ptr[2].set_DataPointer((IntPtr)(void*)(&TaskID));
    ptr[2].set_Reserved(0);
    ptr[3].set_Size(4);
    ptr[3].set_DataPointer((IntPtr)(void*)(&Behavior));
    ptr[3].set_Reserved(0);
    ptr[4].set_Size(4);
    ptr[4].set_DataPointer((IntPtr)(void*)(&ContinueWithTaskID));
    ptr[4].set_Reserved(0);
    if (TasksSetActivityIds) {
      Guid guid = CreateGuidForTaskID(TaskID);
      WriteEventWithRelatedActivityIdCore(10, &guid, 5, ptr);
    } else {
      WriteEventCore(10, 5, ptr);
    }
  }
}

void TplEventSource___::TaskWaitEnd(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 TaskID) {
  if (IsEnabled() && IsEnabled(EventLevel::Verbose, (EventKeywords)2)) {
    WriteEvent(11, OriginatingTaskSchedulerID, OriginatingTaskID, TaskID);
  }
}

void TplEventSource___::TaskWaitContinuationComplete(Int32 TaskID) {
  if (IsEnabled() && IsEnabled(EventLevel::Verbose, (EventKeywords)2)) {
    WriteEvent(13, TaskID);
  }
}

void TplEventSource___::TaskWaitContinuationStarted(Int32 TaskID) {
  if (IsEnabled() && IsEnabled(EventLevel::Verbose, (EventKeywords)2)) {
    WriteEvent(19, TaskID);
  }
}

void TplEventSource___::AwaitTaskContinuationScheduled(Int32 OriginatingTaskSchedulerID, Int32 OriginatingTaskID, Int32 ContinueWithTaskId) {
  if (IsEnabled() && IsEnabled(EventLevel::Informational, (EventKeywords)3)) {
    EventSource::in::EventData as[3] = {};
    EventSource::in::EventData* ptr = as;
    ptr->set_Size(4);
    ptr->set_DataPointer((IntPtr)(void*)(&OriginatingTaskSchedulerID));
    ptr->set_Reserved(0);
    ptr[1].set_Size(4);
    ptr[1].set_DataPointer((IntPtr)(void*)(&OriginatingTaskID));
    ptr[1].set_Reserved(0);
    ptr[2].set_Size(4);
    ptr[2].set_DataPointer((IntPtr)(void*)(&ContinueWithTaskId));
    ptr[2].set_Reserved(0);
    if (TasksSetActivityIds) {
      Guid guid = CreateGuidForTaskID(ContinueWithTaskId);
      WriteEventWithRelatedActivityIdCore(12, &guid, 3, ptr);
    } else {
      WriteEventCore(12, 3, ptr);
    }
  }
}

void TplEventSource___::RunningContinuationList(Int32 TaskID, Int32 Index, Object Object) {
  RunningContinuationList(TaskID, Index, (Int64)(UIntPtr)(IntPtr)(*(IntPtr*)Unsafe::AsPointer(Object)));
}

void TplEventSource___::RunningContinuationList(Int32 TaskID, Int32 Index, Int64 Object) {
  if (Debug) {
    WriteEvent(21, TaskID, Index, Object);
  }
}

void TplEventSource___::DebugFacilityMessage(String Facility, String Message) {
  WriteEvent(23, Facility, Message);
}

void TplEventSource___::DebugFacilityMessage1(String Facility, String Message, String Value1) {
  WriteEvent(24, Facility, Message, Value1);
}

void TplEventSource___::SetActivityId(Guid NewId) {
  if (DebugActivityId) {
    WriteEvent(25, NewId);
  }
}

void TplEventSource___::NewID(Int32 TaskID) {
  if (Debug) {
    WriteEvent(26, TaskID);
  }
}

void TplEventSource___::IncompleteAsyncMethod(IAsyncStateMachineBox stateMachineBox) {
  if (IsEnabled(EventLevel::Warning, (EventKeywords)256)) {
    IAsyncStateMachine stateMachineObject = stateMachineBox->GetStateMachineObject();
    if (stateMachineObject != nullptr) {
      String asyncStateMachineDescription = AsyncMethodBuilderCore::GetAsyncStateMachineDescription(stateMachineObject);
      IncompleteAsyncMethod(asyncStateMachineDescription);
    }
  }
}

void TplEventSource___::IncompleteAsyncMethod(String stateMachineDescription) {
  WriteEvent(27, stateMachineDescription);
}

Guid TplEventSource___::CreateGuidForTaskID(Int32 taskID) {
  UInt32 s_currentPid = EventSource::in::s_currentPid;
  return Guid(taskID, 1, 0, (Byte)s_currentPid, (Byte)(s_currentPid >> 8), (Byte)(s_currentPid >> 16), (Byte)(s_currentPid >> 24), Byte::MaxValue, 220, 215, 181);
}

void TplEventSource___::cctor() {
  Log = rt::newobj<TplEventSource>();
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TplEventSourceNamespace
