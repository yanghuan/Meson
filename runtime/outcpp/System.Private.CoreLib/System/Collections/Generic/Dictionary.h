#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections::Generic {
enum class InsertionBehavior : uint8_t;
FORWARD(IEqualityComparer, T)
namespace DictionaryNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(Dictionary, TKey, TValue) {
  private: struct Entry {
    public: Int32 next;
    public: UInt32 hashCode;
    public: TKey key;
    public: TValue value;
  };
  public: struct Enumerator {
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
      public: void Dispose();
      public: Boolean MoveNext();
      private: Dictionary<TKey, TValue> _dictionary;
      private: Int32 _index;
      private: Int32 _version;
      private: TKey _currentKey;
    };
    public: Enumerator GetEnumerator();
    public: void CopyTo(Array<TKey> array, Int32 index);
    private: Dictionary<TKey, TValue> _dictionary;
  };
  public: CLASS(ValueCollection) {
    public: struct Enumerator {
      public: void Dispose();
      public: Boolean MoveNext();
      private: Dictionary<TKey, TValue> _dictionary;
      private: Int32 _index;
      private: Int32 _version;
      private: TValue _currentValue;
    };
    public: Enumerator GetEnumerator();
    public: void CopyTo(Array<TValue> array, Int32 index);
    private: Dictionary<TKey, TValue> _dictionary;
  };
  public: void Add(TKey key, TValue value);
  public: void Clear();
  public: Boolean ContainsKey(TKey key);
  public: Boolean ContainsValue(TValue value);
  private: void CopyTo(Array<KeyValuePair<TKey, TValue>> array, Int32 index);
  public: Enumerator GetEnumerator();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Int32 FindEntry(TKey key);
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
