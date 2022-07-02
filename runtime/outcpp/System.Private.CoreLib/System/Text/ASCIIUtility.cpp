#include "ASCIIUtility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
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
  return (value & 9259542123273814144) == 0;
}

Boolean ASCIIUtility::AllCharsInUInt32AreAscii(UInt32 value) {
  return (value & 4286644096u) == 0;
}

Boolean ASCIIUtility::AllCharsInUInt64AreAscii(UInt64 value) {
  return (value & 18410996206198128512) == 0;
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
  if (!BitConverter::IsLittleEndian || (value & 65408u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 4286578688u) == 0;
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
  Byte* ptr = pBuffer;
  if (Vector<>::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<SByte>::get_Count())) {
    UInt32 count = (UInt32)Vector<SByte>::get_Count();
    if (Vector<>::GreaterThanOrEqualAll(Unsafe::ReadUnaligned<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
      Byte* ptr2 = pBuffer + bufferLength - count;
      pBuffer = (Byte*)((UInt64)(pBuffer + count) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)(count - 1)));
      while (!Vector<>::LessThanAny(Unsafe::Read<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
        pBuffer += count;
        if (pBuffer > ptr2) {
          break;
        }
      }
      bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)pBuffer);
      bufferLength = (UIntPtr)(bufferLength + ptr);
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
        goto IL_00f9;
      }
      pBuffer += 8;
      bufferLength -= 8;
      continue;
    }
    if ((bufferLength & 4) != 0) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      if (!AllBytesInUInt32AreAscii(num)) {
        goto IL_00f9;
      }
      pBuffer += 4;
    }
    if ((bufferLength & 2) != 0) {
      num = Unsafe::ReadUnaligned<UInt16>(pBuffer);
      if (!AllBytesInUInt32AreAscii(num)) {
        goto IL_00f9;
      }
      pBuffer += 2;
    }
    if ((bufferLength & 1) != 0 && *pBuffer >= 0) {
      pBuffer++;
    }
    break;

  IL_00f9:
    pBuffer += CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(num);
    break;
  }
  return (UIntPtr)(pBuffer - (UInt64)ptr);
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
  Vector128<Byte> bitmask = (BitConverter::IsLittleEndian ? Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)4097)) : Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)272)));
  UInt32 num2 = UInt32::MaxValue();
  UInt32 num3 = UInt32::MaxValue();
  UInt32 num4 = UInt32::MaxValue();
  UInt32 num5 = UInt32::MaxValue();
  Byte* ptr = pBuffer;
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
    goto IL_024f;
  }
  if ((bufferLength & 8) != 0) {
    Int32 size = UIntPtr::get_Size();
    UInt64 num6 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
    if (!AllBytesInUInt64AreAscii(num6)) {
      num6 &= 9259542123273814144;
      pBuffer += (UInt64)(UIntPtr)(void*)(BitOperations::TrailingZeroCount(num6) >> 3);
      goto IL_020e;
    }
    pBuffer += 8;
  }
  if ((bufferLength & 4) != 0) {
    UInt32 value = Unsafe::ReadUnaligned<UInt32>(pBuffer);
    if (!AllBytesInUInt32AreAscii(value)) {
      pBuffer += CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(value);
      goto IL_020e;
    }
    pBuffer += 4;
  }
  if ((bufferLength & 2) != 0) {
    UInt32 value = Unsafe::ReadUnaligned<UInt16>(pBuffer);
    if (!AllBytesInUInt32AreAscii(value)) {
      pBuffer += (UInt64)(UIntPtr)(void*)((Int64)(IntPtr)(void*)((Int64)(SByte)value >> 7) + 1);
      goto IL_020e;
    }
    pBuffer += 2;
  }
  if ((bufferLength & 1) != 0 && *pBuffer >= 0) {
    pBuffer++;
  }
  goto IL_020e;

IL_01ac:
  pBuffer += num;
  goto IL_01b2;

IL_01b2:
  if ((UIntPtr)(void*)((UInt64)(Byte)bufferLength & (UInt64)(Int64)(UInt64)uIntPtr) == (UIntPtr)(void*)(void*)nullptr) {
    goto IL_020e;
  }
  pBuffer += (UInt64)(UIntPtr)(void*)((Int64)(IntPtr)(void*)((UInt64)bufferLength & (UInt64)(Int64)(UInt64)uIntPtr) - (Int64)num);
  if (Sse2::in::get_IsSupported()) {
    num2 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pBuffer));
    if (!ContainsNonAsciiByte_Sse2(num2)) {
      goto IL_0208;
    }
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(AdvSimd::in::LoadVector128(pBuffer), bitmask);
    if (!ContainsNonAsciiByte_AdvSimd(num4)) {
      goto IL_0208;
    }
  }
  goto IL_024f;

