#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
namespace HexConverterNamespace {
using namespace ::System::Private::CoreLib::System;
class HexConverter {
  public: enum class Casing : uint32_t {
    Upper = 0,
    Lower = 8224,
  };
  public: static ReadOnlySpan<Byte> get_CharToHexLookup();
  public: static void ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex = 0, Casing casing = Casing::Upper);
  public: static Int32 FromChar(Int32 c);
  public: static Boolean IsHexChar(Int32 c);
};
} // namespace HexConverterNamespace
using HexConverter = HexConverterNamespace::HexConverter;
} // namespace System::Private::Uri::System
