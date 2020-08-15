#include "UTF8Encoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf16Utility-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf8-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf8Utility-dep.h>
#include <System.Private.CoreLib/System/Text/UTF8Encoding-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Text::UTF8EncodingNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text::Unicode;

ReadOnlySpan<Byte> UTF8EncodingSealed___::get_Preamble() {
  if (!_emitUTF8Identifier) {
    return ReadOnlySpan<T>();
  }
  return get_PreambleSpan();
}

void UTF8EncodingSealed___::ctor(Boolean encoderShouldEmitUTF8Identifier) {
}

Object UTF8EncodingSealed___::Clone() {
  return rt::newobj<UTF8Encoding>(_emitUTF8Identifier);
}

Array<Byte> UTF8EncodingSealed___::GetBytes(String s) {
  if (s != nullptr && s->get_Length() <= 32) {
    return GetBytesForSmallInput(s);
  }
  return Encoding::in::GetBytes(s);
}

Array<Byte> UTF8EncodingSealed___::GetBytesForSmallInput(String s) {
  Byte default[96] = {};
  Byte* ptr = default;
  Int32 length = s->get_Length();
  Int32 bytesCommon;
  {
    Char* ptr2 = s;
    Char* pChars = ptr2;
    bytesCommon = GetBytesCommon(pChars, length, ptr, 96);
  }
  return Span<Byte>(*ptr, bytesCommon).ToArray();
}

String UTF8EncodingSealed___::GetString(Array<Byte> bytes) {
  if (bytes != nullptr && bytes->get_Length() <= 32) {
    return GetStringForSmallInput(bytes);
  }
  return Encoding::in::GetString(bytes);
}

String UTF8EncodingSealed___::GetStringForSmallInput(Array<Byte> bytes) {
  Char default[32] = {};
  Char* ptr = default;
  Int32 byteCount = bytes->get_Length();
  Int32 charsCommon;
  {
    Byte* pBytes = bytes;
    charsCommon = GetCharsCommon(pBytes, byteCount, ptr, 32);
  }
  return rt::newobj<String>(ReadOnlySpan<Char>(*ptr, charsCommon));
}

ReadOnlySpan<Byte> UTF8Encoding___::get_PreambleSpan() {
  return rt::newarr<Array<Byte>>(3);
}

ReadOnlySpan<Byte> UTF8Encoding___::get_Preamble() {
  if (!(GetType() != rt::typeof<UTF8Encoding>())) {
    if (!_emitUTF8Identifier) {
      return ReadOnlySpan<T>();
    }
    return get_PreambleSpan();
  }
  return ReadOnlySpan<Byte>(GetPreamble());
}

void UTF8Encoding___::ctor() {
}

void UTF8Encoding___::ctor(Boolean encoderShouldEmitUTF8Identifier) {
  _emitUTF8Identifier = encoderShouldEmitUTF8Identifier;
}

void UTF8Encoding___::ctor(Boolean encoderShouldEmitUTF8Identifier, Boolean throwOnInvalidBytes) {
  _isThrowException = throwOnInvalidBytes;
  if (_isThrowException) {
    SetDefaultFallbacks();
  }
}

void UTF8Encoding___::SetDefaultFallbacks() {
  if (_isThrowException) {
    encoderFallback = EncoderFallback::in::get_ExceptionFallback();
    decoderFallback = DecoderFallback::in::get_ExceptionFallback();
  } else {
    encoderFallback = rt::newobj<EncoderReplacementFallback>("�");
    decoderFallback = rt::newobj<DecoderReplacementFallback>("�");
  }
}

Int32 UTF8Encoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (chars->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::chars, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  {
    Char* ptr = chars;
    return GetByteCountCommon(ptr + index, count);
  }
}

Int32 UTF8Encoding___::GetByteCount(String chars) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars);
  }
  {
    Char* ptr = chars;
    Char* pChars = ptr;
    return GetByteCountCommon(pChars, chars->get_Length());
  }
}

Int32 UTF8Encoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars);
  }
  if (count < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetByteCountCommon(chars, count);
}

Int32 UTF8Encoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  {
    Char* pChars = &MemoryMarshal::GetReference(chars);
    return GetByteCountCommon(pChars, chars.get_Length());
  }
}

Int32 UTF8Encoding___::GetByteCountCommon(Char* pChars, Int32 charCount) {
  Int32 charsConsumed;
  Int32 num = GetByteCountFast(pChars, charCount, nullptr, charsConsumed);
  if (charsConsumed != charCount) {
    num += GetByteCountWithFallback(pChars, charCount, charsConsumed);
    if (num < 0) {
      Encoding::in::ThrowConversionOverflow();
    }
  }
  return num;
}

