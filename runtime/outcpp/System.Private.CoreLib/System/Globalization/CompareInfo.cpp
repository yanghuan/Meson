#include "CompareInfo-dep.h"

#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>

namespace System::Private::CoreLib::System::Globalization::CompareInfoNamespace {
IntPtr CompareInfo___::SortHandleCache::GetCachedSortHandle(String sortName) {
  return IntPtr();
}

void CompareInfo___::SortHandleCache::ctor_static() {
}

String CompareInfo___::get_Name() {
  return nullptr;
}

SortVersion CompareInfo___::get_Version() {
  return nullptr;
}

Int32 CompareInfo___::get_LCID() {
  return Int32();
}

ReadOnlySpan<Boolean> CompareInfo___::get_HighCharTable() {
  return ReadOnlySpan<Boolean>();
}

void CompareInfo___::ctor(CultureInfo culture) {
}

CompareInfo CompareInfo___::GetCompareInfo(Int32 culture, Assembly assembly) {
  return nullptr;
}

CompareInfo CompareInfo___::GetCompareInfo(String name, Assembly assembly) {
  return nullptr;
}

CompareInfo CompareInfo___::GetCompareInfo(Int32 culture) {
  return nullptr;
}

CompareInfo CompareInfo___::GetCompareInfo(String name) {
  return nullptr;
}

Boolean CompareInfo___::IsSortable(Char ch) {
  return Boolean();
}

Boolean CompareInfo___::IsSortable(String text) {
  return Boolean();
}

Boolean CompareInfo___::IsSortable(ReadOnlySpan<Char> text) {
  return Boolean();
}

Boolean CompareInfo___::IsSortable(Rune value) {
  return Boolean();
}

void CompareInfo___::InitSort(CultureInfo culture) {
}

void CompareInfo___::OnDeserializing(StreamingContext ctx) {
}

void CompareInfo___::OnDeserialized(StreamingContext ctx) {
}

void CompareInfo___::OnDeserialized() {
}

void CompareInfo___::OnSerializing(StreamingContext ctx) {
}

Int32 CompareInfo___::Compare(String string1, String string2) {
  return Int32();
}

Int32 CompareInfo___::Compare(String string1, String string2, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::CompareOptionIgnoreCase(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2) {
  return Int32();
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2) {
  return Int32();
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, String string2, Int32 offset2, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, String string2, Int32 offset2) {
  return Int32();
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::Compare(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  return Int32();
}

void CompareInfo___::CheckCompareOptionsForCompare(CompareOptions options) {
}

void CompareInfo___::ThrowCompareOptionsCheckFailed(CompareOptions options) {
}

Int32 CompareInfo___::CompareStringCore(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(String strA, Int32 indexA, Int32 lengthA, String strB, Int32 indexB, Int32 lengthB) {
  return Int32();
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB) {
  return Int32();
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(String strA, String strB) {
  return Int32();
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  return Int32();
}

Boolean CompareInfo___::EqualsOrdinalIgnoreCase(Char& charA, Char& charB, Int32 length) {
  return Boolean();
}

Boolean CompareInfo___::EqualsOrdinalIgnoreCaseNonAscii(Char& charA, Char& charB, Int32 length) {
  return Boolean();
}

Int32 CompareInfo___::CompareStringOrdinalIgnoreCaseCore(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  return Int32();
}

Boolean CompareInfo___::IsPrefix(String source, String prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::IsPrefix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::StartsWithCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::IsPrefix(String source, String prefix) {
  return Boolean();
}

Boolean CompareInfo___::IsSuffix(String source, String suffix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::IsSuffix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::IsSuffix(String source, String suffix) {
  return Boolean();
}

Boolean CompareInfo___::EndsWithCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
}

Int32 CompareInfo___::IndexOf(String source, Char value) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, String value) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, Char value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, String value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, Int32 count) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, Rune value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Int32* matchLengthPtr, CompareOptions options, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::IndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, Char value) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, String value) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, String value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, Int32 count) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, Int32 count) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::LastIndexOf(ReadOnlySpan<Char> source, Rune value, CompareOptions options) {
  return Int32();
}

