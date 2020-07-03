#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventLevel;
FORWARD(EventListener)
enum class EventCommand;
FORWARD(EventPipeWaitHandle)
namespace EventPipeEventDispatcherNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(EventPipeEventDispatcher) {
  public: CLASS(EventListenerSubscription) {
    private: EventKeywords MatchAnyKeywords;
    private: EventLevel Level;
  };
  public: void SendCommand(EventListener eventListener, EventCommand command, Boolean enable, EventLevel level, EventKeywords matchAnyKeywords);
  public: void RemoveEventListener(EventListener listener);
  private: void CommitDispatchConfiguration();
  private: void StartDispatchTask();
  private: void StopDispatchTask();
  private: void DispatchEventsToEventListeners();
  private: DateTime TimeStampToDateTime(Int64 timeStamp);
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
  private: static UInt32 DefaultEventListenerCircularMBSize;
};
} // namespace EventPipeEventDispatcherNamespace
using EventPipeEventDispatcher = EventPipeEventDispatcherNamespace::EventPipeEventDispatcher;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