Int32 UTF8Encoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  Int64 utf8CodeUnitCountAdjustment;
  Int32 scalarCountAdjustment;
  Char* pointerToFirstInvalidChar = Utf16Utility::GetPointerToFirstInvalidChar(pChars, charsLength, utf8CodeUnitCountAdjustment, scalarCountAdjustment);
  Int64 num = (charsConsumed = (Int32)(pointerToFirstInvalidChar - pChars)) + utf8CodeUnitCountAdjustment;
  if ((UInt64)num > 2147483647) {
    Encoding::in::ThrowConversionOverflow();
  }
  return (Int32)num;
}

Int32 UTF8Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (s == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((s == nullptr) ? ExceptionArgument::s : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((charIndex | charCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((charIndex < 0) ? ExceptionArgument::charIndex : ExceptionArgument::charCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (s->get_Length() - charIndex < charCount) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::s, ExceptionResource::ArgumentOutOfRange_IndexCount);
  }
  if ((UInt32)byteIndex > bytes->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::byteIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  {
    Char* ptr = s;
    Char* ptr2 = ptr;
    {
      Byte* ptr3 = bytes;
      return GetBytesCommon(ptr2 + charIndex, charCount, ptr3 + byteIndex, bytes->get_Length() - byteIndex);
    }
  }
}

Int32 UTF8Encoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((charIndex | charCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((charIndex < 0) ? ExceptionArgument::charIndex : ExceptionArgument::charCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (chars->get_Length() - charIndex < charCount) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::chars, ExceptionResource::ArgumentOutOfRange_IndexCount);
  }
  if ((UInt32)byteIndex > bytes->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::byteIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  {
    Char* ptr = chars;
    {
      Byte* ptr2 = bytes;
      return GetBytesCommon(ptr + charIndex, charCount, ptr2 + byteIndex, bytes->get_Length() - byteIndex);
    }
  }
}

Int32 UTF8Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((charCount | byteCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((charCount < 0) ? ExceptionArgument::charCount : ExceptionArgument::byteCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetBytesCommon(chars, charCount, bytes, byteCount);
}

Int32 UTF8Encoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  {
    Char* pChars = &MemoryMarshal::GetReference(chars);
    {
      Byte* pBytes = &MemoryMarshal::GetReference(bytes);
      return GetBytesCommon(pChars, chars.get_Length(), pBytes, bytes.get_Length());
    }
  }
}

Int32 UTF8Encoding___::GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount) {
  Int32 charsConsumed;
  Int32 bytesFast = GetBytesFast(pChars, charCount, pBytes, byteCount, charsConsumed);
  if (charsConsumed == charCount) {
    return bytesFast;
  }
  return GetBytesWithFallback(pChars, charCount, pBytes, byteCount, charsConsumed, bytesFast);
}

Int32 UTF8Encoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  Char* pInputBufferRemaining;
  Byte* pOutputBufferRemaining;
  Utf8Utility::TranscodeToUtf8(pChars, charsLength, pBytes, bytesLength, pInputBufferRemaining, pOutputBufferRemaining);
  charsConsumed = (Int32)(pInputBufferRemaining - pChars);
  return (Int32)(pOutputBufferRemaining - pBytes);
}

Int32 UTF8Encoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  {
    Byte* ptr = bytes;
    return GetCharCountCommon(ptr + index, count);
  }
}

Int32 UTF8Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if (count < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetCharCountCommon(bytes, count);
}

Int32 UTF8Encoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  {
    Byte* pBytes = &MemoryMarshal::GetReference(bytes);
    return GetCharCountCommon(pBytes, bytes.get_Length());
  }
}

Int32 UTF8Encoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  if (bytes == nullptr || chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException((bytes == nullptr) ? ExceptionArgument::bytes : ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
  if ((byteIndex | byteCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((byteIndex < 0) ? ExceptionArgument::byteIndex : ExceptionArgument::byteCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - byteIndex < byteCount) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  if ((UInt32)charIndex > (UInt32)chars->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::charIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  {
    Byte* ptr = bytes;
    {
      Char* ptr2 = chars;
      return GetCharsCommon(ptr + byteIndex, byteCount, ptr2 + charIndex, chars->get_Length() - charIndex);
    }
  }
}

Int32 UTF8Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException((bytes == nullptr) ? ExceptionArgument::bytes : ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
  if ((byteCount | charCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((byteCount < 0) ? ExceptionArgument::byteCount : ExceptionArgument::charCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetCharsCommon(bytes, byteCount, chars, charCount);
}

Int32 UTF8Encoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  {
    Byte* pBytes = &MemoryMarshal::GetReference(bytes);
    {
      Char* pChars = &MemoryMarshal::GetReference(chars);
      return GetCharsCommon(pBytes, bytes.get_Length(), pChars, chars.get_Length());
    }
  }
}

Int32 UTF8Encoding___::GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount) {
  Int32 bytesConsumed;
  Int32 charsFast = GetCharsFast(pBytes, byteCount, pChars, charCount, bytesConsumed);
  if (bytesConsumed == byteCount) {
    return charsFast;
  }
  return GetCharsWithFallback(pBytes, byteCount, pChars, charCount, bytesConsumed, charsFast);
}

Int32 UTF8Encoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  Byte* pInputBufferRemaining;
  Char* pOutputBufferRemaining;
  Utf8Utility::TranscodeToUtf16(pBytes, bytesLength, pChars, charsLength, pInputBufferRemaining, pOutputBufferRemaining);
  bytesConsumed = (Int32)(pInputBufferRemaining - pBytes);
  return (Int32)(pOutputBufferRemaining - pChars);
}

Int32 UTF8Encoding___::GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder) {
  DecoderReplacementFallback decoderReplacementFallback = rt::as<DecoderReplacementFallback>(((decoder == nullptr) ? Encoding::in::get_DecoderFallback() : decoder->get_Fallback()));
  if (decoderReplacementFallback != nullptr && decoderReplacementFallback->get_MaxCharCount() == 1 && decoderReplacementFallback->get_DefaultString()[0] == 65533) {
    Int32 bytesRead;
    Int32 charsWritten;
    auto& default = decoder;
    auto& extern = default == nullptr ? nullptr : default->get_MustFlush();
    Utf8::ToUtf16(bytes, chars, bytesRead, charsWritten, true, extern != nullptr ? extern : true);
    bytes = bytes.Slice(bytesRead);
    chars = chars.Slice(charsWritten);
  }
  if (bytes.get_IsEmpty()) {
    return originalCharsLength - chars.get_Length();
  }
  return Encoding::in::GetCharsWithFallback(bytes, originalBytesLength, chars, originalCharsLength, decoder);
}

String UTF8Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  if (count == 0) {
    return String::in::Empty;
  }
  {
    Byte* ptr = bytes;
    return String::in::CreateStringFromEncoding(ptr + index, count, (UTF8Encoding)this);
  }
}

Int32 UTF8Encoding___::GetCharCountCommon(Byte* pBytes, Int32 byteCount) {
  Int32 bytesConsumed;
  Int32 num = GetCharCountFast(pBytes, byteCount, nullptr, bytesConsumed);
  if (bytesConsumed != byteCount) {
    num += GetCharCountWithFallback(pBytes, byteCount, bytesConsumed);
    if (num < 0) {
      Encoding::in::ThrowConversionOverflow();
    }
  }
  return num;
}

Int32 UTF8Encoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  Int32 utf16CodeUnitCountAdjustment;
  Int32 scalarCountAdjustment;
  Byte* pointerToFirstInvalidByte = Utf8Utility::GetPointerToFirstInvalidByte(pBytes, bytesLength, utf16CodeUnitCountAdjustment, scalarCountAdjustment);
  return (bytesConsumed = (Int32)(pointerToFirstInvalidByte - pBytes)) + utf16CodeUnitCountAdjustment;
}

Decoder UTF8Encoding___::GetDecoder() {
  return rt::newobj<DecoderNLS>((UTF8Encoding)this);
}

Encoder UTF8Encoding___::GetEncoder() {
  return rt::newobj<EncoderNLS>((UTF8Encoding)this);
}

Boolean UTF8Encoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  byteCount = value.get_Utf8SequenceLength();
  return true;
}

OperationStatus UTF8Encoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  if (!value.TryEncodeToUtf8(bytes, bytesWritten)) {
    return OperationStatus::DestinationTooSmall;
  }
  return OperationStatus::Done;
}

