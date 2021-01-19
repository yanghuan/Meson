#include "ArrayList-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/ArrayList-dep.h>
#include <System.Private.CoreLib/System/Collections/Comparer-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Collections::ArrayListNamespace {
Object IListWrapper___::IListWrapperEnumWrapper___::get_Current() {
  if (_firstCall) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  if (_remaining < 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  return _en->get_Current();
}

void IListWrapper___::IListWrapperEnumWrapper___::ctor(IListWrapper listWrapper, Int32 startIndex, Int32 count) {
  _en = listWrapper->GetEnumerator();
  _initialStartIndex = startIndex;
  _initialCount = count;
  while (startIndex-- > 0 && _en->MoveNext()) {
  }
  _remaining = count;
  _firstCall = true;
}

void IListWrapper___::IListWrapperEnumWrapper___::ctor() {
}

Object IListWrapper___::IListWrapperEnumWrapper___::Clone() {
  IListWrapperEnumWrapper listWrapperEnumWrapper = rt::newobj<IListWrapperEnumWrapper>();
  listWrapperEnumWrapper->_en = (IEnumerator)((ICloneable)_en)->Clone();
  listWrapperEnumWrapper->_initialStartIndex = _initialStartIndex;
  listWrapperEnumWrapper->_initialCount = _initialCount;
  listWrapperEnumWrapper->_remaining = _remaining;
  listWrapperEnumWrapper->_firstCall = _firstCall;
  return listWrapperEnumWrapper;
}

Boolean IListWrapper___::IListWrapperEnumWrapper___::MoveNext() {
  if (_firstCall) {
    _firstCall = false;
    if (_remaining-- > 0) {
      return _en->MoveNext();
    }
    return false;
  }
  if (_remaining < 0) {
    return false;
  }
  if (_en->MoveNext()) {
    return _remaining-- > 0;
  }
  return false;
}

void IListWrapper___::IListWrapperEnumWrapper___::Reset() {
  _en->Reset();
  Int32 initialStartIndex = _initialStartIndex;
  while (initialStartIndex-- > 0 && _en->MoveNext()) {
  }
  _remaining = _initialCount;
  _firstCall = true;
}

Int32 IListWrapper___::get_Capacity() {
  return _list->get_Count();
}

void IListWrapper___::set_Capacity(Int32 value) {
  if (value < get_Count()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
}

Int32 IListWrapper___::get_Count() {
  return _list->get_Count();
}

Boolean IListWrapper___::get_IsReadOnly() {
  return _list->get_IsReadOnly();
}

Boolean IListWrapper___::get_IsFixedSize() {
  return _list->get_IsFixedSize();
}

Boolean IListWrapper___::get_IsSynchronized() {
  return _list->get_IsSynchronized();
}

Object IListWrapper___::get_Item(Int32 index) {
  return _list[index];
}

void IListWrapper___::set_Item(Int32 index, Object value) {
  _list[index] = value;
  _version++;
}

Object IListWrapper___::get_SyncRoot() {
  return _list->get_SyncRoot();
}

void IListWrapper___::ctor(IList list) {
  _list = list;
  _version = 0;
}

Int32 IListWrapper___::Add(Object obj) {
  Int32 result = _list->Add(obj);
  _version++;
  return result;
}

void IListWrapper___::AddRange(ICollection c) {
  InsertRange(get_Count(), c);
}

Int32 IListWrapper___::BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (comparer == nullptr) {
    comparer = Comparer::in::Default;
  }
  Int32 num = index;
  Int32 num2 = index + count - 1;
  while (num <= num2) {
    Int32 num3 = (num + num2) / 2;
    Int32 num4 = comparer->Compare(value, _list[num3]);
    if (num4 == 0) {
      return num3;
    }
    if (num4 < 0) {
      num2 = num3 - 1;
    } else {
      num = num3 + 1;
    }
  }
  return ~num;
}

void IListWrapper___::Clear() {
  if (_list->get_IsFixedSize()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
  }
  _list->Clear();
  _version++;
}

Object IListWrapper___::Clone() {
  return rt::newobj<IListWrapper>(_list);
}

Boolean IListWrapper___::Contains(Object obj) {
  return _list->Contains(obj);
}

void IListWrapper___::CopyTo(Array<> array, Int32 index) {
  _list->CopyTo(array, index);
}

void IListWrapper___::CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (index < 0 || arrayIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "arrayIndex", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - arrayIndex < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  if (_list->get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  for (Int32 i = index; i < index + count; i++) {
    array->SetValue(_list[i], arrayIndex++);
  }
}

IEnumerator IListWrapper___::GetEnumerator() {
  return _list->GetEnumerator();
}

IEnumerator IListWrapper___::GetEnumerator(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_list->get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return rt::newobj<IListWrapperEnumWrapper>((IListWrapper)this, index, count);
}

Int32 IListWrapper___::IndexOf(Object value) {
  return _list->IndexOf(value);
}

Int32 IListWrapper___::IndexOf(Object value, Int32 startIndex) {
  return IndexOf(value, startIndex, _list->get_Count() - startIndex);
}

Int32 IListWrapper___::IndexOf(Object value, Int32 startIndex, Int32 count) {
  if (startIndex < 0 || startIndex > get_Count()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || startIndex > get_Count() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  Int32 num = startIndex + count;
  if (value == nullptr) {
    for (Int32 i = startIndex; i < num; i++) {
      if (_list[i] == nullptr) {
        return i;
      }
    }
    return -1;
  }
  for (Int32 j = startIndex; j < num; j++) {
    if (_list[j] != nullptr && _list[j]->Equals(value)) {
      return j;
    }
  }
  return -1;
}

void IListWrapper___::Insert(Int32 index, Object obj) {
  _list->Insert(index, obj);
  _version++;
}

void IListWrapper___::InsertRange(Int32 index, ICollection c) {
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c", SR::get_ArgumentNull_Collection());
  }
  if (index < 0 || index > get_Count()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (c->get_Count() <= 0) {
    return;
  }
  ArrayList arrayList = rt::as<ArrayList>(_list);
  if (arrayList != nullptr) {
    arrayList->InsertRange(index, c);
  } else {
    IEnumerator enumerator = c->GetEnumerator();
    while (enumerator->MoveNext()) {
      _list->Insert(index++, enumerator->get_Current());
    }
  }
  _version++;
}

Int32 IListWrapper___::LastIndexOf(Object value) {
  return LastIndexOf(value, _list->get_Count() - 1, _list->get_Count());
}

Int32 IListWrapper___::LastIndexOf(Object value, Int32 startIndex) {
  return LastIndexOf(value, startIndex, startIndex + 1);
}

Int32 IListWrapper___::LastIndexOf(Object value, Int32 startIndex, Int32 count) {
  if (_list->get_Count() == 0) {
    return -1;
  }
  if (startIndex < 0 || startIndex >= _list->get_Count()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || count > startIndex + 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  Int32 num = startIndex - count + 1;
  if (value == nullptr) {
    for (Int32 num2 = startIndex; num2 >= num; num2--) {
      if (_list[num2] == nullptr) {
        return num2;
      }
    }
    return -1;
  }
  for (Int32 num3 = startIndex; num3 >= num; num3--) {
    if (_list[num3] != nullptr && _list[num3]->Equals(value)) {
      return num3;
    }
  }
  return -1;
}

void IListWrapper___::Remove(Object value) {
  Int32 num = IndexOf(value);
  if (num >= 0) {
    RemoveAt(num);
  }
}

void IListWrapper___::RemoveAt(Int32 index) {
  _list->RemoveAt(index);
  _version++;
}

void IListWrapper___::RemoveRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_list->get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (count > 0) {
    _version++;
  }
  while (count > 0) {
    _list->RemoveAt(index);
    count--;
  }
}

void IListWrapper___::Reverse(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_list->get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  Int32 num = index;
  Int32 num2 = index + count - 1;
  while (num < num2) {
    Object value = _list[num];
    _list[num++] = _list[num2];
    _list[num2--] = value;
  }
  _version++;
}

void IListWrapper___::SetRange(Int32 index, ICollection c) {
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c", SR::get_ArgumentNull_Collection());
  }
  if (index < 0 || index > _list->get_Count() - c->get_Count()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (c->get_Count() > 0) {
    IEnumerator enumerator = c->GetEnumerator();
    while (enumerator->MoveNext()) {
      _list[index++] = enumerator->get_Current();
    }
    _version++;
  }
}

ArrayList IListWrapper___::GetRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_list->get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return rt::newobj<ArrayList::in::Range>((IListWrapper)this, index, count);
}

void IListWrapper___::Sort(Int32 index, Int32 count, IComparer comparer) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_list->get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  Array<Object> array = rt::newarr<Array<Object>>(count);
  CopyTo(index, array, 0, count);
  Array<>::in::Sort(array, 0, count, comparer);
  for (Int32 i = 0; i < count; i++) {
    _list[i + index] = array[i];
  }
  _version++;
}

Array<Object> IListWrapper___::ToArray() {
  if (get_Count() == 0) {
    return Array<>::in::Empty<Object>();
  }
  Array<Object> array = rt::newarr<Array<Object>>(get_Count());
  _list->CopyTo(array, 0);
  return array;
}

Array<> IListWrapper___::ToArray(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  Array<> array = Array<>::in::CreateInstance(type, _list->get_Count());
  _list->CopyTo(array, 0);
  return array;
}

void IListWrapper___::TrimToSize() {
}

Int32 SyncArrayList___::get_Capacity() {
  {
    rt::lock(_root);
    return _list->get_Capacity();
  }
}

void SyncArrayList___::set_Capacity(Int32 value) {
  {
    rt::lock(_root);
    _list->set_Capacity(value);
  }
}

Int32 SyncArrayList___::get_Count() {
  {
    rt::lock(_root);
    return _list->get_Count();
  }
}

Boolean SyncArrayList___::get_IsReadOnly() {
  return _list->get_IsReadOnly();
}

Boolean SyncArrayList___::get_IsFixedSize() {
  return _list->get_IsFixedSize();
}

Boolean SyncArrayList___::get_IsSynchronized() {
  return true;
}

Object SyncArrayList___::get_Item(Int32 index) {
  {
    rt::lock(_root);
    return _list[index];
  }
}

void SyncArrayList___::set_Item(Int32 index, Object value) {
  {
    rt::lock(_root);
    _list[index] = value;
  }
}

Object SyncArrayList___::get_SyncRoot() {
  return _root;
}

void SyncArrayList___::ctor(ArrayList list) {
  _list = list;
  _root = list->get_SyncRoot();
}

Int32 SyncArrayList___::Add(Object value) {
  {
    rt::lock(_root);
    return _list->Add(value);
  }
}

void SyncArrayList___::AddRange(ICollection c) {
  {
    rt::lock(_root);
    _list->AddRange(c);
  }
}

Int32 SyncArrayList___::BinarySearch(Object value) {
  {
    rt::lock(_root);
    return _list->BinarySearch(value);
  }
}

Int32 SyncArrayList___::BinarySearch(Object value, IComparer comparer) {
  {
    rt::lock(_root);
    return _list->BinarySearch(value, comparer);
  }
}

Int32 SyncArrayList___::BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer) {
  {
    rt::lock(_root);
    return _list->BinarySearch(index, count, value, comparer);
  }
}

