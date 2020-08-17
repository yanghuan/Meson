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
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
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
    goto IL_070f;
  }
  Byte* ptr = pInputBuffer + (UInt32)inputLength - 4;
  while (true) {

  IL_004a:
    UInt32 num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
    while (true) {

    IL_0051:
      if (!ASCIIUtility::AllBytesInUInt32AreAscii(num2)) {
        goto IL_0120;
      }
      Int32 num4;
      UInt32 num5;
      if (outputCharsRemaining >= 4) {
        ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(*pOutputBuffer, num2);
        pInputBuffer += 4;
        pOutputBuffer += 4;
        outputCharsRemaining -= 4;
        UInt32 val = (UInt32)((Int32)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) + 4);
        UInt32 num3 = Math::Min(val, (UInt32)outputCharsRemaining) / 8u;
        num4 = 0;
        while ((UInt32)num4 < num3) {
          num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          num5 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer + 4);
          if (ASCIIUtility::AllBytesInUInt32AreAscii(num2 | num5)) {
            pInputBuffer += 8;
            ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(*pOutputBuffer, num2);
            ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(pOutputBuffer[4], num5);
            pOutputBuffer += 8;
            num4++;
            continue;
          }
          goto IL_00f4;
        }
        outputCharsRemaining -= 8 * num4;
        goto IL_0529;
      }
      goto IL_0530;

    IL_0529:
      if (pInputBuffer <= ptr) {
        goto IL_004a;
      }
      goto IL_0530;

    IL_0120:
      if (UInt32FirstByteIsAscii(num2)) {
        if (outputCharsRemaining >= 3) {
          UInt32 num6 = ToLittleEndian(num2);
          UIntPtr num7 = 1u;
          *pOutputBuffer = (Char)(Byte)num6;
          if (UInt32SecondByteIsAscii(num2)) {
            num7++;
            num6 >>= 8;
            pOutputBuffer[1] = (Char)(Byte)num6;
            if (UInt32ThirdByteIsAscii(num2)) {
              num7++;
              num6 >>= 8;
              pOutputBuffer[2] = (Char)(Byte)num6;
            }
          }
          pInputBuffer += num7;
          pOutputBuffer += num7;
          outputCharsRemaining -= (Int32)num7;
        } else {
          if (outputCharsRemaining == 0) {
            break;
          }
          UInt32 num8 = ToLittleEndian(num2);
          pInputBuffer++;
          Char* num9 = pOutputBuffer;
          pOutputBuffer = num9 + 1;
          *num9 = (Char)(Byte)num8;
          outputCharsRemaining--;
          if (UInt32SecondByteIsAscii(num2)) {
            if (outputCharsRemaining == 0) {
              break;
            }
            pInputBuffer++;
            num8 >>= 8;
            Char* num10 = pOutputBuffer;
            pOutputBuffer = num10 + 1;
            *num10 = (Char)(Byte)num8;
            if (UInt32ThirdByteIsAscii(num2)) {
              break;
            }
            outputCharsRemaining = 0;
          }
        }
        if (pInputBuffer > ptr) {
          goto IL_0530;
        }
        num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
      }
      UInt32 num11;
      while (UInt32BeginsWithUtf8TwoByteMask(num2)) {
        if (!UInt32BeginsWithOverlongUtf8TwoByteSequence(num2)) {
          while ((BitConverter::IsLittleEndian && UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(num2)) || (!BitConverter::IsLittleEndian && UInt32EndsWithUtf8TwoByteMask(num2) && !UInt32EndsWithOverlongUtf8TwoByteSequence(num2))) {
            if (outputCharsRemaining >= 2) {
              Unsafe::WriteUnaligned(pOutputBuffer, ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(num2));
              pInputBuffer += 4;
              pOutputBuffer += 2;
              outputCharsRemaining -= 2;
              if (pInputBuffer <= ptr) {
                num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                if (BitConverter::IsLittleEndian) {
                  if (!UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(num2)) {
                    goto IL_0051;
                  }
                  continue;
                }
                if (!UInt32BeginsWithUtf8TwoByteMask(num2)) {
                  goto IL_0051;
                }
                if (!UInt32BeginsWithOverlongUtf8TwoByteSequence(num2)) {
                  continue;
                }
                goto IL_0722;
              }
            }
            goto IL_0530;
          }
          num11 = ExtractCharFromFirstTwoByteSequence(num2);
          if (UInt32ThirdByteIsAscii(num2)) {
            if (UInt32FourthByteIsAscii(num2)) {
              goto IL_02ac;
            }
            if (outputCharsRemaining >= 2) {
              *pOutputBuffer = (Char)num11;
              pOutputBuffer[1] = (Char)(Byte)(num2 >> (BitConverter::IsLittleEndian ? 16 : 8));
              pInputBuffer += 3;
              pOutputBuffer += 2;
              outputCharsRemaining -= 2;
              if (ptr >= pInputBuffer) {
                num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                continue;
              }
            }
          } else if (outputCharsRemaining != 0) {
            *pOutputBuffer = (Char)num11;
            pInputBuffer += 2;
            pOutputBuffer++;
            outputCharsRemaining--;
            if (ptr >= pInputBuffer) {
              num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              break;
            }
          }

          goto IL_0530;
        }
        goto IL_0722;
      }
      if (UInt32BeginsWithUtf8ThreeByteMask(num2)) {
        while (true) {
          if (BitConverter::IsLittleEndian) {
            if ((num2 & 8207) == 0 || ((num2 - 8205) & 8207) == 0) {
              break;
            }
          } else if ((num2 & 253755392) == 0 || ((num2 - 220200960) & 253755392) == 0) {
            break;
          }

          if (outputCharsRemaining != 0) {
            if (BitConverter::IsLittleEndian && (((Int32)num2 - -536870912) & -268435456) == 0 && outputCharsRemaining > 1 && (IntPtr)(IntPtr)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) >= 3) {
              UInt32 num12 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer + 3);
              if (UInt32BeginsWithUtf8ThreeByteMask(num12) && (num12 & 8207) != 0 && ((num12 - 8205) & 8207) != 0) {
                *pOutputBuffer = (Char)ExtractCharFromFirstThreeByteSequence(num2);
                pOutputBuffer[1] = (Char)ExtractCharFromFirstThreeByteSequence(num12);
                pInputBuffer += 6;
                pOutputBuffer += 2;
                outputCharsRemaining -= 2;
                goto IL_0463;
              }
            }
            *pOutputBuffer = (Char)ExtractCharFromFirstThreeByteSequence(num2);
            pInputBuffer += 3;
            pOutputBuffer++;
            outputCharsRemaining--;
            goto IL_0463;
          }
          goto IL_071e;

        IL_0463:
          if (UInt32FourthByteIsAscii(num2)) {
            if (outputCharsRemaining == 0) {
              goto IL_071e;
            }
            if (BitConverter::IsLittleEndian) {
              *pOutputBuffer = (Char)(num2 >> 24);
            } else {
              *pOutputBuffer = (Char)(Byte)num2;
            }
            pInputBuffer++;
            pOutputBuffer++;
            outputCharsRemaining--;
          }
          if (pInputBuffer <= ptr) {
            num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
            if (!UInt32BeginsWithUtf8ThreeByteMask(num2)) {
              goto IL_0051;
            }
            continue;
          }
          goto IL_0530;
        }
      } else if (UInt32BeginsWithUtf8FourByteMask(num2)) {
        if (BitConverter::IsLittleEndian) {
          UInt32 value = num2 & 65535;
          value = BitOperations::RotateRight(value, 8);
          if (UnicodeUtility::IsInRangeInclusive(value, 4026531984u, 4093640847u)) {
            goto IL_0504;
          }
        } else if (UnicodeUtility::IsInRangeInclusive(num2, 4035969024u, 4103077887u)) {
          goto IL_0504;
        }

      }

      goto IL_0722;

    IL_0504:
      if (outputCharsRemaining < 2) {
        break;
      }
      Unsafe::WriteUnaligned(pOutputBuffer, ExtractCharsFromFourByteSequence(num2));
      pInputBuffer += 4;
      pOutputBuffer += 2;
      outputCharsRemaining -= 2;
      goto IL_0529;

    IL_02ac:
      if (outputCharsRemaining >= 3) {
        *pOutputBuffer = (Char)num11;
        if (BitConverter::IsLittleEndian) {
          num2 >>= 16;
          pOutputBuffer[1] = (Char)(Byte)num2;
          num2 >>= 8;
          pOutputBuffer[2] = (Char)num2;
        } else {
          pOutputBuffer[2] = (Char)(Byte)num2;
          pOutputBuffer[1] = (Char)(Byte)(num2 >> 8);
        }
        pInputBuffer += 4;
        pOutputBuffer += 3;
        outputCharsRemaining -= 3;
        goto IL_0529;
      }
      goto IL_0530;

    IL_00f4:
      if (ASCIIUtility::AllBytesInUInt32AreAscii(num2)) {
        ASCIIUtility::WidenFourAsciiBytesToUtf16AndWriteToBuffer(*pOutputBuffer, num2);
        num2 = num5;
        pInputBuffer += 4;
        pOutputBuffer += 4;
        outputCharsRemaining -= 4;
      }
      outputCharsRemaining -= 8 * num4;
      goto IL_0120;

    IL_0530:
      inputLength = (Int32)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) + 4;
      goto IL_070f;
    }
    break;
  }
  goto IL_071e;

IL_070f:
  OperationStatus result;
  while (true) {
    if (inputLength > 0) {
      UInt32 num13 = *pInputBuffer;
      if (num13 <= 127) {
        if (outputCharsRemaining != 0) {
          *pOutputBuffer = (Char)num13;
          pInputBuffer++;
          pOutputBuffer++;
          inputLength--;
          outputCharsRemaining--;
          continue;
        }
        goto IL_071e;
      }
      num13 -= 194;
      if ((UInt32)(Byte)num13 <= 29u) {
        if (inputLength < 2) {
          goto IL_071a;
        }
        UInt32 num14 = pInputBuffer[1];
        if (IsLowByteUtf8ContinuationByte(num14)) {
          if (outputCharsRemaining != 0) {
            UInt32 num15 = (num13 << 6) + num14 + 128 - 128;
            *pOutputBuffer = (Char)num15;
            pInputBuffer += 2;
            pOutputBuffer++;
            inputLength -= 2;
            outputCharsRemaining--;
            continue;
          }
          goto IL_071e;
        }
      } else if ((UInt32)(Byte)num13 <= 45u) {
        if (inputLength >= 3) {
          UInt32 num16 = pInputBuffer[1];
          UInt32 num17 = pInputBuffer[2];
          if (IsLowByteUtf8ContinuationByte(num16) && IsLowByteUtf8ContinuationByte(num17)) {
            UInt32 num18 = (num13 << 12) + (num16 << 6);
            if (num18 >= 133120) {
              num18 -= 186368;
              if (num18 >= 2048) {
                if (outputCharsRemaining != 0) {
                  num18 += num17;
                  num18 += 55296;
                  num18 -= 128;
                  *pOutputBuffer = (Char)num18;
                  pInputBuffer += 3;
                  pOutputBuffer++;
                  inputLength -= 3;
                  outputCharsRemaining--;
                  continue;
                }
                goto IL_071e;
              }
            }
          }
        } else {
          if (inputLength < 2) {
            goto IL_071a;
          }
          UInt32 num19 = pInputBuffer[1];
          if (IsLowByteUtf8ContinuationByte(num19)) {
            UInt32 num20 = (num13 << 6) + num19;
            if (num20 >= 2080 && !UnicodeUtility::IsInRangeInclusive(num20, 2912u, 2943u)) {
              goto IL_071a;
            }
          }
        }
      } else if ((UInt32)(Byte)num13 <= 50u) {
        if (inputLength < 2) {
          goto IL_071a;
        }
        UInt32 num21 = pInputBuffer[1];
        if (IsLowByteUtf8ContinuationByte(num21)) {
          UInt32 value2 = (num13 << 6) + num21;
          if (UnicodeUtility::IsInRangeInclusive(value2, 3088u, 3343u)) {
            if (inputLength < 3) {
              goto IL_071a;
            }
            if (IsLowByteUtf8ContinuationByte(pInputBuffer[2])) {
              if (inputLength < 4) {
                goto IL_071a;
              }
              if (IsLowByteUtf8ContinuationByte(pInputBuffer[3])) {
                goto IL_071e;
              }
            }
          }
        }
      }


      goto IL_0722;
    }
    result = OperationStatus::Done;
    break;

  IL_071a:
    result = OperationStatus::NeedMoreData;
    break;
  }
  goto IL_0724;

