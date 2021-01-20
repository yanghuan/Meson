#include "UnicodeEncoding-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeEncoding-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Text::UnicodeEncodingNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;

Boolean UnicodeEncoding___::Decoder___::get_HasState() {
  if (lastByte == -1) {
    return lastChar != u'\0';
  }
  return true;
}

void UnicodeEncoding___::Decoder___::ctor(UnicodeEncoding encoding) {
  lastByte = -1;
  DecoderNLS::in::ctor(encoding);
}

void UnicodeEncoding___::Decoder___::Reset() {
  lastByte = -1;
  lastChar = u'\0';
  if (_fallbackBuffer != nullptr) {
    _fallbackBuffer->Reset();
  }
}

ReadOnlySpan<Byte> UnicodeEncoding___::get_Preamble() {
  if (!(GetType() != typeof<UnicodeEncoding>())) {
    if (byteOrderMark) {
      if (bigEndian) {
        return rt::newarr<Array<Byte>>(2);
      }
      return rt::newarr<Array<Byte>>(2);
    }
    return rt::default__;
  }
  return ReadOnlySpan<Byte>(GetPreamble());
}

void UnicodeEncoding___::ctor() {
}

void UnicodeEncoding___::ctor(Boolean bigEndian, Boolean byteOrderMark) {
  this->bigEndian = bigEndian;
  this->byteOrderMark = byteOrderMark;
}

void UnicodeEncoding___::ctor(Boolean bigEndian, Boolean byteOrderMark, Boolean throwOnInvalidBytes) {
  isThrowException = throwOnInvalidBytes;
  if (isThrowException) {
    SetDefaultFallbacks();
  }
}

void UnicodeEncoding___::SetDefaultFallbacks() {
  if (isThrowException) {
    encoderFallback = EncoderFallback::in::get_ExceptionFallback();
    decoderFallback = DecoderFallback::in::get_ExceptionFallback();
  } else {
    encoderFallback = rt::newobj<EncoderReplacementFallback>("�");
    decoderFallback = rt::newobj<DecoderReplacementFallback>("�");
  }
}

Int32 UnicodeEncoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
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

Int32 UnicodeEncoding___::GetByteCount(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  {
    Char* ptr = s;
    Char* pChars = ptr;
    return GetByteCount(pChars, s->get_Length(), nullptr);
  }
}

Int32 UnicodeEncoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetByteCount(chars, count, nullptr);
}

Int32 UnicodeEncoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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

Int32 UnicodeEncoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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

Int32 UnicodeEncoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetBytes(chars, charCount, bytes, byteCount, nullptr);
}

Int32 UnicodeEncoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
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

Int32 UnicodeEncoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetCharCount(bytes, count, nullptr);
}

Int32 UnicodeEncoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
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

Int32 UnicodeEncoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetChars(bytes, byteCount, chars, charCount, nullptr);
}

String UnicodeEncoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
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
    return String::in::CreateStringFromEncoding(ptr + index, count, (UnicodeEncoding)this);
  }
}

