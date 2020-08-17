#include "ASCIIUtility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse41-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Text::ASCIIUtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
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
  if (!Sse2::in::get_IsSupported()) {
    return GetIndexOfFirstNonAsciiByte_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonAsciiByte_Sse2(pBuffer, bufferLength);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte_Default(Byte* pBuffer, UIntPtr bufferLength) {
  Byte* value = pBuffer;
  if (Vector<>::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<SByte>::get_Count())) {
    UInt32 count = (UInt32)Vector<SByte>::get_Count();
    if (Vector<>::GreaterThanOrEqualAll(Unsafe::ReadUnaligned<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
      Byte* ptr = pBuffer + bufferLength - count;
      pBuffer = (Byte*)(void*)(UIntPtr)((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer + (IntPtr)count) & ~(UIntPtr)(count - 1));
      while (!Vector<>::LessThanAny(Unsafe::Read<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
        pBuffer += count;
        if (pBuffer > ptr) {
          break;
        }
      }
      bufferLength -= (UIntPtr)(IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer;
      bufferLength += (UIntPtr)(IntPtr)(UIntPtr)(UIntPtr)(void*)value;
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
  return (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer - (IntPtr)(UIntPtr)(UIntPtr)(void*)value);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte_Sse2(Byte* pBuffer, UIntPtr bufferLength) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr num2 = num - 1;
  Byte* value = pBuffer;
  UInt32 num3;
  if (bufferLength >= num) {
    num3 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pBuffer));
    if (num3 == 0) {
      if (bufferLength < 2 * num) {
        goto IL_00bf;
      }
      pBuffer = (Byte*)(void*)(UIntPtr)((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer + (IntPtr)num) & ~num2);
      bufferLength += (UIntPtr)(IntPtr)(UIntPtr)(UIntPtr)(void*)value;
      bufferLength -= (UIntPtr)(IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer;
      if (bufferLength < 2 * num) {
        goto IL_00aa;
      }
      Byte* ptr = (Byte*)(void*)(UIntPtr)((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer + (IntPtr)bufferLength) - (UIntPtr)(2 * num));
      UInt32 num4;
      while (true) {
        Vector128<Byte> value2 = Sse2::in::LoadAlignedVector128(pBuffer);
        Vector128<Byte> value3 = Sse2::in::LoadAlignedVector128(pBuffer + num);
        num3 = (UInt32)Sse2::in::MoveMask(value2);
        num4 = (UInt32)Sse2::in::MoveMask(value3);
        if ((num3 | num4) != 0) {
          break;
        }
        pBuffer += 2 * num;
        if (pBuffer <= ptr) {
          continue;
        }
        goto IL_00aa;
      }
      if (num3 == 0) {
        pBuffer += num;
        num3 = num4;
      }
    }
    goto IL_0107;
  }
  if ((bufferLength & 8) != 0) {
    _ = UIntPtr::get_Size();
    UInt64 num5 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
    if (!AllBytesInUInt64AreAscii(num5)) {
      num5 &= 9259542123273814144;
      pBuffer += (UIntPtr)(BitOperations::TrailingZeroCount(num5) >> 3);
      goto IL_00ed;
    }
    pBuffer += 8;
  }
  if ((bufferLength & 4) != 0) {
    UInt32 value4 = Unsafe::ReadUnaligned<UInt32>(pBuffer);
    if (!AllBytesInUInt32AreAscii(value4)) {
      pBuffer += CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(value4);
      goto IL_00ed;
    }
    pBuffer += 4;
  }
  if ((bufferLength & 2) != 0) {
    UInt32 value4 = Unsafe::ReadUnaligned<UInt16>(pBuffer);
    if (!AllBytesInUInt32AreAscii(value4)) {
      pBuffer += (UIntPtr)(((IntPtr)(SByte)value4 >> 7) + 1);
      goto IL_00ed;
    }
    pBuffer += 2;
  }
  if ((bufferLength & 1) != 0 && *pBuffer >= 0) {
    pBuffer++;
  }
  goto IL_00ed;

IL_00ed:
  return (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer - (IntPtr)(UIntPtr)(UIntPtr)(void*)value);

IL_0107:
  pBuffer += (UInt32)BitOperations::TrailingZeroCount(num3);
  goto IL_00ed;

IL_00aa:
  if ((bufferLength & num) == 0) {
    goto IL_00c5;
  }
  num3 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadAlignedVector128(pBuffer));
  if (num3 == 0) {
    goto IL_00bf;
  }
  goto IL_0107;

IL_00c5:
  if (((Byte)bufferLength & num2) != 0) {
    pBuffer += (bufferLength & num2) - num;
    num3 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pBuffer));
    if (num3 != 0) {
      goto IL_0107;
    }
    pBuffer += num;
  }
  goto IL_00ed;

IL_00bf:
  pBuffer += num;
  goto IL_00c5;
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
      pBuffer = (Char*)(void*)(UIntPtr)((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer + (IntPtr)count2) & ~(UIntPtr)(count2 - 1));
      while (!Vector<>::GreaterThanAny(Unsafe::Read<Vector<UInt16>>(pBuffer), right)) {
        pBuffer += count;
        if (pBuffer > ptr) {
          break;
        }
      }
      bufferLength -= (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer - (IntPtr)(UIntPtr)(UIntPtr)(void*)value) / (?)2u;
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
    if ((bufferLength & 1) != 0 && *pBuffer <= 127) {
      pBuffer++;
    }
    break;

  IL_0127:
    if (FirstCharInUInt32IsAscii(num)) {
      pBuffer++;
    }
    break;
  }
  UIntPtr num3 = (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer - (IntPtr)(UIntPtr)(UIntPtr)(void*)value);
  return num3 / (?)2u;
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
    right = Vector128<>::Create((?)65408);
    right2 = Vector128<>::Create((?)32640);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
    if ((num3 & 43690) == 0) {
      bufferLength <<= 1;
      if (bufferLength < 2 * num) {
        goto IL_015c;
      }
      pBuffer = (Char*)(void*)(UIntPtr)((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer + (IntPtr)num) & ~(UIntPtr)(num - 1));
      bufferLength += (UIntPtr)(IntPtr)(UIntPtr)(UIntPtr)(void*)value;
      bufferLength -= (UIntPtr)(IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer;
      if (bufferLength < 2 * num) {
        goto IL_0118;
      }
      Char* ptr = (Char*)(void*)(UIntPtr)((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer + (IntPtr)bufferLength) - (UIntPtr)(2 * num));
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
    _ = UIntPtr::get_Size();
    UInt64 num4 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
    if (!AllCharsInUInt64AreAscii(num4)) {
      num4 &= 18410996206198128512;
      pBuffer = (Char*)((Byte*)pBuffer + (UIntPtr)((BitOperations::TrailingZeroCount(num4) >> 3) & ~(?)1));
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
  if ((bufferLength & 1) != 0 && *pBuffer <= 127) {
    pBuffer++;
  }
  goto IL_01bf;

IL_015c:
  pBuffer += num2;
  goto IL_0166;

IL_01bf:
  return (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pBuffer - (IntPtr)(UIntPtr)(UIntPtr)(void*)value) / (?)2u;

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
  UIntPtr num = 0u;
  UInt32 num2 = 0u;
  UInt32 num3 = 0u;
  UInt64 num4 = 0;
  if (Sse2::in::get_IsSupported()) {
    if (elementCount >= (UInt32)(2 * Unsafe::SizeOf<Vector128<Byte>>())) {
      _ = IntPtr::get_Size();
      num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreAscii(num4)) {
        goto IL_018b;
      }
      num = NarrowUtf16ToAscii_Sse2(pUtf16Buffer, pAsciiBuffer, elementCount);
    }
  } else if (Vector<>::get_IsHardwareAccelerated()) {
    UInt32 num5 = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= 2 * num5) {
      _ = IntPtr::get_Size();
      num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreAscii(num4)) {
        goto IL_018b;
      }
      Vector<UInt16> right = Vector<UInt16>(127);
      UIntPtr num6 = elementCount - 2 * num5;
      do {
        Vector<UInt16> vector = Unsafe::ReadUnaligned<Vector<UInt16>>(pUtf16Buffer + num);
        Vector<UInt16> vector2 = Unsafe::ReadUnaligned<Vector<UInt16>>(pUtf16Buffer + num + Vector<UInt16>::get_Count());
        if (Vector<>::GreaterThanAny(Vector<>::BitwiseOr(vector, vector2), right)) {
          break;
        }
        Vector<Byte> value = Vector<>::Narrow(vector, vector2);
        Unsafe::WriteUnaligned(pAsciiBuffer + num, value);
        num += num5;
      } while (num <= num6)
    }
  }

  UIntPtr num7 = elementCount - num;
  if (num7 < 4) {
    goto IL_0137;
  }
  UIntPtr num8 = num + num7 - 4;
  while (true) {
    _ = IntPtr::get_Size();
    num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer + num);
    if (!AllCharsInUInt64AreAscii(num4)) {
      break;
    }
    NarrowFourUtf16CharsToAsciiAndWriteToBuffer(pAsciiBuffer[num], num4);
    num += 4;
    if (num <= num8) {
      continue;
    }
    goto IL_0137;
  }
  goto IL_018b;

