#include "Decimal-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Decimal-dep.h>
#include <System.Private.CoreLib/System/DivideByZeroException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MidpointRounding.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse41-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>

namespace System::Private::CoreLib::System::DecimalNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers::Binary;
using namespace System::Globalization;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics::X86;

UInt64 Decimal::DecCalc::Buf24::get_Low64() {
  return ulo64LE;
}

void Decimal::DecCalc::Buf24::set_Low64(UInt64 value) {
  ulo64LE = value;
}

void Decimal::DecCalc::Buf24::set_Mid64(UInt64 value) {
  umid64LE = value;
}

void Decimal::DecCalc::Buf24::set_High64(UInt64 value) {
  uhigh64LE = value;
}

Decimal::DecCalc::PowerOvfl::PowerOvfl(UInt32 hi, UInt32 mid, UInt32 lo) {
  Hi = hi;
  MidLo = ((UInt64)mid << 32) + lo;
}

UInt64 Decimal::DecCalc::Buf12::get_Low64() {
  return ulo64LE;
}

void Decimal::DecCalc::Buf12::set_Low64(UInt64 value) {
  ulo64LE = value;
}

UInt64 Decimal::DecCalc::Buf12::get_High64() {
  return uhigh64LE;
}

void Decimal::DecCalc::Buf12::set_High64(UInt64 value) {
  uhigh64LE = value;
}

UInt64 Decimal::DecCalc::Buf16::get_Low64() {
  return ulo64LE;
}

void Decimal::DecCalc::Buf16::set_Low64(UInt64 value) {
  ulo64LE = value;
}

UInt64 Decimal::DecCalc::Buf16::get_High64() {
  return uhigh64LE;
}

void Decimal::DecCalc::Buf16::set_High64(UInt64 value) {
  uhigh64LE = value;
}

UInt32 Decimal::DecCalc::get_High() {
  return uhi;
}

void Decimal::DecCalc::set_High(UInt32 value) {
  uhi = value;
}

UInt32 Decimal::DecCalc::get_Low() {
  return ulo;
}

void Decimal::DecCalc::set_Low(UInt32 value) {
  ulo = value;
}

UInt32 Decimal::DecCalc::get_Mid() {
  return umid;
}

void Decimal::DecCalc::set_Mid(UInt32 value) {
  umid = value;
}

Boolean Decimal::DecCalc::get_IsNegative() {
  return (Int32)uflags < 0;
}

Int32 Decimal::DecCalc::get_Scale() {
  return (Byte)(uflags >> 16);
}

UInt64 Decimal::DecCalc::get_Low64() {
  return ulomidLE;
}

void Decimal::DecCalc::set_Low64(UInt64 value) {
  ulomidLE = value;
}

UInt32 Decimal::DecCalc::GetExponent(Single f) {
  return (Byte)(*(UInt32*)(&f) >> 23);
}

UInt32 Decimal::DecCalc::GetExponent(Double d) {
  return (UInt32)((Int32)((UInt64)(*(Int64*)(&d)) >> 52) & 2047);
}

UInt64 Decimal::DecCalc::UInt32x32To64(UInt32 a, UInt32 b) {
  return (UInt64)a * (UInt64)b;
}

void Decimal::DecCalc::UInt64x64To128(UInt64 a, UInt64 b, DecCalc& result) {
  UInt64 num = UInt32x32To64((UInt32)a, (UInt32)b);
  UInt64 num2 = UInt32x32To64((UInt32)a, (UInt32)(b >> 32));
  UInt64 num3 = UInt32x32To64((UInt32)(a >> 32), (UInt32)(b >> 32));
  num3 += num2 >> 32;
  num += (num2 <<= 32);
  if (num < num2) {
    num3++;
  }
  num2 = UInt32x32To64((UInt32)(a >> 32), (UInt32)b);
  num3 += num2 >> 32;
  num += (num2 <<= 32);
  if (num < num2) {
    num3++;
  }
  if (num3 > UInt32::MaxValue) {
    Number::ThrowOverflowException(TypeCode::Decimal);
  }
  result.set_Low64 = num;
  result.set_High = (UInt32)num3;
}

UInt32 Decimal::DecCalc::Div96By32(Buf12& bufNum, UInt32 den) {
  UInt64 high;
  UInt64 num2;
  if (bufNum.U2 != 0) {
    high = bufNum.set_High64;
    num2 = (bufNum.set_High64 = high / den);
    high = ((high - (UInt32)((Int32)num2 * (Int32)den) << 32) | bufNum.U0);
    if (high == 0) {
      return 0u;
    }
    return (UInt32)(Int32)high - (bufNum.U0 = (UInt32)(high / den)) * den;
  }
  high = bufNum.set_Low64;
  if (high == 0) {
    return 0u;
  }
  num2 = (bufNum.set_Low64 = high / den);
  return (UInt32)(high - num2 * den);
}

Boolean Decimal::DecCalc::Div96ByConst(UInt64& high64, UInt32& low, UInt32 pow) {
  UInt64 num = high64 / pow;
  UInt32 num2 = (UInt32)(((high64 - num * pow << 32) + low) / pow);
  if (low == num2 * pow) {
    high64 = num;
    low = num2;
    return true;
  }
  return false;
}

void Decimal::DecCalc::Unscale(UInt32& low, UInt64& high64, Int32& scale) {
  while ((Byte)low == 0 && scale >= 8 && Div96ByConst(high64, low, 100000000u)) {
    scale -= 8;
  }
  if ((low & 15) == 0 && scale >= 4 && Div96ByConst(high64, low, 10000u)) {
    scale -= 4;
  }
  if ((low & 3) == 0 && scale >= 2 && Div96ByConst(high64, low, 100u)) {
    scale -= 2;
  }
  if ((low & 1) == 0 && scale >= 1 && Div96ByConst(high64, low, 10u)) {
    scale--;
  }
}

UInt32 Decimal::DecCalc::Div96By64(Buf12& bufNum, UInt64 den) {
  UInt32 u = bufNum.U2;
  UInt32 num;
  UInt64 low;
  if (u == 0) {
    low = bufNum.set_Low64;
    if (low < den) {
      return 0u;
    }
    num = (UInt32)(low / den);
    low = (bufNum.set_Low64 = low - num * den);
    return num;
  }
  UInt32 num3 = (UInt32)(den >> 32);
  if (u >= num3) {
    low = bufNum.set_Low64;
    low -= den << 32;
    num = 0u;
  }
  UInt64 high = bufNum.get_High64();
  if (high < num3) {
    return 0u;
  }
  num = (UInt32)(high / num3);
  low = (bufNum.U0 | (high - num * num3 << 32));
  UInt64 num4 = UInt32x32To64(num, (UInt32)den);
  low -= num4;
  if (low > ~num4) {
  }
  bufNum.set_Low64 = low;
  return num;
}

