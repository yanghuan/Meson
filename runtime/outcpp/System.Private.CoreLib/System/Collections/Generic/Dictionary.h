#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
FORWARD(IDictionary)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
enum class InsertionBehavior : uint8_t;
FORWARD(ICollection, T)
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IEqualityComparer, T)
FORWARD(IReadOnlyCollection, T)
FORWARD(IReadOnlyDictionary, TKey, TValue)
namespace DictionaryNamespace {
using namespace System::Runtime::Serialization;
template <class TKey, class TValue>
using IDictionary = Generic::IDictionary<TKey, TValue>;
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using IDictionary_ = Collections::IDictionary;
using ICollection_ = Collections::ICollection;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
CLASS(Dictionary, TKey, TValue) : public object {
  public: using interface = rt::TypeList<IDictionary<TKey, TValue>, ICollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IEnumerable_, IDictionary_, ICollection_, IReadOnlyDictionary<TKey, TValue>, IReadOnlyCollection<KeyValuePair<TKey, TValue>>, ISerializable, IDeserializationCallback>;
  private: struct Entry : public valueType<Entry> {
    public: UInt32 hashCode;
    public: Int32 next;
    public: TKey key;
    public: TValue value;
  };
  public: struct Enumerator : public valueType<Enumerator> {
    public: using interface = rt::TypeList<IEnumerator<KeyValuePair<TKey, TValue>>, IDisposable, IEnumerator_, IDictionaryEnumerator>;
    public: KeyValuePair<TKey, TValue> get_Current();
    private: Object get_CurrentOfIEnumerator();
    private: DictionaryEntry get_EntryOfIDictionaryEnumerator();
    private: Object get_KeyOfIDictionaryEnumerator();
    private: Object get_ValueOfIDictionaryEnumerator();
    public: explicit Enumerator(Dictionary<TKey, TValue> dictionary, Int32 getEnumeratorRetType);
    public: Boolean MoveNext();
    public: void Dispose();
    private: void ResetOfIEnumerator();
    public: explicit Enumerator() {}
    private: Dictionary<TKey, TValue> _dictionary;
    private: Int32 _version;
    private: Int32 _index;
    private: KeyValuePair<TKey, TValue> _current;
    private: Int32 _getEnumeratorRetType;
  };
  public: CLASS(KeyCollection) : public object {
    public: using interface = rt::TypeList<ICollection<TKey>, IEnumerable<TKey>, IEnumerable_, ICollection_, IReadOnlyCollection<TKey>>;
    public: struct Enumerator : public valueType<Enumerator> {
      public: using interface = rt::TypeList<IEnumerator<TKey>, IDisposable, IEnumerator_>;
      public: TKey get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: explicit Enumerator(Dictionary<TKey, TValue> dictionary);
      public: void Dispose();
      public: Boolean MoveNext();
      private: void ResetOfIEnumerator();
      public: explicit Enumerator() {}
      private: Dictionary<TKey, TValue> _dictionary;
      private: Int32 _index;
      private: Int32 _version;
      private: TKey _currentKey;
    };
    public: Int32 get_Count();
    private: Boolean get_IsReadOnlyOfICollectionTKey();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: void ctor(Dictionary<TKey, TValue> dictionary);
    public: Enumerator GetEnumerator();
    public: void CopyTo(Array<TKey> array, Int32 index);
    private: void AddOfICollectionTKey(TKey item);
    private: void ClearOfICollectionTKey();
    private: Boolean ContainsOfICollectionTKey(TKey item);
    private: Boolean RemoveOfICollectionTKey(TKey item);
    private: IEnumerator<TKey> GetEnumeratorOfIEnumerableTKey();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: void CopyToOfICollection(Array<> array, Int32 index);
    private: Dictionary<TKey, TValue> _dictionary;
  };
  public: CLASS(ValueCollection) : public object {
    public: using interface = rt::TypeList<ICollection<TValue>, IEnumerable<TValue>, IEnumerable_, ICollection_, IReadOnlyCollection<TValue>>;
    public: struct Enumerator : public valueType<Enumerator> {
      public: using interface = rt::TypeList<IEnumerator<TValue>, IDisposable, IEnumerator_>;
      public: TValue get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: explicit Enumerator(Dictionary<TKey, TValue> dictionary);
      public: void Dispose();
      public: Boolean MoveNext();
      private: void ResetOfIEnumerator();
      public: explicit Enumerator() {}
      private: Dictionary<TKey, TValue> _dictionary;
      private: Int32 _index;
      private: Int32 _version;
      private: TValue _currentValue;
    };
    public: Int32 get_Count();
    private: Boolean get_IsReadOnlyOfICollectionTValue();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: void ctor(Dictionary<TKey, TValue> dictionary);
    public: Enumerator GetEnumerator();
    public: void CopyTo(Array<TValue> array, Int32 index);
    private: void AddOfICollectionTValue(TValue item);
    private: Boolean RemoveOfICollectionTValue(TValue item);
    private: void ClearOfICollectionTValue();
    private: Boolean ContainsOfICollectionTValue(TValue item);
    private: IEnumerator<TValue> GetEnumeratorOfIEnumerableTValue();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: void CopyToOfICollection(Array<> array, Int32 index);
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
  private: ICollection_ get_KeysOfIDictionary();
  private: ICollection_ get_ValuesOfIDictionary();
  private: Object get_ItemOfIDictionary(Object key);
  private: void set_ItemOfIDictionary(Object key, Object value);
  public: void ctor();
  public: void ctor(Int32 capacity);
  public: void ctor(IEqualityComparer<TKey> comparer);
  public: void ctor(Int32 capacity, IEqualityComparer<TKey> comparer);
  public: void ctor(IDictionary<TKey, TValue> dictionary);
  public: void ctor(IDictionary<TKey, TValue> dictionary, IEqualityComparer<TKey> comparer);
  public: void ctor(IEnumerable<KeyValuePair<TKey, TValue>> collection);
  public: void ctor(IEnumerable<KeyValuePair<TKey, TValue>> collection, IEqualityComparer<TKey> comparer);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void Add(TKey key, TValue value);
  private: void AddOfKeyValuePairTKeyTValue(KeyValuePair<TKey, TValue> keyValuePair);
  private: Boolean ContainsOfKeyValuePairTKeyTValue(KeyValuePair<TKey, TValue> keyValuePair);
  private: Boolean RemoveOfKeyValuePairTKeyTValue(KeyValuePair<TKey, TValue> keyValuePair);
  public: void Clear();
  public: Boolean ContainsKey(TKey key);
  public: Boolean ContainsValue(TValue value);
  private: void CopyTo(Array<KeyValuePair<TKey, TValue>> array, Int32 index);
  public: Enumerator GetEnumerator();
  private: IEnumerator<KeyValuePair<TKey, TValue>> GetEnumeratorOfKeyValuePairTKeyTValue();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: TValue& FindValue(TKey key);
  private: Int32 Initialize(Int32 capacity);
  private: Boolean TryInsert(TKey key, TValue value, InsertionBehavior behavior);
  public: void OnDeserialization(Object sender);
  private: void Resize();
  private: void Resize(Int32 newSize, Boolean forceNewHashCodes);
  public: Boolean Remove(TKey key);
  public: Boolean Remove(TKey key, TValue& value);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: Boolean TryAdd(TKey key, TValue value);
  private: void CopyToOfKeyValuePairTKeyTValue(Array<KeyValuePair<TKey, TValue>> array, Int32 index);
  private: void CopyToOfICollection(Array<> array, Int32 index);
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  public: Int32 EnsureCapacity(Int32 capacity);
  public: void TrimExcess();
  public: void TrimExcess(Int32 capacity);
  private: static Boolean IsCompatibleKey(Object key);
  private: void AddOfIDictionary(Object key, Object value);
  private: Boolean ContainsOfIDictionary(Object key);
  private: IDictionaryEnumerator GetEnumeratorOfIDictionary();
  private: void RemoveOfIDictionary(Object key);
  private: Int32& GetBucket(UInt32 hashCode);
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
  public: TValue& operator [](TKey key);
};
} // namespace DictionaryNamespace
template <class TKey, class TValue>
using Dictionary = DictionaryNamespace::Dictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
