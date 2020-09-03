#include "HexConverter-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::Uri::System::HexConverterNamespace {
using namespace ::System::Private::CoreLib::System;

ReadOnlySpan<Byte> HexConverter::get_CharToHexLookup() {
  return rt::newarr<Array<Byte>>(256);
}

void HexConverter::ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex, Casing casing) {
  UInt32 num = (UInt32)(((value & 240) << 4) + (value & 15) - 35209);
  UInt32 num2 = ((((0 - num) & 28784) >> 4) + num + 47545) | (UInt32)casing;
  buffer[startingIndex + 1] = (Char)(num2 & 255);
  buffer[startingIndex] = (Char)(num2 >> 8);
}

Int32 HexConverter::FromChar(Int32 c) {
  if (c < get_CharToHexLookup().get_Length()) {
    return get_CharToHexLookup()[c];
  }
  return 255;
}

Boolean HexConverter::IsHexChar(Int32 c) {
  return FromChar(c) != 255;
}

} // namespace System::Private::Uri::System::HexConverterNamespace
