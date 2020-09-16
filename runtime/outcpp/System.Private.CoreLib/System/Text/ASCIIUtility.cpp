#include "ASCIIUtility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector64-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse41-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Text::ASCIIUtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Boolean ASCIIUtility::AllBytesInUInt64AreAscii(UInt64 value) {
  return ((Int64)value & -9187201950435737472) == 0;
}

Boolean ASCIIUtility::AllCharsInUInt32AreAscii(UInt32 value) {
  return ((Int32)value & -8323200) == 0;
}

Boolean ASCIIUtility::AllCharsInUInt64AreAscii(UInt64 value) {
  return ((Int64)value & -35747867511423104) == 0;
}

Int32 ASCIIUtility::GetIndexOfFirstNonAsciiByteInLane_AdvSimd(Vector128<Byte> value, Vector128<Byte> bitmask) {
  if (!AdvSimd::in::Arm64::in::get_IsSupported() || !BitConverter::IsLittleEndian) {
    rt::throw_exception<PlatformNotSupportedException>();
  }
  Vector128<Byte> left = Vector128<>::AsByte(AdvSimd::in::ShiftRightArithmetic(Vector128<>::AsSByte(value), 7));
  Vector128<Byte> vector = AdvSimd::in::And(left, bitmask);
  vector = AdvSimd::in::Arm64::in::AddPairwise(vector, vector);
  UInt64 value2 = Vector128<>::ToScalar(Vector128<>::AsUInt64(vector));
  return BitOperations::TrailingZeroCount(value2) >> 2;
}

Boolean ASCIIUtility::FirstCharInUInt32IsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 65408) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return ((Int32)value & -8388608) == 0;
    }
    return false;
  }
  return true;
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte(Byte* pBuffer, UIntPtr bufferLength) {
  if (!Sse2::in::get_IsSupported() && (!AdvSimd::in::Arm64::in::get_IsSupported() || !BitConverter::IsLittleEndian)) {
    return GetIndexOfFirstNonAsciiByte_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonAsciiByte_Intrinsified(pBuffer, bufferLength);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte_Default(Byte* pBuffer, UIntPtr bufferLength) {
  Byte* value = pBuffer;
  if (Vector<>::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<SByte>::get_Count())) {
    UInt32 count = (UInt32)Vector<SByte>::get_Count();
    if (Vector<>::GreaterThanOrEqualAll(Unsafe::ReadUnaligned<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
      Byte* ptr = pBuffer + bufferLength - count;
      pBuffer = (Byte*)(void*)(UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer + (Int64)count) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)(count - 1)));
      while (!Vector<>::LessThanAny(Unsafe::Read<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
        pBuffer += count;
        if (pBuffer > ptr) {
          break;
        }
      }
      bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)(Int64)(UInt64)(UIntPtr)(void*)pBuffer);
      bufferLength = (UIntPtr)((UInt64)bufferLength + (UInt64)(Int64)(UInt64)(UIntPtr)(void*)value);
    }
  }
  while (true) {
    UInt32 num;
    if (bufferLength >= 8) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      UInt32 num2 = Unsafe::ReadUnaligned<UInt32>(pBuffer + 4);
      if (!AllBytesInUInt32AreAscii(num | num2)) {
        if (AllBytesInUInt32AreAscii(num)) {
          num = num2;
          pBuffer += 4;
        }
        goto IL_011a;
      }
      pBuffer += 8;
      bufferLength -= 8;
      continue;
    }
    if ((bufferLength & 4) != 0) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      if (!AllBytesInUInt32AreAscii(num)) {
        goto IL_011a;
      }
      pBuffer += 4;
    }
    if ((bufferLength & 2) != 0) {
      num = Unsafe::ReadUnaligned<UInt16>(pBuffer);
      if (!AllBytesInUInt32AreAscii(num)) {
        goto IL_011a;
      }
      pBuffer += 2;
    }
    if ((bufferLength & 1) != 0 && *pBuffer >= 0) {
      pBuffer++;
    }
    break;

  IL_011a:
    pBuffer += CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(num);
    break;
  }
  return (UIntPtr)((UInt64)(Int64)(UInt64)(UIntPtr)(void*)pBuffer - (UInt64)(Int64)(UInt64)(UIntPtr)(void*)value);
}

Boolean ASCIIUtility::ContainsNonAsciiByte_Sse2(UInt32 sseMask) {
  return sseMask != 0;
}

