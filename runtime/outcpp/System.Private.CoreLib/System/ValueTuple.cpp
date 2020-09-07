#include "ValueTuple-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ValueTuple-dep.h>

namespace System::Private::CoreLib::System::ValueTupleNamespace {
Int32 ValueTuple<>::get_LengthOfITuple() {
  return 0;
}

Object ValueTuple<>::get_ItemOfITuple(Int32 index) {
  rt::throw_exception<IndexOutOfRangeException>();
}

Boolean ValueTuple<>::Equals(Object obj) {
  return rt::is<ValueTuple<>>(obj);
}

Boolean ValueTuple<>::Equals(ValueTuple<> other) {
  return true;
}

Boolean ValueTuple<>::EqualsOfIStructuralEquatable(Object other, IEqualityComparer comparer) {
  return rt::is<ValueTuple<>>(other);
}

Int32 ValueTuple<>::CompareToOfIComparable(Object other) {
  if (other == nullptr) {
    return 1;
  }
  if (!rt::is<ValueTuple<>>(other)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_ArgumentException_ValueTupleIncorrectType(), GetType()), "other");
  }
  return 0;
}

Int32 ValueTuple<>::CompareTo(ValueTuple<> other) {
  return 0;
}

Int32 ValueTuple<>::CompareToOfIStructuralComparable(Object other, IComparer comparer) {
  if (other == nullptr) {
    return 1;
  }
  if (!rt::is<ValueTuple<>>(other)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_ArgumentException_ValueTupleIncorrectType(), GetType()), "other");
  }
  return 0;
}

Int32 ValueTuple<>::GetHashCode() {
  return 0;
}

Int32 ValueTuple<>::GetHashCodeOfIStructuralEquatable(IEqualityComparer comparer) {
  return 0;
}

Int32 ValueTuple<>::GetHashCodeOfIValueTupleInternal(IEqualityComparer comparer) {
  return 0;
}

String ValueTuple<>::ToString() {
  return "()";
}

String ValueTuple<>::ToStringEndOfIValueTupleInternal() {
  return ")";
}

ValueTuple<> ValueTuple<>::Create() {
  return rt::default__;
}

} // namespace System::Private::CoreLib::System::ValueTupleNamespace
