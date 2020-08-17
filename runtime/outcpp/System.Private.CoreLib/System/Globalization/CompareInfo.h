#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Text {
FORWARDS(Rune)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
FORWARD(SortKey)
FORWARD(SortVersion)
namespace CompareInfoNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Runtime::Serialization;
using namespace System::Text;
CLASS(CompareInfo) : public Object::in {
  public: using interface = rt::TypeList<IDeserializationCallback>;
  private: class SortHandleCache {
    public: static IntPtr GetCachedSortHandle(String sortName);
    private: static void cctor();
    private: static Dictionary<String, IntPtr> s_sortNameToSortHandleCache;
  };
  public: String get_Name();
  public: SortVersion get_Version();
  public: Int32 get_LCID();
  private: static ReadOnlySpan<Boolean> get_HighCharTable();
  public: void ctor(CultureInfo culture);
  public: static CompareInfo GetCompareInfo(Int32 culture, Assembly assembly);
  public: static CompareInfo GetCompareInfo(String name, Assembly assembly);
  public: static CompareInfo GetCompareInfo(Int32 culture);
  public: static CompareInfo GetCompareInfo(String name);
  public: static Boolean IsSortable(Char ch);
  public: static Boolean IsSortable(String text);
  public: static Boolean IsSortable(ReadOnlySpan<Char> text);
  public: static Boolean IsSortable(Rune value);
  private: void InitSort(CultureInfo culture);
  private: void OnDeserializing(StreamingContext ctx);
  private: void OnDeserialized(StreamingContext ctx);
  private: void OnDeserialized();
  private: void OnSerializing(StreamingContext ctx);
  public: Int32 Compare(String string1, String string2);
  public: Int32 Compare(String string1, String string2, CompareOptions options);
  public: Int32 CompareOptionIgnoreCase(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2);
  public: Int32 Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2);
  public: Int32 Compare(String string1, Int32 offset1, String string2, Int32 offset2, CompareOptions options);
  public: Int32 Compare(String string1, Int32 offset1, String string2, Int32 offset2);
  public: Int32 Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2, CompareOptions options);
  public: Int32 Compare(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options = CompareOptions::None);
  private: static void CheckCompareOptionsForCompare(CompareOptions options);
  private: static void ThrowCompareOptionsCheckFailed(CompareOptions options);
  private: Int32 CompareStringCore(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options);
  public: static Int32 CompareOrdinalIgnoreCase(String strA, Int32 indexA, Int32 lengthA, String strB, Int32 indexB, Int32 lengthB);
  public: static Int32 CompareOrdinalIgnoreCase(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB);
  public: static Int32 CompareOrdinalIgnoreCase(String strA, String strB);
  public: static Int32 CompareOrdinalIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB);
  public: static Boolean EqualsOrdinalIgnoreCase(Char& charA, Char& charB, Int32 length);
  private: static Boolean EqualsOrdinalIgnoreCaseNonAscii(Char& charA, Char& charB, Int32 length);
  private: static Int32 CompareStringOrdinalIgnoreCaseCore(Char& string1, Int32 count1, Char& string2, Int32 count2);
  public: Boolean IsPrefix(String source, String prefix, CompareOptions options);
  public: Boolean IsPrefix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options = CompareOptions::None);
  private: Boolean StartsWithCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  public: Boolean IsPrefix(String source, String prefix);
  public: Boolean IsSuffix(String source, String suffix, CompareOptions options);
  public: Boolean IsSuffix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options = CompareOptions::None);
  public: Boolean IsSuffix(String source, String suffix);
  private: Boolean EndsWithCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  public: Int32 IndexOf(String source, Char value);
  public: Int32 IndexOf(String source, String value);
  public: Int32 IndexOf(String source, Char value, CompareOptions options);
  public: Int32 IndexOf(String source, String value, CompareOptions options);
  public: Int32 IndexOf(String source, Char value, Int32 startIndex);
  public: Int32 IndexOf(String source, String value, Int32 startIndex);
  public: Int32 IndexOf(String source, Char value, Int32 startIndex, CompareOptions options);
  public: Int32 IndexOf(String source, String value, Int32 startIndex, CompareOptions options);
  public: Int32 IndexOf(String source, Char value, Int32 startIndex, Int32 count);
  public: Int32 IndexOf(String source, String value, Int32 startIndex, Int32 count);
  public: Int32 IndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options);
  public: Int32 IndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options);
  public: Int32 IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options = CompareOptions::None);
  public: Int32 IndexOf(ReadOnlySpan<Char> source, Rune value, CompareOptions options = CompareOptions::None);
  private: static Int32 IndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning);
  public: static Int32 IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean fromBeginning);
  public: Int32 IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Int32* matchLengthPtr, CompareOptions options, Boolean fromBeginning);
  private: Int32 IndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning);
  public: Int32 LastIndexOf(String source, Char value);
  public: Int32 LastIndexOf(String source, String value);
  public: Int32 LastIndexOf(String source, Char value, CompareOptions options);
  public: Int32 LastIndexOf(String source, String value, CompareOptions options);
  public: Int32 LastIndexOf(String source, Char value, Int32 startIndex);
  public: Int32 LastIndexOf(String source, String value, Int32 startIndex);
  public: Int32 LastIndexOf(String source, Char value, Int32 startIndex, CompareOptions options);
  public: Int32 LastIndexOf(String source, String value, Int32 startIndex, CompareOptions options);
  public: Int32 LastIndexOf(String source, Char value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(String source, String value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options);
  public: Int32 LastIndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options);
  public: Int32 LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options = CompareOptions::None);
  public: Int32 LastIndexOf(ReadOnlySpan<Char> source, Rune value, CompareOptions options = CompareOptions::None);
  public: SortKey GetSortKey(String source, CompareOptions options);
  public: SortKey GetSortKey(String source);
  private: SortKey CreateSortKeyCore(String source, CompareOptions options);
  public: Int32 GetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options = CompareOptions::None);
  private: Int32 GetSortKeyCore(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options);
  public: Int32 GetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options = CompareOptions::None);
  private: Int32 GetSortKeyLengthCore(ReadOnlySpan<Char> source, CompareOptions options);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: Int32 GetHashCode(String source, CompareOptions options);
  public: Int32 GetHashCode(ReadOnlySpan<Char> source, CompareOptions options);
  private: Int32 GetHashCodeOfStringCore(ReadOnlySpan<Char> source, CompareOptions options);
  public: String ToString();
  private: void IcuInitSortHandle();
  private: static Int32 IcuIndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning);
  private: static Int32 IcuCompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2);
  private: Int32 IcuCompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options);
  private: Int32 IcuIndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning);
  private: Int32 IndexOfOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning);
  private: Int32 IndexOfOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning);
  private: Boolean IcuStartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  private: Boolean StartsWithOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  private: Boolean StartsWithOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  private: Boolean IcuEndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  private: Boolean EndsWithOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  private: Boolean EndsWithOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  private: SortKey IcuCreateSortKey(String source, CompareOptions options);
  private: Int32 IcuGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options);
  private: Int32 IcuGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options);
  private: static Boolean IcuIsSortable(ReadOnlySpan<Char> text);
  private: Int32 IcuGetHashCodeOfString(ReadOnlySpan<Char> source, CompareOptions options);
  private: static Boolean CanUseAsciiOrdinalForOptions(CompareOptions options);
  private: SortVersion IcuGetSortVersion();
  public: static Int32 InvariantIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning = true);
  private: static Int32 InvariantFindString(Char* source, Int32 sourceCount, Char* value, Int32 valueCount, Boolean ignoreCase, Boolean fromBeginning);
  private: static Char InvariantCaseFold(Char c);
  private: SortKey InvariantCreateSortKey(String source, CompareOptions options);
  private: static void InvariantCreateSortKeyOrdinal(ReadOnlySpan<Char> source, Span<Byte> sortKey);
  private: static void InvariantCreateSortKeyOrdinalIgnoreCase(ReadOnlySpan<Char> source, Span<Byte> sortKey);
  private: Int32 InvariantGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options);
  private: Int32 InvariantGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options);
  private: void NlsInitSortHandle();
  public: static IntPtr NlsGetSortHandle(String cultureName);
  private: static Int32 FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean bIgnoreCase);
  private: static Int32 NlsIndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning);
  private: Int32 NlsGetHashCodeOfString(ReadOnlySpan<Char> source, CompareOptions options);
  private: static Int32 NlsCompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2);
  private: Int32 NlsCompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options);
  private: Int32 FindString(UInt32 dwFindNLSStringFlags, ReadOnlySpan<Char> lpStringSource, ReadOnlySpan<Char> lpStringValue, Int32* pcchFound);
  private: Int32 NlsIndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning);
  private: Boolean NlsStartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  private: Boolean NlsEndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  private: SortKey NlsCreateSortKey(String source, CompareOptions options);
  private: Int32 NlsGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options);
  private: Int32 NlsGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options);
  private: static Boolean NlsIsSortable(ReadOnlySpan<Char> text);
  private: static Int32 GetNativeCompareFlags(CompareOptions options);
  private: SortVersion NlsGetSortVersion();
  private: static void cctor();
  public: static CompareInfo Invariant;
  private: String m_name;
  private: IntPtr _sortHandle;
  private: String _sortName;
  private: SortVersion m_SortVersion;
  private: Int32 culture;
  private: Boolean _isAsciiEqualityOrdinal;
};
} // namespace CompareInfoNamespace
using CompareInfo = CompareInfoNamespace::CompareInfo;
} // namespace System::Private::CoreLib::System::Globalization
