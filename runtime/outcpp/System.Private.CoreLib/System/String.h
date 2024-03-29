#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/StringSplitOptions.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS(ValueListBuilder, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm : int32_t;
enum class TrimType : int32_t;
FORWARD(Encoding)
FORWARDS(StringRuneEnumerator)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions : int32_t;
FORWARD(CompareInfo)
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Buffers {
FORWARD(SpanAction, T, TArg)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
enum class StringComparison : int32_t;
enum class TypeCode : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(CharEnumerator)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(ICloneable)
FORWARD_(IComparable)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARDS(ParamsArray)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace StringNamespace {
using namespace System::Buffers;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Text;
using IEnumerable = Collections::IEnumerable;
template <class T>
using IEnumerable_ = Collections::Generic::IEnumerable<T>;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(String) : public object {
  public: using interface = rt::TypeList<IComparable<>, IEnumerable, IConvertible, IEnumerable_<Char>, IComparable<String>, IEquatable<String>, ICloneable>;
  private: struct ProbabilisticMap : public valueType<ProbabilisticMap> {
  };
  public: Char get_Chars(Int32 index);
  public: Int32 get_Length();
  public: static String FastAllocateString(Int32 length);
  public: void SetTrailByte(Byte data);
  public: Boolean TryGetTrailByte(Byte& data);
  private: String Intern();
  private: String IsInterned();
  public: static String Intern(String str);
  public: static String IsInterned(String str);
  public: static void InternalCopy(String src, IntPtr dest, Int32 len);
  public: Int32 GetBytesFromEncoding(Byte* pbNativeBuffer, Int32 cbNativeBuffer, Encoding encoding);
  private: static Boolean EqualsHelper(String strA, String strB);
  private: static Int32 CompareOrdinalHelper(String strA, Int32 indexA, Int32 countA, String strB, Int32 indexB, Int32 countB);
  public: static Boolean EqualsOrdinalIgnoreCase(String strA, String strB);
  private: static Boolean EqualsOrdinalIgnoreCaseNoLengthCheck(String strA, String strB);
  private: static Int32 CompareOrdinalHelper(String strA, String strB);
  public: static Int32 Compare(String strA, String strB);
  public: static Int32 Compare(String strA, String strB, Boolean ignoreCase);
  public: static Int32 Compare(String strA, String strB, StringComparison comparisonType);
  public: static Int32 Compare(String strA, String strB, CultureInfo culture, CompareOptions options);
  public: static Int32 Compare(String strA, String strB, Boolean ignoreCase, CultureInfo culture);
  public: static Int32 Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length);
  public: static Int32 Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, Boolean ignoreCase);
  public: static Int32 Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, Boolean ignoreCase, CultureInfo culture);
  public: static Int32 Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, CultureInfo culture, CompareOptions options);
  public: static Int32 Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, StringComparison comparisonType);
  public: static Int32 CompareOrdinal(String strA, String strB);
  public: static Int32 CompareOrdinal(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB);
  public: static Int32 CompareOrdinal(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(String strB);
  public: Boolean EndsWith(String value);
  public: Boolean EndsWith(String value, StringComparison comparisonType);
  public: Boolean EndsWith(String value, Boolean ignoreCase, CultureInfo culture);
  public: Boolean EndsWith(Char value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(String value);
  public: Boolean Equals(String value, StringComparison comparisonType);
  public: static Boolean Equals(String a, String b);
  public: static Boolean Equals(String a, String b, StringComparison comparisonType);
  public: static Boolean op_Equality(String a, String b);
  public: static Boolean op_Inequality(String a, String b);
  public: Int32 GetHashCode();
  public: Int32 GetHashCode(StringComparison comparisonType);
  public: Int32 GetHashCodeOrdinalIgnoreCase();
  public: static Int32 GetHashCode(ReadOnlySpan<Char> value);
  public: static Int32 GetHashCode(ReadOnlySpan<Char> value, StringComparison comparisonType);
  public: static Int32 GetHashCodeOrdinalIgnoreCase(ReadOnlySpan<Char> value);
  public: Int32 GetNonRandomizedHashCode();
  public: Int32 GetNonRandomizedHashCodeOrdinalIgnoreCase();
  public: Boolean StartsWith(String value);
  public: Boolean StartsWith(String value, StringComparison comparisonType);
  public: Boolean StartsWith(String value, Boolean ignoreCase, CultureInfo culture);
  public: Boolean StartsWith(Char value);
  public: static void CheckStringComparison(StringComparison comparisonType);
  public: static CompareOptions GetCaseCompareOfComparisonCulture(StringComparison comparisonType);
  private: static CompareOptions GetCompareOptionsFromOrdinalStringComparison(StringComparison comparisonType);
  public: void ctor(Array<Char> value);
  public: static String Ctor(Array<Char> value);
  public: void ctor(Array<Char> value, Int32 startIndex, Int32 length);
  public: static String Ctor(Array<Char> value, Int32 startIndex, Int32 length);
  public: void ctor(Char* value);
  public: static String Ctor(Char* ptr);
  public: void ctor(Char* value, Int32 startIndex, Int32 length);
  public: static String Ctor(Char* ptr, Int32 startIndex, Int32 length);
  public: void ctor(SByte* value);
  public: static String Ctor(SByte* value);
  public: void ctor(SByte* value, Int32 startIndex, Int32 length);
  public: static String Ctor(SByte* value, Int32 startIndex, Int32 length);
  private: static String CreateStringForSByteConstructor(Byte* pb, Int32 numBytes);
  public: void ctor(SByte* value, Int32 startIndex, Int32 length, Encoding enc);
  public: static String Ctor(SByte* value, Int32 startIndex, Int32 length, Encoding enc);
  public: void ctor(Char c, Int32 count);
  public: static String Ctor(Char c, Int32 count);
  public: void ctor(ReadOnlySpan<Char> value);
  public: static String Ctor(ReadOnlySpan<Char> value);
  public: template <class TState>
  static String Create(Int32 length, TState state, SpanAction<Char, TState> action);
  public: static ReadOnlySpan<Char> op_Implicit(String value);
  public: Boolean TryGetSpan(Int32 startIndex, Int32 count, ReadOnlySpan<Char>& slice);
  public: Object Clone();
  public: static String Copy(String str);
  public: void CopyTo(Int32 sourceIndex, Array<Char> destination, Int32 destinationIndex, Int32 count);
  public: Array<Char> ToCharArray();
  public: Array<Char> ToCharArray(Int32 startIndex, Int32 length);
  public: static Boolean IsNullOrEmpty(String value);
  public: static Boolean IsNullOrWhiteSpace(String value);
  public: Char& GetPinnableReference();
  public: Char& GetRawStringData();
  public: static String CreateStringFromEncoding(Byte* bytes, Int32 byteLength, Encoding encoding);
  public: static String CreateFromChar(Char c);
  public: static String CreateFromChar(Char c1, Char c2);
  public: static void wstrcpy(Char* dmem, Char* smem, Int32 charCount);
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: CharEnumerator GetEnumerator();
  private: IEnumerator<Char> GetEnumeratorOfChar();
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  public: StringRuneEnumerator EnumerateRunes();
  public: static Int32 wcslen(Char* ptr);
  public: static Int32 strlen(Byte* ptr);
  private: static void ThrowMustBeNullTerminatedString();
  public: TypeCode GetTypeCode();
  private: Boolean ToBooleanOfIConvertible(IFormatProvider provider);
  private: Char ToCharOfIConvertible(IFormatProvider provider);
  private: SByte ToSByteOfIConvertible(IFormatProvider provider);
  private: Byte ToByteOfIConvertible(IFormatProvider provider);
  private: Int16 ToInt16OfIConvertible(IFormatProvider provider);
  private: UInt16 ToUInt16OfIConvertible(IFormatProvider provider);
  private: Int32 ToInt32OfIConvertible(IFormatProvider provider);
  private: UInt32 ToUInt32OfIConvertible(IFormatProvider provider);
  private: Int64 ToInt64OfIConvertible(IFormatProvider provider);
  private: UInt64 ToUInt64OfIConvertible(IFormatProvider provider);
  private: Single ToSingleOfIConvertible(IFormatProvider provider);
  private: Double ToDoubleOfIConvertible(IFormatProvider provider);
  private: Decimal ToDecimalOfIConvertible(IFormatProvider provider);
  private: DateTime ToDateTimeOfIConvertible(IFormatProvider provider);
  private: Object ToTypeOfIConvertible(Type type, IFormatProvider provider);
  public: Boolean IsNormalized();
  public: Boolean IsNormalized(NormalizationForm normalizationForm);
  public: String Normalize();
  public: String Normalize(NormalizationForm normalizationForm);
  private: Boolean IsAscii();
  private: static void FillStringChecked(String dest, Int32 destPos, String src);
  public: static String Concat(Object arg0);
  public: static String Concat(Object arg0, Object arg1);
  public: static String Concat(Object arg0, Object arg1, Object arg2);
  public: static String Concat(Array<Object> args);
  public: template <class T>
  static String Concat(IEnumerable_<T> values);
  public: static String Concat(IEnumerable_<String> values);
  public: static String Concat(String str0, String str1);
  public: static String Concat(String str0, String str1, String str2);
  public: static String Concat(String str0, String str1, String str2, String str3);
  public: static String Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1);
  public: static String Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1, ReadOnlySpan<Char> str2);
  public: static String Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1, ReadOnlySpan<Char> str2, ReadOnlySpan<Char> str3);
  public: static String Concat(Array<String> values);
  public: static String Format(String format, Object arg0);
  public: static String Format(String format, Object arg0, Object arg1);
  public: static String Format(String format, Object arg0, Object arg1, Object arg2);
  public: static String Format(String format, Array<Object> args);
  public: static String Format(IFormatProvider provider, String format, Object arg0);
  public: static String Format(IFormatProvider provider, String format, Object arg0, Object arg1);
  public: static String Format(IFormatProvider provider, String format, Object arg0, Object arg1, Object arg2);
  public: static String Format(IFormatProvider provider, String format, Array<Object> args);
  private: static String FormatHelper(IFormatProvider provider, String format, ParamsArray args);
  public: String Insert(Int32 startIndex, String value);
  public: static String Join(Char separator, Array<String> value);
  public: static String Join(Char separator, Array<Object> values);
  public: template <class T>
  static String Join(Char separator, IEnumerable_<T> values);
  public: static String Join(Char separator, Array<String> value, Int32 startIndex, Int32 count);
  public: static String Join(String separator, Array<String> value);
  public: static String Join(String separator, Array<Object> values);
  public: template <class T>
  static String Join(String separator, IEnumerable_<T> values);
  public: static String Join(String separator, IEnumerable_<String> values);
  public: static String Join(String separator, Array<String> value, Int32 startIndex, Int32 count);
  private: static String JoinCore(Char* separator, Int32 separatorLength, Array<Object> values);
  private: template <class T>
  static String JoinCore(Char* separator, Int32 separatorLength, IEnumerable_<T> values);
  private: static String JoinCore(Char* separator, Int32 separatorLength, Array<String> value, Int32 startIndex, Int32 count);
  public: String PadLeft(Int32 totalWidth);
  public: String PadLeft(Int32 totalWidth, Char paddingChar);
  public: String PadRight(Int32 totalWidth);
  public: String PadRight(Int32 totalWidth, Char paddingChar);
  public: String Remove(Int32 startIndex, Int32 count);
  public: String Remove(Int32 startIndex);
  public: String Replace(String oldValue, String newValue, Boolean ignoreCase, CultureInfo culture);
  public: String Replace(String oldValue, String newValue, StringComparison comparisonType);
  private: String ReplaceCore(String oldValue, String newValue, CompareInfo ci, CompareOptions options);
  private: static String ReplaceCore(ReadOnlySpan<Char> searchSpace, ReadOnlySpan<Char> oldValue, ReadOnlySpan<Char> newValue, CompareInfo compareInfo, CompareOptions options);
  public: String Replace(Char oldChar, Char newChar);
  public: String Replace(String oldValue, String newValue);
  private: String ReplaceHelper(Int32 oldValueLength, String newValue, ReadOnlySpan<Int32> indices);
  public: Array<String> Split(Char separator, StringSplitOptions options = StringSplitOptions::None);
  public: Array<String> Split(Char separator, Int32 count, StringSplitOptions options = StringSplitOptions::None);
  public: Array<String> Split(Array<Char> separator);
  public: Array<String> Split(Array<Char> separator, Int32 count);
  public: Array<String> Split(Array<Char> separator, StringSplitOptions options);
  public: Array<String> Split(Array<Char> separator, Int32 count, StringSplitOptions options);
  private: Array<String> SplitInternal(ReadOnlySpan<Char> separators, Int32 count, StringSplitOptions options);
  public: Array<String> Split(String separator, StringSplitOptions options = StringSplitOptions::None);
  public: Array<String> Split(String separator, Int32 count, StringSplitOptions options = StringSplitOptions::None);
  public: Array<String> Split(Array<String> separator, StringSplitOptions options);
  public: Array<String> Split(Array<String> separator, Int32 count, StringSplitOptions options);
  private: Array<String> SplitInternal(String separator, Array<String> separators, Int32 count, StringSplitOptions options);
  private: Array<String> SplitInternal(String separator, Int32 count, StringSplitOptions options);
  private: Array<String> SplitWithoutPostProcessing(ReadOnlySpan<Int32> sepList, ReadOnlySpan<Int32> lengthList, Int32 defaultLength, Int32 count);
  private: Array<String> SplitWithPostProcessing(ReadOnlySpan<Int32> sepList, ReadOnlySpan<Int32> lengthList, Int32 defaultLength, Int32 count, StringSplitOptions options);
  private: void MakeSeparatorList(ReadOnlySpan<Char> separators, ValueListBuilder<Int32>& sepListBuilder);
  private: void MakeSeparatorList(String separator, ValueListBuilder<Int32>& sepListBuilder);
  private: void MakeSeparatorList(Array<String> separators, ValueListBuilder<Int32>& sepListBuilder, ValueListBuilder<Int32>& lengthListBuilder);
  private: static void CheckStringSplitOptions(StringSplitOptions options);
  public: String Substring(Int32 startIndex);
  public: String Substring(Int32 startIndex, Int32 length);
  private: String InternalSubString(Int32 startIndex, Int32 length);
  public: String ToLower();
  public: String ToLower(CultureInfo culture);
  public: String ToLowerInvariant();
  public: String ToUpper();
  public: String ToUpper(CultureInfo culture);
  public: String ToUpperInvariant();
  public: String Trim();
  public: String Trim(Char trimChar);
  public: String Trim(Array<Char> trimChars);
  public: String TrimStart();
  public: String TrimStart(Char trimChar);
  public: String TrimStart(Array<Char> trimChars);
  public: String TrimEnd();
  public: String TrimEnd(Char trimChar);
  public: String TrimEnd(Array<Char> trimChars);
  private: String TrimWhiteSpaceHelper(TrimType trimType);
  private: String TrimHelper(Char* trimChars, Int32 trimCharsLength, TrimType trimType);
  private: String CreateTrimmedString(Int32 start, Int32 end);
  public: Boolean Contains(String value);
  public: Boolean Contains(String value, StringComparison comparisonType);
  public: Boolean Contains(Char value);
  public: Boolean Contains(Char value, StringComparison comparisonType);
  public: Int32 IndexOf(Char value);
  public: Int32 IndexOf(Char value, Int32 startIndex);
  public: Int32 IndexOf(Char value, StringComparison comparisonType);
  public: Int32 IndexOf(Char value, Int32 startIndex, Int32 count);
  public: Int32 IndexOfAny(Array<Char> anyOf);
  public: Int32 IndexOfAny(Array<Char> anyOf, Int32 startIndex);
  public: Int32 IndexOfAny(Array<Char> anyOf, Int32 startIndex, Int32 count);
  private: Int32 IndexOfCharArray(Array<Char> anyOf, Int32 startIndex, Int32 count);
  private: static void InitializeProbabilisticMap(UInt32* charMap, ReadOnlySpan<Char> anyOf);
  private: static Boolean ArrayContains(Char searchChar, Array<Char> anyOf);
  private: static Boolean IsCharBitSet(UInt32* charMap, Byte value);
  private: static void SetCharBit(UInt32* charMap, Byte value);
  public: Int32 IndexOf(String value);
  public: Int32 IndexOf(String value, Int32 startIndex);
  public: Int32 IndexOf(String value, Int32 startIndex, Int32 count);
  public: Int32 IndexOf(String value, StringComparison comparisonType);
  public: Int32 IndexOf(String value, Int32 startIndex, StringComparison comparisonType);
  public: Int32 IndexOf(String value, Int32 startIndex, Int32 count, StringComparison comparisonType);
  public: Int32 LastIndexOf(Char value);
  public: Int32 LastIndexOf(Char value, Int32 startIndex);
  public: Int32 LastIndexOf(Char value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOfAny(Array<Char> anyOf);
  public: Int32 LastIndexOfAny(Array<Char> anyOf, Int32 startIndex);
  public: Int32 LastIndexOfAny(Array<Char> anyOf, Int32 startIndex, Int32 count);
  private: Int32 LastIndexOfCharArray(Array<Char> anyOf, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(String value);
  public: Int32 LastIndexOf(String value, Int32 startIndex);
  public: Int32 LastIndexOf(String value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(String value, StringComparison comparisonType);
  public: Int32 LastIndexOf(String value, Int32 startIndex, StringComparison comparisonType);
  public: Int32 LastIndexOf(String value, Int32 startIndex, Int32 count, StringComparison comparisonType);
  public: static Int32 _GetNonRandomizedHashCodeOrdinalIgnoreCase_g__GetNonRandomizedHashCodeOrdinalIgnoreCaseSlow52_0(String str);
  public: static String Empty;
  private: Int32 _stringLength;
  private: Char _firstChar;
  public: static constexpr rt::TypeCode code = rt::TypeCode::String;
  public: size_t GetAllocSize() const noexcept { return rt::string::GetAllocSize(_stringLength.get()); }
};
} // namespace StringNamespace
using String = StringNamespace::String;
} // namespace System::Private::CoreLib::System
