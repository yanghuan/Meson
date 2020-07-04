#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventCommandEventArgs)
FORWARD(PollingCounter)
FORWARD(IncrementingPollingCounter)
namespace RuntimeEventSourceNamespace {
CLASS(RuntimeEventSource) {
  public: static void Initialize();
  protected: void OnEventCommand(EventCommandEventArgs command);
  public: static String EventSourceName;
  private: static RuntimeEventSource s_RuntimeEventSource;
  private: PollingCounter _gcHeapSizeCounter;
  private: IncrementingPollingCounter _gen0GCCounter;
  private: IncrementingPollingCounter _gen1GCCounter;
  private: IncrementingPollingCounter _gen2GCCounter;
  private: PollingCounter _cpuTimeCounter;
  private: PollingCounter _workingSetCounter;
  private: PollingCounter _threadPoolThreadCounter;
  private: IncrementingPollingCounter _monitorContentionCounter;
  private: PollingCounter _threadPoolQueueCounter;
  private: IncrementingPollingCounter _completedItemsCounter;
  private: IncrementingPollingCounter _allocRateCounter;
  private: PollingCounter _timerCounter;
  private: IncrementingPollingCounter _exceptionCounter;
  private: PollingCounter _gcTimeCounter;
  private: PollingCounter _gen0SizeCounter;
  private: PollingCounter _gen1SizeCounter;
  private: PollingCounter _gen2SizeCounter;
  private: PollingCounter _lohSizeCounter;
  private: PollingCounter _pohSizeCounter;
  private: PollingCounter _assemblyCounter;
  private: PollingCounter _ilBytesJittedCounter;
  private: PollingCounter _methodsJittedCounter;
};
} // namespace RuntimeEventSourceNamespace
using RuntimeEventSource = RuntimeEventSourceNamespace::RuntimeEventSource;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
