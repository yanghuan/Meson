#include "Utf8Utility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIUtility-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers::Binary;
using namespace System::Numerics;

UInt32 Utf8Utility::ExtractCharFromFirstThreeByteSequence(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return ((value & 4128768) >> 16) | ((value & 16128) >> 2) | ((value & 15) << 12);
  }
  return ((value & 251658240) >> 12) | ((value & 4128768) >> 10) | ((value & 16128) >> 8);
}

UInt32 Utf8Utility::ExtractCharFromFirstTwoByteSequence(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (UInt32)((Byte)value << 6);
    return (Byte)(value >> 8) + num - 12288 - 128;
  }
  return (UInt16)(((value & 520093696) >> 18) | ((value & 4128768) >> 16));
}

UInt32 Utf8Utility::ExtractCharsFromFourByteSequence(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (UInt32)((Byte)value << 8);
    num |= (value & 16128) >> 6;
    num |= (value & 3145728) >> 20;
    num |= (value & 1056964608) >> 8;
    num |= (value & 983040) << 6;
    num -= 64;
    num -= 8192;
    num += 2048;
    return num + 3690987520u;
  }
  UInt32 num2 = value & 4278190080u;
  num2 |= (value & 4128768) << 2;
  num2 |= (value & 12288) << 4;
  num2 |= (value & 3840) >> 2;
  num2 |= (value & 63);
  num2 -= 536870912;
  num2 -= 4194304;
  num2 += 56320;
  return num2 + 134217728;
}

UInt32 Utf8Utility::ExtractFourUtf8BytesFromSurrogatePair(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    value += 64;
    UInt32 value2 = BinaryPrimitives::ReverseEndianness(value & 4130560);
    value2 = BitOperations::RotateLeft(value2, 16);
    UInt32 num = (value & 252) << 6;
    UInt32 num2 = (value >> 6) & 983040;
    num2 |= num;
    UInt32 num3 = (value & 3) << 20;
    num3 |= 2155905264u;
    return num3 | value2 | num2;
  }
  value -= 3623934976u;
  value += 4194304;
  UInt32 num4 = value & 117440512;
  UInt32 num5 = (value >> 2) & 4128768;
  num5 |= num4;
  UInt32 num6 = (value << 2) & 3840;
  UInt32 num7 = (value >> 6) & 196608;
  num7 |= num6;
  UInt32 num8 = (value & 63) + 4034953344u;
  return num8 | num5 | num7;
}

UInt32 Utf8Utility::ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return ((value & 1056980736) >> 8) | ((value & 2031647) << 6);
  }
  return ((value & 520101632) >> 2) | (value & 4128831);
}

UInt32 Utf8Utility::ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return ((value >> 6) & 2031647) + ((value << 8) & 1056980736) + 2160099520u;
  }
  return ((value << 2) & 520101632) + (value & 4128831) + 3229663360u;
}

UInt32 Utf8Utility::ExtractUtf8TwoByteSequenceFromFirstUtf16Char(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (value << 2) & 7936;
    value &= 63;
    return BinaryPrimitives::ReverseEndianness((UInt16)(num + value + 49280));
  }
  UInt32 num2 = (value >> 16) & 63;
  value = ((value >> 22) & 7936);
  return value + num2 + 49280;
}

Boolean Utf8Utility::IsFirstCharAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 65408) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return value < 8388608;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsFirstCharAtLeastThreeUtf8Bytes(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 63488) == 0) {
    if (!BitConverter::IsLittleEndian) {
      return value >= 134217728;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsFirstCharSurrogate(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 55296) & 63488) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (UInt32)((Int32)value - -671088640) < 134217728u;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsFirstCharTwoUtf8Bytes(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 128) & 65535) >= 1920) {
    if (!BitConverter::IsLittleEndian) {
      return UnicodeUtility::IsInRangeInclusive(value, 8388608u, 134217727u);
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsLowByteUtf8ContinuationByte(UInt32 value) {
  return (UInt32)(Byte)(value - 128) <= 63u;
}

Boolean Utf8Utility::IsSecondCharAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || value >= 8388608) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 65408) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsSecondCharAtLeastThreeUtf8Bytes(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((Int32)value & -134217728) == 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 63488) != 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsSecondCharSurrogate(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (UInt32)((Int32)value - -671088640) >= 134217728u) {
    if (!BitConverter::IsLittleEndian) {
      return ((value - 55296) & 63488) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsSecondCharTwoUtf8Bytes(UInt32 value) {
  if (!BitConverter::IsLittleEndian || !UnicodeUtility::IsInRangeInclusive(value, 8388608u, 134217727u)) {
    if (!BitConverter::IsLittleEndian) {
      return ((value - 128) & 65535) < 1920;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsUtf8ContinuationByte(Byte& value) {
  return (SByte)value < -64;
}

Boolean Utf8Utility::IsWellFormedUtf16SurrogatePair(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (((Int32)value - -603924480) & -67044352) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -671032320) & -67044352) == 0;
    }
    return false;
  }
  return true;
}

UInt32 Utf8Utility::ToLittleEndian(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return value;
  }
  return BinaryPrimitives::ReverseEndianness(value);
}

Boolean Utf8Utility::UInt32BeginsWithOverlongUtf8TwoByteSequence(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (UInt32)(Byte)value >= 194u) {
    if (!BitConverter::IsLittleEndian) {
      return value < 3254779904u;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithUtf8FourByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (((Int32)value - -2139062032) & -1061109512) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -260014080) & -121585472) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithUtf8ThreeByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 8421600) & 12632304) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -528449536) & -255803392) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithUtf8TwoByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 32960) & 49376) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -1065353216) & -524288000) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32EndsWithOverlongUtf8TwoByteSequence(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 1966080) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 7680) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32EndsWithUtf8TwoByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (((Int32)value - -2134900736) & -1059061760) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return ((value - 49280) & 57536) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
  if (!BitConverter::IsLittleEndian || !UnicodeUtility::IsInRangeInclusive(value & 49407, 32962u, 32991u)) {
    if (!BitConverter::IsLittleEndian) {
      return false;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
  if (!BitConverter::IsLittleEndian || !UnicodeUtility::IsInRangeInclusive(value & 3237937152u, 2160197632u, 2162098176u)) {
    if (!BitConverter::IsLittleEndian) {
      return false;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32FirstByteIsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 128) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (Int32)value >= 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32FourthByteIsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (Int32)value < 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 128) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32SecondByteIsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 32768) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 8388608) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32ThirdByteIsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 8388608) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 32768) == 0;
    }
    return false;
  }
  return true;
}

void Utf8Utility::WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = ((value << 2) & 16128) | ((value & 63) << 16);
    UInt32 num2 = ((value >> 4) & 251658240) | ((value >> 12) & 15);
    Unsafe::WriteUnaligned(outputBuffer, num + num2 + 3766517984u);
    Unsafe::WriteUnaligned(Unsafe::Add(outputBuffer, 4), (UInt16)(((value >> 22) & 63) + ((value >> 8) & 16128) + 32896));
  } else {
    Unsafe::Add(outputBuffer, 5) = (Byte)((value & 63) | 128);
    Unsafe::Add(outputBuffer, 4) = (Byte)(((value >>= 6) & 63) | 128);
    Unsafe::Add(outputBuffer, 3) = (Byte)(((value >>= 6) & 15) | 224);
    Unsafe::Add(outputBuffer, 2) = (Byte)(((value >>= 4) & 63) | 128);
    Unsafe::Add(outputBuffer, 1) = (Byte)(((value >>= 6) & 63) | 128);
    outputBuffer = (Byte)((value >>= 6) | 224);
  }
}

void Utf8Utility::WriteFirstUtf16CharAsUtf8ThreeByteSequence(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (value << 2) & 16128;
    UInt32 num2 = (UInt32)(UInt16)value >> 12;
    Unsafe::WriteUnaligned(outputBuffer, (UInt16)(num + num2 + 32992));
    Unsafe::Add(outputBuffer, 2) = (Byte)((value & 63) | 4294967168u);
  } else {
    Unsafe::Add(outputBuffer, 2) = (Byte)(((value >>= 16) & 63) | 128);
    Unsafe::Add(outputBuffer, 1) = (Byte)(((value >>= 6) & 63) | 128);
    outputBuffer = (Byte)((value >>= 6) | 224);
  }
}

OperationStatus Utf8Utility::TranscodeToUtf16(Byte* pInputBuffer, Int32 inputLength, Char* pOutputBuffer, Int32 outputCharsRemaining, Byte*& pInputBufferRemaining, Char*& pOutputBufferRemaining) {
  UIntPtr num = ASCIIUtility::WidenAsciiToUtf16(pInputBuffer, pOutputBuffer, (UInt32)Math::Min(inputLength, outputCharsRemaining));
  pInputBuffer += num;
  pOutputBuffer += num;
  if ((Int32)num == inputLength) {
    pInputBufferRemaining = pInputBuffer;
    pOutputBufferRemaining = pOutputBuffer;
    return OperationStatus::Done;
  }
  inputLength -= (Int32)num;
  outputCharsRemaining -= (Int32)num;
  if (inputLength < 4) {
  }
  Byte* ptr = pInputBuffer + (UInt32)inputLength - 4;
  while (true) {
  }
}

OperationStatus Utf8Utility::TranscodeToUtf8(Char* pInputBuffer, Int32 inputLength, Byte* pOutputBuffer, Int32 outputBytesRemaining, Char*& pInputBufferRemaining, Byte*& pOutputBufferRemaining) {
  UIntPtr num = ASCIIUtility::NarrowUtf16ToAscii(pInputBuffer, pOutputBuffer, (UInt32)Math::Min(inputLength, outputBytesRemaining));
  pInputBuffer += num;
  pOutputBuffer += num;
  if ((Int32)num == inputLength) {
    pInputBufferRemaining = pInputBuffer;
    pOutputBufferRemaining = pOutputBuffer;
    return OperationStatus::Done;
  }
  inputLength -= (Int32)num;
  outputBytesRemaining -= (Int32)num;
  if (inputLength < 2) {
  }
  Char* ptr = pInputBuffer + (UInt32)inputLength - 2;
}

Byte* Utf8Utility::GetPointerToFirstInvalidByte(Byte* pInputBuffer, Int32 inputLength, Int32& utf16CodeUnitCountAdjustment, Int32& scalarCountAdjustment) {
  UIntPtr indexOfFirstNonAsciiByte = ASCIIUtility::GetIndexOfFirstNonAsciiByte(pInputBuffer, (UInt32)inputLength);
  pInputBuffer += indexOfFirstNonAsciiByte;
  inputLength -= (Int32)indexOfFirstNonAsciiByte;
  if (inputLength == 0) {
    utf16CodeUnitCountAdjustment = 0;
    scalarCountAdjustment = 0;
    return pInputBuffer;
  }
  Int32 num = 0;
  Int32 num2 = 0;
  Byte* ptr;
  if (inputLength >= 4) {
    ptr = pInputBuffer + (UInt32)inputLength - 4;
    while (pInputBuffer <= ptr) {
      UInt32 num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
      while (true) {
      }
    }
  }
  UIntPtr num7 = (UInt32)inputLength;
}

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace
