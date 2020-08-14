#include "ActivityTracker-dep.h"

#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ActivityTracker-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotImplementedException-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocalValueChangedArgs-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ActivityTrackerNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;

Guid ActivityTracker___::ActivityInfo___::get_ActivityId() {
  return m_guid;
}

void ActivityTracker___::ActivityInfo___::ctor(String name, Int64 uniqueId, ActivityInfo creator, Guid activityIDToRestore, EventActivityOptions options) {
  m_name = name;
  m_eventOptions = options;
  m_creator = creator;
  m_uniqueId = uniqueId;
  m_level = ((creator != nullptr) ? (creator->m_level + 1) : 0);
  m_activityIdToRestore = activityIDToRestore;
  CreateActivityPathGuid(m_guid, m_activityPathGuidOffset);
}

String ActivityTracker___::ActivityInfo___::Path(ActivityInfo activityInfo) {
  if (activityInfo == nullptr) {
    return "";
  }
  return Path(activityInfo->m_creator) + "/" + activityInfo->m_uniqueId;
}

String ActivityTracker___::ActivityInfo___::ToString() {
  return m_name + "(" + Path((ActivityInfo)this) + ((m_stopped != 0) ? ",DEAD)" : ")");
}

String ActivityTracker___::ActivityInfo___::LiveActivities(ActivityInfo list) {
  if (list == nullptr) {
    return "";
  }
  return list->ToString() + ";" + LiveActivities(list->m_creator);
}

Boolean ActivityTracker___::ActivityInfo___::CanBeOrphan() {
}

void ActivityTracker___::ActivityInfo___::CreateActivityPathGuid(Guid& idRet, Int32& activityPathGuidOffset) {
  {
    Guid* outPtr = &idRet;
    Int32 whereToAddId = 0;
    if (m_creator != nullptr) {
      whereToAddId = m_creator->m_activityPathGuidOffset;
      idRet = m_creator->m_guid;
    } else {
      Int32 num = 0;
      num = Thread::in::GetDomainID();
      whereToAddId = AddIdToGuid(outPtr, whereToAddId, (UInt32)num);
    }
    activityPathGuidOffset = AddIdToGuid(outPtr, whereToAddId, (UInt32)m_uniqueId);
    if (12 < activityPathGuidOffset) {
      CreateOverflowGuid(outPtr);
    }
  }
}

void ActivityTracker___::ActivityInfo___::CreateOverflowGuid(Guid* outPtr) {
  for (ActivityInfo creator = m_creator; creator != nullptr; creator = creator->m_creator) {
    if (creator->m_activityPathGuidOffset <= 10) {
      UInt32 id = (UInt32)Interlocked::Increment(creator->m_lastChildID);
      *outPtr = creator->m_guid;
      Int32 num = AddIdToGuid(outPtr, creator->m_activityPathGuidOffset, id, true);
      if (num <= 12) {
        break;
      }
    }
  }
}

Int32 ActivityTracker___::ActivityInfo___::AddIdToGuid(Guid* outPtr, Int32 whereToAddId, UInt32 id, Boolean overflow) {
  Byte* ptr = (Byte*)outPtr;
  Byte* ptr2 = ptr + 12;
  ptr += whereToAddId;
  if (ptr2 <= ptr) {
    return 13;
  }
  if (0 < id && id <= 10 && !overflow) {
    WriteNibble(ptr, ptr2, id);
  } else {
    UInt32 num = 4u;
    if (id <= 255) {
      num = 1u;
    } else if (id <= 65535) {
      num = 2u;
    } else if (id <= 16777215) {
      num = 3u;
    }


    if (overflow) {
      if (ptr2 <= ptr + 2) {
        return 13;
      }
      WriteNibble(ptr, ptr2, 11u);
    }
    WriteNibble(ptr, ptr2, 12 + (num - 1));
    if (ptr < ptr2 && *ptr != 0) {
      if (id < 4096) {
        *ptr = (Byte)(192 + (id >> 8));
        id &= 255;
      }
      ptr++;
    }
    while (0 < num) {
      if (ptr2 <= ptr) {
        ptr++;
        break;
      }
      *(ptr++) = (Byte)id;
      id >>= 8;
      num--;
    }
  }
}