UInt32 Decimal::DecCalc::Div128By96(Buf16& bufNum, Buf12& bufDen) {
  UInt64 high = bufNum.get_High64();
  UInt32 u = bufDen.U2;
  if (high < u) {
    return 0u;
  }
  UInt32 num = (UInt32)(high / u);
  UInt32 num2 = (UInt32)(Int32)high - num * u;
  UInt64 num3 = UInt32x32To64(num, bufDen.U0);
  UInt64 num4 = UInt32x32To64(num, bufDen.U1);
  num4 += num3 >> 32;
  num3 = ((UInt32)num3 | (num4 << 32));
  num4 >>= 32;
  UInt64 low = bufNum.get_Low64();
  low -= num3;
  num2 -= (UInt32)(Int32)num4;
  if (low > ~num3) {
    num2--;
    if (num2 >= (UInt32)(~num4)) {
    }
  } else if (num2 > (UInt32)(~num4)) {
  }

}

UInt32 Decimal::DecCalc::IncreaseScale(Buf12& bufNum, UInt32 power) {
  UInt64 num = UInt32x32To64(bufNum.U0, power);
  bufNum.U0 = (UInt32)num;
  num >>= 32;
  num += UInt32x32To64(bufNum.U1, power);
  bufNum.U1 = (UInt32)num;
  num >>= 32;
  num += UInt32x32To64(bufNum.U2, power);
  bufNum.U2 = (UInt32)num;
  return (UInt32)(num >> 32);
}

void Decimal::DecCalc::IncreaseScale64(Buf12& bufNum, UInt32 power) {
  UInt64 num = UInt32x32To64(bufNum.U0, power);
  bufNum.U0 = (UInt32)num;
  num >>= 32;
  num = (bufNum.set_High64 = num + UInt32x32To64(bufNum.U1, power));
}

Int32 Decimal::DecCalc::ScaleResult(Buf24* bufRes, UInt32 hiRes, Int32 scale) {
  Int32 num = 0;
  if (hiRes > 2) {
    num = (Int32)(hiRes * 32 - 64 - 1);
    num -= BitOperations::LeadingZeroCount(*(UInt32*)((Byte*)bufRes + (Int64)hiRes * 4));
    num = (num * 77 >> 8) + 1;
    if (num > scale) {
    }
  }
  if (num < scale - 28) {
    num = scale - 28;
  }
  if (num == 0) {
  }
  scale -= num;
  UInt32 num2 = 0u;
  UInt32 remainder = 0u;
  while (true) {
    num2 |= remainder;
    UInt32 quotient;
    UInt32 num3;
    switch (num.get()) {
      case 1:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 10u);
        break;
      case 2:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 100u);
        break;
      case 3:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 1000u);
        break;
      case 4:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 10000u);
        break;
      case 5:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 100000u);
        break;
      case 6:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 1000000u);
        break;
      case 7:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 10000000u);
        break;
      case 8:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 100000000u);
        break;
      default:
        num3 = DivByConst((UInt32*)bufRes, hiRes, quotient, remainder, 1000000000u);
        break;
    }
    *(UInt32*)((Byte*)bufRes + (Int64)hiRes * 4) = quotient;
    if (quotient == 0 && hiRes != 0) {
      hiRes--;
    }
    num -= 9;
    if (num > 0) {
      continue;
    }
    if (hiRes > 2) {
      if (scale == 0) {
        break;
      }
      num = 1;
      scale--;
      continue;
    }
    num3 >>= 1;
    if (num3 <= remainder && (num3 < remainder || ((*(UInt32*)bufRes & 1) | num2) != 0) && ++(*(Int32*)bufRes) == 0) {
      UInt32 num4 = 0u;
      while (++(*(Int32*)((Byte*)bufRes + (Int64)(++num4) * 4)) == 0) {
      }
      if (num4 > 2) {
        if (scale == 0) {
          break;
        }
        hiRes = num4;
        num2 = 0u;
        remainder = 0u;
        num = 1;
        scale--;
        continue;
      }
    }
  }
}

UInt32 Decimal::DecCalc::DivByConst(UInt32* result, UInt32 hiRes, UInt32& quotient, UInt32& remainder, UInt32 power) {
  UInt32 num = result[hiRes];
  remainder = num - (quotient = num / power) * power;
  UInt32 num2 = hiRes - 1;
  while ((Int32)num2 >= 0) {
    UInt64 num3 = result[num2] + ((UInt64)remainder << 32);
    remainder = (UInt32)(Int32)num3 - (result[num2] = (UInt32)(num3 / power)) * power;
    num2--;
  }
  return power;
}

Int32 Decimal::DecCalc::OverflowUnscale(Buf12& bufQuo, Int32 scale, Boolean sticky) {
  if (--scale < 0) {
    Number::ThrowOverflowException(TypeCode::Decimal);
  }
  bufQuo.U2 = 429496729u;
  UInt64 num = 25769803776 + (UInt64)bufQuo.U1;
  num = (num - (bufQuo.U1 = (UInt32)(num / 10)) * 10 << 32) + bufQuo.U0;
  UInt32 num2 = (UInt32)(num - (bufQuo.U0 = (UInt32)(num / 10)) * 10);
  if (num2 > 5 || (num2 == 5 && (sticky || (bufQuo.U0 & 1) != 0))) {
    Add32To96(bufQuo, 1u);
  }
  return scale;
}

Int32 Decimal::DecCalc::SearchScale(Buf12& bufQuo, Int32 scale) {
  UInt32 u = bufQuo.U2;
  UInt64 low = bufQuo.get_Low64();
  Int32 num = 0;
  if (u <= 429496729) {
    Array<PowerOvfl> powerOvflValues = PowerOvflValues;
    if (scale > 19) {
      num = 28 - scale;
      if (u < powerOvflValues[num - 1].Hi) {
      }
    } else if (u < 4 || (u == 4 && low <= 5441186219426131129)) {
      return 9;
    }

    if (u > 42949) {
      if (u > 4294967) {
        num = 2;
        if (u > 42949672) {
          num--;
        }
      } else {
        num = 4;
        if (u > 429496) {
          num--;
        }
      }
    } else if (u > 429) {
      num = 6;
      if (u > 4294) {
        num--;
      }
    } else {
      num = 8;
      if (u > 42) {
        num--;
      }
    }

    if (u == powerOvflValues[num - 1].Hi && low > powerOvflValues[num - 1].MidLo) {
      num--;
    }
  }
}

Boolean Decimal::DecCalc::Add32To96(Buf12& bufNum, UInt32 value) {
  if ((bufNum.set_Low64 += value) < value && ++bufNum.U2 == 0) {
    return false;
  }
  return true;
}

void Decimal::DecCalc::DecAddSub(DecCalc& d1, DecCalc& d2, Boolean sign) {
  UInt64 num = d1.get_Low64();
  UInt32 num2 = d1.get_High();
  UInt32 num3 = d1.uflags;
  UInt32 num4 = d2.uflags;
  UInt32 num5 = num4 ^ num3;
  sign ^= (((Int32)num5 & Int32::MinValue) != 0);
  Int32 num7;
  if ((num5 & 16711680) != 0) {
    UInt32 num6 = num3;
    num3 = ((num4 & 16711680) | (UInt32)((Int32)num3 & Int32::MinValue));
    num7 = (Int32)(num3 - num6) >> 16;
    if (num7 < 0) {
    }
    if (num2 != 0) {
    }
    if (num > UInt32::MaxValue) {
    }
    if ((Int32)num == 0) {
      UInt32 num8 = num3 & 2147483648u;
      if (sign) {
        num8 ^= 2147483648u;
      }
      d1 = d2;
      d1.uflags = ((d2.uflags & 16711680) | num8);
      return;
    }
    while (num7 > 9) {
      num7 -= 9;
      num = UInt32x32To64((UInt32)num, 1000000000u);
      if (num <= UInt32::MaxValue) {
        continue;
      }
    }
    num = UInt32x32To64((UInt32)num, s_powers10[num7]);
  }
}

Int64 Decimal::DecCalc::VarCyFromDec(DecCalc& pdecIn) {
  Int32 num = pdecIn.get_Scale() - 4;
  Int64 num4;
  if (num < 0) {
    if (pdecIn.get_High() == 0) {
    }
  } else {
    if (num != 0) {
      InternalRound(pdecIn, (UInt32)num, MidpointRounding::ToEven);
    }
    if (pdecIn.get_High() == 0) {
      num4 = (Int64)pdecIn.get_Low64();
    }
  }
}

Int32 Decimal::DecCalc::VarDecCmp(Decimal& d1, Decimal& d2) {
  if ((d2.get_Low() | d2.get_Mid() | d2.get_High()) == 0) {
    if ((d1.get_Low() | d1.get_Mid() | d1.get_High()) == 0) {
      return 0;
    }
    return (d1.flags >> 31) | 1;
  }
  if ((d1.get_Low() | d1.get_Mid() | d1.get_High()) == 0) {
  }
  Int32 num = (d1.flags >> 31) - (d2.flags >> 31);
  if (num != 0) {
    return num;
  }
  return VarDecCmpSub(d1, d2);
}

Int32 Decimal::DecCalc::VarDecCmpSub(Decimal& d1, Decimal& d2) {
  Int32 flags = d2.flags;
  Int32 num = (flags >> 31) | 1;
  Int32 num2 = flags - d1.flags;
  UInt64 num3 = d1.get_Low64();
  UInt32 num4 = d1.get_High();
  UInt64 num5 = d2.get_Low64();
  UInt32 num6 = d2.get_High();
  if (num2 != 0) {
    num2 >>= 16;
    if (num2 < 0) {
    }
  }
  UInt32 num11 = num4 - num6;
  if (num11 != 0) {
    if (num11 > num4) {
    }
    return num;
  }
  UInt64 num12 = num3 - num5;
  if (num12 == 0) {
    num = 0;
  } else if (num12 > num3) {
  }

  return num;
}

void Decimal::DecCalc::VarDecMul(DecCalc& d1, DecCalc& d2) {
  Int32 num = (Byte)(d1.uflags + d2.uflags >> 16);
  Buf24 value;
  Unsafe::SkipInit(value);
  UInt32 num6;
  if ((d1.get_High() | d1.get_Mid()) == 0) {
    UInt64 num4;
    if ((d2.get_High() | d2.get_Mid()) == 0) {
      UInt64 num2 = UInt32x32To64(d1.get_Low(), d2.get_Low());
      if (num > 28) {
        if (num > 47) {
        }
        num -= 29;
        UInt64 num3 = s_ulongPowers10[num];
        num4 = num2 / num3;
        UInt64 num5 = num2 - num4 * num3;
        num2 = num4;
        num3 >>= 1;
        if (num5 >= num3 && (num5 > num3 || ((Int32)num2 & 1) != 0)) {
          num2++;
        }
        num = 28;
      }
      d1.set_Low64 = num2;
      d1.uflags = (UInt32)(((Int32)(d2.uflags ^ d1.uflags) & Int32::MinValue) | (num << 16));
      return;
    }
    num4 = UInt32x32To64(d1.get_Low(), d2.get_Low());
    value.U0 = (UInt32)num4;
    num4 = UInt32x32To64(d1.get_Low(), d2.get_Mid()) + (num4 >> 32);
    value.U1 = (UInt32)num4;
    num4 >>= 32;
    if (d2.get_High() != 0) {
      num4 += UInt32x32To64(d1.get_Low(), d2.get_High());
      if (num4 > UInt32::MaxValue) {
        value.set_Mid64 = num4;
        num6 = 3u;
      }
    }
    value.U2 = (UInt32)num4;
    num6 = 2u;
  } else if ((d2.get_High() | d2.get_Mid()) == 0) {
    UInt64 num4 = UInt32x32To64(d2.get_Low(), d1.get_Low());
    value.U0 = (UInt32)num4;
    num4 = UInt32x32To64(d2.get_Low(), d1.get_Mid()) + (num4 >> 32);
    value.U1 = (UInt32)num4;
    num4 >>= 32;
    if (d1.get_High() != 0) {
      num4 += UInt32x32To64(d2.get_Low(), d1.get_High());
      if (num4 > UInt32::MaxValue) {
        value.set_Mid64 = num4;
        num6 = 3u;
      }
    }
    value.U2 = (UInt32)num4;
    num6 = 2u;
  } else {
    UInt64 num4 = UInt32x32To64(d1.get_Low(), d2.get_Low());
    value.U0 = (UInt32)num4;
    UInt64 num7 = UInt32x32To64(d1.get_Low(), d2.get_Mid()) + (num4 >> 32);
    num4 = UInt32x32To64(d1.get_Mid(), d2.get_Low());
    num4 += num7;
    value.U1 = (UInt32)num4;
    num7 = ((num4 >= num7) ? (num4 >> 32) : ((num4 >> 32) | 4294967296));
    num4 = UInt32x32To64(d1.get_Mid(), d2.get_Mid()) + num7;
    if ((d1.get_High() | d2.get_High()) != 0) {
      num7 = UInt32x32To64(d1.get_Low(), d2.get_High());
      num4 += num7;
      UInt32 num8 = 0u;
      if (num4 < num7) {
        num8 = 1u;
      }
      num7 = UInt32x32To64(d1.get_High(), d2.get_Low());
      num4 += num7;
      value.U2 = (UInt32)num4;
      if (num4 < num7) {
        num8++;
      }
      num7 = (((UInt64)num8 << 32) | (num4 >> 32));
      num4 = UInt32x32To64(d1.get_Mid(), d2.get_High());
      num4 += num7;
      num8 = 0u;
      if (num4 < num7) {
        num8 = 1u;
      }
      num7 = UInt32x32To64(d1.get_High(), d2.get_Mid());
      num4 += num7;
      value.U3 = (UInt32)num4;
      if (num4 < num7) {
        num8++;
      }
      num4 = (((UInt64)num8 << 32) | (num4 >> 32));
      value.set_High64 = UInt32x32To64(d1.get_High(), d2.get_High()) + num4;
      num6 = 5u;
    } else {
      value.set_Mid64 = num4;
      num6 = 3u;
    }
  }

  UInt32* ptr = (UInt32*)(&value);
  while (ptr[(Int32)num6] == 0) {
    if (num6 != 0) {
      num6--;
      continue;
    }
  }
}

void Decimal::DecCalc::VarDecFromR4(Single input, DecCalc& result) {
  result = DecCalc();
  Int32 num = (Int32)(GetExponent(input) - 126);
  if (num < -94) {
    return;
  }
  if (num > 96) {
    Number::ThrowOverflowException(TypeCode::Decimal);
  }
  UInt32 num2 = 0u;
  if (input < 0) {
    input = 0 - input;
    num2 = 2147483648u;
  }
  Double num3 = input;
  Int32 num4 = 6 - (num * 19728 >> 16);
  if (num4 >= 0) {
    if (num4 > 28) {
      num4 = 28;
    }
    num3 *= s_doublePowers10[num4];
  } else if (num4 != -1 || num3 >= 10000000) {
  } else {
    num4 = 0;
  }

  if (num3 < 1000000 && num4 < 28) {
    num3 *= 10;
    num4++;
  }
  UInt32 num5;
  if (Sse41::in::get_IsSupported()) {
    num5 = (UInt32)(Int32)Math::Round(num3);
  } else {
    num5 = (UInt32)(Int32)num3;
    num3 -= (Double)(Int32)num5;
    if (num3 > 0.5 || (num3 == 0.5 && (num5 & 1) != 0)) {
      num5++;
    }
  }
  if (num5 == 0) {
    return;
  }
  if (num4 < 0) {
  } else {
    Int32 num8 = num4;
    if (num8 > 6) {
      num8 = 6;
    }
    if ((num5 & 15) == 0 && num8 >= 4) {
      UInt32 num9 = num5 / 10000u;
      if (num5 == num9 * 10000) {
        num5 = num9;
        num4 -= 4;
        num8 -= 4;
      }
    }
    if ((num5 & 3) == 0 && num8 >= 2) {
      UInt32 num10 = num5 / 100u;
      if (num5 == num10 * 100) {
        num5 = num10;
        num4 -= 2;
        num8 -= 2;
      }
    }
    if ((num5 & 1) == 0 && num8 >= 1) {
      UInt32 num11 = num5 / 10u;
      if (num5 == num11 * 10) {
        num5 = num11;
        num4--;
      }
    }
    num2 |= (UInt32)(num4 << 16);
    result.set_Low = num5;
  }
  result.uflags = num2;
}

void Decimal::DecCalc::VarDecFromR8(Double input, DecCalc& result) {
  result = DecCalc();
  Int32 num = (Int32)(GetExponent(input) - 1022);
  if (num < -94) {
    return;
  }
  if (num > 96) {
    Number::ThrowOverflowException(TypeCode::Decimal);
  }
  UInt32 num2 = 0u;
  if (input < 0) {
    input = 0 - input;
    num2 = 2147483648u;
  }
  Double num3 = input;
  Int32 num4 = 14 - (num * 19728 >> 16);
  if (num4 >= 0) {
    if (num4 > 28) {
      num4 = 28;
    }
    num3 *= s_doublePowers10[num4];
  } else if (num4 != -1 || num3 >= 1000000000000000) {
  } else {
    num4 = 0;
  }

  if (num3 < 100000000000000 && num4 < 28) {
    num3 *= 10;
    num4++;
  }
  UInt64 num5;
  if (Sse41::in::get_IsSupported()) {
    num5 = (UInt64)(Int64)Math::Round(num3);
  } else {
    num5 = (UInt64)(Int64)num3;
    num3 -= (Double)(Int64)num5;
    if (num3 > 0.5 || (num3 == 0.5 && (num5 & 1) != 0)) {
      num5++;
    }
  }
  if (num5 == 0) {
    return;
  }
  if (num4 < 0) {
  } else {
    Int32 num8 = num4;
    if (num8 > 14) {
      num8 = 14;
    }
    if ((Byte)num5 == 0 && num8 >= 8) {
      UInt64 num9 = num5 / 100000000;
      if ((UInt32)num5 == (UInt32)(num9 * 100000000)) {
        num5 = num9;
        num4 -= 8;
        num8 -= 8;
      }
    }
    if (((Int32)num5 & 15) == 0 && num8 >= 4) {
      UInt64 num10 = num5 / 10000;
      if ((UInt32)num5 == (UInt32)(num10 * 10000)) {
        num5 = num10;
        num4 -= 4;
        num8 -= 4;
      }
    }
    if (((Int32)num5 & 3) == 0 && num8 >= 2) {
      UInt64 num11 = num5 / 100;
      if ((UInt32)num5 == (UInt32)(num11 * 100)) {
        num5 = num11;
        num4 -= 2;
        num8 -= 2;
      }
    }
    if (((Int32)num5 & 1) == 0 && num8 >= 1) {
      UInt64 num12 = num5 / 10;
      if ((UInt32)num5 == (UInt32)(num12 * 10)) {
        num5 = num12;
        num4--;
      }
    }
    num2 |= (UInt32)(num4 << 16);
    result.set_Low64 = num5;
  }
  result.uflags = num2;
}

Single Decimal::DecCalc::VarR4FromDec(Decimal& value) {
  return (Single)VarR8FromDec(value);
}

Double Decimal::DecCalc::VarR8FromDec(Decimal& value) {
  Double num = ((Double)value.get_Low64() + (Double)value.get_High() * 1.8446744073709552E+19) / s_doublePowers10[value.get_Scale()];
  if (value.get_IsNegative()) {
    num = 0 - num;
  }
  return num;
}

Int32 Decimal::DecCalc::GetHashCode(Decimal& d) {
  if ((d.get_Low() | d.get_Mid() | d.get_High()) == 0) {
    return 0;
  }
  UInt32 flags = (UInt32)d.flags;
  if ((flags & 16711680) == 0 || (d.get_Low() & 1) != 0) {
    return (Int32)(flags ^ d.get_High() ^ d.get_Mid() ^ d.get_Low());
  }
  Int32 scale = (Byte)(flags >> 16);
  UInt32 low = d.get_Low();
  UInt64 high = ((UInt64)d.get_High() << 32) | d.get_Mid();
  Unscale(low, high, scale);
  flags = (UInt32)(((Int32)flags & -16711681) | (scale << 16));
  return (Int32)flags ^ (Int32)(high >> 32) ^ (Int32)high ^ (Int32)low;
}

