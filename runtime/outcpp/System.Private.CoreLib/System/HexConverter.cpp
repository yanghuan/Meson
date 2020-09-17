#include "HexConverter-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::HexConverterNamespace {
void HexConverter::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void HexConverter::__c___::ctor() {
}

void HexConverter::__c___::_ToString_b__4_0(Span<Char> chars, ValueTuple<IntPtr, Int32, Casing> args) {
  ReadOnlySpan<Byte> bytes = ReadOnlySpan<Byte>((void*)args.Item1, args.Item2);
  EncodeToUtf16(bytes, chars, args.Item3);
}

ReadOnlySpan<Byte> HexConverter::get_CharToHexLookup() {
  return rt::newarr<Array<Byte>>(256);
}

void HexConverter::ToBytesBuffer(Byte value, Span<Byte> buffer, Int32 startingIndex, Casing casing) {
  UInt32 num = (UInt32)(((value & 240) << 4) + (value & 15) - 35209);
  UInt32 num2 = ((((0 - num) & 28784) >> 4) + num + 47545) | (UInt32)casing;
  buffer[startingIndex + 1] = (Byte)num2;
  buffer[startingIndex] = (Byte)(num2 >> 8);
}

void HexConverter::ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex, Casing casing) {
  UInt32 num = (UInt32)(((value & 240) << 4) + (value & 15) - 35209);
  UInt32 num2 = ((((0 - num) & 28784) >> 4) + num + 47545) | (UInt32)casing;
  buffer[startingIndex + 1] = (Char)(num2 & 255);
  buffer[startingIndex] = (Char)(num2 >> 8);
}

void HexConverter::EncodeToUtf16(ReadOnlySpan<Byte> bytes, Span<Char> chars, Casing casing) {
  for (Int32 i = 0; i < bytes.get_Length(); i++) {
    ToCharsBuffer(bytes[i], chars, i * 2, casing);
  }
}

String HexConverter::ToString(ReadOnlySpan<Byte> bytes, Casing casing) {
  {
    Byte* value = bytes;
    SpanAction<Char, ValueTuple<IntPtr, Int32, Casing>> as = __c::in::__9__4_0;
    return String::in::Create(bytes.get_Length() * 2, {(IntPtr)(void*)value, bytes.get_Length(), casing}, as != nullptr ? as : (__c::in::__9__4_0 = {__c::in::__9, &__c::in::_ToString_b__4_0}));
  }
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

Boolean HexConverter::TryDecodeFromUtf16(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  Int32 charsProcessed;
  return TryDecodeFromUtf16(chars, bytes, charsProcessed);
}

Boolean HexConverter::TryDecodeFromUtf16(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsProcessed) {
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 num3 = 0;
  Int32 num4 = 0;
  while (num2 < bytes.get_Length()) {
    num3 = FromChar(chars[num + 1]);
    num4 = FromChar(chars[num]);
    if ((num3 | num4) == 255) {
      break;
    }
    bytes[num2++] = (Byte)((num4 << 4) | num3);
    num += 2;
  }
  if (num3 == 255) {
    num++;
  }
  charsProcessed = num;
  return (num3 | num4) != 255;
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

} // namespace System::Private::CoreLib::System::HexConverterNamespace
