#include "HexConverter-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.Uri/System/HexConverter-dep.h>

namespace System::Private::Uri::System::HexConverterNamespace {
using namespace ::System::Private::CoreLib::System;

void HexConverter::ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex, Casing casing) {
  UInt32 num = (UInt32)(((value & 240) << 4) + (value & 15) - 35209);
  UInt32 num2 = ((((0 - num) & 28784) >> 4) + num + 47545) | (UInt32)casing;
  buffer[startingIndex + 1] = (Char)(num2 & 255);
  buffer[startingIndex] = (Char)(num2 >> 8);
}

} // namespace System::Private::Uri::System::HexConverterNamespace
