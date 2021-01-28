#include "Latin1Encoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/Latin1Encoding-dep.h>

namespace System::Private::CoreLib::System::Text::Latin1EncodingNamespace {
Boolean Latin1Encoding___::get_IsSingleByte() {
  return true;
}

void Latin1Encoding___::ctor() {
}

Int32 Latin1Encoding___::GetByteCount(Char* chars, Int32 charCount, EncoderNLS encoder) {
  Char c = u'\0';
  EncoderReplacementFallback encoderReplacementFallback;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    encoderReplacementFallback = rt::as<EncoderReplacementFallback>(encoder->get_Fallback());
  } else {
    encoderReplacementFallback = rt::as<EncoderReplacementFallback>(Encoding::in::get_EncoderFallback());
  }
  if (encoderReplacementFallback != nullptr && encoderReplacementFallback->get_MaxCharCount() == 1) {
    if (c > u'\0') {
      charCount++;
    }
    return charCount;
  }
  Int32 num = 0;
  Char* ptr = chars + charCount;
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (c > u'\0') {
    encoderFallbackBuffer = encoder->get_FallbackBuffer();
    encoderFallbackBuffer->InternalInitialize(chars, ptr, encoder, false);
    Char* chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
  }
  Char c2;
  while ((c2 = ((encoderFallbackBuffer != nullptr) ? encoderFallbackBuffer->InternalGetNextChar() : u'\0')) != 0 || chars < ptr) {
    if (c2 == u'\0') {
      c2 = *chars;
      chars++;
    }
    if (c2 > u'ÿ') {
      if (encoderFallbackBuffer == nullptr) {
        encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
        encoderFallbackBuffer->InternalInitialize(ptr - charCount, ptr, encoder, false);
      }
      Char* chars2 = chars;
      encoderFallbackBuffer->InternalFallback(c2, chars2);
      chars = chars2;
    } else {
      num++;
    }
  }
  return num;
}

Int32 Latin1Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder) {
  Char c = u'\0';
  EncoderReplacementFallback encoderReplacementFallback = nullptr;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    encoderReplacementFallback = rt::as<EncoderReplacementFallback>(encoder->get_Fallback());
  } else {
    encoderReplacementFallback = rt::as<EncoderReplacementFallback>(Encoding::in::get_EncoderFallback());
  }
  Char* ptr = chars + charCount;
  Byte* ptr2 = bytes;
  Char* ptr3 = chars;
  if (encoderReplacementFallback != nullptr && encoderReplacementFallback->get_MaxCharCount() == 1) {
    Char c2 = encoderReplacementFallback->get_DefaultString()[0];
    if (c2 <= u'ÿ') {
      if (c > u'\0') {
        if (byteCount == 0) {
          ThrowBytesOverflow(encoder, true);
        }
        *(bytes++) = (Byte)c2;
        byteCount--;
      }
      if (byteCount < charCount) {
        ThrowBytesOverflow(encoder, byteCount < 1);
        ptr = chars + byteCount;
      }
      while (chars < ptr) {
        Char* intPtr = chars;
        chars = intPtr + 1;
        Char c3 = *intPtr;
        if (c3 > u'ÿ') {
          *(bytes++) = (Byte)c2;
        } else {
          *(bytes++) = (Byte)c3;
        }
      }
      if (encoder != nullptr) {
        encoder->_charLeftOver = u'\0';
        encoder->_charsUsed = (Int32)(chars - ptr3);
      }
      return (Int32)(bytes - ptr2);
    }
  }
  Byte* ptr4 = bytes + byteCount;
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (c > u'\0') {
    encoderFallbackBuffer = encoder->get_FallbackBuffer();
    encoderFallbackBuffer->InternalInitialize(chars, ptr, encoder, true);
    Char* chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
    if (encoderFallbackBuffer->get_Remaining() > ptr4 - bytes) {
      ThrowBytesOverflow(encoder, true);
    }
  }
  Char c4;
  while ((c4 = ((encoderFallbackBuffer != nullptr) ? encoderFallbackBuffer->InternalGetNextChar() : u'\0')) != 0 || chars < ptr) {
    if (c4 == u'\0') {
      c4 = *chars;
      chars++;
    }
    if (c4 > u'ÿ') {
      if (encoderFallbackBuffer == nullptr) {
        encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
        encoderFallbackBuffer->InternalInitialize(ptr - charCount, ptr, encoder, true);
      }
      Char* chars2 = chars;
      encoderFallbackBuffer->InternalFallback(c4, chars2);
      chars = chars2;
      if (encoderFallbackBuffer->get_Remaining() > ptr4 - bytes) {
        chars--;
        encoderFallbackBuffer->InternalReset();
        ThrowBytesOverflow(encoder, chars == ptr3);
        break;
      }
      continue;
    }
    if (bytes >= ptr4) {
      if (encoderFallbackBuffer == nullptr || !encoderFallbackBuffer->bFallingBack) {
        chars--;
      }
      ThrowBytesOverflow(encoder, chars == ptr3);
      break;
    }
    *bytes = (Byte)c4;
    bytes++;
  }
  if (encoder != nullptr) {
    if (encoderFallbackBuffer != nullptr && !encoderFallbackBuffer->bUsedEncoder) {
      encoder->_charLeftOver = u'\0';
    }
    encoder->_charsUsed = (Int32)(chars - ptr3);
  }
  return (Int32)(bytes - ptr2);
}

Int32 Latin1Encoding___::GetCharCount(Byte* bytes, Int32 count, DecoderNLS decoder) {
  return count;
}

Int32 Latin1Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS decoder) {
  if (charCount < byteCount) {
    ThrowCharsOverflow(decoder, charCount < 1);
    byteCount = charCount;
  }
  Byte* ptr = bytes + byteCount;
  while (bytes < ptr) {
    *chars = (Char)(*bytes);
    chars++;
    bytes++;
  }
  if (decoder != nullptr) {
    decoder->_bytesUsed = byteCount;
  }
  return byteCount;
}

Int32 Latin1Encoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount + 1;
  if (Encoding::in::get_EncoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_EncoderFallback()->get_MaxCharCount();
  }
  if (num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 Latin1Encoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = byteCount;
  if (Encoding::in::get_DecoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_DecoderFallback()->get_MaxCharCount();
  }
  if (num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_GetCharCountOverflow());
  }
  return (Int32)num;
}

Boolean Latin1Encoding___::IsAlwaysNormalized(NormalizationForm form) {
  return form == NormalizationForm::FormC;
}

Array<Char> Latin1Encoding___::GetBestFitUnicodeToBytesData() {
  return arrayCharBestFit;
}

void Latin1Encoding___::cctor() {
  s_default = rt::newobj<Latin1Encoding>();
  arrayCharBestFit = rt::newarr<Array<Char>>(604);
}

} // namespace System::Private::CoreLib::System::Text::Latin1EncodingNamespace