IL_0092:
  if (bufferLength < 2 * num) {
    goto IL_01ac;
  }
  pBuffer = (Byte*)((UInt64)(pBuffer + num) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)uIntPtr));
  bufferLength = (UIntPtr)(bufferLength + ptr);
  bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)pBuffer);
  if (bufferLength < 2 * num) {
    goto IL_015d;
  }
  Byte* ptr2 = pBuffer + bufferLength - 2 * num;
  while (true) {
    if (Sse2::in::get_IsSupported()) {
      Vector128<Byte> value2 = Sse2::in::LoadAlignedVector128(pBuffer);
      Vector128<Byte> value3 = Sse2::in::LoadAlignedVector128(pBuffer + num);
      num2 = (UInt32)Sse2::in::MoveMask(value2);
      num3 = (UInt32)Sse2::in::MoveMask(value3);
      if (ContainsNonAsciiByte_Sse2(num2 | num3)) {
        break;
      }
    } else {
      if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
        rt::throw_exception<PlatformNotSupportedException>();
      }
      Vector128<Byte> value4 = AdvSimd::in::LoadVector128(pBuffer);
      Vector128<Byte> value5 = AdvSimd::in::LoadVector128(pBuffer + num);
      num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(value4, bitmask);
      num5 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(value5, bitmask);
      if (ContainsNonAsciiByte_AdvSimd(num4) || ContainsNonAsciiByte_AdvSimd(num5)) {
        break;
      }
    }
    pBuffer += 2 * num;
    if (pBuffer <= ptr2) {
      continue;
    }
    goto IL_015d;
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
  goto IL_024f;

IL_015d:
  if ((bufferLength & num) == 0) {
    goto IL_01b2;
  }
  if (Sse2::in::get_IsSupported()) {
    num2 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadAlignedVector128(pBuffer));
    if (!ContainsNonAsciiByte_Sse2(num2)) {
      goto IL_01ac;
    }
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    num4 = (UInt32)GetIndexOfFirstNonAsciiByteInLane_AdvSimd(AdvSimd::in::LoadVector128(pBuffer), bitmask);
    if (!ContainsNonAsciiByte_AdvSimd(num4)) {
      goto IL_01ac;
    }
  }
  goto IL_024f;

IL_0208:
  pBuffer += num;
  goto IL_020e;

IL_020e:
  return (UIntPtr)(pBuffer - (UInt64)ptr);

