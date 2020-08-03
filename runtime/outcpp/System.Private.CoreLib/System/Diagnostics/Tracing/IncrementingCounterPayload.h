#pragma once

#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace IncrementingCounterPayloadNamespace {
using namespace Collections::Generic;
using Collections::Generic::IEnumerator;
CLASS(IncrementingCounterPayload) : public Object::in {
  public: String get_Name() { return Name; }
  public: void set_Name(String value) { Name = value; }
  public: String get_DisplayName() { return DisplayName; }
  public: void set_DisplayName(String value) { DisplayName = value; }
  public: String get_DisplayRateTimeScale() { return DisplayRateTimeScale; }
  public: void set_DisplayRateTimeScale(String value) { DisplayRateTimeScale = value; }
  public: Double get_Increment() { return Increment; }
  public: void set_Increment(Double value) { Increment = value; }
  public: Single get_IntervalSec() { return IntervalSec; }
  public: void set_IntervalSec(Single value) { IntervalSec = value; }
  public: String get_Metadata() { return Metadata; }
  public: void set_Metadata(String value) { Metadata = value; }
  public: String get_Series() { return Series; }
  public: void set_Series(String value) { Series = value; }
  public: String get_CounterType() { return CounterType; }
  public: void set_CounterType(String value) { CounterType = value; }
  public: String get_DisplayUnits() { return DisplayUnits; }
  public: void set_DisplayUnits(String value) { DisplayUnits = value; }
  private: IEnumerable<KeyValuePair<String, Object>> get_ForEnumeration();
  public: IEnumerator<KeyValuePair<String, Object>> GetEnumerator();
  public: void Ctor();
  private: String Name;
  private: String DisplayName;
  private: String DisplayRateTimeScale;
  private: Double Increment;
  private: Single IntervalSec;
  private: String Metadata;
  private: String Series;
  private: String CounterType;
  private: String DisplayUnits;
};
} // namespace IncrementingCounterPayloadNamespace
using IncrementingCounterPayload = IncrementingCounterPayloadNamespace::IncrementingCounterPayload;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
