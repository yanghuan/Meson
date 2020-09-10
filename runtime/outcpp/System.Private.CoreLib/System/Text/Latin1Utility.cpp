#include "Latin1Utility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Bmi1-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse41-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::Latin1UtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::X86;

UInt64 Latin1Utility::GetIndexOfFirstNonLatin1Char(Char* pBuffer, UInt64 bufferLength) {
  if (!Sse2::in::get_IsSupported()) {
    return GetIndexOfFirstNonLatin1Char_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonLatin1Char_Sse2(pBuffer, bufferLength);
}

UInt64 Latin1Utility::GetIndexOfFirstNonLatin1Char_Default(Char* pBuffer, UInt64 bufferLength) {
  Char* ptr = pBuffer;
  if (Vector<>::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<UInt16>::get_Count())) {
    UInt32 count = (UInt32)Vector<UInt16>::get_Count();
    UInt32 count2 = (UInt32)Vector<Byte>::get_Count();
    Vector<UInt16> right = Vector<UInt16>(255);
    if (Vector<>::LessThanOrEqualAll(Unsafe::ReadUnaligned<Vector<UInt16>>(pBuffer), right)) {
      Char* ptr2 = pBuffer + bufferLength - count;
      pBuffer = (Char*)((UInt64)((Int64)pBuffer + (Int64)count2) & ~(UInt64)(count2 - 1));
      while (!Vector<>::GreaterThanAny(Unsafe::Read<Vector<UInt16>>(pBuffer), right)) {
        pBuffer += count;
        if (pBuffer > ptr2) {
          break;
        }
      }
      bufferLength -= (UInt64)(pBuffer - ptr) / 2;
    }
  }
  while (true) {
    UInt32 num;
    if (bufferLength >= 4) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      UInt32 num2 = Unsafe::ReadUnaligned<UInt32>(pBuffer + 2);
      if (!AllCharsInUInt32AreLatin1(num | num2)) {
        if (AllCharsInUInt32AreLatin1(num)) {
          num = num2;
          pBuffer += 2;
        }
        goto IL_0114;
      }
      pBuffer += 4;
      bufferLength -= 4;
      continue;
    }
    if ((bufferLength & 2) != 0) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      if (!AllCharsInUInt32AreLatin1(num)) {
        goto IL_0114;
      }
      pBuffer += 2;
    }
    if ((bufferLength & 1) != 0 && *pBuffer <= 'ÿ') {
      pBuffer++;
    }
    break;

  IL_0114:
    if (FirstCharInUInt32IsLatin1(num)) {
      pBuffer++;
    }
    break;
  }
  UInt64 num3 = (UInt64)(pBuffer - ptr);
  return num3 / 2;
}

UInt64 Latin1Utility::GetIndexOfFirstNonLatin1Char_Sse2(Char* pBuffer, UInt64 bufferLength) {
  if (bufferLength == 0) {
    return 0;
  }
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UInt32 num2 = num / 2u;
  Char* ptr = pBuffer;
  Vector128<UInt16> right;
  Vector128<UInt16> right2;
  Vector128<UInt16> left;
  UInt32 num3;
  if (bufferLength >= num2) {
    right = Vector128<>::Create((UInt16)(Int32)65280);
    right2 = Vector128<>::Create((UInt16)(Int32)32512);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
    if ((num3 & 43690) == 0) {
      bufferLength <<= 1;
      if (bufferLength < 2 * num) {
        goto IL_0144;
      }
      pBuffer = (Char*)((UInt64)((Int64)pBuffer + (Int64)num) & ~(UInt64)(num - 1));
      bufferLength += (UInt64)ptr;
      bufferLength -= (UInt64)pBuffer;
      if (bufferLength < 2 * num) {
        goto IL_0100;
      }
      Char* ptr2 = (Char*)((Int64)pBuffer + (Int64)bufferLength - 2 * num);
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
        if (pBuffer <= ptr2) {
          continue;
        }
        goto IL_0100;
      }
      if (Sse41::in::get_IsSupported()) {
        if (!Sse41::in::TestZ(left, right)) {
          goto IL_01ed;
        }
      } else {
        num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
        if ((num3 & 43690) != 0) {
          goto IL_0201;
        }
      }
      pBuffer += num2;
      left = vector;
      goto IL_01ed;
    }
    goto IL_0201;
  }
  UInt32 num5;
  if ((bufferLength & 4) != 0) {
    if (Bmi1::in::X64::in::get_IsSupported()) {
      UInt64 num4 = Unsafe::ReadUnaligned<UInt64>(pBuffer);
      if (!AllCharsInUInt64AreLatin1(num4)) {
        num4 &= 18374966859414961920;
        pBuffer = (Char*)((Byte*)pBuffer + ((Int64)(Bmi1::in::X64::in::TrailingZeroCount(num4) / 8) & -2));
        goto IL_01a6;
      }
    } else {
      num5 = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      UInt32 num6 = Unsafe::ReadUnaligned<UInt32>(pBuffer + 2);
      if (!AllCharsInUInt32AreLatin1(num5 | num6)) {
        if (AllCharsInUInt32AreLatin1(num5)) {
          num5 = num6;
          pBuffer += 2;
        }
        goto IL_021b;
      }
    }
    pBuffer += 4;
  }
  if ((bufferLength & 2) != 0) {
    num5 = Unsafe::ReadUnaligned<UInt32>(pBuffer);
    if (!AllCharsInUInt32AreLatin1(num5)) {
      goto IL_021b;
    }
    pBuffer += 2;
  }
  if ((bufferLength & 1) != 0 && *pBuffer <= 'ÿ') {
    pBuffer++;
  }
  goto IL_01a6;

