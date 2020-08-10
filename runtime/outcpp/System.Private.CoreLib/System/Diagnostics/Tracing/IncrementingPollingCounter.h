#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Int32)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
namespace IncrementingPollingCounterNamespace {
CLASS(IncrementingPollingCounter) : public DiagnosticCounter::in {
  public: TimeSpan get_DisplayRateTimeScale() { return DisplayRateTimeScale; }
  public: void set_DisplayRateTimeScale(TimeSpan value) { DisplayRateTimeScale = value; }
  public: void ctor(String name, EventSource eventSource, Func<Double> totalValueProvider);
  public: String ToString();
  public: void UpdateMetric();
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  private: TimeSpan DisplayRateTimeScale;
  private: Double _increment;
  private: Double _prevIncrement;
  private: Func<Double> _totalValueProvider;
};
} // namespace IncrementingPollingCounterNamespace
using IncrementingPollingCounter = IncrementingPollingCounterNamespace::IncrementingPollingCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