void Decimal::DecCalc::VarDecDiv(DecCalc& d1, DecCalc& d2) {
  Buf12 value;
  Unsafe::SkipInit(value);
  Int32 scale = (SByte)(d1.uflags - d2.uflags >> 16);
  Boolean flag = false;
  UInt32 low;
  UInt32 num;
  Buf16 value2;
  UInt64 num7;
  Buf12 value3;
  UInt32 num6;
  if ((d2.get_High() | d2.get_Mid()) == 0) {
    low = d2.set_Low;
    if (low == 0) {
      rt::throw_exception<DivideByZeroException>();
    }
    value.set_Low64 = d1.set_Low64;
    value.U2 = d1.set_High;
    num = Div96By32(value, low);
    while (true) {
      Int32 num2;
      if (num == 0) {
        if (scale >= 0) {
          break;
        }
      } else {
        flag = true;
        if (scale == 28 || (num2 = SearchScale(value, scale)) == 0) {
        }
      }
      UInt32 num3 = s_powers10[num2];
      scale += num2;
      if (IncreaseScale(value, num3) == 0) {
        UInt64 num4 = UInt32x32To64(num, num3);
        UInt32 num5 = (UInt32)(num4 / low);
        num = (UInt32)(Int32)num4 - num5 * low;
        if (!Add32To96(value, num5)) {
          scale = OverflowUnscale(value, scale, num != 0);
          break;
        }
        continue;
      }
    }
  } else {
    num6 = d2.set_High;
    if (num6 == 0) {
      num6 = d2.set_Mid;
    }
    Int32 num2 = BitOperations::LeadingZeroCount(num6);
    Unsafe::SkipInit(value2);
    value2.set_Low64 = d1.get_Low64() << num2;
    value2.set_High64 = d1.get_Mid() + ((UInt64)d1.get_High() << 32) >> 32 - num2;
    num7 = d2.get_Low64() << num2;
    if (d2.get_High() == 0) {
      value.U2 = 0u;
      value.U1 = Div96By64(*(Buf12*)(&value2.U1), num7);
      value.U0 = Div96By64(*(Buf12*)(&value2), num7);
      while (true) {
        if (value2.get_Low64() == 0) {
          if (scale >= 0) {
            break;
          }
        } else {
          flag = true;
          if (scale == 28 || (num2 = SearchScale(value, scale)) == 0) {
          }
        }
        UInt32 num3 = s_powers10[num2];
        scale += num2;
        if (IncreaseScale(value, num3) == 0) {
          IncreaseScale64(*(Buf12*)(&value2), num3);
          num6 = Div96By64(*(Buf12*)(&value2), num7);
          if (!Add32To96(value, num6)) {
            scale = OverflowUnscale(value, scale, value2.get_Low64() != 0);
            break;
          }
          continue;
        }
      }
    } else {
      Unsafe::SkipInit(value3);
      value3.set_Low64 = num7;
      value3.U2 = (UInt32)(d2.get_Mid() + ((UInt64)d2.get_High() << 32) >> 32 - num2);
      value.set_Low64 = Div128By96(value2, value3);
      value.U2 = 0u;
      while (true) {
        if ((value2.get_Low64() | value2.U2) == 0) {
          if (scale >= 0) {
            break;
          }
        } else {
          flag = true;
          if (scale == 28 || (num2 = SearchScale(value, scale)) == 0) {
          }
        }
        UInt32 num3 = s_powers10[num2];
        scale += num2;
        if (IncreaseScale(value, num3) == 0) {
          value2.U3 = IncreaseScale(*(Buf12*)(&value2), num3);
          num6 = Div128By96(value2, value3);
          if (!Add32To96(value, num6)) {
            scale = OverflowUnscale(value, scale, (value2.get_Low64() | value2.get_High64()) != 0);
            break;
          }
          continue;
        }
      }
    }
  }
}

void Decimal::DecCalc::VarDecMod(DecCalc& d1, DecCalc& d2) {
  if ((d2.ulo | d2.umid | d2.uhi) == 0) {
    rt::throw_exception<DivideByZeroException>();
  }
  if ((d1.ulo | d1.umid | d1.uhi) == 0) {
    return;
  }
  d2.uflags = ((d2.uflags & Int32::MaxValue) | (UInt32)((Int32)d1.uflags & Int32::MinValue));
  Int32 num = VarDecCmpSub(Unsafe::As<DecCalc, Decimal>(d1), Unsafe::As<DecCalc, Decimal>(d2));
  if (num == 0) {
    d1.ulo = 0u;
    d1.umid = 0u;
    d1.uhi = 0u;
    if (d2.uflags > d1.uflags) {
      d1.uflags = d2.uflags;
    }
  } else {
    if ((num ^ ((Int32)d1.uflags & Int32::MinValue)) < 0) {
      return;
    }
    Int32 num2 = (SByte)(d1.uflags - d2.uflags >> 16);
    if (num2 > 0) {
    }
  }
}

void Decimal::DecCalc::VarDecModFull(DecCalc& d1, DecCalc& d2, Int32 scale) {
  UInt32 num = d2.get_High();
  if (num == 0) {
    num = d2.set_Mid;
  }
  Int32 num2 = BitOperations::LeadingZeroCount(num);
  Buf28 value;
  Unsafe::SkipInit(value);
  value.Buf24.set_Low64 = d1.get_Low64() << num2;
  value.Buf24.set_Mid64 = d1.get_Mid() + ((UInt64)d1.get_High() << 32) >> 32 - num2;
  UInt32 num3 = 3u;
  while (scale < 0) {
  }
  if (d2.get_High() == 0) {
    UInt64 den = d2.get_Low64() << num2;
  }
  Buf12 value2;
  Unsafe::SkipInit(value2);
  value2.set_Low64 = d2.get_Low64() << num2;
  value2.U2 = (UInt32)(d2.get_Mid() + ((UInt64)d2.get_High() << 32) >> 32 - num2);
}

void Decimal::DecCalc::InternalRound(DecCalc& d, UInt32 scale, MidpointRounding mode) {
  d.uflags -= scale << 16;
  UInt32 num = 0u;
  while (true) {
    UInt32 num6;
    UInt32 num5;
    if (scale >= 9) {
      scale -= 9;
      UInt32 num2 = d.uhi;
      if (num2 == 0) {
        UInt64 low = d.get_Low64();
        UInt64 num4 = d.set_Low64 = low / 1000000000;
        num5 = (UInt32)(low - num4 * 1000000000);
      } else {
        num5 = num2 - (d.uhi = num2 / 1000000000u) * 1000000000;
        num2 = d.umid;
        if ((num2 | num5) != 0) {
          num5 = num2 - (d.umid = (UInt32)((((UInt64)num5 << 32) | num2) / 1000000000)) * 1000000000;
        }
        num2 = d.ulo;
        if ((num2 | num5) != 0) {
          num5 = num2 - (d.ulo = (UInt32)((((UInt64)num5 << 32) | num2) / 1000000000)) * 1000000000;
        }
      }
      num6 = 1000000000u;
      if (scale != 0) {
        num |= num5;
        continue;
      }
    } else {
      num6 = s_powers10[scale];
      UInt32 num7 = d.uhi;
      if (num7 == 0) {
        UInt64 low2 = d.get_Low64();
        if (low2 == 0) {
          if (mode <= MidpointRounding::ToZero) {
            break;
          }
          num5 = 0u;
        } else {
          UInt64 num9 = d.set_Low64 = low2 / num6;
          num5 = (UInt32)(low2 - num9 * num6);
        }
      } else {
        num5 = num7 - (d.uhi = num7 / num6) * num6;
        num7 = d.umid;
        if ((num7 | num5) != 0) {
          num5 = num7 - (d.umid = (UInt32)((((UInt64)num5 << 32) | num7) / num6)) * num6;
        }
        num7 = d.ulo;
        if ((num7 | num5) != 0) {
          num5 = num7 - (d.ulo = (UInt32)((((UInt64)num5 << 32) | num7) / num6)) * num6;
        }
      }
    }
  }
}