IL_018b:
  _ = IntPtr::get_Size();
  num2 = (UInt32)((!BitConverter::IsLittleEndian) ? (num4 >> 32) : num4);
  if (AllCharsInUInt32AreAscii(num2)) {
    NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(pAsciiBuffer[num], num2);
    num2 = (UInt32)((!BitConverter::IsLittleEndian) ? num4 : (num4 >> 32));
    num += 2;
  }
  goto IL_01cf;

IL_0189:
  return num;

IL_01cf:
  if (FirstCharInUInt32IsAscii(num2)) {
    if (!BitConverter::IsLittleEndian) {
      num2 >>= 16;
    }
    pAsciiBuffer[num] = (Byte)num2;
    num++;
  }
  goto IL_0189;

IL_0137:
  if (((Int32)num7 & 2) != 0) {
    num2 = Unsafe::ReadUnaligned<UInt32>(pUtf16Buffer + num);
    if (!AllCharsInUInt32AreAscii(num2)) {
      goto IL_01cf;
    }
    NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(pAsciiBuffer[num], num2);
    num += 2;
  }
  if (((Int32)num7 & 1) != 0) {
    num2 = pUtf16Buffer[num];
    if (num2 <= 127) {
      pAsciiBuffer[num] = (Byte)num2;
      num++;
    }
  }
  goto IL_0189;
}

