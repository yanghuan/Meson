#include "Math-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArithmeticException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Numerics/VectorMath-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Bmi2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::MathNamespace {
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Int16 Math::Abs(Int16 value) {
  if (value < 0) {
    value = (Int16)(-value);
    if (value < 0) {
      ThrowAbsOverflow();
    }
  }
  return value;
}

Int32 Math::Abs(Int32 value) {
  if (value < 0) {
    value = -value;
    if (value < 0) {
      ThrowAbsOverflow();
    }
  }
  return value;
}

Int64 Math::Abs(Int64 value) {
  if (value < 0) {
    value = -value;
    if (value < 0) {
      ThrowAbsOverflow();
    }
  }
  return value;
}

SByte Math::Abs(SByte value) {
  if (value < 0) {
    value = (SByte)(-value);
    if (value < 0) {
      ThrowAbsOverflow();
    }
  }
  return value;
}

Decimal Math::Abs(Decimal value) {
  return Decimal::Abs(value);
}

void Math::ThrowAbsOverflow() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_NegateTwosCompNum());
}

Int64 Math::BigMul(Int32 a, Int32 b) {
  return (Int64)a * (Int64)b;
}

UInt64 Math::BigMul(UInt64 a, UInt64 b, UInt64& low) {
  auto SoftwareFallback = [](UInt64 a, UInt64 b, UInt64& low) -> UInt64 {
    UInt32 num2 = (UInt32)a;
    UInt32 num3 = (UInt32)(a >> 32);
    UInt32 num4 = (UInt32)b;
    UInt32 num5 = (UInt32)(b >> 32);
    UInt64 num6 = (UInt64)num2 * (UInt64)num4;
    UInt64 num7 = (UInt64)((Int64)num3 * (Int64)num4) + (num6 >> 32);
    UInt64 num8 = (UInt64)((Int64)num2 * (Int64)num5 + (UInt32)num7);
    low = ((num8 << 32) | (UInt32)num6);
    return (UInt64)((Int64)num3 * (Int64)num5 + (Int64)(num7 >> 32)) + (num8 >> 32);
  };
  if (Bmi2::in::X64::in::get_IsSupported()) {
    UInt64 num;
    UInt64 result = Bmi2::in::X64::in::MultiplyNoFlags(a, b, &num);
    low = num;
    return result;
  }
  return SoftwareFallback(a, b, low);
}

Int64 Math::BigMul(Int64 a, Int64 b, Int64& low) {
  UInt64 low2;
  UInt64 num = BigMul((UInt64)a, (UInt64)b, low2);
  low = (Int64)low2;
  return (Int64)num - ((a >> 63) & b) - ((b >> 63) & a);
}

Double Math::BitDecrement(Double x) {
  Int64 num = BitConverter::DoubleToInt64Bits(x);
  if (((num >> 32) & 2146435072) >= 2146435072) {
    if (num != 9218868437227405312) {
      return x;
    }
    return Double::MaxValue;
  }
  if (num == 0) {
    return -5E-324;
  }
  num += ((num < 0) ? 1 : (-1));
  return BitConverter::Int64BitsToDouble(num);
}

Double Math::BitIncrement(Double x) {
  Int64 num = BitConverter::DoubleToInt64Bits(x);
  if (((num >> 32) & 2146435072) >= 2146435072) {
    if (num != -4503599627370496) {
      return x;
    }
    return Double::MinValue;
  }
  if (num == Int64::MinValue) {
    return Double::Epsilon;
  }
  num += ((num >= 0) ? 1 : (-1));
  return BitConverter::Int64BitsToDouble(num);
}

