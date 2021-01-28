#include "Hashtable-dep.h"

#include <System.Private.CoreLib/<PrivateImplementationDetails>-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/CompatibleComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/HashHelpers-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationInfoEnumerator-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Collections::HashtableNamespace {
using namespace System::Runtime::Serialization;
using namespace System::Threading;

Boolean Hashtable___::KeyCollection___::get_IsSynchronized() {
  return _hashtable->get_IsSynchronized();
}

Object Hashtable___::KeyCollection___::get_SyncRoot() {
  return _hashtable->get_SyncRoot();
}

Int32 Hashtable___::KeyCollection___::get_Count() {
  return _hashtable->_count;
}

void Hashtable___::KeyCollection___::ctor(Hashtable hashtable) {
  _hashtable = hashtable;
}

void Hashtable___::KeyCollection___::CopyTo(Array<> array, Int32 arrayIndex) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  if (arrayIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("arrayIndex", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - arrayIndex < _hashtable->_count) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayPlusOffTooSmall());
  }
  _hashtable->CopyKeys(array, arrayIndex);
}

IEnumerator Hashtable___::KeyCollection___::GetEnumerator() {
  return rt::newobj<HashtableEnumerator>(_hashtable, 1);
}

Boolean Hashtable___::ValueCollection___::get_IsSynchronized() {
  return _hashtable->get_IsSynchronized();
}

Object Hashtable___::ValueCollection___::get_SyncRoot() {
  return _hashtable->get_SyncRoot();
}

Int32 Hashtable___::ValueCollection___::get_Count() {
  return _hashtable->_count;
}

void Hashtable___::ValueCollection___::ctor(Hashtable hashtable) {
  _hashtable = hashtable;
}

void Hashtable___::ValueCollection___::CopyTo(Array<> array, Int32 arrayIndex) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  if (arrayIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("arrayIndex", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - arrayIndex < _hashtable->_count) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayPlusOffTooSmall());
  }
  _hashtable->CopyValues(array, arrayIndex);
}

IEnumerator Hashtable___::ValueCollection___::GetEnumerator() {
  return rt::newobj<HashtableEnumerator>(_hashtable, 2);
}

Int32 SyncHashtable___::get_Count() {
  return _table->get_Count();
}

Boolean SyncHashtable___::get_IsReadOnly() {
  return _table->get_IsReadOnly();
}

Boolean SyncHashtable___::get_IsFixedSize() {
  return _table->get_IsFixedSize();
}

Boolean SyncHashtable___::get_IsSynchronized() {
  return true;
}

Object SyncHashtable___::get_Item(Object key) {
  return _table[key];
}

void SyncHashtable___::set_Item(Object key, Object value) {
  {
    rt::lock(_table->get_SyncRoot());
    _table[key] = value;
  }
}

Object SyncHashtable___::get_SyncRoot() {
  return _table->get_SyncRoot();
}

ICollection SyncHashtable___::get_Keys() {
  {
    rt::lock(_table->get_SyncRoot());
    return _table->get_Keys();
  }
}

ICollection SyncHashtable___::get_Values() {
  {
    rt::lock(_table->get_SyncRoot());
    return _table->get_Values();
  }
}

void SyncHashtable___::ctor(Hashtable table) {
  _table = table;
}

void SyncHashtable___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

void SyncHashtable___::Add(Object key, Object value) {
  {
    rt::lock(_table->get_SyncRoot());
    _table->Add(key, value);
  }
}

void SyncHashtable___::Clear() {
  {
    rt::lock(_table->get_SyncRoot());
    _table->Clear();
  }
}

Boolean SyncHashtable___::Contains(Object key) {
  return _table->Contains(key);
}

Boolean SyncHashtable___::ContainsKey(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  return _table->ContainsKey(key);
}

Boolean SyncHashtable___::ContainsValue(Object key) {
  {
    rt::lock(_table->get_SyncRoot());
    return _table->ContainsValue(key);
  }
}

void SyncHashtable___::CopyTo(Array<> array, Int32 arrayIndex) {
  {
    rt::lock(_table->get_SyncRoot());
    _table->CopyTo(array, arrayIndex);
  }
}

