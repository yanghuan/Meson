#include "Latin1Encoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Latin1Encoding-dep.h>

namespace System::Private::CoreLib::System::Text::Latin1EncodingNamespace {
Boolean Latin1Encoding___::get_IsSingleByte() {
  return true;
}

void Latin1Encoding___::ctor() {
}

Int32 Latin1Encoding___::GetByteCount(Char* chars, Int32 charCount, EncoderNLS encoder) {
  Char c = 0;
  EncoderReplacementFallback encoderReplacementFallback;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    encoderReplacementFallback = (rt::as<EncoderReplacementFallback>(encoder->get_Fallback()));
  } else {
  }
  if (encoderReplacementFallback != nullptr && encoderReplacementFallback->get_MaxCharCount() == 1) {
    if (c > 0) {
      charCount++;
    }
    return charCount;
  }
  Int32 num = 0;
  Char* ptr = chars + charCount;
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (c > 0) {
    encoderFallbackBuffer = encoder->get_FallbackBuffer();
    encoderFallbackBuffer->InternalInitialize(chars, ptr, encoder, false);
    Char* chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
  }
  while (true) {
  }
  return num;
}

Int32 Latin1Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder) {
  Char c = 0;
  EncoderReplacementFallback encoderReplacementFallback = nullptr;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    encoderReplacementFallback = (rt::as<EncoderReplacementFallback>(encoder->get_Fallback()));
  } else {
  }
  Char* ptr = chars + charCount;
  Byte* ptr2 = bytes;
  Char* ptr3 = chars;
  if (encoderReplacementFallback != nullptr && encoderReplacementFallback->get_MaxCharCount() == 1) {
    Char c2 = encoderReplacementFallback->get_DefaultString()[0];
    if (c2 <= 255) {
      if (c > 0) {
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
        Char* num = chars;
        chars = num + 1;
        Char c3 = *num;
        if (c3 > 255) {
          *(bytes++) = (Byte)c2;
        } else {
          *(bytes++) = (Byte)c3;
        }
      }
      if (encoder != nullptr) {
        encoder->_charLeftOver = 0;
        encoder->_charsUsed = (Int32)(chars - ptr3);
      }
      return (Int32)(bytes - ptr2);
    }
  }
  Byte* ptr4 = bytes + byteCount;
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (c > 0) {
    encoderFallbackBuffer = encoder->get_FallbackBuffer();
    encoderFallbackBuffer->InternalInitialize(chars, ptr, encoder, true);
    Char* chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
    if (encoderFallbackBuffer->get_Remaining() > ptr4 - bytes) {
      ThrowBytesOverflow(encoder, true);
    }
  }
  while (true) {
  }
  if (encoder != nullptr) {
    if (encoderFallbackBuffer != nullptr && !encoderFallbackBuffer->bUsedEncoder) {
      encoder->_charLeftOver = 0;
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
}

Int32 Latin1Encoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = byteCount;
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
