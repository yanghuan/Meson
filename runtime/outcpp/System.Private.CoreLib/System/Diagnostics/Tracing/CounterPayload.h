#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace CounterPayloadNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(CounterPayload) {
  private: IEnumerable<KeyValuePair<String, Object>> get_ForEnumeration();
  public: IEnumerator<KeyValuePair<String, Object>> GetEnumerator();
  private: String Name;
  private: String DisplayName;
  private: Double Mean;
  private: Double StandardDeviation;
  private: Int32 Count;
  private: Double Min;
  private: Double Max;
  private: Single IntervalSec;
  private: String Series;
  private: String CounterType;
  private: String Metadata;
  private: String DisplayUnits;
};
} // namespace CounterPayloadNamespace
using CounterPayload = CounterPayloadNamespace::CounterPayload;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
