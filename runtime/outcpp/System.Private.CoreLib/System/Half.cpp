#include "Half-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Half-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/ValueTuple-dep.h>

namespace System::Private::CoreLib::System::HalfNamespace {
using namespace System::Globalization;
using namespace System::Numerics;

Half Half::get_Epsilon() {
  return Half(1);
}

Half Half::get_PositiveInfinity() {
  return Half(31744);
}

Half Half::get_NegativeInfinity() {
  return Half(64512);
}

Half Half::get_NaN() {
  return Half(65024);
}

Half Half::get_MinValue() {
  return Half(64511);
}

Half Half::get_MaxValue() {
  return Half(31743);
}

SByte Half::get_Exponent() {
  return (SByte)((_value & 31744) >> 10);
}

UInt16 Half::get_Significand() {
  return (UInt16)(_value & 1023);
}

Half::Half(UInt16 value) {
  _value = value;
}

Half::Half(Boolean sign, UInt16 exp, UInt16 sig) {
  _value = (UInt16)(((sign ? 1 : 0) << 15) + (exp << 10) + sig);
}

Boolean Half::op_LessThan(Half left, Half right) {
  if (IsNaN(left) || IsNaN(right)) {
    return false;
  }
  Boolean flag = IsNegative(left);
  if (flag != IsNegative(right)) {
    if (flag) {
      return !AreZero(left, right);
    }
    return false;
  }
  return (left._value < right._value) ^ flag;
}

Boolean Half::op_GreaterThan(Half left, Half right) {
  return right < left;
}

Boolean Half::op_LessThanOrEqual(Half left, Half right) {
  if (IsNaN(left) || IsNaN(right)) {
    return false;
  }
  Boolean flag = IsNegative(left);
  if (flag != IsNegative(right)) {
    if (!flag) {
      return AreZero(left, right);
    }
    return true;
  }
  return (left._value <= right._value) ^ flag;
}

Boolean Half::op_GreaterThanOrEqual(Half left, Half right) {
  return right <= left;
}

Boolean Half::op_Equality(Half left, Half right) {
  return left.Equals(right);
}

Boolean Half::op_Inequality(Half left, Half right) {
  return !left.Equals(right);
}

Boolean Half::IsFinite(Half value) {
  return StripSign(value) < 31744;
}

Boolean Half::IsInfinity(Half value) {
  return StripSign(value) == 31744;
}

Boolean Half::IsNaN(Half value) {
  return StripSign(value) > 31744;
}

Boolean Half::IsNegative(Half value) {
  return (Int16)value._value < 0;
}

Boolean Half::IsNegativeInfinity(Half value) {
  return value._value == 64512;
}

Boolean Half::IsNormal(Half value) {
  UInt32 num = StripSign(value);
  if (num < 31744 && num != 0) {
    return (num & 31744) != 0;
  }
  return false;
}

Boolean Half::IsPositiveInfinity(Half value) {
  return value._value == 31744;
}

Boolean Half::IsSubnormal(Half value) {
  UInt32 num = StripSign(value);
  if (num < 31744 && num != 0) {
    return (num & 31744) == 0;
  }
  return false;
}

Half Half::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseHalf(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, NumberFormatInfo::in::get_CurrentInfo());
}

Half Half::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseHalf(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Half Half::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseHalf(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, NumberFormatInfo::in::GetInstance(provider));
}

