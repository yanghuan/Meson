#include "Number-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Buffers/Text/FormattingHelpers-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::NumberNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers::Text;
using namespace System::Numerics;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

Number::DiyFp Number::DiyFp::CreateAndGetBoundaries(Double value, DiyFp& mMinus, DiyFp& mPlus) {
  DiyFp result = DiyFp(value);
  result.GetBoundaries(52, mMinus, mPlus);
  return result;
}

Number::DiyFp Number::DiyFp::CreateAndGetBoundaries(Single value, DiyFp& mMinus, DiyFp& mPlus) {
  DiyFp result = DiyFp(value);
  result.GetBoundaries(23, mMinus, mPlus);
  return result;
}

Number::DiyFp::DiyFp(Double value) {
  f = ExtractFractionAndBiasedExponent(value, e);
}

Number::DiyFp::DiyFp(Single value) {
  f = ExtractFractionAndBiasedExponent(value, e);
}

Number::DiyFp::DiyFp(UInt64 f, Int32 e) {
  this->f = f;
  this->e = e;
}

Number::DiyFp Number::DiyFp::Multiply(DiyFp& other) {
  UInt32 num = (UInt32)(f >> 32);
  UInt32 num2 = (UInt32)f;
  UInt32 num3 = (UInt32)(other.f >> 32);
  UInt32 num4 = (UInt32)other.f;
  UInt64 num5 = (UInt64)num * (UInt64)num3;
  UInt64 num6 = (UInt64)num2 * (UInt64)num3;
  UInt64 num7 = (UInt64)num * (UInt64)num4;
  UInt64 num8 = (UInt64)num2 * (UInt64)num4;
  UInt64 num9 = (num8 >> 32) + (UInt32)num7 + (UInt32)num6;
  num9 += 2147483648u;
  return DiyFp(num5 + (num7 >> 32) + (num6 >> 32) + (num9 >> 32), e + other.e + 64);
}

Number::DiyFp Number::DiyFp::Normalize() {
  Int32 num = BitOperations::LeadingZeroCount(f);
  return DiyFp(f << num, e - num);
}

Number::DiyFp Number::DiyFp::Subtract(DiyFp& other) {
  return DiyFp(f - other.f, e);
}

void Number::DiyFp::GetBoundaries(Int32 implicitBitIndex, DiyFp& mMinus, DiyFp& mPlus) {
  mPlus = DiyFp((f << 1) + 1, e - 1).Normalize();
  if (f == (UInt64)(1 << implicitBitIndex)) {
    mMinus = DiyFp((f << 2) - 1, e - 2);
  } else {
    mMinus = DiyFp((f << 1) - 1, e - 1);
  }
  mMinus = DiyFp(mMinus.f << mMinus.e - mPlus.e, mPlus.e);
}

Number::NumberBuffer::NumberBuffer(NumberBufferKind kind, Byte* digits, Int32 digitsLength) {
  DigitsCount = 0;
  Scale = 0;
  IsNegative = false;
  HasNonZeroTail = false;
  Kind = kind;
  Digits = Span<Byte>(digits, digitsLength);
  Digits[0] = 0;
}

Byte* Number::NumberBuffer::GetDigitsPointer() {
  return (Byte*)Unsafe::AsPointer(Digits[0]);
}

String Number::NumberBuffer::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  stringBuilder->Append(91);
  stringBuilder->Append(34);
  for (Int32 i = 0; i < Digits.get_Length(); i++) {
    Byte b = Digits[i];
    if (b == 0) {
      break;
    }
    stringBuilder->Append((Char)b);
  }
  stringBuilder->Append(34);
  stringBuilder->Append(", Length = ")->Append(DigitsCount);
  stringBuilder->Append(", Scale = ")->Append(Scale);
  stringBuilder->Append(", IsNegative = ")->Append(IsNegative);
  stringBuilder->Append(", HasNonZeroTail = ")->Append(HasNonZeroTail);
  stringBuilder->Append(", Kind = ")->Append(Kind);
  stringBuilder->Append(93);
  return stringBuilder->ToString();
}

void Number::BigInteger::Add(BigInteger& lhs, BigInteger& rhs, BigInteger& result) {
  BigInteger& reference = lhs._length < rhs._length ? rhs : lhs;
  BigInteger& reference2 = lhs._length < rhs._length ? lhs : rhs;
  Int32 length = reference._length;
  Int32 length2 = reference2._length;
  result._length = length;
  UInt64 num = 0;
  Int32 num2 = 0;
  Int32 num3 = 0;
  Int32 num4 = 0;
  while (num3 < length2) {
    UInt64 num5 = num + reference._blocks[num2] + reference2._blocks[num3];
    num = num5 >> 32;
    result._blocks[num4] = (UInt32)num5;
    num2++;
    num3++;
    num4++;
  }
  while (num2 < length) {
    UInt64 num6 = num + reference._blocks[num2];
    num = num6 >> 32;
    result._blocks[num4] = (UInt32)num6;
    num2++;
    num4++;
  }
  if (num != 0) {
    result._blocks[num4] = 1u;
    result._length++;
  }
}

Int32 Number::BigInteger::Compare(BigInteger& lhs, BigInteger& rhs) {
  Int32 length = lhs._length;
  Int32 length2 = rhs._length;
  Int32 num = length - length2;
  if (num != 0) {
    return num;
  }
  if (length == 0) {
    return 0;
  }
  for (Int32 num2 = length - 1; num2 >= 0; num2--) {
    Int64 num3 = (Int64)lhs._blocks[num2] - (Int64)rhs._blocks[num2];
    if (num3 != 0) {
      if (num3 <= 0) {
        return -1;
      }
      return 1;
    }
  }
  return 0;
}

UInt32 Number::BigInteger::CountSignificantBits(UInt32 value) {
  return (UInt32)(32 - BitOperations::LeadingZeroCount(value));
}

UInt32 Number::BigInteger::CountSignificantBits(UInt64 value) {
  return (UInt32)(64 - BitOperations::LeadingZeroCount(value));
}

UInt32 Number::BigInteger::CountSignificantBits(BigInteger& value) {
  if (value.IsZero()) {
    return 0u;
  }
  UInt32 num = (UInt32)(value._length - 1);
  return num * 32 + CountSignificantBits(value._blocks[num]);
}

void Number::BigInteger::DivRem(BigInteger& lhs, BigInteger& rhs, BigInteger& quo, BigInteger& rem) {
  if (lhs.IsZero()) {
    SetZero(quo);
    SetZero(rem);
    return;
  }
  Int32 length = lhs._length;
  Int32 length2 = rhs._length;
  if (length == 1 && length2 == 1) {
    UInt32 result;
    UInt32 value = Math::DivRem(*lhs._blocks, *rhs._blocks, result);
    SetUInt32(quo, value);
    SetUInt32(rem, result);
    return;
  }
  if (length2 == 1) {
    Int32 num = length;
    UInt64 b = *rhs._blocks;
    UInt64 result2 = 0;
    for (Int32 num2 = num - 1; num2 >= 0; num2--) {
      UInt64 a = (result2 << 32) | lhs._blocks[num2];
      UInt64 num3 = Math::DivRem(a, b, result2);
      if (num3 == 0 && num2 == num - 1) {
        num--;
      } else {
        quo._blocks[num2] = (UInt32)num3;
      }
    }
    quo._length = num;
    SetUInt32(rem, (UInt32)result2);
    return;
  }
  if (length2 > length) {
    SetZero(quo);
    SetValue(rem, lhs);
    return;
  }
  Int32 num4 = length - length2 + 1;
  SetValue(rem, lhs);
  Int32 num5 = length;
  UInt32 num6 = rhs._blocks[length2 - 1];
  UInt32 num7 = rhs._blocks[length2 - 2];
  Int32 num8 = BitOperations::LeadingZeroCount(num6);
  Int32 num9 = 32 - num8;
  if (num8 > 0) {
    num6 = ((num6 << num8) | (num7 >> num9));
    num7 <<= num8;
    if (length2 > 2) {
      num7 |= rhs._blocks[length2 - 3] >> num9;
    }
  }
  for (Int32 num10 = length; num10 >= length2; num10--) {
    Int32 num11 = num10 - length2;
    UInt32 num12 = (num10 < length) ? rem._blocks[num10] : 0u;
    UInt64 num13 = ((UInt64)num12 << 32) | rem._blocks[num10 - 1];
    UInt32 num14 = (num10 > 1) ? rem._blocks[num10 - 2] : 0u;
    if (num8 > 0) {
      num13 = ((num13 << num8) | (num14 >> num9));
      num14 <<= num8;
      if (num10 > 2) {
        num14 |= rem._blocks[num10 - 3] >> num9;
      }
    }
    UInt64 num15 = num13 / num6;
    if (num15 > UInt32::MaxValue) {
      num15 = 4294967295;
    }
    while (DivideGuessTooBig(num15, num13, num14, num6, num7)) {
      num15--;
    }
    if (num15 != 0) {
      UInt32 num16 = SubtractDivisor(rem, num11, rhs, num15);
      if (num16 != num12) {
        num16 = AddDivisor(rem, num11, rhs);
        num15--;
      }
    }
    if (num4 != 0) {
      if (num15 == 0 && num11 == num4 - 1) {
        num4--;
      } else {
        quo._blocks[num11] = (UInt32)num15;
      }
    }
    if (num10 < num5) {
      num5--;
    }
  }
  quo._length = num4;
  for (Int32 num17 = num5 - 1; num17 >= 0; num17--) {
    if (rem._blocks[num17] == 0) {
      num5--;
    }
  }
  rem._length = num5;
}

UInt32 Number::BigInteger::HeuristicDivide(BigInteger& dividend, BigInteger& divisor) {
  Int32 num = divisor._length;
  if (dividend._length < num) {
    return 0u;
  }
  Int32 num2 = num - 1;
  UInt32 num3 = dividend._blocks[num2] / (divisor._blocks[num2] + 1);
  if (num3 != 0) {
    Int32 num4 = 0;
    UInt64 num5 = 0;
    UInt64 num6 = 0;
    do {
      UInt64 num7 = (UInt64)((Int64)divisor._blocks[num4] * (Int64)num3) + num6;
      num6 = num7 >> 32;
      UInt64 num8 = (UInt64)((Int64)dividend._blocks[num4] - (Int64)(UInt32)num7) - num5;
      num5 = ((num8 >> 32) & 1);
      dividend._blocks[num4] = (UInt32)num8;
      num4++;
    } while (num4 < num)
    while (num > 0 && dividend._blocks[num - 1] == 0) {
      num--;
    }
    dividend._length = num;
  }
  if (Compare(dividend, divisor) >= 0) {
    num3++;
    Int32 num9 = 0;
    UInt64 num10 = 0;
    do {
      UInt64 num11 = (UInt64)((Int64)dividend._blocks[num9] - (Int64)divisor._blocks[num9]) - num10;
      num10 = ((num11 >> 32) & 1);
      dividend._blocks[num9] = (UInt32)num11;
      num9++;
    } while (num9 < num)
    while (num > 0 && dividend._blocks[num - 1] == 0) {
      num--;
    }
    dividend._length = num;
  }
  return num3;
}

void Number::BigInteger::Multiply(BigInteger& lhs, UInt32 value, BigInteger& result) {
  if (!lhs.IsZero()) {
    switch (value.get()) {
      case 1u:
        break;
      case 0u:
        SetZero(result);
        return;
      default:
        {
          Int32 length = lhs._length;
          Int32 i = 0;
          UInt32 num = 0u;
          for (; i < length; i++) {
            UInt64 num2 = (UInt64)((Int64)lhs._blocks[i] * (Int64)value + num);
            result._blocks[i] = (UInt32)num2;
            num = (UInt32)(num2 >> 32);
          }
          if (num != 0) {
            result._blocks[i] = num;
            result._length = length + 1;
          } else {
            result._length = length;
          }
          return;
        }}
  }
  SetValue(result, lhs);
}

void Number::BigInteger::Multiply(BigInteger& lhs, BigInteger& rhs, BigInteger& result) {
  if (lhs.IsZero() || rhs.IsOne()) {
    SetValue(result, lhs);
    return;
  }
  if (rhs.IsZero()) {
    SetZero(result);
    return;
  }
  BigInteger& reference = lhs;
  Int32 length = lhs._length;
  BigInteger& reference2 = rhs;
  Int32 length2 = rhs._length;
  if (length < length2) {
    reference = rhs;
    length = rhs._length;
    reference2 = lhs;
    length2 = lhs._length;
  }
  Int32 num = result._length = length2 + length;
  Buffer::ZeroMemory((Byte*)result.GetBlocksPointer(), (UInt32)(num * 4));
  Int32 num2 = 0;
  Int32 num3 = 0;
  while (num2 < length2) {
    if (reference2._blocks[num2] != 0) {
      Int32 num4 = 0;
      Int32 num5 = num3;
      UInt64 num6 = 0;
      do {
        UInt64 num7 = (UInt64)(result._blocks[num5] + (Int64)reference2._blocks[num2] * (Int64)reference._blocks[num4]) + num6;
        num6 = num7 >> 32;
        result._blocks[num5] = (UInt32)num7;
        num5++;
        num4++;
      } while (num4 < length)
      result._blocks[num5] = (UInt32)num6;
    }
    num2++;
    num3++;
  }
  if (num > 0 && result._blocks[num - 1] == 0) {
    result._length--;
  }
}

void Number::BigInteger::Pow2(UInt32 exponent, BigInteger& result) {
  UInt32 remainder;
  UInt32 num = DivRem32(exponent, remainder);
  result._length = (Int32)(num + 1);
  if (num != 0) {
    Buffer::ZeroMemory((Byte*)result.GetBlocksPointer(), num * 4);
  }
  result._blocks[num] = (UInt32)(1 << (Int32)remainder);
}

void Number::BigInteger::Pow10(UInt32 exponent, BigInteger& result) {
  BigInteger result2;
  SetUInt32(result2, s_Pow10UInt32Table[exponent & 7]);
  BigInteger& reference = result2;
  BigInteger result3;
  SetZero(result3);
  BigInteger& reference2 = result3;
  exponent >>= 3;
  UInt32 num = 0u;
  while (exponent != 0) {
    if ((exponent & 1) != 0) {
      {
        UInt32* ptr = &s_Pow10BigNumTable[s_Pow10BigNumTableIndices[num]];
        Multiply(reference, *(BigInteger*)ptr, reference2);
      }
      BigInteger& reference3 = reference2;
      reference2 = reference;
      reference = reference3;
    }
    num++;
    exponent >>= 1;
  }
  SetValue(result, reference);
}

UInt32 Number::BigInteger::AddDivisor(BigInteger& lhs, Int32 lhsStartIndex, BigInteger& rhs) {
  Int32 length = lhs._length;
  Int32 length2 = rhs._length;
  UInt64 num = 0;
  for (Int32 i = 0; i < length2; i++) {
    UInt32& reference = lhs._blocks[lhsStartIndex + i];
    UInt64 num2 = reference + num + rhs._blocks[i];
    reference = (UInt32)num2;
    num = num2 >> 32;
  }
  return (UInt32)num;
}

Boolean Number::BigInteger::DivideGuessTooBig(UInt64 q, UInt64 valHi, UInt32 valLo, UInt32 divHi, UInt32 divLo) {
  UInt64 num = divHi * q;
  UInt64 num2 = divLo * q;
  num += num2 >> 32;
  num2 &= UInt32::MaxValue;
  if (num < valHi) {
    return false;
  }
  if (num > valHi) {
    return true;
  }
  if (num2 < valLo) {
    return false;
  }
  if (num2 > valLo) {
    return true;
  }
  return false;
}

UInt32 Number::BigInteger::SubtractDivisor(BigInteger& lhs, Int32 lhsStartIndex, BigInteger& rhs, UInt64 q) {
  Int32 num = lhs._length - lhsStartIndex;
  Int32 length = rhs._length;
  UInt64 num2 = 0;
  for (Int32 i = 0; i < length; i++) {
    num2 += rhs._blocks[i] * q;
    UInt32 num3 = (UInt32)num2;
    num2 >>= 32;
    UInt32& reference = lhs._blocks[lhsStartIndex + i];
    if (reference < num3) {
      num2++;
    }
    reference -= num3;
  }
  return (UInt32)num2;
}

void Number::BigInteger::Add(UInt32 value) {
  Int32 length = _length;
  if (length == 0) {
    SetUInt32(*this, value);
    return;
  }
  *_blocks += value;
  if (*_blocks >= value) {
    return;
  }
  for (Int32 i = 1; i < length; i++) {
    _blocks[i]++;
    if (_blocks[i] != 0) {
      return;
    }
  }
  _blocks[length] = 1u;
  _length = length + 1;
}

UInt32 Number::BigInteger::GetBlock(UInt32 index) {
  return _blocks[index];
}

Int32 Number::BigInteger::GetLength() {
  return _length;
}

Boolean Number::BigInteger::IsOne() {
  if (_length == 1) {
    return *_blocks == 1;
  }
  return false;
}

Boolean Number::BigInteger::IsZero() {
  return _length == 0;
}

void Number::BigInteger::Multiply(UInt32 value) {
  Multiply(*this, value, *this);
}

void Number::BigInteger::Multiply(BigInteger& value) {
  BigInteger result;
  SetValue(result, *this);
  Multiply(result, value, *this);
}

void Number::BigInteger::Multiply10() {
  if (!IsZero()) {
    Int32 i = 0;
    Int32 length = _length;
    UInt64 num = 0;
    for (; i < length; i++) {
      UInt64 num2 = _blocks[i];
      UInt64 num3 = (num2 << 3) + (num2 << 1) + num;
      num = num3 >> 32;
      _blocks[i] = (UInt32)num3;
    }
    if (num != 0) {
      _blocks[i] = (UInt32)num;
      _length++;
    }
  }
}

