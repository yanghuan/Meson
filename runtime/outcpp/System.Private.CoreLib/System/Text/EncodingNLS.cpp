#include "EncodingNLS-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/EncodingNLS-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingNLSNamespace {
using namespace System::Runtime::InteropServices;

void EncodingNLS___::ctor(Int32 codePage) {
}

Int32 EncodingNLS___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
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
    Char* ptr = rt::fixed(chars);
    return GetByteCount(ptr + index, count, nullptr);
  }
}

Int32 EncodingNLS___::GetByteCount(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  {
    Char* ptr = rt::fixed(s);
    Char* pChars = ptr;
    return GetByteCount(pChars, s->get_Length(), nullptr);
  }
}

Int32 EncodingNLS___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetByteCount(chars, count, nullptr);
}

Int32 EncodingNLS___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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
    Char* ptr = rt::fixed(s);
    Char* ptr2 = ptr;
    {
      Byte* ptr3 = rt::fixed(&MemoryMarshal::GetReference<Byte>(bytes));
      return GetBytes(ptr2 + charIndex, charCount, ptr3 + byteIndex, byteCount, nullptr);
    }
  }
}

Int32 EncodingNLS___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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
    Char* ptr = rt::fixed(chars);
    {
      Byte* ptr2 = rt::fixed(&MemoryMarshal::GetReference<Byte>(bytes));
      return GetBytes(ptr + charIndex, charCount, ptr2 + byteIndex, byteCount, nullptr);
    }
  }
}

Int32 EncodingNLS___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetBytes(chars, charCount, bytes, byteCount, nullptr);
}

Int32 EncodingNLS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
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
    Byte* ptr = rt::fixed(bytes);
    return GetCharCount(ptr + index, count, nullptr);
  }
}

Int32 EncodingNLS___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetCharCount(bytes, count, nullptr);
}

Int32 EncodingNLS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
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
    Byte* ptr = rt::fixed(bytes);
    {
      Char* ptr2 = rt::fixed(&MemoryMarshal::GetReference<Char>(chars));
      return GetChars(ptr + byteIndex, byteCount, ptr2 + charIndex, charCount, nullptr);
    }
  }
}

Int32 EncodingNLS___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return GetChars(bytes, byteCount, chars, charCount, nullptr);
}

String EncodingNLS___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
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
    Byte* ptr = rt::fixed(bytes);
    return String::in::CreateStringFromEncoding(ptr + index, count, (EncodingNLS)this);
  }
}

Decoder EncodingNLS___::GetDecoder() {
  return rt::newobj<DecoderNLS>((EncodingNLS)this);
}

Encoder EncodingNLS___::GetEncoder() {
  return rt::newobj<EncoderNLS>((EncodingNLS)this);
}

} // namespace System::Private::CoreLib::System::Text::EncodingNLSNamespace