SortKey CompareInfo___::GetSortKey(String source, CompareOptions options) {
  return nullptr;
}

SortKey CompareInfo___::GetSortKey(String source) {
  return nullptr;
}

SortKey CompareInfo___::CreateSortKeyCore(String source, CompareOptions options) {
  return nullptr;
}

Int32 CompareInfo___::GetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::GetSortKeyCore(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::GetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::GetSortKeyLengthCore(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Boolean CompareInfo___::Equals(Object value) {
  return Boolean();
}

Int32 CompareInfo___::GetHashCode() {
  return Int32();
}

Int32 CompareInfo___::GetHashCode(String source, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::GetHashCode(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::GetHashCodeOfStringCore(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

String CompareInfo___::ToString() {
  return nullptr;
}

void CompareInfo___::IcuInitSortHandle() {
}

Int32 CompareInfo___::IcuIndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::IcuCompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  return Int32();
}

Int32 CompareInfo___::IcuCompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IcuIndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::IndexOfOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::IndexOfOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  return Int32();
}

Boolean CompareInfo___::IcuStartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::StartsWithOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::StartsWithOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::IcuEndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::EndsWithOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::EndsWithOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
}

SortKey CompareInfo___::IcuCreateSortKey(String source, CompareOptions options) {
  return nullptr;
}

Int32 CompareInfo___::IcuGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::IcuGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Boolean CompareInfo___::IcuIsSortable(ReadOnlySpan<Char> text) {
  return Boolean();
}

Int32 CompareInfo___::IcuGetHashCodeOfString(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Boolean CompareInfo___::CanUseAsciiOrdinalForOptions(CompareOptions options) {
  return Boolean();
}

SortVersion CompareInfo___::IcuGetSortVersion() {
  return nullptr;
}

Int32 CompareInfo___::InvariantIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::InvariantFindString(Char* source, Int32 sourceCount, Char* value, Int32 valueCount, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
}

Char CompareInfo___::InvariantCaseFold(Char c) {
  return Char();
}

SortKey CompareInfo___::InvariantCreateSortKey(String source, CompareOptions options) {
  return nullptr;
}

void CompareInfo___::InvariantCreateSortKeyOrdinal(ReadOnlySpan<Char> source, Span<Byte> sortKey) {
}

void CompareInfo___::InvariantCreateSortKeyOrdinalIgnoreCase(ReadOnlySpan<Char> source, Span<Byte> sortKey) {
}

Int32 CompareInfo___::InvariantGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::InvariantGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

void CompareInfo___::NlsInitSortHandle() {
}

IntPtr CompareInfo___::NlsGetSortHandle(String cultureName) {
  return IntPtr();
}

Int32 CompareInfo___::FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean bIgnoreCase) {
  return Int32();
}

Int32 CompareInfo___::NlsIndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  return Int32();
}

Int32 CompareInfo___::NlsGetHashCodeOfString(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::NlsCompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  return Int32();
}

Int32 CompareInfo___::NlsCompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::FindString(UInt32 dwFindNLSStringFlags, ReadOnlySpan<Char> lpStringSource, ReadOnlySpan<Char> lpStringValue, Int32* pcchFound) {
  return Int32();
}

Int32 CompareInfo___::NlsIndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  return Int32();
}

Boolean CompareInfo___::NlsStartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  return Boolean();
}

Boolean CompareInfo___::NlsEndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  return Boolean();
}

SortKey CompareInfo___::NlsCreateSortKey(String source, CompareOptions options) {
  return nullptr;
}

Int32 CompareInfo___::NlsGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  return Int32();
}

Int32 CompareInfo___::NlsGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
  return Int32();
}

Boolean CompareInfo___::NlsIsSortable(ReadOnlySpan<Char> text) {
  return Boolean();
}

Int32 CompareInfo___::GetNativeCompareFlags(CompareOptions options) {
  return Int32();
}

SortVersion CompareInfo___::NlsGetSortVersion() {
  return nullptr;
}

void CompareInfo___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Globalization::CompareInfoNamespace