void Number::BigInteger::MultiplyPow10(UInt32 exponent) {
  if (!IsZero()) {
    BigInteger result;
    Pow10(exponent, result);
    if (result._length == 1) {
      Multiply(*result._blocks);
    } else {
      Multiply(result);
    }
  }
}

void Number::BigInteger::SetUInt32(BigInteger& result, UInt32 value) {
  if (value == 0) {
    SetZero(result);
    return;
  }
  *result._blocks = value;
  result._length = 1;
}

void Number::BigInteger::SetUInt64(BigInteger& result, UInt64 value) {
  if (value <= UInt32::MaxValue) {
    SetUInt32(result, (UInt32)value);
    return;
  }
  *result._blocks = (UInt32)value;
  result._blocks[1] = (UInt32)(value >> 32);
  result._length = 2;
}

void Number::BigInteger::SetValue(BigInteger& result, BigInteger& value) {
  Int32 num = result._length = value._length;
  Buffer::Memcpy((Byte*)result.GetBlocksPointer(), (Byte*)value.GetBlocksPointer(), num * 4);
}

void Number::BigInteger::SetZero(BigInteger& result) {
  result._length = 0;
}

void Number::BigInteger::ShiftLeft(UInt32 shift) {
  Int32 length = _length;
  if (length == 0 || shift == 0) {
    return;
  }
  UInt32 remainder;
  UInt32 num = DivRem32(shift, remainder);
  Int32 num2 = length - 1;
  Int32 num3 = num2 + (Int32)num;
  if (remainder == 0) {
    while (num2 >= 0) {
      _blocks[num3] = _blocks[num2];
      num2--;
      num3--;
    }
    _length += (Int32)num;
    Buffer::ZeroMemory((Byte*)GetBlocksPointer(), num * 4);
    return;
  }
  num3++;
  _length = num3 + 1;
  UInt32 num4 = 32 - remainder;
  UInt32 num5 = 0u;
  UInt32 num6 = _blocks[num2];
  UInt32 num7 = num6 >> (Int32)num4;
  while (num2 > 0) {
    _blocks[num3] = (num5 | num7);
    num5 = num6 << (Int32)remainder;
    num2--;
    num3--;
    num6 = _blocks[num2];
    num7 = num6 >> (Int32)num4;
  }
  _blocks[num3] = (num5 | num7);
  _blocks[num3 - 1] = num6 << (Int32)remainder;
  Buffer::ZeroMemory((Byte*)GetBlocksPointer(), num * 4);
  if (_blocks[_length - 1] == 0) {
    _length--;
  }
}

UInt64 Number::BigInteger::ToUInt64() {
  if (_length > 1) {
    return ((UInt64)_blocks[1] << 32) + *_blocks;
  }
  if (_length > 0) {
    return *_blocks;
  }
  return 0;
}

UInt32* Number::BigInteger::GetBlocksPointer() {
  return (UInt32*)Unsafe::AsPointer(*_blocks);
}

UInt32 Number::BigInteger::DivRem32(UInt32 value, UInt32& remainder) {
  remainder = (value & 31);
  return value >> 5;
}

void Number::BigInteger::cctor() {
  s_Pow10UInt32Table = rt::newarr<Array<UInt32>>(8);
  s_Pow10BigNumTableIndices = rt::newarr<Array<Int32>>(8);
  s_Pow10BigNumTable = rt::newarr<Array<UInt32>>(233);
}

Boolean Number::Grisu3::TryRunDouble(Double value, Int32 requestedDigits, NumberBuffer& number) {
  Double value2 = Double::IsNegative(value) ? (0 - value) : value;
  DiyFp diyFp;
  Boolean flag;
  Int32 length;
  Int32 decimalExponent;
  if (requestedDigits == -1) {
    DiyFp mMinus;
    DiyFp mPlus;
    diyFp = DiyFp::CreateAndGetBoundaries(value2, mMinus, mPlus);
    DiyFp w = diyFp.Normalize();
    flag = TryRunShortest(mMinus, w, mPlus, number.Digits, length, decimalExponent);
  } else {
    diyFp = DiyFp(value2);
    DiyFp w2 = diyFp.Normalize();
    flag = TryRunCounted(w2, requestedDigits, number.Digits, length, decimalExponent);
  }
  if (flag) {
    number.Scale = length + decimalExponent;
    number.Digits[length] = 0;
    number.DigitsCount = length;
  }
  return flag;
}

Boolean Number::Grisu3::TryRunSingle(Single value, Int32 requestedDigits, NumberBuffer& number) {
  Single value2 = Single::IsNegative(value) ? (0 - value) : value;
  DiyFp diyFp;
  Boolean flag;
  Int32 length;
  Int32 decimalExponent;
  if (requestedDigits == -1) {
    DiyFp mMinus;
    DiyFp mPlus;
    diyFp = DiyFp::CreateAndGetBoundaries(value2, mMinus, mPlus);
    DiyFp w = diyFp.Normalize();
    flag = TryRunShortest(mMinus, w, mPlus, number.Digits, length, decimalExponent);
  } else {
    diyFp = DiyFp(value2);
    DiyFp w2 = diyFp.Normalize();
    flag = TryRunCounted(w2, requestedDigits, number.Digits, length, decimalExponent);
  }
  if (flag) {
    number.Scale = length + decimalExponent;
    number.Digits[length] = 0;
    number.DigitsCount = length;
  }
  return flag;
}

Boolean Number::Grisu3::TryRunCounted(DiyFp& w, Int32 requestedDigits, Span<Byte> buffer, Int32& length, Int32& decimalExponent) {
  Int32 minExponent = -60 - (w.e + 64);
  Int32 maxExponent = -32 - (w.e + 64);
  Int32 decimalExponent2;
  DiyFp other = GetCachedPowerForBinaryExponentRange(minExponent, maxExponent, decimalExponent2);
  DiyFp w2 = w.Multiply(other);
  Int32 kappa;
  Boolean result = TryDigitGenCounted(w2, requestedDigits, buffer, length, kappa);
  decimalExponent = -decimalExponent2 + kappa;
  return result;
}

Boolean Number::Grisu3::TryRunShortest(DiyFp& boundaryMinus, DiyFp& w, DiyFp& boundaryPlus, Span<Byte> buffer, Int32& length, Int32& decimalExponent) {
  Int32 minExponent = -60 - (w.e + 64);
  Int32 maxExponent = -32 - (w.e + 64);
  Int32 decimalExponent2;
  DiyFp other = GetCachedPowerForBinaryExponentRange(minExponent, maxExponent, decimalExponent2);
  DiyFp w2 = w.Multiply(other);
  DiyFp low = boundaryMinus.Multiply(other);
  DiyFp high = boundaryPlus.Multiply(other);
  Int32 kappa;
  Boolean result = TryDigitGenShortest(low, w2, high, buffer, length, kappa);
  decimalExponent = -decimalExponent2 + kappa;
  return result;
}

UInt32 Number::Grisu3::BiggestPowerTen(UInt32 number, Int32 numberBits, Int32& exponentPlusOne) {
  Int32 num = (numberBits + 1) * 1233 >> 12;
  UInt32 num2 = s_SmallPowersOfTen[num];
  if (number < num2) {
    num--;
    num2 = s_SmallPowersOfTen[num];
  }
  exponentPlusOne = num + 1;
  return num2;
}

Boolean Number::Grisu3::TryDigitGenCounted(DiyFp& w, Int32 requestedDigits, Span<Byte> buffer, Int32& length, Int32& kappa) {
  UInt64 num = 1;
  DiyFp diyFp = DiyFp((UInt64)(1 << -w.e), w.e);
  UInt32 result = (UInt32)(w.f >> -diyFp.e);
  UInt64 num2 = w.f & (diyFp.f - 1);
  if (num2 == 0 && (requestedDigits >= 11 || result < s_SmallPowersOfTen[requestedDigits - 1])) {
    length = 0;
    kappa = 0;
    return false;
  }
  UInt32 num3 = BiggestPowerTen(result, 64 - -diyFp.e, kappa);
  length = 0;
  while (kappa > 0) {
    UInt32 num4 = Math::DivRem(result, num3, result);
    buffer[length] = (Byte)(48 + num4);
    length++;
    requestedDigits--;
    kappa--;
    if (requestedDigits == 0) {
      break;
    }
    num3 /= 10u;
  }
  if (requestedDigits == 0) {
    UInt64 rest = ((UInt64)result << -diyFp.e) + num2;
    return TryRoundWeedCounted(buffer, length, rest, (UInt64)num3 << -diyFp.e, num, kappa);
  }
  while (requestedDigits > 0 && num2 > num) {
    num2 *= 10;
    num *= 10;
    UInt32 num5 = (UInt32)(num2 >> -diyFp.e);
    buffer[length] = (Byte)(48 + num5);
    length++;
    requestedDigits--;
    kappa--;
    num2 &= diyFp.f - 1;
  }
  if (requestedDigits != 0) {
    buffer[0] = 0;
    length = 0;
    kappa = 0;
    return false;
  }
  return TryRoundWeedCounted(buffer, length, num2, diyFp.f, num, kappa);
}

Boolean Number::Grisu3::TryDigitGenShortest(DiyFp& low, DiyFp& w, DiyFp& high, Span<Byte> buffer, Int32& length, Int32& kappa) {
  UInt64 num = 1;
  DiyFp other = DiyFp(low.f - num, low.e);
  DiyFp diyFp = DiyFp(high.f + num, high.e);
  DiyFp diyFp2 = diyFp.Subtract(other);
  DiyFp diyFp3 = DiyFp((UInt64)(1 << -w.e), w.e);
  UInt32 result = (UInt32)(diyFp.f >> -diyFp3.e);
  UInt64 num2 = diyFp.f & (diyFp3.f - 1);
  UInt32 num3 = BiggestPowerTen(result, 64 - -diyFp3.e, kappa);
  length = 0;
  while (kappa > 0) {
    UInt32 num4 = Math::DivRem(result, num3, result);
    buffer[length] = (Byte)(48 + num4);
    length++;
    kappa--;
    UInt64 num5 = ((UInt64)result << -diyFp3.e) + num2;
    if (num5 < diyFp2.f) {
      return TryRoundWeedShortest(buffer, length, diyFp.Subtract(w).f, diyFp2.f, num5, (UInt64)num3 << -diyFp3.e, num);
    }
    num3 /= 10u;
  }
  do {
    num2 *= 10;
    num *= 10;
    diyFp2 = DiyFp(diyFp2.f * 10, diyFp2.e);
    UInt32 num6 = (UInt32)(num2 >> -diyFp3.e);
    buffer[length] = (Byte)(48 + num6);
    length++;
    kappa--;
    num2 &= diyFp3.f - 1;
  } while (num2 >= diyFp2.f)
  return TryRoundWeedShortest(buffer, length, diyFp.Subtract(w).f * num, diyFp2.f, num2, diyFp3.f, num);
}

Number::DiyFp Number::Grisu3::GetCachedPowerForBinaryExponentRange(Int32 minExponent, Int32 maxExponent, Int32& decimalExponent) {
  Double num = Math::Ceiling((Double)(minExponent + 64 - 1) * 0.3010299956639812);
  Int32 num2 = (348 + (Int32)num - 1) / 8 + 1;
  decimalExponent = s_CachedPowersDecimalExponent[num2];
  return DiyFp(s_CachedPowersSignificand[num2], s_CachedPowersBinaryExponent[num2]);
}

Boolean Number::Grisu3::TryRoundWeedCounted(Span<Byte> buffer, Int32 length, UInt64 rest, UInt64 tenKappa, UInt64 unit, Int32& kappa) {
  if (unit >= tenKappa || tenKappa - unit <= unit) {
    return false;
  }
  if (tenKappa - rest > rest && tenKappa - 2 * rest >= 2 * unit) {
    return true;
  }
  if (rest > unit && (tenKappa <= rest - unit || tenKappa - (rest - unit) <= rest - unit)) {
    buffer[length - 1]++;
    Int32 num = length - 1;
    while (num > 0 && buffer[num] == 58) {
      buffer[num] = 48;
      buffer[num - 1]++;
      num--;
    }
    if (buffer[0] == 58) {
      buffer[0] = 49;
      kappa++;
    }
    return true;
  }
  return false;
}

Boolean Number::Grisu3::TryRoundWeedShortest(Span<Byte> buffer, Int32 length, UInt64 distanceTooHighW, UInt64 unsafeInterval, UInt64 rest, UInt64 tenKappa, UInt64 unit) {
  UInt64 num = distanceTooHighW - unit;
  UInt64 num2 = distanceTooHighW + unit;
  while (rest < num && unsafeInterval - rest >= tenKappa && (rest + tenKappa < num || num - rest >= rest + tenKappa - num)) {
    buffer[length - 1]--;
    rest += tenKappa;
  }
  if (rest < num2 && unsafeInterval - rest >= tenKappa && (rest + tenKappa < num2 || num2 - rest > rest + tenKappa - num2)) {
    return false;
  }
  if (2 * unit <= rest) {
    return rest <= unsafeInterval - 4 * unit;
  }
  return false;
}

void Number::Grisu3::cctor() {
  s_CachedPowersBinaryExponent = rt::newarr<Array<Int16>>(87);
  s_CachedPowersDecimalExponent = rt::newarr<Array<Int16>>(87);
  s_CachedPowersSignificand = rt::newarr<Array<UInt64>>(87);
  s_SmallPowersOfTen = rt::newarr<Array<UInt32>>(10);
}

Number::FloatingPointInfo::FloatingPointInfo(UInt16 denormalMantissaBits, UInt16 exponentBits, Int32 maxBinaryExponent, Int32 exponentBias, UInt64 infinityBits) {
  ExponentBits = exponentBits;
  DenormalMantissaBits = denormalMantissaBits;
  NormalMantissaBits = (UInt16)(denormalMantissaBits + 1);
  OverflowDecimalExponent = (maxBinaryExponent + 2 * NormalMantissaBits) / 3;
  ExponentBias = exponentBias;
  MaxBinaryExponent = maxBinaryExponent;
  MinBinaryExponent = 1 - maxBinaryExponent;
  DenormalMantissaMask = (UInt64)((1 << (Int32)denormalMantissaBits) - 1);
  NormalMantissaMask = (UInt64)((1 << (Int32)NormalMantissaBits) - 1);
  InfinityBits = infinityBits;
  ZeroBits = 0;
}

void Number::FloatingPointInfo::cctor() {
  Double = FloatingPointInfo(52, 11, 1023, 1023, 9218868437227405312);
  Single = FloatingPointInfo(23, 8, 127, 127, 2139095040);
}

ReadOnlySpan<Byte> Number::get_CharToHexLookup() {
  return rt::newarr<Array<Byte>>(103);
}

void Number::Dragon4Double(Double value, Int32 cutoffNumber, Boolean isSignificantDigits, NumberBuffer& number) {
  Double num = Double::IsNegative(value) ? (0 - value) : value;
  Int32 exponent;
  UInt64 num2 = ExtractFractionAndBiasedExponent(value, exponent);
  Boolean hasUnequalMargins = false;
  UInt32 mantissaHighBitIdx;
  if (num2 >> 52 != 0) {
    mantissaHighBitIdx = 52u;
    hasUnequalMargins = (num2 == 4503599627370496);
  } else {
    mantissaHighBitIdx = (UInt32)BitOperations::Log2(num2);
  }
  Int32 decimalExponent;
  Int32 num3 = (Int32)Dragon4(num2, exponent, mantissaHighBitIdx, hasUnequalMargins, cutoffNumber, isSignificantDigits, number.Digits, decimalExponent);
  number.Scale = decimalExponent + 1;
  number.Digits[num3] = 0;
  number.DigitsCount = num3;
}

void Number::Dragon4Single(Single value, Int32 cutoffNumber, Boolean isSignificantDigits, NumberBuffer& number) {
  Single num = Single::IsNegative(value) ? (0 - value) : value;
  Int32 exponent;
  UInt32 num2 = ExtractFractionAndBiasedExponent(value, exponent);
  Boolean hasUnequalMargins = false;
  UInt32 mantissaHighBitIdx;
  if (num2 >> 23 != 0) {
    mantissaHighBitIdx = 23u;
    hasUnequalMargins = (num2 == 8388608);
  } else {
    mantissaHighBitIdx = (UInt32)BitOperations::Log2(num2);
  }
  Int32 decimalExponent;
  Int32 num3 = (Int32)Dragon4(num2, exponent, mantissaHighBitIdx, hasUnequalMargins, cutoffNumber, isSignificantDigits, number.Digits, decimalExponent);
  number.Scale = decimalExponent + 1;
  number.Digits[num3] = 0;
  number.DigitsCount = num3;
}

