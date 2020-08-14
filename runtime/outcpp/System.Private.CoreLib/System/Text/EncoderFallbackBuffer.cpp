#include "EncoderFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Buffers/OperationStatus.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderFallbackBufferNamespace {
using namespace System::Buffers;

void EncoderFallbackBuffer___::Reset() {
  while (GetNextChar() != 0) {
  }
}

void EncoderFallbackBuffer___::InternalReset() {
  charStart = nullptr;
  bFallingBack = false;
  iRecursionCount = 0;
  Reset();
}

void EncoderFallbackBuffer___::InternalInitialize(Char* charStart, Char* charEnd, EncoderNLS encoder, Boolean setEncoder) {
  this->charStart = charStart;
  this->charEnd = charEnd;
  this->encoder = encoder;
  this->setEncoder = setEncoder;
  bUsedEncoder = false;
  bFallingBack = false;
  iRecursionCount = 0;
}

EncoderFallbackBuffer EncoderFallbackBuffer___::CreateAndInitialize(Encoding encoding, EncoderNLS encoder, Int32 originalCharCount) {
  EncoderFallbackBuffer encoderFallbackBuffer = (encoder == nullptr) ? encoding->get_EncoderFallback()->CreateFallbackBuffer() : encoder->get_FallbackBuffer();
  encoderFallbackBuffer->encoding = encoding;
  encoderFallbackBuffer->encoder = encoder;
  encoderFallbackBuffer->originalCharCount = originalCharCount;
  return encoderFallbackBuffer;
}

Char EncoderFallbackBuffer___::InternalGetNextChar() {
  Char nextChar = GetNextChar();
  bFallingBack = (nextChar != 0);
  if (nextChar == 0) {
    iRecursionCount = 0;
  }
  return nextChar;
}

Boolean EncoderFallbackBuffer___::InternalFallback(ReadOnlySpan<Char> chars, Int32& charsConsumed) {
  Char c = chars[0];
  Char c2 = 0;
  if (!chars.get_IsEmpty()) {
    c = chars[0];
    if (1u < (UInt32)chars.get_Length()) {
      c2 = chars[1];
    }
  }
  Int32 index = originalCharCount - chars.get_Length();
  if (!Char::IsSurrogatePair(c, c2)) {
    charsConsumed = 1;
    return Fallback(c, index);
  }
  charsConsumed = 2;
  return Fallback(c, c2, index);
}

Int32 EncoderFallbackBuffer___::InternalFallbackGetByteCount(ReadOnlySpan<Char> chars, Int32& charsConsumed) {
  Int32 result = 0;
  if (InternalFallback(chars, charsConsumed)) {
    result = DrainRemainingDataForGetByteCount();
  }
  return result;
}

Boolean EncoderFallbackBuffer___::TryInternalFallbackGetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsConsumed, Int32& bytesWritten) {
  if (InternalFallback(chars, charsConsumed)) {
    return TryDrainRemainingDataForGetBytes(bytes, bytesWritten);
  }
  bytesWritten = 0;
  return true;
}

Boolean EncoderFallbackBuffer___::TryDrainRemainingDataForGetBytes(Span<Byte> bytes, Int32& bytesWritten) {
  Int32 length = bytes.get_Length();
  while (true) {
    Rune nextRune;
    Rune rune = nextRune = GetNextRune();
    if (rune.get_Value() == 0) {
      break;
    }
    Int32 bytesWritten2;
    switch (encoding->EncodeRune(nextRune, bytes, bytesWritten2)) {
      case OperationStatus::Done:
        bytes = bytes.Slice(bytesWritten2);
        break;
      case OperationStatus::DestinationTooSmall:
        {
          for (Int32 i = 0; i < nextRune.get_Utf16SequenceLength(); i++) {
            MovePrevious();
          }
          bytesWritten = length - bytes.get_Length();
          return false;
        }case OperationStatus::InvalidData:
        ThrowLastCharRecursive(nextRune.get_Value());
        break;
    }
  }
  bytesWritten = length - bytes.get_Length();
  return true;
}

Int32 EncoderFallbackBuffer___::DrainRemainingDataForGetByteCount() {
  Int32 num = 0;
  while (true) {
    Rune nextRune;
    Rune rune = nextRune = GetNextRune();
    if (rune.get_Value() == 0) {
      break;
    }
  }
  return num;
}

Rune EncoderFallbackBuffer___::GetNextRune() {
  Char nextChar = GetNextChar();
}

Boolean EncoderFallbackBuffer___::InternalFallback(Char ch, Char*& chars) {
  Int32 index = (Int32)(chars - charStart) - 1;
  if (Char::IsHighSurrogate(ch)) {
    if (chars >= charEnd) {
      if (encoder != nullptr && !encoder->get_MustFlush()) {
        if (setEncoder) {
          bUsedEncoder = true;
          encoder->_charLeftOver = ch;
        }
        bFallingBack = false;
        return false;
      }
    } else {
      Char c = *chars;
      if (Char::IsLowSurrogate(c)) {
        if (bFallingBack && iRecursionCount++ > 250) {
          ThrowLastCharRecursive(Char::ConvertToUtf32(ch, c));
        }
        chars++;
        bFallingBack = Fallback(ch, c, index);
        return bFallingBack;
      }
    }
  }
  if (bFallingBack && iRecursionCount++ > 250) {
    ThrowLastCharRecursive(ch);
  }
  bFallingBack = Fallback(ch, index);
  return bFallingBack;
}

void EncoderFallbackBuffer___::ThrowLastCharRecursive(Int32 charRecursive) {
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_RecursiveFallback(), charRecursive), "chars");
}

void EncoderFallbackBuffer___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::EncoderFallbackBufferNamespace
