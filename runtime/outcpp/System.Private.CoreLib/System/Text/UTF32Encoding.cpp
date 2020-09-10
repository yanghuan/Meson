#include "UTF32Encoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/UTF32Encoding-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::UTF32EncodingNamespace {
using namespace System::Runtime::InteropServices;

Boolean UTF32Encoding___::UTF32Decoder___::get_HasState() {
  return readByteCount != 0;
}

void UTF32Encoding___::UTF32Decoder___::ctor(UTF32Encoding encoding) {
}

void UTF32Encoding___::UTF32Decoder___::Reset() {
  iChar = 0;
  readByteCount = 0;
  if (_fallbackBuffer != nullptr) {
    _fallbackBuffer->Reset();
  }
}

ReadOnlySpan<Byte> UTF32Encoding___::get_Preamble() {
  if (!(GetType() != typeof<UTF32Encoding>())) {
    if (_emitUTF32ByteOrderMark) {
      if (_bigEndian) {
        return rt::newarr<Array<Byte>>(4);
      }
      return rt::newarr<Array<Byte>>(4);
    }
    return rt::default__;
  }
  return ReadOnlySpan<Byte>(GetPreamble());
}

void UTF32Encoding___::ctor() {
}

void UTF32Encoding___::ctor(Boolean bigEndian, Boolean byteOrderMark) {
  _bigEndian = bigEndian;
  _emitUTF32ByteOrderMark = byteOrderMark;
}

void UTF32Encoding___::ctor(Boolean bigEndian, Boolean byteOrderMark, Boolean throwOnInvalidCharacters) {
  _isThrowException = throwOnInvalidCharacters;
  if (_isThrowException) {
    SetDefaultFallbacks();
  }
}

void UTF32Encoding___::SetDefaultFallbacks() {
  if (_isThrowException) {
    encoderFallback = EncoderFallback::in::get_ExceptionFallback();
    decoderFallback = DecoderFallback::in::get_ExceptionFallback();
  } else {
    encoderFallback = rt::newobj<EncoderReplacementFallback>("�");
    decoderFallback = rt::newobj<DecoderReplacementFallback>("�");
  }
}

Int32 UTF32Encoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (chars->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("chars", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count == 0) {
    return 0;
  }
  {
    Char* ptr = chars;
    return GetByteCount(ptr + index, count, nullptr);
  }
}

Int32 UTF32Encoding___::GetByteCount(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  {
    Char* ptr = s;
    Char* pChars = ptr;
    return GetByteCount(pChars, s->get_Length(), nullptr);
  }
}

Int32 UTF32Encoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetByteCount(chars, count, nullptr);
}

Int32 UTF32Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (s == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((s == nullptr) ? "s" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (charIndex < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charIndex < 0) ? "charIndex" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (s->get_Length() - charIndex < charCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("s", SR::get_ArgumentOutOfRange_IndexCount());
  }
  if (byteIndex < 0 || byteIndex > bytes->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteIndex", SR::get_ArgumentOutOfRange_Index());
  }
  Int32 byteCount = bytes->get_Length() - byteIndex;
  {
    Char* ptr = s;
    Char* ptr2 = ptr;
    {
      Byte* ptr3 = &MemoryMarshal::GetReference<Byte>(bytes);
      return GetBytes(ptr2 + charIndex, charCount, ptr3 + byteIndex, byteCount, nullptr);
    }
  }
}

Int32 UTF32Encoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (charIndex < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charIndex < 0) ? "charIndex" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (chars->get_Length() - charIndex < charCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("chars", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (byteIndex < 0 || byteIndex > bytes->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (charCount == 0) {
    return 0;
  }
  Int32 byteCount = bytes->get_Length() - byteIndex;
  {
    Char* ptr = chars;
    {
      Byte* ptr2 = &MemoryMarshal::GetReference<Byte>(bytes);
      return GetBytes(ptr + charIndex, charCount, ptr2 + byteIndex, byteCount, nullptr);
    }
  }
}

Int32 UTF32Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetBytes(chars, charCount, bytes, byteCount, nullptr);
}

Int32 UTF32Encoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (bytes->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count == 0) {
    return 0;
  }
  {
    Byte* ptr = bytes;
    return GetCharCount(ptr + index, count, nullptr);
  }
}

Int32 UTF32Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetCharCount(bytes, count, nullptr);
}