UInt32 Number::Dragon4(UInt64 mantissa, Int32 exponent, UInt32 mantissaHighBitIdx, Boolean hasUnequalMargins, Int32 cutoffNumber, Boolean isSignificantDigits, Span<Byte> buffer, Int32& decimalExponent) {
  Int32 num = 0;
  BigInteger result;
  BigInteger result2;
  BigInteger result3;
  BigInteger* ptr;
  if (hasUnequalMargins) {
    BigInteger result4;
    if (exponent > 0) {
      BigInteger::SetUInt64(result, 4 * mantissa);
      result.ShiftLeft((UInt32)exponent);
      BigInteger::SetUInt32(result2, 4u);
      BigInteger::Pow2((UInt32)exponent, result3);
      BigInteger::Pow2((UInt32)(exponent + 1), result4);
    } else {
      BigInteger::SetUInt64(result, 4 * mantissa);
      BigInteger::Pow2((UInt32)(-exponent + 2), result2);
      BigInteger::SetUInt32(result3, 1u);
      BigInteger::SetUInt32(result4, 2u);
    }
    ptr = &result4;
  } else {
    if (exponent > 0) {
      BigInteger::SetUInt64(result, 2 * mantissa);
      result.ShiftLeft((UInt32)exponent);
      BigInteger::SetUInt32(result2, 2u);
      BigInteger::Pow2((UInt32)exponent, result3);
    } else {
      BigInteger::SetUInt64(result, 2 * mantissa);
      BigInteger::Pow2((UInt32)(-exponent + 1), result2);
      BigInteger::SetUInt32(result3, 1u);
    }
    ptr = &result3;
  }
  Int32 num2 = (Int32)Math::Ceiling((Double)((Int32)mantissaHighBitIdx + exponent) * 0.3010299956639812 - 0.69);
  if (num2 > 0) {
    result2.MultiplyPow10((UInt32)num2);
  } else if (num2 < 0) {
    BigInteger result5;
    BigInteger::Pow10((UInt32)(-num2), result5);
    result.Multiply(result5);
    result3.Multiply(result5);
    if (ptr != &result3) {
      BigInteger::Multiply(result3, 2u, *ptr);
    }
  }

  Boolean flag = mantissa % 2 == 0;
  Boolean flag2 = false;
  if (cutoffNumber == -1) {
    BigInteger result6;
    BigInteger::Add(result, *ptr, result6);
    Int32 num3 = BigInteger::Compare(result6, result2);
    flag2 = (flag ? (num3 >= 0) : (num3 > 0));
  } else {
    flag2 = (BigInteger::Compare(result, result2) >= 0);
  }
  if (flag2) {
    num2++;
  } else {
    result.Multiply10();
    result3.Multiply10();
    if (ptr != &result3) {
      BigInteger::Multiply(result3, 2u, *ptr);
    }
  }
  Int32 num4 = num2 - buffer.get_Length();
  if (cutoffNumber != -1) {
    Int32 num5 = 0;
    num5 = ((!isSignificantDigits) ? (-cutoffNumber) : (num2 - cutoffNumber));
    if (num5 > num4) {
      num4 = num5;
    }
  }
  num2 = (decimalExponent = num2 - 1);
  UInt32 block = result2.GetBlock((UInt32)(result2.GetLength() - 1));
  if (block < 8 || block > 429496729) {
    UInt32 num6 = (UInt32)BitOperations::Log2(block);
    UInt32 shift = (59 - num6) % 32u;
    result2.ShiftLeft(shift);
    result.ShiftLeft(shift);
    result3.ShiftLeft(shift);
    if (ptr != &result3) {
      BigInteger::Multiply(result3, 2u, *ptr);
    }
  }
  Boolean flag3;
  Boolean flag4;
  UInt32 num7;
  if (cutoffNumber == -1) {
    while (true) {
      num7 = BigInteger::HeuristicDivide(result, result2);
      BigInteger result7;
      BigInteger::Add(result, *ptr, result7);
      Int32 num8 = BigInteger::Compare(result, result3);
      Int32 num9 = BigInteger::Compare(result7, result2);
      if (flag) {
        flag3 = (num8 <= 0);
        flag4 = (num9 >= 0);
      } else {
        flag3 = (num8 < 0);
        flag4 = (num9 > 0);
      }
      if (flag3 || flag4 || num2 == num4) {
        break;
      }
      buffer[num] = (Byte)(48 + num7);
      num++;
      result.Multiply10();
      result3.Multiply10();
      if (ptr != &result3) {
        BigInteger::Multiply(result3, 2u, *ptr);
      }
      num2--;
    }
  } else {
    if (num2 < num4) {
      num7 = BigInteger::HeuristicDivide(result, result2);
      if (num7 > 5 || (num7 == 5 && !result.IsZero())) {
        decimalExponent++;
        num7 = 1u;
      }
      buffer[num] = (Byte)(48 + num7);
      return (UInt32)(num + 1);
    }
    flag3 = false;
    flag4 = false;
    while (true) {
      num7 = BigInteger::HeuristicDivide(result, result2);
      if (result.IsZero() || num2 <= num4) {
        break;
      }
      buffer[num] = (Byte)(48 + num7);
      num++;
      result.Multiply10();
      num2--;
    }
  }
  Boolean flag5 = flag3;
  if (flag3 == flag4) {
    result.ShiftLeft(1u);
    Int32 num10 = BigInteger::Compare(result, result2);
    flag5 = (num10 < 0);
    if (num10 == 0) {
      flag5 = ((num7 & 1) == 0);
    }
  }
  if (flag5) {
    buffer[num] = (Byte)(48 + num7);
    num++;
  } else if (num7 == 9) {
    while (true) {
      if (num == 0) {
        buffer[num] = 49;
        num++;
        decimalExponent++;
        break;
      }
      num--;
      if (buffer[num] != 57) {
        buffer[num]++;
        num++;
        break;
      }
    }
  } else {
    buffer[num] = (Byte)(48 + num7 + 1);
    num++;
  }

  return (UInt32)num;
}

String Number::FormatDecimal(Decimal value, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  Int32 digits;
  Char c = ParseFormatSpecifier(format, digits);
  Byte as[31] = {};
  Byte* digits2 = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Decimal, digits2, 31);
  DecimalToNumber(value, number);
  Char as[32] = {};
  Char* pointer = as;
  ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
  if (c != 0) {
    NumberToString(sb, number, c, digits, info);
  } else {
    NumberToStringFormat(sb, number, format, info);
  }
  return sb.ToString();
}

Boolean Number::TryFormatDecimal(Decimal value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten) {
  Int32 digits;
  Char c = ParseFormatSpecifier(format, digits);
  Byte as[31] = {};
  Byte* digits2 = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Decimal, digits2, 31);
  DecimalToNumber(value, number);
  Char as[32] = {};
  Char* pointer = as;
  ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
  if (c != 0) {
    NumberToString(sb, number, c, digits, info);
  } else {
    NumberToStringFormat(sb, number, format, info);
  }
  return sb.TryCopyTo(destination, charsWritten);
}

void Number::DecimalToNumber(Decimal& d, NumberBuffer& number) {
  Byte* digitsPointer = number.GetDigitsPointer();
  number.DigitsCount = 29;
  number.IsNegative = d.get_IsNegative();
  Byte* bufferEnd = digitsPointer + 29;
  while ((d.get_Mid() | d.get_High()) != 0) {
    bufferEnd = UInt32ToDecChars(bufferEnd, Decimal::DecDivMod1E9(d), 9);
  }
  bufferEnd = UInt32ToDecChars(bufferEnd, d.get_Low(), 0);
  Int32 num = number.DigitsCount = (Int32)(digitsPointer + 29 - bufferEnd);
  number.Scale = num - d.get_Scale();
  Byte* digitsPointer2 = number.GetDigitsPointer();
  while (--num >= 0) {
    *(digitsPointer2++) = *(bufferEnd++);
  }
  *digitsPointer2 = 0;
}

String Number::FormatDouble(Double value, String format, NumberFormatInfo info) {
  Char as[32] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder sb = ValueStringBuilder(initialBuffer);
  String as = FormatDouble(sb, value, format, info);
  return as != nullptr ? as : sb.ToString();
}

Boolean Number::TryFormatDouble(Double value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten) {
  Char as[32] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder sb = ValueStringBuilder(initialBuffer);
  String text = FormatDouble(sb, value, format, info);
  if (text == nullptr) {
    return sb.TryCopyTo(destination, charsWritten);
  }
  return TryCopyTo(text, destination, charsWritten);
}

Int32 Number::GetFloatingPointMaxDigitsAndPrecision(Char fmt, Int32& precision, NumberFormatInfo info, Boolean& isSignificantDigits) {
  if (fmt == 0) {
    isSignificantDigits = true;
    return precision;
  }
  Int32 result = precision;
  switch (fmt.get()) {
    case 67:
    case 99:
      if (precision == -1) {
        precision = info->set_CurrencyDecimalDigits();
      }
      isSignificantDigits = false;
      break;
    case 69:
    case 101:
      if (precision == -1) {
        precision = 6;
      }
      precision++;
      isSignificantDigits = true;
      break;
    case 70:
    case 78:
    case 102:
    case 110:
      if (precision == -1) {
        precision = info->set_NumberDecimalDigits();
      }
      isSignificantDigits = false;
      break;
    case 71:
    case 103:
      if (precision == 0) {
        precision = -1;
      }
      isSignificantDigits = true;
      break;
    case 80:
    case 112:
      if (precision == -1) {
        precision = info->set_PercentDecimalDigits();
      }
      precision += 2;
      isSignificantDigits = false;
      break;
    case 82:
    case 114:
      precision = -1;
      isSignificantDigits = true;
      break;
    default:
      rt::throw_exception<FormatException>(SR::get_Argument_BadFormatSpecifier());
  }
  return result;
}

String Number::FormatDouble(ValueStringBuilder& sb, Double value, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  if (!Double::IsFinite(value)) {
    if (Double::IsNaN(value)) {
      return info->get_NaNSymbol();
    }
    if (!Double::IsNegative(value)) {
      return info->get_PositiveInfinitySymbol();
    }
    return info->get_NegativeInfinitySymbol();
  }
  Int32 digits;
  Char c = ParseFormatSpecifier(format, digits);
  Byte as[769] = {};
  Byte* digits2 = as;
  if (c == 0) {
    digits = 15;
  }
  NumberBuffer number = NumberBuffer(NumberBufferKind::FloatingPoint, digits2, 769);
  number.IsNegative = Double::IsNegative(value);
  Boolean isSignificantDigits;
  Int32 nMaxDigits = GetFloatingPointMaxDigitsAndPrecision(c, digits, info, isSignificantDigits);
  if (value != 0 && (!isSignificantDigits || !Grisu3::TryRunDouble(value, digits, number))) {
    Dragon4Double(value, digits, isSignificantDigits, number);
  }
  if (c != 0) {
    if (digits == -1) {
      nMaxDigits = Math::Max(number.DigitsCount, 17);
    }
    NumberToString(sb, number, c, nMaxDigits, info);
  } else {
    NumberToStringFormat(sb, number, format, info);
  }
  return nullptr;
}

String Number::FormatSingle(Single value, String format, NumberFormatInfo info) {
  Char as[32] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder sb = ValueStringBuilder(initialBuffer);
  String as = FormatSingle(sb, value, format, info);
  return as != nullptr ? as : sb.ToString();
}

Boolean Number::TryFormatSingle(Single value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten) {
  Char as[32] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder sb = ValueStringBuilder(initialBuffer);
  String text = FormatSingle(sb, value, format, info);
  if (text == nullptr) {
    return sb.TryCopyTo(destination, charsWritten);
  }
  return TryCopyTo(text, destination, charsWritten);
}

String Number::FormatSingle(ValueStringBuilder& sb, Single value, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  if (!Single::IsFinite(value)) {
    if (Single::IsNaN(value)) {
      return info->get_NaNSymbol();
    }
    if (!Single::IsNegative(value)) {
      return info->get_PositiveInfinitySymbol();
    }
    return info->get_NegativeInfinitySymbol();
  }
  Int32 digits;
  Char c = ParseFormatSpecifier(format, digits);
  Byte as[114] = {};
  Byte* digits2 = as;
  if (c == 0) {
    digits = 7;
  }
  NumberBuffer number = NumberBuffer(NumberBufferKind::FloatingPoint, digits2, 114);
  number.IsNegative = Single::IsNegative(value);
  Boolean isSignificantDigits;
  Int32 nMaxDigits = GetFloatingPointMaxDigitsAndPrecision(c, digits, info, isSignificantDigits);
  if (value != 0 && (!isSignificantDigits || !Grisu3::TryRunSingle(value, digits, number))) {
    Dragon4Single(value, digits, isSignificantDigits, number);
  }
  if (c != 0) {
    if (digits == -1) {
      nMaxDigits = Math::Max(number.DigitsCount, 9);
    }
    NumberToString(sb, number, c, nMaxDigits, info);
  } else {
    NumberToStringFormat(sb, number, format, info);
  }
  return nullptr;
}

Boolean Number::TryCopyTo(String source, Span<Char> destination, Int32& charsWritten) {
  if (MemoryExtensions::AsSpan(source).TryCopyTo(destination)) {
    charsWritten = source->get_Length();
    return true;
  }
  charsWritten = 0;
  return false;
}

Char Number::GetHexBase(Char fmt) {
  return (Char)(fmt - 33);
}

String Number::FormatInt32(Int32 value, Int32 hexMask, String format, IFormatProvider provider) {
  auto FormatInt32Slow = [](Int32 value, Int32 hexMask, String format, IFormatProvider provider) -> String {
    ReadOnlySpan<Char> format2 = format;
    Int32 digits;
    Char c = ParseFormatSpecifier(format2, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      if (value < 0) {
        return NegativeInt32ToDecStr(value, digits, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign());
      }
      return UInt32ToDecStr((UInt32)value, digits);
    }
    if (c2 == 88) {
      return Int32ToHexStr(value & hexMask, GetHexBase(c), digits);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[11] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 11);
    Int32ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format2, instance);
    }
    return sb.ToString();
  };
  if (String::in::IsNullOrEmpty(format)) {
    if (value < 0) {
      return NegativeInt32ToDecStr(value, -1, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign());
    }
    return UInt32ToDecStr((UInt32)value);
  }
  return FormatInt32Slow(value, hexMask, format, provider);
}

Boolean Number::TryFormatInt32(Int32 value, Int32 hexMask, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  auto TryFormatInt32Slow = [](Int32 value, Int32 hexMask, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) -> Boolean {
    Int32 digits;
    Char c = ParseFormatSpecifier(format, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      if (value < 0) {
        return TryNegativeInt32ToDecStr(value, digits, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign(), destination, charsWritten);
      }
      return TryUInt32ToDecStr((UInt32)value, digits, destination, charsWritten);
    }
    if (c2 == 88) {
      return TryInt32ToHexStr(value & hexMask, GetHexBase(c), digits, destination, charsWritten);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[11] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 11);
    Int32ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format, instance);
    }
    return sb.TryCopyTo(destination, charsWritten);
  };
  if (format.get_Length() == 0) {
    if (value < 0) {
      return TryNegativeInt32ToDecStr(value, -1, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign(), destination, charsWritten);
    }
    return TryUInt32ToDecStr((UInt32)value, -1, destination, charsWritten);
  }
  return TryFormatInt32Slow(value, hexMask, format, provider, destination, charsWritten);
}

String Number::FormatUInt32(UInt32 value, String format, IFormatProvider provider) {
  auto FormatUInt32Slow = [](UInt32 value, String format, IFormatProvider provider) -> String {
    ReadOnlySpan<Char> format2 = format;
    Int32 digits;
    Char c = ParseFormatSpecifier(format2, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      return UInt32ToDecStr(value, digits);
    }
    if (c2 == 88) {
      return Int32ToHexStr((Int32)value, GetHexBase(c), digits);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[11] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 11);
    UInt32ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format2, instance);
    }
    return sb.ToString();
  };
  if (String::in::IsNullOrEmpty(format)) {
    return UInt32ToDecStr(value);
  }
  return FormatUInt32Slow(value, format, provider);
}

Boolean Number::TryFormatUInt32(UInt32 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  auto TryFormatUInt32Slow = [](UInt32 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) -> Boolean {
    Int32 digits;
    Char c = ParseFormatSpecifier(format, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      return TryUInt32ToDecStr(value, digits, destination, charsWritten);
    }
    if (c2 == 88) {
      return TryInt32ToHexStr((Int32)value, GetHexBase(c), digits, destination, charsWritten);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[11] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 11);
    UInt32ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format, instance);
    }
    return sb.TryCopyTo(destination, charsWritten);
  };
  if (format.get_Length() == 0) {
    return TryUInt32ToDecStr(value, -1, destination, charsWritten);
  }
  return TryFormatUInt32Slow(value, format, provider, destination, charsWritten);
}

String Number::FormatInt64(Int64 value, String format, IFormatProvider provider) {
  auto FormatInt64Slow = [](Int64 value, String format, IFormatProvider provider) -> String {
    ReadOnlySpan<Char> format2 = format;
    Int32 digits;
    Char c = ParseFormatSpecifier(format2, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      if (value < 0) {
        return NegativeInt64ToDecStr(value, digits, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign());
      }
      return UInt64ToDecStr((UInt64)value, digits);
    }
    if (c2 == 88) {
      return Int64ToHexStr(value, GetHexBase(c), digits);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[20] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 20);
    Int64ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format2, instance);
    }
    return sb.ToString();
  };
  if (String::in::IsNullOrEmpty(format)) {
    if (value < 0) {
      return NegativeInt64ToDecStr(value, -1, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign());
    }
    return UInt64ToDecStr((UInt64)value, -1);
  }
  return FormatInt64Slow(value, format, provider);
}

Boolean Number::TryFormatInt64(Int64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  auto TryFormatInt64Slow = [](Int64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) -> Boolean {
    Int32 digits;
    Char c = ParseFormatSpecifier(format, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      if (value < 0) {
        return TryNegativeInt64ToDecStr(value, digits, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign(), destination, charsWritten);
      }
      return TryUInt64ToDecStr((UInt64)value, digits, destination, charsWritten);
    }
    if (c2 == 88) {
      return TryInt64ToHexStr(value, GetHexBase(c), digits, destination, charsWritten);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[20] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 20);
    Int64ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format, instance);
    }
    return sb.TryCopyTo(destination, charsWritten);
  };
  if (format.get_Length() == 0) {
    if (value < 0) {
      return TryNegativeInt64ToDecStr(value, -1, NumberFormatInfo::in::GetInstance(provider)->get_NegativeSign(), destination, charsWritten);
    }
    return TryUInt64ToDecStr((UInt64)value, -1, destination, charsWritten);
  }
  return TryFormatInt64Slow(value, format, provider, destination, charsWritten);
}

