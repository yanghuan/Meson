#include "Rune-dep.h"

#include <System.Private.CoreLib/System/Text/Rune-dep.h>

namespace System::Private::CoreLib::System::Text::RuneNamespace {
ReadOnlySpan<Byte> Rune::get_AsciiCharInfo() {
  return ReadOnlySpan<Byte>();
};

String Rune::get_DebuggerDisplay() {
  return nullptr;
};

Boolean Rune::get_IsAscii() {
  return Boolean();
};

Boolean Rune::get_IsBmp() {
  return Boolean();
};

Int32 Rune::get_Plane() {
  return Int32();
};

Rune Rune::get_ReplacementChar() {
  return Rune();
};

Int32 Rune::get_Utf16SequenceLength() {
  return Int32();
};

Int32 Rune::get_Utf8SequenceLength() {
  return Int32();
};

Int32 Rune::get_Value() {
  return Int32();
};

void Rune::Ctor(Char ch) {
};

void Rune::Ctor(Char highSurrogate, Char lowSurrogate) {
};

void Rune::Ctor(Int32 value) {
};

void Rune::Ctor(UInt32 value) {
};

void Rune::Ctor(UInt32 scalarValue, Boolean unused) {
};

Boolean Rune::op_Equality(Rune left, Rune right) {
  return Boolean();
};

Boolean Rune::op_Inequality(Rune left, Rune right) {
  return Boolean();
};

Boolean Rune::op_LessThan(Rune left, Rune right) {
  return Boolean();
};

Boolean Rune::op_LessThanOrEqual(Rune left, Rune right) {
  return Boolean();
};

Boolean Rune::op_GreaterThan(Rune left, Rune right) {
  return Boolean();
};

Boolean Rune::op_GreaterThanOrEqual(Rune left, Rune right) {
  return Boolean();
};

Rune Rune::op_Explicit(Char ch) {
  return Rune();
};

Rune Rune::op_Explicit(UInt32 value) {
  return Rune();
};

Rune Rune::op_Explicit(Int32 value) {
  return Rune();
};

Rune Rune::ChangeCaseCultureAware(Rune rune, TextInfo textInfo, Boolean toUpper) {
  return Rune();
};

Int32 Rune::CompareTo(Rune other) {
  return Int32();
};

OperationStatus Rune::DecodeFromUtf16(ReadOnlySpan<Char> source, Rune& result, Int32& charsConsumed) {
  return OperationStatus::InvalidData;
};

OperationStatus Rune::DecodeFromUtf8(ReadOnlySpan<Byte> source, Rune& result, Int32& bytesConsumed) {
  return OperationStatus::InvalidData;
};

OperationStatus Rune::DecodeLastFromUtf16(ReadOnlySpan<Char> source, Rune& result, Int32& charsConsumed) {
  return OperationStatus::InvalidData;
};

OperationStatus Rune::DecodeLastFromUtf8(ReadOnlySpan<Byte> source, Rune& value, Int32& bytesConsumed) {
  return OperationStatus::InvalidData;
};

Int32 Rune::EncodeToUtf16(Span<Char> destination) {
  return Int32();
};

Int32 Rune::EncodeToUtf8(Span<Byte> destination) {
  return Int32();
};

Boolean Rune::Equals(Object obj) {
  return Boolean();
};

Boolean Rune::Equals(Rune other) {
  return Boolean();
};

Int32 Rune::GetHashCode() {
  return Int32();
};

Rune Rune::GetRuneAt(String input, Int32 index) {
  return Rune();
};

Boolean Rune::IsValid(Int32 value) {
  return Boolean();
};

Boolean Rune::IsValid(UInt32 value) {
  return Boolean();
};

Int32 Rune::ReadFirstRuneFromUtf16Buffer(ReadOnlySpan<Char> input) {
  return Int32();
};

Int32 Rune::ReadRuneFromString(String input, Int32 index) {
  return Int32();
};

String Rune::ToString() {
  return nullptr;
};

Boolean Rune::TryCreate(Char ch, Rune& result) {
  return Boolean();
};

Boolean Rune::TryCreate(Char highSurrogate, Char lowSurrogate, Rune& result) {
  return Boolean();
};

Boolean Rune::TryCreate(Int32 value, Rune& result) {
  return Boolean();
};

Boolean Rune::TryCreate(UInt32 value, Rune& result) {
  return Boolean();
};

Boolean Rune::TryEncodeToUtf16(Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};

Boolean Rune::TryEncodeToUtf8(Span<Byte> destination, Int32& bytesWritten) {
  return Boolean();
};

Boolean Rune::TryGetRuneAt(String input, Int32 index, Rune& value) {
  return Boolean();
};

Rune Rune::UnsafeCreate(UInt32 scalarValue) {
  return Rune();
};

Double Rune::GetNumericValue(Rune value) {
  return Double();
};

UnicodeCategory Rune::GetUnicodeCategory(Rune value) {
  return UnicodeCategory::OtherNotAssigned;
};

UnicodeCategory Rune::GetUnicodeCategoryNonAscii(Rune value) {
  return UnicodeCategory::OtherNotAssigned;
};

Boolean Rune::IsCategoryLetter(UnicodeCategory category) {
  return Boolean();
};

Boolean Rune::IsCategoryLetterOrDecimalDigit(UnicodeCategory category) {
  return Boolean();
};

Boolean Rune::IsCategoryNumber(UnicodeCategory category) {
  return Boolean();
};

Boolean Rune::IsCategoryPunctuation(UnicodeCategory category) {
  return Boolean();
};

Boolean Rune::IsCategorySeparator(UnicodeCategory category) {
  return Boolean();
};

Boolean Rune::IsCategorySymbol(UnicodeCategory category) {
  return Boolean();
};

Boolean Rune::IsControl(Rune value) {
  return Boolean();
};

Boolean Rune::IsDigit(Rune value) {
  return Boolean();
};

Boolean Rune::IsLetter(Rune value) {
  return Boolean();
};

Boolean Rune::IsLetterOrDigit(Rune value) {
  return Boolean();
};

Boolean Rune::IsLower(Rune value) {
  return Boolean();
};

Boolean Rune::IsNumber(Rune value) {
  return Boolean();
};

Boolean Rune::IsPunctuation(Rune value) {
  return Boolean();
};

Boolean Rune::IsSeparator(Rune value) {
  return Boolean();
};

Boolean Rune::IsSymbol(Rune value) {
  return Boolean();
};

Boolean Rune::IsUpper(Rune value) {
  return Boolean();
};

Boolean Rune::IsWhiteSpace(Rune value) {
  return Boolean();
};

Rune Rune::ToLower(Rune value, CultureInfo culture) {
  return Rune();
};

Rune Rune::ToLowerInvariant(Rune value) {
  return Rune();
};

Rune Rune::ToUpper(Rune value, CultureInfo culture) {
  return Rune();
};

Rune Rune::ToUpperInvariant(Rune value) {
  return Rune();
};

} // namespace System::Private::CoreLib::System::Text::RuneNamespace
