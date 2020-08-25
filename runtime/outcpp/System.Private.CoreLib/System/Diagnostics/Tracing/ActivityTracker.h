#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(AsyncLocal, T)
FORWARDS(AsyncLocalValueChangedArgs, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventActivityOptions : int32_t;
namespace ActivityTrackerNamespace {
using namespace System::Threading;
CLASS(ActivityTracker) : public object {
  private: CLASS(ActivityInfo) : public object {
    public: Guid get_ActivityId();
    public: void ctor(String name, Int64 uniqueId, ActivityInfo creator, Guid activityIDToRestore, EventActivityOptions options);
    public: static String Path(ActivityInfo activityInfo);
    public: String ToString();
    public: static String LiveActivities(ActivityInfo list);
    public: Boolean CanBeOrphan();
    private: void CreateActivityPathGuid(Guid& idRet, Int32& activityPathGuidOffset);
    private: void CreateOverflowGuid(Guid* outPtr);
    private: static Int32 AddIdToGuid(Guid* outPtr, Int32 whereToAddId, UInt32 id, Boolean overflow = false);
    private: static void WriteNibble(Byte*& ptr, Byte* endPtr, UInt32 value);
    public: String m_name;
    private: Int64 m_uniqueId;
    public: Guid m_guid;
    public: Int32 m_activityPathGuidOffset;
    public: Int32 m_level;
    public: EventActivityOptions m_eventOptions;
    public: Int64 m_lastChildID;
    public: Int32 m_stopped;
    public: ActivityInfo m_creator;
    public: Guid m_activityIdToRestore;
  };
  public: static ActivityTracker get_Instance();
  public: void OnStart(String providerName, String activityName, Int32 task, Guid& activityId, Guid& relatedActivityId, EventActivityOptions options, Boolean useTplSource = true);
  public: void OnStop(String providerName, String activityName, Int32 task, Guid& activityId, Boolean useTplSource = true);
  public: void Enable();
  private: static ActivityInfo FindActiveActivity(String name, ActivityInfo startLocation);
  private: static String NormalizeActivityName(String providerName, String activityName, Int32 task);
  private: void ActivityChanging(AsyncLocalValueChangedArgs<ActivityInfo> args);
  public: void ctor();
  private: static void cctor();
  private: AsyncLocal<ActivityInfo> m_current;
  private: Boolean m_checkedForEnable;
  private: static ActivityTracker s_activityTrackerInstance;
  private: static Int64 m_nextId;
};
} // namespace ActivityTrackerNamespace
using ActivityTracker = ActivityTrackerNamespace::ActivityTracker;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
