#pragma once

#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD_(IComparable)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace Int32Namespace {
using namespace System::Globalization;
struct Int32 : public valueType<Int32, rt::TypeCode::Int32> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Int32>, IEquatable<Int32>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Int32 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Int32 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default__, IFormatProvider provider = nullptr);
  public: static Int32 Parse(String s);
  public: static Int32 Parse(String s, NumberStyles style);
  public: static Int32 Parse(String s, IFormatProvider provider);
  public: static Int32 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Int32 Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::Integer, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, Int32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Int32& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Int32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int32& result);
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
  private: int32_t m_value;
  public: static constexpr Int32 MaxValue() { return 2147483647; }
  public: static constexpr Int32 MinValue() { return -2147483648; }
  public: constexpr Int32() noexcept : m_value(0) {}
  public: constexpr Int32(int32_t value) noexcept : m_value(value) {}
  public: template <class T> requires(std::is_enum_v<T> || std::is_pointer_v<T>)
  constexpr explicit Int32(T value) noexcept : Int32((int32_t)value) {}
  public: constexpr int32_t& get() noexcept { return m_value; }
  public: constexpr int32_t get() const noexcept { return m_value; }
};
} // namespace Int32Namespace
using Int32 = Int32Namespace::Int32;
} // namespace System::Private::CoreLib::System
