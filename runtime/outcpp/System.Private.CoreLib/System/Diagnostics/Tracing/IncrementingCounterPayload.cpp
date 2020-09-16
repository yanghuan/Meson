#include "IncrementingCounterPayload-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingCounterPayload-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingCounterPayloadNamespace {
KeyValuePair<String, Object> IncrementingCounterPayload___::_get_ForEnumeration_d__39___::get_CurrentOfObject() {
  return __2__current;
}

Object IncrementingCounterPayload___::_get_ForEnumeration_d__39___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void IncrementingCounterPayload___::_get_ForEnumeration_d__39___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void IncrementingCounterPayload___::_get_ForEnumeration_d__39___::DisposeOfIDisposable() {
}

Boolean IncrementingCounterPayload___::_get_ForEnumeration_d__39___::MoveNext() {
  Int32 num = __1__state;
  IncrementingCounterPayload incrementingCounterPayload = __4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Name", incrementingCounterPayload->get_Name());
      __1__state = 1;
      return true;
    case 1:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("DisplayName", incrementingCounterPayload->get_DisplayName());
      __1__state = 2;
      return true;
    case 2:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("DisplayRateTimeScale", incrementingCounterPayload->get_DisplayRateTimeScale());
      __1__state = 3;
      return true;
    case 3:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Increment", incrementingCounterPayload->get_Increment());
      __1__state = 4;
      return true;
    case 4:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("IntervalSec", incrementingCounterPayload->get_IntervalSec());
      __1__state = 5;
      return true;
    case 5:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Series", String::in::Format("Interval={0}", incrementingCounterPayload->get_IntervalSec()));
      __1__state = 6;
      return true;
    case 6:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("CounterType", "Sum");
      __1__state = 7;
      return true;
    case 7:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Metadata", incrementingCounterPayload->get_Metadata());
      __1__state = 8;
      return true;
    case 8:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("DisplayUnits", incrementingCounterPayload->get_DisplayUnits());
      __1__state = 9;
      return true;
    case 9:
      __1__state = -1;
      return false;
  }
}

void IncrementingCounterPayload___::_get_ForEnumeration_d__39___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<KeyValuePair<String, Object>> IncrementingCounterPayload___::_get_ForEnumeration_d__39___::GetEnumeratorOfObject() {
  _get_ForEnumeration_d__39 result;
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    result = (_get_ForEnumeration_d__39)this;
  } else {
    result = rt::newobj<_get_ForEnumeration_d__39>(0);
  }
  return result;
}

IEnumerator_ IncrementingCounterPayload___::_get_ForEnumeration_d__39___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<KeyValuePair<String, Object>>)(_get_ForEnumeration_d__39)this)->GetEnumerator();
}

IEnumerable<KeyValuePair<String, Object>> IncrementingCounterPayload___::get_ForEnumeration() {
}

IEnumerator<KeyValuePair<String, Object>> IncrementingCounterPayload___::GetEnumerator() {
  return get_ForEnumeration()->GetEnumerator();
}

IEnumerator_ IncrementingCounterPayload___::GetEnumeratorOfIEnumerable() {
  return get_ForEnumeration()->GetEnumerator();
}

void IncrementingCounterPayload___::ctor() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingCounterPayloadNamespace
