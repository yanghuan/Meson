#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
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
CLASS(EventPayload) : public Object::in {
  public: using interface = rt::TypeList<IDictionary<String, Object>, ICollection<KeyValuePair<String, Object>>, IEnumerable<KeyValuePair<String, Object>>, IEnumerable_>;
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
