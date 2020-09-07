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
namespace CounterPayloadNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(CounterPayload) : public object {
  public: using interface = rt::TypeList<IEnumerable<KeyValuePair<String, Object>>, IEnumerable_>;
  private: CLASS(_get_ForEnumeration_d__51) : public object {
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
    public: CounterPayload __4__this;
  };
  public: String get_Name() { return Name; }
  public: void set_Name(String value) { Name = value; }
  public: String get_DisplayName() { return DisplayName; }
  public: void set_DisplayName(String value) { DisplayName = value; }
  public: Double get_Mean() { return Mean; }
  public: void set_Mean(Double value) { Mean = value; }
  public: Double get_StandardDeviation() { return StandardDeviation; }
  public: void set_StandardDeviation(Double value) { StandardDeviation = value; }
  public: Int32 get_Count() { return Count; }
  public: void set_Count(Int32 value) { Count = value; }
  public: Double get_Min() { return Min; }
  public: void set_Min(Double value) { Min = value; }
  public: Double get_Max() { return Max; }
  public: void set_Max(Double value) { Max = value; }
  public: Single get_IntervalSec() { return IntervalSec; }
  public: void set_IntervalSec(Single value) { IntervalSec = value; }
  public: String get_Series() { return Series; }
  public: void set_Series(String value) { Series = value; }
  public: String get_CounterType() { return CounterType; }
  public: void set_CounterType(String value) { CounterType = value; }
  public: String get_Metadata() { return Metadata; }
  public: void set_Metadata(String value) { Metadata = value; }
  public: String get_DisplayUnits() { return DisplayUnits; }
  public: void set_DisplayUnits(String value) { DisplayUnits = value; }
  private: IEnumerable<KeyValuePair<String, Object>> get_ForEnumeration();
  public: IEnumerator<KeyValuePair<String, Object>> GetEnumerator();
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  public: void ctor();
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