IL_024f:
  if (Sse2::in::get_IsSupported()) {
    pBuffer += (UInt32)BitOperations::TrailingZeroCount(num2);
  } else {
    if (!AdvSimd::in::Arm64::in::get_IsSupported()) {
      rt::throw_exception<PlatformNotSupportedException>();
    }
    pBuffer += num4;
  }
  goto IL_020e;
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar(Char* pBuffer, UIntPtr bufferLength) {
  if (!Sse2::in::get_IsSupported()) {
    return GetIndexOfFirstNonAsciiChar_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonAsciiChar_Sse2(pBuffer, bufferLength);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar_Default(Char* pBuffer, UIntPtr bufferLength) {
  Char* ptr = pBuffer;
  if (Vector<>::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<UInt16>::get_Count())) {
    UInt32 count = (UInt32)Vector<UInt16>::get_Count();
    UInt32 count2 = (UInt32)Vector<Byte>::get_Count();
    Vector<UInt16> right = Vector<UInt16>(127);
    if (Vector<>::LessThanOrEqualAll(Unsafe::ReadUnaligned<Vector<UInt16>>(pBuffer), right)) {
      Char* ptr2 = pBuffer + bufferLength - count;
      pBuffer = (Char*)((UInt64)((Byte*)pBuffer + count2) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)(count2 - 1)));
      while (!Vector<>::GreaterThanAny(Unsafe::Read<Vector<UInt16>>(pBuffer), right)) {
        pBuffer += count;
        if (pBuffer > ptr2) {
          break;
        }
      }
      bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)(Int64)(IntPtr)(void*)(pBuffer - ptr));
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
        goto IL_0109;
      }
      pBuffer += 4;
      bufferLength -= 4;
      continue;
    }
    if ((bufferLength & 2) != 0) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      if (!AllCharsInUInt32AreAscii(num)) {
        goto IL_0109;
      }
      pBuffer += 2;
    }
    if ((bufferLength & 1) != 0 && *pBuffer <= u'\x007f') {
      pBuffer++;
    }
    break;

  IL_0109:
    if (FirstCharInUInt32IsAscii(num)) {
      pBuffer++;
    }
    break;
  }
  UIntPtr uIntPtr = (UIntPtr)((Byte*)pBuffer - (UInt64)ptr);
  return (UIntPtr)((UInt64)uIntPtr / 2);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar_Sse2(Char* pBuffer, UIntPtr bufferLength) {
  if (bufferLength == 0) {
    return 0u;
  }
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UInt32 num2 = num / 2u;
  Char* ptr = pBuffer;
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
        goto IL_013e;
      }
      pBuffer = (Char*)((UInt64)((Byte*)pBuffer + num) & (UInt64)(Int64)(IntPtr)(void*)(~(UInt64)(num - 1)));
      bufferLength = (UIntPtr)(bufferLength + (Byte*)ptr);
      bufferLength = (UIntPtr)((UInt64)bufferLength - (UInt64)pBuffer);
      if (bufferLength < 2 * num) {
        goto IL_00fa;
      }
      Char* ptr2 = (Char*)((Byte*)pBuffer + bufferLength - 2 * num);
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
          if ((num3 & 43690u) != 0) {
            break;
          }
        }
        pBuffer += 2 * num2;
        if (pBuffer <= ptr2) {
          continue;
        }
        goto IL_00fa;
      }
      if (Sse41::in::get_IsSupported()) {
        if (!Sse41::in::TestZ(left, right)) {
          goto IL_01e6;
        }
      } else {
        num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
        if ((num3 & 43690u) != 0) {
          goto IL_01fa;
        }
      }
      pBuffer += num2;
      left = vector;
      goto IL_01e6;
    }
    goto IL_01fa;
  }
  if ((bufferLength & 4) != 0) {
    Int32 size = UIntPtr::get_Size();
    UInt64 num4 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
    if (!AllCharsInUInt64AreAscii(num4)) {
      num4 &= 18410996206198128512;
      pBuffer = (Char*)((Byte*)pBuffer + (UInt64)(UIntPtr)(void*)((Int64)(BitOperations::TrailingZeroCount(num4) >> 3) & (Int64)(IntPtr)(void*)(~1)));
      goto IL_01a1;
    }
    pBuffer += 4;
  }
  if ((bufferLength & 2) != 0) {
    UInt32 value = Unsafe::ReadUnaligned<UInt32>(pBuffer);
    if (!AllCharsInUInt32AreAscii(value)) {
      if (FirstCharInUInt32IsAscii(value)) {
        pBuffer++;
      }
      goto IL_01a1;
    }
    pBuffer += 2;
  }
  if ((bufferLength & 1) != 0 && *pBuffer <= u'\x007f') {
    pBuffer++;
  }
  goto IL_01a1;

IL_013e:
  pBuffer += num2;
  goto IL_0148;

IL_01a1:
  return (UIntPtr)(pBuffer - ptr);

IL_01fa:
  num3 &= 43690u;
  pBuffer = (Char*)((Byte*)pBuffer + (UInt32)BitOperations::TrailingZeroCount(num3) - 1);
  goto IL_01a1;

IL_00fa:
  if ((bufferLength & num) != 0) {
    left = Sse2::in::LoadAlignedVector128((UInt16*)pBuffer);
    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(left, right)) {
        goto IL_01e6;
      }
    } else {
      num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
      if ((num3 & 43690u) != 0) {
        goto IL_01fa;
      }
    }
    goto IL_013e;
  }
  goto IL_0148;

IL_0148:
  if (((Byte)bufferLength & (num - 1)) != 0) {
    pBuffer = (Char*)((Byte*)pBuffer + (bufferLength & (num - 1)) - num);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(left, right)) {
        goto IL_01e6;
      }
    } else {
      num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
      if ((num3 & 43690u) != 0) {
        goto IL_01fa;
      }
    }
    pBuffer += num2;
  }
  goto IL_01a1;

