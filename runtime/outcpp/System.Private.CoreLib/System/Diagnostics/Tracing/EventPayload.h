#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPayloadNamespace {
using namespace Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(EventPayload) {
  public: ICollection<String> get_Keys();
  public: ICollection<Object> get_Values();
  public: Object get_Item(String key);
  public: void set_Item(String key, Object value);
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
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
