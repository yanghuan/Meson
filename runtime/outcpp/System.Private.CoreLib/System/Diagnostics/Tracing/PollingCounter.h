#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter.h>
#include <System.Private.CoreLib/System/Double.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func)
FORWARDS(Int32)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
namespace PollingCounterNamespace {
CLASS(PollingCounter) : public DiagnosticCounter::in {
  public: void ctor(String name, Tracing::EventSource eventSource, Func<Double> metricProvider);
  public: String ToString();
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  private: Func<Double> _metricProvider;
  private: Double _lastVal;
};
} // namespace PollingCounterNamespace
using PollingCounter = PollingCounterNamespace::PollingCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