void SyncArrayList___::Clear() {
  {
    rt::lock(_root);
    _list->Clear();
  }
}

Object SyncArrayList___::Clone() {
  {
    rt::lock(_root);
    return rt::newobj<SyncArrayList>((ArrayList)_list->Clone());
  }
}

Boolean SyncArrayList___::Contains(Object item) {
  {
    rt::lock(_root);
    return _list->Contains(item);
  }
}

void SyncArrayList___::CopyTo(Array<> array) {
  {
    rt::lock(_root);
    _list->CopyTo(array);
  }
}

void SyncArrayList___::CopyTo(Array<> array, Int32 index) {
  {
    rt::lock(_root);
    _list->CopyTo(array, index);
  }
}

void SyncArrayList___::CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count) {
  {
    rt::lock(_root);
    _list->CopyTo(index, array, arrayIndex, count);
  }
}

IEnumerator SyncArrayList___::GetEnumerator() {
  {
    rt::lock(_root);
    return _list->GetEnumerator();
  }
}

IEnumerator SyncArrayList___::GetEnumerator(Int32 index, Int32 count) {
  {
    rt::lock(_root);
    return _list->GetEnumerator(index, count);
  }
}

Int32 SyncArrayList___::IndexOf(Object value) {
  {
    rt::lock(_root);
    return _list->IndexOf(value);
  }
}