Double Math::CopySign(Double x, Double y) {
  auto SoftwareFallback = [](Double x, Double y) -> Double {
    Int64 num = BitConverter::DoubleToInt64Bits(x);
    Int64 num2 = BitConverter::DoubleToInt64Bits(y);
    num &= Int64::MaxValue;
    num2 &= Int64::MinValue;
    return BitConverter::Int64BitsToDouble(num | num2);
  };
  if (Sse::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Vector128<>::ToScalar(VectorMath::ConditionalSelectBitwise(Vector128<>::CreateScalarUnsafe(-0), Vector128<>::CreateScalarUnsafe(y), Vector128<>::CreateScalarUnsafe(x)));
  }
  return SoftwareFallback(x, y);
}

Int32 Math::DivRem(Int32 a, Int32 b, Int32& result) {
  Int32 num = a / b;
  result = a - num * b;
  return num;
}

Int64 Math::DivRem(Int64 a, Int64 b, Int64& result) {
  Int64 num = a / b;
  result = a - num * b;
  return num;
}

UInt32 Math::DivRem(UInt32 a, UInt32 b, UInt32& result) {
  UInt32 num = a / b;
  result = a - num * b;
  return num;
}

UInt64 Math::DivRem(UInt64 a, UInt64 b, UInt64& result) {
  UInt64 num = a / b;
  result = a - num * b;
  return num;
}

Decimal Math::Ceiling(Decimal d) {
  return Decimal::Ceiling(d);
}