Int32 UTF32Encoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (byteIndex < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteIndex < 0) ? "byteIndex" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (bytes->get_Length() - byteIndex < byteCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (charIndex < 0 || charIndex > chars->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("charIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (byteCount == 0) {
    return 0;
  }
  Int32 charCount = chars->get_Length() - charIndex;
  {
    Byte* ptr = bytes;
    {
      Char* ptr2 = &MemoryMarshal::GetReference<Char>(chars);
      return GetChars(ptr + byteIndex, byteCount, ptr2 + charIndex, charCount, nullptr);
    }
  }
}

Int32 UTF32Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetChars(bytes, byteCount, chars, charCount, nullptr);
}

String UTF32Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (bytes->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count == 0) {
    return String::in::Empty;
  }
  {
    Byte* ptr = bytes;
    return String::in::CreateStringFromEncoding(ptr + index, count, (UTF32Encoding)this);
  }
}

Int32 UTF32Encoding___::GetByteCount(Char* chars, Int32 count, EncoderNLS encoder) {
  Char* ptr = chars + count;
  Char* charStart = chars;
  Int32 num = 0;
  Char c = '\0';
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    encoderFallbackBuffer = encoder->get_FallbackBuffer();
    if (encoderFallbackBuffer->get_Remaining() > 0) {
      String argument_EncoderFallbackNotEmpty = SR::get_Argument_EncoderFallbackNotEmpty();
      String encodingName = get_EncodingName();
      EncoderFallback fallback = encoder->get_Fallback();
      String as = ((fallback != nullptr) ? fallback->GetType()->ToString() : nullptr);
      rt::throw_exception<ArgumentException>(SR::Format(argument_EncoderFallbackNotEmpty, encodingName, as != nullptr ? as : String::in::Empty));
    }
  } else {
    encoderFallbackBuffer = encoderFallback->CreateFallbackBuffer();
  }
  encoderFallbackBuffer->InternalInitialize(charStart, ptr, encoder, false);
  while (true) {
    Char c2;
    if ((c2 = encoderFallbackBuffer->InternalGetNextChar()) != 0 || chars < ptr) {
      if (c2 == '\0') {
        c2 = *chars;
        chars++;
      }
      if (c != 0) {
        if (Char::IsLowSurrogate(c2)) {
          c = '\0';
          num += 4;
          continue;
        }
        chars--;
        Char* chars2 = chars;
        encoderFallbackBuffer->InternalFallback(c, chars2);
        chars = chars2;
        c = '\0';
      } else if (Char::IsHighSurrogate(c2)) {
        c = c2;
      } else if (Char::IsLowSurrogate(c2)) {
        Char* chars2 = chars;
        encoderFallbackBuffer->InternalFallback(c2, chars2);
        chars = chars2;
      } else {
        num += 4;
      }


    } else {
      if ((encoder != nullptr && !encoder->get_MustFlush()) || c <= '\0') {
        break;
      }
      Char* chars2 = chars;
      encoderFallbackBuffer->InternalFallback(c, chars2);
      chars = chars2;
      c = '\0';
    }
  }
  if (num < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return num;
}

