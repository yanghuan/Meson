#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace IncrementingCounterPayloadNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(IncrementingCounterPayload) : public object {
  public: using interface = rt::TypeList<IEnumerable<KeyValuePair<String, Object>>, IEnumerable_>;
  private: CLASS(_get_ForEnumeration_d__39) : public object {
    public: using interface = rt::TypeList<IEnumerable<KeyValuePair<String, Object>>, IEnumerable_, IEnumerator<KeyValuePair<String, Object>>, IDisposable, IEnumerator_>;
    private: KeyValuePair<String, Object> get_CurrentOfObject();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: IEnumerator<KeyValuePair<String, Object>> GetEnumeratorOfObject();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: KeyValuePair<String, Object> __2__current;
    private: Int32 __l__initialThreadId;
    public: IncrementingCounterPayload __4__this;
  };
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
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  public: void ctor();
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
