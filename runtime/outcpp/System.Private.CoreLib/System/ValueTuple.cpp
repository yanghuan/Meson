#include "ValueTuple-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>

namespace System::Private::CoreLib::System::ValueTupleNamespace {
Int32 ValueTuple<>::get_LengthOfITuple() {
  return 0;
}

Object ValueTuple<>::get_ItemOfITuple(Int32 index) {
  rt::throw_exception<IndexOutOfRangeException>();
}

} // namespace System::Private::CoreLib::System::ValueTupleNamespace
