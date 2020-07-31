#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
FORWARD(IComparer)
FORWARD(IDictionary)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerator)
FORWARD(IEqualityComparer)
FORWARD(IHashCodeProvider)
FORWARD(KeyValuePairs)
namespace HashtableNamespace {
using namespace Runtime::Serialization;
CLASS(Hashtable) : public Object::in {
  private: struct bucket {
    public: Object key;
    public: Object val;
    public: Int32 hash_coll;
  };
  private: CLASS(KeyCollection) : public Object::in {
    public: Boolean get_IsSynchronized();
    public: Object get_SyncRoot();
    public: Int32 get_Count();
    public: void Ctor(Hashtable hashtable);
    public: void CopyTo(Array<> array, Int32 arrayIndex);
    public: IEnumerator GetEnumerator();
    private: Hashtable _hashtable;
  };
  private: CLASS(ValueCollection) : public Object::in {
    public: Boolean get_IsSynchronized();
    public: Object get_SyncRoot();
    public: Int32 get_Count();
    public: void Ctor(Hashtable hashtable);
    public: void CopyTo(Array<> array, Int32 arrayIndex);
    public: IEnumerator GetEnumerator();
    private: Hashtable _hashtable;
  };
  private: CLASS(SyncHashtable) : public Hashtable::in {
    public: Int32 get_Count();
    public: Boolean get_IsReadOnly();
    public: Boolean get_IsFixedSize();
    public: Boolean get_IsSynchronized();
    public: Object get_Item(Object key);
    public: void set_Item(Object key, Object value);
    public: Object get_SyncRoot();
    public: ICollection get_Keys();
    public: ICollection get_Values();
    public: void Ctor(Hashtable table);
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
  private: CLASS(HashtableEnumerator) : public Object::in {
    public: Object get_Key();
    public: DictionaryEntry get_Entry();
    public: Object get_Current();
    public: Object get_Value();
    public: void Ctor(Hashtable hashtable, Int32 getObjRetType);
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
  public: CLASS(HashtableDebugView) : public Object::in {
    public: Array<KeyValuePairs> get_Items();
    public: void Ctor(Hashtable hashtable);
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
  public: void Ctor(Boolean trash);
  public: void Ctor();
  public: void Ctor(Int32 capacity);
  public: void Ctor(Int32 capacity, Single loadFactor);
  public: void Ctor(Int32 capacity, Single loadFactor, IEqualityComparer equalityComparer);
  public: void Ctor(IHashCodeProvider hcp, IComparer comparer);
  public: void Ctor(IEqualityComparer equalityComparer);
  public: void Ctor(Int32 capacity, IHashCodeProvider hcp, IComparer comparer);
  public: void Ctor(Int32 capacity, IEqualityComparer equalityComparer);
  public: void Ctor(IDictionary d);
  public: void Ctor(IDictionary d, Single loadFactor);
  public: void Ctor(IDictionary d, IHashCodeProvider hcp, IComparer comparer);
  public: void Ctor(IDictionary d, IEqualityComparer equalityComparer);
  public: void Ctor(Int32 capacity, Single loadFactor, IHashCodeProvider hcp, IComparer comparer);
  public: void Ctor(IDictionary d, Single loadFactor, IHashCodeProvider hcp, IComparer comparer);
  public: void Ctor(IDictionary d, Single loadFactor, IEqualityComparer equalityComparer);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
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
} // namespace HashtableNamespace
using Hashtable = HashtableNamespace::Hashtable;
} // namespace System::Private::CoreLib::System::Collections