String Number::FormatUInt64(UInt64 value, String format, IFormatProvider provider) {
  auto FormatUInt64Slow = [](UInt64 value, String format, IFormatProvider provider) -> String {
    ReadOnlySpan<Char> format2 = format;
    Int32 digits;
    Char c = ParseFormatSpecifier(format2, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      return UInt64ToDecStr(value, digits);
    }
    if (c2 == 88) {
      return Int64ToHexStr((Int64)value, GetHexBase(c), digits);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[21] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 21);
    UInt64ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format2, instance);
    }
    return sb.ToString();
  };
  if (String::in::IsNullOrEmpty(format)) {
    return UInt64ToDecStr(value, -1);
  }
  return FormatUInt64Slow(value, format, provider);
}

Boolean Number::TryFormatUInt64(UInt64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  auto TryFormatUInt64Slow = [](UInt64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) -> Boolean {
    Int32 digits;
    Char c = ParseFormatSpecifier(format, digits);
    Char c2 = (Char)(c & 65503);
    if ((c2 == 71) ? (digits < 1) : (c2 == 68)) {
      return TryUInt64ToDecStr(value, digits, destination, charsWritten);
    }
    if (c2 == 88) {
      return TryInt64ToHexStr((Int64)value, GetHexBase(c), digits, destination, charsWritten);
    }
    NumberFormatInfo instance = NumberFormatInfo::in::GetInstance(provider);
    Byte as[21] = {};
    Byte* digits2 = as;
    NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits2, 21);
    UInt64ToNumber(value, number);
    Char as[32] = {};
    Char* pointer = as;
    ValueStringBuilder sb = ValueStringBuilder(Span<Char>(pointer, 32));
    if (c != 0) {
      NumberToString(sb, number, c, digits, instance);
    } else {
      NumberToStringFormat(sb, number, format, instance);
    }
    return sb.TryCopyTo(destination, charsWritten);
  };
  if (format.get_Length() == 0) {
    return TryUInt64ToDecStr(value, -1, destination, charsWritten);
  }
  return TryFormatUInt64Slow(value, format, provider, destination, charsWritten);
}

void Number::Int32ToNumber(Int32 value, NumberBuffer& number) {
  number.DigitsCount = 10;
  if (value >= 0) {
    number.IsNegative = false;
  } else {
    number.IsNegative = true;
    value = -value;
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  Byte* ptr = UInt32ToDecChars(digitsPointer + 10, (UInt32)value, 0);
  Int32 num = number.Scale = (number.DigitsCount = (Int32)(digitsPointer + 10 - ptr));
  Byte* digitsPointer2 = number.GetDigitsPointer();
  while (--num >= 0) {
    *(digitsPointer2++) = *(ptr++);
  }
  *digitsPointer2 = 0;
}

String Number::Int32ToDecStr(Int32 value) {
  if (value < 0) {
    return NegativeInt32ToDecStr(value, -1, NumberFormatInfo::in::get_CurrentInfo()->get_NegativeSign());
  }
  return UInt32ToDecStr((UInt32)value);
}

String Number::NegativeInt32ToDecStr(Int32 value, Int32 digits, String sNegative) {
  if (digits < 1) {
    digits = 1;
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits((UInt32)(-value))) + sNegative->get_Length();
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* ptr3 = UInt32ToDecChars(ptr2 + num, (UInt32)(-value), digits);
    for (Int32 num2 = sNegative->get_Length() - 1; num2 >= 0; num2--) {
      *(--ptr3) = sNegative[num2];
    }
  }
  return text;
}

Boolean Number::TryNegativeInt32ToDecStr(Int32 value, Int32 digits, String sNegative, Span<Char> destination, Int32& charsWritten) {
  if (digits < 1) {
    digits = 1;
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits((UInt32)(-value))) + sNegative->get_Length();
  if (num > destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* ptr2 = UInt32ToDecChars(ptr + num, (UInt32)(-value), digits);
    for (Int32 num2 = sNegative->get_Length() - 1; num2 >= 0; num2--) {
      *(--ptr2) = sNegative[num2];
    }
  }
  return true;
}

String Number::Int32ToHexStr(Int32 value, Char hexBase, Int32 digits) {
  if (digits < 1) {
    digits = 1;
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountHexDigits((UInt32)value));
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* ptr3 = Int32ToHexChars(ptr2 + num, (UInt32)value, hexBase, digits);
  }
  return text;
}

Boolean Number::TryInt32ToHexStr(Int32 value, Char hexBase, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  if (digits < 1) {
    digits = 1;
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountHexDigits((UInt32)value));
  if (num > destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* ptr2 = Int32ToHexChars(ptr + num, (UInt32)value, hexBase, digits);
  }
  return true;
}

Char* Number::Int32ToHexChars(Char* buffer, UInt32 value, Int32 hexBase, Int32 digits) {
  while (--digits >= 0 || value != 0) {
    Byte b = (Byte)(value & 15);
    *(--buffer) = (Char)(b + ((b < 10) ? 48 : hexBase));
    value >>= 4;
  }
  return buffer;
}

void Number::UInt32ToNumber(UInt32 value, NumberBuffer& number) {
  number.DigitsCount = 10;
  number.IsNegative = false;
  Byte* digitsPointer = number.GetDigitsPointer();
  Byte* ptr = UInt32ToDecChars(digitsPointer + 10, value, 0);
  Int32 num = number.Scale = (number.DigitsCount = (Int32)(digitsPointer + 10 - ptr));
  Byte* digitsPointer2 = number.GetDigitsPointer();
  while (--num >= 0) {
    *(digitsPointer2++) = *(ptr++);
  }
  *digitsPointer2 = 0;
}

Byte* Number::UInt32ToDecChars(Byte* bufferEnd, UInt32 value, Int32 digits) {
  while (--digits >= 0 || value != 0) {
    UInt32 result;
    value = Math::DivRem(value, 10u, result);
    *(--bufferEnd) = (Byte)(result + 48);
  }
  return bufferEnd;
}

Char* Number::UInt32ToDecChars(Char* bufferEnd, UInt32 value, Int32 digits) {
  while (--digits >= 0 || value != 0) {
    UInt32 result;
    value = Math::DivRem(value, 10u, result);
    *(--bufferEnd) = (Char)(result + 48);
  }
  return bufferEnd;
}

String Number::UInt32ToDecStr(UInt32 value) {
  Int32 num = FormattingHelpers::CountDigits(value);
  if (num == 1) {
    return s_singleDigitStringCache[value];
  }
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + num;
    do {
      UInt32 result;
      value = Math::DivRem(value, 10u, result);
      *(--ptr3) = (Char)(result + 48);
    } while (value != 0)
  }
  return text;
}

String Number::UInt32ToDecStr(UInt32 value, Int32 digits) {
  if (digits <= 1) {
    return UInt32ToDecStr(value);
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits(value));
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* bufferEnd = ptr2 + num;
    bufferEnd = UInt32ToDecChars(bufferEnd, value, digits);
  }
  return text;
}

Boolean Number::TryUInt32ToDecStr(UInt32 value, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits(value));
  if (num > destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* ptr2 = ptr + num;
    if (digits <= 1) {
      do {
        UInt32 result;
        value = Math::DivRem(value, 10u, result);
        *(--ptr2) = (Char)(result + 48);
      } while (value != 0)
    } else {
      ptr2 = UInt32ToDecChars(ptr2, value, digits);
    }
  }
  return true;
}

void Number::Int64ToNumber(Int64 input, NumberBuffer& number) {
  UInt64 value = (UInt64)input;
  number.IsNegative = (input < 0);
  number.DigitsCount = 19;
  if (number.IsNegative) {
    value = (UInt64)(-input);
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  Byte* bufferEnd = digitsPointer + 19;
  while (High32(value) != 0) {
    bufferEnd = UInt32ToDecChars(bufferEnd, Int64DivMod1E9(value), 9);
  }
  bufferEnd = UInt32ToDecChars(bufferEnd, Low32(value), 0);
  Int32 num = number.Scale = (number.DigitsCount = (Int32)(digitsPointer + 19 - bufferEnd));
  Byte* digitsPointer2 = number.GetDigitsPointer();
  while (--num >= 0) {
    *(digitsPointer2++) = *(bufferEnd++);
  }
  *digitsPointer2 = 0;
}

String Number::Int64ToDecStr(Int64 value) {
  if (value < 0) {
    return NegativeInt64ToDecStr(value, -1, NumberFormatInfo::in::get_CurrentInfo()->get_NegativeSign());
  }
  return UInt64ToDecStr((UInt64)value, -1);
}

String Number::NegativeInt64ToDecStr(Int64 input, Int32 digits, String sNegative) {
  if (digits < 1) {
    digits = 1;
  }
  UInt64 value = (UInt64)(-input);
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits(value)) + sNegative->get_Length();
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* bufferEnd = ptr2 + num;
    while (High32(value) != 0) {
      bufferEnd = UInt32ToDecChars(bufferEnd, Int64DivMod1E9(value), 9);
      digits -= 9;
    }
    bufferEnd = UInt32ToDecChars(bufferEnd, Low32(value), digits);
    for (Int32 num2 = sNegative->get_Length() - 1; num2 >= 0; num2--) {
      *(--bufferEnd) = sNegative[num2];
    }
  }
  return text;
}

Boolean Number::TryNegativeInt64ToDecStr(Int64 input, Int32 digits, String sNegative, Span<Char> destination, Int32& charsWritten) {
  if (digits < 1) {
    digits = 1;
  }
  UInt64 value = (UInt64)(-input);
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits((UInt64)(-input))) + sNegative->get_Length();
  if (num > destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* bufferEnd = ptr + num;
    while (High32(value) != 0) {
      bufferEnd = UInt32ToDecChars(bufferEnd, Int64DivMod1E9(value), 9);
      digits -= 9;
    }
    bufferEnd = UInt32ToDecChars(bufferEnd, Low32(value), digits);
    for (Int32 num2 = sNegative->get_Length() - 1; num2 >= 0; num2--) {
      *(--bufferEnd) = sNegative[num2];
    }
  }
  return true;
}

String Number::Int64ToHexStr(Int64 value, Char hexBase, Int32 digits) {
  Int32 num = Math::Max(digits, FormattingHelpers::CountHexDigits((UInt64)value));
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* buffer = ptr2 + num;
    if (High32((UInt64)value) != 0) {
      buffer = Int32ToHexChars(buffer, Low32((UInt64)value), hexBase, 8);
      buffer = Int32ToHexChars(buffer, High32((UInt64)value), hexBase, digits - 8);
    } else {
      buffer = Int32ToHexChars(buffer, Low32((UInt64)value), hexBase, Math::Max(digits, 1));
    }
  }
  return text;
}

Boolean Number::TryInt64ToHexStr(Int64 value, Char hexBase, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  Int32 num = Math::Max(digits, FormattingHelpers::CountHexDigits((UInt64)value));
  if (num > destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* buffer = ptr + num;
    if (High32((UInt64)value) != 0) {
      buffer = Int32ToHexChars(buffer, Low32((UInt64)value), hexBase, 8);
      buffer = Int32ToHexChars(buffer, High32((UInt64)value), hexBase, digits - 8);
    } else {
      buffer = Int32ToHexChars(buffer, Low32((UInt64)value), hexBase, Math::Max(digits, 1));
    }
  }
  return true;
}

void Number::UInt64ToNumber(UInt64 value, NumberBuffer& number) {
  number.DigitsCount = 20;
  number.IsNegative = false;
  Byte* digitsPointer = number.GetDigitsPointer();
  Byte* bufferEnd = digitsPointer + 20;
  while (High32(value) != 0) {
    bufferEnd = UInt32ToDecChars(bufferEnd, Int64DivMod1E9(value), 9);
  }
  bufferEnd = UInt32ToDecChars(bufferEnd, Low32(value), 0);
  Int32 num = number.Scale = (number.DigitsCount = (Int32)(digitsPointer + 20 - bufferEnd));
  Byte* digitsPointer2 = number.GetDigitsPointer();
  while (--num >= 0) {
    *(digitsPointer2++) = *(bufferEnd++);
  }
  *digitsPointer2 = 0;
}

String Number::UInt64ToDecStr(UInt64 value, Int32 digits) {
  if (digits < 1) {
    digits = 1;
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits(value));
  if (num == 1) {
    return s_singleDigitStringCache[value];
  }
  String text = String::in::FastAllocateString(num);
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* bufferEnd = ptr2 + num;
    while (High32(value) != 0) {
      bufferEnd = UInt32ToDecChars(bufferEnd, Int64DivMod1E9(value), 9);
      digits -= 9;
    }
    bufferEnd = UInt32ToDecChars(bufferEnd, Low32(value), digits);
  }
  return text;
}

Boolean Number::TryUInt64ToDecStr(UInt64 value, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  if (digits < 1) {
    digits = 1;
  }
  Int32 num = Math::Max(digits, FormattingHelpers::CountDigits(value));
  if (num > destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* bufferEnd = ptr + num;
    while (High32(value) != 0) {
      bufferEnd = UInt32ToDecChars(bufferEnd, Int64DivMod1E9(value), 9);
      digits -= 9;
    }
    bufferEnd = UInt32ToDecChars(bufferEnd, Low32(value), digits);
  }
  return true;
}

Char Number::ParseFormatSpecifier(ReadOnlySpan<Char> format, Int32& digits) {
  Char c = 0;
  if (format.get_Length() > 0) {
    c = format[0];
    if ((UInt32)(c - 65) <= 25u || (UInt32)(c - 97) <= 25u) {
      if (format.get_Length() == 1) {
        digits = -1;
        return c;
      }
      if (format.get_Length() == 2) {
        Int32 num = format[1] - 48;
        if ((UInt32)num < 10u) {
          digits = num;
          return c;
        }
      } else if (format.get_Length() == 3) {
        Int32 num2 = format[1] - 48;
        Int32 num3 = format[2] - 48;
        if ((UInt32)num2 < 10u && (UInt32)num3 < 10u) {
          digits = num2 * 10 + num3;
          return c;
        }
      }

      Int32 num4 = 0;
      Int32 num5 = 1;
      while (num5 < format.get_Length() && (UInt32)(format[num5] - 48) < 10u && num4 < 10) {
        num4 = num4 * 10 + format[num5++] - 48;
      }
      if (num5 == format.get_Length() || format[num5] == 0) {
        digits = num4;
        return c;
      }
    }
  }
  digits = -1;
  if (format.get_Length() != 0 && c != 0) {
    return 0;
  }
  return 71;
}

void Number::NumberToString(ValueStringBuilder& sb, NumberBuffer& number, Char format, Int32 nMaxDigits, NumberFormatInfo info) {
  Boolean isCorrectlyRounded = number.Kind == NumberBufferKind::FloatingPoint;
  Boolean bSuppressScientific;
  switch (format.get()) {
    case 67:
    case 99:
      if (nMaxDigits < 0) {
        nMaxDigits = info->set_CurrencyDecimalDigits();
      }
      RoundNumber(number, number.Scale + nMaxDigits, isCorrectlyRounded);
      FormatCurrency(sb, number, nMaxDigits, info);
      return;
    case 70:
    case 102:
      if (nMaxDigits < 0) {
        nMaxDigits = info->set_NumberDecimalDigits();
      }
      RoundNumber(number, number.Scale + nMaxDigits, isCorrectlyRounded);
      if (number.IsNegative) {
        sb.Append(info->get_NegativeSign());
      }
      FormatFixed(sb, number, nMaxDigits, nullptr, info->get_NumberDecimalSeparator(), nullptr);
      return;
    case 78:
    case 110:
      if (nMaxDigits < 0) {
        nMaxDigits = info->set_NumberDecimalDigits();
      }
      RoundNumber(number, number.Scale + nMaxDigits, isCorrectlyRounded);
      FormatNumber(sb, number, nMaxDigits, info);
      return;
    case 69:
    case 101:
      if (nMaxDigits < 0) {
        nMaxDigits = 6;
      }
      nMaxDigits++;
      RoundNumber(number, nMaxDigits, isCorrectlyRounded);
      if (number.IsNegative) {
        sb.Append(info->get_NegativeSign());
      }
      FormatScientific(sb, number, nMaxDigits, info, format);
      return;
    case 71:
    case 103:
      bSuppressScientific = false;
      if (nMaxDigits < 1) {
        if (number.Kind == NumberBufferKind::Decimal && nMaxDigits == -1) {
          bSuppressScientific = true;
          if (number.Digits[0] != 0) {
            goto IL_0189;
          }
          goto IL_019e;
        }
        nMaxDigits = number.DigitsCount;
      }
      RoundNumber(number, nMaxDigits, isCorrectlyRounded);
      goto IL_0189;
    case 80:
    case 112:
      if (nMaxDigits < 0) {
        nMaxDigits = info->set_PercentDecimalDigits();
      }
      number.Scale += 2;
      RoundNumber(number, number.Scale + nMaxDigits, isCorrectlyRounded);
      FormatPercent(sb, number, nMaxDigits, info);
      return;
    case 82:
    case 114:
      {
        if (number.Kind != NumberBufferKind::FloatingPoint) {
          break;
        }
        format = (Char)(format - 11);
      }
    IL_0189:
      if (number.IsNegative) {
        sb.Append(info->get_NegativeSign());
      }
      goto IL_019e;

    IL_019e:
      FormatGeneral(sb, number, nMaxDigits, info, (Char)(format - 2), bSuppressScientific);
      return;
  }
  rt::throw_exception<FormatException>(SR::get_Argument_BadFormatSpecifier());
}

