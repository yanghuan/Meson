#include "DecoderFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderFallbackBufferNamespace {
using namespace System::Globalization;

void DecoderFallbackBuffer___::Reset() {
  while (GetNextChar() != 0) {
  }
}

void DecoderFallbackBuffer___::InternalReset() {
  byteStart = nullptr;
  Reset();
}

void DecoderFallbackBuffer___::InternalInitialize(Byte* byteStart, Char* charEnd) {
  this->byteStart = byteStart;
  this->charEnd = charEnd;
}

DecoderFallbackBuffer DecoderFallbackBuffer___::CreateAndInitialize(Encoding encoding, DecoderNLS decoder, Int32 originalByteCount) {
  DecoderFallbackBuffer decoderFallbackBuffer = (decoder == nullptr) ? encoding->get_DecoderFallback()->CreateFallbackBuffer() : decoder->get_FallbackBuffer();
  decoderFallbackBuffer->_encoding = encoding;
  decoderFallbackBuffer->_decoder = decoder;
  decoderFallbackBuffer->_originalByteCount = originalByteCount;
  return decoderFallbackBuffer;
}

Boolean DecoderFallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes, Char*& chars) {
  if (Fallback(bytes, (Int32)(pBytes - byteStart - bytes->get_Length()))) {
    Char* ptr = chars;
    Boolean flag = false;
    Char nextChar;
    while ((nextChar = GetNextChar()) != 0) {
      if (Char::IsSurrogate(nextChar)) {
        if (Char::IsHighSurrogate(nextChar)) {
          if (flag) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
          }
          flag = true;
        } else {
          if (!flag) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
          }
          flag = false;
        }
      }
      if (ptr >= charEnd) {
        return false;
      }
      Char* intPtr = ptr;
      ptr = intPtr + 1;
      *intPtr = nextChar;
    }
    if (flag) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
    }
    chars = ptr;
  }
  return true;
}

Int32 DecoderFallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes) {
  if (Fallback(bytes, (Int32)(pBytes - byteStart - bytes->get_Length()))) {
    Int32 num = 0;
    Boolean flag = false;
    Char nextChar;
    while ((nextChar = GetNextChar()) != 0) {
      if (Char::IsSurrogate(nextChar)) {
        if (Char::IsHighSurrogate(nextChar)) {
          if (flag) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
          }
          flag = true;
        } else {
          if (!flag) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
          }
          flag = false;
        }
      }
      num++;
    }
    if (flag) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
    }
    return num;
  }
  return 0;
}

Int32 DecoderFallbackBuffer___::InternalFallbackGetCharCount(ReadOnlySpan<Byte> remainingBytes, Int32 fallbackLength) {
  if (!Fallback(remainingBytes.Slice(0, fallbackLength).ToArray(), _originalByteCount - remainingBytes.get_Length())) {
    return 0;
  }
  return DrainRemainingDataForGetCharCount();
}

Boolean DecoderFallbackBuffer___::TryInternalFallbackGetChars(ReadOnlySpan<Byte> remainingBytes, Int32 fallbackLength, Span<Char> chars, Int32& charsWritten) {
  if (Fallback(remainingBytes.Slice(0, fallbackLength).ToArray(), _originalByteCount - remainingBytes.get_Length())) {
    return TryDrainRemainingDataForGetChars(chars, charsWritten);
  }
  charsWritten = 0;
  return true;
}

Rune DecoderFallbackBuffer___::GetNextRune() {
  Char nextChar = GetNextChar();
  Rune result;
  if (!Rune::TryCreate(nextChar, result) && !Rune::TryCreate(nextChar, GetNextChar(), result)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
  }
  return result;
}

Int32 DecoderFallbackBuffer___::DrainRemainingDataForGetCharCount() {
  Int32 num = 0;
  while (true) {
    Rune nextRune;
    Rune rune = nextRune = GetNextRune();
    if (rune.get_Value() == 0) {
      break;
    }
    num += nextRune.get_Utf16SequenceLength();
    if (num < 0) {
      InternalReset();
      Encoding::in::ThrowConversionOverflow();
    }
  }
  return num;
}

Boolean DecoderFallbackBuffer___::TryDrainRemainingDataForGetChars(Span<Char> chars, Int32& charsWritten) {
  Int32 length = chars.get_Length();
  while (true) {
    Rune nextRune;
    Rune rune = nextRune = GetNextRune();
    if (rune.get_Value() == 0) {
      break;
    }
    Int32 charsWritten2;
    if (nextRune.TryEncodeToUtf16(chars, charsWritten2)) {
      chars = chars.Slice(charsWritten2);
      continue;
    }
    InternalReset();
    charsWritten = 0;
    return false;
  }
  charsWritten = length - chars.get_Length();
  return true;
}

void DecoderFallbackBuffer___::ThrowLastBytesRecursive(Array<Byte> bytesUnknown) {
  if (bytesUnknown == nullptr) {
    bytesUnknown = Array<>::in::Empty<Byte>();
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(bytesUnknown->get_Length() * 3);
  Int32 i;
  for (i = 0; i < bytesUnknown->get_Length() && i < 20; i++) {
    if (stringBuilder->get_Length() > 0) {
      stringBuilder->Append((Char)' ');
    }
    stringBuilder->AppendFormat(CultureInfo::in::get_InvariantCulture(), "\\x{0:X2}", bytesUnknown[i]);
  }
  if (i == 20) {
    stringBuilder->Append(" ...");
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_RecursiveFallbackBytes(), stringBuilder->ToString()), "bytesUnknown");
}

void DecoderFallbackBuffer___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::DecoderFallbackBufferNamespace
