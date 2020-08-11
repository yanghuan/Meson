#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventCommand : int32_t;
enum class EventKeywords : int64_t;
enum class EventLevel : int32_t;
FORWARD(EventListener)
FORWARD(EventPipeWaitHandle)
namespace EventPipeEventDispatcherNamespace {
using namespace Collections::Generic;
using namespace Threading::Tasks;
CLASS(EventPipeEventDispatcher) : public Object::in {
  public: CLASS(EventListenerSubscription) : public Object::in {
    public: EventKeywords get_MatchAnyKeywords() { return MatchAnyKeywords; }
    private: void set_MatchAnyKeywords(EventKeywords value) { MatchAnyKeywords = value; }
    public: EventLevel get_Level() { return Level; }
    private: void set_Level(EventLevel value) { Level = value; }
    public: void ctor(EventKeywords matchAnyKeywords, EventLevel level);
    private: EventKeywords MatchAnyKeywords;
    private: EventLevel Level;
  };
  private: void ctor();
  public: void SendCommand(EventListener eventListener, EventCommand command, Boolean enable, EventLevel level, EventKeywords matchAnyKeywords);
  public: void RemoveEventListener(EventListener listener);
  private: void CommitDispatchConfiguration();
  private: void StartDispatchTask();
  private: void StopDispatchTask();
  private: void DispatchEventsToEventListeners();
  private: DateTime TimeStampToDateTime(Int64 timeStamp);
  private: static void ctor_static();
  public: static EventPipeEventDispatcher Instance;
  private: IntPtr m_RuntimeProviderID;
  private: UInt64 m_sessionID;
  private: DateTime m_syncTimeUtc;
  private: Int64 m_syncTimeQPC;
  private: Int64 m_timeQPCFrequency;
  private: Boolean m_stopDispatchTask;
  private: EventPipeWaitHandle m_dispatchTaskWaitHandle;
  private: Task<> m_dispatchTask;
  private: Object m_dispatchControlLock;
  private: Dictionary<EventListener, EventListenerSubscription> m_subscriptions;
  private: static constexpr UInt32 DefaultEventListenerCircularMBSize = 10u;
};
} // namespace EventPipeEventDispatcherNamespace
using EventPipeEventDispatcher = EventPipeEventDispatcherNamespace::EventPipeEventDispatcher;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