Boolean ASCIIUtility::ContainsNonAsciiByte_AdvSimd(UInt32 advSimdIndex) {
  return advSimdIndex < 16;
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte_Intrinsified(Byte* pBuffer, UIntPtr bufferLength) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr uIntPtr = (UIntPtr)(num - 1);
  Vector128<Byte> bitmask = BitConverter::IsLittleEndian ? Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)4097)) : Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)272));
  UInt32 num2 = UInt32::MaxValue;
  UInt32 num3 = UInt32::MaxValue;
  UInt32 num4 = UInt32::MaxValue;
  UInt32 num5 = UInt32::MaxValue;
  Byte* value = pBuffer;
  if (bufferLength >= num) {
    if (Sse2::in::get_IsSupported()) {
      num2 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pBuffer));
      if (!ContainsNonAsciiByte_Sse2(num2)) {
        goto IL_0092;
      }
    } else {
      if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
        rt::throw_exception<PlatformNotSupportedException>();
      }
      num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(AdvSimd::in::LoadVector128(pBuffer), bitmask);
      if (!ContainsNonAsciiByte_AdvSimd(num4)) {
        goto IL_0092;
      }
    }
    goto IL_0277;
  }
  if ((bufferLength & 8) != 0) {
    Int32 size = UIntPtr::get_Size();
    UInt64 num6 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
    if (!AllBytesInUInt64AreAscii(num6)) {
      num6 &= 9259542123273814144;
      pBuffer += (UInt64)(UIntPtr)(void*)(BitOperations::TrailingZeroCount(num6) >> 3);
      goto IL_022c;
    }
    pBuffer += 8;
  }
  if ((bufferLength & 4) != 0) {
    UInt32 value2 = Unsafe::ReadUnaligned<UInt32>(pBuffer);
    if (!AllBytesInUInt32AreAscii(value2)) {
      pBuffer += CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(value2);
      goto IL_022c;
    }
    pBuffer += 4;
  }
  if ((bufferLength & 2) != 0) {
    UInt32 value2 = Unsafe::ReadUnaligned<UInt16>(pBuffer);
    if (!AllBytesInUInt32AreAscii(value2)) {
      pBuffer += (UInt64)(UIntPtr)(void*)((Int64)(IntPtr)(void*)((Int64)(SByte)value2 >> 7) + 1);
      goto IL_022c;
    }
    pBuffer += 2;
  }
  if ((bufferLength & 1) != 0 && *pBuffer >= 0) {
    pBuffer++;
  }
  goto IL_022c;

IL_01ca:
  pBuffer += num;
  goto IL_01d0;

IL_01d0:
  if ((IntPtr)(void*)((Int64)(Byte)bufferLength & (Int64)(UInt64)uIntPtr) == (IntPtr)(Int32)0) {
    goto IL_022c;
  }
  pBuffer += (UInt64)(UIntPtr)(void*)((Int64)(IntPtr)(void*)((Int64)bufferLength & (Int64)(UInt64)uIntPtr) - (Int64)num);
  if (Sse2::in::get_IsSupported()) {
    num2 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pBuffer));
    if (!ContainsNonAsciiByte_Sse2(num2)) {
      goto IL_0226;
    }
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(AdvSimd::in::LoadVector128(pBuffer), bitmask);
    if (!ContainsNonAsciiByte_AdvSimd(num4)) {
      goto IL_0226;
    }
  }
  goto IL_0277;

IL_0092:
  if (bufferLength < 2 * num) {
    goto IL_01ca;
  }
  pBuffer = (Byte*)(void*)(UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer + (Int64)num) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)uIntPtr));
  bufferLength = (UIntPtr)((UInt64)bufferLength + (UInt64)(Int64)(UInt64)(UIntPtr)(void*)value);
  bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)(Int64)(UInt64)(UIntPtr)(void*)pBuffer);
  if (bufferLength < 2 * num) {
    goto IL_017b;
  }
  Byte* ptr = (Byte*)(void*)(UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer + (Int64)bufferLength) - (UInt64)(2 * num));
  while (true) {
    if (Sse2::in::get_IsSupported()) {
      Vector128<Byte> value3 = Sse2::in::LoadAlignedVector128(pBuffer);
      Vector128<Byte> value4 = Sse2::in::LoadAlignedVector128(pBuffer + num);
      num2 = (UInt32)Sse2::in::MoveMask(value3);
      num3 = (UInt32)Sse2::in::MoveMask(value4);
      if (ContainsNonAsciiByte_Sse2(num2 | num3)) {
        break;
      }
    } else {
      if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
        rt::throw_exception<PlatformNotSupportedException>();
      }
      Vector128<Byte> value5 = AdvSimd::in::LoadVector128(pBuffer);
      Vector128<Byte> value6 = AdvSimd::in::LoadVector128(pBuffer + num);
      num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(value5, bitmask);
      num5 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(value6, bitmask);
      if (ContainsNonAsciiByte_AdvSimd(num4) || ContainsNonAsciiByte_AdvSimd(num5)) {
        break;
      }
    }
    pBuffer += 2 * num;
    if (pBuffer <= ptr) {
      continue;
    }
    goto IL_017b;
  }
  if (Sse2::in::get_IsSupported()) {
    if (!ContainsNonAsciiByte_Sse2(num2)) {
      pBuffer += num;
      num2 = num3;
    }
  } else {
    if (!AdvSimd::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    if (!ContainsNonAsciiByte_AdvSimd(num4)) {
      pBuffer += num;
      num4 = num5;
    }
  }
  goto IL_0277;

IL_017b:
  if ((bufferLength & num) == 0) {
    goto IL_01d0;
  }
  if (Sse2::in::get_IsSupported()) {
    num2 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadAlignedVector128(pBuffer));
    if (!ContainsNonAsciiByte_Sse2(num2)) {
      goto IL_01ca;
    }
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(AdvSimd::in::LoadVector128(pBuffer), bitmask);
    if (!ContainsNonAsciiByte_AdvSimd(num4)) {
      goto IL_01ca;
    }
  }
  goto IL_0277;

