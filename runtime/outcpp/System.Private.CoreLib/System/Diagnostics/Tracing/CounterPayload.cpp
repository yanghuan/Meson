#include "CounterPayload-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterPayload-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterPayloadNamespace {
KeyValuePair<String, Object> CounterPayload___::_get_ForEnumeration_d__51___::get_CurrentOfObject() {
  return <>2__current;
}

Object CounterPayload___::_get_ForEnumeration_d__51___::get_CurrentOfIEnumerator() {
  return <>2__current;
}

void CounterPayload___::_get_ForEnumeration_d__51___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  <>l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void CounterPayload___::_get_ForEnumeration_d__51___::DisposeOfIDisposable() {
}

Boolean CounterPayload___::_get_ForEnumeration_d__51___::MoveNext() {
  Int32 num = <>1__state;
  CounterPayload counterPayload = <>4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Name", counterPayload->get_Name());
      <>1__state = 1;
      return true;
    case 1:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("DisplayName", counterPayload->get_DisplayName());
      <>1__state = 2;
      return true;
    case 2:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("DisplayUnits", counterPayload->get_DisplayUnits());
      <>1__state = 3;
      return true;
    case 3:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Mean", counterPayload->get_Mean());
      <>1__state = 4;
      return true;
    case 4:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("StandardDeviation", counterPayload->get_StandardDeviation());
      <>1__state = 5;
      return true;
    case 5:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Count", counterPayload->get_Count());
      <>1__state = 6;
      return true;
    case 6:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Min", counterPayload->get_Min());
      <>1__state = 7;
      return true;
    case 7:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Max", counterPayload->get_Max());
      <>1__state = 8;
      return true;
    case 8:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("IntervalSec", counterPayload->get_IntervalSec());
      <>1__state = 9;
      return true;
    case 9:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Series", String::in::Format("Interval={0}", counterPayload->get_IntervalSec()));
      <>1__state = 10;
      return true;
    case 10:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("CounterType", "Mean");
      <>1__state = 11;
      return true;
    case 11:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Metadata", counterPayload->get_Metadata());
      <>1__state = 12;
      return true;
    case 12:
      <>1__state = -1;
      return false;
  }
}

void CounterPayload___::_get_ForEnumeration_d__51___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<KeyValuePair<String, Object>> CounterPayload___::_get_ForEnumeration_d__51___::GetEnumeratorOfObject() {
  _get_ForEnumeration_d__51 result;
  if (<>1__state == -2 && <>l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    <>1__state = 0;
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
