#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Single)
FORWARD(String)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventCounterNamespace {
CLASS(EventCounter) {
  public: void WriteMetric(Single value);
  public: void WriteMetric(Double value);
  public: String ToString();
  public: void OnMetricWritten(Double value);
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  public: void ResetStatistics();
  private: void InitializeBuffer();
  private: void Enqueue(Double value);
  protected: void Flush();
  private: Int32 _count;
  private: Double _sum;
  private: Double _sumSquared;
  private: Double _min;
  private: Double _max;
  private: Array<Double> _bufferedValues;
  private: Int32 _bufferedValuesIndex;
};
} // namespace EventCounterNamespace
using EventCounter = EventCounterNamespace::EventCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