IL_0226:
  pBuffer += num;
  goto IL_022c;

IL_022c:
  return (UIntPtr)((UInt64)(Int64)(UInt64)(UIntPtr)(void*)pBuffer - (UInt64)(Int64)(UInt64)(UIntPtr)(void*)value);

IL_0277:
  if (Sse2::in::get_IsSupported()) {
    pBuffer += (UInt32)BitOperations::TrailingZeroCount(num2);
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    pBuffer += num4;
  }
  goto IL_022c;
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar(Char* pBuffer, UIntPtr bufferLength) {
  if (!Sse2::in::get_IsSupported()) {
    return GetIndexOfFirstNonAsciiChar_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonAsciiChar_Sse2(pBuffer, bufferLength);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar_Default(Char* pBuffer, UIntPtr bufferLength) {
  Char* value = pBuffer;
  if (Vector<>::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<UInt16>::get_Count())) {
    UInt32 count = (UInt32)Vector<UInt16>::get_Count();
    UInt32 count2 = (UInt32)Vector<Byte>::get_Count();
    Vector<UInt16> right = Vector<UInt16>(127);
    if (Vector<>::LessThanOrEqualAll(Unsafe::ReadUnaligned<Vector<UInt16>>(pBuffer), right)) {
      Char* ptr = pBuffer + bufferLength - count;
      pBuffer = (Char*)(void*)(UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer + (Int64)count2) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)(count2 - 1)));
      while (!Vector<>::GreaterThanAny(Unsafe::Read<Vector<UInt16>>(pBuffer), right)) {
        pBuffer += count;
        if (pBuffer > ptr) {
          break;
        }
      }
      bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)(Int64)(IntPtr)(void*)((UInt64)(UIntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer - (Int64)(UInt64)(UIntPtr)(void*)value) / 2));
    }
  }
  while (true) {
    UInt32 num;
    if (bufferLength >= 4) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      UInt32 num2 = Unsafe::ReadUnaligned<UInt32>(pBuffer + 2);
      if (!AllCharsInUInt32AreAscii(num | num2)) {
        if (AllCharsInUInt32AreAscii(num)) {
          num = num2;
          pBuffer += 2;
        }
        goto IL_0127;
      }
      pBuffer += 4;
      bufferLength -= 4;
      continue;
    }
    if ((bufferLength & 2) != 0) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      if (!AllCharsInUInt32AreAscii(num)) {
        goto IL_0127;
      }
      pBuffer += 2;
    }
    if ((bufferLength & 1) != 0 && *pBuffer <= '') {
      pBuffer++;
    }
    break;

  IL_0127:
    if (FirstCharInUInt32IsAscii(num)) {
      pBuffer++;
    }
    break;
  }
  UIntPtr uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)(UIntPtr)(void*)pBuffer - (UInt64)(Int64)(UInt64)(UIntPtr)(void*)value);
  return (UIntPtr)((UInt64)uIntPtr / 2);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar_Sse2(Char* pBuffer, UIntPtr bufferLength) {
  if (bufferLength == 0) {
    return 0u;
  }
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UInt32 num2 = num / 2u;
  Char* value = pBuffer;
  Vector128<UInt16> right;
  Vector128<UInt16> right2;
  Vector128<UInt16> left;
  UInt32 num3;
  if (bufferLength >= num2) {
    right = Vector128<>::Create((UInt16)(Int32)65408);
    right2 = Vector128<>::Create((UInt16)(Int32)32640);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
    if ((num3 & 43690) == 0) {
      bufferLength = (UIntPtr)((UInt64)bufferLength << 1);
      if (bufferLength < 2 * num) {
        goto IL_015c;
      }
      pBuffer = (Char*)(void*)(UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer + (Int64)num) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)(num - 1)));
      bufferLength = (UIntPtr)((UInt64)bufferLength + (UInt64)(Int64)(UInt64)(UIntPtr)(void*)value);
      bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)(Int64)(UInt64)(UIntPtr)(void*)pBuffer);
      if (bufferLength < 2 * num) {
        goto IL_0118;
      }
      Char* ptr = (Char*)(void*)(UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer + (Int64)bufferLength) - (UInt64)(2 * num));
      Vector128<UInt16> vector;
      while (true) {
        left = Sse2::in::LoadAlignedVector128((UInt16*)pBuffer);
        vector = Sse2::in::LoadAlignedVector128((UInt16*)(pBuffer + num2));
        Vector128<UInt16> left2 = Sse2::in::Or(left, vector);
        if (Sse41::in::get_IsSupported()) {
          if (!Sse41::in::TestZ(left2, right)) {
            break;
          }
        } else {
          num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left2, right2)));
          if ((num3 & 43690) != 0) {
            break;
          }
        }
        pBuffer += 2 * num2;
        if (pBuffer <= ptr) {
          continue;
        }
        goto IL_0118;
      }
      if (Sse41::in::get_IsSupported()) {
        if (!Sse41::in::TestZ(left, right)) {
          goto IL_020e;
        }
      } else {
        num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
        if ((num3 & 43690) != 0) {
          goto IL_0222;
        }
      }
      pBuffer += num2;
      left = vector;
      goto IL_020e;
    }
    goto IL_0222;
  }
  if ((bufferLength & 4) != 0) {
    Int32 size = UIntPtr::get_Size();
    UInt64 num4 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
    if (!AllCharsInUInt64AreAscii(num4)) {
      num4 &= 18410996206198128512;
      pBuffer = (Char*)((Byte*)pBuffer + (UInt64)(UIntPtr)(void*)((Int64)(BitOperations::TrailingZeroCount(num4) >> 3) & (Int64)(IntPtr)(void*)(~1)));
      goto IL_01bf;
    }
    pBuffer += 4;
  }
  if ((bufferLength & 2) != 0) {
    UInt32 value2 = Unsafe::ReadUnaligned<UInt32>(pBuffer);
    if (!AllCharsInUInt32AreAscii(value2)) {
      if (FirstCharInUInt32IsAscii(value2)) {
        pBuffer++;
      }
      goto IL_01bf;
    }
    pBuffer += 2;
  }
  if ((bufferLength & 1) != 0 && *pBuffer <= '') {
    pBuffer++;
  }
  goto IL_01bf;

