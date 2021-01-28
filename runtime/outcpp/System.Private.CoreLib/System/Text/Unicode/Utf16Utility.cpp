#include "Utf16Utility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse41-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIUtility-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Text::Unicode::Utf16UtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::X86;

Boolean Utf16Utility::AllCharsInUInt32AreAscii(UInt32 value) {
  return (value & 4286644096u) == 0;
}

Boolean Utf16Utility::AllCharsInUInt64AreAscii(UInt64 value) {
  return (value & 18410996206198128512) == 0;
}

UInt32 Utf16Utility::ConvertAllAsciiCharsInUInt32ToLowercase(UInt32 value) {
  UInt32 num = value + 8388736 - 4259905;
  UInt32 num2 = value + 8388736 - 5963867;
  UInt32 num3 = num ^ num2;
  UInt32 num4 = (num3 & 8388736) >> 2;
  return value ^ num4;
}

UInt32 Utf16Utility::ConvertAllAsciiCharsInUInt32ToUppercase(UInt32 value) {
  UInt32 num = value + 8388736 - 6357089;
  UInt32 num2 = value + 8388736 - 8061051;
  UInt32 num3 = num ^ num2;
  UInt32 num4 = (num3 & 8388736) >> 2;
  return value ^ num4;
}

Boolean Utf16Utility::UInt32ContainsAnyLowercaseAsciiChar(UInt32 value) {
  UInt32 num = value + 8388736 - 6357089;
  UInt32 num2 = value + 8388736 - 8061051;
  UInt32 num3 = num ^ num2;
  return (num3 & 8388736) != 0;
}

Boolean Utf16Utility::UInt32ContainsAnyUppercaseAsciiChar(UInt32 value) {
  UInt32 num = value + 8388736 - 4259905;
  UInt32 num2 = value + 8388736 - 5963867;
  UInt32 num3 = num ^ num2;
  return (num3 & 8388736) != 0;
}

Boolean Utf16Utility::UInt32OrdinalIgnoreCaseAscii(UInt32 valueA, UInt32 valueB) {
  UInt32 num = valueA ^ valueB;
  UInt32 num2 = valueA + 16777472 - 4259905;
  UInt32 num3 = (valueA | 2097184) + 8388736 - 8061051;
  UInt32 num4 = num2 | num3;
  return (((num4 >> 2) | 4292870111u) & num) == 0;
}

Boolean Utf16Utility::UInt64OrdinalIgnoreCaseAscii(UInt64 valueA, UInt64 valueB) {
  UInt64 num = valueA + 36029346783166592 - 18296152663326785;
  UInt64 num2 = (valueA | 9007336695791648) + 72058693566333184 - 34621950424449147;
  UInt64 num3 = (36029346783166592 & num & num2) >> 2;
  return (valueA | num3) == (valueB | num3);
}

