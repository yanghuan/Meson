#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPayloadNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class TKey, class TValue>
using IDictionary = Collections::Generic::IDictionary<TKey, TValue>;
template <class T>
using ICollection = Collections::Generic::ICollection<T>;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(EventPayload) : public object {
  public: using interface = rt::TypeList<IDictionary<String, Object>, ICollection<KeyValuePair<String, Object>>, IEnumerable<KeyValuePair<String, Object>>, IEnumerable_>;
  private: CLASS(_GetEnumerator_d__17) : public object {
    public: using interface = rt::TypeList<IEnumerator<KeyValuePair<String, Object>>, IDisposable, IEnumerator_>;
    private: KeyValuePair<String, Object> get_CurrentOfObject();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: Int32 __1__state;
    private: KeyValuePair<String, Object> __2__current;
    public: EventPayload __4__this;
    private: Int32 _i_5__2;
  };
  public: ICollection<String> get_Keys();
  public: ICollection<Object> get_Values();
  public: Object get_Item(String key);
  public: void set_Item(String key, Object value);
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: void ctor(List<String> payloadNames, List<Object> payloadValues);
  public: void Add(String key, Object value);
  public: void Add(KeyValuePair<String, Object> payloadEntry);
  public: void Clear();
  public: Boolean Contains(KeyValuePair<String, Object> entry);
  public: Boolean ContainsKey(String key);
  public: IEnumerator<KeyValuePair<String, Object>> GetEnumerator();
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  public: void CopyTo(Array<KeyValuePair<String, Object>> payloadEntries, Int32 count);
  public: Boolean Remove(String key);
  public: Boolean Remove(KeyValuePair<String, Object> entry);
  public: Boolean TryGetValue(String key, Object& value);
  private: List<String> m_names;
  private: List<Object> m_values;
};
} // namespace EventPayloadNamespace
using EventPayload = EventPayloadNamespace::EventPayload;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