Int32 UTF32Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder) {
  Char* ptr = chars;
  Char* ptr2 = chars + charCount;
  Byte* ptr3 = bytes;
  Byte* ptr4 = bytes + byteCount;
  Char c = '\0';
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    encoderFallbackBuffer = encoder->get_FallbackBuffer();
    if (encoder->_throwOnOverflow && encoderFallbackBuffer->get_Remaining() > 0) {
      String argument_EncoderFallbackNotEmpty = SR::get_Argument_EncoderFallbackNotEmpty();
      String encodingName = get_EncodingName();
      EncoderFallback fallback = encoder->get_Fallback();
      rt::throw_exception<ArgumentException>(SR::Format(argument_EncoderFallbackNotEmpty, encodingName, (fallback != nullptr) ? fallback->GetType() : nullptr));
    }
  } else {
    encoderFallbackBuffer = encoderFallback->CreateFallbackBuffer();
  }
  encoderFallbackBuffer->InternalInitialize(ptr, ptr2, encoder, true);
  while (true) {
    Char c2;
    Char* chars2;
    if ((c2 = encoderFallbackBuffer->InternalGetNextChar()) != 0 || chars < ptr2) {
      if (c2 == '\0') {
        c2 = *chars;
        chars++;
      }
      if (c != 0) {
        if (!Char::IsLowSurrogate(c2)) {
          chars--;
          chars2 = chars;
          encoderFallbackBuffer->InternalFallback(c, chars2);
          chars = chars2;
          c = '\0';
          continue;
        }
        UInt32 surrogate = GetSurrogate(c, c2);
        c = '\0';
        if (bytes + 3 < ptr4) {
          if (_bigEndian) {
            *(bytes++) = 0;
            *(bytes++) = (Byte)(surrogate >> 16);
            *(bytes++) = (Byte)(surrogate >> 8);
            *(bytes++) = (Byte)surrogate;
          } else {
            *(bytes++) = (Byte)surrogate;
            *(bytes++) = (Byte)(surrogate >> 8);
            *(bytes++) = (Byte)(surrogate >> 16);
            *(bytes++) = 0;
          }
          continue;
        }
        if (encoderFallbackBuffer->bFallingBack) {
          encoderFallbackBuffer->MovePrevious();
          encoderFallbackBuffer->MovePrevious();
        } else {
          chars -= 2;
        }
        ThrowBytesOverflow(encoder, bytes == ptr3);
        c = '\0';
      } else {
        if (Char::IsHighSurrogate(c2)) {
          c = c2;
          continue;
        }
        if (Char::IsLowSurrogate(c2)) {
          chars2 = chars;
          encoderFallbackBuffer->InternalFallback(c2, chars2);
          chars = chars2;
          continue;
        }
        if (bytes + 3 < ptr4) {
          if (_bigEndian) {
            *(bytes++) = 0;
            *(bytes++) = 0;
            *(bytes++) = (Byte)((UInt32)c2 >> 8);
            *(bytes++) = (Byte)c2;
          } else {
            *(bytes++) = (Byte)c2;
            *(bytes++) = (Byte)((UInt32)c2 >> 8);
            *(bytes++) = 0;
            *(bytes++) = 0;
          }
          continue;
        }
        if (encoderFallbackBuffer->bFallingBack) {
          encoderFallbackBuffer->MovePrevious();
        } else {
          chars--;
        }
        ThrowBytesOverflow(encoder, bytes == ptr3);
      }
    }
    if ((encoder != nullptr && !encoder->get_MustFlush()) || c <= '\0') {
      break;
    }
    chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
    c = '\0';
  }
  if (encoder != nullptr) {
    encoder->_charLeftOver = c;
    encoder->_charsUsed = (Int32)(chars - ptr);
  }
  return (Int32)(bytes - ptr3);
}

