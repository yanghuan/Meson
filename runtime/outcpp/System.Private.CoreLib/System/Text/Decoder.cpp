#include "Decoder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderNamespace {
using namespace System::Runtime::InteropServices;

DecoderFallback Decoder___::get_Fallback() {
  return _fallback;
}

void Decoder___::set_Fallback(DecoderFallback value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (_fallbackBuffer != nullptr && _fallbackBuffer->get_Remaining() > 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_FallbackBufferNotEmpty(), "value");
  }
  _fallback = value;
  _fallbackBuffer = nullptr;
}

DecoderFallbackBuffer Decoder___::get_FallbackBuffer() {
  if (_fallbackBuffer == nullptr) {
    if (_fallback != nullptr) {
      _fallbackBuffer = _fallback->CreateFallbackBuffer();
    } else {
      _fallbackBuffer = DecoderFallback::in::get_ReplacementFallback()->CreateFallbackBuffer();
    }
  }
  return _fallbackBuffer;
}

Boolean Decoder___::get_InternalHasFallbackBuffer() {
  return _fallbackBuffer != nullptr;
}

void Decoder___::ctor() {
}

void Decoder___::Reset() {
  Array<Byte> bytes = Array<>::in::Empty<Byte>();
  Array<Char> chars = rt::newarr<Array<Char>>(GetCharCount(bytes, 0, 0, true));
  GetChars(bytes, 0, 0, chars, 0, true);
  DecoderFallbackBuffer fallbackBuffer = _fallbackBuffer;
  if (fallbackBuffer != nullptr) {
    fallbackBuffer->Reset();
  }
}

Int32 Decoder___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  return GetCharCount(bytes, index, count);
}

Int32 Decoder___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(count);
  for (Int32 i = 0; i < count; i++) {
    array[i] = *(bytes + i);
  }
  return GetCharCount(array, 0, count);
}

Int32 Decoder___::GetCharCount(ReadOnlySpan<Byte> bytes, Boolean flush) {
  {
    Byte* bytes2 = rt::fixed(&MemoryMarshal::GetNonNullPinnableReference(bytes));
    return GetCharCount(bytes2, bytes.get_Length(), flush);
  }
}

Int32 Decoder___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
  return GetChars(bytes, byteIndex, byteCount, chars, charIndex);
}

Int32 Decoder___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(byteCount);
  for (Int32 i = 0; i < byteCount; i++) {
    array[i] = *(bytes + i);
  }
  Array<Char> array2 = rt::newarr<Array<Char>>(charCount);
  Int32 chars2 = GetChars(array, 0, byteCount, array2, 0, flush);
  if (chars2 < charCount) {
    charCount = chars2;
  }
  for (Int32 i = 0; i < charCount; i++) {
    *(chars + i) = array2[i];
  }
  return charCount;
}

Int32 Decoder___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Boolean flush) {
  {
    Byte* bytes2 = rt::fixed(&MemoryMarshal::GetNonNullPinnableReference(bytes));
    {
      Char* chars2 = rt::fixed(&MemoryMarshal::GetNonNullPinnableReference(chars));
      return GetChars(bytes2, bytes.get_Length(), chars2, chars.get_Length(), flush);
    }
  }
}

void Decoder___::Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (byteIndex < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteIndex < 0) ? "byteIndex" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (charIndex < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charIndex < 0) ? "charIndex" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (bytes->get_Length() - byteIndex < byteCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (chars->get_Length() - charIndex < charCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("chars", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  for (bytesUsed = byteCount; bytesUsed > 0; bytesUsed /= 2) {
    if (GetCharCount(bytes, byteIndex, bytesUsed, flush) <= charCount) {
      charsUsed = GetChars(bytes, byteIndex, bytesUsed, chars, charIndex, flush);
      completed = bytesUsed == byteCount && (_fallbackBuffer == nullptr || _fallbackBuffer->get_Remaining() == 0);
      return;
    }
    flush = false;
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ConversionOverflow());
}

void Decoder___::Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  for (bytesUsed = byteCount; bytesUsed > 0; bytesUsed /= 2) {
    if (GetCharCount(bytes, bytesUsed, flush) <= charCount) {
      charsUsed = GetChars(bytes, bytesUsed, chars, charCount, flush);
      completed = bytesUsed == byteCount && (_fallbackBuffer == nullptr || _fallbackBuffer->get_Remaining() == 0);
      return;
    }
    flush = false;
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ConversionOverflow());
}

void Decoder___::Convert(ReadOnlySpan<Byte> bytes, Span<Char> chars, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  {
    Byte* bytes2 = rt::fixed(&MemoryMarshal::GetNonNullPinnableReference(bytes));
    {
      Char* chars2 = rt::fixed(&MemoryMarshal::GetNonNullPinnableReference(chars));
      Convert(bytes2, bytes.get_Length(), chars2, chars.get_Length(), flush, bytesUsed, charsUsed, completed);
    }
  }
}

} // namespace System::Private::CoreLib::System::Text::DecoderNamespace