Object SyncHashtable___::Clone() {
  {
    rt::lock(_table->get_SyncRoot());
    return Synchronized((Hashtable)_table->Clone());
  }
}

IEnumerator SyncHashtable___::GetEnumeratorOfIEnumerable() {
  return _table->GetEnumerator();
}

IDictionaryEnumerator SyncHashtable___::GetEnumerator() {
  return _table->GetEnumerator();
}

void SyncHashtable___::Remove(Object key) {
  {
    rt::lock(_table->get_SyncRoot());
    _table->Remove(key);
  }
}

void SyncHashtable___::OnDeserialization(Object sender) {
}

Array<KeyValuePairs> SyncHashtable___::ToKeyValuePairsArray() {
  return _table->ToKeyValuePairsArray();
}

Object Hashtable___::HashtableEnumerator___::get_Key() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  return _currentKey;
}

DictionaryEntry Hashtable___::HashtableEnumerator___::get_Entry() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return DictionaryEntry(_currentKey, _currentValue);
}

Object Hashtable___::HashtableEnumerator___::get_Current() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  if (_getObjectRetType == 1) {
    return _currentKey;
  }
  if (_getObjectRetType == 2) {
    return _currentValue;
  }
  return DictionaryEntry(_currentKey, _currentValue);
}

Object Hashtable___::HashtableEnumerator___::get_Value() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return _currentValue;
}

void Hashtable___::HashtableEnumerator___::ctor(Hashtable hashtable, Int32 getObjRetType) {
  _hashtable = hashtable;
  _bucket = hashtable->_buckets->get_Length();
  _version = hashtable->_version;
  _current = false;
  _getObjectRetType = getObjRetType;
}

Object Hashtable___::HashtableEnumerator___::Clone() {
  return MemberwiseClone();
}