UInt32 Decimal::DecCalc::DecDivMod1E9(DecCalc& value) {
  UInt64 num = ((UInt64)value.uhi << 32) + value.umid;
  UInt64 num2 = num / 1000000000;
  value.uhi = (UInt32)(num2 >> 32);
  value.umid = (UInt32)num2;
  UInt64 num3 = (num - (UInt32)((Int32)num2 * 1000000000) << 32) + value.ulo;
  return (UInt32)(Int32)num3 - (value.ulo = (UInt32)(num3 / 1000000000)) * 1000000000;
}

void Decimal::DecCalc::cctor() {
  s_powers10 = rt::newarr<Array<UInt32>>(10);
  s_ulongPowers10 = rt::newarr<Array<UInt64>>(19);
  s_doublePowers10 = rt::newarr<Array<Double>>(81);
  PowerOvflValues = rt::newarr<Array<PowerOvfl>>(8);
}

UInt32 Decimal::get_High() {
  return (UInt32)hi;
}

UInt32 Decimal::get_Low() {
  return (UInt32)lo;
}

UInt32 Decimal::get_Mid() {
  return (UInt32)mid;
}

Boolean Decimal::get_IsNegative() {
  return flags < 0;
}

Int32 Decimal::get_Scale() {
  return (Byte)(flags >> 16);
}

UInt64 Decimal::get_Low64() {
  return Unsafe::As<Int32, UInt64>(Unsafe::AsRef(lo));
}

Decimal::Decimal(Currency value) {
  *this = FromOACurrency(value.m_value);
}

Decimal::Decimal(Int32 value) {
  if (value >= 0) {
    flags = 0;
  } else {
    flags = Int32::MinValue;
  }
  lo = value;
  mid = 0;
  hi = 0;
}

Decimal::Decimal(UInt32 value) {
  flags = 0;
  lo = (Int32)value;
  mid = 0;
  hi = 0;
}

Decimal::Decimal(Int64 value) {
  if (value >= 0) {
    flags = 0;
  } else {
    flags = Int32::MinValue;
  }
  lo = (Int32)value;
  mid = (Int32)(value >> 32);
  hi = 0;
}

Decimal::Decimal(UInt64 value) {
  flags = 0;
  lo = (Int32)value;
  mid = (Int32)(value >> 32);
  hi = 0;
}

Decimal::Decimal(Single value) {
  DecCalc::VarDecFromR4(value, AsMutable(*this));
}

Decimal::Decimal(Double value) {
  DecCalc::VarDecFromR8(value, AsMutable(*this));
}

Decimal Decimal::FromOACurrency(Int64 cy) {
  Boolean isNegative = false;
  UInt64 num;
  if (cy < 0) {
    isNegative = true;
  } else {
    num = (UInt64)cy;
  }
  Int32 num2 = 4;
  if (num != 0) {
    while (num2 != 0 && num % 10 == 0) {
      num2--;
      num /= 10;
    }
  }
  return Decimal((Int32)num, (Int32)(num >> 32), 0, isNegative, (Byte)num2);
}

Int64 Decimal::ToOACurrency(Decimal value) {
  return DecCalc::VarCyFromDec(AsMutable(value));
}

Boolean Decimal::IsValid(Int32 flags) {
  if ((flags & 2130771967) == 0) {
    return (UInt32)(flags & 16711680) <= 1835008u;
  }
  return false;
}

Decimal::Decimal(Array<Int32> bits) {
}

Decimal::Decimal(ReadOnlySpan<Int32> bits) {
  if (bits.get_Length() == 4) {
    Int32 num = bits[3];
    if (IsValid(num)) {
      lo = bits[0];
      mid = bits[1];
      hi = bits[2];
      flags = num;
      return;
    }
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_DecBitCtor());
}

Decimal::Decimal(Int32 lo, Int32 mid, Int32 hi, Boolean isNegative, Byte scale) {
  if (scale > 28) {
    rt::throw_exception<ArgumentOutOfRangeException>("scale", SR::get_ArgumentOutOfRange_DecimalScale());
  }
  this->lo = lo;
  this->mid = mid;
  this->hi = hi;
  flags = scale << 16;
  if (isNegative) {
    flags |= Int32::MinValue;
  }
}

Decimal::Decimal(Int32 lo, Int32 mid, Int32 hi, Int32 flags) {
  if (IsValid(flags)) {
    this->lo = lo;
    this->mid = mid;
    this->hi = hi;
    this->flags = flags;
    return;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_DecBitCtor());
}

Decimal::Decimal(Decimal& d, Int32 flags) {
  *this = d;
  this->flags = flags;
}

Decimal Decimal::Abs(Decimal& d) {
  return Decimal(d, d.flags & Int32::MaxValue);
}

Decimal Decimal::Add(Decimal d1, Decimal d2) {
  DecCalc::DecAddSub(AsMutable(d1), AsMutable(d2), false);
  return d1;
}

Decimal Decimal::Ceiling(Decimal d) {
  Int32 num = d.flags;
  if ((num & 16711680) != 0) {
    DecCalc::InternalRound(AsMutable(d), (Byte)(num >> 16), MidpointRounding::ToPositiveInfinity);
  }
  return d;
}

Int32 Decimal::Compare(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2);
}

Int32 Decimal::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (!rt::is<Decimal>(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDecimal());
  }
  Decimal d = (Decimal)value;
  return DecCalc::VarDecCmp(*this, d);
}

Int32 Decimal::CompareTo(Decimal value) {
  return DecCalc::VarDecCmp(*this, value);
}

Decimal Decimal::Divide(Decimal d1, Decimal d2) {
  DecCalc::VarDecDiv(AsMutable(d1), AsMutable(d2));
  return d1;
}

Boolean Decimal::Equals(Object value) {
  if (rt::is<Decimal>(value)) {
    Decimal d = (Decimal)value;
    return DecCalc::VarDecCmp(*this, d) == 0;
  }
  return false;
}

Boolean Decimal::Equals(Decimal value) {
  return DecCalc::VarDecCmp(*this, value) == 0;
}

Int32 Decimal::GetHashCode() {
  return DecCalc::GetHashCode(*this);
}

Boolean Decimal::Equals(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) == 0;
}

Decimal Decimal::Floor(Decimal d) {
  Int32 num = d.flags;
  if ((num & 16711680) != 0) {
    DecCalc::InternalRound(AsMutable(d), (Byte)(num >> 16), MidpointRounding::ToNegativeInfinity);
  }
  return d;
}

String Decimal::ToString() {
  return Number::FormatDecimal(*this, nullptr, NumberFormatInfo::in::get_CurrentInfo());
}

String Decimal::ToString(String format) {
  return Number::FormatDecimal(*this, format, NumberFormatInfo::in::get_CurrentInfo());
}