Int32 SyncArrayList___::IndexOf(Object value, Int32 startIndex) {
  {
    rt::lock(_root);
    return _list->IndexOf(value, startIndex);
  }
}

Int32 SyncArrayList___::IndexOf(Object value, Int32 startIndex, Int32 count) {
  {
    rt::lock(_root);
    return _list->IndexOf(value, startIndex, count);
  }
}

void SyncArrayList___::Insert(Int32 index, Object value) {
  {
    rt::lock(_root);
    _list->Insert(index, value);
  }
}

void SyncArrayList___::InsertRange(Int32 index, ICollection c) {
  {
    rt::lock(_root);
    _list->InsertRange(index, c);
  }
}

Int32 SyncArrayList___::LastIndexOf(Object value) {
  {
    rt::lock(_root);
    return _list->LastIndexOf(value);
  }
}

Int32 SyncArrayList___::LastIndexOf(Object value, Int32 startIndex) {
  {
    rt::lock(_root);
    return _list->LastIndexOf(value, startIndex);
  }
}

Int32 SyncArrayList___::LastIndexOf(Object value, Int32 startIndex, Int32 count) {
  {
    rt::lock(_root);
    return _list->LastIndexOf(value, startIndex, count);
  }
}

void SyncArrayList___::Remove(Object value) {
  {
    rt::lock(_root);
    _list->Remove(value);
  }
}

void SyncArrayList___::RemoveAt(Int32 index) {
  {
    rt::lock(_root);
    _list->RemoveAt(index);
  }
}

void SyncArrayList___::RemoveRange(Int32 index, Int32 count) {
  {
    rt::lock(_root);
    _list->RemoveRange(index, count);
  }
}

void SyncArrayList___::Reverse(Int32 index, Int32 count) {
  {
    rt::lock(_root);
    _list->Reverse(index, count);
  }
}

void SyncArrayList___::SetRange(Int32 index, ICollection c) {
  {
    rt::lock(_root);
    _list->SetRange(index, c);
  }
}

ArrayList SyncArrayList___::GetRange(Int32 index, Int32 count) {
  {
    rt::lock(_root);
    return _list->GetRange(index, count);
  }
}

void SyncArrayList___::Sort() {
  {
    rt::lock(_root);
    _list->Sort();
  }
}

void SyncArrayList___::Sort(IComparer comparer) {
  {
    rt::lock(_root);
    _list->Sort(comparer);
  }
}

void SyncArrayList___::Sort(Int32 index, Int32 count, IComparer comparer) {
  {
    rt::lock(_root);
    _list->Sort(index, count, comparer);
  }
}

Array<Object> SyncArrayList___::ToArray() {
  {
    rt::lock(_root);
    return _list->ToArray();
  }
}

Array<> SyncArrayList___::ToArray(Type type) {
  {
    rt::lock(_root);
    return _list->ToArray(type);
  }
}

void SyncArrayList___::TrimToSize() {
  {
    rt::lock(_root);
    _list->TrimToSize();
  }
}

Int32 ArrayList___::SyncIList___::get_Count() {
  {
    rt::lock(_root);
    return _list->get_Count();
  }
}

Boolean ArrayList___::SyncIList___::get_IsReadOnly() {
  return _list->get_IsReadOnly();
}

Boolean ArrayList___::SyncIList___::get_IsFixedSize() {
  return _list->get_IsFixedSize();
}

Boolean ArrayList___::SyncIList___::get_IsSynchronized() {
  return true;
}

Object ArrayList___::SyncIList___::get_Item(Int32 index) {
  {
    rt::lock(_root);
    return _list[index];
  }
}

void ArrayList___::SyncIList___::set_Item(Int32 index, Object value) {
  {
    rt::lock(_root);
    _list[index] = value;
  }
}

Object ArrayList___::SyncIList___::get_SyncRoot() {
  return _root;
}

void ArrayList___::SyncIList___::ctor(IList list) {
  _list = list;
  _root = list->get_SyncRoot();
}

Int32 ArrayList___::SyncIList___::Add(Object value) {
  {
    rt::lock(_root);
    return _list->Add(value);
  }
}

void ArrayList___::SyncIList___::Clear() {
  {
    rt::lock(_root);
    _list->Clear();
  }
}

Boolean ArrayList___::SyncIList___::Contains(Object item) {
  {
    rt::lock(_root);
    return _list->Contains(item);
  }
}

void ArrayList___::SyncIList___::CopyTo(Array<> array, Int32 index) {
  {
    rt::lock(_root);
    _list->CopyTo(array, index);
  }
}

IEnumerator ArrayList___::SyncIList___::GetEnumerator() {
  {
    rt::lock(_root);
    return _list->GetEnumerator();
  }
}

Int32 ArrayList___::SyncIList___::IndexOf(Object value) {
  {
    rt::lock(_root);
    return _list->IndexOf(value);
  }
}

void ArrayList___::SyncIList___::Insert(Int32 index, Object value) {
  {
    rt::lock(_root);
    _list->Insert(index, value);
  }
}

void ArrayList___::SyncIList___::Remove(Object value) {
  {
    rt::lock(_root);
    _list->Remove(value);
  }
}

void ArrayList___::SyncIList___::RemoveAt(Int32 index) {
  {
    rt::lock(_root);
    _list->RemoveAt(index);
  }
}

Int32 ArrayList___::FixedSizeList___::get_Count() {
  return _list->get_Count();
}

Boolean ArrayList___::FixedSizeList___::get_IsReadOnly() {
  return _list->get_IsReadOnly();
}

Boolean ArrayList___::FixedSizeList___::get_IsFixedSize() {
  return true;
}

Boolean ArrayList___::FixedSizeList___::get_IsSynchronized() {
  return _list->get_IsSynchronized();
}

Object ArrayList___::FixedSizeList___::get_Item(Int32 index) {
  return _list[index];
}

void ArrayList___::FixedSizeList___::set_Item(Int32 index, Object value) {
  _list[index] = value;
}

Object ArrayList___::FixedSizeList___::get_SyncRoot() {
  return _list->get_SyncRoot();
}

void ArrayList___::FixedSizeList___::ctor(IList l) {
  _list = l;
}