Boolean Hashtable___::HashtableEnumerator___::MoveNext() {
  if (_version != _hashtable->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  while (_bucket > 0) {
    _bucket--;
    Object key = _hashtable->_buckets[_bucket].key;
    if (key != nullptr && key != _hashtable->_buckets) {
      _currentKey = key;
      _currentValue = _hashtable->_buckets[_bucket].val;
      _current = true;
      return true;
    }
  }
  _current = false;
  return false;
}

void Hashtable___::HashtableEnumerator___::Reset() {
  if (_version != _hashtable->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  _current = false;
  _bucket = _hashtable->_buckets->get_Length();
  _currentKey = nullptr;
  _currentValue = nullptr;
}

Array<KeyValuePairs> Hashtable___::HashtableDebugView___::get_Items() {
  return _hashtable->ToKeyValuePairsArray();
}

void Hashtable___::HashtableDebugView___::ctor(Hashtable hashtable) {
  if (hashtable == nullptr) {
    rt::throw_exception<ArgumentNullException>("hashtable");
  }
  _hashtable = hashtable;
}

IHashCodeProvider Hashtable___::get_hcp() {
  if (rt::is<CompatibleComparer>(_keycomparer)) {
    return ((CompatibleComparer)_keycomparer)->get_HashCodeProvider();
  }
  if (_keycomparer == nullptr) {
    return nullptr;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_CannotMixComparisonInfrastructure());
}

void Hashtable___::set_hcp(IHashCodeProvider value) {
  CompatibleComparer compatibleComparer = rt::as<CompatibleComparer>(_keycomparer);
  if (compatibleComparer != nullptr) {
    _keycomparer = rt::newobj<CompatibleComparer>(value, compatibleComparer->get_Comparer());
    return;
  }
  if (_keycomparer == nullptr) {
    _keycomparer = rt::newobj<CompatibleComparer>(value, nullptr);
    return;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_CannotMixComparisonInfrastructure());
}

IComparer Hashtable___::get_comparer() {
  if (rt::is<CompatibleComparer>(_keycomparer)) {
    return ((CompatibleComparer)_keycomparer)->get_Comparer();
  }
  if (_keycomparer == nullptr) {
    return nullptr;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_CannotMixComparisonInfrastructure());
}

void Hashtable___::set_comparer(IComparer value) {
  CompatibleComparer compatibleComparer = rt::as<CompatibleComparer>(_keycomparer);
  if (compatibleComparer != nullptr) {
    _keycomparer = rt::newobj<CompatibleComparer>(compatibleComparer->get_HashCodeProvider(), value);
    return;
  }
  if (_keycomparer == nullptr) {
    _keycomparer = rt::newobj<CompatibleComparer>(nullptr, value);
    return;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_CannotMixComparisonInfrastructure());
}

IEqualityComparer Hashtable___::get_EqualityComparer() {
  return _keycomparer;
}

Object Hashtable___::get_Item(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  Array<bucket> buckets = _buckets;
  UInt32 seed;
  UInt32 incr;
  UInt32 num = InitHash(key, buckets->get_Length(), seed, incr);
  Int32 num2 = 0;
  Int32 num3 = (Int32)(seed % (UInt32)buckets->get_Length());
  bucket bucket;
  do {
    SpinWait spinWait;
    while (true) {
      Int32 version = _version;
      bucket = buckets[num3];
      if (!_isWriterInProgress && version == _version) {
        break;
      }
      spinWait.SpinOnce();
    }
    if (bucket.key == nullptr) {
      return nullptr;
    }
    if ((bucket.hash_coll & 2147483647) == num && KeyEquals(bucket.key, key)) {
      return bucket.val;
    }
    num3 = (Int32)((num3 + incr) % (Int64)(UInt32)buckets->get_Length());
  } while (bucket.hash_coll < 0 && ++num2 < buckets->get_Length());
  return nullptr;
}

void Hashtable___::set_Item(Object key, Object value) {
  Insert(key, value, false);
}

Boolean Hashtable___::get_IsReadOnly() {
  return false;
}

Boolean Hashtable___::get_IsFixedSize() {
  return false;
}

Boolean Hashtable___::get_IsSynchronized() {
  return false;
}

ICollection Hashtable___::get_Keys() {
  ICollection as = _keys;
  return as != nullptr ? as : (_keys = rt::newobj<KeyCollection>((Hashtable)this));
}

ICollection Hashtable___::get_Values() {
  ICollection as = _values;
  return as != nullptr ? as : (_values = rt::newobj<ValueCollection>((Hashtable)this));
}

Object Hashtable___::get_SyncRoot() {
  return (Hashtable)this;
}

Int32 Hashtable___::get_Count() {
  return _count;
}

void Hashtable___::ctor(Boolean trash) {
}

void Hashtable___::ctor() {
}

void Hashtable___::ctor(Int32 capacity) {
}

void Hashtable___::ctor(Int32 capacity, Single loadFactor) {
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (!(loadFactor >= 0.1) || !(loadFactor <= 1)) {
    rt::throw_exception<ArgumentOutOfRangeException>("loadFactor", SR::Format(SR::get_ArgumentOutOfRange_HashtableLoadFactor(), 0.1, 1));
  }
  _loadFactor = 0.72 * loadFactor;
  Double num = (Single)capacity / _loadFactor;
  if (num > 2147483647) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_HTCapacityOverflow(), "capacity");
  }
  Int32 num2 = ((num > 3) ? HashHelpers::GetPrime((Int32)num) : 3);
  _buckets = rt::newarr<Array<bucket>>(num2);
  _loadsize = (Int32)(_loadFactor * (Single)num2);
  _isWriterInProgress = false;
}

void Hashtable___::ctor(Int32 capacity, Single loadFactor, IEqualityComparer equalityComparer) {
  _keycomparer = equalityComparer;
}

void Hashtable___::ctor(IHashCodeProvider hcp, IComparer comparer) {
}

void Hashtable___::ctor(IEqualityComparer equalityComparer) {
}

void Hashtable___::ctor(Int32 capacity, IHashCodeProvider hcp, IComparer comparer) {
}

void Hashtable___::ctor(Int32 capacity, IEqualityComparer equalityComparer) {
}

void Hashtable___::ctor(IDictionary d) {
}

void Hashtable___::ctor(IDictionary d, Single loadFactor) {
}

void Hashtable___::ctor(IDictionary d, IHashCodeProvider hcp, IComparer comparer) {
}

void Hashtable___::ctor(IDictionary d, IEqualityComparer equalityComparer) {
}