Int32 UnicodeEncoding___::GetByteCount(Char* chars, Int32 count, EncoderNLS encoder) {
  Int32 num = count << 1;
  if (num < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  Char* charStart = chars;
  Char* ptr = chars + count;
  Char c = u'\0';
  Boolean flag = false;
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    if (c > u'\0') {
      num += 2;
    }
    if (encoder->get_InternalHasFallbackBuffer()) {
      encoderFallbackBuffer = encoder->get_FallbackBuffer();
      if (encoderFallbackBuffer->get_Remaining() > 0) {
        String argument_EncoderFallbackNotEmpty = SR::get_Argument_EncoderFallbackNotEmpty();
        String encodingName = get_EncodingName();
        EncoderFallback fallback = encoder->get_Fallback();
        rt::throw_exception<ArgumentException>(SR::Format(argument_EncoderFallbackNotEmpty, encodingName, (fallback != nullptr) ? fallback->GetType() : nullptr));
      }
      encoderFallbackBuffer->InternalInitialize(charStart, ptr, encoder, false);
    }
  }
  while (true) {
    Char c2;
    Char* chars2;
    if ((c2 = ((encoderFallbackBuffer != nullptr) ? encoderFallbackBuffer->InternalGetNextChar() : u'\0')) != 0 || chars < ptr) {
      if (c2 == u'\0') {
        if ((bigEndian ^ BitConverter::IsLittleEndian) && ((UInt64)chars & 7) == 0 && c == u'\0') {
          UInt64* ptr2 = (UInt64*)(ptr - 3);
          UInt64* ptr3;
          for (ptr3 = (UInt64*)chars; ptr3 < ptr2; ptr3++) {
            if ((9223512776490647552 & *ptr3) != 0) {
              UInt64 num2 = (17870556004450629632 & *ptr3) ^ 15564677810327967744;
              if (((num2 & 18446462598732840960) == 0 || (num2 & 281470681743360) == 0 || (num2 & 4294901760u) == 0 || (num2 & 65535) == 0) && (18158790778715962368 & *ptr3) != (UInt64)(BitConverter::IsLittleEndian ? (-2593835887162763264) : (-2882061865335071744))) {
                break;
              }
            }
          }
          chars = (Char*)ptr3;
          if (chars >= ptr) {
            goto IL_02a0;
          }
        }
        c2 = *chars;
        chars++;
      } else {
        num += 2;
      }
      if (c2 >= u'�' && c2 <= u'�') {
        if (c2 <= u'�') {
          if (c > u'\0') {
            chars--;
            num -= 2;
            if (encoderFallbackBuffer == nullptr) {
              encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
              encoderFallbackBuffer->InternalInitialize(charStart, ptr, encoder, false);
            }
            chars2 = chars;
            encoderFallbackBuffer->InternalFallback(c, chars2);
            chars = chars2;
            c = u'\0';
          } else {
            c = c2;
          }
        } else if (c == u'\0') {
          num -= 2;
          if (encoderFallbackBuffer == nullptr) {
            encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
            encoderFallbackBuffer->InternalInitialize(charStart, ptr, encoder, false);
          }
          chars2 = chars;
          encoderFallbackBuffer->InternalFallback(c2, chars2);
          chars = chars2;
        } else {
          c = u'\0';
        }

      } else if (c > u'\0') {
        chars--;
        if (encoderFallbackBuffer == nullptr) {
          encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
          encoderFallbackBuffer->InternalInitialize(charStart, ptr, encoder, false);
        }
        chars2 = chars;
        encoderFallbackBuffer->InternalFallback(c, chars2);
        chars = chars2;
        num -= 2;
        c = u'\0';
      }

      continue;
    }
    goto IL_02a0;

  IL_02a0:
    if (c <= u'\0') {
      break;
    }
    num -= 2;
    if (encoder != nullptr && !encoder->get_MustFlush()) {
      break;
    }
    if (flag) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_RecursiveFallback(), c), "chars");
    }
    if (encoderFallbackBuffer == nullptr) {
      encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
      encoderFallbackBuffer->InternalInitialize(charStart, ptr, encoder, false);
    }
    chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
    c = u'\0';
    flag = true;
  }
  return num;
}

