#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Double)
FORWARD_(Func)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventCommandEventArgs)
FORWARD(IncrementingPollingCounter)
FORWARD(PollingCounter)
namespace RuntimeEventSourceNamespace {
CLASS(RuntimeEventSource) : public EventSource::in {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: Double _OnEventCommand_b__26_0();
    public: Double _OnEventCommand_b__26_1();
    public: Double _OnEventCommand_b__26_2();
    public: Double _OnEventCommand_b__26_3();
    public: Double _OnEventCommand_b__26_4();
    public: Double _OnEventCommand_b__26_5();
    public: Double _OnEventCommand_b__26_6();
    public: Double _OnEventCommand_b__26_7();
    public: Double _OnEventCommand_b__26_8();
    public: Double _OnEventCommand_b__26_9();
    public: Double _OnEventCommand_b__26_10();
    public: Double _OnEventCommand_b__26_11();
    public: Double _OnEventCommand_b__26_12();
    public: Double _OnEventCommand_b__26_13();
    public: Double _OnEventCommand_b__26_14();
    public: Double _OnEventCommand_b__26_15();
    public: Double _OnEventCommand_b__26_16();
    public: Double _OnEventCommand_b__26_17();
    public: Double _OnEventCommand_b__26_18();
    public: Double _OnEventCommand_b__26_19();
    public: Double _OnEventCommand_b__26_20();
    public: Double _OnEventCommand_b__26_21();
    public: static __c __9;
    public: static Func<Double> __9__26_0;
    public: static Func<Double> __9__26_1;
    public: static Func<Double> __9__26_2;
    public: static Func<Double> __9__26_3;
    public: static Func<Double> __9__26_4;
    public: static Func<Double> __9__26_5;
    public: static Func<Double> __9__26_6;
    public: static Func<Double> __9__26_7;
    public: static Func<Double> __9__26_8;
    public: static Func<Double> __9__26_9;
    public: static Func<Double> __9__26_10;
    public: static Func<Double> __9__26_11;
    public: static Func<Double> __9__26_12;
    public: static Func<Double> __9__26_13;
    public: static Func<Double> __9__26_14;
    public: static Func<Double> __9__26_15;
    public: static Func<Double> __9__26_16;
    public: static Func<Double> __9__26_17;
    public: static Func<Double> __9__26_18;
    public: static Func<Double> __9__26_19;
    public: static Func<Double> __9__26_20;
    public: static Func<Double> __9__26_21;
  };
  public: static void Initialize();
  public: void ctor();
  protected: void OnEventCommand(EventCommandEventArgs command);
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