void Hashtable___::ctor(Int32 capacity, Single loadFactor, IHashCodeProvider hcp, IComparer comparer) {
  if (hcp != nullptr || comparer != nullptr) {
    _keycomparer = rt::newobj<CompatibleComparer>(hcp, comparer);
  }
}

void Hashtable___::ctor(IDictionary d, Single loadFactor, IHashCodeProvider hcp, IComparer comparer) {
  if (d == nullptr) {
    rt::throw_exception<ArgumentNullException>("d", SR::get_ArgumentNull_Dictionary());
  }
  IDictionaryEnumerator enumerator = d->GetEnumerator();
  while (enumerator->MoveNext()) {
    Add(enumerator->get_Key(), enumerator->get_Value());
  }
}

void Hashtable___::ctor(IDictionary d, Single loadFactor, IEqualityComparer equalityComparer) {
  if (d == nullptr) {
    rt::throw_exception<ArgumentNullException>("d", SR::get_ArgumentNull_Dictionary());
  }
  IDictionaryEnumerator enumerator = d->GetEnumerator();
  while (enumerator->MoveNext()) {
    Add(enumerator->get_Key(), enumerator->get_Value());
  }
}

void Hashtable___::ctor(SerializationInfo info, StreamingContext context) {
  HashHelpers::get_SerializationInfoTable()->Add((Hashtable)this, info);
}

UInt32 Hashtable___::InitHash(Object key, Int32 hashsize, UInt32& seed, UInt32& incr) {
  UInt32 result = (seed = (UInt32)GetHash(key) & 2147483647u);
  incr = 1 + seed * 101 % (UInt32)(hashsize - 1);
  return result;
}

void Hashtable___::Add(Object key, Object value) {
  Insert(key, value, true);
}

void Hashtable___::Clear() {
  if (_count != 0 || _occupancy != 0) {
    _isWriterInProgress = true;
    for (Int32 i = 0; i < _buckets->get_Length(); i++) {
      _buckets[i].hash_coll = 0;
      _buckets[i].key = nullptr;
      _buckets[i].val = nullptr;
    }
    _count = 0;
    _occupancy = 0;
    UpdateVersion();
    _isWriterInProgress = false;
  }
}

Object Hashtable___::Clone() {
  Array<bucket> buckets = _buckets;
  Hashtable hashtable = rt::newobj<Hashtable>(_count, _keycomparer);
  hashtable->_version = _version;
  hashtable->_loadFactor = _loadFactor;
  hashtable->_count = 0;
  Int32 num = buckets->get_Length();
  while (num > 0) {
    num--;
    Object key = buckets[num].key;
    if (key != nullptr && key != buckets) {
      hashtable[key] = buckets[num].val;
    }
  }
  return hashtable;
}

Boolean Hashtable___::Contains(Object key) {
  return ContainsKey(key);
}

Boolean Hashtable___::ContainsKey(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  Array<bucket> buckets = _buckets;
  UInt32 seed;
  UInt32 incr;
  UInt32 num = InitHash(key, buckets->get_Length(), seed, incr);
  Int32 num2 = 0;
  Int32 num3 = (Int32)(seed % (UInt32)buckets->get_Length());
  bucket bucket;
  do {
    bucket = buckets[num3];
    if (bucket.key == nullptr) {
      return false;
    }
    if ((bucket.hash_coll & 2147483647) == num && KeyEquals(bucket.key, key)) {
      return true;
    }
    num3 = (Int32)((num3 + incr) % (Int64)(UInt32)buckets->get_Length());
  } while (bucket.hash_coll < 0 && ++num2 < buckets->get_Length());
  return false;
}

Boolean Hashtable___::ContainsValue(Object value) {
  if (value == nullptr) {
    Int32 num = _buckets->get_Length();
    while (--num >= 0) {
      if (_buckets[num].key != nullptr && _buckets[num].key != _buckets && _buckets[num].val == nullptr) {
        return true;
      }
    }
  } else {
    Int32 num2 = _buckets->get_Length();
    while (--num2 >= 0) {
      Object val = _buckets[num2].val;
      if (val != nullptr && val->Equals(value)) {
        return true;
      }
    }
  }
  return false;
}

