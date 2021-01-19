#include "Utf8Utility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector64-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse41-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIUtility-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf16Utility-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers::Binary;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

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
  num2 |= value & 63u;
  num2 -= 536870912;
  num2 -= 4194304;
  num2 += 56320;
  return num2 + 134217728;
}

UInt32 Utf8Utility::ExtractFourUtf8BytesFromSurrogatePair(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    value += 64;
    UInt32 value2 = BinaryPrimitives::ReverseEndianness(value & 4130560u);
    value2 = BitOperations::RotateLeft(value2, 16);
    UInt32 num = (value & 252) << 6;
    UInt32 num2 = (value >> 6) & 983040u;
    num2 |= num;
    UInt32 num3 = (value & 3) << 20;
    num3 |= 2155905264u;
    return num3 | value2 | num2;
  }
  value -= 3623934976u;
  value += 4194304;
  UInt32 num4 = value & 117440512u;
  UInt32 num5 = (value >> 2) & 4128768u;
  num5 |= num4;
  UInt32 num6 = (value << 2) & 3840u;
  UInt32 num7 = (value >> 6) & 196608u;
  num7 |= num6;
  UInt32 num8 = (value & 63) + 4034953344u;
  return num8 | num5 | num7;
}

UInt32 Utf8Utility::ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return ((value & 1056980736) >> 8) | ((value & 2031647) << 6);
  }
  return ((value & 520101632) >> 2) | (value & 4128831u);
}

UInt32 Utf8Utility::ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    return ((value >> 6) & 2031647) + ((value << 8) & 1056980736) + 2160099520u;
  }
  return ((value << 2) & 520101632) + (value & 4128831) + 3229663360u;
}

UInt32 Utf8Utility::ExtractUtf8TwoByteSequenceFromFirstUtf16Char(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (value << 2) & 7936u;
    value &= 63u;
    return BinaryPrimitives::ReverseEndianness((UInt16)(num + value + 49280));
  }
  UInt32 num2 = (value >> 16) & 63u;
  value = (value >> 22) & 7936u;
  return value + num2 + 49280;
}

Boolean Utf8Utility::IsFirstCharAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 65408u) != 0) {
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
  if (!BitConverter::IsLittleEndian || ((value - 55296) & 63488u) != 0) {
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
  if (!BitConverter::IsLittleEndian || (value & 4160749568u) == 0) {
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
  if (!BitConverter::IsLittleEndian || ((value - 3691042816u) & 4227922944u) != 0) {
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
  if (!BitConverter::IsLittleEndian || ((value - 2155905264u) & 3233857784u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -260014080) & -121585472) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithUtf8ThreeByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 8421600) & 12632304u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -528449536) & -255803392) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithUtf8TwoByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 32960) & 49376u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (((Int32)value - -1065353216) & -524288000) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32EndsWithOverlongUtf8TwoByteSequence(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 1966080u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 7680) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32EndsWithUtf8TwoByteMask(UInt32 value) {
  if (!BitConverter::IsLittleEndian || ((value - 2160066560u) & 3235905536u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return ((value - 49280) & 57536) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
  if (!BitConverter::IsLittleEndian || !UnicodeUtility::IsInRangeInclusive(value & 49407u, 32962u, 32991u)) {
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
  if (!BitConverter::IsLittleEndian || (value & 128u) != 0) {
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
  if (!BitConverter::IsLittleEndian || (value & 32768u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 8388608) == 0;
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32ThirdByteIsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (value & 8388608u) != 0) {
    if (!BitConverter::IsLittleEndian) {
      return (value & 32768) == 0;
    }
    return false;
  }
  return true;
}

void Utf8Utility::WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = ((value << 2) & 16128u) | ((value & 63) << 16);
    UInt32 num2 = ((value >> 4) & 251658240u) | ((value >> 12) & 15u);
    Unsafe::WriteUnaligned(outputBuffer, num + num2 + 3766517984u);
    Unsafe::WriteUnaligned(Unsafe::Add(outputBuffer, 4), (UInt16)(((value >> 22) & 63) + ((value >> 8) & 16128) + 32896));
  } else {
    Unsafe::Add(outputBuffer, 5) = (Byte)((value & 63u) | 128u);
    Unsafe::Add(outputBuffer, 4) = (Byte)(((value >>= 6) & 63u) | 128u);
    Unsafe::Add(outputBuffer, 3) = (Byte)(((value >>= 6) & 15u) | 224u);
    Unsafe::Add(outputBuffer, 2) = (Byte)(((value >>= 4) & 63u) | 128u);
    Unsafe::Add(outputBuffer, 1) = (Byte)(((value >>= 6) & 63u) | 128u);
    outputBuffer = (Byte)((value >>= 6) | 224u);
  }
}

void Utf8Utility::WriteFirstUtf16CharAsUtf8ThreeByteSequence(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (value << 2) & 16128u;
    UInt32 num2 = (UInt32)(UInt16)value >> 12;
    Unsafe::WriteUnaligned(outputBuffer, (UInt16)(num + num2 + 32992));
    Unsafe::Add(outputBuffer, 2) = (Byte)((value & 63u) | 4294967168u);
  } else {
    Unsafe::Add(outputBuffer, 2) = (Byte)(((value >>= 16) & 63u) | 128u);
    Unsafe::Add(outputBuffer, 1) = (Byte)(((value >>= 6) & 63u) | 128u);
    outputBuffer = (Byte)((value >>= 6) | 224u);
  }
}

OperationStatus Utf8Utility::TranscodeToUtf16(Byte* pInputBuffer, Int32 inputLength, Char* pOutputBuffer, Int32 outputCharsRemaining, Byte*& pInputBufferRemaining, Char*& pOutputBufferRemaining) {
  UIntPtr uIntPtr = ASCIIUtility::WidenAsciiToUtf16(pInputBuffer, pOutputBuffer, (UIntPtr)(UInt32)Math::Min(inputLength, outputCharsRemaining));
  pInputBuffer += (UInt64)uIntPtr;
  pOutputBuffer += (UInt64)uIntPtr;
  if ((Int32)(UInt64)uIntPtr == inputLength) {
    pInputBufferRemaining = pInputBuffer;
    pOutputBufferRemaining = pOutputBuffer;
    return OperationStatus::Done;
  }
  inputLength -= (Int32)(UInt64)uIntPtr;
  outputCharsRemaining -= (Int32)(UInt64)uIntPtr;
  if (inputLength < 4) {
    goto IL_070a;
  }
  Byte* ptr = pInputBuffer + (UInt32)inputLength - 4;
  while (true) {

  IL_004a:
    UInt32 num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
    while (true) {

    IL_0051:
      if (!ASCIIUtility::AllBytesInUInt32AreAscii(num)) {
        goto IL_0120;
      }
      Int32 num3;
      UInt32 num4;
      if (outputCharsRemaining >= 4) {
        ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(*pOutputBuffer, num);
        pInputBuffer += 4;
        pOutputBuffer += 4;
        outputCharsRemaining -= 4;
        UInt32 val = (UInt32)((Int32)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) + 4);
        UInt32 num2 = Math::Min(val, (UInt32)outputCharsRemaining) / 8u;
        num3 = 0;
        while ((UInt32)num3 < num2) {
          num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          num4 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer + 4);
          if (ASCIIUtility::AllBytesInUInt32AreAscii(num | num4)) {
            pInputBuffer += 8;
            ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(*pOutputBuffer, num);
            ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(pOutputBuffer[4], num4);
            pOutputBuffer += 8;
            num3++;
            continue;
          }
          goto IL_00f4;
        }
        outputCharsRemaining -= 8 * num3;
        goto IL_0524;
      }
      goto IL_052b;

    IL_0524:
      if (pInputBuffer <= ptr) {
        goto IL_004a;
      }
      goto IL_052b;

    IL_0120:
      if (UInt32FirstByteIsAscii(num)) {
        if (outputCharsRemaining >= 3) {
          UInt32 num5 = ToLittleEndian(num);
          UIntPtr uIntPtr2 = (UIntPtr)(void*)(Int32)1;
          *pOutputBuffer = (Char)(Byte)num5;
          if (UInt32SecondByteIsAscii(num)) {
            uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 1);
            num5 >>= 8;
            pOutputBuffer[1] = (Char)(Byte)num5;
            if (UInt32ThirdByteIsAscii(num)) {
              uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 1);
              num5 >>= 8;
              pOutputBuffer[2] = (Char)(Byte)num5;
            }
          }
          pInputBuffer += (UInt64)uIntPtr2;
          pOutputBuffer += (UInt64)uIntPtr2;
          outputCharsRemaining -= (Int32)(UInt64)uIntPtr2;
        } else {
          if (outputCharsRemaining == 0) {
            break;
          }
          UInt32 num6 = ToLittleEndian(num);
          pInputBuffer++;
          Char* intPtr = pOutputBuffer;
          pOutputBuffer = intPtr + 1;
          *intPtr = (Char)(Byte)num6;
          outputCharsRemaining--;
          if (UInt32SecondByteIsAscii(num)) {
            if (outputCharsRemaining == 0) {
              break;
            }
            pInputBuffer++;
            num6 >>= 8;
            Char* intPtr2 = pOutputBuffer;
            pOutputBuffer = intPtr2 + 1;
            *intPtr2 = (Char)(Byte)num6;
            if (UInt32ThirdByteIsAscii(num)) {
              break;
            }
            outputCharsRemaining = 0;
          }
        }
        if (pInputBuffer > ptr) {
          goto IL_052b;
        }
        num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
      }
      UInt32 num7;
      while (UInt32BeginsWithUtf8TwoByteMask(num)) {
        if (!UInt32BeginsWithOverlongUtf8TwoByteSequence(num)) {
          while ((BitConverter::IsLittleEndian && UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(num)) || (!BitConverter::IsLittleEndian && UInt32EndsWithUtf8TwoByteMask(num) && !UInt32EndsWithOverlongUtf8TwoByteSequence(num))) {
            if (outputCharsRemaining >= 2) {
              Unsafe::WriteUnaligned(pOutputBuffer, ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(num));
              pInputBuffer += 4;
              pOutputBuffer += 2;
              outputCharsRemaining -= 2;
              if (pInputBuffer <= ptr) {
                num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                if (BitConverter::IsLittleEndian) {
                  if (!UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(num)) {
                    goto IL_0051;
                  }
                  continue;
                }
                if (!UInt32BeginsWithUtf8TwoByteMask(num)) {
                  goto IL_0051;
                }
                if (!UInt32BeginsWithOverlongUtf8TwoByteSequence(num)) {
                  continue;
                }
                goto IL_071d;
              }
            }
            goto IL_052b;
          }
          num7 = ExtractCharFromFirstTwoByteSequence(num);
          if (UInt32ThirdByteIsAscii(num)) {
            if (UInt32FourthByteIsAscii(num)) {
              goto IL_02ac;
            }
            if (outputCharsRemaining >= 2) {
              *pOutputBuffer = (Char)num7;
              pOutputBuffer[1] = (Char)(Byte)(num >> (BitConverter::IsLittleEndian ? 16 : 8));
              pInputBuffer += 3;
              pOutputBuffer += 2;
              outputCharsRemaining -= 2;
              if (ptr >= pInputBuffer) {
                num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                continue;
              }
            }
          } else if (outputCharsRemaining != 0) {
            *pOutputBuffer = (Char)num7;
            pInputBuffer += 2;
            pOutputBuffer++;
            outputCharsRemaining--;
            if (ptr >= pInputBuffer) {
              num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              break;
            }
          }

          goto IL_052b;
        }
        goto IL_071d;
      }
      if (UInt32BeginsWithUtf8ThreeByteMask(num)) {
        while (true) {
          if (BitConverter::IsLittleEndian) {
            if ((num & 8207) == 0 || ((num - 8205) & 8207) == 0) {
              break;
            }
          } else if ((num & 253755392) == 0 || ((num - 220200960) & 253755392) == 0) {
            break;
          }

          if (outputCharsRemaining != 0) {
            if (BitConverter::IsLittleEndian && (((Int32)num - -536870912) & -268435456) == 0 && outputCharsRemaining > 1 && (Int64)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) >= 3) {
              UInt32 num8 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer + 3);
              if (UInt32BeginsWithUtf8ThreeByteMask(num8) && (num8 & 8207u) != 0 && ((num8 - 8205) & 8207u) != 0) {
                *pOutputBuffer = (Char)ExtractCharFromFirstThreeByteSequence(num);
                pOutputBuffer[1] = (Char)ExtractCharFromFirstThreeByteSequence(num8);
                pInputBuffer += 6;
                pOutputBuffer += 2;
                outputCharsRemaining -= 2;
                goto IL_045e;
              }
            }
            *pOutputBuffer = (Char)ExtractCharFromFirstThreeByteSequence(num);
            pInputBuffer += 3;
            pOutputBuffer++;
            outputCharsRemaining--;
            goto IL_045e;
          }
          goto IL_0719;

        IL_045e:
          if (UInt32FourthByteIsAscii(num)) {
            if (outputCharsRemaining == 0) {
              goto IL_0719;
            }
            if (BitConverter::IsLittleEndian) {
              *pOutputBuffer = (Char)(num >> 24);
            } else {
              *pOutputBuffer = (Char)(Byte)num;
            }
            pInputBuffer++;
            pOutputBuffer++;
            outputCharsRemaining--;
          }
          if (pInputBuffer <= ptr) {
            num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
            if (!UInt32BeginsWithUtf8ThreeByteMask(num)) {
              goto IL_0051;
            }
            continue;
          }
          goto IL_052b;
        }
      } else if (UInt32BeginsWithUtf8FourByteMask(num)) {
        if (BitConverter::IsLittleEndian) {
          UInt32 value = num & 65535u;
          value = BitOperations::RotateRight(value, 8);
          if (UnicodeUtility::IsInRangeInclusive(value, 4026531984u, 4093640847u)) {
            goto IL_04ff;
          }
        } else if (UnicodeUtility::IsInRangeInclusive(num, 4035969024u, 4103077887u)) {
          goto IL_04ff;
        }

      }

      goto IL_071d;

    IL_04ff:
      if (outputCharsRemaining < 2) {
        break;
      }
      Unsafe::WriteUnaligned(pOutputBuffer, ExtractCharsFromFourByteSequence(num));
      pInputBuffer += 4;
      pOutputBuffer += 2;
      outputCharsRemaining -= 2;
      goto IL_0524;

    IL_02ac:
      if (outputCharsRemaining >= 3) {
        *pOutputBuffer = (Char)num7;
        if (BitConverter::IsLittleEndian) {
          num >>= 16;
          pOutputBuffer[1] = (Char)(Byte)num;
          num >>= 8;
          pOutputBuffer[2] = (Char)num;
        } else {
          pOutputBuffer[2] = (Char)(Byte)num;
          pOutputBuffer[1] = (Char)(Byte)(num >> 8);
        }
        pInputBuffer += 4;
        pOutputBuffer += 3;
        outputCharsRemaining -= 3;
        goto IL_0524;
      }
      goto IL_052b;

    IL_00f4:
      if (ASCIIUtility::AllBytesInUInt32AreAscii(num)) {
        ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(*pOutputBuffer, num);
        num = num4;
        pInputBuffer += 4;
        pOutputBuffer += 4;
        outputCharsRemaining -= 4;
      }
      outputCharsRemaining -= 8 * num3;
      goto IL_0120;

    IL_052b:
      inputLength = (Int32)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) + 4;
      goto IL_070a;
    }
    break;
  }
  goto IL_0719;

