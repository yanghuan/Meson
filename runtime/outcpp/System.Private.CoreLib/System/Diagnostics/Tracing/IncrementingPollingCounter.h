#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func)
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
  public: void ctor(String name, Tracing::EventSource eventSource, Func<Double> totalValueProvider);
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
