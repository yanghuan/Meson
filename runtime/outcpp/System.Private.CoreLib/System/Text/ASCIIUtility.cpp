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
}

Boolean ASCIIUtility::AllCharsInUInt32AreAscii(UInt32 value) {
}

Boolean ASCIIUtility::AllCharsInUInt64AreAscii(UInt64 value) {
}

Boolean ASCIIUtility::FirstCharInUInt32IsAscii(UInt32 value) {
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte(Byte* pBuffer, UIntPtr bufferLength) {
  if (!Sse2::in::get_IsSupported()) {
    return GetIndexOfFirstNonAsciiByte_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonAsciiByte_Sse2(pBuffer, bufferLength);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiByte_Default(Byte* pBuffer, UIntPtr bufferLength) {
  Byte* value = pBuffer;
  if (Vector::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<SByte>::get_Count())) {
    UInt32 count = (UInt32)Vector<SByte>::get_Count();
    if (Vector::GreaterThanOrEqualAll(Unsafe::ReadUnaligned<Vector<SByte>>(pBuffer), Vector<SByte>::get_Zero())) {
      Byte* ptr = pBuffer + bufferLength - count;
    }
  }
  while (true) {
    UInt32 num;
    if (bufferLength >= 8) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      UInt32 num2 = Unsafe::ReadUnaligned<UInt32>(pBuffer + 4);
    }
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
      }
    }
  }
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar(Char* pBuffer, UIntPtr bufferLength) {
  if (!Sse2::in::get_IsSupported()) {
    return GetIndexOfFirstNonAsciiChar_Default(pBuffer, bufferLength);
  }
  return GetIndexOfFirstNonAsciiChar_Sse2(pBuffer, bufferLength);
}

UIntPtr ASCIIUtility::GetIndexOfFirstNonAsciiChar_Default(Char* pBuffer, UIntPtr bufferLength) {
  Char* value = pBuffer;
  if (Vector::get_IsHardwareAccelerated() && bufferLength >= (UInt32)(2 * Vector<UInt16>::get_Count())) {
    UInt32 count = (UInt32)Vector<UInt16>::get_Count();
    UInt32 count2 = (UInt32)Vector<Byte>::get_Count();
    Vector<UInt16> right = Vector<UInt16>(127);
    if (Vector::LessThanOrEqualAll(Unsafe::ReadUnaligned<Vector<UInt16>>(pBuffer), right)) {
      Char* ptr = pBuffer + bufferLength - count;
    }
  }
  while (true) {
    UInt32 num;
    if (bufferLength >= 4) {
      num = Unsafe::ReadUnaligned<UInt32>(pBuffer);
      UInt32 num2 = Unsafe::ReadUnaligned<UInt32>(pBuffer + 2);
    }
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
    right = Vector128::Create((?)65408);
    right2 = Vector128::Create((?)32640);
    left = Sse2::in::LoadVector128((UInt16*)pBuffer);
    num3 = (UInt32)Sse2::in::MoveMask(Vector128::AsByte(Sse2::in::AddSaturate(left, right2)));
  }
}

void ASCIIUtility::NarrowFourUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt64 value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Int16> vector = Vector128::AsInt16(Sse2::in::X64::in::ConvertScalarToVector128UInt64(value));
    Vector128<UInt32> value2 = Vector128::AsUInt32(Sse2::in::PackUnsignedSaturate(vector, vector));
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
      }
      num = NarrowUtf16ToAscii_Sse2(pUtf16Buffer, pAsciiBuffer, elementCount);
    }
  } else if (Vector::get_IsHardwareAccelerated()) {
    UInt32 num5 = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= 2 * num5) {
      _ = IntPtr::get_Size();
      num4 = Unsafe::ReadUnaligned<UInt64>(pUtf16Buffer);
      if (!AllCharsInUInt64AreAscii(num4)) {
      }
      Vector<UInt16> right = Vector<UInt16>(127);
      UIntPtr num6 = elementCount - 2 * num5;
    }
  }

  UIntPtr num7 = elementCount - num;
  if (num7 < 4) {
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
    }
  }
}

UIntPtr ASCIIUtility::NarrowUtf16ToAscii_Sse2(Char* pUtf16Buffer, Byte* pAsciiBuffer, UIntPtr elementCount) {
  UInt32 num = (UInt32)Unsafe::SizeOf<Vector128<Byte>>();
  UIntPtr num2 = num - 1;
  Vector128<Int16> right = Vector128::Create((?)(-128));
  Vector128<UInt16> right2 = Vector128::Create((?)32640);
  Vector128<Int16> vector = Sse2::in::LoadVector128((Int16*)pUtf16Buffer);
}

UIntPtr ASCIIUtility::WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount) {
  UIntPtr num = 0u;
  if (Sse2::in::get_IsSupported()) {
    if (elementCount >= (UInt32)(2 * Unsafe::SizeOf<Vector128<Byte>>())) {
      num = WidenAsciiToUtf16_Sse2(pAsciiBuffer, pUtf16Buffer, elementCount);
    }
  } else if (Vector::get_IsHardwareAccelerated()) {
    UInt32 num2 = (UInt32)Unsafe::SizeOf<Vector<Byte>>();
    if (elementCount >= num2) {
      UIntPtr num3 = elementCount - num2;
    }
  }

  UIntPtr num4 = elementCount - num;
  if (num4 < 4) {
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
    }
  }
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
}

void ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(Char& outputBuffer, UInt32 value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Byte> left = Vector128::AsByte(Sse2::in::ConvertScalarToVector128UInt32(value));
    Vector128<UInt64> value2 = Vector128::AsUInt64(Sse2::in::UnpackLow(left, Vector128<Byte>::get_Zero()));
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
}

UInt32 ASCIIUtility::CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  }
  value = ~value;
  value = BitOperations::RotateLeft(value, 1);
}

} // namespace System::Private::CoreLib::System::Text::ASCIIUtilityNamespace