IL_015c:
  pBuffer += num2;
  goto IL_0166;

IL_01bf:
  return (UIntPtr)((UInt64)(UIntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pBuffer - (Int64)(UInt64)(UIntPtr)(void*)value) / 2);

IL_0222:
  num3 &= 43690;
  pBuffer = (Char*)((Byte*)pBuffer + (UInt32)BitOperations::TrailingZeroCount(num3) - 1);
  goto IL_01bf;

IL_0118:
  if ((bufferLength & num) != 0) {
    left = Sse2::in::LoadAlignedVector128((UInt16*)pBuffer);
    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(left, right)) {
        goto IL_020e;
      }
    } else {
      num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
      if ((num3 & 43690) != 0) {
        goto IL_0222;
      }
    }
    goto IL_015c;
  }
  goto IL_0166;

IL_0166:
  if (((Byte)bufferLength & (num - 1)) != 0) {
    pBuffer = (Char*)((Byte*)pBuffer + (bufferLength & (num - 1)) - num);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(left, right)) {
        goto IL_020e;
      }
    } else {
      num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
      if ((num3 & 43690) != 0) {
        goto IL_0222;
      }
    }
    pBuffer += num2;
  }
  goto IL_01bf;

IL_020e:
  num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
  goto IL_0222;
}

void ASCIIUtility::NarrowFourUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt64 value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Int16> vector = Vector128<>::AsInt16(Sse2::in::X64::in::ConvertScalarToVector128UInt64(value));
    Vector128<UInt32> value2 = Vector128<>::AsUInt32(Sse2::in::PackUnsignedSaturate(vector, vector));
    Unsafe::WriteUnaligned(outputBuffer, Sse2::in::ConvertToUInt32(value2));
  } else if (AdvSimd::in::get_IsSupported()) {
    Vector128<Int16> value3 = Vector128<>::AsInt16(Vector128<>::CreateScalarUnsafe(value));
    Vector64<Byte> vector2 = AdvSimd::in::ExtractNarrowingSaturateUnsignedLower(value3);
    Unsafe::WriteUnaligned(outputBuffer, Vector64<>::ToScalar(Vector64<>::AsUInt32(vector2)));
  } else if (BitConverter::IsLittleEndian) {
    outputBuffer = (Byte)value;
    value >>= 16;
    Unsafe::Add(outputBuffer, 1) = (Byte)value;
    value >>= 16;
    Unsafe::Add(outputBuffer, 2) = (Byte)value;
    value >>= 16;
    Unsafe::Add(outputBuffer, 3) = (Byte)value;
  } else {
    Unsafe::Add(outputBuffer, 3) = (Byte)value;
    value >>= 16;
    Unsafe::Add(outputBuffer, 2) = (Byte)value;
    value >>= 16;
    Unsafe::Add(outputBuffer, 1) = (Byte)value;
    value >>= 16;
    outputBuffer = (Byte)value;
  }


}

