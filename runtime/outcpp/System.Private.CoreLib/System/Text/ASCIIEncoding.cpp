#include "ASCIIEncoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIEncoding-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIUtility-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::ASCIIEncodingNamespace {
using namespace System::Runtime::InteropServices;

Object ASCIIEncodingSealed___::Clone() {
  return rt::newobj<ASCIIEncoding>();
}

void ASCIIEncodingSealed___::ctor() {
}

Boolean ASCIIEncoding___::get_IsSingleByte() {
  return true;
}

void ASCIIEncoding___::ctor() {
}

void ASCIIEncoding___::SetDefaultFallbacks() {
  encoderFallback = EncoderFallback::in::get_ReplacementFallback();
  decoderFallback = DecoderFallback::in::get_ReplacementFallback();
}

Int32 ASCIIEncoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetByteCount(String chars) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars);
  }
  {
    Char* ptr = chars;
    Char* pChars = ptr;
    return GetByteCountCommon(pChars, chars->get_Length());
  }
}

Int32 ASCIIEncoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars);
  }
  if (count < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetByteCountCommon(chars, count);
}

Int32 ASCIIEncoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  {
    Char* pChars = &MemoryMarshal::GetReference(chars);
    return GetByteCountCommon(pChars, chars.get_Length());
  }
}

Int32 ASCIIEncoding___::GetByteCountCommon(Char* pChars, Int32 charCount) {
  Int32 charsConsumed;
}

Int32 ASCIIEncoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  Int32 num = charsLength;
  EncoderReplacementFallback encoderReplacementFallback = rt::as<EncoderReplacementFallback>(fallback);
  if (encoderReplacementFallback == nullptr || encoderReplacementFallback->get_MaxCharCount() != 1 || encoderReplacementFallback->get_DefaultString()[0] > 127) {
    num = (Int32)ASCIIUtility::GetIndexOfFirstNonAsciiChar(pChars, (UInt32)charsLength);
  }
  charsConsumed = num;
  return num;
}

Int32 ASCIIEncoding___::GetBytes(String chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  {
    Char* pChars = &MemoryMarshal::GetReference(chars);
    {
      Byte* pBytes = &MemoryMarshal::GetReference(bytes);
      return GetBytesCommon(pChars, chars.get_Length(), pBytes, bytes.get_Length());
    }
  }
}

Int32 ASCIIEncoding___::GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount) {
  Int32 charsConsumed;
  Int32 bytesFast = GetBytesFast(pChars, charCount, pBytes, byteCount, charsConsumed);
  if (charsConsumed == charCount) {
    return bytesFast;
  }
  return GetBytesWithFallback(pChars, charCount, pBytes, byteCount, charsConsumed, bytesFast);
}

Int32 ASCIIEncoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  return charsConsumed = (Int32)ASCIIUtility::NarrowUtf16ToAscii(pChars, pBytes, (UInt32)Math::Min(charsLength, bytesLength));
}

Int32 ASCIIEncoding___::GetBytesWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, Span<Byte> bytes, Int32 originalBytesLength, EncoderNLS encoder) {
}

Int32 ASCIIEncoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if (count < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetCharCountCommon(bytes, count);
}

Int32 ASCIIEncoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  {
    Byte* pBytes = &MemoryMarshal::GetReference(bytes);
    return GetCharCountCommon(pBytes, bytes.get_Length());
  }
}

Int32 ASCIIEncoding___::GetCharCountCommon(Byte* pBytes, Int32 byteCount) {
  Int32 bytesConsumed;
}

Int32 ASCIIEncoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  Int32 num = bytesLength;
  DecoderReplacementFallback decoderReplacementFallback = rt::as<DecoderReplacementFallback>(fallback);
  if (decoderReplacementFallback == nullptr || decoderReplacementFallback->get_MaxCharCount() != 1) {
    num = (Int32)ASCIIUtility::GetIndexOfFirstNonAsciiByte(pBytes, (UInt32)bytesLength);
  }
  bytesConsumed = num;
  return num;
}

Int32 ASCIIEncoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  if (bytes == nullptr || chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException((bytes == nullptr) ? ExceptionArgument::bytes : ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException((bytes == nullptr) ? ExceptionArgument::bytes : ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
}

Int32 ASCIIEncoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  {
    Byte* pBytes = &MemoryMarshal::GetReference(bytes);
    {
      Char* pChars = &MemoryMarshal::GetReference(chars);
      return GetCharsCommon(pBytes, bytes.get_Length(), pChars, chars.get_Length());
    }
  }
}

Int32 ASCIIEncoding___::GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount) {
  Int32 bytesConsumed;
  Int32 charsFast = GetCharsFast(pBytes, byteCount, pChars, charCount, bytesConsumed);
  if (bytesConsumed == byteCount) {
    return charsFast;
  }
  return GetCharsWithFallback(pBytes, byteCount, pChars, charCount, bytesConsumed, charsFast);
}

Int32 ASCIIEncoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  return bytesConsumed = (Int32)ASCIIUtility::WidenAsciiToUtf16(pBytes, pChars, (UInt32)Math::Min(bytesLength, charsLength));
}

Int32 ASCIIEncoding___::GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder) {
}

String ASCIIEncoding___::GetString(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
}

Boolean ASCIIEncoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  if (value.get_IsAscii()) {
    byteCount = 1;
    return true;
  }
  byteCount = 0;
  return false;
}

OperationStatus ASCIIEncoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  if (value.get_IsAscii()) {
    if (!bytes.get_IsEmpty()) {
      bytes[0] = (Byte)value.get_Value();
      bytesWritten = 1;
      return OperationStatus::Done;
    }
    bytesWritten = 0;
    return OperationStatus::DestinationTooSmall;
  }
  bytesWritten = 0;
  return OperationStatus::InvalidData;
}

OperationStatus ASCIIEncoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  if (!bytes.get_IsEmpty()) {
    Byte b = bytes[0];
    if (b <= 127) {
      value = Rune(b);
      bytesConsumed = 1;
      return OperationStatus::Done;
    }
    value = Rune::get_ReplacementChar();
    bytesConsumed = 1;
    return OperationStatus::InvalidData;
  }
  value = Rune::get_ReplacementChar();
  bytesConsumed = 0;
  return OperationStatus::NeedMoreData;
}

Int32 ASCIIEncoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount + 1;
}

Int32 ASCIIEncoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = byteCount;
}

Decoder ASCIIEncoding___::GetDecoder() {
  return rt::newobj<DecoderNLS>((ASCIIEncoding)this);
}

Encoder ASCIIEncoding___::GetEncoder() {
  return rt::newobj<EncoderNLS>((ASCIIEncoding)this);
}

void ASCIIEncoding___::cctor() {
  s_default = rt::newobj<ASCIIEncodingSealed>();
}

} // namespace System::Private::CoreLib::System::Text::ASCIIEncodingNamespace
