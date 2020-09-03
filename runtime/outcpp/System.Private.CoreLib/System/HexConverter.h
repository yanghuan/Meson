#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace HexConverterNamespace {
class HexConverter {
  public: enum class Casing : uint32_t {
    Upper = 0,
    Lower = 8224,
  };
  public: static ReadOnlySpan<Byte> get_CharToHexLookup();
  public: static void ToBytesBuffer(Byte value, Span<Byte> buffer, Int32 startingIndex = 0, Casing casing = Casing::Upper);
  public: static void ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex = 0, Casing casing = Casing::Upper);
  public: static void EncodeToUtf16(ReadOnlySpan<Byte> bytes, Span<Char> chars, Casing casing = Casing::Upper);
  public: static String ToString(ReadOnlySpan<Byte> bytes, Casing casing = Casing::Upper);
  public: static Char ToCharUpper(Int32 value);
  public: static Char ToCharLower(Int32 value);
  public: static Boolean TryDecodeFromUtf16(ReadOnlySpan<Char> chars, Span<Byte> bytes);
  public: static Boolean TryDecodeFromUtf16(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsProcessed);
  public: static Int32 FromChar(Int32 c);
  public: static Boolean IsHexChar(Int32 c);
};
} // namespace HexConverterNamespace
using HexConverter = HexConverterNamespace::HexConverter;
} // namespace System::Private::CoreLib::System