OperationStatus UTF8Encoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  return Rune::DecodeFromUtf8(bytes, value, bytesConsumed);
}

Int32 UTF8Encoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount + 1;
  if (Encoding::in::get_EncoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_EncoderFallback()->get_MaxCharCount();
  }
  num *= 3;
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 UTF8Encoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)byteCount + 1;
  if (Encoding::in::get_DecoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_DecoderFallback()->get_MaxCharCount();
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_GetCharCountOverflow());
  }
  return (Int32)num;
}

Array<Byte> UTF8Encoding___::GetPreamble() {
  if (_emitUTF8Identifier) {
    return rt::newarr<Array<Byte>>(3);
  }
  return Array<>::in::Empty<Byte>();
}

Boolean UTF8Encoding___::Equals(Object value) {
  UTF8Encoding uTF8Encoding = rt::as<UTF8Encoding>(value);
  if (uTF8Encoding != nullptr) {
    if (_emitUTF8Identifier == uTF8Encoding->_emitUTF8Identifier && Encoding::in::get_EncoderFallback()->Equals(uTF8Encoding->get_EncoderFallback())) {
      return Encoding::in::get_DecoderFallback()->Equals(uTF8Encoding->get_DecoderFallback());
    }
    return false;
  }
  return false;
}

Int32 UTF8Encoding___::GetHashCode() {
  return Encoding::in::get_EncoderFallback()->GetHashCode() + Encoding::in::get_DecoderFallback()->GetHashCode() + 65001 + (_emitUTF8Identifier ? 1 : 0);
}

void UTF8Encoding___::cctor() {
  s_default = rt::newobj<UTF8EncodingSealed>(true);
}

} // namespace System::Private::CoreLib::System::Text::UTF8EncodingNamespace
