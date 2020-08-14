#include "UTF7Encoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/UTF7Encoding-dep.h>

namespace System::Private::CoreLib::System::Text::UTF7EncodingNamespace {
using namespace System::Runtime::InteropServices;

Boolean UTF7Encoding___::Decoder___::get_HasState() {
  return bitCount != -1;
}

void UTF7Encoding___::Decoder___::ctor(UTF7Encoding encoding) {
}

void UTF7Encoding___::Decoder___::Reset() {
  bits = 0;
  bitCount = -1;
  firstByte = false;
  if (_fallbackBuffer != nullptr) {
    _fallbackBuffer->Reset();
  }
}

Boolean UTF7Encoding___::Encoder___::get_HasState() {
  if (bits == 0) {
    return bitCount != -1;
  }
  return true;
}

void UTF7Encoding___::Encoder___::ctor(UTF7Encoding encoding) {
}

void UTF7Encoding___::Encoder___::Reset() {
  bitCount = -1;
  bits = 0;
  if (_fallbackBuffer != nullptr) {
    _fallbackBuffer->Reset();
  }
}

Int32 UTF7Encoding___::DecoderUTF7Fallback___::get_MaxCharCount() {
  return 1;
}

DecoderFallbackBuffer UTF7Encoding___::DecoderUTF7Fallback___::CreateFallbackBuffer() {
  return rt::newobj<DecoderUTF7FallbackBuffer>();
}

Boolean UTF7Encoding___::DecoderUTF7Fallback___::Equals(Object value) {
  return rt::is<DecoderUTF7Fallback>(value);
}

Int32 UTF7Encoding___::DecoderUTF7Fallback___::GetHashCode() {
  return 984;
}

void UTF7Encoding___::DecoderUTF7Fallback___::ctor() {
}

Int32 UTF7Encoding___::DecoderUTF7FallbackBuffer___::get_Remaining() {
  if (iCount <= 0) {
    return 0;
  }
  return iCount;
}

Boolean UTF7Encoding___::DecoderUTF7FallbackBuffer___::Fallback(Array<Byte> bytesUnknown, Int32 index) {
  cFallback = (Char)bytesUnknown[0];
  if (cFallback == 0) {
    return false;
  }
  iCount = (iSize = 1);
  return true;
}

Char UTF7Encoding___::DecoderUTF7FallbackBuffer___::GetNextChar() {
  if (iCount-- > 0) {
    return cFallback;
  }
  return 0;
}

Boolean UTF7Encoding___::DecoderUTF7FallbackBuffer___::MovePrevious() {
  if (iCount >= 0) {
    iCount++;
  }
  if (iCount >= 0) {
    return iCount <= iSize;
  }
  return false;
}

void UTF7Encoding___::DecoderUTF7FallbackBuffer___::Reset() {
  iCount = -1;
  byteStart = nullptr;
}

Int32 UTF7Encoding___::DecoderUTF7FallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes) {
  if (bytes->get_Length() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
  }
  if (bytes[0] != 0) {
    return 1;
  }
  return 0;
}

void UTF7Encoding___::DecoderUTF7FallbackBuffer___::ctor() {
  iCount = -1;
  DecoderFallbackBuffer::ctor();
}

void UTF7Encoding___::ctor() {
}

void UTF7Encoding___::ctor(Boolean allowOptionals) {
  _allowOptionals = allowOptionals;
  MakeTables();
}

