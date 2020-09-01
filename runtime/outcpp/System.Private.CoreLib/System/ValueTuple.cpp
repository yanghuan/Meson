#include "ValueTuple-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
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

Int32 ValueTuple<>::CompareTo(ValueTuple<> other) {
  return 0;
}

Int32 ValueTuple<>::GetHashCode() {
  return 0;
}

String ValueTuple<>::ToString() {
  return "()";
}

ValueTuple<> ValueTuple<>::Create() {
  return rt::default__;
}

} // namespace System::Private::CoreLib::System::ValueTupleNamespace
