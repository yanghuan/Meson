#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Double)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
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
    public: Double _OnEventCommand_b__27_0();
    public: Double _OnEventCommand_b__27_1();
    public: Double _OnEventCommand_b__27_2();
    public: Double _OnEventCommand_b__27_3();
    public: Double _OnEventCommand_b__27_4();
    public: Double _OnEventCommand_b__27_5();
    public: Double _OnEventCommand_b__27_6();
    public: Double _OnEventCommand_b__27_7();
    public: Double _OnEventCommand_b__27_8();
    public: Double _OnEventCommand_b__27_9();
    public: Double _OnEventCommand_b__27_10();
    public: Double _OnEventCommand_b__27_11();
    public: Double _OnEventCommand_b__27_12();
    public: Double _OnEventCommand_b__27_13();
    public: Double _OnEventCommand_b__27_14();
    public: Double _OnEventCommand_b__27_15();
    public: Double _OnEventCommand_b__27_16();
    public: Double _OnEventCommand_b__27_17();
    public: Double _OnEventCommand_b__27_18();
    public: Double _OnEventCommand_b__27_19();
    public: Double _OnEventCommand_b__27_20();
    public: Double _OnEventCommand_b__27_21();
    public: Double _OnEventCommand_b__27_22();
    public: static __c __9;
    public: static Func<Double> __9__27_0;
    public: static Func<Double> __9__27_1;
    public: static Func<Double> __9__27_2;
    public: static Func<Double> __9__27_3;
    public: static Func<Double> __9__27_4;
    public: static Func<Double> __9__27_5;
    public: static Func<Double> __9__27_6;
    public: static Func<Double> __9__27_7;
    public: static Func<Double> __9__27_8;
    public: static Func<Double> __9__27_9;
    public: static Func<Double> __9__27_10;
    public: static Func<Double> __9__27_11;
    public: static Func<Double> __9__27_12;
    public: static Func<Double> __9__27_13;
    public: static Func<Double> __9__27_14;
    public: static Func<Double> __9__27_15;
    public: static Func<Double> __9__27_16;
    public: static Func<Double> __9__27_17;
    public: static Func<Double> __9__27_18;
    public: static Func<Double> __9__27_19;
    public: static Func<Double> __9__27_20;
    public: static Func<Double> __9__27_21;
    public: static Func<Double> __9__27_22;
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
  private: PollingCounter _fragmentationCounter;
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
