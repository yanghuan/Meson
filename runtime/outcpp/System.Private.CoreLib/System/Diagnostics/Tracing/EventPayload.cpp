#include "EventPayload-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyNotFoundException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPayload-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPayloadNamespace {
using namespace System::Collections::Generic;

KeyValuePair<String, Object> EventPayload___::_GetEnumerator_d__17___::get_CurrentOfObject() {
  return __2__current;
}

Object EventPayload___::_GetEnumerator_d__17___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void EventPayload___::_GetEnumerator_d__17___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
}

void EventPayload___::_GetEnumerator_d__17___::DisposeOfIDisposable() {
}

Boolean EventPayload___::_GetEnumerator_d__17___::MoveNext() {
  Int32 num = __1__state;
  EventPayload eventPayload = __4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      __1__state = -1;
      _i_5__2 = 0;
      break;
    case 1:
      __1__state = -1;
      _i_5__2++;
      break;
  }
  if (_i_5__2 < eventPayload->get_Keys()->get_Count()) {
    __2__current = KeyValuePair<String, Object>(eventPayload->m_names[_i_5__2], eventPayload->m_values[_i_5__2]);
    __1__state = 1;
    return true;
  }
  return false;
}

void EventPayload___::_GetEnumerator_d__17___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

ICollection<String> EventPayload___::get_Keys() {
  return m_names;
}

ICollection<Object> EventPayload___::get_Values() {
  return m_values;
}

Object EventPayload___::get_Item(String key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key");
  }
  Int32 num = 0;
  for (String&& name : *m_names) {
    if (name == key) {
      return m_values[num];
    }
    num++;
  }
  rt::throw_exception<KeyNotFoundException>(SR::Format(SR::get_Arg_KeyNotFoundWithKey(), key));
}

void EventPayload___::set_Item(String key, Object value) {
  rt::throw_exception<NotSupportedException>();
}

Int32 EventPayload___::get_Count() {
  return m_names->get_Count();
}

Boolean EventPayload___::get_IsReadOnly() {
  return true;
}

void EventPayload___::ctor(List<String> payloadNames, List<Object> payloadValues) {
  m_names = payloadNames;
  m_values = payloadValues;
}

void EventPayload___::Add(String key, Object value) {
  rt::throw_exception<NotSupportedException>();
}

void EventPayload___::Add(KeyValuePair<String, Object> payloadEntry) {
  rt::throw_exception<NotSupportedException>();
}

void EventPayload___::Clear() {
  rt::throw_exception<NotSupportedException>();
}

Boolean EventPayload___::Contains(KeyValuePair<String, Object> entry) {
  return ContainsKey(entry.get_Key());
}

Boolean EventPayload___::ContainsKey(String key) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key");
  }
  for (String&& name : *m_names) {
    if (name == key) {
      return true;
    }
  }
  return false;
}

IEnumerator<KeyValuePair<String, Object>> EventPayload___::GetEnumerator() {
  for (Int32 i = 0; i < get_Keys()->get_Count(); i++) {
  }
}

IEnumerator_ EventPayload___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<KeyValuePair<String, Object>>)(EventPayload)this)->GetEnumerator();
}

void EventPayload___::CopyTo(Array<KeyValuePair<String, Object>> payloadEntries, Int32 count) {
  rt::throw_exception<NotSupportedException>();
}

Boolean EventPayload___::Remove(String key) {
  rt::throw_exception<NotSupportedException>();
}

Boolean EventPayload___::Remove(KeyValuePair<String, Object> entry) {
  rt::throw_exception<NotSupportedException>();
}

Boolean EventPayload___::TryGetValue(String key, Object& value) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key");
  }
  Int32 num = 0;
  for (String&& name : *m_names) {
    if (name == key) {
      value = m_values[num];
      return true;
    }
    num++;
  }
  value = nullptr;
  return false;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPayloadNamespace
