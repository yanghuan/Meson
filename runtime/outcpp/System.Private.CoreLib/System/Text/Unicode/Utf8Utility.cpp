#include "Utf8Utility-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIUtility-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers::Binary;

UInt32 Utf8Utility::ExtractCharFromFirstThreeByteSequence(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  }
}

UInt32 Utf8Utility::ExtractCharFromFirstTwoByteSequence(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (UInt32)((Byte)value << 6);
    return (Byte)(value >> 8) + num - 12288 - 128;
  }
}

UInt32 Utf8Utility::ExtractCharsFromFourByteSequence(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 num = (UInt32)((Byte)value << 8);
  }
}

UInt32 Utf8Utility::ExtractFourUtf8BytesFromSurrogatePair(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    value += 64;
  }
  value -= 3623934976u;
  value += 4194304;
}

UInt32 Utf8Utility::ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  }
}

UInt32 Utf8Utility::ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  }
}

UInt32 Utf8Utility::ExtractUtf8TwoByteSequenceFromFirstUtf16Char(UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  }
}

Boolean Utf8Utility::IsFirstCharAscii(UInt32 value) {
}

Boolean Utf8Utility::IsFirstCharAtLeastThreeUtf8Bytes(UInt32 value) {
}

Boolean Utf8Utility::IsFirstCharSurrogate(UInt32 value) {
}

Boolean Utf8Utility::IsFirstCharTwoUtf8Bytes(UInt32 value) {
}

Boolean Utf8Utility::IsLowByteUtf8ContinuationByte(UInt32 value) {
  return (UInt32)(Byte)(value - 128) <= 63u;
}

Boolean Utf8Utility::IsSecondCharAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || value >= 8388608) {
    if (!BitConverter::IsLittleEndian) {
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsSecondCharAtLeastThreeUtf8Bytes(UInt32 value) {
}

Boolean Utf8Utility::IsSecondCharSurrogate(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (UInt32)((Int32)value - -671088640) >= 134217728u) {
    if (!BitConverter::IsLittleEndian) {
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsSecondCharTwoUtf8Bytes(UInt32 value) {
  if (!BitConverter::IsLittleEndian || !UnicodeUtility::IsInRangeInclusive(value, 8388608u, 134217727u)) {
    if (!BitConverter::IsLittleEndian) {
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::IsUtf8ContinuationByte(Byte& value) {
  return (SByte)value < -64;
}

Boolean Utf8Utility::IsWellFormedUtf16SurrogatePair(UInt32 value) {
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
}

Boolean Utf8Utility::UInt32BeginsWithUtf8ThreeByteMask(UInt32 value) {
}

Boolean Utf8Utility::UInt32BeginsWithUtf8TwoByteMask(UInt32 value) {
}

Boolean Utf8Utility::UInt32EndsWithOverlongUtf8TwoByteSequence(UInt32 value) {
}

Boolean Utf8Utility::UInt32EndsWithUtf8TwoByteMask(UInt32 value) {
}

Boolean Utf8Utility::UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
}

Boolean Utf8Utility::UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
}

Boolean Utf8Utility::UInt32FirstByteIsAscii(UInt32 value) {
}

Boolean Utf8Utility::UInt32FourthByteIsAscii(UInt32 value) {
  if (!BitConverter::IsLittleEndian || (Int32)value < 0) {
    if (!BitConverter::IsLittleEndian) {
    }
    return false;
  }
  return true;
}

Boolean Utf8Utility::UInt32SecondByteIsAscii(UInt32 value) {
}

Boolean Utf8Utility::UInt32ThirdByteIsAscii(UInt32 value) {
}

void Utf8Utility::WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  } else {
  }
}

void Utf8Utility::WriteFirstUtf16CharAsUtf8ThreeByteSequence(Byte& outputBuffer, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
  } else {
  }
}

OperationStatus Utf8Utility::TranscodeToUtf16(Byte* pInputBuffer, Int32 inputLength, Char* pOutputBuffer, Int32 outputCharsRemaining, Byte*& pInputBufferRemaining, Char*& pOutputBufferRemaining) {
  unsigned int num = ASCIIUtility::WidenAsciiToUtf16(pInputBuffer, pOutputBuffer, (UInt32)Math::Min(inputLength, outputCharsRemaining));
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
  unsigned int num = ASCIIUtility::NarrowUtf16ToAscii(pInputBuffer, pOutputBuffer, (UInt32)Math::Min(inputLength, outputBytesRemaining));
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
  unsigned int indexOfFirstNonAsciiByte = ASCIIUtility::GetIndexOfFirstNonAsciiByte(pInputBuffer, (UInt32)inputLength);
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
  unsigned int num7 = (UInt32)inputLength;
}

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace
