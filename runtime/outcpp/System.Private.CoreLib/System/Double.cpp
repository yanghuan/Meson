#include "Double-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::DoubleNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;

Boolean Double::IsFinite(Double d) {
  Int64 num = BitConverter::DoubleToInt64Bits(d);
  return (num & Int64::MaxValue) < 9218868437227405312;
}

Boolean Double::IsInfinity(Double d) {
  Int64 num = BitConverter::DoubleToInt64Bits(d);
  return (num & Int64::MaxValue) == 9218868437227405312;
}

Boolean Double::IsNaN(Double d) {
  return d != d;
}

Boolean Double::IsNegative(Double d) {
  return BitConverter::DoubleToInt64Bits(d) < 0;
}

Boolean Double::IsNegativeInfinity(Double d) {
  return d == Double::NegativeInfinity;
}

Boolean Double::IsNormal(Double d) {
  Int64 num = BitConverter::DoubleToInt64Bits(d);
  num &= Int64::MaxValue;
  if (num < 9218868437227405312 && num != 0) {
    return (num & 9218868437227405312) != 0;
  }
  return false;
}

Boolean Double::IsPositiveInfinity(Double d) {
  return d == Double::PositiveInfinity;
}

Boolean Double::IsSubnormal(Double d) {
  Int64 num = BitConverter::DoubleToInt64Bits(d);
  num &= Int64::MaxValue;
  if (num < 9218868437227405312 && num != 0) {
    return (num & 9218868437227405312) == 0;
  }
  return false;
}

Int32 Double::ExtractExponentFromBits(UInt64 bits) {
  return (Int32)(bits >> 52) & 2047;
}

UInt64 Double::ExtractSignificandFromBits(UInt64 bits) {
  return bits & 4503599627370495;
}

Int32 Double::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<Double>(value)) {
    Double num = (Double)value;
    if (*this < num) {
      return -1;
    }
    if (*this > num) {
      return 1;
    }
    if (*this == num) {
      return 0;
    }
    if (IsNaN(*this)) {
      if (!IsNaN(num)) {
        return -1;
      }
      return 0;
    }
    return 1;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDouble());
}

Int32 Double::CompareTo(Double value) {
  if (*this < value) {
    return -1;
  }
  if (*this > value) {
    return 1;
  }
  if (*this == value) {
    return 0;
  }
  if (IsNaN(*this)) {
    if (!IsNaN(value)) {
      return -1;
    }
    return 0;
  }
  return 1;
}

Boolean Double::Equals(Object obj) {
  if (!rt::is<Double>(obj)) {
    return false;
  }
  Double num = (Double)obj;
  if (num == *this) {
    return true;
  }
  if (IsNaN(num)) {
    return IsNaN(*this);
  }
  return false;
}

Boolean Double::op_Equality(Double left, Double right) {
  return left == right;
}

Boolean Double::op_Inequality(Double left, Double right) {
  return left != right;
}

Boolean Double::op_LessThan(Double left, Double right) {
  return left < right;
}

Boolean Double::op_GreaterThan(Double left, Double right) {
  return left > right;
}

Boolean Double::op_LessThanOrEqual(Double left, Double right) {
  return left <= right;
}

Boolean Double::op_GreaterThanOrEqual(Double left, Double right) {
  return left >= right;
}

Boolean Double::Equals(Double obj) {
  if (obj == *this) {
    return true;
  }
  if (IsNaN(obj)) {
    return IsNaN(*this);
  }
  return false;
}

Int32 Double::GetHashCode() {
  Int64 num = Unsafe::As<Double, Int64>(Unsafe::AsRef(m_value));
  if (((num - 1) & Int64::MaxValue) >= 9218868437227405312) {
    num &= 9218868437227405312;
  }
  return (Int32)num ^ (Int32)(num >> 32);
}

String Double::ToString() {
  return Number::FormatDouble(*this, nullptr, NumberFormatInfo::in::get_CurrentInfo());
}

String Double::ToString(String format) {
  return Number::FormatDouble(*this, format, NumberFormatInfo::in::get_CurrentInfo());
}

String Double::ToString(IFormatProvider provider) {
  return Number::FormatDouble(*this, nullptr, NumberFormatInfo::in::GetInstance(provider));
}

String Double::ToString(String format, IFormatProvider provider) {
  return Number::FormatDouble(*this, format, NumberFormatInfo::in::GetInstance(provider));
}

template <>
Boolean Double::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatDouble(*this, format, NumberFormatInfo::in::GetInstance(provider), destination, charsWritten);
}

Double Double::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDouble(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, NumberFormatInfo::in::get_CurrentInfo());
}

Double Double::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDouble(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Double Double::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDouble(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, NumberFormatInfo::in::GetInstance(provider));
}

Double Double::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDouble(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Double Double::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return Number::ParseDouble(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean Double::TryParse(String s, Double& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Double::TryParse(ReadOnlySpan<Char> s, Double& result) {
  return TryParse(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Double::TryParse(String s, NumberStyles style, IFormatProvider provider, Double& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Double::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Double& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return TryParse(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Double::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Double& result) {
  return Number::TryParseDouble(s, style, info, result);
}

TypeCode Double::GetTypeCode() {
  return TypeCode::Double;
}

Boolean Double::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(*this);
}

Char Double::ToCharOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Double", "Char"));
}

SByte Double::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Double::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 Double::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 Double::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Double::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Double::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Double::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 Double::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Double::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(*this);
}

Double Double::ToDoubleOfIConvertible(IFormatProvider provider) {
  return *this;
}

Decimal Double::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime Double::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Double", "DateTime"));
}

Object Double::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

} // namespace System::Private::CoreLib::System::DoubleNamespace
