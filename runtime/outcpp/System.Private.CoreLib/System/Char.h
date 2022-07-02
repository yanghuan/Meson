#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class UnicodeCategory : int32_t;
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD_(IComparable)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace CharNamespace {
using namespace System::Globalization;
struct Char : public valueType<Char, rt::TypeCode::Char> {
  public: using interface = rt::TypeList<IComparable<>, IComparable<Char>, IEquatable<Char>, IConvertible>;
  private: static ReadOnlySpan<Byte> get_Latin1CharInfo();
  private: static Boolean IsLatin1(Char ch);
  private: static Boolean IsAscii(Char ch);
  private: static UnicodeCategory GetLatin1UnicodeCategory(Char ch);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Char obj);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Char value);
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: static String ToString(Char c);
  public: static Char Parse(String s);
  public: static Boolean TryParse(String s, Char& result);
  public: static Boolean IsDigit(Char c);
  public: static Boolean IsInRange(Char c, Char min, Char max);
  private: static Boolean IsInRange(UnicodeCategory c, UnicodeCategory min, UnicodeCategory max);
  public: static Boolean CheckLetter(UnicodeCategory uc);
  public: static Boolean IsLetter(Char c);
  private: static Boolean IsWhiteSpaceLatin1(Char c);
  public: static Boolean IsWhiteSpace(Char c);
  public: static Boolean IsUpper(Char c);
  public: static Boolean IsLower(Char c);
  public: static Boolean CheckPunctuation(UnicodeCategory uc);
  public: static Boolean IsPunctuation(Char c);
  public: static Boolean CheckLetterOrDigit(UnicodeCategory uc);
  public: static Boolean IsLetterOrDigit(Char c);
  public: static Char ToUpper(Char c, CultureInfo culture);
  public: static Char ToUpper(Char c);
  public: static Char ToUpperInvariant(Char c);
  public: static Char ToLower(Char c, CultureInfo culture);
  public: static Char ToLower(Char c);
  public: static Char ToLowerInvariant(Char c);
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
  public: static Boolean IsControl(Char c);
  public: static Boolean IsControl(String s, Int32 index);
  public: static Boolean IsDigit(String s, Int32 index);
  public: static Boolean IsLetter(String s, Int32 index);
  public: static Boolean IsLetterOrDigit(String s, Int32 index);
  public: static Boolean IsLower(String s, Int32 index);
  public: static Boolean CheckNumber(UnicodeCategory uc);
  public: static Boolean IsNumber(Char c);
  public: static Boolean IsNumber(String s, Int32 index);
  public: static Boolean IsPunctuation(String s, Int32 index);
  public: static Boolean CheckSeparator(UnicodeCategory uc);
  private: static Boolean IsSeparatorLatin1(Char c);
  public: static Boolean IsSeparator(Char c);
  public: static Boolean IsSeparator(String s, Int32 index);
  public: static Boolean IsSurrogate(Char c);
  public: static Boolean IsSurrogate(String s, Int32 index);
  public: static Boolean CheckSymbol(UnicodeCategory uc);
  public: static Boolean IsSymbol(Char c);
  public: static Boolean IsSymbol(String s, Int32 index);
  public: static Boolean IsUpper(String s, Int32 index);
  public: static Boolean IsWhiteSpace(String s, Int32 index);
  public: static UnicodeCategory GetUnicodeCategory(Char c);
  public: static UnicodeCategory GetUnicodeCategory(String s, Int32 index);
  public: static Double GetNumericValue(Char c);
  public: static Double GetNumericValue(String s, Int32 index);
  public: static Boolean IsHighSurrogate(Char c);
  public: static Boolean IsHighSurrogate(String s, Int32 index);
  public: static Boolean IsLowSurrogate(Char c);
  public: static Boolean IsLowSurrogate(String s, Int32 index);
  public: static Boolean IsSurrogatePair(String s, Int32 index);
  public: static Boolean IsSurrogatePair(Char highSurrogate, Char lowSurrogate);
  public: static String ConvertFromUtf32(Int32 utf32);
  public: static Int32 ConvertToUtf32(Char highSurrogate, Char lowSurrogate);
  private: static void ConvertToUtf32_ThrowInvalidArgs(UInt32 highSurrogateOffset);
  public: static Int32 ConvertToUtf32(String s, Int32 index);
  private: char16_t m_value;
  public: static constexpr Char MaxValue() { return u'\uffff'; }
  public: static constexpr Char MinValue() { return u'\0'; }
  public: constexpr Char() noexcept : m_value(0) {}
  public: constexpr Char(char16_t value) noexcept : m_value(value) {}
  public: template <class T> requires(std::is_enum_v<T> || std::is_pointer_v<T>)
  constexpr explicit Char(T value) noexcept : Char((char16_t)value) {}
  public: constexpr char16_t& get() noexcept { return m_value; }
  public: constexpr char16_t get() const noexcept { return m_value; }
};
} // namespace CharNamespace
using Char = CharNamespace::Char;
} // namespace System::Private::CoreLib::System