Int32 UTF32Encoding___::GetCharCount(Byte* bytes, Int32 count, DecoderNLS baseDecoder) {
  UTF32Decoder uTF32Decoder = (UTF32Decoder)baseDecoder;
  Int32 num = 0;
  Byte* ptr = bytes + count;
  Byte* byteStart = bytes;
  Int32 num2 = 0;
  UInt32 num3 = 0u;
  DecoderFallbackBuffer decoderFallbackBuffer = nullptr;
  if (uTF32Decoder != nullptr) {
    num2 = uTF32Decoder->readByteCount;
    num3 = (UInt32)uTF32Decoder->iChar;
    decoderFallbackBuffer = uTF32Decoder->get_FallbackBuffer();
  } else {
    decoderFallbackBuffer = decoderFallback->CreateFallbackBuffer();
  }
  decoderFallbackBuffer->InternalInitialize(byteStart, nullptr);
  while (bytes < ptr && num >= 0) {
    if (_bigEndian) {
      num3 <<= 8;
      num3 += *(bytes++);
    } else {
      num3 >>= 8;
      num3 += (UInt32)(*(bytes++) << 24);
    }
    num2++;
    if (num2 < 4) {
      continue;
    }
    num2 = 0;
    if (num3 > 1114111 || (num3 >= 55296 && num3 <= 57343)) {
      Array<Byte> bytes2 = (!_bigEndian) ? rt::newarr<Array<Byte>>(4) : rt::newarr<Array<Byte>>(4);
      num += decoderFallbackBuffer->InternalFallback(bytes2, bytes);
      num3 = 0u;
    } else {
      if (num3 >= 65536) {
        num++;
      }
      num++;
      num3 = 0u;
    }
  }
  if (num2 > 0 && (uTF32Decoder == nullptr || uTF32Decoder->get_MustFlush())) {
    Array<Byte> array = rt::newarr<Array<Byte>>(num2);
    if (_bigEndian) {
      while (num2 > 0) {
        array[--num2] = (Byte)num3;
        num3 >>= 8;
      }
    } else {
      while (num2 > 0) {
        array[--num2] = (Byte)(num3 >> 24);
        num3 <<= 8;
      }
    }
    num += decoderFallbackBuffer->InternalFallback(array, bytes);
  }
  if (num < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return num;
}

Int32 UTF32Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS baseDecoder) {
  UTF32Decoder uTF32Decoder = (UTF32Decoder)baseDecoder;
  Char* ptr = chars;
  Char* ptr2 = chars + charCount;
  Byte* ptr3 = bytes;
  Byte* ptr4 = bytes + byteCount;
  Int32 num = 0;
  UInt32 num2 = 0u;
  DecoderFallbackBuffer decoderFallbackBuffer = nullptr;
  if (uTF32Decoder != nullptr) {
    num = uTF32Decoder->readByteCount;
    num2 = (UInt32)uTF32Decoder->iChar;
    decoderFallbackBuffer = baseDecoder->get_FallbackBuffer();
  } else {
    decoderFallbackBuffer = decoderFallback->CreateFallbackBuffer();
  }
  decoderFallbackBuffer->InternalInitialize(bytes, chars + charCount);
  while (bytes < ptr4) {
    if (_bigEndian) {
      num2 <<= 8;
      num2 += *(bytes++);
    } else {
      num2 >>= 8;
      num2 += (UInt32)(*(bytes++) << 24);
    }
    num++;
    if (num < 4) {
      continue;
    }
    num = 0;
    if (num2 > 1114111 || (num2 >= 55296 && num2 <= 57343)) {
      Array<Byte> bytes2 = (!_bigEndian) ? rt::newarr<Array<Byte>>(4) : rt::newarr<Array<Byte>>(4);
      Char* chars2 = chars;
      Boolean flag = decoderFallbackBuffer->InternalFallback(bytes2, bytes, chars2);
      chars = chars2;
      if (!flag) {
        bytes -= 4;
        num2 = 0u;
        decoderFallbackBuffer->InternalReset();
        ThrowCharsOverflow(uTF32Decoder, chars == ptr);
        break;
      }
      num2 = 0u;
      continue;
    }
    if (num2 >= 65536) {
      if (chars >= ptr2 - 1) {
        bytes -= 4;
        num2 = 0u;
        ThrowCharsOverflow(uTF32Decoder, chars == ptr);
        break;
      }
      Char* intPtr = chars;
      chars = intPtr + 1;
      *intPtr = GetHighSurrogate(num2);
      num2 = GetLowSurrogate(num2);
    } else if (chars >= ptr2) {
      bytes -= 4;
      num2 = 0u;
      ThrowCharsOverflow(uTF32Decoder, chars == ptr);
      break;
    }

    Char* intPtr2 = chars;
    chars = intPtr2 + 1;
    *intPtr2 = (Char)num2;
    num2 = 0u;
  }
  if (num > 0 && (uTF32Decoder == nullptr || uTF32Decoder->get_MustFlush())) {
    Array<Byte> array = rt::newarr<Array<Byte>>(num);
    Int32 num3 = num;
    if (_bigEndian) {
      while (num3 > 0) {
        array[--num3] = (Byte)num2;
        num2 >>= 8;
      }
    } else {
      while (num3 > 0) {
        array[--num3] = (Byte)(num2 >> 24);
        num2 <<= 8;
      }
    }
    Char* chars2 = chars;
    Boolean flag2 = decoderFallbackBuffer->InternalFallback(array, bytes, chars2);
    chars = chars2;
    if (!flag2) {
      decoderFallbackBuffer->InternalReset();
      ThrowCharsOverflow(uTF32Decoder, chars == ptr);
    } else {
      num = 0;
      num2 = 0u;
    }
  }
  if (uTF32Decoder != nullptr) {
    uTF32Decoder->iChar = (Int32)num2;
    uTF32Decoder->readByteCount = num;
    uTF32Decoder->_bytesUsed = (Int32)(bytes - ptr3);
  }
  return (Int32)(chars - ptr);
}

