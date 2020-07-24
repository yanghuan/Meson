#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Double)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class UnicodeCategory;
FORWARD(CultureInfo)
FORWARD(TextInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text {
namespace RuneNamespace {
using namespace Buffers;
using namespace Globalization;
struct Rune : public rt::ValueType<Rune> {
  private: static ReadOnlySpan<Byte> get_AsciiCharInfo();
  private: String get_DebuggerDisplay();
  public: Boolean get_IsAscii();
  public: Boolean get_IsBmp();
  public: Int32 get_Plane();
  public: static Rune get_ReplacementChar();
  public: Int32 get_Utf16SequenceLength();
  public: Int32 get_Utf8SequenceLength();
  public: Int32 get_Value();
  public: explicit Rune(Char ch);
  public: explicit Rune(Char highSurrogate, Char lowSurrogate);
  public: explicit Rune(Int32 value);
  public: explicit Rune(UInt32 value);
  private: explicit Rune(UInt32 scalarValue, Boolean unused);
  public: static Boolean op_Equality(Rune left, Rune right);
  public: static Boolean op_Inequality(Rune left, Rune right);
  public: static Boolean op_LessThan(Rune left, Rune right);
  public: static Boolean op_LessThanOrEqual(Rune left, Rune right);
  public: static Boolean op_GreaterThan(Rune left, Rune right);
  public: static Boolean op_GreaterThanOrEqual(Rune left, Rune right);
  public: static Rune op_Explicit(Char ch);
  public: static Rune op_Explicit(UInt32 value);
  public: static Rune op_Explicit(Int32 value);
  private: static Rune ChangeCaseCultureAware(Rune rune, TextInfo textInfo, Boolean toUpper);
  public: Int32 CompareTo(Rune other);
  public: static OperationStatus DecodeFromUtf16(ReadOnlySpan<Char> source, Rune& result, Int32& charsConsumed);
  public: static OperationStatus DecodeFromUtf8(ReadOnlySpan<Byte> source, Rune& result, Int32& bytesConsumed);
  public: static OperationStatus DecodeLastFromUtf16(ReadOnlySpan<Char> source, Rune& result, Int32& charsConsumed);
  public: static OperationStatus DecodeLastFromUtf8(ReadOnlySpan<Byte> source, Rune& value, Int32& bytesConsumed);
  public: Int32 EncodeToUtf16(Span<Char> destination);
  public: Int32 EncodeToUtf8(Span<Byte> destination);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Rune other);
  public: Int32 GetHashCode();
  public: static Rune GetRuneAt(String input, Int32 index);
  public: static Boolean IsValid(Int32 value);
  public: static Boolean IsValid(UInt32 value);
  public: static Int32 ReadFirstRuneFromUtf16Buffer(ReadOnlySpan<Char> input);
  private: static Int32 ReadRuneFromString(String input, Int32 index);
  public: String ToString();
  public: static Boolean TryCreate(Char ch, Rune& result);
  public: static Boolean TryCreate(Char highSurrogate, Char lowSurrogate, Rune& result);
  public: static Boolean TryCreate(Int32 value, Rune& result);
  public: static Boolean TryCreate(UInt32 value, Rune& result);
  public: Boolean TryEncodeToUtf16(Span<Char> destination, Int32& charsWritten);
  public: Boolean TryEncodeToUtf8(Span<Byte> destination, Int32& bytesWritten);
  public: static Boolean TryGetRuneAt(String input, Int32 index, Rune& value);
  public: static Rune UnsafeCreate(UInt32 scalarValue);
  public: static Double GetNumericValue(Rune value);
  public: static UnicodeCategory GetUnicodeCategory(Rune value);
  private: static UnicodeCategory GetUnicodeCategoryNonAscii(Rune value);
  private: static Boolean IsCategoryLetter(UnicodeCategory category);
  private: static Boolean IsCategoryLetterOrDecimalDigit(UnicodeCategory category);
  private: static Boolean IsCategoryNumber(UnicodeCategory category);
  private: static Boolean IsCategoryPunctuation(UnicodeCategory category);
  private: static Boolean IsCategorySeparator(UnicodeCategory category);
  private: static Boolean IsCategorySymbol(UnicodeCategory category);
  public: static Boolean IsControl(Rune value);
  public: static Boolean IsDigit(Rune value);
  public: static Boolean IsLetter(Rune value);
  public: static Boolean IsLetterOrDigit(Rune value);
  public: static Boolean IsLower(Rune value);
  public: static Boolean IsNumber(Rune value);
  public: static Boolean IsPunctuation(Rune value);
  public: static Boolean IsSeparator(Rune value);
  public: static Boolean IsSymbol(Rune value);
  public: static Boolean IsUpper(Rune value);
  public: static Boolean IsWhiteSpace(Rune value);
  public: static Rune ToLower(Rune value, CultureInfo culture);
  public: static Rune ToLowerInvariant(Rune value);
  public: static Rune ToUpper(Rune value, CultureInfo culture);
  public: static Rune ToUpperInvariant(Rune value);
  public: explicit Rune() {}
  private: UInt32 _value;
};
} // namespace RuneNamespace
using Rune = RuneNamespace::Rune;
} // namespace System::Private::CoreLib::System::Text