Half Half::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseHalf(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Half Half::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return Number::ParseHalf(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean Half::TryParse(String s, Half& result) {
  if (s == nullptr) {
    result = rt::default__;
    return false;
  }
  return TryParse(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, nullptr, result);
}

Boolean Half::TryParse(ReadOnlySpan<Char> s, Half& result) {
  return TryParse(s, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, nullptr, result);
}

Boolean Half::TryParse(String s, NumberStyles style, IFormatProvider provider, Half& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    result = rt::default__;
    return false;
  }
  return TryParse(MemoryExtensions::AsSpan(s), style, provider, result);
}

Boolean Half::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Half& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return Number::TryParseHalf(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Half::AreZero(Half left, Half right) {
  return (UInt16)((left._value | right._value) & -32769) == 0;
}

Boolean Half::IsNaNOrZero(Half value) {
  return ((value._value - 1) & -32769) >= 31744;
}

UInt32 Half::StripSign(Half value) {
  return (UInt16)(value._value & -32769);
}

Int32 Half::CompareTo(Object obj) {
  if (!rt::is<Half>(obj)) {
    if (obj != nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeHalf());
    }
    return 1;
  }
  return CompareTo((Half)obj);
}

Int32 Half::CompareTo(Half other) {
  if (*this < other) {
    return -1;
  }
  if (*this > other) {
    return 1;
  }
  if (*this == other) {
    return 0;
  }
  if (IsNaN(*this)) {
    if (!IsNaN(other)) {
      return -1;
    }
    return 0;
  }
  return 1;
}

Boolean Half::Equals(Object obj) {
  if (rt::is<Half>(obj)) {
    Half other = (Half)obj;
    return Equals(other);
  }
  return false;
}

Boolean Half::Equals(Half other) {
  if (IsNaN(*this) || IsNaN(other)) {
    return false;
  }
  if (_value != other._value) {
    return AreZero(*this, other);
  }
  return true;
}

Int32 Half::GetHashCode() {
  if (IsNaNOrZero(*this)) {
    return _value & 31744;
  }
  return _value;
}

String Half::ToString() {
  return Number::FormatHalf(*this, nullptr, NumberFormatInfo::in::get_CurrentInfo());
}

String Half::ToString(String format) {
  return Number::FormatHalf(*this, format, NumberFormatInfo::in::get_CurrentInfo());
}

String Half::ToString(IFormatProvider provider) {
  return Number::FormatHalf(*this, nullptr, NumberFormatInfo::in::GetInstance(provider));
}

String Half::ToString(String format, IFormatProvider provider) {
  return Number::FormatHalf(*this, format, NumberFormatInfo::in::GetInstance(provider));
}

template <>
Boolean Half::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatHalf(*this, format, NumberFormatInfo::in::GetInstance(provider), destination, charsWritten);
}

Half Half::op_Explicit(Single value) {
  UInt32 num = (UInt32)BitConverter::SingleToInt32Bits(value);
  Boolean flag = (UInt32)((Int32)num & Int32::MinValue) >> 31 != 0;
  Int32 num2 = (Int32)(num & 2139095040) >> 23;
  UInt32 num3 = num & 8388607;
  if (num2 == 255) {
    if (num3 != 0) {
      return CreateHalfNaN(flag, (UInt64)num3 << 41);
    }
    if (!flag) {
      return get_PositiveInfinity();
    }
    return get_NegativeInfinity();
  }
  UInt32 num4 = (num3 >> 9) | (UInt32)(((num3 & 511) != 0) ? 1 : 0);
  if ((num2 | (Int32)num4) == 0) {
    return Half(flag, 0, 0);
  }
  return Half(RoundPackToHalf(flag, (Int16)(num2 - 113), (UInt16)(num4 | 16384)));
}

Half Half::op_Explicit(Double value) {
  UInt64 num = (UInt64)BitConverter::DoubleToInt64Bits(value);
  Boolean flag = (UInt64)((Int64)num & Int64::MinValue) >> 63 != 0;
  Int32 num2 = (Int32)((num & 9218868437227405312) >> 52);
  UInt64 num3 = num & 4503599627370495;
  if (num2 == 2047) {
    if (num3 != 0) {
      return CreateHalfNaN(flag, num3 << 12);
    }
    if (!flag) {
      return get_PositiveInfinity();
    }
    return get_NegativeInfinity();
  }
  UInt32 num4 = (UInt32)ShiftRightJam(num3, 38);
  if ((num2 | (Int32)num4) == 0) {
    return Half(flag, 0, 0);
  }
  return Half(RoundPackToHalf(flag, (Int16)(num2 - 1009), (UInt16)(num4 | 16384)));
}

Single Half::op_Explicit(Half value, Single) {
  Boolean flag = IsNegative(value);
  Int32 num = value.get_Exponent();
  UInt32 num2 = value.get_Significand();
  switch (num.get()) {
    case 31:
      if (num2 != 0) {
        return CreateSingleNaN(flag, (UInt64)num2 << 54);
      }
      if (!flag) {
        return Single::PositiveInfinity;
      }
      return Single::NegativeInfinity;
    case 0:
      {
        if (num2 == 0) {
          return BitConverter::Int32BitsToSingle(flag ? Int32::MinValue : 0);
        }
        ValueTuple<Int32, UInt32> tuple = NormSubnormalF16Sig(num2);
        num = tuple.Item1;
        num2 = tuple.Item2;
        num--;
        break;
      }}
  return CreateSingle(flag, (Byte)(num + 112), num2 << 13);
}