void ActivityTracker___::ActivityInfo___::WriteNibble(Byte*& ptr, Byte* endPtr, UInt32 value) {
  if (*ptr != 0) {
    Byte* intPtr = ptr++;
  } else {
    *ptr = (Byte)(value << 4);
  }
}

ActivityTracker ActivityTracker___::get_Instance() {
  return s_activityTrackerInstance;
}

void ActivityTracker___::OnStart(String providerName, String activityName, Int32 task, Guid& activityId, Guid& relatedActivityId, EventActivityOptions options, Boolean useTplSource) {
  if (m_current == nullptr) {
    if (m_checkedForEnable) {
      return;
    }
    m_checkedForEnable = true;
    if (useTplSource && TplEventSource::in::Log->IsEnabled(EventLevel::Informational, (EventKeywords)128)) {
      Enable();
    }
    if (m_current == nullptr) {
      return;
    }
  }
  ActivityInfo value = m_current->get_Value();
  String text = NormalizeActivityName(providerName, activityName, task);
  TplEventSource tplEventSource = useTplSource ? TplEventSource::in::Log : nullptr;
}

void ActivityTracker___::OnStop(String providerName, String activityName, Int32 task, Guid& activityId, Boolean useTplSource) {
  if (m_current == nullptr) {
    return;
  }
  String text = NormalizeActivityName(providerName, activityName, task);
  TplEventSource tplEventSource = useTplSource ? TplEventSource::in::Log : nullptr;
}

void ActivityTracker___::Enable() {
  if (m_current == nullptr) {
    try{
      m_current = rt::newobj<AsyncLocal<ActivityInfo>>(rt::newobj<Action<AsyncLocalValueChangedArgs<ActivityInfo>>>(&ActivityChanging));
    } catch (NotImplementedException) {
    }
  }
}

ActivityTracker::in::ActivityInfo ActivityTracker___::FindActiveActivity(String name, ActivityInfo startLocation) {
  for (ActivityInfo activityInfo = startLocation; activityInfo != nullptr; activityInfo = activityInfo->m_creator) {
    if (name == activityInfo->m_name && activityInfo->m_stopped == 0) {
      return activityInfo;
    }
  }
  return nullptr;
}

String ActivityTracker___::NormalizeActivityName(String providerName, String activityName, Int32 task) {
  if (activityName->EndsWith("Start", StringComparison::Ordinal)) {
    return providerName + MemoryExtensions::AsSpan(activityName, 0, activityName->get_Length() - "Start"->get_Length());
  }
  if (activityName->EndsWith("Stop", StringComparison::Ordinal)) {
    return providerName + MemoryExtensions::AsSpan(activityName, 0, activityName->get_Length() - "Stop"->get_Length());
  }
  if (task != 0) {
    return providerName + "task" + task;
  }
  return providerName + activityName;
}

void ActivityTracker___::ActivityChanging(AsyncLocalValueChangedArgs<ActivityInfo> args) {
  ActivityInfo activityInfo = args.get_CurrentValue();
  ActivityInfo previousValue = args.get_PreviousValue();
  if (previousValue != nullptr && previousValue->m_creator == activityInfo && (activityInfo == nullptr || previousValue->m_activityIdToRestore != activityInfo->get_ActivityId())) {
    EventSource::in::SetCurrentThreadActivityId(previousValue->m_activityIdToRestore);
    return;
  }
  while (activityInfo != nullptr) {
    if (activityInfo->m_stopped == 0) {
      EventSource::in::SetCurrentThreadActivityId(activityInfo->get_ActivityId());
      break;
    }
    activityInfo = activityInfo->m_creator;
  }
}

void ActivityTracker___::ctor() {
}

void ActivityTracker___::cctor() {
  s_activityTrackerInstance = rt::newobj<ActivityTracker>();
  m_nextId = 0;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ActivityTrackerNamespace
