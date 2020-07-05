#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(Span, T)
namespace HexConverterNamespace {
class HexConverter {
  public: enum class Casing : uint32_t {
    Upper = 0,
    Lower = 8224,
  };
  public: static void ToBytesBuffer(Byte value, Span<Byte> buffer, Int32 startingIndex, Casing casing);
  public: static void ToCharsBuffer(Byte value, Span<Char> buffer, Int32 startingIndex, Casing casing);
  public: static Char ToCharUpper(Int32 value);
  public: static Char ToCharLower(Int32 value);
};
} // namespace HexConverterNamespace
using HexConverter = HexConverterNamespace::HexConverter;
} // namespace System::Private::CoreLib::System