IL_070a:
  OperationStatus result;
  while (true) {
    if (inputLength > 0) {
      UInt32 num9 = *pInputBuffer;
      if (num9 <= 127) {
        if (outputCharsRemaining != 0) {
          *pOutputBuffer = (Char)num9;
          pInputBuffer++;
          pOutputBuffer++;
          inputLength--;
          outputCharsRemaining--;
          continue;
        }
        goto IL_0719;
      }
      num9 -= 194;
      if ((UInt32)(Byte)num9 <= 29u) {
        if (inputLength < 2) {
          goto IL_0715;
        }
        UInt32 num10 = pInputBuffer[1];
        if (IsLowByteUtf8ContinuationByte(num10)) {
          if (outputCharsRemaining != 0) {
            UInt32 num11 = (num9 << 6) + num10 + 128 - 128;
            *pOutputBuffer = (Char)num11;
            pInputBuffer += 2;
            pOutputBuffer++;
            inputLength -= 2;
            outputCharsRemaining--;
            continue;
          }
          goto IL_0719;
        }
      } else if ((UInt32)(Byte)num9 <= 45u) {
        if (inputLength >= 3) {
          UInt32 num12 = pInputBuffer[1];
          UInt32 num13 = pInputBuffer[2];
          if (IsLowByteUtf8ContinuationByte(num12) && IsLowByteUtf8ContinuationByte(num13)) {
            UInt32 num14 = (num9 << 12) + (num12 << 6);
            if (num14 >= 133120) {
              num14 -= 186368;
              if (num14 >= 2048) {
                if (outputCharsRemaining != 0) {
                  num14 += num13;
                  num14 += 55296;
                  num14 -= 128;
                  *pOutputBuffer = (Char)num14;
                  pInputBuffer += 3;
                  pOutputBuffer++;
                  inputLength -= 3;
                  outputCharsRemaining--;
                  continue;
                }
                goto IL_0719;
              }
            }
          }
        } else {
          if (inputLength < 2) {
            goto IL_0715;
          }
          UInt32 num15 = pInputBuffer[1];
          if (IsLowByteUtf8ContinuationByte(num15)) {
            UInt32 num16 = (num9 << 6) + num15;
            if (num16 >= 2080 && !UnicodeUtility::IsInRangeInclusive(num16, 2912u, 2943u)) {
              goto IL_0715;
            }
          }
        }
      } else if ((UInt32)(Byte)num9 <= 50u) {
        if (inputLength < 2) {
          goto IL_0715;
        }
        UInt32 num17 = pInputBuffer[1];
        if (IsLowByteUtf8ContinuationByte(num17)) {
          UInt32 value2 = (num9 << 6) + num17;
          if (UnicodeUtility::IsInRangeInclusive(value2, 3088u, 3343u)) {
            if (inputLength < 3) {
              goto IL_0715;
            }
            if (IsLowByteUtf8ContinuationByte(pInputBuffer[2])) {
              if (inputLength < 4) {
                goto IL_0715;
              }
              if (IsLowByteUtf8ContinuationByte(pInputBuffer[3])) {
                goto IL_0719;
              }
            }
          }
        }
      }


      goto IL_071d;
    }
    result = OperationStatus::Done;
    break;

  IL_0715:
    result = OperationStatus::NeedMoreData;
    break;
  }
  goto IL_071f;