Byte Math::Clamp(Byte value, Byte min, Byte max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Decimal Math::Clamp(Decimal value, Decimal min, Decimal max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Double Math::Clamp(Double value, Double min, Double max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Int16 Math::Clamp(Int16 value, Int16 min, Int16 max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Int32 Math::Clamp(Int32 value, Int32 min, Int32 max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Int64 Math::Clamp(Int64 value, Int64 min, Int64 max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

SByte Math::Clamp(SByte value, SByte min, SByte max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Single Math::Clamp(Single value, Single min, Single max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

UInt16 Math::Clamp(UInt16 value, UInt16 min, UInt16 max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

UInt32 Math::Clamp(UInt32 value, UInt32 min, UInt32 max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

UInt64 Math::Clamp(UInt64 value, UInt64 min, UInt64 max) {
  if (min > max) {
    ThrowMinMaxException(min, max);
  }
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

Decimal Math::Floor(Decimal d) {
  return Decimal::Floor(d);
}

Double Math::IEEERemainder(Double x, Double y) {
  if (Double::IsNaN(x)) {
    return x;
  }
  if (Double::IsNaN(y)) {
    return y;
  }
  Double num = x % y;
  if (Double::IsNaN(num)) {
    return Double::NaN;
  }
  if (num == 0 && Double::IsNegative(x)) {
    return -0;
  }
  Double num2 = num - Abs(y) * (Double)Sign(x);
  if (Abs(num2) == Abs(num)) {
    Double num3 = x / y;
    Double value = Round(num3);
    if (Abs(value) > Abs(num3)) {
      return num2;
    }
    return num;
  }
  if (Abs(num2) < Abs(num)) {
    return num2;
  }
  return num;
}

Double Math::Log(Double a, Double newBase) {
  if (Double::IsNaN(a)) {
    return a;
  }
  if (Double::IsNaN(newBase)) {
    return newBase;
  }
  if (newBase == 1) {
    return Double::NaN;
  }
  if (a != 1 && (newBase == 0 || Double::IsPositiveInfinity(newBase))) {
    return Double::NaN;
  }
  return Log(a) / Log(newBase);
}

Byte Math::Max(Byte val1, Byte val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

Decimal Math::Max(Decimal val1, Decimal val2) {
  return Decimal::Max(val1, val2);
}

Double Math::Max(Double val1, Double val2) {
  if (val1 != val2) {
    if (!Double::IsNaN(val1)) {
      if (!(val2 < val1)) {
        return val2;
      }
      return val1;
    }
    return val1;
  }
  if (!Double::IsNegative(val2)) {
    return val2;
  }
  return val1;
}

Int16 Math::Max(Int16 val1, Int16 val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

Int32 Math::Max(Int32 val1, Int32 val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

Int64 Math::Max(Int64 val1, Int64 val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

SByte Math::Max(SByte val1, SByte val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

Single Math::Max(Single val1, Single val2) {
  if (val1 != val2) {
    if (!Single::IsNaN(val1)) {
      if (!(val2 < val1)) {
        return val2;
      }
      return val1;
    }
    return val1;
  }
  if (!Single::IsNegative(val2)) {
    return val2;
  }
  return val1;
}

UInt16 Math::Max(UInt16 val1, UInt16 val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

UInt32 Math::Max(UInt32 val1, UInt32 val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

UInt64 Math::Max(UInt64 val1, UInt64 val2) {
  if (val1 < val2) {
    return val2;
  }
  return val1;
}

Double Math::MaxMagnitude(Double x, Double y) {
  Double num = Abs(x);
  Double num2 = Abs(y);
  if (num > num2 || Double::IsNaN(num)) {
    return x;
  }
  if (num == num2) {
    if (!Double::IsNegative(x)) {
      return x;
    }
    return y;
  }
  return y;
}

Byte Math::Min(Byte val1, Byte val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

Decimal Math::Min(Decimal val1, Decimal val2) {
  return Decimal::Min(val1, val2);
}

Double Math::Min(Double val1, Double val2) {
  if (val1 != val2 && !Double::IsNaN(val1)) {
    if (!(val1 < val2)) {
      return val2;
    }
    return val1;
  }
  if (!Double::IsNegative(val1)) {
    return val2;
  }
  return val1;
}

Int16 Math::Min(Int16 val1, Int16 val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

Int32 Math::Min(Int32 val1, Int32 val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

Int64 Math::Min(Int64 val1, Int64 val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

SByte Math::Min(SByte val1, SByte val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

Single Math::Min(Single val1, Single val2) {
  if (val1 != val2 && !Single::IsNaN(val1)) {
    if (!(val1 < val2)) {
      return val2;
    }
    return val1;
  }
  if (!Single::IsNegative(val1)) {
    return val2;
  }
  return val1;
}

UInt16 Math::Min(UInt16 val1, UInt16 val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

UInt32 Math::Min(UInt32 val1, UInt32 val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

UInt64 Math::Min(UInt64 val1, UInt64 val2) {
  if (val1 > val2) {
    return val2;
  }
  return val1;
}

Double Math::MinMagnitude(Double x, Double y) {
  Double num = Abs(x);
  Double num2 = Abs(y);
  if (num < num2 || Double::IsNaN(num)) {
    return x;
  }
  if (num == num2) {
    if (!Double::IsNegative(x)) {
      return y;
    }
    return x;
  }
  return y;
}

Decimal Math::Round(Decimal d) {
  return Decimal::Round(d, 0);
}

Decimal Math::Round(Decimal d, Int32 decimals) {
  return Decimal::Round(d, decimals);
}

Decimal Math::Round(Decimal d, MidpointRounding mode) {
  return Decimal::Round(d, 0, mode);
}

Decimal Math::Round(Decimal d, Int32 decimals, MidpointRounding mode) {
  return Decimal::Round(d, decimals, mode);
}

Double Math::Round(Double a) {
  UInt64 num = (UInt64)BitConverter::DoubleToInt64Bits(a);
  Int32 num2 = Double::ExtractExponentFromBits(num);
  if (num2 <= 1022) {
    if (num << 1 == 0) {
      return a;
    }
    Double x = (num2 == 1022 && Double::ExtractSignificandFromBits(num) != 0) ? 1 : 0;
    return CopySign(x, a);
  }
  if (num2 >= 1075) {
    return a;
  }
  UInt64 num3 = (UInt64)(1 << 1075 - num2);
  UInt64 num4 = num3 - 1;
  num += num3 >> 1;
  num = (((num & num4) != 0) ? (num & ~num4) : (num & ~num3));
  return BitConverter::Int64BitsToDouble((Int64)num);
}

Double Math::Round(Double value, Int32 digits) {
  return Round(value, digits, MidpointRounding::ToEven);
}

Double Math::Round(Double value, MidpointRounding mode) {
  return Round(value, 0, mode);
}

Double Math::Round(Double value, Int32 digits, MidpointRounding mode) {
  if (digits < 0 || digits > 15) {
    rt::throw_exception<ArgumentOutOfRangeException>("digits", SR::get_ArgumentOutOfRange_RoundingDigits());
  }
  if (mode < MidpointRounding::ToEven || mode > MidpointRounding::ToPositiveInfinity) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidEnumValue(), mode, "MidpointRounding"), "mode");
  }
  if (Abs(value) < 10000000000000000) {
    Double num = roundPower10Double[digits];
    value *= num;
    switch (mode) {
      case MidpointRounding::ToEven:
        value = Round(value);
        break;
      case MidpointRounding::AwayFromZero:
        {
          Double value2 = ModF(value, &value);
          if (Abs(value2) >= 0.5) {
            value += (Double)Sign(value2);
          }
          break;
        }case MidpointRounding::ToZero:
        value = Truncate(value);
        break;
      case MidpointRounding::ToNegativeInfinity:
        value = Floor(value);
        break;
      case MidpointRounding::ToPositiveInfinity:
        value = Ceiling(value);
        break;
      default:
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidEnumValue(), mode, "MidpointRounding"), "mode");
    }
    value /= num;
  }
  return value;
}

Int32 Math::Sign(Decimal value) {
  return Decimal::Sign(value);
}

Int32 Math::Sign(Double value) {
  if (value < 0) {
    return -1;
  }
  if (value > 0) {
    return 1;
  }
  if (value == 0) {
    return 0;
  }
  rt::throw_exception<ArithmeticException>(SR::get_Arithmetic_NaN());
}

Int32 Math::Sign(Int16 value) {
  return Sign((Int32)value);
}

Int32 Math::Sign(Int32 value) {
  return (value >> 31) | (Int32)((UInt32)(-value) >> 31);
}

Int32 Math::Sign(Int64 value) {
  return (Int32)((value >> 63) | (Int64)((UInt64)(-value) >> 63));
}

Int32 Math::Sign(SByte value) {
  return Sign((Int32)value);
}

Int32 Math::Sign(Single value) {
  if (value < 0) {
    return -1;
  }
  if (value > 0) {
    return 1;
  }
  if (value == 0) {
    return 0;
  }
  rt::throw_exception<ArithmeticException>(SR::get_Arithmetic_NaN());
}

Decimal Math::Truncate(Decimal d) {
  return Decimal::Truncate(d);
}

Double Math::Truncate(Double d) {
  ModF(d, &d);
  return d;
}

void Math::cctor() {
  roundPower10Double = rt::newarr<Array<Double>>(16);
}

UInt64 Math::_BigMul_g__SoftwareFallback42_0(UInt64 a, UInt64 b, UInt64& low) {
  UInt32 num = (UInt32)a;
  UInt32 num2 = (UInt32)(a >> 32);
  UInt32 num3 = (UInt32)b;
  UInt32 num4 = (UInt32)(b >> 32);
  UInt64 num5 = (UInt64)num * (UInt64)num3;
  UInt64 num6 = (UInt64)((Int64)num2 * (Int64)num3) + (num5 >> 32);
  UInt64 num7 = (UInt64)((Int64)num * (Int64)num4 + (UInt32)num6);
  low = ((num7 << 32) | (UInt32)num5);
  return (UInt64)((Int64)num2 * (Int64)num4 + (Int64)(num6 >> 32)) + (num7 >> 32);
}

Double Math::_CopySign_g__SoftwareFallback46_0(Double x, Double y) {
  Int64 num = BitConverter::DoubleToInt64Bits(x);
  Int64 num2 = BitConverter::DoubleToInt64Bits(y);
  num &= Int64::MaxValue;
  num2 &= Int64::MinValue;
  return BitConverter::Int64BitsToDouble(num | num2);
}

} // namespace System::Private::CoreLib::System::MathNamespace