IL_01e6:
  num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
  goto IL_01fa;
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
  UIntPtr uIntPtr = (UIntPtr)(void*)(void*)nullptr;
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
      } while ((UInt64)uIntPtr <= (UInt64)uIntPtr2);
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
  if (((UInt32)(Int32)(UInt64)uIntPtr3 & 2u) != 0) {
    num = Unsafe::ReadUnaligned<UInt32>(pUtf16Buffer + (UInt64)uIntPtr);
    if (!AllCharsInUInt32AreAscii(num)) {
      goto IL_01cf;
    }
    NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(*(pAsciiBuffer + (UInt64)uIntPtr), num);
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 2);
  }
  if (((UInt32)(Int32)(UInt64)uIntPtr3 & (true ? 1u : 0u)) != 0) {
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
  } else if (((UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690u) != 0) {
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

  goto IL_0183;

IL_0183:
  return uIntPtr2;

IL_00e7:
  uIntPtr2 = (UIntPtr)(void*)((UInt64)num - (UInt64)(Int64)(IntPtr)(void*)((UInt64)pAsciiBuffer & (UInt64)(Int64)(UInt64)uIntPtr));
  UIntPtr uIntPtr3 = elementCount - num;
  do {
    vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + (UInt64)uIntPtr2));
    Vector128<Int16> right3 = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + (UInt64)uIntPtr2 + num / 2u));
    Vector128<Int16> vector3 = Sse2::in::Or(vector, right3);
    if (Sse41::in::get_IsSupported()) {
      if (Sse41::in::TestZ(vector3, right)) {
        goto IL_015b;
      }
    } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector3), right2))) & 43690) == 0) {
      goto IL_015b;
    }

    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(vector, right)) {
        break;
      }
    } else if (((UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690u) != 0) {
      break;
    }

    vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
    Sse2::in::StoreScalar((UInt64*)(pAsciiBuffer + (UInt64)uIntPtr2), Vector128<>::AsUInt64(vector2));
    uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(num / 2u));
    break;

  IL_015b:
    vector2 = Sse2::in::PackUnsignedSaturate(vector, right3);
    Sse2::in::StoreAligned(pAsciiBuffer + (UInt64)uIntPtr2, vector2);
    uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)num);
  } while ((UInt64)uIntPtr2 <= (UInt64)uIntPtr3);
  goto IL_0183;

IL_00ca:
  vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
  Sse2::in::StoreScalar((UInt64*)(pAsciiBuffer + (UInt64)uIntPtr2), Vector128<>::AsUInt64(vector2));
  goto IL_00e7;
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UIntPtr uIntPtr = (UIntPtr)(void*)(void*)nullptr;
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
      } while ((UInt64)uIntPtr <= (UInt64)uIntPtr2);
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
  if (((UInt32)(Int32)(UInt64)uIntPtr3 & 2u) != 0) {
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
  if (((UInt32)(Int32)(UInt64)uIntPtr3 & (true ? 1u : 0u)) != 0) {
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
  return (Vector128<>::ToScalar(Vector128<>::AsUInt64(value)) & 9259542123273814144) != 0;
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16_Intrinsified(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr uIntPtr = (UIntPtr)(num - 1);
  Vector128<Byte> vector;
  Boolean flag;
  if (Sse2::in::get_IsSupported()) {
    vector = Sse2::in::LoadVector128(pAsciiBuffer);
    flag = Sse2::in::MoveMask(vector) != 0;
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
  UIntPtr uIntPtr2 = (UIntPtr)(void*)((UInt64)(num >> 1) - (UInt64)(Int64)(IntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((UInt64)pUtf16Buffer >> 1) & (UInt64)(Int64)(IntPtr)(void*)((UInt64)uIntPtr >> 1)));
  UIntPtr uIntPtr3 = elementCount - num;
  Char* ptr = pUtf16Buffer + (UInt64)uIntPtr2;
  while (true) {
    if (Sse2::in::get_IsSupported()) {
      vector = Sse2::in::LoadVector128(pAsciiBuffer + (UInt64)uIntPtr2);
      flag = Sse2::in::MoveMask(vector) != 0;
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
  return (value & 2155905152u) == 0;
}

UInt32 ASCIIUtility::CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return (UInt32)BitOperations::TrailingZeroCount(value & 2155905152u) >> 3;
  }
  value = ~value;
  value = BitOperations::RotateLeft(value, 1);
  UInt32 num = value & 1u;
  UInt32 num2 = num;
  value = BitOperations::RotateLeft(value, 8);
  num &= value;
  num2 += num;
  value = BitOperations::RotateLeft(value, 8);
  num &= value;
  return num2 + num;
}

} // namespace System::Private::CoreLib::System::Text::ASCIIUtilityNamespace