void Number::NumberToStringFormat(ValueStringBuilder& sb, NumberBuffer& number, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  Int32 num = 0;
  Byte* digitsPointer = number.GetDigitsPointer();
  Int32 num2 = FindSection(format, (*digitsPointer == 0) ? 2 : (number.IsNegative ? 1 : 0));
  Int32 num3;
  Int32 num4;
  Boolean flag;
  Boolean flag2;
  Int32 num5;
  Int32 num6;
  Int32 num9;
  while (true) {
    num3 = 0;
    num4 = -1;
    num5 = Int32::MaxValue;
    num6 = 0;
    flag = false;
    Int32 num7 = -1;
    flag2 = false;
    Int32 num8 = 0;
    num9 = num2;
    {
      Char* ptr = &MemoryMarshal::GetReference(format);
      Char c;
      while (num9 < format.get_Length() && (c = ptr[num9++]) != 0) {
        switch (c.get()) {
          case 59:
            break;
          case 35:
            num3++;
            continue;
          case 48:
            if (num5 == Int32::MaxValue) {
              num5 = num3;
            }
            num3++;
            num6 = num3;
            continue;
          case 46:
            if (num4 < 0) {
              num4 = num3;
            }
            continue;
          case 44:
            if (num3 <= 0 || num4 >= 0) {
              continue;
            }
            if (num7 >= 0) {
              if (num7 == num3) {
                num++;
                continue;
              }
              flag2 = true;
            }
            num7 = num3;
            num = 1;
            continue;
          case 37:
            num8 += 2;
            continue;
          case 8240:
            num8 += 3;
            continue;
          case 34:
          case 39:
            while (num9 < format.get_Length() && ptr[num9] != 0 && ptr[num9++] != c) {
            }
            continue;
          case 92:
            if (num9 < format.get_Length() && ptr[num9] != 0) {
              num9++;
            }
            continue;
          case 69:
          case 101:
            if ((num9 < format.get_Length() && ptr[num9] == 48) || (num9 + 1 < format.get_Length() && (ptr[num9] == 43 || ptr[num9] == 45) && ptr[num9 + 1] == 48)) {
              while (++num9 < format.get_Length() && ptr[num9] == 48) {
              }
              flag = true;
            }
            continue;
          default:
            continue;
        }
        break;
      }
    }
    if (num4 < 0) {
      num4 = num3;
    }
    if (num7 >= 0) {
      if (num7 == num4) {
        num8 -= num * 3;
      } else {
        flag2 = true;
      }
    }
    if (*digitsPointer != 0) {
      number.Scale += num8;
      Int32 pos = flag ? num3 : (number.Scale + num3 - num4);
      RoundNumber(number, pos, false);
      if (*digitsPointer != 0) {
        break;
      }
      num9 = FindSection(format, 2);
      if (num9 == num2) {
        break;
      }
      num2 = num9;
      continue;
    }
    if (number.Kind != NumberBufferKind::FloatingPoint) {
      number.IsNegative = false;
    }
    number.Scale = 0;
    break;
  }
  num5 = ((num5 < num4) ? (num4 - num5) : 0);
  num6 = ((num6 > num4) ? (num4 - num6) : 0);
  Int32 num10;
  Int32 num11;
  if (flag) {
    num10 = num4;
    num11 = 0;
  } else {
    num10 = ((number.Scale > num4) ? number.Scale : num4);
    num11 = number.Scale - num4;
  }
  num9 = num2;
  Int32 as[4] = {};
  Span<Int32> span = as;
  Int32 num12 = -1;
  if (flag2 && info->get_NumberGroupSeparator()->get_Length() > 0) {
    Array<Int32> numberGroupSizes = info->_numberGroupSizes;
    Int32 num13 = 0;
    Int32 i = 0;
    Int32 num14 = numberGroupSizes->get_Length();
    if (num14 != 0) {
      i = numberGroupSizes[num13];
    }
    Int32 num15 = i;
    Int32 num16 = num10 + ((num11 < 0) ? num11 : 0);
    for (Int32 num17 = (num5 > num16) ? num5 : num16; num17 > i; i += num15) {
      if (num15 == 0) {
        break;
      }
      num12++;
      if (num12 >= span.get_Length()) {
        Array<Int32> array = rt::newarr<Array<Int32>>(span.get_Length() * 2);
        span.CopyTo(array);
        span = array;
      }
      span[num12] = i;
      if (num13 < num14 - 1) {
        num13++;
        num15 = numberGroupSizes[num13];
      }
    }
  }
  if (number.IsNegative && num2 == 0 && number.Scale != 0) {
    sb.Append(info->get_NegativeSign());
  }
  Boolean flag3 = false;
  {
    Char* ptr3 = &MemoryMarshal::GetReference(format);
    Byte* ptr2 = digitsPointer;
    Char c;
    while (num9 < format.get_Length() && (c = ptr3[num9++]) != 0 && c != 59) {
      if (num11 > 0 && (c == 35 || c == 46 || c == 48)) {
        while (num11 > 0) {
          sb.Append((Char)((*ptr2 != 0) ? (*(ptr2++)) : 48));
          if (flag2 && num10 > 1 && num12 >= 0 && num10 == span[num12] + 1) {
            sb.Append(info->get_NumberGroupSeparator());
            num12--;
          }
          num10--;
          num11--;
        }
      }
      switch (c.get()) {
        case 35:
        case 48:
          if (num11 < 0) {
            num11++;
            c = ((num10 <= num5) ? 48 : 0);
          } else {
            c = (Char)((*ptr2 != 0) ? ((Int32)(*(ptr2++))) : ((Int32)((num10 > num6) ? 48 : 0)));
          }
          if (c != 0) {
            sb.Append(c);
            if (flag2 && num10 > 1 && num12 >= 0 && num10 == span[num12] + 1) {
              sb.Append(info->get_NumberGroupSeparator());
              num12--;
            }
          }
          num10--;
          break;
        case 46:
          if (!(num10 != 0 || flag3) && (num6 < 0 || (num4 < num3 && *ptr2 != 0))) {
            sb.Append(info->get_NumberDecimalSeparator());
            flag3 = true;
          }
          break;
        case 8240:
          sb.Append(info->get_PerMilleSymbol());
          break;
        case 37:
          sb.Append(info->get_PercentSymbol());
          break;
        case 34:
        case 39:
          while (num9 < format.get_Length() && ptr3[num9] != 0 && ptr3[num9] != c) {
            sb.Append(ptr3[num9++]);
          }
          if (num9 < format.get_Length() && ptr3[num9] != 0) {
            num9++;
          }
          break;
        case 92:
          if (num9 < format.get_Length() && ptr3[num9] != 0) {
            sb.Append(ptr3[num9++]);
          }
          break;
        case 69:
        case 101:
          {
            Boolean positiveSign = false;
            Int32 num18 = 0;
            if (flag) {
              if (num9 < format.get_Length() && ptr3[num9] == 48) {
                num18++;
              } else if (num9 + 1 < format.get_Length() && ptr3[num9] == 43 && ptr3[num9 + 1] == 48) {
                positiveSign = true;
              } else if (num9 + 1 >= format.get_Length() || ptr3[num9] != 45 || ptr3[num9 + 1] != 48) {
                sb.Append(c);
                break;
              }


              while (++num9 < format.get_Length() && ptr3[num9] == 48) {
                num18++;
              }
              if (num18 > 10) {
                num18 = 10;
              }
              Int32 value = (*digitsPointer != 0) ? (number.Scale - num4) : 0;
              FormatExponent(sb, info, value, c, num18, positiveSign);
              flag = false;
              break;
            }
            sb.Append(c);
            if (num9 < format.get_Length()) {
              if (ptr3[num9] == 43 || ptr3[num9] == 45) {
                sb.Append(ptr3[num9++]);
              }
              while (num9 < format.get_Length() && ptr3[num9] == 48) {
                sb.Append(ptr3[num9++]);
              }
            }
            break;
          }default:
          sb.Append(c);
          break;
        case 44:
          break;
      }
    }
  }
  if (number.IsNegative && num2 == 0 && number.Scale == 0 && sb.get_Length() > 0) {
    sb.Insert(0, info->get_NegativeSign());
  }
}

void Number::FormatCurrency(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info) {
  String text = number.IsNegative ? s_negCurrencyFormats[info->get_CurrencyNegativePattern()] : s_posCurrencyFormats[info->get_CurrencyPositivePattern()];
  String text2 = text;
}

void Number::FormatFixed(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, Array<Int32> groupDigits, String sDecimal, String sGroup) {
  Int32 num = number.Scale;
  Byte* ptr = number.GetDigitsPointer();
  if (num > 0) {
    if (groupDigits != nullptr) {
      Int32 num2 = 0;
      Int32 num3 = num;
      Int32 num4 = 0;
      if (groupDigits->get_Length() != 0) {
        Int32 num5 = groupDigits[num2];
        while (num > num5 && groupDigits[num2] != 0) {
          num3 += sGroup->get_Length();
          if (num2 < groupDigits->get_Length() - 1) {
            num2++;
          }
          num5 += groupDigits[num2];
          if (num5 < 0 || num3 < 0) {
            rt::throw_exception<ArgumentOutOfRangeException>();
          }
        }
        num4 = ((num5 != 0) ? groupDigits[0] : 0);
      }
      num2 = 0;
      Int32 num6 = 0;
      Int32 digitsCount = number.DigitsCount;
      Int32 num7 = (num < digitsCount) ? num : digitsCount;
      {
        Char* ptr2 = &MemoryMarshal::GetReference(sb.AppendSpan(num3));
        Char* ptr3 = ptr2 + num3 - 1;
        for (Int32 num8 = num - 1; num8 >= 0; num8--) {
          Char* num9 = ptr3;
          ptr3 = num9 - 1;
          *num9 = (Char)((num8 < num7) ? ptr[num8] : 48);
          if (num4 > 0) {
            num6++;
            if (num6 == num4 && num8 != 0) {
              for (Int32 num10 = sGroup->get_Length() - 1; num10 >= 0; num10--) {
                Char* num11 = ptr3;
                ptr3 = num11 - 1;
                *num11 = sGroup[num10];
              }
              if (num2 < groupDigits->get_Length() - 1) {
                num2++;
                num4 = groupDigits[num2];
              }
              num6 = 0;
            }
          }
        }
        ptr += num7;
      }
    } else {
      do {
        sb.Append((Char)((*ptr != 0) ? (*(ptr++)) : 48));
      } while (--num > 0)
    }
  } else {
    sb.Append(48);
  }
  if (nMaxDigits > 0) {
    sb.Append(sDecimal);
    if (num < 0 && nMaxDigits > 0) {
      Int32 num12 = Math::Min(-num, nMaxDigits);
      sb.Append(48, num12);
      num += num12;
      nMaxDigits -= num12;
    }
    while (nMaxDigits > 0) {
      sb.Append((Char)((*ptr != 0) ? (*(ptr++)) : 48));
      nMaxDigits--;
    }
  }
}

void Number::FormatNumber(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info) {
  String text = number.IsNegative ? s_negNumberFormats[info->get_NumberNegativePattern()] : "#";
  String text2 = text;
}

void Number::FormatScientific(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info, Char expChar) {
  Byte* digitsPointer = number.GetDigitsPointer();
  sb.Append((Char)((*digitsPointer != 0) ? (*(digitsPointer++)) : 48));
  if (nMaxDigits != 1) {
    sb.Append(info->get_NumberDecimalSeparator());
  }
  while (--nMaxDigits > 0) {
    sb.Append((Char)((*digitsPointer != 0) ? (*(digitsPointer++)) : 48));
  }
  Int32 value = (number.Digits[0] != 0) ? (number.Scale - 1) : 0;
  FormatExponent(sb, info, value, expChar, 3, true);
}

void Number::FormatExponent(ValueStringBuilder& sb, NumberFormatInfo info, Int32 value, Char expChar, Int32 minDigits, Boolean positiveSign) {
  sb.Append(expChar);
  if (value < 0) {
    sb.Append(info->get_NegativeSign());
    value = -value;
  } else if (positiveSign) {
    sb.Append(info->get_PositiveSign());
  }

  Char as[10] = {};
  Char* ptr = as;
  Char* ptr2 = UInt32ToDecChars(ptr + 10, (UInt32)value, minDigits);
  sb.Append(ptr2, (Int32)(ptr + 10 - ptr2));
}

