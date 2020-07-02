#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Char)
FORWARDS(Boolean)
FORWARDS(ReadOnlySpan, T)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
FORWARD(SortVersion)
enum class CompareOptions;
FORWARD(SortKey)
FORWARD(CultureInfo)
namespace CompareInfoNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(CompareInfo) {
  public: String get_Name();
  public: SortVersion get_Version();
  public: Int32 get_LCID();
  public: static CompareInfo GetCompareInfo(Int32 culture, Assembly assembly);
  public: static CompareInfo GetCompareInfo(String name, Assembly assembly);
  public: static CompareInfo GetCompareInfo(Int32 culture);
  public: static CompareInfo GetCompareInfo(String name);
  public: static Boolean IsSortable(Char ch);
  public: static Boolean IsSortable(String text);
  private: void OnDeserializing(StreamingContext ctx);
  private: void OnDeserialized(StreamingContext ctx);
  private: void OnDeserialized();
  private: void OnSerializing(StreamingContext ctx);
  public: Int32 Compare(String string1, String string2);
  public: Int32 Compare(String string1, String string2, CompareOptions options);
  public: Int32 Compare(ReadOnlySpan<Char> string1, String string2, CompareOptions options);
  public: Int32 CompareOptionNone(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2);
  public: Int32 CompareOptionIgnoreCase(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2);
  public: Int32 Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2);
  public: Int32 Compare(String string1, Int32 offset1, String string2, Int32 offset2, CompareOptions options);
  public: Int32 Compare(String string1, Int32 offset1, String string2, Int32 offset2);
  public: Int32 Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2, CompareOptions options);
  public: static Int32 CompareOrdinalIgnoreCase(String strA, Int32 indexA, Int32 lengthA, String strB, Int32 indexB, Int32 lengthB);
  public: static Int32 CompareOrdinalIgnoreCase(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB);
  public: static Int32 CompareOrdinalIgnoreCase(String strA, String strB);
  public: static Int32 CompareOrdinalIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB);
  public: static Boolean EqualsOrdinalIgnoreCase(Char& charA, Char& charB, Int32 length);
  private: static Boolean EqualsOrdinalIgnoreCaseNonAscii(Char& charA, Char& charB, Int32 length);
  public: Boolean IsPrefix(String source, String prefix, CompareOptions options);
  public: Boolean IsPrefix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  public: Boolean IsPrefix(String source, String prefix);
  public: Boolean IsSuffix(String source, String suffix, CompareOptions options);
  public: Boolean IsSuffix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  public: Boolean IsSuffix(String source, String suffix);
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
  public: Int32 IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value);
  public: Int32 LastIndexOfOrdinal(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase);
  public: Int32 IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options);
  public: Int32 LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options);
  public: Int32 IndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options, Int32* matchLengthPtr);
  public: Int32 IndexOfOrdinal(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
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
  public: Int32 LastIndexOfOrdinal(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
  public: SortKey GetSortKey(String source, CompareOptions options);
  public: SortKey GetSortKey(String source);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: Int32 GetHashCodeOfString(String source, CompareOptions options);
  public: Int32 GetHashCode(String source, CompareOptions options);
  public: Int32 GetHashCode(ReadOnlySpan<Char> source, CompareOptions options);
  public: String ToString();
  public: static Int32 InvariantIndexOf(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
  public: static Int32 InvariantIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning);
  public: static Int32 InvariantLastIndexOf(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
  private: static Int32 InvariantFindString(Char* source, Int32 sourceCount, Char* value, Int32 valueCount, Boolean ignoreCase, Boolean fromBeginning);
  private: static Char InvariantToUpper(Char c);
  private: SortKey InvariantCreateSortKey(String source, CompareOptions options);
  public: static IntPtr GetSortHandle(String cultureName);
  private: void InitSort(CultureInfo culture);
  private: static Int32 FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, String stringSource, Int32 offset, Int32 cchSource, String value, Int32 cchValue, Boolean bIgnoreCase);
  private: static Int32 FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean bIgnoreCase);
  public: static Int32 IndexOfOrdinalCore(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
  public: static Int32 IndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning);
  public: static Int32 LastIndexOfOrdinalCore(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase);
  private: Int32 GetHashCodeOfStringCore(ReadOnlySpan<Char> source, CompareOptions options);
  private: static Int32 CompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2);
  private: Int32 CompareString(ReadOnlySpan<Char> string1, String string2, CompareOptions options);
  private: Int32 CompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options);
  private: Int32 FindString(UInt32 dwFindNLSStringFlags, ReadOnlySpan<Char> lpStringSource, ReadOnlySpan<Char> lpStringValue, Int32* pcchFound);
  private: Int32 FindString(UInt32 dwFindNLSStringFlags, String lpStringSource, Int32 startSource, Int32 cchSource, String lpStringValue, Int32 startValue, Int32 cchValue, Int32* pcchFound);
  public: Int32 IndexOfCore(String source, String target, Int32 startIndex, Int32 count, CompareOptions options, Int32* matchLengthPtr);
  public: Int32 IndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning);
  private: Int32 LastIndexOfCore(String source, String target, Int32 startIndex, Int32 count, CompareOptions options);
  private: Boolean StartsWith(String source, String prefix, CompareOptions options);
  private: Boolean StartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options);
  private: Boolean EndsWith(String source, String suffix, CompareOptions options);
  private: Boolean EndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options);
  private: static Int32 FastLastIndexOfString(String source, String target, Int32 startIndex, Int32 sourceCount, Int32 targetCount);
  private: SortKey CreateSortKey(String source, CompareOptions options);
  private: static Boolean IsSortable(Char* text, Int32 length);
  private: static Int32 GetNativeCompareFlags(CompareOptions options);
  private: SortVersion GetSortVersion();
  public: static CompareInfo Invariant;
  private: String m_name;
  private: String _sortName;
  private: SortVersion m_SortVersion;
  private: Int32 culture;
  private: IntPtr _sortHandle;
};
} // namespace CompareInfoNamespace
using CompareInfo = CompareInfoNamespace::CompareInfo;
} // namespace System::Private::CoreLib::System::Globalization