Char* Utf16Utility::GetPointerToFirstInvalidChar(Char* pInputBuffer, Int32 inputLength, Int64& utf8CodeUnitCountAdjustment, Int32& scalarCountAdjustment) {
  Int32 num = (Int32)ASCIIUtility::GetIndexOfFirstNonAsciiChar(pInputBuffer, (UIntPtr)(UInt32)inputLength);
  pInputBuffer += (UInt32)num;
  inputLength -= num;
  if (inputLength == 0) {
    utf8CodeUnitCountAdjustment = 0;
    scalarCountAdjustment = 0;
    return pInputBuffer;
  }
  Int64 num2 = 0;
  Int32 num3 = 0;
  if (Sse2::in::get_IsSupported()) {
    if (inputLength >= Vector128<UInt16>::get_Count()) {
      Vector128<UInt16> vector = Vector128<>::Create((UInt16)(Int32)128);
      Vector128<UInt16> right = Vector128<>::Create((UInt16)(Int32)43008);
      Vector128<Int16> right2 = Vector128<>::Create((Int16)(Int32)(-30720));
      Vector128<UInt16> zero = Vector128<UInt16>::get_Zero();
      do {
        Vector128<UInt16> vector2 = Sse2::in::LoadVector128((UInt16*)pInputBuffer);
        Vector128<UInt16> left = ((!Sse41::in::get_IsSupported()) ? Sse2::in::AndNot(Vector128<>::AsUInt16(Sse2::in::CompareGreaterThan(Vector128<>::AsInt16(vector), Vector128<>::AsInt16(vector2))), vector) : Sse41::in::Min(vector2, vector));
        Vector128<UInt16> right3 = Sse2::in::Subtract(zero, Sse2::in::ShiftRightLogical(vector2, 11));
        UInt32 value = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::Or(left, right3)));
        UInt32 num4 = (UInt32)BitOperations::PopCount(value);
        vector2 = Sse2::in::Add(vector2, right);
        value = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareLessThan(Vector128<>::AsInt16(vector2), right2)));
        if (value != 0) {
          UInt32 num5 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::ShiftRightLogical(vector2, 3)));
          UInt32 num6 = num5 & value;
          UInt32 num7 = (num5 ^ 21845u) & value;
          num7 <<= 2;
          if ((UInt16)num7 != num6) {
            break;
          }
          if (num7 > 65535) {
            num7 = (UInt16)num7;
            num4 -= 2;
            pInputBuffer--;
            inputLength++;
          }
          UIntPtr uIntPtr = (UIntPtr)(UInt32)BitOperations::PopCount(num7);
          num3 -= (Int32)(UInt64)uIntPtr;
          Int32 size = IntPtr::get_Size();
          num2 -= (Int64)(UInt64)uIntPtr;
          num2 -= (Int64)(UInt64)uIntPtr;
        }
        num2 += num4;
        pInputBuffer += Vector128<UInt16>::get_Count();
        inputLength -= Vector128<UInt16>::get_Count();
      } while (inputLength >= Vector128<UInt16>::get_Count());
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && inputLength >= Vector<UInt16>::get_Count()) {
    Vector<UInt16> right4 = Vector<UInt16>(128);
    Vector<UInt16> right5 = Vector<UInt16>(1024);
    Vector<UInt16> right6 = Vector<UInt16>(2048);
    Vector<UInt16> vector3 = Vector<UInt16>(55296);
    while (true) {
      Vector<UInt16> left2 = Unsafe::ReadUnaligned<Vector<UInt16>>(pInputBuffer);
      Vector<UInt16> right7 = Vector<>::GreaterThanOrEqual(left2, right4);
      Vector<UInt16> right8 = Vector<>::GreaterThanOrEqual(left2, right6);
      Vector<UInt64> vector4 = (Vector<UInt64>)(Vector<UInt16>::get_Zero() - right7 - right8);
      UIntPtr uIntPtr2 = (UIntPtr)(void*)(void*)nullptr;
      for (Int32 i = 0; i < Vector<UInt64>::get_Count(); i++) {
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(Int64)(IntPtr)(void*)vector4[i]);
      }
      UInt32 num8 = (UInt32)(UInt64)uIntPtr2;
      Int32 size2 = IntPtr::get_Size();
      num8 += (UInt32)(Int32)((UInt64)uIntPtr2 >> 32);
      num8 = (UInt16)num8 + (num8 >> 16);
      left2 -= vector3;
      Vector<UInt16> left3 = Vector<>::LessThan(left2, right6);
      if (left3 != Vector<UInt16>::get_Zero()) {
        Vector<UInt16> right9 = Vector<>::LessThan(left2, right5);
        Vector<UInt16> vector5 = Vector<>::AndNot(left3, right9);
        if (vector5[0] != 0) {
          break;
        }
        UInt16 num9 = 0;
        Int32 num10 = 0;
        while (num10 < Vector<UInt16>::get_Count() - 1) {
          num9 = (UInt16)(num9 - right9[num10]);
          if (right9[num10] == vector5[num10 + 1]) {
            num10++;
            continue;
          }
          goto IL_03c1;
        }
        if (right9[Vector<UInt16>::get_Count() - 1] != 0) {
          pInputBuffer--;
          inputLength++;
          num8 -= 2;
        }
        IntPtr intPtr = (IntPtr)(void*)num9;
        num3 -= (Int32)(Int64)intPtr;
        num2 -= (Int64)intPtr;
        num2 -= (Int64)intPtr;
      }
      num2 += num8;
      pInputBuffer += Vector<UInt16>::get_Count();
      inputLength -= Vector<UInt16>::get_Count();
      if (inputLength >= Vector<UInt16>::get_Count()) {
        continue;
      }
      goto IL_03c1;
    }
    goto IL_03c5;
  }

  goto IL_03c1;

IL_03c1:
  while (inputLength > 0) {
    UInt32 num11 = *pInputBuffer;
    if (num11 > 127) {
      num2 += num11 + 129024 >> 16;
      if (UnicodeUtility::IsSurrogateCodePoint(num11)) {
        num2 -= 2;
        if (inputLength == 1) {
          break;
        }
        num11 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
        if (((num11 - (UInt32)(BitConverter::IsLittleEndian ? (-603924480) : (-671032320))) & 4227922944u) != 0) {
          break;
        }
        num3--;
        num2 += 2;
        pInputBuffer++;
        inputLength--;
      }
    }
    pInputBuffer++;
    inputLength--;
  }
  goto IL_03c5;

IL_03c5:
  utf8CodeUnitCountAdjustment = num2;
  scalarCountAdjustment = num3;
  return pInputBuffer;
}

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf16UtilityNamespace
