#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD_(IComparable, T1, T2)
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
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace BooleanNamespace {
struct Boolean : public valueType<Boolean, rt::TypeCode::Boolean> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IComparable<Boolean>, IEquatable<Boolean>>;
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Boolean obj);
  public: Int32 CompareTo(Object obj);
  public: Int32 CompareTo(Boolean value);
  public: static Boolean IsTrueStringIgnoreCase(ReadOnlySpan<Char> value);
  public: static Boolean IsFalseStringIgnoreCase(ReadOnlySpan<Char> value);
  public: static Boolean Parse(String value);
  public: static Boolean Parse(ReadOnlySpan<Char> value);
  public: static Boolean TryParse(String value, Boolean& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> value, Boolean& result);
  private: static ReadOnlySpan<Char> TrimWhiteSpaceAndNull(ReadOnlySpan<Char> value);
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
  public: static void cctor();
  private: bool m_value;
  public: static String TrueString;
  public: static String FalseString;
  public: constexpr Boolean() noexcept : m_value(false) {}
  public: template <class T> requires(rt::IsBool<T>)
  constexpr Boolean(T value) noexcept : m_value(value) {}
  public: constexpr bool& get() noexcept { return m_value; }
  public: constexpr bool get() const noexcept { return m_value; }
};
} // namespace BooleanNamespace
using Boolean = BooleanNamespace::Boolean;
} // namespace System::Private::CoreLib::System
