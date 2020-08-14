#include "MethodTable-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::MethodTableNamespace {
Boolean MethodTable::get_HasComponentSize() {
}

Boolean MethodTable::get_ContainsGCPointers() {
}

Boolean MethodTable::get_NonTrivialInterfaceCast() {
}

Boolean MethodTable::get_HasTypeEquivalence() {
}

Boolean MethodTable::get_IsMultiDimensionalArray() {
  return BaseSize > (UInt32)(3 * sizeof(IntPtr));
}

Int32 MethodTable::get_MultiDimensionalArrayRank() {
  return (Int32)((UInt32)((Int32)BaseSize - 3 * sizeof(IntPtr)) / 8u);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::MethodTableNamespace