void Number::FormatGeneral(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info, Char expChar, Boolean bSuppressScientific) {
  Int32 i = number.Scale;
  Boolean flag = false;
  if (!bSuppressScientific && (i > nMaxDigits || i < -3)) {
    i = 1;
    flag = true;
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  if (i > 0) {
    do {
      sb.Append((Char)((*digitsPointer != 0) ? (*(digitsPointer++)) : 48));
    } while (--i > 0)
  } else {
    sb.Append(48);
  }
  if (*digitsPointer != 0 || i < 0) {
    sb.Append(info->get_NumberDecimalSeparator());
    for (; i < 0; i++) {
      sb.Append(48);
    }
    while (*digitsPointer != 0) {
      sb.Append((Char)(*(digitsPointer++)));
    }
  }
  if (flag) {
    FormatExponent(sb, info, number.Scale - 1, expChar, 2, true);
  }
}

void Number::FormatPercent(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info) {
  String text = number.IsNegative ? s_negPercentFormats[info->get_PercentNegativePattern()] : s_posPercentFormats[info->get_PercentPositivePattern()];
  String text2 = text;
}

void Number::RoundNumber(NumberBuffer& number, Int32 pos, Boolean isCorrectlyRounded) {
  auto ShouldRoundUp = [](Byte* dig, Int32 i, NumberBufferKind numberKind, Boolean isCorrectlyRounded) -> Boolean {
    Byte b = dig[i];
    if (b == 0 || isCorrectlyRounded) {
      return false;
    }
    return b >= 53;
  };
  Byte* digitsPointer = number.GetDigitsPointer();
  Int32 j;
  for (j = 0; j < pos && digitsPointer[j] != 0; j++) {
  }
  if (j == pos && ShouldRoundUp(digitsPointer, j, number.Kind, isCorrectlyRounded)) {
    while (j > 0 && digitsPointer[j - 1] == 57) {
      j--;
    }
    if (j > 0) {
      Byte* num = digitsPointer + (j - 1);
      *num = (Byte)(*num + 1);
    } else {
      number.Scale++;
      *digitsPointer = 49;
      j = 1;
    }
  } else {
    while (j > 0 && digitsPointer[j - 1] == 48) {
      j--;
    }
  }
  if (j == 0) {
    if (number.Kind != NumberBufferKind::FloatingPoint) {
      number.IsNegative = false;
    }
    number.Scale = 0;
  }
  digitsPointer[j] = 0;
  number.DigitsCount = j;
}

Int32 Number::FindSection(ReadOnlySpan<Char> format, Int32 section) {
  if (section == 0) {
    return 0;
  }
  {
    Char* ptr = &MemoryMarshal::GetReference(format);
    Int32 num = 0;
    while (true) {
      if (num >= format.get_Length()) {
        return 0;
      }
      Char c;
      Char c2 = c = ptr[num++];
      if ((UInt32)c2 <= 34u) {
        if (c2 == 0) {
          break;
        }
        if (c2 != 34) {
          continue;
        }
      } else if (c2 != 39) {
        switch (c2.get()) {
          default:
            continue;
          case 92:
            if (num < format.get_Length() && ptr[num] != 0) {
              num++;
            }
            continue;
          case 59:
            break;
        }
        if (--section == 0) {
          if (num >= format.get_Length() || ptr[num] == 0 || ptr[num] == 59) {
            break;
          }
          return num;
        }
        continue;
      }

      while (num < format.get_Length() && ptr[num] != 0 && ptr[num++] != c) {
      }
    }
    return 0;
  }
}

UInt32 Number::Low32(UInt64 value) {
  return (UInt32)value;
}

UInt32 Number::High32(UInt64 value) {
  return (UInt32)((UInt64)((Int64)value & -4294967296) >> 32);
}

UInt32 Number::Int64DivMod1E9(UInt64& value) {
  UInt32 result = (UInt32)(value % 1000000000);
  value /= 1000000000;
  return result;
}

UInt64 Number::ExtractFractionAndBiasedExponent(Double value, Int32& exponent) {
  UInt64 num = (UInt64)BitConverter::DoubleToInt64Bits(value);
  UInt64 num2 = num & 4503599627370495;
  exponent = ((Int32)(num >> 52) & 2047);
  if (exponent != 0) {
    num2 |= 4503599627370496;
    exponent -= 1075;
  } else {
    exponent = -1074;
  }
  return num2;
}

UInt32 Number::ExtractFractionAndBiasedExponent(Single value, Int32& exponent) {
  UInt32 num = (UInt32)BitConverter::SingleToInt32Bits(value);
  UInt32 num2 = num & 8388607;
  exponent = (Int32)((num >> 23) & 255);
  if (exponent != 0) {
    num2 |= 8388608;
    exponent -= 150;
  } else {
    exponent = -149;
  }
  return num2;
}

void Number::AccumulateDecimalDigitsIntoBigInteger(NumberBuffer& number, UInt32 firstIndex, UInt32 lastIndex, BigInteger& result) {
  BigInteger::SetZero(result);
  Byte* ptr = number.GetDigitsPointer() + firstIndex;
  UInt32 num = lastIndex - firstIndex;
  while (num != 0) {
    UInt32 num2 = Math::Min(num, 9u);
    UInt32 value = DigitsToUInt32(ptr, (Int32)num2);
    result.MultiplyPow10(num2);
    result.Add(value);
    ptr += num2;
    num -= num2;
  }
}

UInt64 Number::AssembleFloatingPointBits(FloatingPointInfo& info, UInt64 initialMantissa, Int32 initialExponent, Boolean hasZeroTail) {
  UInt32 num = BigInteger::CountSignificantBits(initialMantissa);
  Int32 num2 = (Int32)(info.get_NormalMantissaBits() - num);
  Int32 num3 = initialExponent - num2;
  UInt64 num4 = initialMantissa;
  Int32 num5 = num3;
  if (num3 > info.get_MaxBinaryExponent()) {
    return info.get_InfinityBits();
  }
  if (num3 < info.get_MinBinaryExponent()) {
    Int32 num6 = num2 + num3 + info.get_ExponentBias() - 1;
    num5 = -info.get_ExponentBias();
    if (num6 < 0) {
      num4 = RightShiftWithRounding(num4, -num6, hasZeroTail);
      if (num4 == 0) {
        return info.get_ZeroBits();
      }
      if (num4 > info.get_DenormalMantissaMask()) {
        num5 = initialExponent - (num6 + 1) - num2;
      }
    } else {
      num4 <<= num6;
    }
  } else if (num2 < 0) {
    num4 = RightShiftWithRounding(num4, -num2, hasZeroTail);
    if (num4 > info.get_NormalMantissaMask()) {
      num4 >>= 1;
      num5++;
      if (num5 > info.get_MaxBinaryExponent()) {
        return info.get_InfinityBits();
      }
    }
  } else if (num2 > 0) {
    num4 <<= num2;
  }


  num4 &= info.get_DenormalMantissaMask();
  UInt64 num7 = (UInt64)((Int64)(num5 + info.get_ExponentBias()) << (Int32)info.get_DenormalMantissaBits());
  return num7 | num4;
}

UInt64 Number::ConvertBigIntegerToFloatingPointBits(BigInteger& value, FloatingPointInfo& info, UInt32 integerBitsOfPrecision, Boolean hasNonZeroFractionalPart) {
  Int32 denormalMantissaBits = info.get_DenormalMantissaBits();
  if (integerBitsOfPrecision <= 64) {
    return AssembleFloatingPointBits(info, value.ToUInt64(), denormalMantissaBits, !hasNonZeroFractionalPart);
  }
  UInt32 result;
  UInt32 num = Math::DivRem(integerBitsOfPrecision, 32u, result);
  UInt32 num2 = num - 1;
  UInt32 num3 = num2 - 1;
  Int32 num4 = denormalMantissaBits + (Int32)(num3 * 32);
  Boolean flag = !hasNonZeroFractionalPart;
  UInt64 initialMantissa;
  if (result == 0) {
    initialMantissa = ((UInt64)value.GetBlock(num2) << 32) + value.GetBlock(num3);
  } else {
    Int32 num5 = (Int32)result;
    Int32 num6 = 64 - num5;
    Int32 num7 = num6 - 32;
    num4 += (Int32)result;
    UInt32 block = value.GetBlock(num3);
    UInt32 num8 = block >> num5;
    UInt64 num9 = (UInt64)value.GetBlock(num2) << num7;
    UInt64 num10 = (UInt64)value.GetBlock(num) << num6;
    initialMantissa = num10 + num9 + num8;
    UInt32 num11 = (UInt32)((1 << (Int32)result) - 1);
    flag = (flag && (block & num11) == 0);
  }
  for (UInt32 num12 = 0u; num12 != num3; num12++) {
    flag &= (value.GetBlock(num12) == 0);
  }
  return AssembleFloatingPointBits(info, initialMantissa, num4, flag);
}

UInt32 Number::DigitsToUInt32(Byte* p, Int32 count) {
  Byte* ptr = p + count;
  UInt32 num = (UInt32)(*p - 48);
  for (p++; p < ptr; p++) {
    num = 10 * num + *p - 48;
  }
  return num;
}

UInt64 Number::DigitsToUInt64(Byte* p, Int32 count) {
  Byte* ptr = p + count;
  UInt64 num = (UInt64)(*p - 48);
  for (p++; p < ptr; p++) {
    num = 10 * num + *p - 48;
  }
  return num;
}

UInt64 Number::NumberToFloatingPointBits(NumberBuffer& number, FloatingPointInfo& info) {
  UInt32 digitsCount = (UInt32)number.DigitsCount;
  UInt32 num = (UInt32)Math::Max(0, number.Scale);
  UInt32 num2 = Math::Min(num, digitsCount);
  UInt32 num3 = digitsCount - num2;
  UInt32 num4 = (UInt32)Math::Abs(number.Scale - num2 - num3);
  Byte* digitsPointer = number.GetDigitsPointer();
  if (info.get_DenormalMantissaBits() == 23 && digitsCount <= 7 && num4 <= 10) {
    Single num5 = DigitsToUInt32(digitsPointer, (Int32)digitsCount);
    Single num6 = s_Pow10SingleTable[num4];
    num5 = ((num3 == 0) ? (num5 * num6) : (num5 / num6));
    return (UInt32)BitConverter::SingleToInt32Bits(num5);
  }
  if (digitsCount <= 15 && num4 <= 22) {
    Double num7 = DigitsToUInt64(digitsPointer, (Int32)digitsCount);
    Double num8 = s_Pow10DoubleTable[num4];
    num7 = ((num3 == 0) ? (num7 * num8) : (num7 / num8));
    if (info.get_DenormalMantissaBits() == 52) {
      return (UInt64)BitConverter::DoubleToInt64Bits(num7);
    }
    return (UInt32)BitConverter::SingleToInt32Bits((Single)num7);
  }
  return NumberToFloatingPointBitsSlow(number, info, num, num2, num3);
}

UInt64 Number::NumberToFloatingPointBitsSlow(NumberBuffer& number, FloatingPointInfo& info, UInt32 positiveExponent, UInt32 integerDigitsPresent, UInt32 fractionalDigitsPresent) {
  UInt32 num = (UInt32)(info.get_NormalMantissaBits() + 1);
  UInt32 digitsCount = (UInt32)number.DigitsCount;
  UInt32 num2 = positiveExponent - integerDigitsPresent;
  UInt32 lastIndex = digitsCount;
  BigInteger result;
  AccumulateDecimalDigitsIntoBigInteger(number, 0u, integerDigitsPresent, result);
  if (num2 != 0) {
    if (num2 > info.get_OverflowDecimalExponent()) {
      return info.get_InfinityBits();
    }
    result.MultiplyPow10(num2);
  }
  UInt32 num3 = BigInteger::CountSignificantBits(result);
  if (num3 >= num || fractionalDigitsPresent == 0) {
    return ConvertBigIntegerToFloatingPointBits(result, info, num3, fractionalDigitsPresent != 0);
  }
  UInt32 num4 = fractionalDigitsPresent;
  if (number.Scale < 0) {
    num4 += (UInt32)(-number.Scale);
  }
  if (num3 == 0 && num4 - (Int32)digitsCount > info.get_OverflowDecimalExponent()) {
    return info.get_ZeroBits();
  }
  BigInteger result2;
  AccumulateDecimalDigitsIntoBigInteger(number, integerDigitsPresent, lastIndex, result2);
  if (result2.IsZero()) {
    return ConvertBigIntegerToFloatingPointBits(result, info, num3, fractionalDigitsPresent != 0);
  }
  BigInteger result3;
  BigInteger::Pow10(num4, result3);
  UInt32 num5 = BigInteger::CountSignificantBits(result2);
  UInt32 num6 = BigInteger::CountSignificantBits(result3);
  UInt32 num7 = 0u;
  if (num6 > num5) {
    num7 = num6 - num5;
  }
  if (num7 != 0) {
    result2.ShiftLeft(num7);
  }
  UInt32 num8 = num - num3;
  UInt32 num9 = num8;
  if (num3 != 0) {
    if (num7 > num9) {
      return ConvertBigIntegerToFloatingPointBits(result, info, num3, fractionalDigitsPresent != 0);
    }
    num9 -= num7;
  }
  UInt32 num10 = num7;
  if (BigInteger::Compare(result2, result3) < 0) {
    num10++;
  }
  result2.ShiftLeft(num9);
  BigInteger quo;
  BigInteger rem;
  BigInteger::DivRem(result2, result3, quo, rem);
  UInt64 num11 = quo.ToUInt64();
  Boolean flag = !number.HasNonZeroTail && rem.IsZero();
  UInt32 num12 = BigInteger::CountSignificantBits(num11);
  if (num12 > num8) {
    Int32 num13 = (Int32)(num12 - num8);
    flag = (flag && ((Int64)num11 & ((1 << num13) - 1)) == 0);
    num11 >>= num13;
  }
  UInt64 num14 = result.ToUInt64();
  UInt64 initialMantissa = (num14 << (Int32)num8) + num11;
  Int32 initialExponent = (Int32)((num3 != 0) ? (num3 - 2) : (0 - num10 - 1));
  return AssembleFloatingPointBits(info, initialMantissa, initialExponent, flag);
}

UInt64 Number::RightShiftWithRounding(UInt64 value, Int32 shift, Boolean hasZeroTail) {
  if (shift >= 64) {
    return 0;
  }
  UInt64 num = (UInt64)((1 << shift - 1) - 1);
  UInt64 num2 = (UInt64)(1 << shift - 1);
  UInt64 num3 = (UInt64)(1 << shift);
  Boolean lsbBit = (value & num3) != 0;
  Boolean roundBit = (value & num2) != 0;
  Boolean hasTailBits = !hasZeroTail || (value & num) != 0;
  return (value >> shift) + (UInt64)(ShouldRoundUp(lsbBit, roundBit, hasTailBits) ? 1 : 0);
}

Boolean Number::ShouldRoundUp(Boolean lsbBit, Boolean roundBit, Boolean hasTailBits) {
  if (roundBit) {
    return hasTailBits || lsbBit;
  }
  return false;
}

Boolean Number::TryNumberToInt32(NumberBuffer& number, Int32& value) {
  Int32 num = number.Scale;
  if (num > 10 || num < number.DigitsCount) {
    return false;
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  Int32 num2 = 0;
  while (--num >= 0) {
    if ((UInt32)num2 > 214748364u) {
      return false;
    }
    num2 *= 10;
    if (*digitsPointer != 0) {
      num2 += *(digitsPointer++) - 48;
    }
  }
  if (number.IsNegative) {
    num2 = -num2;
    if (num2 > 0) {
      return false;
    }
  } else if (num2 < 0) {
    return false;
  }

  value = num2;
  return true;
}

Boolean Number::TryNumberToInt64(NumberBuffer& number, Int64& value) {
  Int32 num = number.Scale;
  if (num > 19 || num < number.DigitsCount) {
    return false;
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  Int64 num2 = 0;
  while (--num >= 0) {
    if ((UInt64)num2 > 922337203685477580) {
      return false;
    }
    num2 *= 10;
    if (*digitsPointer != 0) {
      num2 += *(digitsPointer++) - 48;
    }
  }
  if (number.IsNegative) {
    num2 = -num2;
    if (num2 > 0) {
      return false;
    }
  } else if (num2 < 0) {
    return false;
  }

  value = num2;
  return true;
}

Boolean Number::TryNumberToUInt32(NumberBuffer& number, UInt32& value) {
  Int32 num = number.Scale;
  if (num > 10 || num < number.DigitsCount || number.IsNegative) {
    return false;
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  UInt32 num2 = 0u;
  while (--num >= 0) {
    if (num2 > 429496729) {
      return false;
    }
    num2 *= 10;
    if (*digitsPointer != 0) {
      UInt32 num3 = num2 + (UInt32)(*(digitsPointer++) - 48);
      if (num3 < num2) {
        return false;
      }
      num2 = num3;
    }
  }
  value = num2;
  return true;
}

Boolean Number::TryNumberToUInt64(NumberBuffer& number, UInt64& value) {
  Int32 num = number.Scale;
  if (num > 20 || num < number.DigitsCount || number.IsNegative) {
    return false;
  }
  Byte* digitsPointer = number.GetDigitsPointer();
  UInt64 num2 = 0;
  while (--num >= 0) {
    if (num2 > 1844674407370955161) {
      return false;
    }
    num2 *= 10;
    if (*digitsPointer != 0) {
      UInt64 num3 = num2 + (UInt64)(*(digitsPointer++) - 48);
      if (num3 < num2) {
        return false;
      }
      num2 = num3;
    }
  }
  value = num2;
  return true;
}

Int32 Number::ParseInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  Int32 result;
  ParsingStatus parsingStatus = TryParseInt32(value, styles, info, result);
  if (parsingStatus != 0) {
    ThrowOverflowOrFormatException(parsingStatus, TypeCode::Int32);
  }
  return result;
}

Int64 Number::ParseInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  Int64 result;
  ParsingStatus parsingStatus = TryParseInt64(value, styles, info, result);
  if (parsingStatus != 0) {
    ThrowOverflowOrFormatException(parsingStatus, TypeCode::Int64);
  }
  return result;
}

UInt32 Number::ParseUInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  UInt32 result;
  ParsingStatus parsingStatus = TryParseUInt32(value, styles, info, result);
  if (parsingStatus != 0) {
    ThrowOverflowOrFormatException(parsingStatus, TypeCode::UInt32);
  }
  return result;
}

UInt64 Number::ParseUInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  UInt64 result;
  ParsingStatus parsingStatus = TryParseUInt64(value, styles, info, result);
  if (parsingStatus != 0) {
    ThrowOverflowOrFormatException(parsingStatus, TypeCode::UInt64);
  }
  return result;
}

Boolean Number::TryParseNumber(Char*& str, Char* strEnd, NumberStyles styles, NumberBuffer& number, NumberFormatInfo info) {
  String text = nullptr;
  Boolean flag = false;
  String value;
  String value2;
  if ((styles & NumberStyles::AllowCurrencySymbol) != 0) {
    text = info->set_CurrencySymbol();
    value = info->set_CurrencyDecimalSeparator();
    value2 = info->set_CurrencyGroupSeparator();
    flag = true;
  } else {
    value = info->set_NumberDecimalSeparator();
    value2 = info->set_NumberGroupSeparator();
  }
  Int32 num = 0;
  Char* ptr = str;
  Char c = (ptr < strEnd) ? (*ptr) : 0;
  while (true) {
    if (!IsWhite(c) || (styles & NumberStyles::AllowLeadingWhite) == 0 || ((num & 1) != 0 && (num & 32) == 0 && info->get_NumberNegativePattern() != 2)) {
      Char* ptr2;
      if ((styles & NumberStyles::AllowLeadingSign) != 0 && (num & 1) == 0 && ((ptr2 = MatchChars(ptr, strEnd, info->get_PositiveSign())) != nullptr || ((ptr2 = MatchChars(ptr, strEnd, info->get_NegativeSign())) != nullptr && (number.IsNegative = true)))) {
        num |= 1;
        ptr = ptr2 - 1;
      } else if (c == 40 && (styles & NumberStyles::AllowParentheses) != 0 && (num & 1) == 0) {
        num |= 3;
        number.IsNegative = true;
      } else {
        if (text == nullptr || (ptr2 = MatchChars(ptr, strEnd, text)) == nullptr) {
          break;
        }
        num |= 32;
        text = nullptr;
        ptr = ptr2 - 1;
      }

    }
    c = ((++ptr < strEnd) ? (*ptr) : 0);
  }
  Int32 num2 = 0;
  Int32 num3 = 0;
  Int32 num4 = number.Digits.get_Length() - 1;
  while (true) {
    Char* ptr2;
    if (IsDigit(c)) {
      num |= 4;
      if (c != 48 || (num & 8) != 0) {
        if (num2 < num4) {
          number.Digits[num2++] = (Byte)c;
          if (c != 48 || number.Kind != NumberBufferKind::Integer) {
            num3 = num2;
          }
        } else if (c != 48) {
          number.HasNonZeroTail = true;
        }

        if ((num & 16) == 0) {
          number.Scale++;
        }
        num |= 8;
      } else if ((num & 16) != 0) {
        number.Scale--;
      }

    } else if ((styles & NumberStyles::AllowDecimalPoint) != 0 && (num & 16) == 0 && ((ptr2 = MatchChars(ptr, strEnd, value)) != nullptr || (flag && (num & 32) == 0 && (ptr2 = MatchChars(ptr, strEnd, info->get_NumberDecimalSeparator())) != nullptr))) {
      num |= 16;
      ptr = ptr2 - 1;
    } else {
      if ((styles & NumberStyles::AllowThousands) == 0 || (num & 4) == 0 || (num & 16) != 0 || ((ptr2 = MatchChars(ptr, strEnd, value2)) == nullptr && (!flag || (num & 32) != 0 || (ptr2 = MatchChars(ptr, strEnd, info->get_NumberGroupSeparator())) == nullptr))) {
        break;
      }
      ptr = ptr2 - 1;
    }

    c = ((++ptr < strEnd) ? (*ptr) : 0);
  }
  Boolean flag2 = false;
  number.DigitsCount = num3;
  number.Digits[num3] = 0;
  if ((num & 4) != 0) {
    if ((c == 69 || c == 101) && (styles & NumberStyles::AllowExponent) != 0) {
      Char* ptr3 = ptr;
      c = ((++ptr < strEnd) ? (*ptr) : 0);
      Char* ptr2;
      if ((ptr2 = MatchChars(ptr, strEnd, info->_positiveSign)) != nullptr) {
        c = (((ptr = ptr2) < strEnd) ? (*ptr) : 0);
      } else if ((ptr2 = MatchChars(ptr, strEnd, info->_negativeSign)) != nullptr) {
        c = (((ptr = ptr2) < strEnd) ? (*ptr) : 0);
        flag2 = true;
      }

      if (IsDigit(c)) {
        Int32 num5 = 0;
        do {
          num5 = num5 * 10 + (c - 48);
          c = ((++ptr < strEnd) ? (*ptr) : 0);
          if (num5 > 1000) {
            num5 = 9999;
            while (IsDigit(c)) {
              c = ((++ptr < strEnd) ? (*ptr) : 0);
            }
          }
        } while (IsDigit(c))
        if (flag2) {
          num5 = -num5;
        }
        number.Scale += num5;
      } else {
        ptr = ptr3;
        c = ((ptr < strEnd) ? (*ptr) : 0);
      }
    }
    while (true) {
      if (!IsWhite(c) || (styles & NumberStyles::AllowTrailingWhite) == 0) {
        Char* ptr2;
        if ((styles & NumberStyles::AllowTrailingSign) != 0 && (num & 1) == 0 && ((ptr2 = MatchChars(ptr, strEnd, info->get_PositiveSign())) != nullptr || ((ptr2 = MatchChars(ptr, strEnd, info->get_NegativeSign())) != nullptr && (number.IsNegative = true)))) {
          num |= 1;
          ptr = ptr2 - 1;
        } else if (c == 41 && (num & 2) != 0) {
          num &= -3;
        } else {
          if (text == nullptr || (ptr2 = MatchChars(ptr, strEnd, text)) == nullptr) {
            break;
          }
          text = nullptr;
          ptr = ptr2 - 1;
        }

      }
      c = ((++ptr < strEnd) ? (*ptr) : 0);
    }
    if ((num & 2) == 0) {
      if ((num & 8) == 0) {
        if (number.Kind != NumberBufferKind::Decimal) {
          number.Scale = 0;
        }
        if (number.Kind == NumberBufferKind::Integer && (num & 16) == 0) {
          number.IsNegative = false;
        }
      }
      str = ptr;
      return true;
    }
  }
  str = ptr;
  return false;
}