IL_01a6:
  return (UInt64)(pBuffer - ptr) / 2;

IL_014e:
  if (((Byte)bufferLength & (num - 1)) != 0) {
    pBuffer = (Char*)((Byte*)pBuffer + (bufferLength & (num - 1)) - num);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(left, right)) {
        goto IL_01ed;
      }
    } else {
      num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
      if ((num3 & 43690) != 0) {
        goto IL_0201;
      }
    }
    pBuffer += num2;
  }
  goto IL_01a6;

IL_021b:
  if (FirstCharInUInt32IsLatin1(num5)) {
    pBuffer++;
  }
  goto IL_01a6;

IL_0201:
  num3 &= 43690;
  pBuffer = (Char*)((Byte*)pBuffer + (UInt32)BitOperations::TrailingZeroCount(num3) - 1);
  goto IL_01a6;

IL_0144:
  pBuffer += num2;
  goto IL_014e;

IL_01ed:
  num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
  goto IL_0201;

IL_0100:
  if ((bufferLength & num) != 0) {
    left = Sse2::in::LoadAlignedVector128((UInt16*)pBuffer);
    if (Sse41::in::get_IsSupported()) {
      if (!Sse41::in::TestZ(left, right)) {
        goto IL_01ed;
      }
    } else {
      num3 = (UInt32)Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(left, right2)));
      if ((num3 & 43690) != 0) {
        goto IL_0201;
      }
    }
    goto IL_0144;
  }
  goto IL_014e;
}

UInt64 Latin1Utility::NarrowUtf16ToLatin1(Char* pUtf16Buffer, Byte* pLatin1Buffer, UInt64 elementCount) {
  UInt64 num = 0;
  UInt32 num2 = 0u;
  UInt32 num3 = 0u;
  UInt64 num4 = 0;
  if (Sse2::in::get_IsSupported()) {
    if (elementCount >= (UInt32)(2 * Unsafe::SizeOf<Vector128<Byte>>())) {
      Int32 size = IntPtr::get_Size();
      num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreLatin1(num4)) {
        goto IL_0186;
      }
      num = NarrowUtf16ToLatin1_Sse2(pUtf16Buffer, pLatin1Buffer, elementCount);
    }
  } else if (Vector<>::get_IsHardwareAccelerated()) {
    UInt32 num5 = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= 2 * num5) {
      Int32 size2 = IntPtr::get_Size();
      num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreLatin1(num4)) {
        goto IL_0186;
      }
      Vector<UInt16> right = Vector<UInt16>(255);
      UInt64 num6 = elementCount - 2 * num5;
      do {
        Vector<UInt16> vector = Unsafe::ReadUnaligned<Vector<UInt16>>(pUtf16Buffer + num);
        Vector<UInt16> vector2 = Unsafe::ReadUnaligned<Vector<UInt16>>(pUtf16Buffer + num + Vector<UInt16>::get_Count());
        if (Vector<>::GreaterThanAny(Vector<>::BitwiseOr(vector, vector2), right)) {
          break;
        }
        Vector<Byte> value = Vector<>::Narrow(vector, vector2);
        Unsafe::WriteUnaligned(pLatin1Buffer + num, value);
        num += num5;
      } while (num <= num6)
    }
  }

  UInt64 num7 = elementCount - num;
  if (num7 < 4) {
    goto IL_0132;
  }
  UInt64 num8 = num + num7 - 4;
  while (true) {
    Int32 size3 = IntPtr::get_Size();
    num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer + num);
    if (!AllCharsInUInt64AreLatin1(num4)) {
      break;
    }
    NarrowFourUtf16CharsToLatin1AndWriteToBuffer(*(pLatin1Buffer + num), num4);
    num += 4;
    if (num <= num8) {
      continue;
    }
    goto IL_0132;
  }
  goto IL_0186;

IL_0186:
  Int32 size4 = IntPtr::get_Size();
  num2 = (UInt32)((!BitConverter::IsLittleEndian) ? (num4 >> 32) : num4);
  if (AllCharsInUInt32AreLatin1(num2)) {
    NarrowTwoUtf16CharsToLatin1AndWriteToBuffer(*(pLatin1Buffer + num), num2);
    num2 = (UInt32)((!BitConverter::IsLittleEndian) ? num4 : (num4 >> 32));
    num += 2;
  }
  goto IL_01c9;

IL_0184:
  return num;

IL_01c9:
  if (FirstCharInUInt32IsLatin1(num2)) {
    if (!BitConverter::IsLittleEndian) {
      num2 >>= 16;
    }
    *(pLatin1Buffer + num) = (Byte)num2;
    num++;
  }
  goto IL_0184;

IL_0132:
  if (((Int32)num7 & 2) != 0) {
    num2 = Unsafe::ReadUnaligned<UInt32>(pUtf16Buffer + num);
    if (!AllCharsInUInt32AreLatin1(num2)) {
      goto IL_01c9;
    }
    NarrowTwoUtf16CharsToLatin1AndWriteToBuffer(*(pLatin1Buffer + num), num2);
    num += 2;
  }
  if (((Int32)num7 & 1) != 0) {
    num2 = *(pUtf16Buffer + num);
    if (num2 <= 255) {
      *(pLatin1Buffer + num) = (Byte)num2;
      num++;
    }
  }
  goto IL_0184;
}

UInt64 Latin1Utility::NarrowUtf16ToLatin1_Sse2(Char* pUtf16Buffer, Byte* pLatin1Buffer, UInt64 elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UInt64 num2 = num - 1;
  Vector128<Int16> right = Vector128<>::Create((Int16)(Int32)(-256));
  Vector128<UInt16> right2 = Vector128<>::Create((UInt16)(Int32)32512);
  Vector128<Int16> vector = Sse2::in::LoadVector128((Int16*)pUtf16Buffer);
  if (Sse41::in::get_IsSupported()) {
    if (!Sse41::in::TestZ(vector, right)) {
      return 0;
    }
  } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) != 0) {
    return 0;
  }

  Vector128<Byte> vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
  Sse2::in::StoreScalar((UInt64*)pLatin1Buffer, Vector128<>::AsUInt64(vector2));
  UInt64 num3 = num / 2u;
  if (((UInt32)(Int32)pLatin1Buffer & (num / 2u)) != 0) {
    goto IL_00e8;
  }
  vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + num3));
  if (Sse41::in::get_IsSupported()) {
    if (Sse41::in::TestZ(vector, right)) {
      goto IL_00cc;
    }
  } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) == 0) {
    goto IL_00cc;
  }

  goto IL_0182;

IL_0182:
  return num3;

IL_00e8:
  num3 = (UInt64)(num - ((Int64)pLatin1Buffer & (Int64)num2));
  UInt64 num4 = elementCount - num;
  do {
    vector = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + num3));
    Vector128<Int16> right3 = Sse2::in::LoadVector128((Int16*)(pUtf16Buffer + num3 + num / 2u));
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
    } else if ((Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::AddSaturate(Vector128<>::AsUInt16(vector), right2))) & 43690) != 0) {
      break;
    }

    vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
    Sse2::in::StoreScalar((UInt64*)(pLatin1Buffer + num3), Vector128<>::AsUInt64(vector2));
    num3 += num / 2u;
    break;

  IL_015b:
    vector2 = Sse2::in::PackUnsignedSaturate(vector, right3);
    Sse2::in::StoreAligned(pLatin1Buffer + num3, vector2);
    num3 += num;
  } while (num3 <= num4)
  goto IL_0182;

IL_00cc:
  vector2 = Sse2::in::PackUnsignedSaturate(vector, vector);
  Sse2::in::StoreScalar((UInt64*)(pLatin1Buffer + num3), Vector128<>::AsUInt64(vector2));
  goto IL_00e8;
}

void Latin1Utility::WidenLatin1ToUtf16(Byte* pLatin1Buffer, Char* pUtf16Buffer, UInt64 elementCount) {
  if (Sse2::in::get_IsSupported()) {
    WidenLatin1ToUtf16_Sse2(pLatin1Buffer, pUtf16Buffer, elementCount);
  } else {
    WidenLatin1ToUtf16_Fallback(pLatin1Buffer, pUtf16Buffer, elementCount);
  }
}

