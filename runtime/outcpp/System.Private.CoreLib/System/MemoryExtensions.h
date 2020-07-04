#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
FORWARDS(SpanRuneEnumerator)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(Index)
FORWARDS(Range)
FORWARDS(Boolean)
enum class StringComparison;
FORWARDS(Span, T)
FORWARDS(Memory, T)
namespace MemoryExtensionsNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Text;
class MemoryExtensions {
  public: static ReadOnlySpan<Char> AsSpan(String text);
  public: static ReadOnlySpan<Char> AsSpan(String text, Int32 start);
  public: static ReadOnlySpan<Char> AsSpan(String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Char> AsMemory(String text);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Int32 start);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Index startIndex);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Range range);
  public: static Boolean IsWhiteSpace(ReadOnlySpan<Char> span);
  public: static Boolean Contains(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType);
  public: static Boolean Equals(ReadOnlySpan<Char> span, ReadOnlySpan<Char> other, StringComparison comparisonType);
  public: static Boolean EqualsOrdinal(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value);
  public: static Boolean EqualsOrdinalIgnoreCase(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value);
  public: static Int32 CompareTo(ReadOnlySpan<Char> span, ReadOnlySpan<Char> other, StringComparison comparisonType);
  public: static Int32 IndexOf(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType);
  public: static Int32 LastIndexOf(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType);
  public: static Int32 ToLower(ReadOnlySpan<Char> source, Span<Char> destination, CultureInfo culture);
  public: static Int32 ToLowerInvariant(ReadOnlySpan<Char> source, Span<Char> destination);
  public: static Int32 ToUpper(ReadOnlySpan<Char> source, Span<Char> destination, CultureInfo culture);
  public: static Int32 ToUpperInvariant(ReadOnlySpan<Char> source, Span<Char> destination);
  public: static Boolean EndsWith(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType);
  public: static Boolean EndsWithOrdinalIgnoreCase(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value);
  public: static Boolean StartsWith(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType);
  public: static Boolean StartsWithOrdinalIgnoreCase(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value);
  public: static SpanRuneEnumerator EnumerateRunes(ReadOnlySpan<Char> span);
  public: static SpanRuneEnumerator EnumerateRunes(Span<Char> span);
  public: static Memory<Char> Trim(Memory<Char> memory);
  public: static Memory<Char> TrimStart(Memory<Char> memory);
  public: static Memory<Char> TrimEnd(Memory<Char> memory);
  public: static ReadOnlyMemory<Char> Trim(ReadOnlyMemory<Char> memory);
  public: static ReadOnlyMemory<Char> TrimStart(ReadOnlyMemory<Char> memory);
  public: static ReadOnlyMemory<Char> TrimEnd(ReadOnlyMemory<Char> memory);
  public: static ReadOnlySpan<Char> Trim(ReadOnlySpan<Char> span);
  public: static ReadOnlySpan<Char> TrimStart(ReadOnlySpan<Char> span);
  public: static ReadOnlySpan<Char> TrimEnd(ReadOnlySpan<Char> span);
  public: static ReadOnlySpan<Char> Trim(ReadOnlySpan<Char> span, Char trimChar);
  public: static ReadOnlySpan<Char> TrimStart(ReadOnlySpan<Char> span, Char trimChar);
  public: static ReadOnlySpan<Char> TrimEnd(ReadOnlySpan<Char> span, Char trimChar);
  public: static ReadOnlySpan<Char> Trim(ReadOnlySpan<Char> span, ReadOnlySpan<Char> trimChars);
  public: static ReadOnlySpan<Char> TrimStart(ReadOnlySpan<Char> span, ReadOnlySpan<Char> trimChars);
  public: static ReadOnlySpan<Char> TrimEnd(ReadOnlySpan<Char> span, ReadOnlySpan<Char> trimChars);
  public: static Span<Char> Trim(Span<Char> span);
  public: static Span<Char> TrimStart(Span<Char> span);
  public: static Span<Char> TrimEnd(Span<Char> span);
  private: static Int32 ClampStart(ReadOnlySpan<Char> span);
  private: static Int32 ClampEnd(ReadOnlySpan<Char> span, Int32 start);
};
} // namespace MemoryExtensionsNamespace
using MemoryExtensions = MemoryExtensionsNamespace::MemoryExtensions;
} // namespace System::Private::CoreLib::System