IL_0724:
  pInputBufferRemaining = pInputBuffer;
  pOutputBufferRemaining = pOutputBuffer;
  return result;

IL_071e:
  result = OperationStatus::DestinationTooSmall;
  goto IL_0724;

IL_0722:
  result = OperationStatus::InvalidData;
  goto IL_0724;
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
    goto IL_04be;
  }
  Char* ptr = pInputBuffer + (UInt32)inputLength - 2;
  Vector128<Int16> value;
  Unsafe::SkipInit(value);
  if (Sse41::in::X64::in::get_IsSupported()) {
    value = Vector128<>::Create((?)(-128));
  }
  UInt32 num2;
  while (true) {

  IL_006d:
    num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
    while (true) {

    IL_0074:
      if (!Utf16Utility::AllCharsInUInt32AreAscii(num2)) {
        goto IL_02a9;
      }
      if (outputBytesRemaining < 2) {
        break;
      }
      UInt32 num3 = num2 | (num2 >> 8);
      Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)num3);
      pInputBuffer += 2;
      pOutputBuffer += 2;
      outputBytesRemaining -= 2;
      UInt32 num4 = (UInt32)((Int32)(ptr - pInputBuffer) + 2);
      UInt32 num5 = (UInt32)Math::Min(num4, outputBytesRemaining);
      Int32 num7;
      UInt64 num8;
      Vector128<Int16> vector;
      Int32 num10;
      UInt32 num11;
      if (Sse41::in::X64::in::get_IsSupported()) {
        UInt32 num6 = num5 / 8u;
        num7 = 0;
        while ((UInt32)num7 < num6) {
          vector = Unsafe::ReadUnaligned<Vector128<Int16>>(pInputBuffer);
          if (Sse41::in::TestZ(vector, value)) {
            Sse2::in::StoreScalar((UInt64*)pOutputBuffer, Vector128<>::AsUInt64(Sse2::in::PackUnsignedSaturate(vector, vector)));
            pInputBuffer += 8;
            pOutputBuffer += 8;
            num7++;
            continue;
          }
          goto IL_017a;
        }
        outputBytesRemaining -= 8 * num7;
        if ((num5 & 4) != 0) {
          num8 = Unsafe::ReadUnaligned<UInt64>(pInputBuffer);
          if (!Utf16Utility::AllCharsInUInt64AreAscii(num8)) {
            goto IL_01d3;
          }
          vector = Vector128<>::AsInt16(Vector128<>::CreateScalarUnsafe(num8));
          Unsafe::WriteUnaligned(pOutputBuffer, Sse2::in::ConvertToUInt32(Vector128<>::AsUInt32(Sse2::in::PackUnsignedSaturate(vector, vector))));
          pInputBuffer += 4;
          pOutputBuffer += 4;
          outputBytesRemaining -= 4;
        }
      } else {
        UInt32 num9 = num5 / 4u;
        num10 = 0;
        while ((UInt32)num10 < num9) {
          num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          num11 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer + 2);
          if (Utf16Utility::AllCharsInUInt32AreAscii(num2 | num11)) {
            Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)(num2 | (num2 >> 8)));
            Unsafe::WriteUnaligned(pOutputBuffer + 2, (UInt16)(num11 | (num11 >> 8)));
            pInputBuffer += 4;
            pOutputBuffer += 4;
            num10++;
            continue;
          }
          goto IL_0278;
        }
        outputBytesRemaining -= 4 * num10;
      }
      goto IL_04ac;

    IL_02a9:
      while (true) {
        if (IsFirstCharAscii(num2)) {
          if (outputBytesRemaining == 0) {
            break;
          }
          if (BitConverter::IsLittleEndian) {
            *pOutputBuffer = (Byte)num2;
          } else {
            *pOutputBuffer = (Byte)(num2 >> 24);
          }
          pInputBuffer++;
          pOutputBuffer++;
          outputBytesRemaining--;
          if (pInputBuffer > ptr) {
            goto IL_04b3;
          }
          num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
        }
        if (!IsFirstCharAtLeastThreeUtf8Bytes(num2)) {
          while (IsSecondCharTwoUtf8Bytes(num2)) {
            if (outputBytesRemaining >= 4) {
              Unsafe::WriteUnaligned(pOutputBuffer, ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(num2));
              pInputBuffer += 2;
              pOutputBuffer += 4;
              outputBytesRemaining -= 4;
              if (pInputBuffer <= ptr) {
                num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                if (!IsFirstCharTwoUtf8Bytes(num2)) {
                  goto IL_0074;
                }
                continue;
              }
              goto IL_04b3;
            }
            goto IL_04c9;
          }
          if (outputBytesRemaining < 2) {
            break;
          }
          Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)ExtractUtf8TwoByteSequenceFromFirstUtf16Char(num2));
          if (IsSecondCharAscii(num2)) {
            goto IL_0357;
          }
          pInputBuffer++;
          pOutputBuffer += 2;
          outputBytesRemaining -= 2;
          if (pInputBuffer > ptr) {
            goto IL_04b3;
          }
          num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
        }
        while (!IsFirstCharSurrogate(num2)) {
          if (IsSecondCharAtLeastThreeUtf8Bytes(num2) && !IsSecondCharSurrogate(num2) && outputBytesRemaining >= 6) {
            WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(*pOutputBuffer, num2);
            pInputBuffer += 2;
            pOutputBuffer += 6;
            outputBytesRemaining -= 6;
            if (pInputBuffer <= ptr) {
              num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              if (!IsFirstCharAtLeastThreeUtf8Bytes(num2)) {
                goto IL_0074;
              }
              continue;
            }
            goto IL_04b3;
          }
          if (outputBytesRemaining >= 3) {
            WriteFirstUtf16CharAsUtf8ThreeByteSequence(*pOutputBuffer, num2);
            pInputBuffer++;
            pOutputBuffer += 3;
            outputBytesRemaining -= 3;
            if (!IsSecondCharAscii(num2)) {
              goto IL_046c;
            }
            if (outputBytesRemaining != 0) {
              if (BitConverter::IsLittleEndian) {
                *pOutputBuffer = (Byte)(num2 >> 16);
              } else {
                *pOutputBuffer = (Byte)num2;
              }
              pInputBuffer++;
              pOutputBuffer++;
              outputBytesRemaining--;
              if (pInputBuffer <= ptr) {
                num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
                if (!IsFirstCharAtLeastThreeUtf8Bytes(num2)) {
                  goto IL_0074;
                }
                continue;
              }
              goto IL_04b3;
            }
          }
          goto IL_057b;
        }
        goto IL_047c;

      IL_046c:
        if (pInputBuffer <= ptr) {
          num2 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          continue;
        }
        goto IL_04b3;
      }
      goto IL_057b;

    IL_01d3:
      num2 = (UInt32)num8;
      if (Utf16Utility::AllCharsInUInt32AreAscii(num2)) {
        Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)(num2 | (num2 >> 8)));
        pInputBuffer += 2;
        pOutputBuffer += 2;
        outputBytesRemaining -= 2;
        num2 = (UInt32)(num8 >> 32);
      }
      goto IL_02a9;

    IL_0357:
      if (outputBytesRemaining >= 3) {
        if (BitConverter::IsLittleEndian) {
          num2 >>= 16;
        }
        pOutputBuffer[2] = (Byte)num2;
        pInputBuffer += 2;
        pOutputBuffer += 3;
        outputBytesRemaining -= 3;
        goto IL_04ac;
      }
      pInputBuffer++;
      pOutputBuffer += 2;
      goto IL_057b;

    IL_047c:
      if (IsWellFormedUtf16SurrogatePair(num2)) {
        if (outputBytesRemaining >= 4) {
          Unsafe::WriteUnaligned(pOutputBuffer, ExtractFourUtf8BytesFromSurrogatePair(num2));
          pInputBuffer += 2;
          pOutputBuffer += 4;
          outputBytesRemaining -= 4;
          goto IL_04ac;
        }
        goto IL_057b;
      }
      goto IL_0580;

    IL_04b3:
      inputLength = (Int32)(ptr - pInputBuffer) + 2;
      goto IL_04be;

    IL_0278:
      outputBytesRemaining -= 4 * num10;
      if (Utf16Utility::AllCharsInUInt32AreAscii(num2)) {
        Unsafe::WriteUnaligned(pOutputBuffer, (UInt16)(num2 | (num2 >> 8)));
        pInputBuffer += 2;
        pOutputBuffer += 2;
        outputBytesRemaining -= 2;
        num2 = num11;
      }
      goto IL_02a9;

    IL_04ac:
      if (pInputBuffer <= ptr) {
        goto IL_006d;
      }
      goto IL_04b3;

    IL_017a:
      outputBytesRemaining -= 8 * num7;
      num8 = Sse2::in::X64::in::ConvertToUInt64(Vector128<>::AsUInt64(vector));
      if (Utf16Utility::AllCharsInUInt64AreAscii(num8)) {
        Unsafe::WriteUnaligned(pOutputBuffer, Sse2::in::ConvertToUInt32(Vector128<>::AsUInt32(Sse2::in::PackUnsignedSaturate(vector, vector))));
        pInputBuffer += 4;
        pOutputBuffer += 4;
        outputBytesRemaining -= 4;
        num8 = Vector128<>::GetElement(Vector128<>::AsUInt64(vector), 1);
      }
      goto IL_01d3;
    }
    break;
  }
  goto IL_04c9;

IL_0583:
  pInputBufferRemaining = pInputBuffer;
  pOutputBufferRemaining = pOutputBuffer;
  OperationStatus result;
  return result;

IL_056d:
  if (inputLength <= 1) {
    goto IL_0571;
  }
  goto IL_057b;

IL_04c9:
  UInt32 num12 = (!BitConverter::IsLittleEndian) ? (num2 >> 16) : (num2 & 65535);
  goto IL_04df;

IL_04be:
  if (inputLength != 0) {
    num12 = *pInputBuffer;
    goto IL_04df;
  }
  goto IL_0571;

IL_057b:
  result = OperationStatus::DestinationTooSmall;
  goto IL_0583;

IL_04df:
  if (num12 <= 127) {
    if (outputBytesRemaining != 0) {
      *pOutputBuffer = (Byte)num12;
      pInputBuffer++;
      pOutputBuffer++;
      goto IL_056d;
    }
  } else if (num12 < 2048) {
    if (outputBytesRemaining >= 2) {
      pOutputBuffer[1] = (Byte)((num12 & 63) | 4294967168u);
      *pOutputBuffer = (Byte)((num12 >> 6) | 4294967232u);
      pInputBuffer++;
      pOutputBuffer += 2;
      goto IL_056d;
    }
  } else {
    if (UnicodeUtility::IsSurrogateCodePoint(num12)) {
      if (num12 > 56319) {
        goto IL_0580;
      }
      result = OperationStatus::NeedMoreData;
      goto IL_0583;
    }
    if (outputBytesRemaining >= 3) {
      pOutputBuffer[2] = (Byte)((num12 & 63) | 4294967168u);
      pOutputBuffer[1] = (Byte)(((num12 >> 6) & 63) | 4294967168u);
      *pOutputBuffer = (Byte)((num12 >> 12) | 4294967264u);
      pInputBuffer++;
      pOutputBuffer += 3;
      goto IL_056d;
    }
  }

  goto IL_057b;

