#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections::Generic {
enum class InsertionBehavior : uint8_t;
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEqualityComparer, T)
namespace DictionaryNamespace {
using namespace Runtime::Serialization;
template <class T>
using ICollection = Generic::ICollection<T>;
using ICollection1 = Collections::ICollection;
CLASS(Dictionary, TKey, TValue) {
  private: struct Entry {
    public: UInt32 hashCode;
    public: Int32 next;
    public: TKey key;
    public: TValue value;
  };
  public: struct Enumerator {
    public: KeyValuePair<TKey, TValue> get_Current();
    private: Object get_CurrentOfIEnumerator();
    private: DictionaryEntry get_EntryOfIDictionaryEnumerator();
    private: Object get_KeyOfIDictionaryEnumerator();
    private: Object get_ValueOfIDictionaryEnumerator();
    public: Boolean MoveNext();
    public: void Dispose();
    private: Dictionary<TKey, TValue> _dictionary;
    private: Int32 _version;
    private: Int32 _index;
    private: KeyValuePair<TKey, TValue> _current;
    private: Int32 _getEnumeratorRetType;
  };
  public: CLASS(KeyCollection) {
    public: struct Enumerator {
      public: TKey get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: void Dispose();
      public: Boolean MoveNext();
      private: Dictionary<TKey, TValue> _dictionary;
      private: Int32 _index;
      private: Int32 _version;
      private: TKey _currentKey;
    };
    public: Int32 get_Count();
    private: Boolean get_IsReadOnlyOfICollectionTKey();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: Enumerator GetEnumerator();
    public: void CopyTo(Array<TKey> array, Int32 index);
    private: Dictionary<TKey, TValue> _dictionary;
  };
  public: CLASS(ValueCollection) {
    public: struct Enumerator {
      public: TValue get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: void Dispose();
      public: Boolean MoveNext();
      private: Dictionary<TKey, TValue> _dictionary;
      private: Int32 _index;
      private: Int32 _version;
      private: TValue _currentValue;
    };
    public: Int32 get_Count();
    private: Boolean get_IsReadOnlyOfICollectionTValue();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: Enumerator GetEnumerator();
    public: void CopyTo(Array<TValue> array, Int32 index);
    private: Dictionary<TKey, TValue> _dictionary;
  };
  public: IEqualityComparer<TKey> get_Comparer();
  public: Int32 get_Count();
  public: KeyCollection get_Keys();
  private: ICollection<TKey> get_KeysOfIDictionaryTKeyTValue();
  private: IEnumerable<TKey> get_KeysOfIReadOnlyDictionaryTKeyTValue();
  public: ValueCollection get_Values();
  private: ICollection<TValue> get_ValuesOfIDictionaryTKeyTValue();
  private: IEnumerable<TValue> get_ValuesOfIReadOnlyDictionaryTKeyTValue();
  public: TValue get_Item(TKey key);
  public: void set_Item(TKey key, TValue value);
  private: Boolean get_IsReadOnlyOfKeyValuePairTKeyTValue();
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  private: Boolean get_IsFixedSizeOfIDictionary();
  private: Boolean get_IsReadOnlyOfIDictionary();
  private: ICollection1 get_KeysOfIDictionary();
  private: ICollection1 get_ValuesOfIDictionary();
  private: Object get_ItemOfIDictionary(Object key);
  private: void set_ItemOfIDictionary(Object key, Object value);
  public: void Add(TKey key, TValue value);
  public: void Clear();
  public: Boolean ContainsKey(TKey key);
  public: Boolean ContainsValue(TValue value);
  private: void CopyTo(Array<KeyValuePair<TKey, TValue>> array, Int32 index);
  public: Enumerator GetEnumerator();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Int32 Initialize(Int32 capacity);
  private: Boolean TryInsert(TKey key, TValue value, InsertionBehavior behavior);
  public: void OnDeserialization(Object sender);
  private: void Resize();
  private: void Resize(Int32 newSize, Boolean forceNewHashCodes);
  public: Boolean Remove(TKey key);
  public: Boolean Remove(TKey key, TValue& value);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: Boolean TryAdd(TKey key, TValue value);
  public: Int32 EnsureCapacity(Int32 capacity);
  public: void TrimExcess();
  public: void TrimExcess(Int32 capacity);
  private: static Boolean IsCompatibleKey(Object key);
  private: Array<Int32> _buckets;
  private: Array<Entry> _entries;
  private: UInt64 _fastModMultiplier;
  private: Int32 _count;
  private: Int32 _freeList;
  private: Int32 _freeCount;
  private: Int32 _version;
  private: IEqualityComparer<TKey> _comparer;
  private: KeyCollection _keys;
  private: ValueCollection _values;
};
} // namespace DictionaryNamespace
template <class TKey, class TValue>
using Dictionary = DictionaryNamespace::Dictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