Number::ParsingStatus Number::TryParseInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result) {
  if ((styles & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign)) == 0) {
    return TryParseInt32IntegerStyle(value, styles, info, result);
  }
  if ((styles & NumberStyles::AllowHexSpecifier) != 0) {
    result = 0;
    return TryParseUInt32HexNumberStyle(value, styles, Unsafe::As<Int32, UInt32>(result));
  }
  return TryParseInt32Number(value, styles, info, result);
}

Number::ParsingStatus Number::TryParseInt32Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result) {
  result = 0;
  Byte as[11] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits, 11);
  if (!TryStringToNumber(value, styles, number, info)) {
    return ParsingStatus::Failed;
  }
  if (!TryNumberToInt32(number, result)) {
    return ParsingStatus::Overflow;
  }
  return ParsingStatus::OK;
}

Number::ParsingStatus Number::TryParseInt32IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result) {
  Int32 i;
  Int32 num;
  if (!value.get_IsEmpty()) {
    i = 0;
    num = value[0];
    if ((styles & NumberStyles::AllowLeadingWhite) == 0 || !IsWhite(num)) {
      goto IL_0048;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (IsWhite(num)) {
        continue;
      }
      goto IL_0048;
    }
  }
  goto IL_025a;

IL_0170:
  if (IsDigit(num)) {
    goto IL_017b;
  }
  goto IL_026a;

IL_0262:
  result = 0;
  return ParsingStatus::Overflow;

IL_017b:
  Int32 num2 = num - 48;
  i++;
  Int32 num3 = 0;
  while (num3 < 8) {
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_024e;
    }
    num = value[i];
    if (IsDigit(num)) {
      i++;
      num2 = 10 * num2 + num - 48;
      num3++;
      continue;
    }
    goto IL_026a;
  }
  if ((UInt32)i >= (UInt32)value.get_Length()) {
    goto IL_024e;
  }
  num = value[i];
  Boolean flag;
  Int32 num4;
  if (IsDigit(num)) {
    i++;
    flag = (num2 > 214748364);
    num2 = num2 * 10 + num - 48;
    flag = (flag || (UInt32)num2 > Int32::MaxValue + ((UInt32)num4 >> 31));
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_024b;
    }
    num = value[i];
    while (IsDigit(num)) {
      flag = true;
      i++;
      if ((UInt32)i < (UInt32)value.get_Length()) {
        num = value[i];
        continue;
      }
      goto IL_0262;
    }
  }
  goto IL_026a;

IL_024e:
  result = num2 * num4;
  return ParsingStatus::OK;

IL_0048:
  num4 = 1;
  if ((styles & NumberStyles::AllowLeadingSign) != 0) {
    if (info->get_HasInvariantNumberSigns()) {
      if (num == 45) {
        num4 = -1;
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_025a;
        }
        num = value[i];
      } else if (num == 43) {
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_025a;
        }
        num = value[i];
      }

    } else {
      value = value.Slice(i);
      i = 0;
      String positiveSign = info->get_PositiveSign();
      String negativeSign = info->get_NegativeSign();
      if (!String::in::IsNullOrEmpty(positiveSign) && MemoryExtensions::StartsWith(value, positiveSign)) {
        i += positiveSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_025a;
        }
        num = value[i];
      } else if (!String::in::IsNullOrEmpty(negativeSign) && MemoryExtensions::StartsWith(value, negativeSign)) {
        num4 = -1;
        i += negativeSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_025a;
        }
        num = value[i];
      }

    }
  }
  flag = false;
  num2 = 0;
  if (IsDigit(num)) {
    if (num != 48) {
      goto IL_017b;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (num == 48) {
        continue;
      }
      goto IL_0170;
    }
    goto IL_024e;
  }
  goto IL_025a;

IL_026a:
  if (IsWhite(num)) {
    if ((styles & NumberStyles::AllowTrailingWhite) == 0) {
      goto IL_025a;
    }
    for (i++; i < value.get_Length() && IsWhite(value[i]); i++) {
    }
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_024b;
    }
  }
  if (TrailingZeros(value, i)) {
    goto IL_024b;
  }
  goto IL_025a;

IL_024b:
  if (!flag) {
    goto IL_024e;
  }
  goto IL_0262;

IL_025a:
  result = 0;
  return ParsingStatus::Failed;
}

Number::ParsingStatus Number::TryParseInt64IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result) {
  Int32 i;
  Int32 num;
  if (!value.get_IsEmpty()) {
    i = 0;
    num = value[0];
    if ((styles & NumberStyles::AllowLeadingWhite) == 0 || !IsWhite(num)) {
      goto IL_0048;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (IsWhite(num)) {
        continue;
      }
      goto IL_0048;
    }
  }
  goto IL_0270;

IL_0171:
  if (IsDigit(num)) {
    goto IL_017c;
  }
  goto IL_0282;

IL_0279:
  result = 0;
  return ParsingStatus::Overflow;

IL_017c:
  Int64 num2 = num - 48;
  i++;
  Int32 num3 = 0;
  while (num3 < 17) {
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0263;
    }
    num = value[i];
    if (IsDigit(num)) {
      i++;
      num2 = 10 * num2 + num - 48;
      num3++;
      continue;
    }
    goto IL_0282;
  }
  if ((UInt32)i >= (UInt32)value.get_Length()) {
    goto IL_0263;
  }
  num = value[i];
  Boolean flag;
  Int32 num4;
  if (IsDigit(num)) {
    i++;
    flag = (num2 > 922337203685477580);
    num2 = num2 * 10 + num - 48;
    flag = (flag || (UInt64)num2 > (UInt64)(Int64::MaxValue + (Int64)((UInt32)num4 >> 31)));
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0260;
    }
    num = value[i];
    while (IsDigit(num)) {
      flag = true;
      i++;
      if ((UInt32)i < (UInt32)value.get_Length()) {
        num = value[i];
        continue;
      }
      goto IL_0279;
    }
  }
  goto IL_0282;

IL_0263:
  result = num2 * num4;
  return ParsingStatus::OK;

IL_0048:
  num4 = 1;
  if ((styles & NumberStyles::AllowLeadingSign) != 0) {
    if (info->get_HasInvariantNumberSigns()) {
      if (num == 45) {
        num4 = -1;
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0270;
        }
        num = value[i];
      } else if (num == 43) {
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0270;
        }
        num = value[i];
      }

    } else {
      value = value.Slice(i);
      i = 0;
      String positiveSign = info->get_PositiveSign();
      String negativeSign = info->get_NegativeSign();
      if (!String::in::IsNullOrEmpty(positiveSign) && MemoryExtensions::StartsWith(value, positiveSign)) {
        i += positiveSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0270;
        }
        num = value[i];
      } else if (!String::in::IsNullOrEmpty(negativeSign) && MemoryExtensions::StartsWith(value, negativeSign)) {
        num4 = -1;
        i += negativeSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0270;
        }
        num = value[i];
      }

    }
  }
  flag = false;
  num2 = 0;
  if (IsDigit(num)) {
    if (num != 48) {
      goto IL_017c;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (num == 48) {
        continue;
      }
      goto IL_0171;
    }
    goto IL_0263;
  }
  goto IL_0270;

IL_0282:
  if (IsWhite(num)) {
    if ((styles & NumberStyles::AllowTrailingWhite) == 0) {
      goto IL_0270;
    }
    for (i++; i < value.get_Length() && IsWhite(value[i]); i++) {
    }
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0260;
    }
  }
  if (TrailingZeros(value, i)) {
    goto IL_0260;
  }
  goto IL_0270;

IL_0260:
  if (!flag) {
    goto IL_0263;
  }
  goto IL_0279;

IL_0270:
  result = 0;
  return ParsingStatus::Failed;
}

Number::ParsingStatus Number::TryParseInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result) {
  if ((styles & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign)) == 0) {
    return TryParseInt64IntegerStyle(value, styles, info, result);
  }
  if ((styles & NumberStyles::AllowHexSpecifier) != 0) {
    result = 0;
    return TryParseUInt64HexNumberStyle(value, styles, Unsafe::As<Int64, UInt64>(result));
  }
  return TryParseInt64Number(value, styles, info, result);
}

Number::ParsingStatus Number::TryParseInt64Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result) {
  result = 0;
  Byte as[20] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits, 20);
  if (!TryStringToNumber(value, styles, number, info)) {
    return ParsingStatus::Failed;
  }
  if (!TryNumberToInt64(number, result)) {
    return ParsingStatus::Overflow;
  }
  return ParsingStatus::OK;
}

Number::ParsingStatus Number::TryParseUInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result) {
  if ((styles & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign)) == 0) {
    return TryParseUInt32IntegerStyle(value, styles, info, result);
  }
  if ((styles & NumberStyles::AllowHexSpecifier) != 0) {
    return TryParseUInt32HexNumberStyle(value, styles, result);
  }
  return TryParseUInt32Number(value, styles, info, result);
}

Number::ParsingStatus Number::TryParseUInt32Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result) {
  result = 0u;
  Byte as[11] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits, 11);
  if (!TryStringToNumber(value, styles, number, info)) {
    return ParsingStatus::Failed;
  }
  if (!TryNumberToUInt32(number, result)) {
    return ParsingStatus::Overflow;
  }
  return ParsingStatus::OK;
}

Number::ParsingStatus Number::TryParseUInt32IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result) {
  Int32 i;
  Int32 num;
  if (!value.get_IsEmpty()) {
    i = 0;
    num = value[0];
    if ((styles & NumberStyles::AllowLeadingWhite) == 0 || !IsWhite(num)) {
      goto IL_0048;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (IsWhite(num)) {
        continue;
      }
      goto IL_0048;
    }
  }
  goto IL_0252;

IL_016d:
  if (IsDigit(num)) {
    goto IL_0178;
  }
  Boolean flag = false;
  goto IL_0264;

IL_0178:
  Int32 num2 = num - 48;
  i++;
  Int32 num3 = 0;
  while (num3 < 8) {
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0246;
    }
    num = value[i];
    if (IsDigit(num)) {
      i++;
      num2 = 10 * num2 + num - 48;
      num3++;
      continue;
    }
    goto IL_0264;
  }
  if ((UInt32)i >= (UInt32)value.get_Length()) {
    goto IL_0246;
  }
  num = value[i];
  if (IsDigit(num)) {
    i++;
    flag = (flag || (UInt32)num2 > 429496729u || (num2 == 429496729 && num > 53));
    num2 = num2 * 10 + num - 48;
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0246;
    }
    num = value[i];
    while (IsDigit(num)) {
      flag = true;
      i++;
      if ((UInt32)i < (UInt32)value.get_Length()) {
        num = value[i];
        continue;
      }
      goto IL_025a;
    }
  }
  goto IL_0264;

IL_0264:
  if (IsWhite(num)) {
    if ((styles & NumberStyles::AllowTrailingWhite) == 0) {
      goto IL_0252;
    }
    for (i++; i < value.get_Length() && IsWhite(value[i]); i++) {
    }
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0246;
    }
  }
  if (TrailingZeros(value, i)) {
    goto IL_0246;
  }
  goto IL_0252;

IL_025a:
  result = 0u;
  return ParsingStatus::Overflow;

IL_0048:
  flag = false;
  if ((styles & NumberStyles::AllowLeadingSign) != 0) {
    if (info->get_HasInvariantNumberSigns()) {
      if (num == 43) {
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0252;
        }
        num = value[i];
      } else if (num == 45) {
        flag = true;
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0252;
        }
        num = value[i];
      }

    } else {
      value = value.Slice(i);
      i = 0;
      String positiveSign = info->get_PositiveSign();
      String negativeSign = info->get_NegativeSign();
      if (!String::in::IsNullOrEmpty(positiveSign) && MemoryExtensions::StartsWith(value, positiveSign)) {
        i += positiveSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0252;
        }
        num = value[i];
      } else if (!String::in::IsNullOrEmpty(negativeSign) && MemoryExtensions::StartsWith(value, negativeSign)) {
        flag = true;
        i += negativeSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0252;
        }
        num = value[i];
      }

    }
  }
  num2 = 0;
  if (IsDigit(num)) {
    if (num != 48) {
      goto IL_0178;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (num == 48) {
        continue;
      }
      goto IL_016d;
    }
    goto IL_0249;
  }
  goto IL_0252;

IL_0246:
  if (!flag) {
    goto IL_0249;
  }
  goto IL_025a;

IL_0249:
  result = (UInt32)num2;
  return ParsingStatus::OK;

IL_0252:
  result = 0u;
  return ParsingStatus::Failed;
}

Number::ParsingStatus Number::TryParseUInt32HexNumberStyle(ReadOnlySpan<Char> value, NumberStyles styles, UInt32& result) {
  Int32 i;
  Int32 num;
  if (!value.get_IsEmpty()) {
    i = 0;
    num = value[0];
    if ((styles & NumberStyles::AllowLeadingWhite) == 0 || !IsWhite(num)) {
      goto IL_0048;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (IsWhite(num)) {
        continue;
      }
      goto IL_0048;
    }
  }
  goto IL_018c;

IL_0098:
  ReadOnlySpan<Byte> charToHexLookup;
  if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
    goto IL_00b8;
  }
  goto IL_019c;

IL_017c:
  Boolean flag = true;
  goto IL_019c;

IL_00b8:
  UInt32 num2 = charToHexLookup[num];
  i++;
  Int32 num3 = 0;
  while (num3 < 7) {
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0183;
    }
    num = value[i];
    UInt32 num4;
    if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && (num4 = charToHexLookup[num]) != 255) {
      i++;
      num2 = 16 * num2 + num4;
      num3++;
      continue;
    }
    goto IL_019c;
  }
  if ((UInt32)i >= (UInt32)value.get_Length()) {
    goto IL_0183;
  }
  num = value[i];
  if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
        continue;
      }
      goto IL_017c;
    }
    goto IL_0194;
  }
  goto IL_019c;

IL_018c:
  result = 0u;
  return ParsingStatus::Failed;

IL_0048:
  flag = false;
  num2 = 0u;
  charToHexLookup = get_CharToHexLookup();
  if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
    if (num != 48) {
      goto IL_00b8;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (num == 48) {
        continue;
      }
      goto IL_0098;
    }
    goto IL_0183;
  }
  goto IL_018c;

IL_0183:
  result = num2;
  return ParsingStatus::OK;

IL_0194:
  result = 0u;
  return ParsingStatus::Overflow;

IL_0180:
  if (!flag) {
    goto IL_0183;
  }
  goto IL_0194;

IL_019c:
  if (IsWhite(num)) {
    if ((styles & NumberStyles::AllowTrailingWhite) == 0) {
      goto IL_018c;
    }
    for (i++; i < value.get_Length() && IsWhite(value[i]); i++) {
    }
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0180;
    }
  }
  if (TrailingZeros(value, i)) {
    goto IL_0180;
  }
  goto IL_018c;
}

Number::ParsingStatus Number::TryParseUInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result) {
  if ((styles & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign)) == 0) {
    return TryParseUInt64IntegerStyle(value, styles, info, result);
  }
  if ((styles & NumberStyles::AllowHexSpecifier) != 0) {
    return TryParseUInt64HexNumberStyle(value, styles, result);
  }
  return TryParseUInt64Number(value, styles, info, result);
}

Number::ParsingStatus Number::TryParseUInt64Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result) {
  result = 0;
  Byte as[21] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Integer, digits, 21);
  if (!TryStringToNumber(value, styles, number, info)) {
    return ParsingStatus::Failed;
  }
  if (!TryNumberToUInt64(number, result)) {
    return ParsingStatus::Overflow;
  }
  return ParsingStatus::OK;
}

