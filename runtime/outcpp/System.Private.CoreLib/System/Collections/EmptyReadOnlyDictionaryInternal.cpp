#include "EmptyReadOnlyDictionaryInternal-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Collections/EmptyReadOnlyDictionaryInternal-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Collections::EmptyReadOnlyDictionaryInternalNamespace {
Object EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::get_Current() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
}

Object EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::get_Key() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
}

Object EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::get_Value() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
}

DictionaryEntry EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::get_Entry() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
}

void EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::ctor() {
}

Boolean EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::MoveNext() {
  return false;
}

void EmptyReadOnlyDictionaryInternal___::NodeEnumerator___::Reset() {
}

Int32 EmptyReadOnlyDictionaryInternal___::get_Count() {
  return 0;
}

Object EmptyReadOnlyDictionaryInternal___::get_SyncRoot() {
  return (EmptyReadOnlyDictionaryInternal)this;
}

Boolean EmptyReadOnlyDictionaryInternal___::get_IsSynchronized() {
  return false;
}

Object EmptyReadOnlyDictionaryInternal___::get_Item(Object key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  return nullptr;
}

void EmptyReadOnlyDictionaryInternal___::set_Item(Object key, Object value) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  if (!key->GetType()->get_IsSerializable()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotSerializable(), "key");
  }
  if (value != nullptr && !value->GetType()->get_IsSerializable()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotSerializable(), "value");
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
}

ICollection EmptyReadOnlyDictionaryInternal___::get_Keys() {
  return Array<>::in::Empty<Object>();
}

ICollection EmptyReadOnlyDictionaryInternal___::get_Values() {
  return Array<>::in::Empty<Object>();
}

Boolean EmptyReadOnlyDictionaryInternal___::get_IsReadOnly() {
  return true;
}

Boolean EmptyReadOnlyDictionaryInternal___::get_IsFixedSize() {
  return true;
}

void EmptyReadOnlyDictionaryInternal___::ctor() {
}

void EmptyReadOnlyDictionaryInternal___::CopyTo(Array<> array, Int32 index) {
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
}

Boolean EmptyReadOnlyDictionaryInternal___::Contains(Object key) {
  return false;
}

void EmptyReadOnlyDictionaryInternal___::Add(Object key, Object value) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key", SR::get_ArgumentNull_Key());
  }
  if (!key->GetType()->get_IsSerializable()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotSerializable(), "key");
  }
  if (value != nullptr && !value->GetType()->get_IsSerializable()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotSerializable(), "value");
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
}

void EmptyReadOnlyDictionaryInternal___::Clear() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
}

IDictionaryEnumerator EmptyReadOnlyDictionaryInternal___::GetEnumerator() {
  return rt::newobj<NodeEnumerator>();
}

void EmptyReadOnlyDictionaryInternal___::Remove(Object key) {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
}

} // namespace System::Private::CoreLib::System::Collections::EmptyReadOnlyDictionaryInternalNamespace