void Hashtable___::CopyKeys(Array<> array, Int32 arrayIndex) {
  Array<bucket> buckets = _buckets;
  Int32 num = buckets->get_Length();
  while (--num >= 0) {
    Object key = buckets[num].key;
    if (key != nullptr && key != _buckets) {
      array->SetValue(key, arrayIndex++);
    }
  }
}

void Hashtable___::CopyEntries(Array<> array, Int32 arrayIndex) {
  Array<bucket> buckets = _buckets;
  Int32 num = buckets->get_Length();
  while (--num >= 0) {
    Object key = buckets[num].key;
    if (key != nullptr && key != _buckets) {
      DictionaryEntry dictionaryEntry = DictionaryEntry(key, buckets[num].val);
      array->SetValue(dictionaryEntry, arrayIndex++);
    }
  }
}

void Hashtable___::CopyTo(Array<> array, Int32 arrayIndex) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array", SR::get_ArgumentNull_Array());
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  if (arrayIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("arrayIndex", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - arrayIndex < get_Count()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayPlusOffTooSmall());
  }
  CopyEntries(array, arrayIndex);
}

Array<KeyValuePairs> Hashtable___::ToKeyValuePairsArray() {
  Array<KeyValuePairs> array = rt::newarr<Array<KeyValuePairs>>(_count);
  Int32 num = 0;
  Array<bucket> buckets = _buckets;
  Int32 num2 = buckets->get_Length();
  while (--num2 >= 0) {
    Object key = buckets[num2].key;
    if (key != nullptr && key != _buckets) {
      array[num++] = rt::newobj<KeyValuePairs>(key, buckets[num2].val);
    }
  }
  return array;
}

void Hashtable___::CopyValues(Array<> array, Int32 arrayIndex) {
  Array<bucket> buckets = _buckets;
  Int32 num = buckets->get_Length();
  while (--num >= 0) {
    Object key = buckets[num].key;
    if (key != nullptr && key != _buckets) {
      array->SetValue(buckets[num].val, arrayIndex++);
    }
  }
}

void Hashtable___::expand() {
  Int32 newsize = HashHelpers::ExpandPrime(_buckets->get_Length());
  rehash(newsize);
}

void Hashtable___::rehash() {
  rehash(_buckets->get_Length());
}

void Hashtable___::UpdateVersion() {
  _version++;
}

void Hashtable___::rehash(Int32 newsize) {
  _occupancy = 0;
  Array<bucket> array = rt::newarr<Array<bucket>>(newsize);
  for (Int32 i = 0; i < _buckets->get_Length(); i++) {
    bucket bucket = _buckets[i];
    if (bucket.key != nullptr && bucket.key != _buckets) {
      Int32 hashcode = bucket.hash_coll & 2147483647;
      putEntry(array, bucket.key, bucket.val, hashcode);
    }
  }
  _isWriterInProgress = true;
  _buckets = array;
  _loadsize = (Int32)(_loadFactor * (Single)newsize);
  UpdateVersion();
  _isWriterInProgress = false;
}

IEnumerator Hashtable___::GetEnumeratorOfIEnumerable() {
  return rt::newobj<HashtableEnumerator>((Hashtable)this, 3);
}

IDictionaryEnumerator Hashtable___::GetEnumerator() {
  return rt::newobj<HashtableEnumerator>((Hashtable)this, 3);
}

Int32 Hashtable___::GetHash(Object key) {
  if (_keycomparer != nullptr) {
    return _keycomparer->GetHashCode(key);
  }
  return key->GetHashCode();
}

Boolean Hashtable___::KeyEquals(Object item, Object key) {
  if (_buckets == item) {
    return false;
  }
  if (item == key) {
    return true;
  }
  if (_keycomparer != nullptr) {
    return _keycomparer->Equals(item, key);
  }
  if (item != nullptr) {
    return item->Equals(key);
  }
  return false;
}