IL_071f:
  pInputBufferRemaining = pInputBuffer;
  pOutputBufferRemaining = pOutputBuffer;
  return result;

IL_0719:
  result = OperationStatus::DestinationTooSmall;
  goto IL_071f;

IL_071d:
  result = OperationStatus::InvalidData;
  goto IL_071f;
}

OperationStatus Utf8Utility::TranscodeToUtf8(Char* pInputBuffer, Int32 inputLength, Byte* pOutputBuffer, Int32 outputBytesRemaining, Char*& pInputBufferRemaining, Byte*& pOutputBufferRemaining) {
  UIntPtr uIntPtr = ASCIIUtility::NarrowUtf16ToAscii(pInputBuffer, pOutputBuffer, (UIntPtr)(UInt32)Math::Min(inputLength, outputBytesRemaining));
  pInputBuffer += (UInt64)uIntPtr;
  pOutputBuffer += (UInt64)uIntPtr;
  if ((Int32)(UInt64)uIntPtr == inputLength) {
    pInputBufferRemaining = pInputBuffer;
    pOutputBufferRemaining = pOutputBuffer;
    return OperationStatus::Done;
  }
  inputLength -= (Int32)(UInt64)uIntPtr;
  outputBytesRemaining -= (Int32)(UInt64)uIntPtr;
  if (inputLength < 2) {
    goto IL_057e;
  }
  Char* ptr = pInputBuffer + (UInt32)inputLength - 2;
  Vector128<Int16> value;
  Unsafe::SkipInit<Vector128<Int16>>(value);
  if (Sse41::in::X64::in::get_IsSupported() || (AdvSimd::in::Arm64::in::get_IsSupported() && BitConverter::IsLittleEndian)) {
    value = Vector128<>::Create((Int16)(Int32)(-128));
  }
  UInt32 num;
  while (true) {

  IL_007b:
    num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
    while (true) {

    IL_0082:
      if (!Utf16Utility::AllCharsInUInt32AreAscii(num)) {
        goto IL_0369;
      }
      if (outputBytesRemaining < 2) {
        break;
      }
      UInt32 num2 = num | (num >> 8);
      Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)num2);
      pInputBuffer += 2;
      pOutputBuffer += 2;
      outputBytesRemaining -= 2;
      UInt32 num3 = (UInt32)((Int32)(ptr - pInputBuffer) + 2);
      UInt32 num4 = (UInt32)Math::Min(num3, outputBytesRemaining);
      Int32 i;
      UInt64 num6;
      Vector128<Int16> vector;
      Int32 num8;
      UInt32 num9;
      if (Sse41::in::X64::in::get_IsSupported() || (AdvSimd::in::Arm64::in::get_IsSupported() && BitConverter::IsLittleEndian)) {
        UInt32 num5 = num4 / 8u;
        for (i = 0; (UInt32)i < num5; pInputBuffer += 8, pOutputBuffer += 8, i++) {
          vector = Unsafe::ReadUnaligned<Vector128<Int16>>(pInputBuffer);
          if (AdvSimd::in::get_IsSupported()) {
            Vector128<Int16> vector2 = AdvSimd::in::CompareTest(vector, value);
            if (Vector128<>::ToScalar(Vector128<>::AsUInt64(AdvSimd::in::Arm64::in::MinPairwise(vector2, vector2))) == 0) {
              Vector64<Byte> source = AdvSimd::in::ExtractNarrowingSaturateUnsignedLower(vector);
              AdvSimd::in::Store(pOutputBuffer, source);
              continue;
            }
          } else if (Sse41::in::TestZ(vector, value)) {
            Sse2::in::StoreScalar((UInt64*)pOutputBuffer, Vector128<>::AsUInt64(Sse2::in::PackUnsignedSaturate(vector, vector)));
            continue;
          }

          goto IL_0203;
        }
        outputBytesRemaining -= 8 * i;
        if ((num4 & 4u) != 0) {
          num6 = Unsafe::ReadUnaligned<UInt64>(pInputBuffer);
          if (!Utf16Utility::AllCharsInUInt64AreAscii(num6)) {
            goto IL_0293;
          }
          vector = Vector128<>::AsInt16(Vector128<>::CreateScalarUnsafe(num6));
          if (AdvSimd::in::get_IsSupported()) {
            Vector64<Byte> vector3 = AdvSimd::in::ExtractNarrowingSaturateUnsignedLower(vector);
            AdvSimd::in::StoreSelectedScalar((UInt32*)pOutputBuffer, Vector64<>::AsUInt32(vector3), 0);
          } else {
            Unsafe::WriteUnaligned(pOutputBuffer, Sse2::in::ConvertToUInt32(Vector128<>::AsUInt32(Sse2::in::PackUnsignedSaturate(vector, vector))));
          }
          pInputBuffer += 4;
          pOutputBuffer += 4;
          outputBytesRemaining -= 4;
        }
      } else {
        UInt32 num7 = num4 / 4u;
        num8 = 0;
        while ((UInt32)num8 < num7) {
          num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          num9 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer + 2);
          if (Utf16Utility::AllCharsInUInt32AreAscii(num | num9)) {
            Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)(num | (num >> 8)));
            Unsafe::WriteUnaligned(pOutputBuffer + 2, (UInt16)(num9 | (num9 >> 8)));
            pInputBuffer += 4;
            pOutputBuffer += 4;
            num8++;
            continue;
          }
          goto IL_0338;
        }
        outputBytesRemaining -= 4 * num8;
      }
      goto IL_056c;

    IL_0369:
      while (true) {
        if (IsFirstCharAscii(num)) {
          if (outputBytesRemaining == 0) {
            break;
          }
          if (BitConverter::IsLittleEndian) {
            *pOutputBuffer = (Byte)num;
          } else {
            *pOutputBuffer = (Byte)(num >> 24);
          }
          pInputBuffer++;
          pOutputBuffer++;
          outputBytesRemaining--;
          if (pInputBuffer > ptr) {
            goto IL_0573;
          }
          num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
        }
        if (!IsFirstCharAtLeastThreeUtf8Bytes(num)) {
          while (IsSecondCharTwoUtf8Bytes(num)) {
            if (outputBytesRemaining >= 4) {
              Unsafe::WriteUnaligned(pOutputBuffer, ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(num));
              pInputBuffer += 2;
              pOutputBuffer += 4;
              outputBytesRemaining -= 4;
              if (pInputBuffer <= ptr) {
                num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                if (!IsFirstCharTwoUtf8Bytes(num)) {
                  goto IL_0082;
                }
                continue;
              }
              goto IL_0573;
            }
            goto IL_0589;
          }
          if (outputBytesRemaining < 2) {
            break;
          }
          Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)ExtractUtf8TwoByteSequenceFromFirstUtf16Char(num));
          if (IsSecondCharAscii(num)) {
            goto IL_0417;
          }
          pInputBuffer++;
          pOutputBuffer += 2;
          outputBytesRemaining -= 2;
          if (pInputBuffer > ptr) {
            goto IL_0573;
          }
          num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
        }
        while (!IsFirstCharSurrogate(num)) {
          if (IsSecondCharAtLeastThreeUtf8Bytes(num) && !IsSecondCharSurrogate(num) && outputBytesRemaining >= 6) {
            WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(*pOutputBuffer, num);
            pInputBuffer += 2;
            pOutputBuffer += 6;
            outputBytesRemaining -= 6;
            if (pInputBuffer <= ptr) {
              num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              if (!IsFirstCharAtLeastThreeUtf8Bytes(num)) {
                goto IL_0082;
              }
              continue;
            }
            goto IL_0573;
          }
          if (outputBytesRemaining >= 3) {
            WriteFirstUtf16CharAsUtf8ThreeByteSequence(*pOutputBuffer, num);
            pInputBuffer++;
            pOutputBuffer += 3;
            outputBytesRemaining -= 3;
            if (!IsSecondCharAscii(num)) {
              goto IL_052c;
            }
            if (outputBytesRemaining != 0) {
              if (BitConverter::IsLittleEndian) {
                *pOutputBuffer = (Byte)(num >> 16);
              } else {
                *pOutputBuffer = (Byte)num;
              }
              pInputBuffer++;
              pOutputBuffer++;
              outputBytesRemaining--;
              if (pInputBuffer <= ptr) {
                num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                if (!IsFirstCharAtLeastThreeUtf8Bytes(num)) {
                  goto IL_0082;
                }
                continue;
              }
              goto IL_0573;
            }
          }
          goto IL_063b;
        }
        goto IL_053c;

      IL_052c:
        if (pInputBuffer <= ptr) {
          num = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          continue;
        }
        goto IL_0573;
      }
      goto IL_063b;

    IL_0203:
      outputBytesRemaining -= 8 * i;
      num6 = ((!Sse2::in::X64::in::get_IsSupported()) ? Vector128<>::ToScalar(Vector128<>::AsUInt64(vector)) : Sse2::in::X64::in::ConvertToUInt64(Vector128<>::AsUInt64(vector)));
      if (Utf16Utility::AllCharsInUInt64AreAscii(num6)) {
        if (AdvSimd::in::get_IsSupported()) {
          Vector64<Byte> vector4 = AdvSimd::in::ExtractNarrowingSaturateUnsignedLower(vector);
          AdvSimd::in::StoreSelectedScalar((UInt32*)pOutputBuffer, Vector64<>::AsUInt32(vector4), 0);
        } else {
          Unsafe::WriteUnaligned(pOutputBuffer, Sse2::in::ConvertToUInt32(Vector128<>::AsUInt32(Sse2::in::PackUnsignedSaturate(vector, vector))));
        }
        pInputBuffer += 4;
        pOutputBuffer += 4;
        outputBytesRemaining -= 4;
        num6 = Vector128<>::GetElement(Vector128<>::AsUInt64(vector), 1);
      }
      goto IL_0293;

    IL_0293:
      num = (UInt32)num6;
      if (Utf16Utility::AllCharsInUInt32AreAscii(num)) {
        Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)(num | (num >> 8)));
        pInputBuffer += 2;
        pOutputBuffer += 2;
        outputBytesRemaining -= 2;
        num = (UInt32)(num6 >> 32);
      }
      goto IL_0369;

    IL_0417:
      if (outputBytesRemaining >= 3) {
        if (BitConverter::IsLittleEndian) {
          num >>= 16;
        }
        pOutputBuffer[2] = (Byte)num;
        pInputBuffer += 2;
        pOutputBuffer += 3;
        outputBytesRemaining -= 3;
        goto IL_056c;
      }
      pInputBuffer++;
      pOutputBuffer += 2;
      goto IL_063b;

    IL_056c:
      if (pInputBuffer <= ptr) {
        goto IL_007b;
      }
      goto IL_0573;

    IL_053c:
      if (IsWellFormedUtf16SurrogatePair(num)) {
        if (outputBytesRemaining >= 4) {
          Unsafe::WriteUnaligned(pOutputBuffer, ExtractFourUtf8BytesFromSurrogatePair(num));
          pInputBuffer += 2;
          pOutputBuffer += 4;
          outputBytesRemaining -= 4;
          goto IL_056c;
        }
        goto IL_063b;
      }
      goto IL_0640;

    IL_0573:
      inputLength = (Int32)(ptr - pInputBuffer) + 2;
      goto IL_057e;

    IL_0338:
      outputBytesRemaining -= 4 * num8;
      if (Utf16Utility::AllCharsInUInt32AreAscii(num)) {
        Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)(num | (num >> 8)));
        pInputBuffer += 2;
        pOutputBuffer += 2;
        outputBytesRemaining -= 2;
        num = num9;
      }
      goto IL_0369;
    }
    break;
  }
  goto IL_0589;

IL_0643:
  pInputBufferRemaining = pInputBuffer;
  pOutputBufferRemaining = pOutputBuffer;
  OperationStatus result;
  return result;

IL_0589:
  UInt32 num10 = ((!BitConverter::IsLittleEndian) ? (num >> 16) : (num & 65535u));
  goto IL_059f;

IL_0640:
  result = OperationStatus::InvalidData;
  goto IL_0643;

IL_057e:
  if (inputLength != 0) {
    num10 = *pInputBuffer;
    goto IL_059f;
  }
  goto IL_0631;

IL_059f:
  if (num10 <= 127) {
    if (outputBytesRemaining != 0) {
      *pOutputBuffer = (Byte)num10;
      pInputBuffer++;
      pOutputBuffer++;
      goto IL_062d;
    }
  } else if (num10 < 2048) {
    if (outputBytesRemaining >= 2) {
      pOutputBuffer[1] = (Byte)((num10 & 63u) | 4294967168u);
      *pOutputBuffer = (Byte)((num10 >> 6) | 4294967232u);
      pInputBuffer++;
      pOutputBuffer += 2;
      goto IL_062d;
    }
  } else {
    if (UnicodeUtility::IsSurrogateCodePoint(num10)) {
      if (num10 > 56319) {
        goto IL_0640;
      }
      result = OperationStatus::NeedMoreData;
      goto IL_0643;
    }
    if (outputBytesRemaining >= 3) {
      pOutputBuffer[2] = (Byte)((num10 & 63u) | 4294967168u);
      pOutputBuffer[1] = (Byte)(((num10 >> 6) & 63u) | 4294967168u);
      *pOutputBuffer = (Byte)((num10 >> 12) | 4294967264u);
      pInputBuffer++;
      pOutputBuffer += 3;
      goto IL_062d;
    }
  }

  goto IL_063b;

IL_0631:
  result = OperationStatus::Done;
  goto IL_0643;

IL_062d:
  if (inputLength <= 1) {
    goto IL_0631;
  }
  goto IL_063b;

IL_063b:
  result = OperationStatus::DestinationTooSmall;
  goto IL_0643;
}

Byte* Utf8Utility::GetPointerToFirstInvalidByte(Byte* pInputBuffer, Int32 inputLength, Int32& utf16CodeUnitCountAdjustment, Int32& scalarCountAdjustment) {
  UIntPtr indexOfFirstNonAsciiByte = ASCIIUtility::GetIndexOfFirstNonAsciiByte(pInputBuffer, (UIntPtr)(UInt32)inputLength);
  pInputBuffer += (UInt64)indexOfFirstNonAsciiByte;
  inputLength -= (Int32)(UInt64)indexOfFirstNonAsciiByte;
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

      IL_0043:
        UInt32 num4;
        UIntPtr uIntPtr;
        if (ASCIIUtility::AllBytesInUInt32AreAscii(num3)) {
          pInputBuffer += 4;
          if ((Int64)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) < 16) {
            break;
          }
          num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          if (ASCIIUtility::AllBytesInUInt32AreAscii(num3)) {
            pInputBuffer = (Byte*)((UInt64)(pInputBuffer + 4) & (UInt64)(Int64)(IntPtr)(void*)(~3));
            Byte* ptr2 = ptr - 12;
            Vector128<Byte> bitMask = (BitConverter::IsLittleEndian ? Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)4097)) : Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)272)));
            UInt64 nonAsciiBytes;
            while (true) {
              if (AdvSimd::in::Arm64::in::get_IsSupported() && BitConverter::IsLittleEndian) {
                nonAsciiBytes = GetNonAsciiBytes(AdvSimd::in::LoadVector128(pInputBuffer), bitMask);
                if (nonAsciiBytes != 0) {
                  break;
                }
              } else {
                if (!Sse2::in::get_IsSupported()) {
                  if (ASCIIUtility::AllBytesInUInt32AreAscii(*(UInt32*)pInputBuffer | *(UInt32*)(pInputBuffer + 4))) {
                    if (ASCIIUtility::AllBytesInUInt32AreAscii(*(UInt32*)(pInputBuffer + 2 * 4) | *(UInt32*)(pInputBuffer + 3 * 4))) {
                      goto IL_012b;
                    }
                    pInputBuffer += 8;
                  }
                  num3 = *(UInt32*)pInputBuffer;
                  if (ASCIIUtility::AllBytesInUInt32AreAscii(num3)) {
                    pInputBuffer += 4;
                    num3 = *(UInt32*)pInputBuffer;
                  }
                  goto IL_0172;
                }
                num4 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pInputBuffer));
                if (num4 != 0) {
                  goto IL_00fb;
                }
              }
              goto IL_012b;

            IL_012b:
              pInputBuffer += 16;
              if (pInputBuffer <= ptr2) {
                continue;
              }
              goto IL_052f;
            }
            uIntPtr = (UIntPtr)(void*)((UInt64)BitOperations::TrailingZeroCount(nonAsciiBytes) >> 2);
            goto IL_013e;
          }
        }
        goto IL_0172;

      IL_0522:
        pInputBuffer += 4;
        num -= 2;
        num2--;
        break;

      IL_0191:
        while (true) {
          num3 -= (UInt32)(BitConverter::IsLittleEndian ? 32960 : (-1065353216));
          if ((num3 & (BitConverter::IsLittleEndian ? 49376u : 3770679296u)) != 0) {
            break;
          }
          if ((!BitConverter::IsLittleEndian || (UInt32)(Byte)num3 >= 2u) && (BitConverter::IsLittleEndian || num3 >= 33554432)) {
            while ((BitConverter::IsLittleEndian && UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(num3)) || (!BitConverter::IsLittleEndian && UInt32EndsWithUtf8TwoByteMask(num3) && !UInt32EndsWithOverlongUtf8TwoByteSequence(num3))) {
              pInputBuffer += 4;
              num -= 2;
              if (pInputBuffer > ptr) {
                goto IL_0540;
              }
              num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              if (BitConverter::IsLittleEndian) {
                if (!UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(num3)) {
                  goto IL_0043;
                }
                continue;
              }
              if (!UInt32BeginsWithUtf8TwoByteMask(num3)) {
                goto IL_0043;
              }
              if (!UInt32BeginsWithOverlongUtf8TwoByteSequence(num3)) {
                continue;
              }
              goto IL_0628;
            }
            num--;
            if (UInt32ThirdByteIsAscii(num3)) {
              if (UInt32FourthByteIsAscii(num3)) {
                pInputBuffer += 4;
              } else {
                pInputBuffer += 3;
                if (pInputBuffer <= ptr) {
                  num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                  continue;
                }
              }
            } else {
              pInputBuffer += 2;
            }
            goto IL_052f;
          }
          goto IL_0628;
        }
        num3 -= (UInt32)(BitConverter::IsLittleEndian ? 8388640 : 536903680);
        if ((num3 & (UInt32)(BitConverter::IsLittleEndian ? 12632304 : (-255803392))) == 0) {
          while (true) {
            if (BitConverter::IsLittleEndian) {
              if ((num3 & 8207) == 0 || ((num3 - 8205) & 8207) == 0) {
                break;
              }
            } else if ((num3 & 253755392) == 0 || ((num3 - 220200960) & 253755392) == 0) {
              break;
            }

            while (true) {

            IL_0316:
              IntPtr intPtr = (IntPtr)(void*)((!BitConverter::IsLittleEndian) ? ((Int64)(SByte)num3 >> 7) : ((Int32)num3 >> 31));
              pInputBuffer += 4;
              pInputBuffer += (Int64)intPtr;
              num -= 2;
              UInt64 num5;
              while (true) {
                Int32 size = IntPtr::get_Size();
                if (!BitConverter::IsLittleEndian || (Int64)(IntPtr)(void*)(ptr - pInputBuffer) < 5) {
                  break;
                }
                num5 = Unsafe::ReadUnaligned<UInt64>(pInputBuffer);
                num3 = (UInt32)num5;
                if ((num5 & 13902823984598139120) != 9286563722648649952 || !IsUtf8ContinuationByte(pInputBuffer[8])) {
                  goto IL_0415;
                }
                if (((UInt32)(Int32)num5 & 8207u) != 0 && ((UInt32)((Int32)num5 - 8205) & 8207u) != 0) {
                  num5 >>= 24;
                  if (((UInt32)(Int32)num5 & 8207u) != 0 && ((UInt32)((Int32)num5 - 8205) & 8207u) != 0) {
                    num5 >>= 24;
                    if (((UInt32)(Int32)num5 & 8207u) != 0 && ((UInt32)((Int32)num5 - 8205) & 8207u) != 0) {
                      pInputBuffer += 9;
                      num -= 6;
                      continue;
                    }
                  }
                  goto IL_0316;
                }
                goto IL_0628;
              }
              break;

            IL_0415:
              if ((num5 & 211934905417968) != 141291010687200) {
                goto IL_0485;
              }
              if (((UInt32)(Int32)num5 & 8207u) != 0 && ((UInt32)((Int32)num5 - 8205) & 8207u) != 0) {
                num5 >>= 24;
                if (((Int32)num5 & 8207) == 0 || (((Int32)num5 - 8205) & 8207) == 0) {
                  continue;
                }
                goto IL_0477;
              }
              goto IL_0628;
            }
            if (pInputBuffer <= ptr) {
              num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              if (!UInt32BeginsWithUtf8ThreeByteMask(num3)) {
                goto IL_0043;
              }
              continue;
            }
            goto IL_0540;

          IL_0485:
            if (!UInt32BeginsWithUtf8ThreeByteMask(num3)) {
              goto IL_0043;
            }
          }
        } else if (BitConverter::IsLittleEndian) {
          num3 &= 3233873919u;
          if ((Int32)num3 <= -2147467265) {
            num3 = BitOperations::RotateRight(num3, 8);
            if (UnicodeUtility::IsInRangeInclusive(num3, 276824080u, 343932943u)) {
              goto IL_0522;
            }
          }
        } else {
          num3 -= 128;
          if ((num3 & 12632256) == 0 && UnicodeUtility::IsInRangeInclusive(num3, 269484032u, 336592895u)) {
            goto IL_0522;
          }
        }

        goto IL_0628;

      IL_00fb:
        uIntPtr = (UIntPtr)(void*)BitOperations::TrailingZeroCount(num4);
        goto IL_013e;

      IL_0477:
        pInputBuffer += 6;
        num -= 4;
        break;

      IL_0172:
        UInt32 num6 = ASCIIUtility::CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(num3);
        pInputBuffer += num6;
        if (ptr >= pInputBuffer) {
          num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          goto IL_0191;
        }
        goto IL_0540;

      IL_013e:
        pInputBuffer += (UInt64)uIntPtr;
        if (pInputBuffer <= ptr) {
          num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          goto IL_0191;
        }
        goto IL_0540;
      }

    IL_052f:
    }
    goto IL_0540;
  }
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)inputLength;
  goto IL_0620;