void Latin1Utility::WidenLatin1ToUtf16_Sse2(Byte* pLatin1Buffer, Char* pUtf16Buffer, UInt64 elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UInt64 num2 = num - 1;
  UInt64 num3 = 0;
  Vector128<Byte> zero = Vector128<Byte>::get_Zero();
  if (elementCount >= num) {
    Vector128<Byte> left = Vector128<>::AsByte(Sse2::in::LoadScalarVector128((UInt64*)pLatin1Buffer));
    Sse2::in::Store((Byte*)pUtf16Buffer, Sse2::in::UnpackLow(left, zero));
    num3 = (num >> 1) - (((UInt64)pUtf16Buffer >> 1) & (num2 >> 1));
    Char* ptr = pUtf16Buffer + num3;
    UInt64 num4 = elementCount - num;
    while (num3 <= num4) {
      left = Sse2::in::LoadVector128(pLatin1Buffer + num3);
      Vector128<Byte> source = Sse2::in::UnpackLow(left, zero);
      Sse2::in::StoreAligned((Byte*)ptr, source);
      Vector128<Byte> source2 = Sse2::in::UnpackHigh(left, zero);
      Sse2::in::StoreAligned((Byte*)ptr + num, source2);
      num3 += num;
      ptr += num;
    }
  }
  UInt32 num5 = (UInt32)((Int32)elementCount - (Int32)num3);
  if ((num5 & 8) != 0) {
    Vector128<Byte> left = Vector128<>::AsByte(Sse2::in::LoadScalarVector128((UInt64*)(pLatin1Buffer + num3)));
    Sse2::in::Store((Byte*)(pUtf16Buffer + num3), Sse2::in::UnpackLow(left, zero));
    num3 += 8;
  }
  if ((num5 & 4) != 0) {
    Vector128<Byte> left = Vector128<>::AsByte(Sse2::in::LoadScalarVector128((UInt32*)(pLatin1Buffer + num3)));
    Sse2::in::StoreScalar((UInt64*)(pUtf16Buffer + num3), Vector128<>::AsUInt64(Sse2::in::UnpackLow(left, zero)));
    num3 += 4;
  }
  if ((num5 & 3) == 0) {
    return;
  }
  *(pUtf16Buffer + num3) = (Char)*(pLatin1Buffer + num3);
  if ((num5 & 2) != 0) {
    *(pUtf16Buffer + num3 + 1) = (Char)*(pLatin1Buffer + num3 + 1);
    if ((num5 & 1) != 0) {
      *(pUtf16Buffer + num3 + 2) = (Char)*(pLatin1Buffer + num3 + 2);
    }
  }
}

void Latin1Utility::WidenLatin1ToUtf16_Fallback(Byte* pLatin1Buffer, Char* pUtf16Buffer, UInt64 elementCount) {
  UInt64 num = 0;
  if (Vector<>::get_IsHardwareAccelerated()) {
    UInt32 count = (UInt32)Vector<Byte>::get_Count();
    if (elementCount >= count) {
      UInt64 num2 = elementCount - count;
      do {
        Vector<Byte> value = Unsafe::ReadUnaligned<Vector<Byte>>(pLatin1Buffer + num);
        Vector<UInt16> low;
        Vector<UInt16> high;
        Vector<>::Widen(Vector<>::AsVectorByte(value), low, high);
        Unsafe::WriteUnaligned(pUtf16Buffer + num, low);
        Unsafe::WriteUnaligned(pUtf16Buffer + num + Vector<UInt16>::get_Count(), high);
        num += count;
      } while (num <= num2)
    }
  }
  for (; num < elementCount; num++) {
    *(pUtf16Buffer + num) = (Char)*(pLatin1Buffer + num);
  }
}

Boolean Latin1Utility::AllCharsInUInt32AreLatin1(UInt32 value) {
  return ((Int32)value & -16711936) == 0;
}

Boolean Latin1Utility::AllCharsInUInt64AreLatin1(UInt64 value) {
  return ((Int64)value & -71777214294589696) == 0;
}

Boolean Latin1Utility::FirstCharInUInt32IsLatin1(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 65280) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return ((Int32)value & -16777216) == 0;
    }
    return false;
  }
  return true;
}

void Latin1Utility::NarrowFourUtf16CharsToLatin1AndWriteToBuffer(Byte& outputBuffer, UInt64 value) {
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

void Latin1Utility::NarrowTwoUtf16CharsToLatin1AndWriteToBuffer(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    outputBuffer = (Byte)value;
    Unsafe::Add(outputBuffer, 1) = (Byte)(value >> 16);
  } else {
    Unsafe::Add(outputBuffer, 1) = (Byte)value;
    outputBuffer = (Byte)(value >> 16);
  }
}

} // namespace System::Private::CoreLib::System::Text::Latin1UtilityNamespace
