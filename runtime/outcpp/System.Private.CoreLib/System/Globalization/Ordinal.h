#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace OrdinalNamespace {
class Ordinal {
  public: static Int32 CompareStringIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB);
  public: static Int32 CompareStringIgnoreCaseNonAscii(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB);
  public: static Boolean EqualsIgnoreCase(Char& charA, Char& charB, Int32 length);
  public: static Int32 CompareIgnoreCaseInvariantMode(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB);
  public: static Int32 IndexOf(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
  public: static Int32 IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value);
  public: static Int32 LastIndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value);
  public: static Int32 ToUpperOrdinal(ReadOnlySpan<Char> source, Span<Char> destination);
};
} // namespace OrdinalNamespace
using Ordinal = OrdinalNamespace::Ordinal;
} // namespace System::Private::CoreLib::System::Globalization
