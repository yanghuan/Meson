#include "IncrementingCounterPayload-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingCounterPayload-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingCounterPayloadNamespace {
KeyValuePair<String, Object> IncrementingCounterPayload___::_get_ForEnumeration_d__39___::get_CurrentOfObject() {
  return <>2__current;
}

Object IncrementingCounterPayload___::_get_ForEnumeration_d__39___::get_CurrentOfIEnumerator() {
  return <>2__current;
}

void IncrementingCounterPayload___::_get_ForEnumeration_d__39___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  <>l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void IncrementingCounterPayload___::_get_ForEnumeration_d__39___::DisposeOfIDisposable() {
}

Boolean IncrementingCounterPayload___::_get_ForEnumeration_d__39___::MoveNext() {
  Int32 num = <>1__state;
  IncrementingCounterPayload incrementingCounterPayload = <>4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Name", incrementingCounterPayload->get_Name());
      <>1__state = 1;
      return true;
    case 1:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("DisplayName", incrementingCounterPayload->get_DisplayName());
      <>1__state = 2;
      return true;
    case 2:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("DisplayRateTimeScale", incrementingCounterPayload->get_DisplayRateTimeScale());
      <>1__state = 3;
      return true;
    case 3:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Increment", incrementingCounterPayload->get_Increment());
      <>1__state = 4;
      return true;
    case 4:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("IntervalSec", incrementingCounterPayload->get_IntervalSec());
      <>1__state = 5;
      return true;
    case 5:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Series", String::in::Format("Interval={0}", incrementingCounterPayload->get_IntervalSec()));
      <>1__state = 6;
      return true;
    case 6:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("CounterType", "Sum");
      <>1__state = 7;
      return true;
    case 7:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("Metadata", incrementingCounterPayload->get_Metadata());
      <>1__state = 8;
      return true;
    case 8:
      <>1__state = -1;
      <>2__current = KeyValuePair<String, Object>("DisplayUnits", incrementingCounterPayload->get_DisplayUnits());
      <>1__state = 9;
      return true;
    case 9:
      <>1__state = -1;
      return false;
  }
}

void IncrementingCounterPayload___::_get_ForEnumeration_d__39___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<KeyValuePair<String, Object>> IncrementingCounterPayload___::_get_ForEnumeration_d__39___::GetEnumeratorOfObject() {
  _get_ForEnumeration_d__39 result;
  if (<>1__state == -2 && <>l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    <>1__state = 0;
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
