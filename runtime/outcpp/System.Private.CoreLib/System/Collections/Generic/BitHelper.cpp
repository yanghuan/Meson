#include "BitHelper-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::BitHelperNamespace {
BitHelper::BitHelper(Span<Int32> span, Boolean clear) {
  if (clear) {
    span.Clear();
  }
  _span = span;
}

void BitHelper::MarkBit(Int32 bitPosition) {
  Int32 num = bitPosition / 32;
  if ((UInt32)num < (UInt32)_span.get_Length()) {
    _span[num] |= 1 << bitPosition % 32;
  }
}

Boolean BitHelper::IsMarked(Int32 bitPosition) {
  Int32 num = bitPosition / 32;
  if ((UInt32)num < (UInt32)_span.get_Length()) {
    return (_span[num] & (1 << bitPosition % 32)) != 0;
  }
  return false;
}

Int32 BitHelper::ToIntArrayLength(Int32 n) {
  if (n <= 0) {
    return 0;
  }
  return (n - 1) / 32 + 1;
}

} // namespace System::Private::CoreLib::System::Collections::Generic::BitHelperNamespace