Int32 ArrayList___::FixedSizeList___::Add(Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void ArrayList___::FixedSizeList___::Clear() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

Boolean ArrayList___::FixedSizeList___::Contains(Object obj) {
  return _list->Contains(obj);
}

void ArrayList___::FixedSizeList___::CopyTo(Array<> array, Int32 index) {
  _list->CopyTo(array, index);
}

IEnumerator ArrayList___::FixedSizeList___::GetEnumerator() {
  return _list->GetEnumerator();
}

Int32 ArrayList___::FixedSizeList___::IndexOf(Object value) {
  return _list->IndexOf(value);
}

void ArrayList___::FixedSizeList___::Insert(Int32 index, Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void ArrayList___::FixedSizeList___::Remove(Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void ArrayList___::FixedSizeList___::RemoveAt(Int32 index) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

Int32 FixedSizeArrayList___::get_Count() {
  return _list->get_Count();
}

Boolean FixedSizeArrayList___::get_IsReadOnly() {
  return _list->get_IsReadOnly();
}

Boolean FixedSizeArrayList___::get_IsFixedSize() {
  return true;
}

Boolean FixedSizeArrayList___::get_IsSynchronized() {
  return _list->get_IsSynchronized();
}

Object FixedSizeArrayList___::get_Item(Int32 index) {
  return _list[index];
}

void FixedSizeArrayList___::set_Item(Int32 index, Object value) {
  _list[index] = value;
  _version = _list->_version;
}

Object FixedSizeArrayList___::get_SyncRoot() {
  return _list->get_SyncRoot();
}

Int32 FixedSizeArrayList___::get_Capacity() {
  return _list->get_Capacity();
}

void FixedSizeArrayList___::set_Capacity(Int32 value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void FixedSizeArrayList___::ctor(ArrayList l) {
  _list = l;
  _version = _list->_version;
}

Int32 FixedSizeArrayList___::Add(Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void FixedSizeArrayList___::AddRange(ICollection c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

Int32 FixedSizeArrayList___::BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer) {
  return _list->BinarySearch(index, count, value, comparer);
}

void FixedSizeArrayList___::Clear() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

Object FixedSizeArrayList___::Clone() {
  FixedSizeArrayList fixedSizeArrayList = rt::newobj<FixedSizeArrayList>(_list);
  fixedSizeArrayList->_list = (ArrayList)_list->Clone();
  return fixedSizeArrayList;
}

Boolean FixedSizeArrayList___::Contains(Object obj) {
  return _list->Contains(obj);
}

void FixedSizeArrayList___::CopyTo(Array<> array, Int32 index) {
  _list->CopyTo(array, index);
}

void FixedSizeArrayList___::CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count) {
  _list->CopyTo(index, array, arrayIndex, count);
}

IEnumerator FixedSizeArrayList___::GetEnumerator() {
  return _list->GetEnumerator();
}

IEnumerator FixedSizeArrayList___::GetEnumerator(Int32 index, Int32 count) {
  return _list->GetEnumerator(index, count);
}

Int32 FixedSizeArrayList___::IndexOf(Object value) {
  return _list->IndexOf(value);
}

Int32 FixedSizeArrayList___::IndexOf(Object value, Int32 startIndex) {
  return _list->IndexOf(value, startIndex);
}

Int32 FixedSizeArrayList___::IndexOf(Object value, Int32 startIndex, Int32 count) {
  return _list->IndexOf(value, startIndex, count);
}

void FixedSizeArrayList___::Insert(Int32 index, Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void FixedSizeArrayList___::InsertRange(Int32 index, ICollection c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

Int32 FixedSizeArrayList___::LastIndexOf(Object value) {
  return _list->LastIndexOf(value);
}

Int32 FixedSizeArrayList___::LastIndexOf(Object value, Int32 startIndex) {
  return _list->LastIndexOf(value, startIndex);
}

Int32 FixedSizeArrayList___::LastIndexOf(Object value, Int32 startIndex, Int32 count) {
  return _list->LastIndexOf(value, startIndex, count);
}

void FixedSizeArrayList___::Remove(Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void FixedSizeArrayList___::RemoveAt(Int32 index) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void FixedSizeArrayList___::RemoveRange(Int32 index, Int32 count) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

void FixedSizeArrayList___::SetRange(Int32 index, ICollection c) {
  _list->SetRange(index, c);
  _version = _list->_version;
}

ArrayList FixedSizeArrayList___::GetRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return rt::newobj<ArrayList::in::Range>((FixedSizeArrayList)this, index, count);
}

void FixedSizeArrayList___::Reverse(Int32 index, Int32 count) {
  _list->Reverse(index, count);
  _version = _list->_version;
}

void FixedSizeArrayList___::Sort(Int32 index, Int32 count, IComparer comparer) {
  _list->Sort(index, count, comparer);
  _version = _list->_version;
}

Array<Object> FixedSizeArrayList___::ToArray() {
  return _list->ToArray();
}

Array<> FixedSizeArrayList___::ToArray(Type type) {
  return _list->ToArray(type);
}

void FixedSizeArrayList___::TrimToSize() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FixedSizeCollection());
}

Int32 ArrayList___::ReadOnlyList___::get_Count() {
  return _list->get_Count();
}

Boolean ArrayList___::ReadOnlyList___::get_IsReadOnly() {
  return true;
}

Boolean ArrayList___::ReadOnlyList___::get_IsFixedSize() {
  return true;
}

Boolean ArrayList___::ReadOnlyList___::get_IsSynchronized() {
  return _list->get_IsSynchronized();
}

Object ArrayList___::ReadOnlyList___::get_Item(Int32 index) {
  return _list[index];
}

void ArrayList___::ReadOnlyList___::set_Item(Int32 index, Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Object ArrayList___::ReadOnlyList___::get_SyncRoot() {
  return _list->get_SyncRoot();
}

void ArrayList___::ReadOnlyList___::ctor(IList l) {
  _list = l;
}

Int32 ArrayList___::ReadOnlyList___::Add(Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ArrayList___::ReadOnlyList___::Clear() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Boolean ArrayList___::ReadOnlyList___::Contains(Object obj) {
  return _list->Contains(obj);
}

void ArrayList___::ReadOnlyList___::CopyTo(Array<> array, Int32 index) {
  _list->CopyTo(array, index);
}

IEnumerator ArrayList___::ReadOnlyList___::GetEnumerator() {
  return _list->GetEnumerator();
}

Int32 ArrayList___::ReadOnlyList___::IndexOf(Object value) {
  return _list->IndexOf(value);
}

void ArrayList___::ReadOnlyList___::Insert(Int32 index, Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ArrayList___::ReadOnlyList___::Remove(Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ArrayList___::ReadOnlyList___::RemoveAt(Int32 index) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Int32 ReadOnlyArrayList___::get_Count() {
  return _list->get_Count();
}

Boolean ReadOnlyArrayList___::get_IsReadOnly() {
  return true;
}

Boolean ReadOnlyArrayList___::get_IsFixedSize() {
  return true;
}

Boolean ReadOnlyArrayList___::get_IsSynchronized() {
  return _list->get_IsSynchronized();
}

Object ReadOnlyArrayList___::get_Item(Int32 index) {
  return _list[index];
}

void ReadOnlyArrayList___::set_Item(Int32 index, Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Object ReadOnlyArrayList___::get_SyncRoot() {
  return _list->get_SyncRoot();
}

Int32 ReadOnlyArrayList___::get_Capacity() {
  return _list->get_Capacity();
}

void ReadOnlyArrayList___::set_Capacity(Int32 value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::ctor(ArrayList l) {
  _list = l;
}

Int32 ReadOnlyArrayList___::Add(Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::AddRange(ICollection c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Int32 ReadOnlyArrayList___::BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer) {
  return _list->BinarySearch(index, count, value, comparer);
}

void ReadOnlyArrayList___::Clear() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Object ReadOnlyArrayList___::Clone() {
  ReadOnlyArrayList readOnlyArrayList = rt::newobj<ReadOnlyArrayList>(_list);
  readOnlyArrayList->_list = (ArrayList)_list->Clone();
  return readOnlyArrayList;
}

Boolean ReadOnlyArrayList___::Contains(Object obj) {
  return _list->Contains(obj);
}

void ReadOnlyArrayList___::CopyTo(Array<> array, Int32 index) {
  _list->CopyTo(array, index);
}

void ReadOnlyArrayList___::CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count) {
  _list->CopyTo(index, array, arrayIndex, count);
}

IEnumerator ReadOnlyArrayList___::GetEnumerator() {
  return _list->GetEnumerator();
}

IEnumerator ReadOnlyArrayList___::GetEnumerator(Int32 index, Int32 count) {
  return _list->GetEnumerator(index, count);
}

Int32 ReadOnlyArrayList___::IndexOf(Object value) {
  return _list->IndexOf(value);
}

Int32 ReadOnlyArrayList___::IndexOf(Object value, Int32 startIndex) {
  return _list->IndexOf(value, startIndex);
}

Int32 ReadOnlyArrayList___::IndexOf(Object value, Int32 startIndex, Int32 count) {
  return _list->IndexOf(value, startIndex, count);
}

void ReadOnlyArrayList___::Insert(Int32 index, Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::InsertRange(Int32 index, ICollection c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Int32 ReadOnlyArrayList___::LastIndexOf(Object value) {
  return _list->LastIndexOf(value);
}

Int32 ReadOnlyArrayList___::LastIndexOf(Object value, Int32 startIndex) {
  return _list->LastIndexOf(value, startIndex);
}

Int32 ReadOnlyArrayList___::LastIndexOf(Object value, Int32 startIndex, Int32 count) {
  return _list->LastIndexOf(value, startIndex, count);
}

void ReadOnlyArrayList___::Remove(Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::RemoveAt(Int32 index) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::RemoveRange(Int32 index, Int32 count) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::SetRange(Int32 index, ICollection c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

ArrayList ReadOnlyArrayList___::GetRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (get_Count() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return rt::newobj<ArrayList::in::Range>((ReadOnlyArrayList)this, index, count);
}

void ReadOnlyArrayList___::Reverse(Int32 index, Int32 count) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

void ReadOnlyArrayList___::Sort(Int32 index, Int32 count, IComparer comparer) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Array<Object> ReadOnlyArrayList___::ToArray() {
  return _list->ToArray();
}

Array<> ReadOnlyArrayList___::ToArray(Type type) {
  return _list->ToArray(type);
}

void ReadOnlyArrayList___::TrimToSize() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ReadOnlyCollection());
}

Object ArrayList___::ArrayListEnumerator___::get_Current() {
  if (_index < _startIndex) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  if (_index > _endIndex) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  return _currentElement;
}

void ArrayList___::ArrayListEnumerator___::ctor(ArrayList list, Int32 index, Int32 count) {
  _list = list;
  _startIndex = index;
  _index = index - 1;
  _endIndex = _index + count;
  _version = list->_version;
  _currentElement = nullptr;
}

Object ArrayList___::ArrayListEnumerator___::Clone() {
  return MemberwiseClone();
}

Boolean ArrayList___::ArrayListEnumerator___::MoveNext() {
  if (_version != _list->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  if (_index < _endIndex) {
    _currentElement = _list[++_index];
    return true;
  }
  _index = _endIndex + 1;
  return false;
}

void ArrayList___::ArrayListEnumerator___::Reset() {
  if (_version != _list->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  _index = _startIndex - 1;
}

Int32 Range___::get_Capacity() {
  return _baseList->get_Capacity();
}

void Range___::set_Capacity(Int32 value) {
  if (value < get_Count()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
}

Int32 Range___::get_Count() {
  InternalUpdateRange();
  return _baseSize;
}

Boolean Range___::get_IsReadOnly() {
  return _baseList->get_IsReadOnly();
}

Boolean Range___::get_IsFixedSize() {
  return _baseList->get_IsFixedSize();
}

Boolean Range___::get_IsSynchronized() {
  return _baseList->get_IsSynchronized();
}

Object Range___::get_SyncRoot() {
  return _baseList->get_SyncRoot();
}

Object Range___::get_Item(Int32 index) {
  InternalUpdateRange();
  if (index < 0 || index >= _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  return _baseList[_baseIndex + index];
}

void Range___::set_Item(Int32 index, Object value) {
  InternalUpdateRange();
  if (index < 0 || index >= _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  _baseList[_baseIndex + index] = value;
  InternalUpdateVersion();
}

void Range___::ctor(ArrayList list, Int32 index, Int32 count) {
  _baseList = list;
  _baseIndex = index;
  _baseSize = count;
  _baseVersion = list->_version;
  _version = list->_version;
}

void Range___::InternalUpdateRange() {
  if (_baseVersion != _baseList->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnderlyingArrayListChanged());
  }
}

void Range___::InternalUpdateVersion() {
  _baseVersion++;
  _version++;
}

Int32 Range___::Add(Object value) {
  InternalUpdateRange();
  _baseList->Insert(_baseIndex + _baseSize, value);
  InternalUpdateVersion();
  return _baseSize++;
}

void Range___::AddRange(ICollection c) {
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c");
  }
  InternalUpdateRange();
  Int32 count = c->get_Count();
  if (count > 0) {
    _baseList->InsertRange(_baseIndex + _baseSize, c);
    InternalUpdateVersion();
    _baseSize += count;
  }
}

Int32 Range___::BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  Int32 num = _baseList->BinarySearch(_baseIndex + index, count, value, comparer);
  if (num >= 0) {
    return num - _baseIndex;
  }
  return num + _baseIndex;
}

void Range___::Clear() {
  InternalUpdateRange();
  if (_baseSize != 0) {
    _baseList->RemoveRange(_baseIndex, _baseSize);
    InternalUpdateVersion();
    _baseSize = 0;
  }
}

Object Range___::Clone() {
  InternalUpdateRange();
  Range range = rt::newobj<Range>(_baseList, _baseIndex, _baseSize);
  range->_baseList = (ArrayList)_baseList->Clone();
  return range;
}

Boolean Range___::Contains(Object item) {
  InternalUpdateRange();
  if (item == nullptr) {
    for (Int32 i = 0; i < _baseSize; i++) {
      if (_baseList[_baseIndex + i] == nullptr) {
        return true;
      }
    }
    return false;
  }
  for (Int32 j = 0; j < _baseSize; j++) {
    if (_baseList[_baseIndex + j] != nullptr && _baseList[_baseIndex + j]->Equals(item)) {
      return true;
    }
  }
  return false;
}

void Range___::CopyTo(Array<> array, Int32 index) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - index < _baseSize) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  _baseList->CopyTo(_baseIndex, array, index, _baseSize);
}

void Range___::CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - arrayIndex < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  _baseList->CopyTo(_baseIndex + index, array, arrayIndex, count);
}

IEnumerator Range___::GetEnumerator() {
  return GetEnumerator(0, _baseSize);
}

IEnumerator Range___::GetEnumerator(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  return _baseList->GetEnumerator(_baseIndex + index, count);
}

ArrayList Range___::GetRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  return rt::newobj<Range>((Range)this, index, count);
}

Int32 Range___::IndexOf(Object value) {
  InternalUpdateRange();
  Int32 num = _baseList->IndexOf(value, _baseIndex, _baseSize);
  if (num >= 0) {
    return num - _baseIndex;
  }
  return -1;
}

Int32 Range___::IndexOf(Object value, Int32 startIndex) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (startIndex > _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  InternalUpdateRange();
  Int32 num = _baseList->IndexOf(value, _baseIndex + startIndex, _baseSize - startIndex);
  if (num >= 0) {
    return num - _baseIndex;
  }
  return -1;
}

Int32 Range___::IndexOf(Object value, Int32 startIndex, Int32 count) {
  if (startIndex < 0 || startIndex > _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || startIndex > _baseSize - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  InternalUpdateRange();
  Int32 num = _baseList->IndexOf(value, _baseIndex + startIndex, count);
  if (num >= 0) {
    return num - _baseIndex;
  }
  return -1;
}

void Range___::Insert(Int32 index, Object value) {
  if (index < 0 || index > _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  InternalUpdateRange();
  _baseList->Insert(_baseIndex + index, value);
  InternalUpdateVersion();
  _baseSize++;
}

void Range___::InsertRange(Int32 index, ICollection c) {
  if (index < 0 || index > _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c");
  }
  InternalUpdateRange();
  Int32 count = c->get_Count();
  if (count > 0) {
    _baseList->InsertRange(_baseIndex + index, c);
    _baseSize += count;
    InternalUpdateVersion();
  }
}

Int32 Range___::LastIndexOf(Object value) {
  InternalUpdateRange();
  Int32 num = _baseList->LastIndexOf(value, _baseIndex + _baseSize - 1, _baseSize);
  if (num >= 0) {
    return num - _baseIndex;
  }
  return -1;
}

Int32 Range___::LastIndexOf(Object value, Int32 startIndex) {
  return LastIndexOf(value, startIndex, startIndex + 1);
}

Int32 Range___::LastIndexOf(Object value, Int32 startIndex, Int32 count) {
  InternalUpdateRange();
  if (_baseSize == 0) {
    return -1;
  }
  if (startIndex >= _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 num = _baseList->LastIndexOf(value, _baseIndex + startIndex, count);
  if (num >= 0) {
    return num - _baseIndex;
  }
  return -1;
}

void Range___::RemoveAt(Int32 index) {
  if (index < 0 || index >= _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  InternalUpdateRange();
  _baseList->RemoveAt(_baseIndex + index);
  InternalUpdateVersion();
  _baseSize--;
}

void Range___::RemoveRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  if (count > 0) {
    _baseList->RemoveRange(_baseIndex + index, count);
    InternalUpdateVersion();
    _baseSize -= count;
  }
}

void Range___::Reverse(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  _baseList->Reverse(_baseIndex + index, count);
  InternalUpdateVersion();
}

void Range___::SetRange(Int32 index, ICollection c) {
  InternalUpdateRange();
  if (index < 0 || index >= _baseSize) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  _baseList->SetRange(_baseIndex + index, c);
  if (c->get_Count() > 0) {
    InternalUpdateVersion();
  }
}

void Range___::Sort(Int32 index, Int32 count, IComparer comparer) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_baseSize - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  InternalUpdateRange();
  _baseList->Sort(_baseIndex + index, count, comparer);
  InternalUpdateVersion();
}

Array<Object> Range___::ToArray() {
  InternalUpdateRange();
  if (_baseSize == 0) {
    return Array<>::in::Empty<Object>();
  }
  Array<Object> array = rt::newarr<Array<Object>>(_baseSize);
  Array<>::in::Copy(_baseList->_items, _baseIndex, array, 0, _baseSize);
  return array;
}

Array<> Range___::ToArray(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  InternalUpdateRange();
  Array<> array = Array<>::in::CreateInstance(type, _baseSize);
  _baseList->CopyTo(_baseIndex, array, 0, _baseSize);
  return array;
}

void Range___::TrimToSize() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_RangeCollection());
}

Object ArrayList___::ArrayListEnumeratorSimple___::get_Current() {
  Object currentElement = _currentElement;
  if (s_dummyObject == currentElement) {
    if (_index == -1) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
    }
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  return currentElement;
}

void ArrayList___::ArrayListEnumeratorSimple___::ctor(ArrayList list) {
  _list = list;
  _index = -1;
  _version = list->_version;
  _isArrayList = list->GetType() == typeof<ArrayList>();
  _currentElement = s_dummyObject;
}

Object ArrayList___::ArrayListEnumeratorSimple___::Clone() {
  return MemberwiseClone();
}

Boolean ArrayList___::ArrayListEnumeratorSimple___::MoveNext() {
  if (_version != _list->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  if (_isArrayList) {
    if (_index < _list->_size - 1) {
      _currentElement = _list->_items[++_index];
      return true;
    }
    _currentElement = s_dummyObject;
    _index = _list->_size;
    return false;
  }
  if (_index < _list->get_Count() - 1) {
    _currentElement = _list[++_index];
    return true;
  }
  _index = _list->get_Count();
  _currentElement = s_dummyObject;
  return false;
}

void ArrayList___::ArrayListEnumeratorSimple___::Reset() {
  if (_version != _list->_version) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
  }
  _currentElement = s_dummyObject;
  _index = -1;
}

void ArrayList___::ArrayListEnumeratorSimple___::cctor() {
  s_dummyObject = rt::newobj<Object>();
}

Array<Object> ArrayList___::ArrayListDebugView___::get_Items() {
  return _arrayList->ToArray();
}

void ArrayList___::ArrayListDebugView___::ctor(ArrayList arrayList) {
  if (arrayList == nullptr) {
    rt::throw_exception<ArgumentNullException>("arrayList");
  }
  _arrayList = arrayList;
}

Int32 ArrayList___::get_Capacity() {
  return _items->get_Length();
}

void ArrayList___::set_Capacity(Int32 value) {
  if (value < _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
  if (value == _items->get_Length()) {
    return;
  }
  if (value > 0) {
    Array<Object> array = rt::newarr<Array<Object>>(value);
    if (_size > 0) {
      Array<>::in::Copy(_items, array, _size);
    }
    _items = array;
  } else {
    _items = rt::newarr<Array<Object>>(4);
  }
}

Int32 ArrayList___::get_Count() {
  return _size;
}

Boolean ArrayList___::get_IsFixedSize() {
  return false;
}

Boolean ArrayList___::get_IsReadOnly() {
  return false;
}

Boolean ArrayList___::get_IsSynchronized() {
  return false;
}

Object ArrayList___::get_SyncRoot() {
  return (ArrayList)this;
}

Object ArrayList___::get_Item(Int32 index) {
  if (index < 0 || index >= _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  return _items[index];
}

void ArrayList___::set_Item(Int32 index, Object value) {
  if (index < 0 || index >= _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  _items[index] = value;
  _version++;
}

void ArrayList___::ctor() {
  _items = Array<>::in::Empty<Object>();
}

void ArrayList___::ctor(Int32 capacity) {
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::Format(SR::get_ArgumentOutOfRange_MustBeNonNegNum(), "capacity"));
  }
  if (capacity == 0) {
    _items = Array<>::in::Empty<Object>();
  } else {
    _items = rt::newarr<Array<Object>>(capacity);
  }
}

void ArrayList___::ctor(ICollection c) {
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c", SR::get_ArgumentNull_Collection());
  }
  Int32 count = c->get_Count();
  if (count == 0) {
    _items = Array<>::in::Empty<Object>();
    return;
  }
  _items = rt::newarr<Array<Object>>(count);
  AddRange(c);
}

ArrayList ArrayList___::Adapter(IList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<IListWrapper>(list);
}

Int32 ArrayList___::Add(Object value) {
  if (_size == _items->get_Length()) {
    EnsureCapacity(_size + 1);
  }
  _items[_size] = value;
  _version++;
  return _size++;
}

void ArrayList___::AddRange(ICollection c) {
  InsertRange(_size, c);
}

Int32 ArrayList___::BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer) {
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Array<>::in::BinarySearch(_items, index, count, value, comparer);
}

Int32 ArrayList___::BinarySearch(Object value) {
  return BinarySearch(0, get_Count(), value, nullptr);
}

Int32 ArrayList___::BinarySearch(Object value, IComparer comparer) {
  return BinarySearch(0, get_Count(), value, comparer);
}

void ArrayList___::Clear() {
  if (_size > 0) {
    Array<>::in::Clear(_items, 0, _size);
    _size = 0;
  }
  _version++;
}

Object ArrayList___::Clone() {
  ArrayList arrayList = rt::newobj<ArrayList>(_size);
  arrayList->_size = _size;
  arrayList->_version = _version;
  Array<>::in::Copy(_items, arrayList->_items, _size);
  return arrayList;
}

Boolean ArrayList___::Contains(Object item) {
  if (item == nullptr) {
    for (Int32 i = 0; i < _size; i++) {
      if (_items[i] == nullptr) {
        return true;
      }
    }
    return false;
  }
  for (Int32 j = 0; j < _size; j++) {
    if (_items[j] != nullptr && _items[j]->Equals(item)) {
      return true;
    }
  }
  return false;
}

void ArrayList___::CopyTo(Array<> array) {
  CopyTo(array, 0);
}

void ArrayList___::CopyTo(Array<> array, Int32 arrayIndex) {
  if (array != nullptr && array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  Array<>::in::Copy(_items, 0, array, arrayIndex, _size);
}

void ArrayList___::CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count) {
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (array != nullptr && array->get_Rank() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RankMultiDimNotSupported(), "array");
  }
  Array<>::in::Copy(_items, index, array, arrayIndex, count);
}

void ArrayList___::EnsureCapacity(Int32 min) {
  if (_items->get_Length() < min) {
    Int32 num = ((_items->get_Length() == 0) ? 4 : (_items->get_Length() * 2));
    if ((UInt32)num > 2146435071u) {
      num = 2146435071;
    }
    if (num < min) {
      num = min;
    }
    get_Capacity(num);
  }
}

IList ArrayList___::FixedSize(IList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<FixedSizeList>(list);
}

ArrayList ArrayList___::FixedSize(ArrayList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<FixedSizeArrayList>(list);
}

IEnumerator ArrayList___::GetEnumerator() {
  return rt::newobj<ArrayListEnumeratorSimple>((ArrayList)this);
}

IEnumerator ArrayList___::GetEnumerator(Int32 index, Int32 count) {
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return rt::newobj<ArrayListEnumerator>((ArrayList)this, index, count);
}

Int32 ArrayList___::IndexOf(Object value) {
  return Array<>::in::IndexOf(_items, value, 0, _size);
}

Int32 ArrayList___::IndexOf(Object value, Int32 startIndex) {
  if (startIndex > _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  return Array<>::in::IndexOf(_items, value, startIndex, _size - startIndex);
}

Int32 ArrayList___::IndexOf(Object value, Int32 startIndex, Int32 count) {
  if (startIndex > _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || startIndex > _size - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  return Array<>::in::IndexOf(_items, value, startIndex, count);
}

void ArrayList___::Insert(Int32 index, Object value) {
  if (index < 0 || index > _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (_size == _items->get_Length()) {
    EnsureCapacity(_size + 1);
  }
  if (index < _size) {
    Array<>::in::Copy(_items, index, _items, index + 1, _size - index);
  }
  _items[index] = value;
  _size++;
  _version++;
}

void ArrayList___::InsertRange(Int32 index, ICollection c) {
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c", SR::get_ArgumentNull_Collection());
  }
  if (index < 0 || index > _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  Int32 count = c->get_Count();
  if (count > 0) {
    EnsureCapacity(_size + count);
    if (index < _size) {
      Array<>::in::Copy(_items, index, _items, index + count, _size - index);
    }
    Array<Object> array = rt::newarr<Array<Object>>(count);
    c->CopyTo(array, 0);
    array->CopyTo(_items, index);
    _size += count;
    _version++;
  }
}

Int32 ArrayList___::LastIndexOf(Object value) {
  return LastIndexOf(value, _size - 1, _size);
}

Int32 ArrayList___::LastIndexOf(Object value, Int32 startIndex) {
  if (startIndex >= _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  return LastIndexOf(value, startIndex, startIndex + 1);
}

Int32 ArrayList___::LastIndexOf(Object value, Int32 startIndex, Int32 count) {
  if (get_Count() != 0 && (startIndex < 0 || count < 0)) {
    rt::throw_exception<ArgumentOutOfRangeException>((startIndex < 0) ? "startIndex" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size == 0) {
    return -1;
  }
  if (startIndex >= _size || count > startIndex + 1) {
    rt::throw_exception<ArgumentOutOfRangeException>((startIndex >= _size) ? "startIndex" : "count", SR::get_ArgumentOutOfRange_BiggerThanCollection());
  }
  return Array<>::in::LastIndexOf(_items, value, startIndex, count);
}

IList ArrayList___::ReadOnly(IList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<ReadOnlyList>(list);
}

ArrayList ArrayList___::ReadOnly(ArrayList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<ReadOnlyArrayList>(list);
}

void ArrayList___::Remove(Object obj) {
  Int32 num = IndexOf(obj);
  if (num >= 0) {
    RemoveAt(num);
  }
}

void ArrayList___::RemoveAt(Int32 index) {
  if (index < 0 || index >= _size) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  _size--;
  if (index < _size) {
    Array<>::in::Copy(_items, index + 1, _items, index, _size - index);
  }
  _items[_size] = nullptr;
  _version++;
}

void ArrayList___::RemoveRange(Int32 index, Int32 count) {
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (count > 0) {
    Int32 num = _size;
    _size -= count;
    if (index < _size) {
      Array<>::in::Copy(_items, index + count, _items, index, _size - index);
    }
    while (num > _size) {
      _items[--num] = nullptr;
    }
    _version++;
  }
}

ArrayList ArrayList___::Repeat(Object value, Int32 count) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  ArrayList arrayList = rt::newobj<ArrayList>((count > 4) ? count : 4);
  for (Int32 i = 0; i < count; i++) {
    arrayList->Add(value);
  }
  return arrayList;
}

void ArrayList___::Reverse() {
  Reverse(0, get_Count());
}

void ArrayList___::Reverse(Int32 index, Int32 count) {
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  Array<>::in::Reverse(_items, index, count);
  _version++;
}

void ArrayList___::SetRange(Int32 index, ICollection c) {
  if (c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c", SR::get_ArgumentNull_Collection());
  }
  Int32 count = c->get_Count();
  if (index < 0 || index > _size - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (count > 0) {
    c->CopyTo(_items, index);
    _version++;
  }
}

ArrayList ArrayList___::GetRange(Int32 index, Int32 count) {
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return rt::newobj<Range>((ArrayList)this, index, count);
}

void ArrayList___::Sort() {
  Sort(0, get_Count(), Comparer::in::Default);
}

void ArrayList___::Sort(IComparer comparer) {
  Sort(0, get_Count(), comparer);
}

void ArrayList___::Sort(Int32 index, Int32 count, IComparer comparer) {
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_size - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  Array<>::in::Sort(_items, index, count, comparer);
  _version++;
}

IList ArrayList___::Synchronized(IList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<SyncIList>(list);
}

ArrayList ArrayList___::Synchronized(ArrayList list) {
  if (list == nullptr) {
    rt::throw_exception<ArgumentNullException>("list");
  }
  return rt::newobj<SyncArrayList>(list);
}

Array<Object> ArrayList___::ToArray() {
  if (_size == 0) {
    return Array<>::in::Empty<Object>();
  }
  Array<Object> array = rt::newarr<Array<Object>>(_size);
  Array<>::in::Copy(_items, array, _size);
  return array;
}

Array<> ArrayList___::ToArray(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  Array<> array = Array<>::in::CreateInstance(type, _size);
  Array<>::in::Copy(_items, array, _size);
  return array;
}

void ArrayList___::TrimToSize() {
  get_Capacity(_size);
}

} // namespace System::Private::CoreLib::System::Collections::ArrayListNamespace
