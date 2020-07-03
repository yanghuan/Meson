#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace IncrementingEventCounterNamespace {
CLASS(IncrementingEventCounter) {
  public: void Increment(Double increment);
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
