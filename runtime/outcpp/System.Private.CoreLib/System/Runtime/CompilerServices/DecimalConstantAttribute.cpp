#include "DecimalConstantAttribute-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::DecimalConstantAttributeNamespace {
Decimal DecimalConstantAttribute___::get_Value() {
  return _dec;
}

void DecimalConstantAttribute___::ctor(Byte scale, Byte sign, UInt32 hi, UInt32 mid, UInt32 low) {
  _dec = Decimal((Int32)low, (Int32)mid, (Int32)hi, sign != 0, scale);
}

void DecimalConstantAttribute___::ctor(Byte scale, Byte sign, Int32 hi, Int32 mid, Int32 low) {
  _dec = Decimal(low, mid, hi, sign != 0, scale);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::DecimalConstantAttributeNamespace
