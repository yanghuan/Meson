#include "Encoder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderNamespace {
using namespace System::Runtime::InteropServices;

EncoderFallback Encoder___::get_Fallback() {
  return _fallback;
}

void Encoder___::set_Fallback(EncoderFallback value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (_fallbackBuffer != nullptr && _fallbackBuffer->get_Remaining() > 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_FallbackBufferNotEmpty(), "value");
  }
  _fallback = value;
  _fallbackBuffer = nullptr;
}

EncoderFallbackBuffer Encoder___::get_FallbackBuffer() {
  if (_fallbackBuffer == nullptr) {
    if (_fallback != nullptr) {
      _fallbackBuffer = _fallback->CreateFallbackBuffer();
    } else {
      _fallbackBuffer = EncoderFallback::in::get_ReplacementFallback()->CreateFallbackBuffer();
    }
  }
  return _fallbackBuffer;
}

Boolean Encoder___::get_InternalHasFallbackBuffer() {
  return _fallbackBuffer != nullptr;
}

void Encoder___::ctor() {
}

void Encoder___::Reset() {
  Array<Char> chars = Array<>::in::Empty<Char>();
  Array<Byte> bytes = rt::newarr<Array<Byte>>(GetByteCount(chars, 0, 0, true));
  GetBytes(chars, 0, 0, bytes, 0, true);
  if (_fallbackBuffer != nullptr) {
    _fallbackBuffer->Reset();
  }
}

Int32 Encoder___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Char> array = rt::newarr<Array<Char>>(count);
  for (Int32 i = 0; i < count; i++) {
    array[i] = chars[i];
  }
  return GetByteCount(array, 0, count, flush);
}

Int32 Encoder___::GetByteCount(ReadOnlySpan<Char> chars, Boolean flush) {
  {
    Char* chars2 = &MemoryMarshal::GetNonNullPinnableReference(chars);
    return GetByteCount(chars2, chars.get_Length(), flush);
  }
}

Int32 Encoder___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Char> array = rt::newarr<Array<Char>>(charCount);
  for (Int32 i = 0; i < charCount; i++) {
    array[i] = chars[i];
  }
  Array<Byte> array2 = rt::newarr<Array<Byte>>(byteCount);
  Int32 bytes2 = GetBytes(array, 0, charCount, array2, 0, flush);
  if (bytes2 < byteCount) {
    byteCount = bytes2;
  }
  for (Int32 i = 0; i < byteCount; i++) {
    bytes[i] = array2[i];
  }
  return byteCount;
}

Int32 Encoder___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Boolean flush) {
  {
    Char* chars2 = &MemoryMarshal::GetNonNullPinnableReference(chars);
    {
      Byte* bytes2 = &MemoryMarshal::GetNonNullPinnableReference(bytes);
      return GetBytes(chars2, chars.get_Length(), bytes2, bytes.get_Length(), flush);
    }
  }
}

void Encoder___::Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (charIndex < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charIndex < 0) ? "charIndex" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (byteIndex < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteIndex < 0) ? "byteIndex" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (chars->get_Length() - charIndex < charCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("chars", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (bytes->get_Length() - byteIndex < byteCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  for (charsUsed = charCount; charsUsed > 0; charsUsed /= 2) {
    if (GetByteCount(chars, charIndex, charsUsed, flush) <= byteCount) {
      bytesUsed = GetBytes(chars, charIndex, charsUsed, bytes, byteIndex, flush);
      completed = (charsUsed == charCount && (_fallbackBuffer == nullptr || _fallbackBuffer->get_Remaining() == 0));
      return;
    }
    flush = false;
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ConversionOverflow());
}

void Encoder___::Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  for (charsUsed = charCount; charsUsed > 0; charsUsed /= 2) {
    if (GetByteCount(chars, charsUsed, flush) <= byteCount) {
      bytesUsed = GetBytes(chars, charsUsed, bytes, byteCount, flush);
      completed = (charsUsed == charCount && (_fallbackBuffer == nullptr || _fallbackBuffer->get_Remaining() == 0));
      return;
    }
    flush = false;
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ConversionOverflow());
}

void Encoder___::Convert(ReadOnlySpan<Char> chars, Span<Byte> bytes, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  {
    Char* chars2 = &MemoryMarshal::GetNonNullPinnableReference(chars);
    {
      Byte* bytes2 = &MemoryMarshal::GetNonNullPinnableReference(bytes);
      Convert(chars2, chars.get_Length(), bytes2, bytes.get_Length(), flush, charsUsed, bytesUsed, completed);
    }
  }
}

} // namespace System::Private::CoreLib::System::Text::EncoderNamespace