void ASCIIUtility::NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    outputBuffer = (Byte)value;
    Unsafe::Add(outputBuffer, 1) = (Byte)(value >> 16);
  } else {
    Unsafe::Add(outputBuffer, 1) = (Byte)value;
    outputBuffer = (Byte)(value >> 16);
  }
}

UIntPtr ASCIIUtility::NarrowUtf16ToAscii(Char* pUtf16Buffer, Byte* pAsciiBuffer, UIntPtr elementCount) {
  UIntPtr uIntPtr = (UIntPtr)(void*)nullptr;
  UInt32 num = 0u;
  UInt32 num2 = 0u;
  UInt64 num3 = 0;
  if (Sse2::in::get_IsSupported()) {
    if (elementCount >= (UInt32)(2 * Unsafe::SizeOf<Vector128<Byte>>())) {
      Int32 size = IntPtr::get_Size();
      num3 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreAscii(num3)) {
        goto IL_018b;
      }
      uIntPtr = NarrowUtf16ToAscii_Sse2(pUtf16Buffer, pAsciiBuffer, elementCount);
    }
  } else if (Vector<>::get_IsHardwareAccelerated()) {
    UInt32 num4 = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= 2 * num4) {
      Int32 size2 = IntPtr::get_Size();
      num3 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreAscii(num3)) {
        goto IL_018b;
      }
      Vector<UInt16> right = Vector<UInt16>(127);
      UIntPtr uIntPtr2 = elementCount - 2 * num4;
      do {
        Vector<UInt16> vector = Unsafe::ReadUnaligned<Vector<UInt16>>(pUtf16Buffer + (UInt64)uIntPtr);
        Vector<UInt16> vector2 = Unsafe::ReadUnaligned<Vector<UInt16>>(pUtf16Buffer + (UInt64)uIntPtr + Vector<UInt16>::get_Count());
        if (Vector<>::GreaterThanAny(Vector<>::BitwiseOr(vector, vector2), right)) {
          break;
        }
        Vector<Byte> value = Vector<>::Narrow(vector, vector2);
        Unsafe::WriteUnaligned(pAsciiBuffer + (UInt64)uIntPtr, value);
        uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)num4);
      } while ((UInt64)uIntPtr <= (UInt64)uIntPtr2)
    }
  }

  UIntPtr uIntPtr3 = (UIntPtr)(void*)((UInt64)elementCount - (UInt64)(Int64)(UInt64)uIntPtr);
  if ((UInt64)uIntPtr3 < 4) {
    goto IL_0137;
  }
  UIntPtr uIntPtr4 = (UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)uIntPtr + (Int64)(UInt64)uIntPtr3) - 4);
  while (true) {
    Int32 size3 = IntPtr::get_Size();
    num3 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer + (UInt64)uIntPtr);
    if (!AllCharsInUInt64AreAscii(num3)) {
      break;
    }
    NarrowFourUtf16CharsToAsciiAndWriteToBuffer(*(pAsciiBuffer + (UInt64)uIntPtr), num3);
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 4);
    if ((UInt64)uIntPtr <= (UInt64)uIntPtr4) {
      continue;
    }
    goto IL_0137;
  }
  goto IL_018b;

IL_018b:
  Int32 size4 = IntPtr::get_Size();
  num = (UInt32)((!BitConverter::IsLittleEndian) ? (num3 >> 32) : num3);
  if (AllCharsInUInt32AreAscii(num)) {
    NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(*(pAsciiBuffer + (UInt64)uIntPtr), num);
    num = (UInt32)((!BitConverter::IsLittleEndian) ? num3 : (num3 >> 32));
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 2);
  }
  goto IL_01cf;

IL_0189:
  return uIntPtr;

IL_01cf:
  if (FirstCharInUInt32IsAscii(num)) {
    if (!BitConverter::IsLittleEndian) {
      num >>= 16;
    }
    *(pAsciiBuffer + (UInt64)uIntPtr) = (Byte)num;
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
  }
  goto IL_0189;