UInt32 UTF32Encoding___::GetSurrogate(Char cHigh, Char cLow) {
  return (UInt32)((cHigh - 55296) * 1024 + (cLow - 56320) + 65536);
}

Char UTF32Encoding___::GetHighSurrogate(UInt32 iChar) {
  return (Char)((iChar - 65536) / 1024u + 55296);
}

Char UTF32Encoding___::GetLowSurrogate(UInt32 iChar) {
  return (Char)((iChar - 65536) % 1024u + 56320);
}

Decoder UTF32Encoding___::GetDecoder() {
  return rt::newobj<UTF32Decoder>((UTF32Encoding)this);
}

Encoder UTF32Encoding___::GetEncoder() {
  return rt::newobj<EncoderNLS>((UTF32Encoding)this);
}

Int32 UTF32Encoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount + 1;
  if (Encoding::in::get_EncoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_EncoderFallback()->get_MaxCharCount();
  }
  num *= 4;
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 UTF32Encoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 num = byteCount / 2 + 2;
  if (Encoding::in::get_DecoderFallback()->get_MaxCharCount() > 2) {
    num *= Encoding::in::get_DecoderFallback()->get_MaxCharCount();
    num /= 2;
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_GetCharCountOverflow());
  }
  return num;
}

Array<Byte> UTF32Encoding___::GetPreamble() {
  if (_emitUTF32ByteOrderMark) {
    if (!_bigEndian) {
      return rt::newarr<Array<Byte>>(4);
    }
    return rt::newarr<Array<Byte>>(4);
  }
  return Array<>::in::Empty<Byte>();
}

Boolean UTF32Encoding___::Equals(Object value) {
  UTF32Encoding uTF32Encoding = rt::as<UTF32Encoding>(value);
  if (uTF32Encoding != nullptr) {
    if (_emitUTF32ByteOrderMark == uTF32Encoding->_emitUTF32ByteOrderMark && _bigEndian == uTF32Encoding->_bigEndian && Encoding::in::get_EncoderFallback()->Equals(uTF32Encoding->get_EncoderFallback())) {
      return Encoding::in::get_DecoderFallback()->Equals(uTF32Encoding->get_DecoderFallback());
    }
    return false;
  }
  return false;
}

Int32 UTF32Encoding___::GetHashCode() {
  return Encoding::in::get_EncoderFallback()->GetHashCode() + Encoding::in::get_DecoderFallback()->GetHashCode() + get_CodePage() + (_emitUTF32ByteOrderMark ? 4 : 0) + (_bigEndian ? 8 : 0);
}

void UTF32Encoding___::cctor() {
  s_default = rt::newobj<UTF32Encoding>(false, true);
  s_bigEndianDefault = rt::newobj<UTF32Encoding>(true, true);
}

} // namespace System::Private::CoreLib::System::Text::UTF32EncodingNamespace
