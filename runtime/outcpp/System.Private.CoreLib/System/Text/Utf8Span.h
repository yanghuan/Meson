#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/Text/Rune.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(Object)
FORWARDS(Range)
FORWARDS(Span, T)
FORWARD(String)
enum class StringComparison;
FORWARD(Utf8String)
enum class Utf8StringSplitOptions;
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm;
enum class TrimType;
namespace Utf8SpanNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct SplitResult;
struct Utf8Span {
  friend struct CharEnumerable;
  friend struct RuneEnumerable;
  friend struct SplitOnResult;
  public: ReadOnlySpan<Byte> get_Bytes() { return Bytes; }
  public: static Utf8Span get_Empty();
  public: Boolean get_IsEmpty();
  public: Int32 get_Length();
  public: Utf8Span get_Item(Range range);
  public: CharEnumerable get_Chars();
  public: RuneEnumerable get_Runes();
  public: Boolean IsEmptyOrWhiteSpace();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Utf8Span other);
  public: Boolean Equals(Utf8Span other, StringComparison comparison);
  public: static Boolean Equals(Utf8Span left, Utf8Span right);
  public: static Boolean Equals(Utf8Span left, Utf8Span right, StringComparison comparison);
  public: Int32 GetHashCode();
  public: Int32 GetHashCode(StringComparison comparison);
  public: Boolean IsAscii();
  public: Boolean IsNormalized(NormalizationForm normalizationForm);
  public: String ToString();
  public: String ToStringNoReplacement();
  public: Utf8String ToUtf8String();
  public: static Utf8Span UnsafeCreateWithoutValidation(ReadOnlySpan<Byte> buffer);
  public: Int32 CompareTo(Utf8Span other);
  public: Int32 CompareTo(Utf8Span other, StringComparison comparison);
  public: Boolean Contains(Char value);
  public: Boolean Contains(Char value, StringComparison comparison);
  public: Boolean Contains(Rune value);
  public: Boolean Contains(Rune value, StringComparison comparison);
  public: Boolean Contains(Utf8Span value);
  public: Boolean Contains(Utf8Span value, StringComparison comparison);
  public: Boolean EndsWith(Char value);
  public: Boolean EndsWith(Char value, StringComparison comparison);
  public: Boolean EndsWith(Rune value);
  public: Boolean EndsWith(Rune value, StringComparison comparison);
  public: Boolean EndsWith(Utf8Span value);
  public: Boolean EndsWith(Utf8Span value, StringComparison comparison);
  public: Boolean StartsWith(Char value);
  public: Boolean StartsWith(Char value, StringComparison comparison);
  public: Boolean StartsWith(Rune value);
  public: Boolean StartsWith(Rune value, StringComparison comparison);
  public: Boolean StartsWith(Utf8Span value);
  public: Boolean StartsWith(Utf8Span value, StringComparison comparison);
  public: Utf8String Normalize(NormalizationForm normalizationForm);
  public: Int32 Normalize(Span<Byte> destination, NormalizationForm normalizationForm);
  public: Array<Byte> ToByteArray();
  public: Array<Char> ToCharArray();
  public: Int32 ToChars(Span<Char> destination);
  public: Utf8String ToLower(CultureInfo culture);
  public: Int32 ToLower(Span<Byte> destination, CultureInfo culture);
  public: Utf8String ToLowerInvariant();
  public: Int32 ToLowerInvariant(Span<Byte> destination);
  public: Utf8String ToUpper(CultureInfo culture);
  public: Int32 ToUpper(Span<Byte> destination, CultureInfo culture);
  public: Utf8String ToUpperInvariant();
  public: Int32 ToUpperInvariant(Span<Byte> destination);
  public: SplitResult Split(Char separator, Utf8StringSplitOptions options);
  public: SplitResult Split(Rune separator, Utf8StringSplitOptions options);
  public: SplitResult Split(Utf8Span separator, Utf8StringSplitOptions options);
  public: SplitOnResult SplitOn(Char separator);
  public: SplitOnResult SplitOn(Char separator, StringComparison comparisonType);
  public: SplitOnResult SplitOn(Rune separator);
  public: SplitOnResult SplitOn(Rune separator, StringComparison comparisonType);
  public: SplitOnResult SplitOn(Utf8Span separator);
  public: SplitOnResult SplitOn(Utf8Span separator, StringComparison comparisonType);
  public: SplitOnResult SplitOnLast(Char separator);
  public: SplitOnResult SplitOnLast(Char separator, StringComparison comparisonType);
  public: SplitOnResult SplitOnLast(Rune separator);
  public: SplitOnResult SplitOnLast(Rune separator, StringComparison comparisonType);
  public: SplitOnResult SplitOnLast(Utf8Span separator);
  public: SplitOnResult SplitOnLast(Utf8Span separator, StringComparison comparisonType);
  public: Utf8Span Trim();
  public: Utf8Span TrimEnd();
  public: Utf8Span TrimHelper(TrimType trimType);
  public: Utf8Span TrimStart();
  public: Boolean TryFind(Char value, Range& range);
  public: Boolean TryFind(Char value, StringComparison comparisonType, Range& range);
  public: Boolean TryFind(Rune value, Range& range);
  public: Boolean TryFind(Rune value, StringComparison comparisonType, Range& range);
  public: Boolean TryFind(Utf8Span value, Range& range);
  public: Boolean TryFind(Utf8Span value, StringComparison comparisonType, Range& range);
  private: Boolean TryFind(Utf8Span value, StringComparison comparisonType, Range& range, Boolean fromBeginning);
  public: Boolean TryFindLast(Char value, Range& range);
  public: Boolean TryFindLast(Char value, StringComparison comparisonType, Range& range);
  public: Boolean TryFindLast(Rune value, Range& range);
  public: Boolean TryFindLast(Rune value, StringComparison comparisonType, Range& range);
  public: Boolean TryFindLast(Utf8Span value, Range& range);
  public: Boolean TryFindLast(Utf8Span value, StringComparison comparisonType, Range& range);
  private: ReadOnlySpan<Byte> Bytes;
};
struct CharEnumerable {
  public: struct Enumerator {
    public: Char get_Current();
    public: Boolean MoveNext();
    private: UInt32 _currentCharPair;
    private: ReadOnlySpan<Byte> _remainingUtf8Bytes;
  };
  public: Enumerator GetEnumerator();
  private: Utf8Span _span;
};
struct RuneEnumerable {
  public: struct Enumerator {
    public: Rune get_Current();
    public: Boolean MoveNext();
    private: Rune _currentRune;
    private: ReadOnlySpan<Byte> _remainingUtf8Bytes;
  };
  public: Enumerator GetEnumerator();
  private: Utf8Span _span;
};
struct State {
  public: Boolean DeconstructHelper(Utf8Span& source, Utf8Span& firstItem, Utf8Span& remainder);
  public: Utf8Span RemainingSearchSpace;
  public: Int32 SearchRune;
  public: Utf8Span SearchTerm;
  public: Utf8StringSplitOptions SplitOptions;
};
struct SplitResult {
  friend struct State;
  friend struct Enumerator;
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2);
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2, Utf8Span& item3);
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2, Utf8Span& item3, Utf8Span& item4);
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2, Utf8Span& item3, Utf8Span& item4, Utf8Span& item5);
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2, Utf8Span& item3, Utf8Span& item4, Utf8Span& item5, Utf8Span& item6);
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2, Utf8Span& item3, Utf8Span& item4, Utf8Span& item5, Utf8Span& item6, Utf8Span& item7);
  public: void Deconstruct(Utf8Span& item1, Utf8Span& item2, Utf8Span& item3, Utf8Span& item4, Utf8Span& item5, Utf8Span& item6, Utf8Span& item7, Utf8Span& item8);
  public: Enumerator GetEnumerator();
  private: void TrimIfNeeded(Utf8Span& span);
  private: State _state;
};
struct Enumerator {
  public: Utf8Span get_Current();
  public: Boolean MoveNext();
  private: Utf8Span _current;
  private: State _state;
};
struct SplitOnResult {
  public: Utf8Span get_After() { return After; }
  public: Utf8Span get_Before() { return Before; }
  public: void Deconstruct(Utf8Span& before, Utf8Span& after);
  private: Utf8Span After;
  private: Utf8Span Before;
};
} // namespace Utf8SpanNamespace
using Utf8Span = Utf8SpanNamespace::Utf8Span;
} // namespace System::Private::CoreLib::System::Text