Double Half::op_Explicit(Half value, Double) {
  Boolean flag = IsNegative(value);
  Int32 num = value.get_Exponent();
  UInt32 num2 = value.get_Significand();
  switch (num.get()) {
    case 31:
      if (num2 != 0) {
        return CreateDoubleNaN(flag, (UInt64)num2 << 54);
      }
      if (!flag) {
        return Double::PositiveInfinity;
      }
      return Double::NegativeInfinity;
    case 0:
      {
        if (num2 == 0) {
          return BitConverter::Int64BitsToDouble(flag ? Int64::MinValue : 0);
        }
        ValueTuple<Int32, UInt32> tuple = NormSubnormalF16Sig(num2);
        num = tuple.Item1;
        num2 = tuple.Item2;
        num--;
        break;
      }}
  return CreateDouble(flag, (UInt16)(num + 1008), (UInt64)num2 << 42);
}

Half Half::Negate(Half value) {
  if (!IsNaN(value)) {
    return Half((UInt16)(value._value ^ 32768));
  }
  return value;
}

ValueTuple<Int32, UInt32> Half::NormSubnormalF16Sig(UInt32 sig) {
  Int32 num = BitOperations::LeadingZeroCount(sig) - 16 - 5;
  return {1 - num, sig << num};
}

Half Half::CreateHalfNaN(Boolean sign, UInt64 significand) {
  UInt32 num = (UInt32)((sign ? 1 : 0) << 15);
  UInt32 num2 = (UInt32)(significand >> 54);
  return BitConverter::Int16BitsToHalf((Int16)(num | 32256 | num2));
}

UInt16 Half::RoundPackToHalf(Boolean sign, Int16 exp, UInt16 sig) {
  Int32 num = sig & 15;
  if ((UInt32)exp >= 29u) {
    if (exp < 0) {
      sig = (UInt16)ShiftRightJam(sig, -exp);
      exp = 0;
    } else if (exp > 29 || sig + 8 >= 32768) {
      if (!sign) {
        return 31744;
      }
      return 64512;
    }

  }
  sig = (UInt16)(sig + 8 >> 4);
  sig = (UInt16)(sig & (UInt16)(~((((num ^ 8) == 0) ? 1 : 0) & 1)));
  if (sig == 0) {
    exp = 0;
  }
  return Half(sign, (UInt16)exp, sig)._value;
}

UInt32 Half::ShiftRightJam(UInt32 i, Int32 dist) {
  if (dist >= 31) {
    if (i == 0) {
      return 0u;
    }
    return 1u;
  }
  return (i >> dist) | (UInt32)((i << -dist != 0) ? 1 : 0);
}

UInt64 Half::ShiftRightJam(UInt64 l, Int32 dist) {
  if (dist >= 63) {
    if (l == 0) {
      return 0;
    }
    return 1;
  }
  return (l >> dist) | (UInt64)((l << -dist != 0) ? 1 : 0);
}

Single Half::CreateSingleNaN(Boolean sign, UInt64 significand) {
  UInt32 num = (UInt32)((sign ? 1 : 0) << 31);
  UInt32 num2 = (UInt32)(significand >> 41);
  return BitConverter::Int32BitsToSingle((Int32)(num | 2143289344 | num2));
}

Double Half::CreateDoubleNaN(Boolean sign, UInt64 significand) {
  UInt64 num = (UInt64)((Int64)(sign ? 1 : 0) << 63);
  UInt64 num2 = significand >> 12;
  return BitConverter::Int64BitsToDouble((Int64)(num | 9221120237041090560 | num2));
}

Single Half::CreateSingle(Boolean sign, Byte exp, UInt32 sig) {
  return BitConverter::Int32BitsToSingle(((sign ? 1 : 0) << 31) | (exp << 23) | (Int32)sig);
}

Double Half::CreateDouble(Boolean sign, UInt16 exp, UInt64 sig) {
  return BitConverter::Int64BitsToDouble(((Int64)(sign ? 1 : 0) << 63) | (Int64)((UInt64)exp << 52) | (Int64)sig);
}

void Half::cctor() {
  PositiveZero = Half(0);
  NegativeZero = Half(32768);
}

} // namespace System::Private::CoreLib::System::HalfNamespace
