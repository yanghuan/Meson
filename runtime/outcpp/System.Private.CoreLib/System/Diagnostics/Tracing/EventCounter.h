#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
namespace EventCounterNamespace {
CLASS(EventCounter) : public DiagnosticCounter::in {
  public: void ctor(String name, EventSource eventSource);
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
