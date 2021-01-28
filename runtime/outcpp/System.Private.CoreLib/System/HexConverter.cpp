#include "HexConverter-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::HexConverterNamespace {
void HexConverter::ToBytesBuffer(Byte value, Span<Byte> buffer, Int32 startingIndex, Casing casing) {
  UInt32 num = (UInt32)(((value & 240) << 4) + (value & 15) - 35209);
  UInt32 num2 = ((((0 - num) & 28784) >> 4) + num + 47545) | (UInt32)casing;
  buffer[startingIndex + 1] = (Byte)num2;
  buffer[startingIndex] = (Byte)(num2 >> 8);
}

void HexConverter::ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex, Casing casing) {
  UInt32 num = (UInt32)(((value & 240) << 4) + (value & 15) - 35209);
  UInt32 num2 = ((((0 - num) & 28784) >> 4) + num + 47545) | (UInt32)casing;
  buffer[startingIndex + 1] = (Char)(num2 & 255u);
  buffer[startingIndex] = (Char)(num2 >> 8);
}

Char HexConverter::ToCharUpper(Int32 value) {
  value &= 15;
  value += 48;
  if (value > 57) {
    value += 7;
  }
  return (Char)value;
}

Char HexConverter::ToCharLower(Int32 value) {
  value &= 15;
  value += 48;
  if (value > 57) {
    value += 39;
  }
  return (Char)value;
}

} // namespace System::Private::CoreLib::System::HexConverterNamespace