Number::ParsingStatus Number::TryParseUInt64IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result) {
  Int32 i;
  Int32 num;
  if (!value.get_IsEmpty()) {
    i = 0;
    num = value[0];
    if ((styles & NumberStyles::AllowLeadingWhite) == 0 || !IsWhite(num)) {
      goto IL_0048;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (IsWhite(num)) {
        continue;
      }
      goto IL_0048;
    }
  }
  goto IL_0266;

IL_016e:
  if (IsDigit(num)) {
    goto IL_0179;
  }
  Boolean flag = false;
  goto IL_027a;

IL_0179:
  Int64 num2 = num - 48;
  i++;
  Int32 num3 = 0;
  while (num3 < 18) {
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_025a;
    }
    num = value[i];
    if (IsDigit(num)) {
      i++;
      num2 = 10 * num2 + num - 48;
      num3++;
      continue;
    }
    goto IL_027a;
  }
  if ((UInt32)i >= (UInt32)value.get_Length()) {
    goto IL_025a;
  }
  num = value[i];
  if (IsDigit(num)) {
    i++;
    flag = (flag || (UInt64)num2 > 1844674407370955161 || (num2 == 1844674407370955161 && num > 53));
    num2 = num2 * 10 + num - 48;
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_025a;
    }
    num = value[i];
    while (IsDigit(num)) {
      flag = true;
      i++;
      if ((UInt32)i < (UInt32)value.get_Length()) {
        num = value[i];
        continue;
      }
      goto IL_026f;
    }
  }
  goto IL_027a;

IL_027a:
  if (IsWhite(num)) {
    if ((styles & NumberStyles::AllowTrailingWhite) == 0) {
      goto IL_0266;
    }
    for (i++; i < value.get_Length() && IsWhite(value[i]); i++) {
    }
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_025a;
    }
  }
  if (TrailingZeros(value, i)) {
    goto IL_025a;
  }
  goto IL_0266;

IL_026f:
  result = 0;
  return ParsingStatus::Overflow;

IL_0048:
  flag = false;
  if ((styles & NumberStyles::AllowLeadingSign) != 0) {
    if (info->get_HasInvariantNumberSigns()) {
      if (num == 43) {
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0266;
        }
        num = value[i];
      } else if (num == 45) {
        flag = true;
        i++;
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0266;
        }
        num = value[i];
      }

    } else {
      value = value.Slice(i);
      i = 0;
      String positiveSign = info->get_PositiveSign();
      String negativeSign = info->get_NegativeSign();
      if (!String::in::IsNullOrEmpty(positiveSign) && MemoryExtensions::StartsWith(value, positiveSign)) {
        i += positiveSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0266;
        }
        num = value[i];
      } else if (!String::in::IsNullOrEmpty(negativeSign) && MemoryExtensions::StartsWith(value, negativeSign)) {
        flag = true;
        i += negativeSign->get_Length();
        if ((UInt32)i >= (UInt32)value.get_Length()) {
          goto IL_0266;
        }
        num = value[i];
      }

    }
  }
  num2 = 0;
  if (IsDigit(num)) {
    if (num != 48) {
      goto IL_0179;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (num == 48) {
        continue;
      }
      goto IL_016e;
    }
    goto IL_025d;
  }
  goto IL_0266;

IL_025a:
  if (!flag) {
    goto IL_025d;
  }
  goto IL_026f;

IL_025d:
  result = (UInt64)num2;
  return ParsingStatus::OK;

IL_0266:
  result = 0;
  return ParsingStatus::Failed;
}

Number::ParsingStatus Number::TryParseUInt64HexNumberStyle(ReadOnlySpan<Char> value, NumberStyles styles, UInt64& result) {
  Int32 i;
  Int32 num;
  if (!value.get_IsEmpty()) {
    i = 0;
    num = value[0];
    if ((styles & NumberStyles::AllowLeadingWhite) == 0 || !IsWhite(num)) {
      goto IL_0048;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (IsWhite(num)) {
        continue;
      }
      goto IL_0048;
    }
  }
  goto IL_0191;

IL_0099:
  ReadOnlySpan<Byte> charToHexLookup;
  if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
    goto IL_00b9;
  }
  goto IL_01a3;

IL_0181:
  Boolean flag = true;
  goto IL_01a3;

IL_00b9:
  UInt64 num2 = charToHexLookup[num];
  i++;
  Int32 num3 = 0;
  while (num3 < 15) {
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0188;
    }
    num = value[i];
    UInt32 num4;
    if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && (num4 = charToHexLookup[num]) != 255) {
      i++;
      num2 = 16 * num2 + num4;
      num3++;
      continue;
    }
    goto IL_01a3;
  }
  if ((UInt32)i >= (UInt32)value.get_Length()) {
    goto IL_0188;
  }
  num = value[i];
  if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
        continue;
      }
      goto IL_0181;
    }
    goto IL_019a;
  }
  goto IL_01a3;

IL_0191:
  result = 0;
  return ParsingStatus::Failed;

IL_0048:
  flag = false;
  num2 = 0;
  charToHexLookup = get_CharToHexLookup();
  if ((UInt32)num < (UInt32)charToHexLookup.get_Length() && charToHexLookup[num] != Byte::MaxValue) {
    if (num != 48) {
      goto IL_00b9;
    }
    while (true) {
      i++;
      if ((UInt32)i >= (UInt32)value.get_Length()) {
        break;
      }
      num = value[i];
      if (num == 48) {
        continue;
      }
      goto IL_0099;
    }
    goto IL_0188;
  }
  goto IL_0191;

IL_0188:
  result = num2;
  return ParsingStatus::OK;

IL_019a:
  result = 0;
  return ParsingStatus::Overflow;

IL_0185:
  if (!flag) {
    goto IL_0188;
  }
  goto IL_019a;

IL_01a3:
  if (IsWhite(num)) {
    if ((styles & NumberStyles::AllowTrailingWhite) == 0) {
      goto IL_0191;
    }
    for (i++; i < value.get_Length() && IsWhite(value[i]); i++) {
    }
    if ((UInt32)i >= (UInt32)value.get_Length()) {
      goto IL_0185;
    }
  }
  if (TrailingZeros(value, i)) {
    goto IL_0185;
  }
  goto IL_0191;
}

Decimal Number::ParseDecimal(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  Decimal result;
  ParsingStatus parsingStatus = TryParseDecimal(value, styles, info, result);
  if (parsingStatus != 0) {
    ThrowOverflowOrFormatException(parsingStatus, TypeCode::Decimal);
  }
  return result;
}

Boolean Number::TryNumberToDecimal(NumberBuffer& number, Decimal& value) {
  Byte* ptr = number.GetDigitsPointer();
  Int32 num = number.Scale;
  Boolean isNegative = number.IsNegative;
  UInt32 num2 = *ptr;
  if (num2 == 0) {
    value = Decimal(0, 0, 0, isNegative, (Byte)Math::Clamp(-num, 0, 28));
    return true;
  }
  if (num > 29) {
    return false;
  }
  UInt64 num3 = 0;
  while (num > -28) {
    num--;
    num3 *= 10;
    num3 += num2 - 48;
    num2 = *(++ptr);
    if (num3 >= 1844674407370955161) {
      break;
    }
    if (num2 != 0) {
      continue;
    }
    while (num > 0) {
      num--;
      num3 *= 10;
      if (num3 >= 1844674407370955161) {
        break;
      }
    }
    break;
  }
  UInt32 num4 = 0u;
  while ((num > 0 || (num2 != 0 && num > -28)) && (num4 < 429496729 || (num4 == 429496729 && (num3 < 11068046444225730969 || (num3 == 11068046444225730969 && num2 <= 53))))) {
    UInt64 num5 = (UInt64)(UInt32)num3 * 10;
    UInt64 num6 = (UInt64)((Int64)(UInt32)(num3 >> 32) * 10) + (num5 >> 32);
    num3 = (UInt32)num5 + (num6 << 32);
    num4 = (UInt32)(Int32)(num6 >> 32) + num4 * 10;
    if (num2 != 0) {
      num2 -= 48;
      num3 += num2;
      if (num3 < num2) {
        num4++;
      }
      num2 = *(++ptr);
    }
    num--;
  }
  if (num2 >= 53) {
    if (num2 == 53 && (num3 & 1) == 0) {
      num2 = *(++ptr);
      Boolean flag = !number.HasNonZeroTail;
      while (num2 != 0 && flag) {
        flag = (flag && num2 == 48);
        num2 = *(++ptr);
      }
      if (flag) {
        goto IL_01a8;
      }
    }
    if (++num3 == 0 && ++num4 == 0) {
      num3 = 11068046444225730970;
      num4 = 429496729u;
      num++;
    }
  }
  goto IL_01a8;

IL_01a8:
  if (num > 0) {
    return false;
  }
  if (num <= -29) {
    value = Decimal(0, 0, 0, isNegative, 28);
  } else {
    value = Decimal((Int32)num3, (Int32)(num3 >> 32), (Int32)num4, isNegative, (Byte)(-num));
  }
  return true;
}

Double Number::ParseDouble(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  Double result;
  if (!TryParseDouble(value, styles, info, result)) {
    ThrowOverflowOrFormatException(ParsingStatus::Failed);
  }
  return result;
}

Single Number::ParseSingle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  Single result;
  if (!TryParseSingle(value, styles, info, result)) {
    ThrowOverflowOrFormatException(ParsingStatus::Failed);
  }
  return result;
}

Number::ParsingStatus Number::TryParseDecimal(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Decimal& result) {
  Byte as[31] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::Decimal, digits, 31);
  result = Decimal();
  if (!TryStringToNumber(value, styles, number, info)) {
    return ParsingStatus::Failed;
  }
  if (!TryNumberToDecimal(number, result)) {
    return ParsingStatus::Overflow;
  }
  return ParsingStatus::OK;
}

Boolean Number::TryParseDouble(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Double& result) {
  Byte as[769] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::FloatingPoint, digits, 769);
  if (!TryStringToNumber(value, styles, number, info)) {
    ReadOnlySpan<Char> span = MemoryExtensions::Trim(value);
    if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_PositiveInfinitySymbol())) {
      result = Double::PositiveInfinity;
    } else if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_NegativeInfinitySymbol())) {
      result = Double::NegativeInfinity;
    } else if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_NaNSymbol())) {
      result = Double::NaN;
    } else if (MemoryExtensions::StartsWith(span, info->get_PositiveSign(), StringComparison::OrdinalIgnoreCase)) {
      span = span.Slice(info->get_PositiveSign()->get_Length());
      if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_PositiveInfinitySymbol())) {
        result = Double::PositiveInfinity;
      } else {
        if (!MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_NaNSymbol())) {
          result = 0;
          return false;
        }
        result = Double::NaN;
      }
    } else {
      if (!MemoryExtensions::StartsWith(span, info->get_NegativeSign(), StringComparison::OrdinalIgnoreCase) || !MemoryExtensions::EqualsOrdinalIgnoreCase(span.Slice(info->get_NegativeSign()->get_Length()), info->get_NaNSymbol())) {
        result = 0;
        return false;
      }
      result = Double::NaN;
    }



  } else {
    result = NumberToDouble(number);
  }
  return true;
}

Boolean Number::TryParseSingle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Single& result) {
  Byte as[114] = {};
  Byte* digits = as;
  NumberBuffer number = NumberBuffer(NumberBufferKind::FloatingPoint, digits, 114);
  if (!TryStringToNumber(value, styles, number, info)) {
    ReadOnlySpan<Char> span = MemoryExtensions::Trim(value);
    if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_PositiveInfinitySymbol())) {
      result = Single::PositiveInfinity;
    } else if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_NegativeInfinitySymbol())) {
      result = Single::NegativeInfinity;
    } else if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_NaNSymbol())) {
      result = Single::NaN;
    } else if (MemoryExtensions::StartsWith(span, info->get_PositiveSign(), StringComparison::OrdinalIgnoreCase)) {
      span = span.Slice(info->get_PositiveSign()->get_Length());
      if (!info->get_PositiveInfinitySymbol()->StartsWith(info->get_PositiveSign(), StringComparison::OrdinalIgnoreCase) && MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_PositiveInfinitySymbol())) {
        result = Single::PositiveInfinity;
      } else {
        if (info->get_NaNSymbol()->StartsWith(info->get_PositiveSign(), StringComparison::OrdinalIgnoreCase) || !MemoryExtensions::EqualsOrdinalIgnoreCase(span, info->get_NaNSymbol())) {
          result = 0;
          return false;
        }
        result = Single::NaN;
      }
    } else {
      if (!MemoryExtensions::StartsWith(span, info->get_NegativeSign(), StringComparison::OrdinalIgnoreCase) || info->get_NaNSymbol()->StartsWith(info->get_NegativeSign(), StringComparison::OrdinalIgnoreCase) || !MemoryExtensions::EqualsOrdinalIgnoreCase(span.Slice(info->get_NegativeSign()->get_Length()), info->get_NaNSymbol())) {
        result = 0;
        return false;
      }
      result = Single::NaN;
    }



  } else {
    result = NumberToSingle(number);
  }
  return true;
}

Boolean Number::TryStringToNumber(ReadOnlySpan<Char> value, NumberStyles styles, NumberBuffer& number, NumberFormatInfo info) {
  {
    Char* ptr = &MemoryMarshal::GetReference(value);
    Char* str = ptr;
    if (!TryParseNumber(str, str + value.get_Length(), styles, number, info) || ((Int32)(str - ptr) < value.get_Length() && !TrailingZeros(value, (Int32)(str - ptr)))) {
      return false;
    }
  }
  return true;
}

Boolean Number::TrailingZeros(ReadOnlySpan<Char> value, Int32 index) {
  for (Int32 i = index; (UInt32)i < (UInt32)value.get_Length(); i++) {
    if (value[i] != 0) {
      return false;
    }
  }
  return true;
}

Boolean Number::IsSpaceReplacingChar(Char c) {
  if (c != 160) {
    return c == 8239;
  }
  return true;
}

Char* Number::MatchChars(Char* p, Char* pEnd, String value) {
  {
    Char* ptr = value;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2;
    if (*ptr3 != 0) {
      while (true) {
        Char c = (p < pEnd) ? (*p) : 0;
        if (c != *ptr3 && (!IsSpaceReplacingChar(*ptr3) || c != 32)) {
          break;
        }
        p++;
        ptr3++;
        if (*ptr3 == 0) {
          return p;
        }
      }
    }
  }
  return nullptr;
}

Boolean Number::IsWhite(Int32 ch) {
  if (ch != 32 && (UInt32)(ch - 9) > 4u) {
    return false;
  }
  return true;
}

Boolean Number::IsDigit(Int32 ch) {
  return (UInt32)(ch - 48) <= 9u;
}

void Number::ThrowOverflowOrFormatException(ParsingStatus status, TypeCode type) {
  rt::throw_exception(GetException(status, type));
}

void Number::ThrowOverflowException(TypeCode type) {
  rt::throw_exception(GetException(ParsingStatus::Overflow, type));
}

Exception Number::GetException(ParsingStatus status, TypeCode type) {
  if (status == ParsingStatus::Failed) {
    return rt::newobj<FormatException>(SR::get_Format_InvalidString());
  }
  String message;
  switch (type) {
    case TypeCode::SByte:
      message = SR::get_Overflow_SByte();
      break;
    case TypeCode::Byte:
      message = SR::get_Overflow_Byte();
      break;
    case TypeCode::Int16:
      message = SR::get_Overflow_Int16();
      break;
    case TypeCode::UInt16:
      message = SR::get_Overflow_UInt16();
      break;
    case TypeCode::Int32:
      message = SR::get_Overflow_Int32();
      break;
    case TypeCode::UInt32:
      message = SR::get_Overflow_UInt32();
      break;
    case TypeCode::Int64:
      message = SR::get_Overflow_Int64();
      break;
    case TypeCode::UInt64:
      message = SR::get_Overflow_UInt64();
      break;
    default:
      message = SR::get_Overflow_Decimal();
      break;
  }
  return rt::newobj<OverflowException>(message);
}

Double Number::NumberToDouble(NumberBuffer& number) {
  Double num;
  if (number.DigitsCount == 0 || number.Scale < -324) {
    num = 0;
  } else if (number.Scale > 309) {
    num = Double::PositiveInfinity;
  } else {
    UInt64 value = NumberToFloatingPointBits(number, FloatingPointInfo::Double);
    num = BitConverter::Int64BitsToDouble((Int64)value);
  }

  if (!number.IsNegative) {
    return num;
  }
  return 0 - num;
}

Single Number::NumberToSingle(NumberBuffer& number) {
  Single num;
  if (number.DigitsCount == 0 || number.Scale < -45) {
    num = 0;
  } else if (number.Scale > 39) {
    num = Single::PositiveInfinity;
  } else {
    UInt32 value = (UInt32)NumberToFloatingPointBits(number, FloatingPointInfo::Single);
    num = BitConverter::Int32BitsToSingle((Int32)value);
  }

  if (!number.IsNegative) {
    return num;
  }
  return 0 - num;
}

void Number::cctor() {
  s_singleDigitStringCache = rt::newarr<Array<String>>(10);
  s_posCurrencyFormats = rt::newarr<Array<String>>(4);
  s_negCurrencyFormats = rt::newarr<Array<String>>(17);
  s_posPercentFormats = rt::newarr<Array<String>>(4);
  s_negPercentFormats = rt::newarr<Array<String>>(12);
  s_negNumberFormats = rt::newarr<Array<String>>(5);
  s_Pow10SingleTable = rt::newarr<Array<Single>>(11);
  s_Pow10DoubleTable = rt::newarr<Array<Double>>(23);
}

} // namespace System::Private::CoreLib::System::NumberNamespace
