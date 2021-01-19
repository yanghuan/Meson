#include "Single-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::SingleNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;

Boolean Single::IsFinite(Single f) {
  Int32 num = BitConverter::SingleToInt32Bits(f);
  return (num & 2147483647) < 2139095040;
}

Boolean Single::IsInfinity(Single f) {
  Int32 num = BitConverter::SingleToInt32Bits(f);
  return (num & 2147483647) == 2139095040;
}

Boolean Single::IsNaN(Single f) {
  return f != f;
}

Boolean Single::IsNegative(Single f) {
  return BitConverter::SingleToInt32Bits(f) < 0;
}

Boolean Single::IsNegativeInfinity(Single f) {
  return f == Single::NegativeInfinity;
}

Boolean Single::IsNormal(Single f) {
  Int32 num = BitConverter::SingleToInt32Bits(f);
  num &= 2147483647;
  if (num < 2139095040 && num != 0) {
    return (num & 2139095040) != 0;
  }
  return false;
}

Boolean Single::IsPositiveInfinity(Single f) {
  return f == Single::PositiveInfinity;
}

Boolean Single::IsSubnormal(Single f) {
  Int32 num = BitConverter::SingleToInt32Bits(f);
  num &= 2147483647;
  if (num < 2139095040 && num != 0) {
    return (num & 2139095040) == 0;
  }
  return false;
}

Int32 Single::ExtractExponentFromBits(UInt32 bits) {
  return (Int32)((bits >> 23) & 255);
}

UInt32 Single::ExtractSignificandFromBits(UInt32 bits) {
  return bits & 8388607u;
}

Int32 Single::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<Single>(value)) {
    Single num = (Single)value;
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
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeSingle());
}

Int32 Single::CompareTo(Single value) {
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

Boolean Single::op_Equality(Single left, Single right) {
  return left == right;
}

Boolean Single::op_Inequality(Single left, Single right) {
  return left != right;
}

Boolean Single::op_LessThan(Single left, Single right) {
  return left < right;
}

Boolean Single::op_GreaterThan(Single left, Single right) {
  return left > right;
}

Boolean Single::op_LessThanOrEqual(Single left, Single right) {
  return left <= right;
}

Boolean Single::op_GreaterThanOrEqual(Single left, Single right) {
  return left >= right;
}

Boolean Single::Equals(Object obj) {
  if (!rt::is<Single>(obj)) {
    return false;
  }
  Single num = (Single)obj;
  if (num == *this) {
    return true;
  }
  if (IsNaN(num)) {
    return IsNaN(*this);
  }
  return false;
}

Boolean Single::Equals(Single obj) {
  if (obj == *this) {
    return true;
  }
  if (IsNaN(obj)) {
    return IsNaN(*this);
  }
  return false;
}

Int32 Single::GetHashCode() {
  Int32 num = Unsafe::As<Single, Int32>(Unsafe::AsRef(m_value));
  if (((num - 1) & 2147483647) >= 2139095040) {
    num &= 2139095040;
  }
  return num;
}

String Single::ToString() {
  return Number::FormatSingle(*this, nullptr, NumberFormatInfo::in::get_CurrentInfo());
}

String Single::ToString(IFormatProvider provider) {
  return Number::FormatSingle(*this, nullptr, NumberFormatInfo::in::GetInstance(provider));
}

String Single::ToString(String format) {
  return Number::FormatSingle(*this, format, NumberFormatInfo::in::get_CurrentInfo());
}

String Single::ToString(String format, IFormatProvider provider) {
  return Number::FormatSingle(*this, format, NumberFormatInfo::in::GetInstance(provider));
}

template <>
Boolean Single::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatSingle(*this, format, NumberFormatInfo::in::GetInstance(provider), destination, charsWritten);
}

Single Single::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseSingle(s, NumberStyles::Float | NumberStyles::AllowThousands, NumberFormatInfo::in::get_CurrentInfo());
}

Single Single::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseSingle(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Single Single::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseSingle(s, NumberStyles::Float | NumberStyles::AllowThousands, NumberFormatInfo::in::GetInstance(provider));
}

Single Single::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseSingle(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Single Single::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return Number::ParseSingle(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean Single::TryParse(String s, Single& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, NumberStyles::Float | NumberStyles::AllowThousands, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Single::TryParse(ReadOnlySpan<Char> s, Single& result) {
  return TryParse(s, NumberStyles::Float | NumberStyles::AllowThousands, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Single::TryParse(String s, NumberStyles style, IFormatProvider provider, Single& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Single::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Single& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return TryParse(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Single::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Single& result) {
  return Number::TryParseSingle(s, style, info, result);
}

TypeCode Single::GetTypeCode() {
  return TypeCode::Single;
}

Boolean Single::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(*this);
}

Char Single::ToCharOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Single", "Char"));
}

SByte Single::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Single::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 Single::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 Single::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Single::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Single::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Single::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 Single::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Single::ToSingleOfIConvertible(IFormatProvider provider) {
  return *this;
}

Double Single::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(*this);
}

Decimal Single::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime Single::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Single", "DateTime"));
}

Object Single::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

} // namespace System::Private::CoreLib::System::SingleNamespace
