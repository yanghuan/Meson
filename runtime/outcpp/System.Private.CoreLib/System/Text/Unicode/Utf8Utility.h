#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text::Unicode {
namespace Utf8UtilityNamespace {
using namespace ::System::Private::CoreLib::System::Buffers;
class Utf8Utility {
  private: static UInt32 ExtractCharFromFirstThreeByteSequence(UInt32 value);
  private: static UInt32 ExtractCharFromFirstTwoByteSequence(UInt32 value);
  private: static UInt32 ExtractCharsFromFourByteSequence(UInt32 value);
  private: static UInt32 ExtractFourUtf8BytesFromSurrogatePair(UInt32 value);
  private: static UInt32 ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(UInt32 value);
  private: static UInt32 ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(UInt32 value);
  private: static UInt32 ExtractUtf8TwoByteSequenceFromFirstUtf16Char(UInt32 value);
  private: static Boolean IsFirstCharAscii(UInt32 value);
  private: static Boolean IsFirstCharAtLeastThreeUtf8Bytes(UInt32 value);
  private: static Boolean IsFirstCharSurrogate(UInt32 value);
  private: static Boolean IsFirstCharTwoUtf8Bytes(UInt32 value);
  private: static Boolean IsLowByteUtf8ContinuationByte(UInt32 value);
  private: static Boolean IsSecondCharAscii(UInt32 value);
  private: static Boolean IsSecondCharAtLeastThreeUtf8Bytes(UInt32 value);
  private: static Boolean IsSecondCharSurrogate(UInt32 value);
  private: static Boolean IsSecondCharTwoUtf8Bytes(UInt32 value);
  public: static Boolean IsUtf8ContinuationByte(Byte& value);
  private: static Boolean IsWellFormedUtf16SurrogatePair(UInt32 value);
  private: static UInt32 ToLittleEndian(UInt32 value);
  private: static Boolean UInt32BeginsWithOverlongUtf8TwoByteSequence(UInt32 value);
  private: static Boolean UInt32BeginsWithUtf8FourByteMask(UInt32 value);
  private: static Boolean UInt32BeginsWithUtf8ThreeByteMask(UInt32 value);
  private: static Boolean UInt32BeginsWithUtf8TwoByteMask(UInt32 value);
  private: static Boolean UInt32EndsWithOverlongUtf8TwoByteSequence(UInt32 value);
  private: static Boolean UInt32EndsWithUtf8TwoByteMask(UInt32 value);
  private: static Boolean UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value);
  private: static Boolean UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value);
  private: static Boolean UInt32FirstByteIsAscii(UInt32 value);
  private: static Boolean UInt32FourthByteIsAscii(UInt32 value);
  private: static Boolean UInt32SecondByteIsAscii(UInt32 value);
  private: static Boolean UInt32ThirdByteIsAscii(UInt32 value);
  private: static void WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(Byte& outputBuffer, UInt32 value);
  private: static void WriteFirstUtf16CharAsUtf8ThreeByteSequence(Byte& outputBuffer, UInt32 value);
  public: static OperationStatus TranscodeToUtf16(Byte* pInputBuffer, Int32 inputLength, Char* pOutputBuffer, Int32 outputCharsRemaining, Byte*& pInputBufferRemaining, Char*& pOutputBufferRemaining);
  public: static OperationStatus TranscodeToUtf8(Char* pInputBuffer, Int32 inputLength, Byte* pOutputBuffer, Int32 outputBytesRemaining, Char*& pInputBufferRemaining, Byte*& pOutputBufferRemaining);
  public: static Byte* GetPointerToFirstInvalidByte(Byte* pInputBuffer, Int32 inputLength, Int32& utf16CodeUnitCountAdjustment, Int32& scalarCountAdjustment);
};
} // namespace Utf8UtilityNamespace
using Utf8Utility = Utf8UtilityNamespace::Utf8Utility;
} // namespace System::Private::CoreLib::System::Text::Unicode