UIntPtr ASCIIUtility::NarrowUtf16ToAscii_Sse2(Char* pUtf16Buffer, Byte* pAsciiBuffer, UIntPtr elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr num2 = num - 1;
  Vector128<Int16> right = Vector128<>::Create((?)(-128));
  Vector128<UInt16> right2 = Vector128<>::Create((?)32640);
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
  UIntPtr num3 = num / 2u;
  if (((UInt32)(Int32)pAsciiBuffer & (num / 2u)) != 0) {
    goto IL_00e7;
  }
  vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + num3));
  if (Sse41::in::get_IsSupported()) {
    if (Sse41::in::TestZ(vector, right)) {
      goto IL_00ca;
    }
  } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) == 0) {
    goto IL_00ca;
  }

  goto IL_0188;

IL_0188:
  return num3;

IL_00e7:
  num3 = (UIntPtr)num - (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)pAsciiBuffer & (IntPtr)num2);
  UIntPtr num4 = elementCount - num;
  do {
    vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + num3));
    Vector128<Int16> right3 = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + num3 + num / 2u));
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
    Sse2::in::StoreScalar((UInt64*)(pAsciiBuffer + num3), Vector128<>::AsUInt64(vector2));
    num3 += num / 2u;
    break;

  IL_0160:
    vector2 = Sse2::in::PackUnsignedSaturate(vector, right3);
    Sse2::in::StoreAligned(pAsciiBuffer + num3, vector2);
    num3 += num;
  } while (num3 <= num4)
  goto IL_0188;

IL_00ca:
  vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
  Sse2::in::StoreScalar((UInt64*)(pAsciiBuffer + num3), Vector128<>::AsUInt64(vector2));
  goto IL_00e7;
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UIntPtr num = 0u;
  if (Sse2::in::get_IsSupported()) {
    if (elementCount >= (UInt32)(2 * Unsafe::SizeOf<Vector128<Byte>>())) {
      num = WidenAsciiToUtf16_Sse2(pAsciiBuffer, pUtf16Buffer, elementCount);
    }
  } else if (Vector<>::get_IsHardwareAccelerated()) {
    UInt32 num2 = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= num2) {
      UIntPtr num3 = elementCount - num2;
      do {
        Vector<SByte> vector = Unsafe::ReadUnaligned<Vector<SByte>>(pAsciiBuffer + num);
        if (Vector<>::LessThanAny(vector, Vector<SByte>::get_Zero())) {
          break;
        }
        Vector<UInt16> low;
        Vector<UInt16> high;
        Vector<>::Widen(Vector<>::AsVectorByte(vector), low, high);
        Unsafe::WriteUnaligned(pUtf16Buffer + num, low);
        Unsafe::WriteUnaligned(pUtf16Buffer + num + Vector<UInt16>::get_Count(), high);
        num += num2;
      } while (num <= num3)
    }
  }

  UIntPtr num4 = elementCount - num;
  if (num4 < 4) {
    goto IL_00d2;
  }
  UIntPtr num5 = num + num4 - 4;
  UInt32 num6;
  while (true) {
    num6 = Unsafe::ReadUnaligned<UInt32>(pAsciiBuffer + num);
    if (!AllBytesInUInt32AreAscii(num6)) {
      break;
    }
    WidenFourAsciiBytesToUtf16AndWriteToBuffer(pUtf16Buffer[num], num6);
    num += 4;
    if (num <= num5) {
      continue;
    }
    goto IL_00d2;
  }
  goto IL_016a;

IL_016a:
  while (((Byte)num6 & 128) == 0) {
    pUtf16Buffer[num] = (Char)(Byte)num6;
    num++;
    num6 >>= 8;
  }
  goto IL_0155;

IL_0155:
  return num;

IL_00d2:
  if (((Int32)num4 & 2) != 0) {
    num6 = Unsafe::ReadUnaligned<UInt16>(pAsciiBuffer + num);
    if (!AllBytesInUInt32AreAscii(num6)) {
      goto IL_016a;
    }
    if (BitConverter::IsLittleEndian) {
      pUtf16Buffer[num] = (Char)(Byte)num6;
      pUtf16Buffer[num + 1] = (Char)(num6 >> 8);
    } else {
      pUtf16Buffer[num + 1] = (Char)(Byte)num6;
      pUtf16Buffer[num] = (Char)(num6 >> 8);
    }
    num += 2;
  }
  if (((Int32)num4 & 1) != 0) {
    num6 = pAsciiBuffer[num];
    if (((Byte)num6 & 128) == 0) {
      pUtf16Buffer[num] = (Char)num6;
      num++;
    }
  }
  goto IL_0155;
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16_Sse2(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr num2 = num - 1;
  Vector128<Byte> vector = Sse2::in::LoadVector128(pAsciiBuffer);
  UInt32 num3 = (UInt32)Sse2::in::MoveMask(vector);
  if ((Byte)num3 != 0) {
    return 0u;
  }
  Vector128<Byte> zero = Vector128<Byte>::get_Zero();
  Vector128<Byte> source = Sse2::in::UnpackLow(vector, zero);
  Sse2::in::Store((Byte*)pUtf16Buffer, source);
  UIntPtr num4 = (num >> 1) - (((UIntPtr)(UIntPtr)(void*)pUtf16Buffer >> 1) & (num2 >> 1));
  UIntPtr num5 = elementCount - num;
  do {
    vector = Sse2::in::LoadVector128(pAsciiBuffer + num4);
    num3 = (UInt32)Sse2::in::MoveMask(vector);
    if (num3 == 0) {
      Byte* ptr = (Byte*)(pUtf16Buffer + num4);
      Sse2::in::StoreAligned(ptr, Sse2::in::UnpackLow(vector, zero));
      ptr += num;
      Sse2::in::StoreAligned(ptr, Sse2::in::UnpackHigh(vector, zero));
      num4 += num;
      continue;
    }
    if ((Byte)num3 == 0) {
      source = Sse2::in::UnpackLow(vector, zero);
      Sse2::in::StoreAligned((Byte*)(pUtf16Buffer + num4), source);
      num4 += num / 2u;
    }
    break;
  } while (num4 <= num5)
  return num4;
}

void ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(Char& outputBuffer, UInt32 value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Byte> left = Vector128<>::AsByte(Sse2::in::ConvertScalarToVector128UInt32(value));
    Vector128<UInt64> value2 = Vector128<>::AsUInt64(Sse2::in::UnpackLow(left, Vector128<Byte>::get_Zero()));
    Unsafe::WriteUnaligned(Unsafe::As<Char, Byte>(outputBuffer), Sse2::in::X64::in::ConvertToUInt64(value2));
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
