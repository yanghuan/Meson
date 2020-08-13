#include "HexConverter-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::HexConverterNamespace {
void HexConverter::ToBytesBuffer(Byte value, Span<Byte> buffer, Int32 startingIndex, Casing casing) {
}

void HexConverter::ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex, Casing casing) {
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
