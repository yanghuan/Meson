#include "CompareInfo-dep.h"

#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>

namespace System::Private::CoreLib::System::Globalization::CompareInfoNamespace {
String CompareInfo___::get_Name() {
  return nullptr;
};
SortVersion CompareInfo___::get_Version() {
  return nullptr;
};
Int32 CompareInfo___::get_LCID() {
  return Int32();
};
CompareInfo CompareInfo___::GetCompareInfo(Int32 culture, Assembly assembly) {
  return nullptr;
};
CompareInfo CompareInfo___::GetCompareInfo(String name, Assembly assembly) {
  return nullptr;
};
CompareInfo CompareInfo___::GetCompareInfo(Int32 culture) {
  return nullptr;
};
CompareInfo CompareInfo___::GetCompareInfo(String name) {
  return nullptr;
};
Boolean CompareInfo___::IsSortable(Char ch) {
  return Boolean();
};
Boolean CompareInfo___::IsSortable(String text) {
  return Boolean();
};
void CompareInfo___::OnDeserializing(StreamingContext ctx) {
  return void();
};
void CompareInfo___::OnDeserialized(StreamingContext ctx) {
  return void();
};
void CompareInfo___::OnDeserialized() {
  return void();
};
void CompareInfo___::OnSerializing(StreamingContext ctx) {
  return void();
};
Int32 CompareInfo___::Compare(String string1, String string2) {
  return Int32();
};
Int32 CompareInfo___::Compare(String string1, String string2, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::Compare(ReadOnlySpan<Char> string1, String string2, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::CompareOptionNone(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2) {
  return Int32();
};
Int32 CompareInfo___::CompareOptionIgnoreCase(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2) {
  return Int32();
};
Int32 CompareInfo___::Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2) {
  return Int32();
};
Int32 CompareInfo___::Compare(String string1, Int32 offset1, String string2, Int32 offset2, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::Compare(String string1, Int32 offset1, String string2, Int32 offset2) {
  return Int32();
};
Int32 CompareInfo___::Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::CompareOrdinalIgnoreCase(String strA, Int32 indexA, Int32 lengthA, String strB, Int32 indexB, Int32 lengthB) {
  return Int32();
};
Int32 CompareInfo___::CompareOrdinalIgnoreCase(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB) {
  return Int32();
};
Int32 CompareInfo___::CompareOrdinalIgnoreCase(String strA, String strB) {
  return Int32();
};
Int32 CompareInfo___::CompareOrdinalIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  return Int32();
};
Boolean CompareInfo___::EqualsOrdinalIgnoreCase(Char& charA, Char& charB, Int32 length) {
  return Boolean();
};
Boolean CompareInfo___::EqualsOrdinalIgnoreCaseNonAscii(Char& charA, Char& charB, Int32 length) {
  return Boolean();
};
Boolean CompareInfo___::IsPrefix(String source, String prefix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::IsPrefix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::IsPrefix(String source, String prefix) {
  return Boolean();
};
Boolean CompareInfo___::IsSuffix(String source, String suffix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::IsSuffix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::IsSuffix(String source, String suffix) {
  return Boolean();
};
Int32 CompareInfo___::IndexOf(String source, Char value) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, Char value, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOfOrdinal(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options, Int32* matchLengthPtr) {
  return Int32();
};
Int32 CompareInfo___::IndexOfOrdinal(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, Char value) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, String value) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, Char value, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, String value, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOfOrdinal(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  return Int32();
};
SortKey CompareInfo___::GetSortKey(String source, CompareOptions options) {
  return nullptr;
};
SortKey CompareInfo___::GetSortKey(String source) {
  return nullptr;
};
Boolean CompareInfo___::Equals(Object value) {
  return Boolean();
};
Int32 CompareInfo___::GetHashCode() {
  return Int32();
};
Int32 CompareInfo___::GetHashCodeOfString(String source, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::GetHashCode(String source, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::GetHashCode(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
};
String CompareInfo___::ToString() {
  return nullptr;
};
Int32 CompareInfo___::InvariantIndexOf(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  return Int32();
};
Int32 CompareInfo___::InvariantIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
};
Int32 CompareInfo___::InvariantLastIndexOf(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  return Int32();
};
Int32 CompareInfo___::InvariantFindString(Char* source, Int32 sourceCount, Char* value, Int32 valueCount, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
};
Char CompareInfo___::InvariantToUpper(Char c) {
  return Char();
};
SortKey CompareInfo___::InvariantCreateSortKey(String source, CompareOptions options) {
  return nullptr;
};
IntPtr CompareInfo___::GetSortHandle(String cultureName) {
  return IntPtr();
};
void CompareInfo___::InitSort(CultureInfo culture) {
  return void();
};
Int32 CompareInfo___::FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, String stringSource, Int32 offset, Int32 cchSource, String value, Int32 cchValue, Boolean bIgnoreCase) {
  return Int32();
};
Int32 CompareInfo___::FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean bIgnoreCase) {
  return Int32();
};
Int32 CompareInfo___::IndexOfOrdinalCore(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  return Int32();
};
Int32 CompareInfo___::IndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOfOrdinalCore(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  return Int32();
};
Int32 CompareInfo___::GetHashCodeOfStringCore(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::CompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  return Int32();
};
Int32 CompareInfo___::CompareString(ReadOnlySpan<Char> string1, String string2, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::CompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  return Int32();
};
Int32 CompareInfo___::FindString(UInt32 dwFindNLSStringFlags, ReadOnlySpan<Char> lpStringSource, ReadOnlySpan<Char> lpStringValue, Int32* pcchFound) {
  return Int32();
};
Int32 CompareInfo___::FindString(UInt32 dwFindNLSStringFlags, String lpStringSource, Int32 startSource, Int32 cchSource, String lpStringValue, Int32 startValue, Int32 cchValue, Int32* pcchFound) {
  return Int32();
};
Int32 CompareInfo___::IndexOfCore(String source, String target, Int32 startIndex, Int32 count, CompareOptions options, Int32* matchLengthPtr) {
  return Int32();
};
Int32 CompareInfo___::IndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  return Int32();
};
Int32 CompareInfo___::LastIndexOfCore(String source, String target, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
};
Boolean CompareInfo___::StartsWith(String source, String prefix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::StartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::EndsWith(String source, String suffix, CompareOptions options) {
  return Boolean();
};
Boolean CompareInfo___::EndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
};
Int32 CompareInfo___::FastLastIndexOfString(String source, String target, Int32 startIndex, Int32 sourceCount, Int32 targetCount) {
  return Int32();
};
SortKey CompareInfo___::CreateSortKey(String source, CompareOptions options) {
  return nullptr;
};
Boolean CompareInfo___::IsSortable(Char* text, Int32 length) {
  return Boolean();
};
Int32 CompareInfo___::GetNativeCompareFlags(CompareOptions options) {
  return Int32();
};
SortVersion CompareInfo___::GetSortVersion() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Globalization::CompareInfoNamespace