IL_0137:
  if (((Int32)(UInt64)uIntPtr3 & 2) != 0) {
    num = Unsafe::ReadUnaligned<UInt32>(pUtf16Buffer + (UInt64)uIntPtr);
    if (!AllCharsInUInt32AreAscii(num)) {
      goto IL_01cf;
    }
    NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(*(pAsciiBuffer + (UInt64)uIntPtr), num);
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 2);
  }
  if (((Int32)(UInt64)uIntPtr3 & 1) != 0) {
    num = *(pUtf16Buffer + (UInt64)uIntPtr);
    if (num <= 127) {
      *(pAsciiBuffer + (UInt64)uIntPtr) = (Byte)num;
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
    }
  }
  goto IL_0189;
}

UIntPtr ASCIIUtility::NarrowUtf16ToAscii_Sse2(Char* pUtf16Buffer, Byte* pAsciiBuffer, UIntPtr elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr uIntPtr = (UIntPtr)(num - 1);
  Vector128<Int16> right = Vector128<>::Create((Int16)(Int32)(-128));
  Vector128<UInt16> right2 = Vector128<>::Create((UInt16)(Int32)32640);
  Vector128<Int16> vector = Sse2::in::LoadVector128((Int16*)pUtf16Buffer);
  if (Sse41::in::get_IsSupported()) {
    if (!Sse41::in::TestZ(vector, right)) {
      return 0u;
    }
  } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) != 0) {
    return 0u;
  }

  Vector128<Byte> vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
  Sse2::in::StoreScalar((UInt64*)pAsciiBuffer, Vector128<>::AsUInt64(vector2));
  UIntPtr uIntPtr2 = (UIntPtr)(num / 2u);
  if (((UInt32)(Int32)pAsciiBuffer & (num / 2u)) != 0) {
    goto IL_00e7;
  }
  vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + (UInt64)uIntPtr2));
  if (Sse41::in::get_IsSupported()) {
    if (Sse41::in::TestZ(vector, right)) {
      goto IL_00ca;
    }
  } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) == 0) {
    goto IL_00ca;
  }

  goto IL_0188;

IL_0188:
  return uIntPtr2;

IL_00e7:
  uIntPtr2 = (UIntPtr)(void*)((UInt64)num - (UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)pAsciiBuffer & (Int64)(UInt64)uIntPtr));
  UIntPtr uIntPtr3 = elementCount - num;
  do {
    vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + (UInt64)uIntPtr2));
    Vector128<Int16> right3 = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + (UInt64)uIntPtr2 + num / 2u));
    Vector128<Int16> vector3 = Sse2::in::Or(vector, right3);
    if (Sse41::in::get_IsSupported()) {
      if (Sse41::in::TestZ(vector3, right)) {
        goto IL_0160;
      }
    } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector3), right2))) & 43690) == 0) {
      goto IL_0160;
    }

    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(vector, right)) {
        break;
      }
    } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) != 0) {
      break;
    }

    vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
    Sse2::in::StoreScalar((UInt64*)(pAsciiBuffer + (UInt64)uIntPtr2), Vector128<>::AsUInt64(vector2));
    uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(num / 2u));
    break;

  IL_0160:
    vector2 = Sse2::in::PackUnsignedSaturate(vector, right3);
    Sse2::in::StoreAligned(pAsciiBuffer + (UInt64)uIntPtr2, vector2);
    uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)num);
  } while ((UInt64)uIntPtr2 <= (UInt64)uIntPtr3)
  goto IL_0188;

