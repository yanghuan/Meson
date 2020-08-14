#include "EncoderNLS-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderNLS-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderNLSNamespace {
using namespace System::Runtime::InteropServices;

Encoding EncoderNLS___::get_Encoding() {
  return _encoding;
}

Boolean EncoderNLS___::get_MustFlush() {
  return _mustFlush;
}

Boolean EncoderNLS___::get_HasLeftoverData() {
  if (_charLeftOver == 0) {
    if (_fallbackBuffer != nullptr) {
      return _fallbackBuffer->get_Remaining() > 0;
    }
    return false;
  }
  return true;
}

Boolean EncoderNLS___::get_HasState() {
  return _charLeftOver != 0;
}

void EncoderNLS___::ctor(Encoding encoding) {
  _encoding = encoding;
  _fallback = _encoding->set_EncoderFallback;
  Reset();
}

void EncoderNLS___::Reset() {
  _charLeftOver = 0;
  if (_fallbackBuffer != nullptr) {
    _fallbackBuffer->Reset();
  }
}

Int32 EncoderNLS___::GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (chars->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("chars", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  Int32 num = -1;
  {
    Char* ptr = &MemoryMarshal::GetReference<Char>(chars);
    num = GetByteCount(ptr + index, count, flush);
  }
  return num;
}

Int32 EncoderNLS___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  _mustFlush = flush;
  _throwOnOverflow = true;
  return _encoding->GetByteCount(chars, count, (EncoderNLS)this);
}

Int32 EncoderNLS___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush) {
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
  Int32 byteCount = bytes->get_Length() - byteIndex;
  {
    Char* ptr = &MemoryMarshal::GetReference<Char>(chars);
    {
      Byte* ptr2 = &MemoryMarshal::GetReference<Byte>(bytes);
      return GetBytes(ptr + charIndex, charCount, ptr2 + byteIndex, byteCount, flush);
    }
  }
}

Int32 EncoderNLS___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  _mustFlush = flush;
  _throwOnOverflow = true;
  return _encoding->GetBytes(chars, charCount, bytes, byteCount, (EncoderNLS)this);
}

void EncoderNLS___::Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
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
  {
    Char* ptr = &MemoryMarshal::GetReference<Char>(chars);
    {
      Byte* ptr2 = &MemoryMarshal::GetReference<Byte>(bytes);
      Convert(ptr + charIndex, charCount, ptr2 + byteIndex, byteCount, flush, charsUsed, bytesUsed, completed);
    }
  }
}

void EncoderNLS___::Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  _mustFlush = flush;
  _throwOnOverflow = false;
  _charsUsed = 0;
  bytesUsed = _encoding->GetBytes(chars, charCount, bytes, byteCount, (EncoderNLS)this);
  charsUsed = _charsUsed;
  completed = (charsUsed == charCount && (!flush || !get_HasState()) && (_fallbackBuffer == nullptr || _fallbackBuffer->get_Remaining() == 0));
}

void EncoderNLS___::ClearMustFlush() {
  _mustFlush = false;
}

Int32 EncoderNLS___::DrainLeftoverDataForGetByteCount(ReadOnlySpan<Char> chars, Int32& charsConsumed) {
  if (_fallbackBuffer != nullptr && _fallbackBuffer->get_Remaining() > 0) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_EncoderFallbackNotEmpty(), get_Encoding()->get_EncodingName(), _fallbackBuffer->GetType()));
  }
  charsConsumed = 0;
  if (_charLeftOver == 0) {
    return 0;
  }
  Char c = 0;
  if (chars.get_IsEmpty()) {
    if (!get_MustFlush()) {
      return 0;
    }
  } else {
    c = chars[0];
  }
}

Boolean EncoderNLS___::TryDrainLeftoverDataForGetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsConsumed, Int32& bytesWritten) {
  charsConsumed = 0;
  bytesWritten = 0;
  if (_charLeftOver != 0) {
    Char c = 0;
    if (chars.get_IsEmpty()) {
      if (!get_MustFlush()) {
        charsConsumed = 0;
        bytesWritten = 0;
        return true;
      }
    } else {
      c = chars[0];
    }
    Char charLeftOver = _charLeftOver;
    _charLeftOver = 0;
  }
  if (_fallbackBuffer != nullptr && _fallbackBuffer->get_Remaining() > 0) {
    return _fallbackBuffer->TryDrainRemainingDataForGetBytes(bytes, bytesWritten);
  }
  return true;
}

} // namespace System::Private::CoreLib::System::Text::EncoderNLSNamespace
