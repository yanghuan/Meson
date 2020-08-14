#include "DictionaryEntry-dep.h"

namespace System::Private::CoreLib::System::Collections::DictionaryEntryNamespace {
Object DictionaryEntry::get_Key() {
  return _key;
}

void DictionaryEntry::set_Key(Object value) {
  _key = value;
}

Object DictionaryEntry::get_Value() {
  return _value;
}

void DictionaryEntry::set_Value(Object value) {
  _value = value;
}

DictionaryEntry::DictionaryEntry(Object key, Object value) {
  _key = key;
  _value = value;
}

void DictionaryEntry::Deconstruct(Object& key, Object& value) {
  key = get_Key();
  value = get_Value();
}

} // namespace System::Private::CoreLib::System::Collections::DictionaryEntryNamespace
