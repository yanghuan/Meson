#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
FORWARDS(SpanRuneEnumerator)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
enum class StringComparison : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(Comparison, T)
FORWARD_(IComparable, T1, T2)
FORWARDS(Index)
FORWARDS(Int32)
FORWARDS(Memory, T)
FORWARDS(Range)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace MemoryExtensionsNamespace {
using namespace System::Globalization;
using namespace System::Text;
class MemoryExtensions {
  public: template <class T>
  static Span<T> AsSpan(Array<T> array, Int32 start);
  public: template <class T>
  static Span<T> AsSpan(Array<T> array, Index startIndex);
  public: template <class T>
  static Span<T> AsSpan(Array<T> array, Range range);
  public: static ReadOnlySpan<Char> AsSpan(String text);
  public: static ReadOnlySpan<Char> AsSpan(String text, Int32 start);
  public: static ReadOnlySpan<Char> AsSpan(String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Char> AsMemory(String text);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Int32 start);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Index startIndex);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Char> AsMemory(String text, Range range);
  public: template <class T>
  static Boolean Contains(Span<T> span, T value);
  public: template <class T>
  static Boolean Contains(ReadOnlySpan<T> span, T value);
  public: template <class T>
  static Int32 IndexOf(Span<T> span, T value);
  public: template <class T>
  static Int32 IndexOf(Span<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Int32 LastIndexOf(Span<T> span, T value);
  public: template <class T>
  static Int32 LastIndexOf(Span<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Boolean SequenceEqual(Span<T> span, ReadOnlySpan<T> other);
  public: template <class T>
  static Int32 SequenceCompareTo(Span<T> span, ReadOnlySpan<T> other);
  public: template <class T>
  static Int32 IndexOf(ReadOnlySpan<T> span, T value);
  public: template <class T>
  static Int32 IndexOf(ReadOnlySpan<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Int32 LastIndexOf(ReadOnlySpan<T> span, T value);
  public: template <class T>
  static Int32 LastIndexOf(ReadOnlySpan<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Int32 IndexOfAny(Span<T> span, T value0, T value1);
  public: template <class T>
  static Int32 IndexOfAny(Span<T> span, T value0, T value1, T value2);
  public: template <class T>
  static Int32 IndexOfAny(Span<T> span, ReadOnlySpan<T> values);
  public: template <class T>
  static Int32 IndexOfAny(ReadOnlySpan<T> span, T value0, T value1);
  public: template <class T>
  static Int32 IndexOfAny(ReadOnlySpan<T> span, T value0, T value1, T value2);
  public: template <class T>
  static Int32 IndexOfAny(ReadOnlySpan<T> span, ReadOnlySpan<T> values);
  public: template <class T>
  static Int32 LastIndexOfAny(Span<T> span, T value0, T value1);
  public: template <class T>
  static Int32 LastIndexOfAny(Span<T> span, T value0, T value1, T value2);
  public: template <class T>
  static Int32 LastIndexOfAny(Span<T> span, ReadOnlySpan<T> values);
  public: template <class T>
  static Int32 LastIndexOfAny(ReadOnlySpan<T> span, T value0, T value1);
  public: template <class T>
  static Int32 LastIndexOfAny(ReadOnlySpan<T> span, T value0, T value1, T value2);
  public: template <class T>
  static Int32 LastIndexOfAny(ReadOnlySpan<T> span, ReadOnlySpan<T> values);
  public: template <class T>
  static Boolean SequenceEqual(ReadOnlySpan<T> span, ReadOnlySpan<T> other);
  public: template <class T>
  static Int32 SequenceCompareTo(ReadOnlySpan<T> span, ReadOnlySpan<T> other);
  public: template <class T>
  static Boolean StartsWith(Span<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Boolean StartsWith(ReadOnlySpan<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Boolean EndsWith(Span<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static Boolean EndsWith(ReadOnlySpan<T> span, ReadOnlySpan<T> value);
  public: template <class T>
  static void Reverse(Span<T> span);
  public: template <class T>
  static Span<T> AsSpan(Array<T> array);
  public: template <class T>
  static Span<T> AsSpan(Array<T> array, Int32 start, Int32 length);
  public: template <class T>
  static Span<T> AsSpan(ArraySegment<T> segment);
  public: template <class T>
  static Span<T> AsSpan(ArraySegment<T> segment, Int32 start);
  public: template <class T>
  static Span<T> AsSpan(ArraySegment<T> segment, Index startIndex);
  public: template <class T>
  static Span<T> AsSpan(ArraySegment<T> segment, Int32 start, Int32 length);
  public: template <class T>
  static Span<T> AsSpan(ArraySegment<T> segment, Range range);
  public: template <class T>
  static Memory<T> AsMemory(Array<T> array);
  public: template <class T>
  static Memory<T> AsMemory(Array<T> array, Int32 start);
  public: template <class T>
  static Memory<T> AsMemory(Array<T> array, Index startIndex);
  public: template <class T>
  static Memory<T> AsMemory(Array<T> array, Int32 start, Int32 length);
  public: template <class T>
  static Memory<T> AsMemory(Array<T> array, Range range);
  public: template <class T>
  static Memory<T> AsMemory(ArraySegment<T> segment);
  public: template <class T>
  static Memory<T> AsMemory(ArraySegment<T> segment, Int32 start);
  public: template <class T>
  static Memory<T> AsMemory(ArraySegment<T> segment, Int32 start, Int32 length);
  public: template <class T>
  static void CopyTo(Array<T> source, Span<T> destination);
  public: template <class T>
  static void CopyTo(Array<T> source, Memory<T> destination);
  public: template <class T>
  static Boolean Overlaps(Span<T> span, ReadOnlySpan<T> other);
  public: template <class T>
  static Boolean Overlaps(Span<T> span, ReadOnlySpan<T> other, Int32& elementOffset);
  public: template <class T>
  static Boolean Overlaps(ReadOnlySpan<T> span, ReadOnlySpan<T> other);
  public: template <class T>
  static Boolean Overlaps(ReadOnlySpan<T> span, ReadOnlySpan<T> other, Int32& elementOffset);
  public: template <class T>
  static Int32 BinarySearch(Span<T> span, IComparable<T> comparable);
  public: template <class T, class TComparable>
  static Int32 BinarySearch(Span<T> span, TComparable comparable);
  public: template <class T, class TComparer>
  static Int32 BinarySearch(Span<T> span, T value, TComparer comparer);
  public: template <class T>
  static Int32 BinarySearch(ReadOnlySpan<T> span, IComparable<T> comparable);
  public: template <class T, class TComparable>
  static Int32 BinarySearch(ReadOnlySpan<T> span, TComparable comparable);
  public: template <class T, class TComparer>
  static Int32 BinarySearch(ReadOnlySpan<T> span, T value, TComparer comparer);
  public: template <class T>
  static void Sort(Span<T> span);
  public: template <class T, class TComparer>
  static void Sort(Span<T> span, TComparer comparer);
  public: template <class T>
  static void Sort(Span<T> span, Comparison<T> comparison);
  public: template <class TKey, class TValue>
  static void Sort(Span<TKey> keys, Span<TValue> items);
  public: template <class TKey, class TValue, class TComparer>
  static void Sort(Span<TKey> keys, Span<TValue> items, TComparer comparer);
  public: template <class TKey, class TValue>
  static void Sort(Span<TKey> keys, Span<TValue> items, Comparison<TKey> comparison);
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
  public: template <class T>
  static Memory<T> Trim(Memory<T> memory, T trimElement);
  public: template <class T>
  static Memory<T> TrimStart(Memory<T> memory, T trimElement);
  public: template <class T>
  static Memory<T> TrimEnd(Memory<T> memory, T trimElement);
  public: template <class T>
  static ReadOnlyMemory<T> Trim(ReadOnlyMemory<T> memory, T trimElement);
  public: template <class T>
  static ReadOnlyMemory<T> TrimStart(ReadOnlyMemory<T> memory, T trimElement);
  public: template <class T>
  static ReadOnlyMemory<T> TrimEnd(ReadOnlyMemory<T> memory, T trimElement);
  public: template <class T>
  static Span<T> Trim(Span<T> span, T trimElement);
  public: template <class T>
  static Span<T> TrimStart(Span<T> span, T trimElement);
  public: template <class T>
  static Span<T> TrimEnd(Span<T> span, T trimElement);
  public: template <class T>
  static ReadOnlySpan<T> Trim(ReadOnlySpan<T> span, T trimElement);
  public: template <class T>
  static ReadOnlySpan<T> TrimStart(ReadOnlySpan<T> span, T trimElement);
  public: template <class T>
  static ReadOnlySpan<T> TrimEnd(ReadOnlySpan<T> span, T trimElement);
  private: template <class T>
  static Int32 ClampStart(ReadOnlySpan<T> span, T trimElement);
  private: template <class T>
  static Int32 ClampEnd(ReadOnlySpan<T> span, Int32 start, T trimElement);
  public: template <class T>
  static Memory<T> Trim(Memory<T> memory, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static Memory<T> TrimStart(Memory<T> memory, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static Memory<T> TrimEnd(Memory<T> memory, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static ReadOnlyMemory<T> Trim(ReadOnlyMemory<T> memory, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static ReadOnlyMemory<T> TrimStart(ReadOnlyMemory<T> memory, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static ReadOnlyMemory<T> TrimEnd(ReadOnlyMemory<T> memory, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static Span<T> Trim(Span<T> span, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static Span<T> TrimStart(Span<T> span, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static Span<T> TrimEnd(Span<T> span, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static ReadOnlySpan<T> Trim(ReadOnlySpan<T> span, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static ReadOnlySpan<T> TrimStart(ReadOnlySpan<T> span, ReadOnlySpan<T> trimElements);
  public: template <class T>
  static ReadOnlySpan<T> TrimEnd(ReadOnlySpan<T> span, ReadOnlySpan<T> trimElements);
  private: template <class T>
  static Int32 ClampStart(ReadOnlySpan<T> span, ReadOnlySpan<T> trimElements);
  private: template <class T>
  static Int32 ClampEnd(ReadOnlySpan<T> span, Int32 start, ReadOnlySpan<T> trimElements);
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