void UTF7Encoding___::MakeTables() {
  _base64Bytes = rt::newarr<Array<Byte>>(64);
  for (Int32 i = 0; i < 64; i++) {
    _base64Bytes[i] = (Byte)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i];
  }
  _base64Values = rt::newarr<Array<SByte>>(128);
  for (Int32 j = 0; j < 128; j++) {
    _base64Values[j] = -1;
  }
  for (Int32 k = 0; k < 64; k++) {
    _base64Values[_base64Bytes[k]] = (SByte)k;
  }
  _directEncode = rt::newarr<Array<Boolean>>(128);
  Int32 length = "	
 '(),-./0123456789:?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"->get_Length();
  for (Int32 l = 0; l < length; l++) {
    _directEncode["	
 '(),-./0123456789:?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[l]] = true;
  }
  if (_allowOptionals) {
    length = "!"#$%&*;<=>@[]^_`{|}"->get_Length();
    for (Int32 m = 0; m < length; m++) {
      _directEncode["!"#$%&*;<=>@[]^_`{|}"[m]] = true;
    }
  }
}

void UTF7Encoding___::SetDefaultFallbacks() {
  encoderFallback = rt::newobj<EncoderReplacementFallback>(String::in::Empty);
  decoderFallback = rt::newobj<DecoderUTF7Fallback>();
}

Boolean UTF7Encoding___::Equals(Object value) {
  UTF7Encoding uTF7Encoding = rt::as<UTF7Encoding>(value);
  if (uTF7Encoding != nullptr) {
    if (_allowOptionals == uTF7Encoding->_allowOptionals && Encoding::get_EncoderFallback()->Equals(uTF7Encoding->get_EncoderFallback())) {
      return Encoding::get_DecoderFallback()->Equals(uTF7Encoding->get_DecoderFallback());
    }
    return false;
  }
  return false;
}

Int32 UTF7Encoding___::GetHashCode() {
  return get_CodePage() + Encoding::get_EncoderFallback()->GetHashCode() + Encoding::get_DecoderFallback()->GetHashCode();
}

Int32 UTF7Encoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
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

Int32 UTF7Encoding___::GetByteCount(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  {
    Char* ptr = s;
    Char* pChars = ptr;
    return GetByteCount(pChars, s->get_Length(), nullptr);
  }
}

Int32 UTF7Encoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetByteCount(chars, count, nullptr);
}

Int32 UTF7Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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

Int32 UTF7Encoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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

Int32 UTF7Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetBytes(chars, charCount, bytes, byteCount, nullptr);
}

Int32 UTF7Encoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
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

Int32 UTF7Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetCharCount(bytes, count, nullptr);
}

Int32 UTF7Encoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
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

Int32 UTF7Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetChars(bytes, byteCount, chars, charCount, nullptr);
}

String UTF7Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
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
    return String::in::CreateStringFromEncoding(ptr + index, count, (UTF7Encoding)this);
  }
}

Int32 UTF7Encoding___::GetByteCount(Char* chars, Int32 count, EncoderNLS baseEncoder) {
  return GetBytes(chars, count, nullptr, 0, baseEncoder);
}

Int32 UTF7Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS baseEncoder) {
  Encoder encoder = (Encoder)baseEncoder;
  Int32 num = 0;
  Int32 num2 = -1;
  Encoding::in::EncodingByteBuffer encodingByteBuffer = rt::newobj<Encoding::in::EncodingByteBuffer>((UTF7Encoding)this, encoder, bytes, byteCount, chars, charCount);
  if (encoder != nullptr) {
    num = encoder->bits;
    num2 = encoder->bitCount;
    while (num2 >= 6) {
      num2 -= 6;
      if (!encodingByteBuffer->AddByte(_base64Bytes[(num >> num2) & 63])) {
        ThrowBytesOverflow(encoder, encodingByteBuffer->get_Count() == 0);
      }
    }
  }
  while (encodingByteBuffer->get_MoreData()) {
    Char nextChar = encodingByteBuffer->GetNextChar();
    if (nextChar < 128 && _directEncode[nextChar]) {
      if (num2 >= 0) {
        if (num2 > 0) {
          if (!encodingByteBuffer->AddByte(_base64Bytes[(num << 6 - num2) & 63])) {
            break;
          }
          num2 = 0;
        }
        if (!encodingByteBuffer->AddByte(45)) {
          break;
        }
        num2 = -1;
      }
      if (!encodingByteBuffer->AddByte((Byte)nextChar)) {
        break;
      }
      continue;
    }
    if (num2 < 0 && nextChar == 43) {
      if (!encodingByteBuffer->AddByte((?)43, (?)45)) {
        break;
      }
      continue;
    }
    if (num2 < 0) {
      if (!encodingByteBuffer->AddByte(43)) {
        break;
      }
      num2 = 0;
    }
    num = ((num << 16) | nextChar);
    num2 += 16;
    while (num2 >= 6) {
      num2 -= 6;
      if (!encodingByteBuffer->AddByte(_base64Bytes[(num >> num2) & 63])) {
        num2 += 6;
        encodingByteBuffer->GetNextChar();
        break;
      }
    }
    if (num2 >= 6) {
      break;
    }
  }
  if (num2 >= 0 && (encoder == nullptr || encoder->get_MustFlush())) {
    if (num2 > 0 && encodingByteBuffer->AddByte(_base64Bytes[(num << 6 - num2) & 63])) {
      num2 = 0;
    }
    if (encodingByteBuffer->AddByte(45)) {
      num = 0;
      num2 = -1;
    } else {
      encodingByteBuffer->GetNextChar();
    }
  }
  if (bytes != nullptr && encoder != nullptr) {
    encoder->bits = num;
    encoder->bitCount = num2;
    encoder->_charsUsed = encodingByteBuffer->get_CharsUsed();
  }
  return encodingByteBuffer->get_Count();
}

