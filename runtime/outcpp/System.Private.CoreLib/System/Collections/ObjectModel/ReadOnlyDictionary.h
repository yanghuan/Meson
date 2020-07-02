#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace ReadOnlyDictionaryNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
template <class T>
using ICollection = ::System::Private::CoreLib::System::Collections::Generic::ICollection<T>;
using ICollection1 = ::System::Private::CoreLib::System::Collections::ICollection;
CLASS(ReadOnlyDictionary, TKey, TValue) {
  private: struct DictionaryEnumerator {
    public: DictionaryEntry get_Entry();
    public: Object get_Key();
    public: Object get_Value();
    public: Object get_Current();
    public: Boolean MoveNext();
    public: void Reset();
    private: IDictionary<TKey, TValue> m_dictionary;
    private: IEnumerator<KeyValuePair<TKey, TValue>> m_enumerator;
  };
  public: CLASS(KeyCollection) {
    public: Int32 get_Count();
    private: Boolean get_IsReadOnlyOfICollectionTKey();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: void CopyTo(Array<TKey> array, Int32 arrayIndex);
    public: IEnumerator<TKey> GetEnumerator();
    private: ICollection<TKey> m_collection;
    private: Object m_syncRoot;
  };
  public: CLASS(ValueCollection) {
    public: Int32 get_Count();
    private: Boolean get_IsReadOnlyOfICollectionTValue();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: void CopyTo(Array<TValue> array, Int32 arrayIndex);
    public: IEnumerator<TValue> GetEnumerator();
    private: ICollection<TValue> m_collection;
    private: Object m_syncRoot;
  };
  public: KeyCollection get_Keys();
  public: ValueCollection get_Values();
  private: ICollection<TKey> get_KeysOfIDictionaryTKeyTValue();
  private: ICollection<TValue> get_ValuesOfIDictionaryTKeyTValue();
  public: TValue get_Item(TKey key);
  private: TValue get_ItemOfIDictionaryTKeyTValue(TKey key);
  private: void set_ItemOfIDictionaryTKeyTValue(TKey key, TValue value);
  public: Int32 get_Count();
  private: Boolean get_IsReadOnlyOfKeyValuePairTKeyTValue();
  private: Boolean get_IsFixedSizeOfIDictionary();
  private: Boolean get_IsReadOnlyOfIDictionary();
  private: ICollection1 get_KeysOfIDictionary();
  private: ICollection1 get_ValuesOfIDictionary();
  private: Object get_ItemOfIDictionary(Object key);
  private: void set_ItemOfIDictionary(Object key, Object value);
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  private: IEnumerable<TKey> get_KeysOfIReadOnlyDictionaryTKeyTValue();
  private: IEnumerable<TValue> get_ValuesOfIReadOnlyDictionaryTKeyTValue();
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
