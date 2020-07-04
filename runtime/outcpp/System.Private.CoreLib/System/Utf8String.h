#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/Rune.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm;
enum class TrimType;
FORWARDS(Utf8Span)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Char)
enum class Utf8StringSplitOptions;
FORWARDS(Range)
FORWARDS(ReadOnlySpan, T)
enum class StringComparison;
FORWARDS(Span, T)
FORWARD_(Array, T1, T2)
FORWARD(String)
namespace Utf8StringNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(Utf8String) {
  public: struct ByteEnumerable {
    public: struct Enumerator {
      public: Byte get_Current() { return Current; }
      private: void set_Current(Byte value) { Current = value; }
      private: Object get_CurrentOfIEnumerator();
      public: Boolean MoveNext();
      private: Utf8String _obj;
      private: Int32 _nextByteIdx;
      private: Byte Current;
    };
    public: Enumerator GetEnumerator();
    private: Utf8String _obj;
  };
  public: struct CharEnumerable {
    public: struct Enumerator {
      public: Char get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: Boolean MoveNext();
      private: Utf8String _obj;
      private: UInt32 _currentCharPair;
      private: Int32 _nextByteIdx;
    };
    public: Enumerator GetEnumerator();
    private: Utf8String _obj;
  };
  public: struct RuneEnumerable {
    public: struct Enumerator {
      public: Rune get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: Boolean MoveNext();
      private: Utf8String _obj;
      private: Rune _currentRune;
      private: Int32 _nextByteIdx;
    };
    public: Enumerator GetEnumerator();
    private: Utf8String _obj;
  };
  public: struct SplitResult {
    private: struct State {
      public: Boolean DeconstructHelper(Utf8Span& source, Utf8Span& firstItem, Utf8Span& remainder);
      public: Utf8Span GetRemainingSearchSpace();
      public: Utf8String FullSearchSpace;
      public: Int32 OffsetAtWhichToContinueSearch;
      public: Int32 SearchRune;
      public: Utf8String SearchTerm;
      public: Utf8StringSplitOptions SplitOptions;
    };
    public: struct Enumerator {
      public: Utf8String get_Current();
      private: Object get_CurrentOfIEnumerator();
      public: Boolean MoveNext();
      private: Utf8String _current;
      private: State _state;
    };
    public: void Deconstruct(Utf8String& item1, Utf8String& item2);
    public: void Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3);
    public: void Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4);
    public: void Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5);
    public: void Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5, Utf8String& item6);
    public: void Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5, Utf8String& item6, Utf8String& item7);
    public: void Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5, Utf8String& item6, Utf8String& item7, Utf8String& item8);
    public: Enumerator GetEnumerator();
    private: Utf8String TrimIfNeeded(Utf8Span span);
    private: State _state;
  };
  public: struct SplitOnResult {
    public: Utf8String get_After() { return After; }
    public: Utf8String get_Before() { return Before; }
    public: void Deconstruct(Utf8String& before, Utf8String& after);
    private: Utf8String After;
    private: Utf8String Before;
  };
  public: Int32 get_Length();
  public: Utf8String get_Item(Range range);
  public: ByteEnumerable get_Bytes();
  public: CharEnumerable get_Chars();
  public: RuneEnumerable get_Runes();
  public: ReadOnlySpan<Byte> AsBytesSkipNullCheck();
  public: Utf8Span AsSpanSkipNullCheck();
  public: Int32 CompareTo(Utf8String other);
  public: Int32 CompareTo(Utf8String other, StringComparison comparison);
  public: Span<Byte> DangerousGetMutableSpan();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Utf8String value);
  public: Boolean Equals(Utf8String value, StringComparison comparison);
  public: static Boolean Equals(Utf8String left, Utf8String right);
  public: static Boolean Equals(Utf8String a, Utf8String b, StringComparison comparison);
  public: Int32 GetHashCode();
  public: Int32 GetHashCode(StringComparison comparison);
  public: Boolean IsAscii();
  public: static Boolean IsNullOrEmpty(Utf8String value);
  public: static Boolean IsNullOrWhiteSpace(Utf8String value);
  public: Array<Byte> ToByteArray();
  public: String ToString();
  public: static Boolean AreEquivalent(Utf8String utf8Text, String utf16Text);
  public: static Boolean AreEquivalent(Utf8Span utf8Text, ReadOnlySpan<Char> utf16Text);
  public: static Boolean AreEquivalent(ReadOnlySpan<Byte> utf8Text, ReadOnlySpan<Char> utf16Text);
  private: static Boolean AreEquivalentOrdinalSkipShortCircuitingChecks(ReadOnlySpan<Byte> utf8Text, ReadOnlySpan<Char> utf16Text);
  public: Boolean Contains(Char value);
  public: Boolean Contains(Char value, StringComparison comparison);
  public: Boolean Contains(Rune value);
  public: Boolean Contains(Rune value, StringComparison comparison);
  public: Boolean Contains(Utf8String value);
  public: Boolean Contains(Utf8String value, StringComparison comparison);
  public: Boolean EndsWith(Char value);
  public: Boolean EndsWith(Char value, StringComparison comparison);
  public: Boolean EndsWith(Rune value);
  public: Boolean EndsWith(Rune value, StringComparison comparison);
  public: Boolean EndsWith(Utf8String value);
  public: Boolean EndsWith(Utf8String value, StringComparison comparison);
  public: Boolean StartsWith(Char value);
  public: Boolean StartsWith(Char value, StringComparison comparison);
  public: Boolean StartsWith(Rune value);
  public: Boolean StartsWith(Rune value, StringComparison comparison);
  public: Boolean StartsWith(Utf8String value);
  public: Boolean StartsWith(Utf8String value, StringComparison comparison);
  private: Utf8String Ctor(ReadOnlySpan<Byte> value);
  private: Utf8String Ctor(Array<Byte> value, Int32 startIndex, Int32 length);
  private: Utf8String Ctor(Byte* value);
  private: Utf8String Ctor(ReadOnlySpan<Char> value);
  private: Utf8String Ctor(Array<Char> value, Int32 startIndex, Int32 length);
  private: Utf8String Ctor(Char* value);
  private: Utf8String Ctor(String value);
  public: static Boolean TryCreateFrom(ReadOnlySpan<Byte> buffer, Utf8String& value);
  public: static Boolean TryCreateFrom(ReadOnlySpan<Char> buffer, Utf8String& value);
  public: static Utf8String CreateFromRelaxed(ReadOnlySpan<Byte> buffer);
  public: static Utf8String CreateFromRelaxed(ReadOnlySpan<Char> buffer);
  public: static Utf8String CreateFromRune(Rune value);
  private: static Utf8String CreateFromUtf16Common(ReadOnlySpan<Char> value, Boolean replaceInvalidSequences);
  public: static Utf8String UnsafeCreateWithoutValidation(ReadOnlySpan<Byte> utf8Contents);
  private: static Utf8String FastAllocate(Int32 length);
  private: static Utf8String FastAllocateSkipZeroInit(Int32 length);
  public: Boolean IsNormalized(NormalizationForm normalizationForm);
  public: Utf8String Normalize(NormalizationForm normalizationForm);
  public: Array<Char> ToCharArray();
  public: Utf8String ToLower(CultureInfo culture);
  public: Utf8String ToLowerInvariant();
  public: Utf8String ToUpper(CultureInfo culture);
  public: Utf8String ToUpperInvariant();
  public: static void CheckSplitOptions(Utf8StringSplitOptions options);
  private: static void CheckSplitOptions_Throw(Utf8StringSplitOptions options);
  private: Utf8String InternalSubstring(Int32 startIndex, Int32 length);
  public: static void ThrowImproperStringSplit();
  public: Utf8String Substring(Int32 startIndex, Int32 length);
  public: SplitResult Split(Char separator, Utf8StringSplitOptions options);
  public: SplitResult Split(Rune separator, Utf8StringSplitOptions options);
  public: SplitResult Split(Utf8String separator, Utf8StringSplitOptions options);
  public: SplitOnResult SplitOn(Char separator);
  public: SplitOnResult SplitOn(Char separator, StringComparison comparisonType);
  public: SplitOnResult SplitOn(Rune separator);
  public: SplitOnResult SplitOn(Rune separator, StringComparison comparisonType);
  public: SplitOnResult SplitOn(Utf8String separator);
  public: SplitOnResult SplitOn(Utf8String separator, StringComparison comparisonType);
  public: SplitOnResult SplitOnLast(Char separator);
  public: SplitOnResult SplitOnLast(Char separator, StringComparison comparisonType);
  public: SplitOnResult SplitOnLast(Rune separator);
  public: SplitOnResult SplitOnLast(Rune separator, StringComparison comparisonType);
  public: SplitOnResult SplitOnLast(Utf8String separator);
  public: SplitOnResult SplitOnLast(Utf8String separator, StringComparison comparisonType);
  public: Utf8String Trim();
  public: Utf8String TrimEnd();
  private: Utf8String TrimHelper(TrimType trimType);
  public: Utf8String TrimStart();
  private: void ValidateStartIndexAndLength(Int32 startIndex, Int32 length);
  public: Boolean TryFind(Char value, Range& range);
  public: Boolean TryFind(Char value, StringComparison comparisonType, Range& range);
  public: Boolean TryFind(Rune value, Range& range);
  public: Boolean TryFind(Rune value, StringComparison comparisonType, Range& range);
  public: Boolean TryFind(Utf8String value, Range& range);
  public: Boolean TryFind(Utf8String value, StringComparison comparisonType, Range& range);
  public: Boolean TryFindLast(Char value, Range& range);
  public: Boolean TryFindLast(Char value, StringComparison comparisonType, Range& range);
  public: Boolean TryFindLast(Rune value, Range& range);
  public: Boolean TryFindLast(Rune value, StringComparison comparisonType, Range& range);
  public: Boolean TryFindLast(Utf8String value, Range& range);
  public: Boolean TryFindLast(Utf8String value, StringComparison comparisonType, Range& range);
  public: static Utf8String Empty;
  private: Int32 _length;
  private: Byte _firstByte;
};
} // namespace Utf8StringNamespace
using Utf8String = Utf8StringNamespace::Utf8String;
} // namespace System::Private::CoreLib::System
