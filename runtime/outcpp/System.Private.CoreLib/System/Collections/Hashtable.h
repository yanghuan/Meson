#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Single.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(ICloneable)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
FORWARD(IComparer)
FORWARD(IDictionary)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
FORWARD(IEqualityComparer)
FORWARD(IHashCodeProvider)
FORWARD(KeyValuePairs)
namespace HashtableNamespace {
using namespace System::Runtime::Serialization;
CLASS(Hashtable) : public object {
  public: using interface = rt::TypeList<IDictionary, ICollection, IEnumerable, ISerializable, IDeserializationCallback, ICloneable>;
  private: struct bucket : public valueType<bucket> {
    public: Object key;
    public: Object val;
    public: Int32 hash_coll;
  };
  private: CLASS(KeyCollection) : public object {
    public: using interface = rt::TypeList<ICollection, IEnumerable>;
    public: Boolean get_IsSynchronized();
    public: Object get_SyncRoot();
    public: Int32 get_Count();
    public: void ctor(Hashtable hashtable);
    public: void CopyTo(Array<> array, Int32 arrayIndex);
    public: IEnumerator GetEnumerator();
    private: Hashtable _hashtable;
  };
  private: CLASS(ValueCollection) : public object {
    public: using interface = rt::TypeList<ICollection, IEnumerable>;
    public: Boolean get_IsSynchronized();
    public: Object get_SyncRoot();
    public: Int32 get_Count();
    public: void ctor(Hashtable hashtable);
    public: void CopyTo(Array<> array, Int32 arrayIndex);
    public: IEnumerator GetEnumerator();
    private: Hashtable _hashtable;
  };
  private: FRIENDN(SyncHashtable)
  private: CLASS(HashtableEnumerator) : public object {
    public: using interface = rt::TypeList<IDictionaryEnumerator, IEnumerator, ICloneable>;
    public: Object get_Key();
    public: DictionaryEntry get_Entry();
    public: Object get_Current();
    public: Object get_Value();
    public: void ctor(Hashtable hashtable, Int32 getObjRetType);
    public: Object Clone();
    public: Boolean MoveNext();
    public: void Reset();
    private: Hashtable _hashtable;
    private: Int32 _bucket;
    private: Int32 _version;
    private: Boolean _current;
    private: Int32 _getObjectRetType;
    private: Object _currentKey;
    private: Object _currentValue;
  };
  public: CLASS(HashtableDebugView) : public object {
    public: Array<KeyValuePairs> get_Items();
    public: void ctor(Hashtable hashtable);
    private: Hashtable _hashtable;
  };
  protected: IHashCodeProvider get_hcp();
  protected: void set_hcp(IHashCodeProvider value);
  protected: IComparer get_comparer();
  protected: void set_comparer(IComparer value);
  protected: IEqualityComparer get_EqualityComparer();
  public: Object get_Item(Object key);
  public: void set_Item(Object key, Object value);
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: ICollection get_Keys();
  public: ICollection get_Values();
  public: Object get_SyncRoot();
  public: Int32 get_Count();
  public: void ctor(Boolean trash);
  public: void ctor();
  public: void ctor(Int32 capacity);
  public: void ctor(Int32 capacity, Single loadFactor);
  public: void ctor(Int32 capacity, Single loadFactor, IEqualityComparer equalityComparer);
  public: void ctor(IHashCodeProvider hcp, IComparer comparer);
  public: void ctor(IEqualityComparer equalityComparer);
  public: void ctor(Int32 capacity, IHashCodeProvider hcp, IComparer comparer);
  public: void ctor(Int32 capacity, IEqualityComparer equalityComparer);
  public: void ctor(IDictionary d);
  public: void ctor(IDictionary d, Single loadFactor);
  public: void ctor(IDictionary d, IHashCodeProvider hcp, IComparer comparer);
  public: void ctor(IDictionary d, IEqualityComparer equalityComparer);
  public: void ctor(Int32 capacity, Single loadFactor, IHashCodeProvider hcp, IComparer comparer);
  public: void ctor(IDictionary d, Single loadFactor, IHashCodeProvider hcp, IComparer comparer);
  public: void ctor(IDictionary d, Single loadFactor, IEqualityComparer equalityComparer);
  public: void ctor(SerializationInfo info, StreamingContext context);
  private: UInt32 InitHash(Object key, Int32 hashsize, UInt32& seed, UInt32& incr);
  public: void Add(Object key, Object value);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object key);
  public: Boolean ContainsKey(Object key);
  public: Boolean ContainsValue(Object value);
  private: void CopyKeys(Array<> array, Int32 arrayIndex);
  private: void CopyEntries(Array<> array, Int32 arrayIndex);
  public: void CopyTo(Array<> array, Int32 arrayIndex);
  public: Array<KeyValuePairs> ToKeyValuePairsArray();
  private: void CopyValues(Array<> array, Int32 arrayIndex);
  private: void expand();
  private: void rehash();
  private: void UpdateVersion();
  private: void rehash(Int32 newsize);
  public: IDictionaryEnumerator GetEnumerator();
  protected: Int32 GetHash(Object key);
  protected: Boolean KeyEquals(Object item, Object key);
  private: void Insert(Object key, Object nvalue, Boolean add);
  private: void putEntry(Array<bucket> newBuckets, Object key, Object nvalue, Int32 hashcode);
  public: void Remove(Object key);
  public: static Hashtable Synchronized(Hashtable table);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: void OnDeserialization(Object sender);
  private: Array<bucket> _buckets;
  private: Int32 _count;
  private: Int32 _occupancy;
  private: Int32 _loadsize;
  private: Single _loadFactor;
  private: Int32 _version;
  private: Boolean _isWriterInProgress;
  private: ICollection _keys;
  private: ICollection _values;
  private: IEqualityComparer _keycomparer;
};
CLASS(SyncHashtable) : public Hashtable::in {
  public: using interface = rt::TypeList<IEnumerable>;
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Object key);
  public: void set_Item(Object key, Object value);
  public: Object get_SyncRoot();
  public: ICollection get_Keys();
  public: ICollection get_Values();
  public: void ctor(Hashtable table);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: void Add(Object key, Object value);
  public: void Clear();
  public: Boolean Contains(Object key);
  public: Boolean ContainsKey(Object key);
  public: Boolean ContainsValue(Object key);
  public: void CopyTo(Array<> array, Int32 arrayIndex);
  public: Object Clone();
  public: IDictionaryEnumerator GetEnumerator();
  public: void Remove(Object key);
  public: void OnDeserialization(Object sender);
  public: Array<KeyValuePairs> ToKeyValuePairsArray();
  protected: Hashtable _table;
};
} // namespace HashtableNamespace
using Hashtable = HashtableNamespace::Hashtable;
} // namespace System::Private::CoreLib::System::Collections