void Hashtable___::Insert(Object key, Object nvalue, Boolean add) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  if (_count >= _loadsize) {
    expand();
  } else if (_occupancy > _loadsize && _count > 100) {
    rehash();
  }

  UInt32 seed;
  UInt32 incr;
  UInt32 num = InitHash(key, _buckets->get_Length(), seed, incr);
  Int32 num2 = 0;
  Int32 num3 = -1;
  Int32 num4 = (Int32)(seed % (UInt32)_buckets->get_Length());
  do {
    if (num3 == -1 && _buckets[num4].key == _buckets && _buckets[num4].hash_coll < 0) {
      num3 = num4;
    }
    if (_buckets[num4].key == nullptr || (_buckets[num4].key == _buckets && (_buckets[num4].hash_coll & 2147483648u) == 0)) {
      if (num3 != -1) {
        num4 = num3;
      }
      _isWriterInProgress = true;
      _buckets[num4].val = nvalue;
      _buckets[num4].key = key;
      _buckets[num4].hash_coll |= (Int32)num;
      _count++;
      UpdateVersion();
      _isWriterInProgress = false;
      return;
    }
    if ((_buckets[num4].hash_coll & 2147483647) == num && KeyEquals(_buckets[num4].key, key)) {
      if (add) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AddingDuplicate__(), _buckets[num4].key, key));
      }
      _isWriterInProgress = true;
      _buckets[num4].val = nvalue;
      UpdateVersion();
      _isWriterInProgress = false;
      return;
    }
    if (num3 == -1 && _buckets[num4].hash_coll >= 0) {
      _buckets[num4].hash_coll |= Int32::MinValue();
      _occupancy++;
    }
    num4 = (Int32)((num4 + incr) % (Int64)(UInt32)_buckets->get_Length());
  } while (++num2 < _buckets->get_Length());
  if (num3 != -1) {
    _isWriterInProgress = true;
    _buckets[num3].val = nvalue;
    _buckets[num3].key = key;
    _buckets[num3].hash_coll |= (Int32)num;
    _count++;
    UpdateVersion();
    _isWriterInProgress = false;
    return;
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_HashInsertFailed());
}

void Hashtable___::putEntry(Array<bucket> newBuckets, Object key, Object nvalue, Int32 hashcode) {
  UInt32 num = 1 + (UInt32)(hashcode * 101) % (UInt32)(newBuckets->get_Length() - 1);
  Int32 num2 = (Int32)((UInt32)hashcode % (UInt32)newBuckets->get_Length());
  while (newBuckets[num2].key != nullptr && newBuckets[num2].key != _buckets) {
    if (newBuckets[num2].hash_coll >= 0) {
      newBuckets[num2].hash_coll |= Int32::MinValue();
      _occupancy++;
    }
    num2 = (Int32)((num2 + num) % (Int64)(UInt32)newBuckets->get_Length());
  }
  newBuckets[num2].val = nvalue;
  newBuckets[num2].key = key;
  newBuckets[num2].hash_coll |= hashcode;
}

void Hashtable___::Remove(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  UInt32 seed;
  UInt32 incr;
  UInt32 num = InitHash(key, _buckets->get_Length(), seed, incr);
  Int32 num2 = 0;
  Int32 num3 = (Int32)(seed % (UInt32)_buckets->get_Length());
  bucket bucket;
  do {
    bucket = _buckets[num3];
    if ((bucket.hash_coll & 2147483647) == num && KeyEquals(bucket.key, key)) {
      _isWriterInProgress = true;
      _buckets[num3].hash_coll &= Int32::MinValue();
      if (_buckets[num3].hash_coll != 0) {
        _buckets[num3].key = _buckets;
      } else {
        _buckets[num3].key = nullptr;
      }
      _buckets[num3].val = nullptr;
      _count--;
      UpdateVersion();
      _isWriterInProgress = false;
      break;
    }
    num3 = (Int32)((num3 + incr) % (Int64)(UInt32)_buckets->get_Length());
  } while (bucket.hash_coll < 0 && ++num2 < _buckets->get_Length());
}

Hashtable Hashtable___::Synchronized(Hashtable table) {
  if (table == nullptr) {
    rt::throw_exception<ArgumentNullException>("table");
  }
  return rt::newobj<SyncHashtable>(table);
}