Int32 UTF7Encoding___::GetCharCount(Byte* bytes, Int32 count, DecoderNLS baseDecoder) {
  return GetChars(bytes, count, nullptr, 0, baseDecoder);
}

Int32 UTF7Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS baseDecoder) {
  Decoder decoder = (Decoder)baseDecoder;
  Encoding::in::EncodingCharBuffer encodingCharBuffer = rt::newobj<Encoding::in::EncodingCharBuffer>((UTF7Encoding)this, decoder, chars, charCount, bytes, byteCount);
  Int32 num = 0;
  Int32 num2 = -1;
  Boolean flag = false;
  if (decoder != nullptr) {
    num = decoder->bits;
    num2 = decoder->bitCount;
    flag = decoder->firstByte;
  }
  if (num2 >= 16) {
    if (!encodingCharBuffer->AddChar((Char)((num >> num2 - 16) & 65535))) {
      ThrowCharsOverflow(decoder, true);
    }
    num2 -= 16;
  }
  while (encodingCharBuffer->get_MoreData()) {
    Byte nextByte = encodingCharBuffer->GetNextByte();
    Int32 num3;
    if (num2 >= 0) {
      SByte b;
      if (nextByte < 128 && (b = _base64Values[nextByte]) >= 0) {
        flag = false;
        num = ((num << 6) | (Byte)b);
        num2 += 6;
        if (num2 < 16) {
          continue;
        }
        num3 = ((num >> num2 - 16) & 65535);
        num2 -= 16;
      } else {
        num2 = -1;
        if (nextByte != 45) {
          if (!encodingCharBuffer->Fallback(nextByte)) {
            break;
          }
          continue;
        }
        if (!flag) {
          continue;
        }
        num3 = 43;
      }
    } else {
      if (nextByte == 43) {
        num2 = 0;
        flag = true;
        continue;
      }
      if (nextByte >= 128) {
        if (!encodingCharBuffer->Fallback(nextByte)) {
          break;
        }
        continue;
      }
      num3 = nextByte;
    }
    if (num3 >= 0 && !encodingCharBuffer->AddChar((Char)num3)) {
      if (num2 >= 0) {
        encodingCharBuffer->AdjustBytes(1);
        num2 += 16;
      }
      break;
    }
  }
  if (chars != nullptr && decoder != nullptr) {
    if (decoder->get_MustFlush()) {
      decoder->bits = 0;
      decoder->bitCount = -1;
      decoder->firstByte = false;
    } else {
      decoder->bits = num;
      decoder->bitCount = num2;
      decoder->firstByte = flag;
    }
    decoder->_bytesUsed = encodingCharBuffer->get_BytesUsed();
  }
  return encodingCharBuffer->get_Count();
}

Decoder UTF7Encoding___::GetDecoder() {
  return rt::newobj<Decoder>((UTF7Encoding)this);
}

Encoder UTF7Encoding___::GetEncoder() {
  return rt::newobj<Encoder>((UTF7Encoding)this);
}

Int32 UTF7Encoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount * 3 + 2;
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 UTF7Encoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 num = byteCount;
  if (num == 0) {
    num = 1;
  }
  return num;
}

void UTF7Encoding___::cctor() {
  s_default = rt::newobj<UTF7Encoding>();
}

} // namespace System::Private::CoreLib::System::Text::UTF7EncodingNamespace