Int32 UnicodeEncoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder) {
  Char c = u'\0';
  Boolean flag = false;
  Byte* ptr = bytes + byteCount;
  Char* ptr2 = chars + charCount;
  Byte* ptr3 = bytes;
  Char* ptr4 = chars;
  EncoderFallbackBuffer encoderFallbackBuffer = nullptr;
  if (encoder != nullptr) {
    c = encoder->_charLeftOver;
    if (encoder->get_InternalHasFallbackBuffer()) {
      encoderFallbackBuffer = encoder->get_FallbackBuffer();
      if (encoderFallbackBuffer->get_Remaining() > 0 && encoder->_throwOnOverflow) {
        String argument_EncoderFallbackNotEmpty = SR::get_Argument_EncoderFallbackNotEmpty();
        String encodingName = get_EncodingName();
        EncoderFallback fallback = encoder->get_Fallback();
        rt::throw_exception<ArgumentException>(SR::Format(argument_EncoderFallbackNotEmpty, encodingName, (fallback != nullptr) ? fallback->GetType() : nullptr));
      }
      encoderFallbackBuffer->InternalInitialize(ptr4, ptr2, encoder, false);
    }
  }
  while (true) {
    Char c2;
    Char* chars2;
    if ((c2 = ((encoderFallbackBuffer != nullptr) ? encoderFallbackBuffer->InternalGetNextChar() : u'\0')) != 0 || chars < ptr2) {
      if (c2 == u'\0') {
        if ((bigEndian ^ BitConverter::IsLittleEndian) && ((UInt64)chars & 7) == 0 && c == u'\0') {
          UInt64* ptr5 = (UInt64*)(chars - 3 + ((ptr - bytes >> 1 < ptr2 - chars) ? (ptr - bytes >> 1) : (ptr2 - chars)));
          UInt64* ptr6 = (UInt64*)chars;
          UInt64* ptr7 = (UInt64*)bytes;
          while (ptr6 < ptr5) {
            if ((9223512776490647552 & *ptr6) != 0) {
              UInt64 num = (17870556004450629632 & *ptr6) ^ 15564677810327967744;
              if (((num & 18446462598732840960) == 0 || (num & 281470681743360) == 0 || (num & 4294901760u) == 0 || (num & 65535) == 0) && (18158790778715962368 & *ptr6) != (UInt64)(BitConverter::IsLittleEndian ? (-2593835887162763264) : (-2882061865335071744))) {
                break;
              }
            }
            Unsafe::WriteUnaligned(ptr7, *ptr6);
            ptr6++;
            ptr7++;
          }
          chars = (Char*)ptr6;
          bytes = (Byte*)ptr7;
          if (chars >= ptr2) {
            goto IL_03aa;
          }
        }
        c2 = *chars;
        chars++;
      }
      if (c2 >= u'�' && c2 <= u'�') {
        if (c2 <= u'�') {
          if (c > u'\0') {
            chars--;
            if (encoderFallbackBuffer == nullptr) {
              encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
              encoderFallbackBuffer->InternalInitialize(ptr4, ptr2, encoder, true);
            }
            chars2 = chars;
            encoderFallbackBuffer->InternalFallback(c, chars2);
            chars = chars2;
            c = u'\0';
          } else {
            c = c2;
          }
          continue;
        }
        if (c == u'\0') {
          if (encoderFallbackBuffer == nullptr) {
            encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
            encoderFallbackBuffer->InternalInitialize(ptr4, ptr2, encoder, true);
          }
          chars2 = chars;
          encoderFallbackBuffer->InternalFallback(c2, chars2);
          chars = chars2;
          continue;
        }
        if (bytes + 3 >= ptr) {
          if (encoderFallbackBuffer != nullptr && encoderFallbackBuffer->bFallingBack) {
            encoderFallbackBuffer->MovePrevious();
            encoderFallbackBuffer->MovePrevious();
          } else {
            chars -= 2;
          }
          ThrowBytesOverflow(encoder, bytes == ptr3);
          c = u'\0';
          goto IL_03aa;
        }
        if (bigEndian) {
          *(bytes++) = (Byte)((Int32)c >> 8);
          *(bytes++) = (Byte)c;
        } else {
          *(bytes++) = (Byte)c;
          *(bytes++) = (Byte)((Int32)c >> 8);
        }
        c = u'\0';
      } else if (c > u'\0') {
        chars--;
        if (encoderFallbackBuffer == nullptr) {
          encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
          encoderFallbackBuffer->InternalInitialize(ptr4, ptr2, encoder, true);
        }
        chars2 = chars;
        encoderFallbackBuffer->InternalFallback(c, chars2);
        chars = chars2;
        c = u'\0';
        continue;
      }

      if (bytes + 1 < ptr) {
        if (bigEndian) {
          *(bytes++) = (Byte)((Int32)c2 >> 8);
          *(bytes++) = (Byte)c2;
        } else {
          *(bytes++) = (Byte)c2;
          *(bytes++) = (Byte)((Int32)c2 >> 8);
        }
        continue;
      }
      if (encoderFallbackBuffer != nullptr && encoderFallbackBuffer->bFallingBack) {
        encoderFallbackBuffer->MovePrevious();
      } else {
        chars--;
      }
      ThrowBytesOverflow(encoder, bytes == ptr3);
    }
    goto IL_03aa;

  IL_03aa:
    if (c <= u'\0' || (encoder != nullptr && !encoder->get_MustFlush())) {
      break;
    }
    if (flag) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_RecursiveFallback(), c), "chars");
    }
    if (encoderFallbackBuffer == nullptr) {
      encoderFallbackBuffer = ((encoder != nullptr) ? encoder->get_FallbackBuffer() : encoderFallback->CreateFallbackBuffer());
      encoderFallbackBuffer->InternalInitialize(ptr4, ptr2, encoder, true);
    }
    chars2 = chars;
    encoderFallbackBuffer->InternalFallback(c, chars2);
    chars = chars2;
    c = u'\0';
    flag = true;
  }
  if (encoder != nullptr) {
    encoder->_charLeftOver = c;
    encoder->_charsUsed = (Int32)(chars - ptr4);
  }
  return (Int32)(bytes - ptr3);
}