IL_0580:
  result = OperationStatus::InvalidData;
  goto IL_0583;

IL_0571:
  result = OperationStatus::Done;
  goto IL_0583;
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

      IL_0043:
        if (ASCIIUtility::AllBytesInUInt32AreAscii(num3)) {
          pInputBuffer += 4;
          if ((IntPtr)(IntPtr)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) < 16) {
            break;
          }
          num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          if (ASCIIUtility::AllBytesInUInt32AreAscii(num3)) {
            pInputBuffer = (Byte*)(void*)(UIntPtr)(UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)(pInputBuffer + 4) & ~(?)3);
            Byte* ptr2 = ptr - 12;
            UInt32 num4;
            while (true) {
              if (Sse2::in::get_IsSupported()) {
                num4 = (UInt32)Sse2::in::MoveMask(Sse2::in::LoadVector128(pInputBuffer));
                if (num4 != 0) {
                  break;
                }
                goto IL_00d8;
              }
              if (ASCIIUtility::AllBytesInUInt32AreAscii(*(UInt32*)pInputBuffer | *(UInt32*)(pInputBuffer + 4))) {
                if (ASCIIUtility::AllBytesInUInt32AreAscii(*(UInt32*)(pInputBuffer + (?)2 * (?)4) | *(UInt32*)(pInputBuffer + (?)3 * (?)4))) {
                  goto IL_00d8;
                }
                pInputBuffer += 8;
              }
              num3 = *(UInt32*)pInputBuffer;
              if (ASCIIUtility::AllBytesInUInt32AreAscii(num3)) {
                pInputBuffer += 4;
                num3 = *(UInt32*)pInputBuffer;
              }
              goto IL_011f;

            IL_00d8:
              pInputBuffer += 16;
              if (pInputBuffer <= ptr2) {
                continue;
              }
              goto IL_04dc;
            }
            pInputBuffer += BitOperations::TrailingZeroCount(num4);
            if (pInputBuffer <= ptr) {
              num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              goto IL_013e;
            }
            goto IL_04ed;
          }
        }
        goto IL_011f;

      IL_013e:
        while (true) {
          num3 -= (UInt32)(BitConverter::IsLittleEndian ? 32960 : (-1065353216));
          if ((num3 & (UInt32)(BitConverter::IsLittleEndian ? 49376 : (-524288000))) != 0) {
            break;
          }
          if ((!BitConverter::IsLittleEndian || (UInt32)(Byte)num3 >= 2u) && (BitConverter::IsLittleEndian || num3 >= 33554432)) {
            while ((BitConverter::IsLittleEndian && UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(num3)) || (!BitConverter::IsLittleEndian && UInt32EndsWithUtf8TwoByteMask(num3) && !UInt32EndsWithOverlongUtf8TwoByteSequence(num3))) {
              pInputBuffer += 4;
              num -= 2;
              if (pInputBuffer > ptr) {
                goto IL_04ed;
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
              goto IL_05da;
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
            goto IL_04dc;
          }
          goto IL_05da;
        }
        num3 -= (UInt32)(BitConverter::IsLittleEndian ? 8388640 : 536903680);
        if (((Int32)num3 & (BitConverter::IsLittleEndian ? 12632304 : (-255803392))) == 0) {
          while (true) {
            if (BitConverter::IsLittleEndian) {
              if ((num3 & 8207) == 0 || ((num3 - 8205) & 8207) == 0) {
                break;
              }
            } else if ((num3 & 253755392) == 0 || ((num3 - 220200960) & 253755392) == 0) {
              break;
            }

            while (true) {

            IL_02c3:
              IntPtr intPtr = (!BitConverter::IsLittleEndian) ? ((IntPtr)(SByte)num3 >> 7) : ((Int32)num3 >> 31);
              pInputBuffer += 4;
              pInputBuffer += (IntPtr)intPtr;
              num -= 2;
              UInt64 num5;
              while (true) {
                _ = IntPtr::get_Size();
                if (!BitConverter::IsLittleEndian || (IntPtr)(ptr - pInputBuffer) < 5) {
                  break;
                }
                num5 = Unsafe::ReadUnaligned<UInt64>(pInputBuffer);
                num3 = (UInt32)num5;
                if (((Int64)num5 & -4543920089111412496) != -9160180351060901664 || !IsUtf8ContinuationByte(pInputBuffer[8])) {
                  goto IL_03c2;
                }
                if (((Int32)num5 & 8207) != 0 && (((Int32)num5 - 8205) & 8207) != 0) {
                  num5 >>= 24;
                  if (((Int32)num5 & 8207) != 0 && (((Int32)num5 - 8205) & 8207) != 0) {
                    num5 >>= 24;
                    if (((Int32)num5 & 8207) != 0 && (((Int32)num5 - 8205) & 8207) != 0) {
                      pInputBuffer += 9;
                      num -= 6;
                      continue;
                    }
                  }
                  goto IL_02c3;
                }
                goto IL_05da;
              }
              break;

            IL_03c2:
              if ((num5 & 211934905417968) != 141291010687200) {
                goto IL_0432;
              }
              if (((Int32)num5 & 8207) != 0 && (((Int32)num5 - 8205) & 8207) != 0) {
                num5 >>= 24;
                if (((Int32)num5 & 8207) == 0 || (((Int32)num5 - 8205) & 8207) == 0) {
                  continue;
                }
                goto IL_0424;
              }
              goto IL_05da;
            }
            if (pInputBuffer <= ptr) {
              num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
              if (!UInt32BeginsWithUtf8ThreeByteMask(num3)) {
                goto IL_0043;
              }
              continue;
            }
            goto IL_04ed;

          IL_0432:
            if (!UInt32BeginsWithUtf8ThreeByteMask(num3)) {
              goto IL_0043;
            }
          }
        } else if (BitConverter::IsLittleEndian) {
          num3 &= 3233873919u;
          if ((Int32)num3 <= -2147467265) {
            num3 = BitOperations::RotateRight(num3, 8);
            if (UnicodeUtility::IsInRangeInclusive(num3, 276824080u, 343932943u)) {
              goto IL_04cf;
            }
          }
        } else {
          num3 -= 128;
          if ((num3 & 12632256) == 0 && UnicodeUtility::IsInRangeInclusive(num3, 269484032u, 336592895u)) {
            goto IL_04cf;
          }
        }

        goto IL_05da;

      IL_0424:
        pInputBuffer += 6;
        num -= 4;
        break;

      IL_011f:
        UInt32 num6 = ASCIIUtility::CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(num3);
        pInputBuffer += num6;
        if (ptr >= pInputBuffer) {
          num3 = Unsafe::ReadUnaligned<UInt32>(pInputBuffer);
          goto IL_013e;
        }
        goto IL_04ed;

      IL_04cf:
        pInputBuffer += 4;
        num -= 2;
        num2--;
        break;
      }

    IL_04dc:
    }
    goto IL_04ed;
  }
  UIntPtr num7 = (UInt32)inputLength;
  goto IL_05d2;

IL_05d2:
  while (num7 != 0) {
    UInt32 num8 = *pInputBuffer;
    if ((UInt32)(Byte)num8 < 128u) {
      pInputBuffer++;
      num7--;
      continue;
    }
    if (num7 < 2) {
      break;
    }
    UInt32 value = pInputBuffer[1];
    if ((UInt32)(Byte)num8 < 224u) {
      if ((UInt32)(Byte)num8 < 194u || !IsLowByteUtf8ContinuationByte(value)) {
        break;
      }
      pInputBuffer += 2;
      num--;
      num7 -= 2;
      continue;
    }
    if (num7 < 3 || (UInt32)(Byte)num8 >= 240u) {
      break;
    }
    if ((Byte)num8 == 224) {
      if (!UnicodeUtility::IsInRangeInclusive(value, 160u, 191u)) {
        break;
      }
    } else if ((Byte)num8 == 237) {
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
    num7 -= 3;
  }
  goto IL_05da;

IL_04ed:
  num7 = (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)Unsafe::ByteOffset(*pInputBuffer, *ptr) + 4);
  goto IL_05d2;

IL_05da:
  utf16CodeUnitCountAdjustment = num;
  scalarCountAdjustment = num2;
  return pInputBuffer;
}

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace
