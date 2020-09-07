#include "ListDictionaryInternal-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/ListDictionaryInternal-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Collections::ListDictionaryInternalNamespace {
void ListDictionaryInternal___::DictionaryNode___::ctor() {
}

Object ListDictionaryInternal___::NodeEnumerator___::get_Current() {
  return get_Entry();
}

DictionaryEntry ListDictionaryInternal___::NodeEnumerator___::get_Entry() {
  if (current == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return DictionaryEntry(current->key, current->value);
}

Object ListDictionaryInternal___::NodeEnumerator___::get_Key() {
  if (current == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return current->key;
}

Object ListDictionaryInternal___::NodeEnumerator___::get_Value() {
  if (current == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return current->value;
}

void ListDictionaryInternal___::NodeEnumerator___::ctor(ListDictionaryInternal list) {
  this->list = list;
  version = list->version;
  start = true;
  current = nullptr;
}

Boolean ListDictionaryInternal___::NodeEnumerator___::MoveNext() {
  if (version != list->version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  if (start) {
    current = list->head;
    start = false;
  } else if (current != nullptr) {
    current = current->next;
  }

  return current != nullptr;
}

void ListDictionaryInternal___::NodeEnumerator___::Reset() {
  if (version != list->version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  start = true;
  current = nullptr;
}

Object ListDictionaryInternal___::NodeKeyValueCollection___::NodeKeyValueEnumerator___::get_Current() {
  if (current == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  if (!isKeys) {
    return current->value;
  }
  return current->key;
}

void ListDictionaryInternal___::NodeKeyValueCollection___::NodeKeyValueEnumerator___::ctor(ListDictionaryInternal list, Boolean isKeys) {
  this->list = list;
  this->isKeys = isKeys;
  version = list->version;
  start = true;
  current = nullptr;
}

Boolean ListDictionaryInternal___::NodeKeyValueCollection___::NodeKeyValueEnumerator___::MoveNext() {
  if (version != list->version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  if (start) {
    current = list->head;
    start = false;
  } else if (current != nullptr) {
    current = current->next;
  }

  return current != nullptr;
}

void ListDictionaryInternal___::NodeKeyValueCollection___::NodeKeyValueEnumerator___::Reset() {
  if (version != list->version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  start = true;
  current = nullptr;
}

Int32 ListDictionaryInternal___::NodeKeyValueCollection___::get_CountOfICollection() {
  Int32 num = 0;
  for (DictionaryNode dictionaryNode = list->head; dictionaryNode != nullptr; dictionaryNode = dictionaryNode->next) {
    num++;
  }
  return num;
}

Boolean ListDictionaryInternal___::NodeKeyValueCollection___::get_IsSynchronizedOfICollection() {
  return false;
}

Object ListDictionaryInternal___::NodeKeyValueCollection___::get_SyncRootOfICollection() {
  return list->get_SyncRoot();
}

void ListDictionaryInternal___::NodeKeyValueCollection___::ctor(ListDictionaryInternal list, Boolean isKeys) {
  this->list = list;
  this->isKeys = isKeys;
}

void ListDictionaryInternal___::NodeKeyValueCollection___::CopyToOfICollection(Array<> array, Int32 index) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - index < list->get_Count()) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_Index(), "index");
  }
  for (DictionaryNode dictionaryNode = list->head; dictionaryNode != nullptr; dictionaryNode = dictionaryNode->next) {
    array->SetValue(isKeys ? dictionaryNode->key : dictionaryNode->value, index);
    index++;
  }
}

IEnumerator ListDictionaryInternal___::NodeKeyValueCollection___::GetEnumeratorOfIEnumerable() {
  return rt::newobj<NodeKeyValueEnumerator>(list, isKeys);
}

Object ListDictionaryInternal___::get_Item(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  for (DictionaryNode next = head; next != nullptr; next = next->next) {
    if (next->key->Equals(key)) {
      return next->value;
    }
  }
  return nullptr;
}

void ListDictionaryInternal___::set_Item(Object key, Object value) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  version++;
  DictionaryNode dictionaryNode = nullptr;
  DictionaryNode next = head;
  while (next != nullptr && !next->key->Equals(key)) {
    dictionaryNode = next;
    next = next->next;
  }
  if (next != nullptr) {
    next->value = value;
    return;
  }
  DictionaryNode dictionaryNode2 = rt::newobj<DictionaryNode>();
  dictionaryNode2->key = key;
  dictionaryNode2->value = value;
  if (dictionaryNode != nullptr) {
    dictionaryNode->next = dictionaryNode2;
  } else {
    head = dictionaryNode2;
  }
  count++;
}

Int32 ListDictionaryInternal___::get_Count() {
  return count;
}

ICollection ListDictionaryInternal___::get_Keys() {
  return rt::newobj<NodeKeyValueCollection>((ListDictionaryInternal)this, true);
}

Boolean ListDictionaryInternal___::get_IsReadOnly() {
  return false;
}

Boolean ListDictionaryInternal___::get_IsFixedSize() {
  return false;
}

Boolean ListDictionaryInternal___::get_IsSynchronized() {
  return false;
}

Object ListDictionaryInternal___::get_SyncRoot() {
  return (ListDictionaryInternal)this;
}

ICollection ListDictionaryInternal___::get_Values() {
  return rt::newobj<NodeKeyValueCollection>((ListDictionaryInternal)this, false);
}

void ListDictionaryInternal___::ctor() {
}

void ListDictionaryInternal___::Add(Object key, Object value) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  version++;
  DictionaryNode dictionaryNode = nullptr;
  DictionaryNode next;
  for (next = head; next != nullptr; next = next->next) {
    if (next->key->Equals(key)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AddingDuplicate__(), next->key, key));
    }
    dictionaryNode = next;
  }
  if (next != nullptr) {
    next->value = value;
    return;
  }
  DictionaryNode dictionaryNode2 = rt::newobj<DictionaryNode>();
  dictionaryNode2->key = key;
  dictionaryNode2->value = value;
  if (dictionaryNode != nullptr) {
    dictionaryNode->next = dictionaryNode2;
  } else {
    head = dictionaryNode2;
  }
  count++;
}

void ListDictionaryInternal___::Clear() {
  count = 0;
  head = nullptr;
  version++;
}

Boolean ListDictionaryInternal___::Contains(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  for (DictionaryNode next = head; next != nullptr; next = next->next) {
    if (next->key->Equals(key)) {
      return true;
    }
  }
  return false;
}

void ListDictionaryInternal___::CopyTo(Array<> array, Int32 index) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - index < get_Count()) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_Index(), "index");
  }
  for (DictionaryNode next = head; next != nullptr; next = next->next) {
    array->SetValue(DictionaryEntry(next->key, next->value), index);
    index++;
  }
}

IDictionaryEnumerator ListDictionaryInternal___::GetEnumerator() {
  return rt::newobj<NodeEnumerator>((ListDictionaryInternal)this);
}

IEnumerator ListDictionaryInternal___::GetEnumeratorOfIEnumerable() {
  return rt::newobj<NodeEnumerator>((ListDictionaryInternal)this);
}

void ListDictionaryInternal___::Remove(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  version++;
  DictionaryNode dictionaryNode = nullptr;
  DictionaryNode next = head;
  while (next != nullptr && !next->key->Equals(key)) {
    dictionaryNode = next;
    next = next->next;
  }
  if (next != nullptr) {
    if (next == head) {
      head = next->next;
    } else {
      dictionaryNode->next = next->next;
    }
    count--;
  }
}

} // namespace System::Private::CoreLib::System::Collections::ListDictionaryInternalNamespace