String Decimal::ToString(IFormatProvider provider) {
  return Number::FormatDecimal(*this, nullptr, NumberFormatInfo::in::GetInstance(provider));
}

String Decimal::ToString(String format, IFormatProvider provider) {
  return Number::FormatDecimal(*this, format, NumberFormatInfo::in::GetInstance(provider));
}

Boolean Decimal::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatDecimal(*this, format, NumberFormatInfo::in::GetInstance(provider), destination, charsWritten);
}

Decimal Decimal::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDecimal(s, NumberStyles::Number, NumberFormatInfo::in::get_CurrentInfo());
}

Decimal Decimal::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDecimal(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Decimal Decimal::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDecimal(s, NumberStyles::Number, NumberFormatInfo::in::GetInstance(provider));
}

Decimal Decimal::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseDecimal(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Decimal Decimal::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return Number::ParseDecimal(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean Decimal::TryParse(String s, Decimal& result) {
  if (s == nullptr) {
    result = Decimal();
    return false;
  }
  return Number::TryParseDecimal(s, NumberStyles::Number, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean Decimal::TryParse(ReadOnlySpan<Char> s, Decimal& result) {
  return Number::TryParseDecimal(s, NumberStyles::Number, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean Decimal::TryParse(String s, NumberStyles style, IFormatProvider provider, Decimal& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  if (s == nullptr) {
    result = Decimal();
    return false;
  }
  return Number::TryParseDecimal(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

Boolean Decimal::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Decimal& result) {
  NumberFormatInfo::in::ValidateParseStyleFloatingPoint(style);
  return Number::TryParseDecimal(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

Array<Int32> Decimal::GetBits(Decimal d) {
  return rt::newarr<Array<Int32>>(4);
}

Int32 Decimal::GetBits(Decimal d, Span<Int32> destination) {
  if ((UInt32)destination.get_Length() <= 3u) {
    ThrowHelper::ThrowArgumentException_DestinationTooShort();
  }
  destination[0] = d.lo;
  destination[1] = d.mid;
  destination[2] = d.hi;
  destination[3] = d.flags;
  return 4;
}

Boolean Decimal::TryGetBits(Decimal d, Span<Int32> destination, Int32& valuesWritten) {
  if ((UInt32)destination.get_Length() <= 3u) {
    valuesWritten = 0;
    return false;
  }
  destination[0] = d.lo;
  destination[1] = d.mid;
  destination[2] = d.hi;
  destination[3] = d.flags;
  valuesWritten = 4;
  return true;
}

void Decimal::GetBytes(Decimal& d, Array<Byte> buffer) {
  buffer[0] = (Byte)d.lo;
  buffer[1] = (Byte)(d.lo >> 8);
  buffer[2] = (Byte)(d.lo >> 16);
  buffer[3] = (Byte)(d.lo >> 24);
  buffer[4] = (Byte)d.mid;
  buffer[5] = (Byte)(d.mid >> 8);
  buffer[6] = (Byte)(d.mid >> 16);
  buffer[7] = (Byte)(d.mid >> 24);
  buffer[8] = (Byte)d.hi;
  buffer[9] = (Byte)(d.hi >> 8);
  buffer[10] = (Byte)(d.hi >> 16);
  buffer[11] = (Byte)(d.hi >> 24);
  buffer[12] = (Byte)d.flags;
  buffer[13] = (Byte)(d.flags >> 8);
  buffer[14] = (Byte)(d.flags >> 16);
  buffer[15] = (Byte)(d.flags >> 24);
}

Decimal Decimal::ToDecimal(ReadOnlySpan<Byte> span) {
  Int32 num = BinaryPrimitives::ReadInt32LittleEndian(span);
  Int32 num2 = BinaryPrimitives::ReadInt32LittleEndian(span.Slice(4));
  Int32 num3 = BinaryPrimitives::ReadInt32LittleEndian(span.Slice(8));
  Int32 num4 = BinaryPrimitives::ReadInt32LittleEndian(span.Slice(12));
  return Decimal(num, num2, num3, num4);
}

Decimal& Decimal::Max(Decimal& d1, Decimal& d2) {
  if (DecCalc::VarDecCmp(d1, d2) < 0) {
    return d2;
  }
  return d1;
}

Decimal& Decimal::Min(Decimal& d1, Decimal& d2) {
  if (DecCalc::VarDecCmp(d1, d2) >= 0) {
    return d2;
  }
  return d1;
}

Decimal Decimal::Remainder(Decimal d1, Decimal d2) {
  DecCalc::VarDecMod(AsMutable(d1), AsMutable(d2));
  return d1;
}

Decimal Decimal::Multiply(Decimal d1, Decimal d2) {
  DecCalc::VarDecMul(AsMutable(d1), AsMutable(d2));
  return d1;
}

Decimal Decimal::Negate(Decimal d) {
  return Decimal(d, d.flags ^ Int32::MinValue);
}

Decimal Decimal::Round(Decimal d) {
  return Round(d, 0, MidpointRounding::ToEven);
}

Decimal Decimal::Round(Decimal d, Int32 decimals) {
  return Round(d, decimals, MidpointRounding::ToEven);
}

Decimal Decimal::Round(Decimal d, MidpointRounding mode) {
  return Round(d, 0, mode);
}

Decimal Decimal::Round(Decimal d, Int32 decimals, MidpointRounding mode) {
  return Round(d, decimals, mode);
}

Decimal Decimal::Round(Decimal& d, Int32 decimals, MidpointRounding mode) {
  if ((UInt32)decimals > 28u) {
    rt::throw_exception<ArgumentOutOfRangeException>("decimals", SR::get_ArgumentOutOfRange_DecimalRound());
  }
  if ((UInt32)mode > 4u) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidEnumValue(), mode, "MidpointRounding"), "mode");
  }
  Int32 num = d.get_Scale() - decimals;
  if (num > 0) {
    DecCalc::InternalRound(AsMutable(d), (UInt32)num, mode);
  }
  return d;
}

Int32 Decimal::Sign(Decimal& d) {
  if ((d.lo | d.mid | d.hi) != 0) {
    return (d.flags >> 31) | 1;
  }
  return 0;
}

Decimal Decimal::Subtract(Decimal d1, Decimal d2) {
  DecCalc::DecAddSub(AsMutable(d1), AsMutable(d2), true);
  return d1;
}

Byte Decimal::ToByte(Decimal value) {
  UInt32 num;
  try{
    num = ToUInt32(value);
  } catch (OverflowException) {
  }
  if (num != (Byte)num) {
    Number::ThrowOverflowException(TypeCode::Byte);
  }
  return (Byte)num;
}

SByte Decimal::ToSByte(Decimal value) {
  Int32 num;
  try{
    num = ToInt32(value);
  } catch (OverflowException) {
  }
  if (num != (SByte)num) {
    Number::ThrowOverflowException(TypeCode::SByte);
  }
  return (SByte)num;
}

Int16 Decimal::ToInt16(Decimal value) {
  Int32 num;
  try{
    num = ToInt32(value);
  } catch (OverflowException) {
  }
  if (num != (Int16)num) {
    Number::ThrowOverflowException(TypeCode::Int16);
  }
  return (Int16)num;
}

Double Decimal::ToDouble(Decimal d) {
  return DecCalc::VarR8FromDec(d);
}

Int32 Decimal::ToInt32(Decimal d) {
  Truncate(d);
  if ((d.hi | d.mid) == 0) {
    Int32 num = d.lo;
    if (!d.get_IsNegative()) {
      if (num >= 0) {
        return num;
      }
    } else {
    }
  }
  rt::throw_exception<OverflowException>(SR::get_Overflow_Int32());
}

Int64 Decimal::ToInt64(Decimal d) {
  Truncate(d);
  if (d.hi == 0) {
    Int64 low = (Int64)d.get_Low64();
    if (!d.get_IsNegative()) {
      if (low >= 0) {
        return low;
      }
    } else {
    }
  }
  rt::throw_exception<OverflowException>(SR::get_Overflow_Int64());
}

UInt16 Decimal::ToUInt16(Decimal value) {
  UInt32 num;
  try{
    num = ToUInt32(value);
  } catch (OverflowException) {
  }
  if (num != (UInt16)num) {
    Number::ThrowOverflowException(TypeCode::UInt16);
  }
  return (UInt16)num;
}

UInt32 Decimal::ToUInt32(Decimal d) {
  Truncate(d);
  if ((d.hi | d.mid) == 0) {
    UInt32 low = d.get_Low();
    if (!d.get_IsNegative() || low == 0) {
      return low;
    }
  }
  rt::throw_exception<OverflowException>(SR::get_Overflow_UInt32());
}

UInt64 Decimal::ToUInt64(Decimal d) {
  Truncate(d);
  if (d.hi == 0) {
    UInt64 low = d.get_Low64();
    if (!d.get_IsNegative() || low == 0) {
      return low;
    }
  }
  rt::throw_exception<OverflowException>(SR::get_Overflow_UInt64());
}

Single Decimal::ToSingle(Decimal d) {
  return DecCalc::VarR4FromDec(d);
}

Decimal Decimal::Truncate(Decimal d) {
  Truncate(d);
  return d;
}

void Decimal::Truncate(Decimal& d) {
  Int32 num = d.flags;
  if ((num & 16711680) != 0) {
    DecCalc::InternalRound(AsMutable(d), (Byte)(num >> 16), MidpointRounding::ToZero);
  }
}

Decimal Decimal::op_Implicit(Byte value) {
  return Decimal((UInt32)value);
}

Decimal Decimal::op_Implicit(SByte value) {
  return Decimal(value);
}

Decimal Decimal::op_Implicit(Int16 value) {
  return Decimal(value);
}

Decimal Decimal::op_Implicit(UInt16 value) {
  return Decimal((UInt32)value);
}

Decimal Decimal::op_Implicit(Char value) {
  return Decimal((UInt32)value);
}

Decimal Decimal::op_Implicit(Int32 value) {
  return Decimal(value);
}

Decimal Decimal::op_Implicit(UInt32 value) {
  return Decimal(value);
}

Decimal Decimal::op_Implicit(Int64 value) {
  return Decimal(value);
}

Decimal Decimal::op_Implicit(UInt64 value) {
  return Decimal(value);
}

Decimal Decimal::op_Explicit(Single value) {
  return Decimal(value);
}

Decimal Decimal::op_Explicit(Double value) {
  return Decimal(value);
}

Byte Decimal::op_Explicit(Decimal value, Byte) {
  return ToByte(value);
}

SByte Decimal::op_Explicit(Decimal value, SByte) {
  return ToSByte(value);
}

Char Decimal::op_Explicit(Decimal value, Char) {
  try{
    return (Char)ToUInt16(value);
  } catch (OverflowException innerException) {
  }
}

Int16 Decimal::op_Explicit(Decimal value, Int16) {
  return ToInt16(value);
}

UInt16 Decimal::op_Explicit(Decimal value, UInt16) {
  return ToUInt16(value);
}

Int32 Decimal::op_Explicit(Decimal value, Int32) {
  return ToInt32(value);
}

UInt32 Decimal::op_Explicit(Decimal value, UInt32) {
  return ToUInt32(value);
}

Int64 Decimal::op_Explicit(Decimal value, Int64) {
  return ToInt64(value);
}

UInt64 Decimal::op_Explicit(Decimal value, UInt64) {
  return ToUInt64(value);
}

Single Decimal::op_Explicit(Decimal value, Single) {
  return DecCalc::VarR4FromDec(value);
}

Double Decimal::op_Explicit(Decimal value, Double) {
  return DecCalc::VarR8FromDec(value);
}

Decimal Decimal::op_UnaryPlus(Decimal d) {
  return d;
}

Decimal Decimal::op_UnaryNegation(Decimal d) {
  return Decimal(d, d.flags ^ Int32::MinValue);
}

Decimal Decimal::op_Increment(Decimal d) {
  return Add(d, 1);
}

Decimal Decimal::op_Decrement(Decimal d) {
  return Subtract(d, 1);
}

Decimal Decimal::op_Addition(Decimal d1, Decimal d2) {
  DecCalc::DecAddSub(AsMutable(d1), AsMutable(d2), false);
  return d1;
}

Decimal Decimal::op_Subtraction(Decimal d1, Decimal d2) {
  DecCalc::DecAddSub(AsMutable(d1), AsMutable(d2), true);
  return d1;
}

Decimal Decimal::op_Multiply(Decimal d1, Decimal d2) {
  DecCalc::VarDecMul(AsMutable(d1), AsMutable(d2));
  return d1;
}

Decimal Decimal::op_Division(Decimal d1, Decimal d2) {
  DecCalc::VarDecDiv(AsMutable(d1), AsMutable(d2));
  return d1;
}

Decimal Decimal::op_Modulus(Decimal d1, Decimal d2) {
  DecCalc::VarDecMod(AsMutable(d1), AsMutable(d2));
  return d1;
}

Boolean Decimal::op_Equality(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) == 0;
}

Boolean Decimal::op_Inequality(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) != 0;
}

Boolean Decimal::op_LessThan(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) < 0;
}

Boolean Decimal::op_LessThanOrEqual(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) <= 0;
}

Boolean Decimal::op_GreaterThan(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) > 0;
}

Boolean Decimal::op_GreaterThanOrEqual(Decimal d1, Decimal d2) {
  return DecCalc::VarDecCmp(d1, d2) >= 0;
}

TypeCode Decimal::GetTypeCode() {
  return TypeCode::Decimal;
}

Decimal::DecCalc& Decimal::AsMutable(Decimal& d) {
  return Unsafe::As<Decimal, DecCalc>(d);
}

UInt32 Decimal::DecDivMod1E9(Decimal& value) {
  return DecCalc::DecDivMod1E9(AsMutable(value));
}

void Decimal::cctor() {
  Zero = 0;
  One = 1;
  MinusOne = -1;
  MaxValue = Decimal::MaxValue;
  MinValue = Decimal::MinValue;
}

} // namespace System::Private::CoreLib::System::DecimalNamespace
