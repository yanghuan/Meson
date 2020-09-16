#include "CounterPayload-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterPayload-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterPayloadNamespace {
KeyValuePair<String, Object> CounterPayload___::_get_ForEnumeration_d__51___::get_CurrentOfObject() {
  return __2__current;
}

Object CounterPayload___::_get_ForEnumeration_d__51___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void CounterPayload___::_get_ForEnumeration_d__51___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void CounterPayload___::_get_ForEnumeration_d__51___::DisposeOfIDisposable() {
}

Boolean CounterPayload___::_get_ForEnumeration_d__51___::MoveNext() {
  Int32 num = __1__state;
  CounterPayload counterPayload = __4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Name", counterPayload->get_Name());
      __1__state = 1;
      return true;
    case 1:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("DisplayName", counterPayload->get_DisplayName());
      __1__state = 2;
      return true;
    case 2:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("DisplayUnits", counterPayload->get_DisplayUnits());
      __1__state = 3;
      return true;
    case 3:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Mean", counterPayload->get_Mean());
      __1__state = 4;
      return true;
    case 4:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("StandardDeviation", counterPayload->get_StandardDeviation());
      __1__state = 5;
      return true;
    case 5:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Count", counterPayload->get_Count());
      __1__state = 6;
      return true;
    case 6:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Min", counterPayload->get_Min());
      __1__state = 7;
      return true;
    case 7:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Max", counterPayload->get_Max());
      __1__state = 8;
      return true;
    case 8:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("IntervalSec", counterPayload->get_IntervalSec());
      __1__state = 9;
      return true;
    case 9:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Series", String::in::Format("Interval={0}", counterPayload->get_IntervalSec()));
      __1__state = 10;
      return true;
    case 10:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("CounterType", "Mean");
      __1__state = 11;
      return true;
    case 11:
      __1__state = -1;
      __2__current = KeyValuePair<String, Object>("Metadata", counterPayload->get_Metadata());
      __1__state = 12;
      return true;
    case 12:
      __1__state = -1;
      return false;
  }
}

void CounterPayload___::_get_ForEnumeration_d__51___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<KeyValuePair<String, Object>> CounterPayload___::_get_ForEnumeration_d__51___::GetEnumeratorOfObject() {
  _get_ForEnumeration_d__51 result;
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    result = (_get_ForEnumeration_d__51)this;
  } else {
    result = rt::newobj<_get_ForEnumeration_d__51>(0);
  }
  return result;
}

IEnumerator_ CounterPayload___::_get_ForEnumeration_d__51___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<KeyValuePair<String, Object>>)(_get_ForEnumeration_d__51)this)->GetEnumerator();
}

IEnumerable<KeyValuePair<String, Object>> CounterPayload___::get_ForEnumeration() {
}

IEnumerator<KeyValuePair<String, Object>> CounterPayload___::GetEnumerator() {
  return get_ForEnumeration()->GetEnumerator();
}

IEnumerator_ CounterPayload___::GetEnumeratorOfIEnumerable() {
  return get_ForEnumeration()->GetEnumerator();
}

void CounterPayload___::ctor() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterPayloadNamespace
