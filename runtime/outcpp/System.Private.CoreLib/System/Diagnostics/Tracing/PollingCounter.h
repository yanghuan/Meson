#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Int32)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace PollingCounterNamespace {
CLASS(PollingCounter) {
  public: String ToString();
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  private: Func<Double> _metricProvider;
  private: Double _lastVal;
};
} // namespace PollingCounterNamespace
using PollingCounter = PollingCounterNamespace::PollingCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
