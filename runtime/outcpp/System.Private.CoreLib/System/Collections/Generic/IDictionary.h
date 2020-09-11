#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
namespace IDictionaryNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
CLASS(IDictionary, TKey, TValue) : public object {
  public: using interface = rt::TypeList<ICollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IEnumerable_>;
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: TValue get_Item(TKey key);
  public: void set_Item(TKey key, TValue value);
  public: ICollection<TKey> get_Keys();
  public: ICollection<TValue> get_Values();
  public: IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator();
  public: void Add(KeyValuePair<TKey, TValue> item);
  public: void Clear();
  public: Boolean Contains(KeyValuePair<TKey, TValue> item);
  public: void CopyTo(Array<KeyValuePair<TKey, TValue>> array, Int32 arrayIndex);
  public: Boolean Remove(KeyValuePair<TKey, TValue> item);
  public: Boolean ContainsKey(TKey key);
  public: void Add(TKey key, TValue value);
  public: Boolean Remove(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDictionaryNamespace
template <class TKey, class TValue>
using IDictionary = IDictionaryNamespace::IDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
