#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(Single)
FORWARD_(WeakReference, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(AutoResetEvent)
FORWARD(Thread)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(DiagnosticCounter)
FORWARD(EventCommandEventArgs)
FORWARD(EventSource)
namespace CounterGroupNamespace {
using namespace Collections::Generic;
using namespace Threading;
CLASS(CounterGroup) {
  public: void Ctor(EventSource eventSource);
  public: void Add(DiagnosticCounter eventCounter);
  public: void Remove(DiagnosticCounter eventCounter);
  private: void RegisterCommandCallback();
  private: void OnEventSourceCommand(Object sender, EventCommandEventArgs e);
  private: static void EnsureEventSourceIndexAvailable(Int32 eventSourceIndex);
  public: static CounterGroup GetCounterGroup(EventSource eventSource);
  private: void EnableTimer(Single pollingIntervalInSeconds);
  private: void DisableTimer();
  private: void ResetCounters();
  private: void OnTimer();
  private: static void PollForValues();
  private: static void SCtor();
  private: EventSource _eventSource;
  private: List<DiagnosticCounter> _counters;
  private: static Object s_counterGroupLock;
  private: static Array<WeakReference<CounterGroup>> s_counterGroups;
  private: DateTime _timeStampSinceCollectionStarted;
  private: Int32 _pollingIntervalInMilliseconds;
  private: DateTime _nextPollingTimeStamp;
  private: static Thread s_pollingThread;
  private: static AutoResetEvent s_pollingThreadSleepEvent;
  private: static List<CounterGroup> s_counterGroupEnabledList;
};
} // namespace CounterGroupNamespace
using CounterGroup = CounterGroupNamespace::CounterGroup;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
