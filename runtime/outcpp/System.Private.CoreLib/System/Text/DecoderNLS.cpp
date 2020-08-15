#include "DecoderNLS-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffers/OperationStatus.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderNLSNamespace {
using namespace System::Buffers;
using namespace System::Runtime::InteropServices;

Boolean DecoderNLS___::get_MustFlush() {
  return _mustFlush;
}

Boolean DecoderNLS___::get_HasState() {
  return _leftoverByteCount != 0;
}

Boolean DecoderNLS___::get_HasLeftoverData() {
  return _leftoverByteCount != 0;
}

void DecoderNLS___::ctor(Encoding encoding) {
  _encoding = encoding;
  _fallback = _encoding->set_DecoderFallback;
  Reset();
}

void DecoderNLS___::Reset() {
  ClearLeftoverData();
  auto& default = _fallbackBuffer;
  default == nullptr ? nullptr : default->Reset();
}

Int32 DecoderNLS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return GetCharCount(bytes, index, count, false);
}

Int32 DecoderNLS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (bytes->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  {
    Byte* ptr = &MemoryMarshal::GetReference<Byte>(bytes);
    return GetCharCount(ptr + index, count, flush);
  }
}

Int32 DecoderNLS___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  _mustFlush = flush;
  _throwOnOverflow = true;
  return _encoding->GetCharCount(bytes, count, (DecoderNLS)this);
}

Int32 DecoderNLS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return GetChars(bytes, byteIndex, byteCount, chars, charIndex, false);
}

Int32 DecoderNLS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
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
  Int32 charCount = chars->get_Length() - charIndex;
  {
    Byte* ptr = &MemoryMarshal::GetReference<Byte>(bytes);
    {
      Char* ptr2 = &MemoryMarshal::GetReference<Char>(chars);
      return GetChars(ptr + byteIndex, byteCount, ptr2 + charIndex, charCount, flush);
    }
  }
}

Int32 DecoderNLS___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  _mustFlush = flush;
  _throwOnOverflow = true;
  return _encoding->GetChars(bytes, byteCount, chars, charCount, (DecoderNLS)this);
}

void DecoderNLS___::Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
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
  {
    Byte* ptr = &MemoryMarshal::GetReference<Byte>(bytes);
    {
      Char* ptr2 = &MemoryMarshal::GetReference<Char>(chars);
      Convert(ptr + byteIndex, byteCount, ptr2 + charIndex, charCount, flush, bytesUsed, charsUsed, completed);
    }
  }
}

void DecoderNLS___::Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  _mustFlush = flush;
  _throwOnOverflow = false;
  _bytesUsed = 0;
  charsUsed = _encoding->GetChars(bytes, byteCount, chars, charCount, (DecoderNLS)this);
  bytesUsed = _bytesUsed;
  completed = (bytesUsed == byteCount && (!flush || !get_HasState()) && (_fallbackBuffer == nullptr || _fallbackBuffer->get_Remaining() == 0));
}

void DecoderNLS___::ClearMustFlush() {
  _mustFlush = false;
}

ReadOnlySpan<Byte> DecoderNLS___::GetLeftoverData() {
  return MemoryMarshal::AsBytes(ReadOnlySpan<Int32>(_leftoverBytes, 1)).Slice(0, _leftoverByteCount);
}

void DecoderNLS___::SetLeftoverData(ReadOnlySpan<Byte> bytes) {
  bytes.CopyTo(MemoryMarshal::AsBytes(Span<Int32>(_leftoverBytes, 1)));
  _leftoverByteCount = bytes.get_Length();
}

void DecoderNLS___::ClearLeftoverData() {
  _leftoverByteCount = 0;
}

Int32 DecoderNLS___::DrainLeftoverDataForGetCharCount(ReadOnlySpan<Byte> bytes, Int32& bytesConsumed) {
  Byte default[4] = {};
  Span<Byte> span = Span<Byte>(default, 4);
  Span<Byte> span2 = span;
  span2 = span2.Slice(0, ConcatInto(GetLeftoverData(), bytes, span2));
  Int32 result = 0;
  Rune value;
  Int32 bytesConsumed2;
}

Int32 DecoderNLS___::DrainLeftoverDataForGetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Int32& bytesConsumed) {
  Byte default[4] = {};
  Span<Byte> span = Span<Byte>(default, 4);
  Span<Byte> span2 = span;
  span2 = span2.Slice(0, ConcatInto(GetLeftoverData(), bytes, span2));
  Int32 charsWritten = 0;
  Boolean flag = false;
  Rune value;
  Int32 bytesConsumed2;
  switch (_encoding->DecodeFirstRune(span2, value, bytesConsumed2)) {
    case OperationStatus::Done:
      if (!value.TryEncodeToUtf16(chars, charsWritten)) {
        break;
      }
      goto IL_00aa;
    case OperationStatus::NeedMoreData:
      if (get_MustFlush()) {
      }
      flag = true;
      goto IL_00aa;
    default:
      {
        if (Decoder::get_FallbackBuffer()->Fallback(span2.Slice(0, bytesConsumed2).ToArray(), -_leftoverByteCount) && !_fallbackBuffer->TryDrainRemainingDataForGetChars(chars, charsWritten)) {
          break;
        }
        goto IL_00aa;
      }
    IL_00aa:
      bytesConsumed = bytesConsumed2 - _leftoverByteCount;
      if (flag) {
        SetLeftoverData(span2);
      } else {
        ClearLeftoverData();
      }
      return charsWritten;
  }
  _encoding->ThrowCharsOverflow((DecoderNLS)this, true);
  rt::throw_exception(nullptr);
}

Int32 DecoderNLS___::ConcatInto(ReadOnlySpan<Byte> srcLeft, ReadOnlySpan<Byte> srcRight, Span<Byte> dest) {
  Int32 num = 0;
  Int32 num2 = 0;
  while (true) {
    if (num2 < srcLeft.get_Length()) {
      if ((UInt32)num >= (UInt32)dest.get_Length()) {
        break;
      }
      dest[num++] = srcLeft[num2];
      num2++;
      continue;
    }
    for (Int32 i = 0; i < srcRight.get_Length(); i++) {
      if ((UInt32)num >= (UInt32)dest.get_Length()) {
        break;
      }
      dest[num++] = srcRight[i];
    }
    break;
  }
  return num;
}

} // namespace System::Private::CoreLib::System::Text::DecoderNLSNamespace
