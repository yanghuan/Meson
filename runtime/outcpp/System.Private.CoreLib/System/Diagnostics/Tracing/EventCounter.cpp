#include "EventCounter-dep.h"

#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventCounterNamespace {
using namespace System::Threading;

void EventCounter___::ctor(String name, Tracing::EventSource eventSource) {
  _min = Double::PositiveInfinity;
  _max = Double::NegativeInfinity;
  InitializeBuffer();
  Publish();
}

void EventCounter___::WriteMetric(Single value) {
  Enqueue(value);
}

void EventCounter___::WriteMetric(Double value) {
  Enqueue(value);
}

String EventCounter___::ToString() {
  Int32 num = Volatile::Read(_count);
  if (num != 0) {
  }
}

void EventCounter___::OnMetricWritten(Double value) {
  _sum += value;
  _sumSquared += value * value;
  if (value > _max) {
    _max = value;
  }
  if (value < _min) {
    _min = value;
  }
  _count++;
}

void EventCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
}

void EventCounter___::ResetStatistics() {
}

void EventCounter___::InitializeBuffer() {
  _bufferedValues = rt::newarr<Array<Double>>(10);
  for (Int32 i = 0; i < _bufferedValues->get_Length(); i++) {
    _bufferedValues[i] = Double::NegativeInfinity;
  }
}

void EventCounter___::Enqueue(Double value) {
  Int32 num = _bufferedValuesIndex;
  Double num2;
}

void EventCounter___::Flush() {
  for (Int32 i = 0; i < _bufferedValues->get_Length(); i++) {
    Double num = Interlocked::Exchange(_bufferedValues[i], Double::NegativeInfinity);
    if (num != Double::NegativeInfinity) {
      OnMetricWritten(num);
    }
  }
  _bufferedValuesIndex = 0;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventCounterNamespace
