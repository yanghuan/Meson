#include "String-dep.h"

#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::StringNamespace {
String String___::Intern(String str) {
  return nullptr;
};
String String___::IsInterned(String str) {
  return nullptr;
};
void String___::InternalCopy(String src, IntPtr dest, Int32 len) {
};
Int32 String___::GetBytesFromEncoding(Byte* pbNativeBuffer, Int32 cbNativeBuffer, Encoding encoding) {
  return Int32();
};
Boolean String___::EqualsHelper(String strA, String strB) {
  return Boolean();
};
Int32 String___::CompareOrdinalHelper(String strA, Int32 indexA, Int32 countA, String strB, Int32 indexB, Int32 countB) {
  return Int32();
};
Boolean String___::EqualsOrdinalIgnoreCase(String strA, String strB) {
  return Boolean();
};
Int32 String___::CompareOrdinalHelper(String strA, String strB) {
  return Int32();
};
Int32 String___::Compare(String strA, String strB) {
  return Int32();
};
Int32 String___::Compare(String strA, String strB, Boolean ignoreCase) {
  return Int32();
};
Int32 String___::Compare(String strA, String strB, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::Compare(String strA, String strB, CultureInfo culture, CompareOptions options) {
  return Int32();
};
Int32 String___::Compare(String strA, String strB, Boolean ignoreCase, CultureInfo culture) {
  return Int32();
};
Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length) {
  return Int32();
};
Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, Boolean ignoreCase) {
  return Int32();
};
Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, Boolean ignoreCase, CultureInfo culture) {
  return Int32();
};
Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, CultureInfo culture, CompareOptions options) {
  return Int32();
};
Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::CompareOrdinal(String strA, String strB) {
  return Int32();
};
Int32 String___::CompareOrdinal(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB) {
  return Int32();
};
Int32 String___::CompareOrdinal(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length) {
  return Int32();
};
Int32 String___::CompareTo(Object value) {
  return Int32();
};
Int32 String___::CompareTo(String strB) {
  return Int32();
};
Boolean String___::EndsWith(String value) {
  return Boolean();
};
Boolean String___::EndsWith(String value, StringComparison comparisonType) {
  return Boolean();
};
Boolean String___::EndsWith(String value, Boolean ignoreCase, CultureInfo culture) {
  return Boolean();
};
Boolean String___::EndsWith(Char value) {
  return Boolean();
};
Boolean String___::Equals(Object obj) {
  return Boolean();
};
Boolean String___::Equals(String value) {
  return Boolean();
};
Boolean String___::Equals(String value, StringComparison comparisonType) {
  return Boolean();
};
Boolean String___::Equals(String a, String b) {
  return Boolean();
};
Boolean String___::Equals(String a, String b, StringComparison comparisonType) {
  return Boolean();
};
Int32 String___::GetHashCode() {
  return Int32();
};
Int32 String___::GetHashCode(StringComparison comparisonType) {
  return Int32();
};
Int32 String___::GetHashCodeOrdinalIgnoreCase() {
  return Int32();
};
Int32 String___::GetHashCode(ReadOnlySpan<Char> value) {
  return Int32();
};
Int32 String___::GetHashCode(ReadOnlySpan<Char> value, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::GetHashCodeOrdinalIgnoreCase(ReadOnlySpan<Char> value) {
  return Int32();
};
Int32 String___::GetNonRandomizedHashCode() {
  return Int32();
};
Boolean String___::StartsWith(String value) {
  return Boolean();
};
Boolean String___::StartsWith(String value, StringComparison comparisonType) {
  return Boolean();
};
Boolean String___::StartsWith(String value, Boolean ignoreCase, CultureInfo culture) {
  return Boolean();
};
Boolean String___::StartsWith(Char value) {
  return Boolean();
};
void String___::CheckStringComparison(StringComparison comparisonType) {
};
CompareOptions String___::GetCaseCompareOfComparisonCulture(StringComparison comparisonType) {
  return CompareOptions::Ordinal;
};
String String___::Ctor(Array<Char> value) {
  return nullptr;
};
String String___::Ctor(Array<Char> value, Int32 startIndex, Int32 length) {
  return nullptr;
};
String String___::Ctor(Char* ptr) {
  return nullptr;
};
String String___::Ctor(Char* ptr, Int32 startIndex, Int32 length) {
  return nullptr;
};
String String___::Ctor(SByte* value) {
  return nullptr;
};
String String___::Ctor(SByte* value, Int32 startIndex, Int32 length) {
  return nullptr;
};
String String___::CreateStringForSByteConstructor(Byte* pb, Int32 numBytes) {
  return nullptr;
};
String String___::Ctor(SByte* value, Int32 startIndex, Int32 length, Encoding enc) {
  return nullptr;
};
String String___::Ctor(Char c, Int32 count) {
  return nullptr;
};
String String___::Ctor(ReadOnlySpan<Char> value) {
  return nullptr;
};
Object String___::Clone() {
  return nullptr;
};
String String___::Copy(String str) {
  return nullptr;
};
void String___::CopyTo(Int32 sourceIndex, Array<Char> destination, Int32 destinationIndex, Int32 count) {
};
Array<Char> String___::ToCharArray() {
  return Array<Char>();
};
Array<Char> String___::ToCharArray(Int32 startIndex, Int32 length) {
  return Array<Char>();
};
Boolean String___::IsNullOrEmpty(String value) {
  return Boolean();
};
Boolean String___::IsNullOrWhiteSpace(String value) {
  return Boolean();
};
String String___::CreateStringFromEncoding(Byte* bytes, Int32 byteLength, Encoding encoding) {
  return nullptr;
};
String String___::CreateFromChar(Char c) {
  return nullptr;
};
String String___::CreateFromChar(Char c1, Char c2) {
  return nullptr;
};
void String___::wstrcpy(Char* dmem, Char* smem, Int32 charCount) {
};
String String___::ToString() {
  return nullptr;
};
String String___::ToString(IFormatProvider provider) {
  return nullptr;
};
CharEnumerator String___::GetEnumerator() {
  return nullptr;
};
StringRuneEnumerator String___::EnumerateRunes() {
  return StringRuneEnumerator();
};
Int32 String___::wcslen(Char* ptr) {
  return Int32();
};
Int32 String___::strlen(Byte* ptr) {
  return Int32();
};
void String___::ThrowMustBeNullTerminatedString() {
};
TypeCode String___::GetTypeCode() {
  return TypeCode::String;
};
Boolean String___::IsNormalized() {
  return Boolean();
};
Boolean String___::IsNormalized(NormalizationForm normalizationForm) {
  return Boolean();
};
String String___::Normalize() {
  return nullptr;
};
String String___::Normalize(NormalizationForm normalizationForm) {
  return nullptr;
};
Boolean String___::IsAscii() {
  return Boolean();
};
void String___::FillStringChecked(String dest, Int32 destPos, String src) {
};
String String___::Concat(Object arg0) {
  return nullptr;
};
String String___::Concat(Object arg0, Object arg1) {
  return nullptr;
};
String String___::Concat(Object arg0, Object arg1, Object arg2) {
  return nullptr;
};
String String___::Concat(Array<Object> args) {
  return nullptr;
};
String String___::Concat(IEnumerable<String> values) {
  return nullptr;
};
String String___::Concat(String str0, String str1) {
  return nullptr;
};
String String___::Concat(String str0, String str1, String str2) {
  return nullptr;
};
String String___::Concat(String str0, String str1, String str2, String str3) {
  return nullptr;
};
String String___::Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1) {
  return nullptr;
};
String String___::Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1, ReadOnlySpan<Char> str2) {
  return nullptr;
};
String String___::Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1, ReadOnlySpan<Char> str2, ReadOnlySpan<Char> str3) {
  return nullptr;
};
String String___::Concat(Array<String> values) {
  return nullptr;
};
String String___::Format(String format, Object arg0) {
  return nullptr;
};
String String___::Format(String format, Object arg0, Object arg1) {
  return nullptr;
};
String String___::Format(String format, Object arg0, Object arg1, Object arg2) {
  return nullptr;
};
String String___::Format(String format, Array<Object> args) {
  return nullptr;
};
String String___::Format(IFormatProvider provider, String format, Object arg0) {
  return nullptr;
};
String String___::Format(IFormatProvider provider, String format, Object arg0, Object arg1) {
  return nullptr;
};
String String___::Format(IFormatProvider provider, String format, Object arg0, Object arg1, Object arg2) {
  return nullptr;
};
String String___::Format(IFormatProvider provider, String format, Array<Object> args) {
  return nullptr;
};
String String___::FormatHelper(IFormatProvider provider, String format, ParamsArray args) {
  return nullptr;
};
String String___::Insert(Int32 startIndex, String value) {
  return nullptr;
};
String String___::Join(Char separator, Array<String> value) {
  return nullptr;
};
String String___::Join(Char separator, Array<Object> values) {
  return nullptr;
};
String String___::Join(Char separator, Array<String> value, Int32 startIndex, Int32 count) {
  return nullptr;
};
String String___::Join(String separator, Array<String> value) {
  return nullptr;
};
String String___::Join(String separator, Array<Object> values) {
  return nullptr;
};
String String___::Join(String separator, IEnumerable<String> values) {
  return nullptr;
};
String String___::Join(String separator, Array<String> value, Int32 startIndex, Int32 count) {
  return nullptr;
};
String String___::JoinCore(Char* separator, Int32 separatorLength, Array<Object> values) {
  return nullptr;
};
String String___::JoinCore(Char* separator, Int32 separatorLength, Array<String> value, Int32 startIndex, Int32 count) {
  return nullptr;
};
String String___::PadLeft(Int32 totalWidth) {
  return nullptr;
};
String String___::PadLeft(Int32 totalWidth, Char paddingChar) {
  return nullptr;
};
String String___::PadRight(Int32 totalWidth) {
  return nullptr;
};
String String___::PadRight(Int32 totalWidth, Char paddingChar) {
  return nullptr;
};
String String___::Remove(Int32 startIndex, Int32 count) {
  return nullptr;
};
String String___::Remove(Int32 startIndex) {
  return nullptr;
};
String String___::Replace(String oldValue, String newValue, Boolean ignoreCase, CultureInfo culture) {
  return nullptr;
};
String String___::Replace(String oldValue, String newValue, StringComparison comparisonType) {
  return nullptr;
};
String String___::ReplaceCore(String oldValue, String newValue, CultureInfo culture, CompareOptions options) {
  return nullptr;
};
String String___::Replace(Char oldChar, Char newChar) {
  return nullptr;
};
String String___::Replace(String oldValue, String newValue) {
  return nullptr;
};
String String___::ReplaceHelper(Int32 oldValueLength, String newValue, ReadOnlySpan<Int32> indices) {
  return nullptr;
};
Array<String> String___::Split(Char separator, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(Char separator, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(Array<Char> separator) {
  return Array<String>();
};
Array<String> String___::Split(Array<Char> separator, Int32 count) {
  return Array<String>();
};
Array<String> String___::Split(Array<Char> separator, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(Array<Char> separator, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::SplitInternal(ReadOnlySpan<Char> separators, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(String separator, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(String separator, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(Array<String> separator, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::Split(Array<String> separator, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::SplitInternal(String separator, Array<String> separators, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::SplitInternal(String separator, Int32 count, StringSplitOptions options) {
  return Array<String>();
};
Array<String> String___::SplitKeepEmptyEntries(ReadOnlySpan<Int32> sepList, ReadOnlySpan<Int32> lengthList, Int32 defaultLength, Int32 count) {
  return Array<String>();
};
Array<String> String___::SplitOmitEmptyEntries(ReadOnlySpan<Int32> sepList, ReadOnlySpan<Int32> lengthList, Int32 defaultLength, Int32 count) {
  return Array<String>();
};
void String___::MakeSeparatorList(ReadOnlySpan<Char> separators, ValueListBuilder<Int32>& sepListBuilder) {
};
void String___::MakeSeparatorList(String separator, ValueListBuilder<Int32>& sepListBuilder) {
};
void String___::MakeSeparatorList(Array<String> separators, ValueListBuilder<Int32>& sepListBuilder, ValueListBuilder<Int32>& lengthListBuilder) {
};
String String___::Substring(Int32 startIndex) {
  return nullptr;
};
String String___::Substring(Int32 startIndex, Int32 length) {
  return nullptr;
};
String String___::InternalSubString(Int32 startIndex, Int32 length) {
  return nullptr;
};
String String___::ToLower() {
  return nullptr;
};
String String___::ToLower(CultureInfo culture) {
  return nullptr;
};
String String___::ToLowerInvariant() {
  return nullptr;
};
String String___::ToUpper() {
  return nullptr;
};
String String___::ToUpper(CultureInfo culture) {
  return nullptr;
};
String String___::ToUpperInvariant() {
  return nullptr;
};
String String___::Trim() {
  return nullptr;
};
String String___::Trim(Char trimChar) {
  return nullptr;
};
String String___::Trim(Array<Char> trimChars) {
  return nullptr;
};
String String___::TrimStart() {
  return nullptr;
};
String String___::TrimStart(Char trimChar) {
  return nullptr;
};
String String___::TrimStart(Array<Char> trimChars) {
  return nullptr;
};
String String___::TrimEnd() {
  return nullptr;
};
String String___::TrimEnd(Char trimChar) {
  return nullptr;
};
String String___::TrimEnd(Array<Char> trimChars) {
  return nullptr;
};
String String___::TrimWhiteSpaceHelper(TrimType trimType) {
  return nullptr;
};
String String___::TrimHelper(Char* trimChars, Int32 trimCharsLength, TrimType trimType) {
  return nullptr;
};
String String___::CreateTrimmedString(Int32 start, Int32 end) {
  return nullptr;
};
Boolean String___::Contains(String value) {
  return Boolean();
};
Boolean String___::Contains(String value, StringComparison comparisonType) {
  return Boolean();
};
Boolean String___::Contains(Char value) {
  return Boolean();
};
Boolean String___::Contains(Char value, StringComparison comparisonType) {
  return Boolean();
};
Int32 String___::IndexOf(Char value) {
  return Int32();
};
Int32 String___::IndexOf(Char value, Int32 startIndex) {
  return Int32();
};
Int32 String___::IndexOf(Char value, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::IndexOf(Char value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::IndexOfAny(Array<Char> anyOf) {
  return Int32();
};
Int32 String___::IndexOfAny(Array<Char> anyOf, Int32 startIndex) {
  return Int32();
};
Int32 String___::IndexOfAny(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::IndexOfCharArray(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  return Int32();
};
void String___::InitializeProbabilisticMap(UInt32* charMap, ReadOnlySpan<Char> anyOf) {
};
Boolean String___::ArrayContains(Char searchChar, Array<Char> anyOf) {
  return Boolean();
};
Boolean String___::IsCharBitSet(UInt32* charMap, Byte value) {
  return Boolean();
};
void String___::SetCharBit(UInt32* charMap, Byte value) {
};
Int32 String___::IndexOf(String value) {
  return Int32();
};
Int32 String___::IndexOf(String value, Int32 startIndex) {
  return Int32();
};
Int32 String___::IndexOf(String value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::IndexOf(String value, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::IndexOf(String value, Int32 startIndex, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::IndexOf(String value, Int32 startIndex, Int32 count, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::LastIndexOf(Char value) {
  return Int32();
};
Int32 String___::LastIndexOf(Char value, Int32 startIndex) {
  return Int32();
};
Int32 String___::LastIndexOf(Char value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::LastIndexOfAny(Array<Char> anyOf) {
  return Int32();
};
Int32 String___::LastIndexOfAny(Array<Char> anyOf, Int32 startIndex) {
  return Int32();
};
Int32 String___::LastIndexOfAny(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::LastIndexOfCharArray(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::LastIndexOf(String value) {
  return Int32();
};
Int32 String___::LastIndexOf(String value, Int32 startIndex) {
  return Int32();
};
Int32 String___::LastIndexOf(String value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 String___::LastIndexOf(String value, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::LastIndexOf(String value, Int32 startIndex, StringComparison comparisonType) {
  return Int32();
};
Int32 String___::LastIndexOf(String value, Int32 startIndex, Int32 count, StringComparison comparisonType) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::StringNamespace