Int32 UnicodeEncoding___::GetCharCount(Byte* bytes, Int32 count, DecoderNLS baseDecoder) {
  Decoder decoder = (Decoder)baseDecoder;
  Byte* ptr = bytes + count;
  Byte* byteStart = bytes;
  Int32 num = -1;
  Char c = u'\0';
  Int32 num2 = count >> 1;
  DecoderFallbackBuffer decoderFallbackBuffer = nullptr;
  if (decoder != nullptr) {
    num = decoder->lastByte;
    c = decoder->lastChar;
    if (c > u'\0') {
      num2++;
    }
    if (num >= 0 && (count & 1) == 1) {
      num2++;
    }
  }
  while (bytes < ptr) {
    if ((bigEndian ^ BitConverter::IsLittleEndian) && ((UInt64)bytes & 7) == 0 && num == -1 && c == u'\0') {
      UInt64* ptr2 = (UInt64*)(ptr - 7);
      UInt64* ptr3;
      for (ptr3 = (UInt64*)bytes; ptr3 < ptr2; ptr3++) {
        if ((9223512776490647552 & *ptr3) != 0) {
          UInt64 num3 = (17870556004450629632 & *ptr3) ^ 15564677810327967744;
          if (((num3 & 18446462598732840960) == 0 || (num3 & 281470681743360) == 0 || (num3 & 4294901760u) == 0 || (num3 & 65535) == 0) && (18158790778715962368 & *ptr3) != (UInt64)(BitConverter::IsLittleEndian ? (-2593835887162763264) : (-2882061865335071744))) {
            break;
          }
        }
      }
      bytes = (Byte*)ptr3;
      if (bytes >= ptr) {
        break;
      }
    }
    if (num < 0) {
      num = *(bytes++);
      if (bytes >= ptr) {
        break;
      }
    }
    Char c2 = ((!bigEndian) ? ((Char)((*(bytes++) << 8) | num)) : ((Char)((num << 8) | *(bytes++))));
    num = -1;
    if (c2 >= u'�' && c2 <= u'�') {
      if (c2 <= u'�') {
        if (c > u'\0') {
          num2--;
          Array<Byte> array = nullptr;
          array = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
          if (decoderFallbackBuffer == nullptr) {
            decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
            decoderFallbackBuffer->InternalInitialize(byteStart, nullptr);
          }
          num2 += decoderFallbackBuffer->InternalFallback(array, bytes);
        }
        c = c2;
      } else if (c == u'\0') {
        num2--;
        Array<Byte> array2 = nullptr;
        array2 = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
        if (decoderFallbackBuffer == nullptr) {
          decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
          decoderFallbackBuffer->InternalInitialize(byteStart, nullptr);
        }
        num2 += decoderFallbackBuffer->InternalFallback(array2, bytes);
      } else {
        c = u'\0';
      }

    } else if (c > u'\0') {
      num2--;
      Array<Byte> array3 = nullptr;
      array3 = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
      if (decoderFallbackBuffer == nullptr) {
        decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
        decoderFallbackBuffer->InternalInitialize(byteStart, nullptr);
      }
      num2 += decoderFallbackBuffer->InternalFallback(array3, bytes);
      c = u'\0';
    }

  }
  if (decoder == nullptr || decoder->get_MustFlush()) {
    if (c > u'\0') {
      num2--;
      Array<Byte> array4 = nullptr;
      array4 = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
      if (decoderFallbackBuffer == nullptr) {
        decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
        decoderFallbackBuffer->InternalInitialize(byteStart, nullptr);
      }
      num2 += decoderFallbackBuffer->InternalFallback(array4, bytes);
      c = u'\0';
    }
    if (num >= 0) {
      if (decoderFallbackBuffer == nullptr) {
        decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
        decoderFallbackBuffer->InternalInitialize(byteStart, nullptr);
      }
      num2 += decoderFallbackBuffer->InternalFallback(rt::newarr<Array<Byte>>(1), bytes);
      num = -1;
    }
  }
  if (c > u'\0') {
    num2--;
  }
  return num2;
}