void Hashtable___::GetObjectData(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  {
    rt::lock(get_SyncRoot());
    Int32 version = _version;
    info->AddValue("LoadFactor", _loadFactor);
    info->AddValue("Version", _version);
    IEqualityComparer keycomparer = _keycomparer;
    if (keycomparer == nullptr) {
      info->AddValue("Comparer", nullptr, typeof<IComparer>());
      info->AddValue("HashCodeProvider", nullptr, typeof<IHashCodeProvider>());
    } else if (rt::is<CompatibleComparer>(keycomparer)) {
      CompatibleComparer compatibleComparer = rt::as<CompatibleComparer>(keycomparer);
      info->AddValue("Comparer", compatibleComparer->get_Comparer(), typeof<IComparer>());
      info->AddValue("HashCodeProvider", compatibleComparer->get_HashCodeProvider(), typeof<IHashCodeProvider>());
    } else {
      info->AddValue("KeyComparer", keycomparer, typeof<IEqualityComparer>());
    }

    info->AddValue("HashSize", _buckets->get_Length());
    Array<Object> array = rt::newarr<Array<Object>>(_count);
    Array<Object> array2 = rt::newarr<Array<Object>>(_count);
    CopyKeys(array, 0);
    CopyValues(array2, 0);
    info->AddValue("Keys", array, typeof<Array<Object>>());
    info->AddValue("Values", array2, typeof<Array<Object>>());
    if (_version != version) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
    }
  }
}

void Hashtable___::OnDeserialization(Object sender) {
  if (_buckets != nullptr) {
    return;
  }
  SerializationInfo value;
  HashHelpers::get_SerializationInfoTable()->TryGetValue((Hashtable)this, value);
  if (value == nullptr) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidOnDeser());
  }
  Int32 num = 0;
  IComparer comparer = nullptr;
  IHashCodeProvider hashCodeProvider = nullptr;
  Array<Object> array = nullptr;
  Array<Object> array2 = nullptr;
  SerializationInfoEnumerator enumerator = value->GetEnumerator();
  while (enumerator->MoveNext()) {
    String name = enumerator->get_Name();
    switch (<PrivateImplementationDetails>::in::ComputeStringHash(name).get()) {
      case 3483216242u:
        if (name == "LoadFactor") {
          _loadFactor = value->GetSingle("LoadFactor");
        }
        break;
      case 3356145248u:
        if (name == "HashSize") {
          num = value->GetInt32("HashSize");
        }
        break;
      case 1228509323u:
        if (name == "KeyComparer") {
          _keycomparer = (IEqualityComparer)value->GetValue("KeyComparer", typeof<IEqualityComparer>());
        }
        break;
      case 891156946u:
        if (name == "Comparer") {
          comparer = (IComparer)value->GetValue("Comparer", typeof<IComparer>());
        }
        break;
      case 2484309429u:
        if (name == "HashCodeProvider") {
          hashCodeProvider = (IHashCodeProvider)value->GetValue("HashCodeProvider", typeof<IHashCodeProvider>());
        }
        break;
      case 1613443821u:
        if (name == "Keys") {
          array = (Array<Object>)value->GetValue("Keys", typeof<Array<Object>>());
        }
        break;
      case 2370642523u:
        if (name == "Values") {
          array2 = (Array<Object>)value->GetValue("Values", typeof<Array<Object>>());
        }
        break;
    }
  }
  _loadsize = (Int32)(_loadFactor * (Single)num);
  if (_keycomparer == nullptr && (comparer != nullptr || hashCodeProvider != nullptr)) {
    _keycomparer = rt::newobj<CompatibleComparer>(hashCodeProvider, comparer);
  }
  _buckets = rt::newarr<Array<bucket>>(num);
  if (array == nullptr) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_MissingKeys());
  }
  if (array2 == nullptr) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_MissingValues());
  }
  if (array->get_Length() != array2->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_KeyValueDifferentSizes());
  }
  for (Int32 i = 0; i < array->get_Length(); i++) {
    if (array[i] == nullptr) {
      rt::throw_exception<SerializationException>(SR::get_Serialization_NullKey());
    }
    Insert(array[i], array2[i], true);
  }
  _version = value->GetInt32("Version");
  HashHelpers::get_SerializationInfoTable()->Remove((Hashtable)this);
}

} // namespace System::Private::CoreLib::System::Collections::HashtableNamespace
