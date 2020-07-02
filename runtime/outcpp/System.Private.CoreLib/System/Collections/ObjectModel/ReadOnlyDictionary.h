#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
FORWARD(ICollection, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace ReadOnlyDictionaryNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(ReadOnlyDictionary, TKey, TValue) {
  private: struct DictionaryEnumerator {
    public: Boolean MoveNext();
    public: void Reset();
    private: IDictionary<TKey, TValue> m_dictionary;
    private: IEnumerator<KeyValuePair<TKey, TValue>> m_enumerator;
  };
  public: CLASS(KeyCollection) {
    public: void CopyTo(Array<TKey> array, Int32 arrayIndex);
    public: IEnumerator<TKey> GetEnumerator();
    private: ICollection<TKey> m_collection;
    private: Object m_syncRoot;
  };
  public: CLASS(ValueCollection) {
    public: void CopyTo(Array<TValue> array, Int32 arrayIndex);
    public: IEnumerator<TValue> GetEnumerator();
    private: ICollection<TValue> m_collection;
    private: Object m_syncRoot;
  };
  public: Boolean ContainsKey(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator();
  private: static Boolean IsCompatibleKey(Object key);
  private: IDictionary<TKey, TValue> m_dictionary;
  private: Object m_syncRoot;
  private: KeyCollection m_keys;
  private: ValueCollection m_values;
};
} // namespace ReadOnlyDictionaryNamespace
template <class TKey, class TValue>
using ReadOnlyDictionary = ReadOnlyDictionaryNamespace::ReadOnlyDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