Int32 UnicodeEncoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS baseDecoder) {
  Decoder decoder = (Decoder)baseDecoder;
  Int32 num = -1;
  Char c = u'\0';
  if (decoder != nullptr) {
    num = decoder->lastByte;
    c = decoder->lastChar;
  }
  DecoderFallbackBuffer decoderFallbackBuffer = nullptr;
  Byte* ptr = bytes + byteCount;
  Char* ptr2 = chars + charCount;
  Byte* ptr3 = bytes;
  Char* ptr4 = chars;
  while (bytes < ptr) {
    if ((bigEndian ^ BitConverter::IsLittleEndian) && ((UInt64)chars & 7) == 0 && num == -1 && c == u'\0') {
      UInt64* ptr5 = (UInt64*)(bytes - 7 + ((ptr - bytes >> 1 < ptr2 - chars) ? (ptr - bytes) : (ptr2 - chars << 1)));
      UInt64* ptr6 = (UInt64*)bytes;
      UInt64* ptr7 = (UInt64*)chars;
      while (ptr6 < ptr5) {
        if ((9223512776490647552 & *ptr6) != 0) {
          UInt64 num2 = (17870556004450629632 & *ptr6) ^ 15564677810327967744;
          if (((num2 & 18446462598732840960) == 0 || (num2 & 281470681743360) == 0 || (num2 & 4294901760u) == 0 || (num2 & 65535) == 0) && (18158790778715962368 & *ptr6) != (UInt64)(BitConverter::IsLittleEndian ? (-2593835887162763264) : (-2882061865335071744))) {
            break;
          }
        }
        Unsafe::WriteUnaligned(ptr7, *ptr6);
        ptr6++;
        ptr7++;
      }
      chars = (Char*)ptr7;
      bytes = (Byte*)ptr6;
      if (bytes >= ptr) {
        break;
      }
    }
    if (num < 0) {
      num = *(bytes++);
      continue;
    }
    Char c2 = ((!bigEndian) ? ((Char)((*(bytes++) << 8) | num)) : ((Char)((num << 8) | *(bytes++))));
    num = -1;
    if (c2 >= u'�' && c2 <= u'�') {
      if (c2 <= u'�') {
        if (c > u'\0') {
          Array<Byte> array = nullptr;
          array = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
          if (decoderFallbackBuffer == nullptr) {
            decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
            decoderFallbackBuffer->InternalInitialize(ptr3, ptr2);
          }
          Char* chars2 = chars;
          Boolean flag = decoderFallbackBuffer->InternalFallback(array, bytes, chars2);
          chars = chars2;
          if (!flag) {
            bytes -= 2;
            decoderFallbackBuffer->InternalReset();
            ThrowCharsOverflow(decoder, chars == ptr4);
            break;
          }
        }
        c = c2;
        continue;
      }
      if (c == u'\0') {
        Array<Byte> array2 = nullptr;
        array2 = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
        if (decoderFallbackBuffer == nullptr) {
          decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
          decoderFallbackBuffer->InternalInitialize(ptr3, ptr2);
        }
        Char* chars2 = chars;
        Boolean flag2 = decoderFallbackBuffer->InternalFallback(array2, bytes, chars2);
        chars = chars2;
        if (!flag2) {
          bytes -= 2;
          decoderFallbackBuffer->InternalReset();
          ThrowCharsOverflow(decoder, chars == ptr4);
          break;
        }
        continue;
      }
      if (chars >= ptr2 - 1) {
        bytes -= 2;
        ThrowCharsOverflow(decoder, chars == ptr4);
        break;
      }
      Char* intPtr = chars;
      chars = intPtr + 1;
      *intPtr = c;
      c = u'\0';
    } else if (c > u'\0') {
      Array<Byte> array3 = nullptr;
      array3 = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
      if (decoderFallbackBuffer == nullptr) {
        decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
        decoderFallbackBuffer->InternalInitialize(ptr3, ptr2);
      }
      Char* chars2 = chars;
      Boolean flag3 = decoderFallbackBuffer->InternalFallback(array3, bytes, chars2);
      chars = chars2;
      if (!flag3) {
        bytes -= 2;
        decoderFallbackBuffer->InternalReset();
        ThrowCharsOverflow(decoder, chars == ptr4);
        break;
      }
      c = u'\0';
    }

    if (chars >= ptr2) {
      bytes -= 2;
      ThrowCharsOverflow(decoder, chars == ptr4);
      break;
    }
    Char* intPtr2 = chars;
    chars = intPtr2 + 1;
    *intPtr2 = c2;
  }
  if (decoder == nullptr || decoder->get_MustFlush()) {
    if (c > u'\0') {
      Array<Byte> array4 = nullptr;
      array4 = ((!bigEndian) ? rt::newarr<Array<Byte>>(2) : rt::newarr<Array<Byte>>(2));
      if (decoderFallbackBuffer == nullptr) {
        decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
        decoderFallbackBuffer->InternalInitialize(ptr3, ptr2);
      }
      Char* chars2 = chars;
      Boolean flag4 = decoderFallbackBuffer->InternalFallback(array4, bytes, chars2);
      chars = chars2;
      if (!flag4) {
        bytes -= 2;
        if (num >= 0) {
          bytes--;
        }
        decoderFallbackBuffer->InternalReset();
        ThrowCharsOverflow(decoder, chars == ptr4);
        bytes += 2;
        if (num >= 0) {
          bytes++;
        }
        goto IL_04ea;
      }
      c = u'\0';
    }
    if (num >= 0) {
      if (decoderFallbackBuffer == nullptr) {
        decoderFallbackBuffer = ((decoder != nullptr) ? decoder->get_FallbackBuffer() : decoderFallback->CreateFallbackBuffer());
        decoderFallbackBuffer->InternalInitialize(ptr3, ptr2);
      }
      Char* chars2 = chars;
      Boolean flag5 = decoderFallbackBuffer->InternalFallback(rt::newarr<Array<Byte>>(1), bytes, chars2);
      chars = chars2;
      if (!flag5) {
        bytes--;
        decoderFallbackBuffer->InternalReset();
        ThrowCharsOverflow(decoder, chars == ptr4);
        bytes++;
      } else {
        num = -1;
      }
    }
  }
  goto IL_04ea;

IL_04ea:
  if (decoder != nullptr) {
    decoder->_bytesUsed = (Int32)(bytes - ptr3);
    decoder->lastChar = c;
    decoder->lastByte = num;
  }
  return (Int32)(chars - ptr4);
}

Encoder UnicodeEncoding___::GetEncoder() {
  return rt::newobj<EncoderNLS>((UnicodeEncoding)this);
}

Decoder UnicodeEncoding___::GetDecoder() {
  return rt::newobj<Decoder>((UnicodeEncoding)this);
}

Array<Byte> UnicodeEncoding___::GetPreamble() {
  if (byteOrderMark) {
    if (!bigEndian) {
      return rt::newarr<Array<Byte>>(2);
    }
    return rt::newarr<Array<Byte>>(2);
  }
  return Array<>::in::Empty<Byte>();
}

Int32 UnicodeEncoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount + 1;
  if (Encoding::in::get_EncoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_EncoderFallback()->get_MaxCharCount();
  }
  num <<= 1;
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 UnicodeEncoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)(byteCount >> 1) + (Int64)(byteCount & 1) + 1;
  if (Encoding::in::get_DecoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_DecoderFallback()->get_MaxCharCount();
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_GetCharCountOverflow());
  }
  return (Int32)num;
}

Boolean UnicodeEncoding___::Equals(Object value) {
  UnicodeEncoding unicodeEncoding = rt::as<UnicodeEncoding>(value);
  if (unicodeEncoding != nullptr) {
    if (get_CodePage() == unicodeEncoding->get_CodePage() && byteOrderMark == unicodeEncoding->byteOrderMark && bigEndian == unicodeEncoding->bigEndian && Encoding::in::get_EncoderFallback()->Equals(unicodeEncoding->get_EncoderFallback())) {
      return Encoding::in::get_DecoderFallback()->Equals(unicodeEncoding->get_DecoderFallback());
    }
    return false;
  }
  return false;
}

Int32 UnicodeEncoding___::GetHashCode() {
  return get_CodePage() + Encoding::in::get_EncoderFallback()->GetHashCode() + Encoding::in::get_DecoderFallback()->GetHashCode() + (byteOrderMark ? 4 : 0) + (bigEndian ? 8 : 0);
}

void UnicodeEncoding___::cctor() {
  s_bigEndianDefault = rt::newobj<UnicodeEncoding>(true, true);
  s_littleEndianDefault = rt::newobj<UnicodeEncoding>(false, true);
}

} // namespace System::Private::CoreLib::System::Text::UnicodeEncodingNamespace