IL_00ca:
  vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
  Sse2::in::StoreScalar((UInt64*)(pAsciiBuffer + (UInt64)uIntPtr2), Vector128<>::AsUInt64(vector2));
  goto IL_00e7;
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UIntPtr uIntPtr = (UIntPtr)(void*)nullptr;
  if (BitConverter::IsLittleEndian && (Sse2::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported())) {
    if (elementCount >= (UInt32)(2 * Unsafe::SizeOf<Vector128<Byte>>())) {
      uIntPtr = WidenAsciiToUtf16_Intrinsified(pAsciiBuffer, pUtf16Buffer, elementCount);
    }
  } else if (Vector<>::get_IsHardwareAccelerated()) {
    UInt32 num = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= num) {
      UIntPtr uIntPtr2 = elementCount - num;
      do {
        Vector<SByte> vector = Unsafe::ReadUnaligned<Vector<SByte>>(pAsciiBuffer + (UInt64)uIntPtr);
        if (Vector<>::LessThanAny(vector, Vector<SByte>::get_Zero())) {
          break;
        }
        Vector<UInt16> low;
        Vector<UInt16> high;
        Vector<>::Widen(Vector<>::AsVectorByte(vector), low, high);
        Unsafe::WriteUnaligned(pUtf16Buffer + (UInt64)uIntPtr, low);
        Unsafe::WriteUnaligned(pUtf16Buffer + (UInt64)uIntPtr + Vector<UInt16>::get_Count(), high);
        uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)num);
      } while ((UInt64)uIntPtr <= (UInt64)uIntPtr2)
    }
  }

  UIntPtr uIntPtr3 = (UIntPtr)(void*)((UInt64)elementCount - (UInt64)(Int64)(UInt64)uIntPtr);
  if ((UInt64)uIntPtr3 < 4) {
    goto IL_00e0;
  }
  UIntPtr uIntPtr4 = (UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt64)uIntPtr + (Int64)(UInt64)uIntPtr3) - 4);
  UInt32 num2;
  while (true) {
    num2 = Unsafe::ReadUnaligned<UInt32>(pAsciiBuffer + (UInt64)uIntPtr);
    if (!AllBytesInUInt32AreAscii(num2)) {
      break;
    }
    WidenFourAsciiBytesToUtf16AndWriteToBuffer(*(pUtf16Buffer + (UInt64)uIntPtr), num2);
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 4);
    if ((UInt64)uIntPtr <= (UInt64)uIntPtr4) {
      continue;
    }
    goto IL_00e0;
  }
  goto IL_0178;

IL_0163:
  return uIntPtr;

IL_00e0:
  if (((Int32)(UInt64)uIntPtr3 & 2) != 0) {
    num2 = Unsafe::ReadUnaligned<UInt16>(pAsciiBuffer + (UInt64)uIntPtr);
    if (!AllBytesInUInt32AreAscii(num2)) {
      goto IL_0178;
    }
    if (BitConverter::IsLittleEndian) {
      *(pUtf16Buffer + (UInt64)uIntPtr) = (Char)(Byte)num2;
      *(pUtf16Buffer + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr + 1)) = (Char)(num2 >> 8);
    } else {
      *(pUtf16Buffer + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr + 1)) = (Char)(Byte)num2;
      *(pUtf16Buffer + (UInt64)uIntPtr) = (Char)(num2 >> 8);
    }
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 2);
  }
  if (((Int32)(UInt64)uIntPtr3 & 1) != 0) {
    num2 = *(pAsciiBuffer + (UInt64)uIntPtr);
    if (((Byte)num2 & 128) == 0) {
      *(pUtf16Buffer + (UInt64)uIntPtr) = (Char)num2;
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
    }
  }
  goto IL_0163;

IL_0178:
  while (((Byte)num2 & 128) == 0) {
    *(pUtf16Buffer + (UInt64)uIntPtr) = (Char)(Byte)num2;
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
    num2 >>= 8;
  }
  goto IL_0163;
}

