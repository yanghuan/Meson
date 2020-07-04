#include "Utf8String-dep.h"

#include <System.Private.CoreLib/System/Utf8String-dep.h>

namespace System::Private::CoreLib::System::Utf8StringNamespace {
Object Utf8String___::ByteEnumerable::Enumerator::get_CurrentOfIEnumerator() {
  return nullptr;
};
Boolean Utf8String___::ByteEnumerable::Enumerator::MoveNext() {
  return Boolean();
};
Utf8String::in::ByteEnumerable::Enumerator Utf8String___::ByteEnumerable::GetEnumerator() {
  return Utf8String::in::ByteEnumerable::Enumerator();
};
Char Utf8String___::CharEnumerable::Enumerator::get_Current() {
  return Char();
};
Object Utf8String___::CharEnumerable::Enumerator::get_CurrentOfIEnumerator() {
  return nullptr;
};
Boolean Utf8String___::CharEnumerable::Enumerator::MoveNext() {
  return Boolean();
};
Utf8String::in::CharEnumerable::Enumerator Utf8String___::CharEnumerable::GetEnumerator() {
  return Utf8String::in::CharEnumerable::Enumerator();
};
Rune Utf8String___::RuneEnumerable::Enumerator::get_Current() {
  return Rune();
};
Object Utf8String___::RuneEnumerable::Enumerator::get_CurrentOfIEnumerator() {
  return nullptr;
};
Boolean Utf8String___::RuneEnumerable::Enumerator::MoveNext() {
  return Boolean();
};
Utf8String::in::RuneEnumerable::Enumerator Utf8String___::RuneEnumerable::GetEnumerator() {
  return Utf8String::in::RuneEnumerable::Enumerator();
};
Boolean Utf8String___::SplitResult::State::DeconstructHelper(Utf8Span& source, Utf8Span& firstItem, Utf8Span& remainder) {
  return Boolean();
};
Utf8Span Utf8String___::SplitResult::State::GetRemainingSearchSpace() {
  return Utf8Span();
};
Utf8String Utf8String___::SplitResult::Enumerator::get_Current() {
  return nullptr;
};
Object Utf8String___::SplitResult::Enumerator::get_CurrentOfIEnumerator() {
  return nullptr;
};
Boolean Utf8String___::SplitResult::Enumerator::MoveNext() {
  return Boolean();
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2) {
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3) {
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4) {
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5) {
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5, Utf8String& item6) {
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5, Utf8String& item6, Utf8String& item7) {
};
void Utf8String___::SplitResult::Deconstruct(Utf8String& item1, Utf8String& item2, Utf8String& item3, Utf8String& item4, Utf8String& item5, Utf8String& item6, Utf8String& item7, Utf8String& item8) {
};
Utf8String::in::SplitResult::Enumerator Utf8String___::SplitResult::GetEnumerator() {
  return Utf8String::in::SplitResult::Enumerator();
};
Utf8String Utf8String___::SplitResult::TrimIfNeeded(Utf8Span span) {
  return nullptr;
};
void Utf8String___::SplitOnResult::Deconstruct(Utf8String& before, Utf8String& after) {
};
Int32 Utf8String___::get_Length() {
  return Int32();
};
Utf8String Utf8String___::get_Item(Range range) {
  return nullptr;
};
Utf8String::in::ByteEnumerable Utf8String___::get_Bytes() {
  return Utf8String::in::ByteEnumerable();
};
Utf8String::in::CharEnumerable Utf8String___::get_Chars() {
  return Utf8String::in::CharEnumerable();
};
Utf8String::in::RuneEnumerable Utf8String___::get_Runes() {
  return Utf8String::in::RuneEnumerable();
};
ReadOnlySpan<Byte> Utf8String___::AsBytesSkipNullCheck() {
  return ReadOnlySpan<Byte>();
};
Utf8Span Utf8String___::AsSpanSkipNullCheck() {
  return Utf8Span();
};
Int32 Utf8String___::CompareTo(Utf8String other) {
  return Int32();
};
Int32 Utf8String___::CompareTo(Utf8String other, StringComparison comparison) {
  return Int32();
};
Span<Byte> Utf8String___::DangerousGetMutableSpan() {
  return Span<Byte>();
};
Boolean Utf8String___::Equals(Object obj) {
  return Boolean();
};
Boolean Utf8String___::Equals(Utf8String value) {
  return Boolean();
};
Boolean Utf8String___::Equals(Utf8String value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::Equals(Utf8String left, Utf8String right) {
  return Boolean();
};
Boolean Utf8String___::Equals(Utf8String a, Utf8String b, StringComparison comparison) {
  return Boolean();
};
Int32 Utf8String___::GetHashCode() {
  return Int32();
};
Int32 Utf8String___::GetHashCode(StringComparison comparison) {
  return Int32();
};
Boolean Utf8String___::IsAscii() {
  return Boolean();
};
Boolean Utf8String___::IsNullOrEmpty(Utf8String value) {
  return Boolean();
};
Boolean Utf8String___::IsNullOrWhiteSpace(Utf8String value) {
  return Boolean();
};
Array<Byte> Utf8String___::ToByteArray() {
  return Array<Byte>();
};
String Utf8String___::ToString() {
  return nullptr;
};
Boolean Utf8String___::AreEquivalent(Utf8String utf8Text, String utf16Text) {
  return Boolean();
};
Boolean Utf8String___::AreEquivalent(Utf8Span utf8Text, ReadOnlySpan<Char> utf16Text) {
  return Boolean();
};
Boolean Utf8String___::AreEquivalent(ReadOnlySpan<Byte> utf8Text, ReadOnlySpan<Char> utf16Text) {
  return Boolean();
};
Boolean Utf8String___::AreEquivalentOrdinalSkipShortCircuitingChecks(ReadOnlySpan<Byte> utf8Text, ReadOnlySpan<Char> utf16Text) {
  return Boolean();
};
Boolean Utf8String___::Contains(Char value) {
  return Boolean();
};
Boolean Utf8String___::Contains(Char value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::Contains(Rune value) {
  return Boolean();
};
Boolean Utf8String___::Contains(Rune value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::Contains(Utf8String value) {
  return Boolean();
};
Boolean Utf8String___::Contains(Utf8String value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::EndsWith(Char value) {
  return Boolean();
};
Boolean Utf8String___::EndsWith(Char value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::EndsWith(Rune value) {
  return Boolean();
};
Boolean Utf8String___::EndsWith(Rune value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::EndsWith(Utf8String value) {
  return Boolean();
};
Boolean Utf8String___::EndsWith(Utf8String value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::StartsWith(Char value) {
  return Boolean();
};
Boolean Utf8String___::StartsWith(Char value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::StartsWith(Rune value) {
  return Boolean();
};
Boolean Utf8String___::StartsWith(Rune value, StringComparison comparison) {
  return Boolean();
};
Boolean Utf8String___::StartsWith(Utf8String value) {
  return Boolean();
};
Boolean Utf8String___::StartsWith(Utf8String value, StringComparison comparison) {
  return Boolean();
};
Utf8String Utf8String___::Ctor(ReadOnlySpan<Byte> value) {
  return nullptr;
};
Utf8String Utf8String___::Ctor(Array<Byte> value, Int32 startIndex, Int32 length) {
  return nullptr;
};
Utf8String Utf8String___::Ctor(Byte* value) {
  return nullptr;
};
Utf8String Utf8String___::Ctor(ReadOnlySpan<Char> value) {
  return nullptr;
};
Utf8String Utf8String___::Ctor(Array<Char> value, Int32 startIndex, Int32 length) {
  return nullptr;
};
Utf8String Utf8String___::Ctor(Char* value) {
  return nullptr;
};
Utf8String Utf8String___::Ctor(String value) {
  return nullptr;
};
Boolean Utf8String___::TryCreateFrom(ReadOnlySpan<Byte> buffer, Utf8String& value) {
  return Boolean();
};
Boolean Utf8String___::TryCreateFrom(ReadOnlySpan<Char> buffer, Utf8String& value) {
  return Boolean();
};
Utf8String Utf8String___::CreateFromRelaxed(ReadOnlySpan<Byte> buffer) {
  return nullptr;
};
Utf8String Utf8String___::CreateFromRelaxed(ReadOnlySpan<Char> buffer) {
  return nullptr;
};
Utf8String Utf8String___::CreateFromRune(Rune value) {
  return nullptr;
};
Utf8String Utf8String___::CreateFromUtf16Common(ReadOnlySpan<Char> value, Boolean replaceInvalidSequences) {
  return nullptr;
};
Utf8String Utf8String___::UnsafeCreateWithoutValidation(ReadOnlySpan<Byte> utf8Contents) {
  return nullptr;
};
Utf8String Utf8String___::FastAllocateSkipZeroInit(Int32 length) {
  return nullptr;
};
Boolean Utf8String___::IsNormalized(NormalizationForm normalizationForm) {
  return Boolean();
};
Utf8String Utf8String___::Normalize(NormalizationForm normalizationForm) {
  return nullptr;
};
Array<Char> Utf8String___::ToCharArray() {
  return Array<Char>();
};
Utf8String Utf8String___::ToLower(CultureInfo culture) {
  return nullptr;
};
Utf8String Utf8String___::ToLowerInvariant() {
  return nullptr;
};
Utf8String Utf8String___::ToUpper(CultureInfo culture) {
  return nullptr;
};
Utf8String Utf8String___::ToUpperInvariant() {
  return nullptr;
};
void Utf8String___::CheckSplitOptions(Utf8StringSplitOptions options) {
};
void Utf8String___::CheckSplitOptions_Throw(Utf8StringSplitOptions options) {
};
Utf8String Utf8String___::InternalSubstring(Int32 startIndex, Int32 length) {
  return nullptr;
};
void Utf8String___::ThrowImproperStringSplit() {
};
Utf8String Utf8String___::Substring(Int32 startIndex, Int32 length) {
  return nullptr;
};
Utf8String::in::SplitResult Utf8String___::Split(Char separator, Utf8StringSplitOptions options) {
  return Utf8String::in::SplitResult();
};
Utf8String::in::SplitResult Utf8String___::Split(Rune separator, Utf8StringSplitOptions options) {
  return Utf8String::in::SplitResult();
};
Utf8String::in::SplitResult Utf8String___::Split(Utf8String separator, Utf8StringSplitOptions options) {
  return Utf8String::in::SplitResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOn(Char separator) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOn(Char separator, StringComparison comparisonType) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOn(Rune separator) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOn(Rune separator, StringComparison comparisonType) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOn(Utf8String separator) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOn(Utf8String separator, StringComparison comparisonType) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOnLast(Char separator) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOnLast(Char separator, StringComparison comparisonType) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOnLast(Rune separator) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOnLast(Rune separator, StringComparison comparisonType) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOnLast(Utf8String separator) {
  return Utf8String::in::SplitOnResult();
};
Utf8String::in::SplitOnResult Utf8String___::SplitOnLast(Utf8String separator, StringComparison comparisonType) {
  return Utf8String::in::SplitOnResult();
};
Utf8String Utf8String___::Trim() {
  return nullptr;
};
Utf8String Utf8String___::TrimEnd() {
  return nullptr;
};
Utf8String Utf8String___::TrimHelper(TrimType trimType) {
  return nullptr;
};
Utf8String Utf8String___::TrimStart() {
  return nullptr;
};
void Utf8String___::ValidateStartIndexAndLength(Int32 startIndex, Int32 length) {
};
Boolean Utf8String___::TryFind(Char value, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFind(Char value, StringComparison comparisonType, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFind(Rune value, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFind(Rune value, StringComparison comparisonType, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFind(Utf8String value, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFind(Utf8String value, StringComparison comparisonType, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFindLast(Char value, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFindLast(Char value, StringComparison comparisonType, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFindLast(Rune value, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFindLast(Rune value, StringComparison comparisonType, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFindLast(Utf8String value, Range& range) {
  return Boolean();
};
Boolean Utf8String___::TryFindLast(Utf8String value, StringComparison comparisonType, Range& range) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Utf8StringNamespace
