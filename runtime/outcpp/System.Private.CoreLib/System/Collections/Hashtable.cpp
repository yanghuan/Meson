#include "Hashtable-dep.h"

#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>

namespace System::Private::CoreLib::System::Collections::HashtableNamespace {
Boolean Hashtable___::KeyCollection___::get_IsSynchronized() {
  return Boolean();
};
Object Hashtable___::KeyCollection___::get_SyncRoot() {
  return nullptr;
};
Int32 Hashtable___::KeyCollection___::get_Count() {
  return Int32();
};
void Hashtable___::KeyCollection___::CopyTo(Array<> array, Int32 arrayIndex) {
  return void();
};
IEnumerator Hashtable___::KeyCollection___::GetEnumerator() {
  return nullptr;
};
Boolean Hashtable___::ValueCollection___::get_IsSynchronized() {
  return Boolean();
};
Object Hashtable___::ValueCollection___::get_SyncRoot() {
  return nullptr;
};
Int32 Hashtable___::ValueCollection___::get_Count() {
  return Int32();
};
void Hashtable___::ValueCollection___::CopyTo(Array<> array, Int32 arrayIndex) {
  return void();
};
IEnumerator Hashtable___::ValueCollection___::GetEnumerator() {
  return nullptr;
};
Int32 Hashtable___::SyncHashtable___::get_Count() {
  return Int32();
};
Boolean Hashtable___::SyncHashtable___::get_IsReadOnly() {
  return Boolean();
};
Boolean Hashtable___::SyncHashtable___::get_IsFixedSize() {
  return Boolean();
};
Boolean Hashtable___::SyncHashtable___::get_IsSynchronized() {
  return Boolean();
};
Object Hashtable___::SyncHashtable___::get_Item(Object key) {
  return nullptr;
};
void Hashtable___::SyncHashtable___::set_Item(Object key, Object value) {
  return void();
};
Object Hashtable___::SyncHashtable___::get_SyncRoot() {
  return nullptr;
};
ICollection Hashtable___::SyncHashtable___::get_Keys() {
  return nullptr;
};
ICollection Hashtable___::SyncHashtable___::get_Values() {
  return nullptr;
};
void Hashtable___::SyncHashtable___::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
void Hashtable___::SyncHashtable___::Add(Object key, Object value) {
  return void();
};
void Hashtable___::SyncHashtable___::Clear() {
  return void();
};
Boolean Hashtable___::SyncHashtable___::Contains(Object key) {
  return Boolean();
};
Boolean Hashtable___::SyncHashtable___::ContainsKey(Object key) {
  return Boolean();
};
Boolean Hashtable___::SyncHashtable___::ContainsValue(Object key) {
  return Boolean();
};
void Hashtable___::SyncHashtable___::CopyTo(Array<> array, Int32 arrayIndex) {
  return void();
};
Object Hashtable___::SyncHashtable___::Clone() {
  return nullptr;
};
IDictionaryEnumerator Hashtable___::SyncHashtable___::GetEnumerator() {
  return nullptr;
};
void Hashtable___::SyncHashtable___::Remove(Object key) {
  return void();
};
void Hashtable___::SyncHashtable___::OnDeserialization(Object sender) {
  return void();
};
Array<KeyValuePairs> Hashtable___::SyncHashtable___::ToKeyValuePairsArray() {
  return Array<KeyValuePairs>();
};
Object Hashtable___::HashtableEnumerator___::get_Key() {
  return nullptr;
};
DictionaryEntry Hashtable___::HashtableEnumerator___::get_Entry() {
  return DictionaryEntry();
};
Object Hashtable___::HashtableEnumerator___::get_Current() {
  return nullptr;
};
Object Hashtable___::HashtableEnumerator___::get_Value() {
  return nullptr;
};
Object Hashtable___::HashtableEnumerator___::Clone() {
  return nullptr;
};
Boolean Hashtable___::HashtableEnumerator___::MoveNext() {
  return Boolean();
};
void Hashtable___::HashtableEnumerator___::Reset() {
  return void();
};
Array<KeyValuePairs> Hashtable___::HashtableDebugView___::get_Items() {
  return Array<KeyValuePairs>();
};
IHashCodeProvider Hashtable___::get_hcp() {
  return nullptr;
};
void Hashtable___::set_hcp(IHashCodeProvider value) {
  return void();
};
IComparer Hashtable___::get_comparer() {
  return nullptr;
};
void Hashtable___::set_comparer(IComparer value) {
  return void();
};
IEqualityComparer Hashtable___::get_EqualityComparer() {
  return nullptr;
};
Object Hashtable___::get_Item(Object key) {
  return nullptr;
};
void Hashtable___::set_Item(Object key, Object value) {
  return void();
};
Boolean Hashtable___::get_IsReadOnly() {
  return Boolean();
};
Boolean Hashtable___::get_IsFixedSize() {
  return Boolean();
};
Boolean Hashtable___::get_IsSynchronized() {
  return Boolean();
};
ICollection Hashtable___::get_Keys() {
  return nullptr;
};
ICollection Hashtable___::get_Values() {
  return nullptr;
};
Object Hashtable___::get_SyncRoot() {
  return nullptr;
};
Int32 Hashtable___::get_Count() {
  return Int32();
};
UInt32 Hashtable___::InitHash(Object key, Int32 hashsize, UInt32& seed, UInt32& incr) {
  return UInt32();
};
void Hashtable___::Add(Object key, Object value) {
  return void();
};
void Hashtable___::Clear() {
  return void();
};
Object Hashtable___::Clone() {
  return nullptr;
};
Boolean Hashtable___::Contains(Object key) {
  return Boolean();
};
Boolean Hashtable___::ContainsKey(Object key) {
  return Boolean();
};
Boolean Hashtable___::ContainsValue(Object value) {
  return Boolean();
};
void Hashtable___::CopyKeys(Array<> array, Int32 arrayIndex) {
  return void();
};
void Hashtable___::CopyEntries(Array<> array, Int32 arrayIndex) {
  return void();
};
void Hashtable___::CopyTo(Array<> array, Int32 arrayIndex) {
  return void();
};
Array<KeyValuePairs> Hashtable___::ToKeyValuePairsArray() {
  return Array<KeyValuePairs>();
};
void Hashtable___::CopyValues(Array<> array, Int32 arrayIndex) {
  return void();
};
void Hashtable___::expand() {
  return void();
};
void Hashtable___::rehash() {
  return void();
};
void Hashtable___::UpdateVersion() {
  return void();
};
void Hashtable___::rehash(Int32 newsize) {
  return void();
};
IDictionaryEnumerator Hashtable___::GetEnumerator() {
  return nullptr;
};
Int32 Hashtable___::GetHash(Object key) {
  return Int32();
};
Boolean Hashtable___::KeyEquals(Object item, Object key) {
  return Boolean();
};
void Hashtable___::Insert(Object key, Object nvalue, Boolean add) {
  return void();
};
void Hashtable___::putEntry(Array<bucket> newBuckets, Object key, Object nvalue, Int32 hashcode) {
  return void();
};
void Hashtable___::Remove(Object key) {
  return void();
};
Hashtable Hashtable___::Synchronized(Hashtable table) {
  return nullptr;
};
void Hashtable___::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
void Hashtable___::OnDeserialization(Object sender) {
  return void();
};
} // namespace System::Private::CoreLib::System::Collections::HashtableNamespace
