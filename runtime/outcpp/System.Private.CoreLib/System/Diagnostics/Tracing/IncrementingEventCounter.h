#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
namespace IncrementingEventCounterNamespace {
CLASS(IncrementingEventCounter) : public DiagnosticCounter::in {
  public: TimeSpan get_DisplayRateTimeScale() { return DisplayRateTimeScale; }
  public: void set_DisplayRateTimeScale(TimeSpan value) { DisplayRateTimeScale = value; }
  public: void ctor(String name, Tracing::EventSource eventSource);
  public: void Increment(Double increment = 1);
  public: String ToString();
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  public: void UpdateMetric();
  private: TimeSpan DisplayRateTimeScale;
  private: Double _increment;
  private: Double _prevIncrement;
};
} // namespace IncrementingEventCounterNamespace
using IncrementingEventCounter = IncrementingEventCounterNamespace::IncrementingEventCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
