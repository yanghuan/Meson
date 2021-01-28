#include "MethodTable-dep.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::MethodTableNamespace {
Boolean MethodTable::get_HasComponentSize() {
  return (Flags & 2147483648u) != 0;
}

Boolean MethodTable::get_ContainsGCPointers() {
  return (Flags & 16777216) != 0;
}

Boolean MethodTable::get_NonTrivialInterfaceCast() {
  return (Flags & 1078460416) != 0;
}

Boolean MethodTable::get_HasTypeEquivalence() {
  return (Flags & 16384) != 0;
}

Boolean MethodTable::get_IsMultiDimensionalArray() {
  return BaseSize > (UInt32)(3 * sizeof(IntPtr));
}

Int32 MethodTable::get_MultiDimensionalArrayRank() {
  return (Int32)((UInt32)((Int32)BaseSize - 3 * sizeof(IntPtr)) / 8u);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::MethodTableNamespace