Boolean ASCIIUtility::ContainsNonAsciiByte(Vector128<Byte> value) {
  if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
    rt::throw_exception<PlatformNotSupportedException>();
  }
  value = AdvSimd::in::Arm64::in::MaxPairwise(value, value);
  return ((Int64)Vector128<>::ToScalar(Vector128<>::AsUInt64(value)) & -9187201950435737472) != 0;
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16_Intrinsified(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr uIntPtr = (UIntPtr)(num - 1);
  Vector128<Byte> vector;
  Boolean flag;
  if (Sse2::in::get_IsSupported()) {
    vector = Sse2::in::LoadVector128(pAsciiBuffer);
    flag = (Sse2::in::MoveMask(vector) != 0);
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    vector = AdvSimd::in::LoadVector128(pAsciiBuffer);
    flag = ContainsNonAsciiByte(vector);
  }
  if (flag) {
    return 0u;
  }
  Vector128<Byte> zero = Vector128<Byte>::get_Zero();
  if (Sse2::in::get_IsSupported()) {
    Vector128<Byte> source = Sse2::in::UnpackLow(vector, zero);
    Sse2::in::Store((Byte*)pUtf16Buffer, source);
  } else {
    if (!AdvSimd::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    Vector128<Byte> source = Vector128<>::AsByte(AdvSimd::in::ZeroExtendWideningLower(Vector128<>::GetLower(vector)));
    AdvSimd::in::Store((Byte*)pUtf16Buffer, source);
  }
  UIntPtr uIntPtr2 = (UIntPtr)(void*)((UInt64)(num >> 1) - (UInt64)(Int64)(IntPtr)(void*)((Int64)(IntPtr)(void*)((UInt64)(UIntPtr)(void*)pUtf16Buffer >> 1) & (Int64)(IntPtr)(void*)((UInt64)uIntPtr >> 1)));
  UIntPtr uIntPtr3 = elementCount - num;
  Char* ptr = pUtf16Buffer + (UInt64)uIntPtr2;
  while (true) {
    if (Sse2::in::get_IsSupported()) {
      vector = Sse2::in::LoadVector128(pAsciiBuffer + (UInt64)uIntPtr2);
      flag = (Sse2::in::MoveMask(vector) != 0);
    } else {
      if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
        rt::throw_exception<PlatformNotSupportedException>();
      }
      vector = AdvSimd::in::LoadVector128(pAsciiBuffer + (UInt64)uIntPtr2);
      flag = ContainsNonAsciiByte(vector);
    }
    if (!flag) {
      if (Sse2::in::get_IsSupported()) {
        Vector128<Byte> source2 = Sse2::in::UnpackLow(vector, zero);
        Sse2::in::StoreAligned((Byte*)ptr, source2);
        Vector128<Byte> source3 = Sse2::in::UnpackHigh(vector, zero);
        Sse2::in::StoreAligned((Byte*)ptr + num, source3);
      } else {
        if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
          rt::throw_exception<PlatformNotSupportedException>();
        }
        Vector128<UInt16> value = AdvSimd::in::ZeroExtendWideningLower(Vector128<>::GetLower(vector));
        Vector128<UInt16> value2 = AdvSimd::in::ZeroExtendWideningUpper(vector);
        AdvSimd::in::Arm64::in::StorePair((UInt16*)ptr, value, value2);
      }
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)num);
      ptr += num;
      if ((UInt64)uIntPtr2 <= (UInt64)uIntPtr3) {
        continue;
      }
    } else if (!flag) {
      if (Sse2::in::get_IsSupported()) {
        Vector128<Byte> source = Sse2::in::UnpackLow(vector, zero);
        Sse2::in::StoreAligned((Byte*)(pUtf16Buffer + (UInt64)uIntPtr2), source);
      } else {
        if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
          break;
        }
        Vector128<UInt16> source4 = AdvSimd::in::ZeroExtendWideningLower(Vector128<>::GetLower(vector));
        AdvSimd::in::Store((UInt16*)(pUtf16Buffer + (UInt64)uIntPtr2), source4);
      }
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(num / 2u));
    }

    return uIntPtr2;
  }
  rt::throw_exception<PlatformNotSupportedException>();
}

void ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(Char& outputBuffer, UInt32 value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Byte> left = Vector128<>::AsByte(Sse2::in::ConvertScalarToVector128UInt32(value));
    Vector128<UInt64> value2 = Vector128<>::AsUInt64(Sse2::in::UnpackLow(left, Vector128<Byte>::get_Zero()));
    Unsafe::WriteUnaligned(Unsafe::As<Char, Byte>(outputBuffer), Sse2::in::X64::in::ConvertToUInt64(value2));
  } else if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    Vector128<Byte> left2 = Vector128<>::AsByte(AdvSimd::in::DuplicateToVector128(value));
    Vector128<UInt64> vector = Vector128<>::AsUInt64(AdvSimd::in::Arm64::in::ZipLow(left2, Vector128<Byte>::get_Zero()));
    Unsafe::WriteUnaligned(Unsafe::As<Char, Byte>(outputBuffer), Vector128<>::ToScalar(vector));
  } else if (BitConverter::IsLittleEndian) {
    outputBuffer = (Char)(Byte)value;
    value >>= 8;
    Unsafe::Add(outputBuffer, 1) = (Char)(Byte)value;
    value >>= 8;
    Unsafe::Add(outputBuffer, 2) = (Char)(Byte)value;
    value >>= 8;
    Unsafe::Add(outputBuffer, 3) = (Char)value;
  } else {
    Unsafe::Add(outputBuffer, 3) = (Char)(Byte)value;
    value >>= 8;
    Unsafe::Add(outputBuffer, 2) = (Char)(Byte)value;
    value >>= 8;
    Unsafe::Add(outputBuffer, 1) = (Char)(Byte)value;
    value >>= 8;
    outputBuffer = (Char)value;
  }


}

Boolean ASCIIUtility::AllBytesInUInt32AreAscii(UInt32 value) {
  return ((Int32)value & -2139062144) == 0;
}

UInt32 ASCIIUtility::CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return (UInt32)BitOperations::TrailingZeroCount(value & 2155905152u) >> 3;
  }
  value = ~value;
  value = BitOperations::RotateLeft(value, 1);
  UInt32 num = value & 1;
  UInt32 num2 = num;
  value = BitOperations::RotateLeft(value, 8);
  num &= value;
  num2 += num;
  value = BitOperations::RotateLeft(value, 8);
  num &= value;
  return num2 + num;
}

} // namespace System::Private::CoreLib::System::Text::ASCIIUtilityNamespace
