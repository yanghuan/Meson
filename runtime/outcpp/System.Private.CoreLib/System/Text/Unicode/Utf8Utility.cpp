#include "Utf8Utility-dep.h"

namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace {
UInt32 Utf8Utility::ExtractCharFromFirstThreeByteSequence(UInt32 value) {
  return UInt32();
};

UInt32 Utf8Utility::ExtractCharFromFirstTwoByteSequence(UInt32 value) {
  return UInt32();
};

UInt32 Utf8Utility::ExtractCharsFromFourByteSequence(UInt32 value) {
  return UInt32();
};

UInt32 Utf8Utility::ExtractFourUtf8BytesFromSurrogatePair(UInt32 value) {
  return UInt32();
};

UInt32 Utf8Utility::ExtractTwoCharsPackedFromTwoAdjacentTwoByteSequences(UInt32 value) {
  return UInt32();
};

UInt32 Utf8Utility::ExtractTwoUtf8TwoByteSequencesFromTwoPackedUtf16Chars(UInt32 value) {
  return UInt32();
};

UInt32 Utf8Utility::ExtractUtf8TwoByteSequenceFromFirstUtf16Char(UInt32 value) {
  return UInt32();
};

Boolean Utf8Utility::IsFirstCharAscii(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsFirstCharAtLeastThreeUtf8Bytes(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsFirstCharSurrogate(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsFirstCharTwoUtf8Bytes(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsLowByteUtf8ContinuationByte(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsSecondCharAscii(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsSecondCharAtLeastThreeUtf8Bytes(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsSecondCharSurrogate(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsSecondCharTwoUtf8Bytes(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::IsUtf8ContinuationByte(Byte& value) {
  return Boolean();
};

Boolean Utf8Utility::IsWellFormedUtf16SurrogatePair(UInt32 value) {
  return Boolean();
};

UInt32 Utf8Utility::ToLittleEndian(UInt32 value) {
  return UInt32();
};

Boolean Utf8Utility::UInt32BeginsWithOverlongUtf8TwoByteSequence(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32BeginsWithUtf8FourByteMask(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32BeginsWithUtf8ThreeByteMask(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32BeginsWithUtf8TwoByteMask(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32EndsWithOverlongUtf8TwoByteSequence(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32EndsWithUtf8TwoByteMask(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32BeginsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32EndsWithValidUtf8TwoByteSequenceLittleEndian(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32FirstByteIsAscii(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32FourthByteIsAscii(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32SecondByteIsAscii(UInt32 value) {
  return Boolean();
};

Boolean Utf8Utility::UInt32ThirdByteIsAscii(UInt32 value) {
  return Boolean();
};

void Utf8Utility::WriteTwoUtf16CharsAsTwoUtf8ThreeByteSequences(Byte& outputBuffer, UInt32 value) {
};

void Utf8Utility::WriteFirstUtf16CharAsUtf8ThreeByteSequence(Byte& outputBuffer, UInt32 value) {
};

OperationStatus Utf8Utility::TranscodeToUtf16(Byte* pInputBuffer, Int32 inputLength, Char* pOutputBuffer, Int32 outputCharsRemaining, Byte*& pInputBufferRemaining, Char*& pOutputBufferRemaining) {
  return OperationStatus::InvalidData;
};

OperationStatus Utf8Utility::TranscodeToUtf8(Char* pInputBuffer, Int32 inputLength, Byte* pOutputBuffer, Int32 outputBytesRemaining, Char*& pInputBufferRemaining, Byte*& pOutputBufferRemaining) {
  return OperationStatus::InvalidData;
};

Byte* Utf8Utility::GetPointerToFirstInvalidByte(Byte* pInputBuffer, Int32 inputLength, Int32& utf16CodeUnitCountAdjustment, Int32& scalarCountAdjustment) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8UtilityNamespace
