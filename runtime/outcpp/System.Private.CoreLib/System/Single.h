#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
FORWARD(NumberFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt32)
namespace SingleNamespace {
using namespace Globalization;
struct Single {
  public: static Boolean IsFinite(Single f);
  public: static Boolean IsInfinity(Single f);
  public: static Boolean IsNaN(Single f);
  public: static Boolean IsNegative(Single f);
  public: static Boolean IsNegativeInfinity(Single f);
  public: static Boolean IsNormal(Single f);
  public: static Boolean IsPositiveInfinity(Single f);
  public: static Boolean IsSubnormal(Single f);
  public: static Int32 ExtractExponentFromBits(UInt32 bits);
  public: static UInt32 ExtractSignificandFromBits(UInt32 bits);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Single value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Single obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Single Parse(String s);
  public: static Single Parse(String s, NumberStyles style);
  public: static Single Parse(String s, IFormatProvider provider);
  public: static Single Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Single Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, Single& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Single& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Single& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Single& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Single& result);
  public: TypeCode GetTypeCode();
  private: float m_value;
  public: static Single MinValue;
  public: static Single Epsilon;
  public: static Single MaxValue;
  public: static Single PositiveInfinity;
  public: static Single NegativeInfinity;
  public: static Single NaN;
};
} // namespace SingleNamespace
using Single = SingleNamespace::Single;
} // namespace System::Private::CoreLib::System