IL_0628:
  utf16CodeUnitCountAdjustment = num;
  scalarCountAdjustment = num2;
  return pInputBuffer;

IL_0620:
  while (uIntPtr2 != (UIntPtr)(void*)(void*)nullptr) {
    UInt32 num7 = *pInputBuffer;
    if ((UInt32)(Byte)num7 < 128u) {
      pInputBuffer++;
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      continue;
    }
    if ((UInt64)uIntPtr2 < 2) {
      break;
    }
    UInt32 value = pInputBuffer[1];
    if ((UInt32)(Byte)num7 < 224u) {
      if ((UInt32)(Byte)num7 < 194u || !IsLowByteUtf8ContinuationByte(value)) {
        break;
      }
      pInputBuffer += 2;
      num--;
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 2);
      continue;
    }
    if ((UInt64)uIntPtr2 < 3 || (UInt32)(Byte)num7 >= 240u) {
      break;
    }
    if ((Byte)num7 == 224) {
      if (!UnicodeUtility::IsInRangeInclusive(value, 160u, 191u)) {
        break;
      }
    } else if ((Byte)num7 == 237) {
      if (!UnicodeUtility::IsInRangeInclusive(value, 128u, 159u)) {
        break;
      }
    } else if (!IsLowByteUtf8ContinuationByte(value)) {
      break;
    }


    if (!IsUtf8ContinuationByte(pInputBuffer[2])) {
      break;
    }
    pInputBuffer += 3;
    num -= 2;
    uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 3);
  }
  goto IL_0628;

IL_0540:
  uIntPtr2 = (UIntPtr)((Byte*)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) + 4);
  goto IL_0620;
}

UInt64 Utf8Utility::GetNonAsciiBytes(Vector128<Byte> value, Vector128<Byte> bitMask128) {
  if (!AdvSimd::in::Arm64::in::get_IsSupported() || !BitConverter::IsLittleEndian) {
    rt::throw_exception<PlatformNotSupportedException>();
  }
  Vector128<Byte> left = Vector128<>::AsByte(AdvSimd::in::ShiftRightArithmetic(Vector128<>::AsSByte(value), 7));
  Vector128<Byte> vector = AdvSimd::in::And(left, bitMask128);
  vector = AdvSimd::in::Arm64::in::AddPairwise(vector, vector);
  return Vector128<>::ToScalar(Vector128<>::AsUInt64(vector));
}

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace
