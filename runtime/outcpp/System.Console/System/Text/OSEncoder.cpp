#include "OSEncoder-dep.h"

#include <System.Console/System/SR-dep.h>
#include <System.Console/System/Text/OSEncoding-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Console::System::Text::OSEncoderNamespace {
using namespace ::System::Private::CoreLib::System;

void OSEncoder___::ctor(Encoding encoding) {
  _encoding = encoding;
  Reset();
}

void OSEncoder___::Reset() {
  _charLeftOver = u'\0';
}

Int32 OSEncoder___::GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (chars->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("chars", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (chars->get_Length() == 0 && (_charLeftOver == u'\0' || !flush)) {
    return 0;
  }
  {
    Char* ptr = chars;
    Char c;
    Char* chars2 = ((ptr == nullptr) ? (&c) : (ptr + index));
    return GetByteCount(chars2, count, flush);
  }
}

Int32 OSEncoder___::ConvertWithLeftOverChar(Char* chars, Int32 count, Byte* bytes, Int32 byteCount) {
  Char as[2] = {};
  Char* ptr = as;
  *ptr = _charLeftOver;
  Int32 num = 0;
  if (count > 0 && Char::IsLowSurrogate(*chars)) {
    ptr[1] = *chars;
    num++;
  }
  Int32 num2 = OSEncoding::in::WideCharToMultiByte(_encoding->get_CodePage(), ptr, num + 1, bytes, byteCount);
  if (count - num > 0) {
    num2 += OSEncoding::in::WideCharToMultiByte(_encoding->get_CodePage(), chars + num, count - num, (Byte*)((bytes == nullptr) ? ((IntPtr)(void*)(void*)nullptr) : ((IntPtr)(bytes + num2))), (bytes != nullptr) ? (byteCount - num2) : 0);
  }
  return num2;
}

Int32 OSEncoder___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Boolean flag = count > 0 && !flush && Char::IsHighSurrogate(*(chars + count - 1));
  if (flag) {
    count--;
  }
  if (_charLeftOver == u'\0') {
    if (count <= 0) {
      return 0;
    }
    return OSEncoding::in::WideCharToMultiByte(_encoding->get_CodePage(), chars, count, nullptr, 0);
  }
  if (count == 0 && !flag && !flush) {
    return 0;
  }
  return ConvertWithLeftOverChar(chars, count, nullptr, 0);
}

Int32 OSEncoder___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush) {
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
  if (bytes->get_Length() == 0) {
    return 0;
  }
  if (charCount == 0 && (_charLeftOver == u'\0' || !flush)) {
    return 0;
  }
  {
    Char* ptr = chars;
    {
      Byte* ptr2 = &bytes[0];
      Char c;
      Char* chars2 = ((ptr == nullptr) ? (&c) : (ptr + charIndex));
      return GetBytes(chars2, charCount, ptr2 + byteIndex, bytes->get_Length() - byteIndex, flush);
    }
  }
}

Int32 OSEncoder___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (byteCount == 0) {
    return 0;
  }
  Char c = ((charCount > 0 && !flush && Char::IsHighSurrogate(*(chars + charCount - 1))) ? *(chars + charCount - 1) : u'\0');
  if (c != 0) {
    charCount--;
  }
  if (_charLeftOver == u'\0') {
    if (charCount <= 0) {
      _charLeftOver = c;
      return 0;
    }
    Int32 result = OSEncoding::in::WideCharToMultiByte(_encoding->get_CodePage(), chars, charCount, bytes, byteCount);
    _charLeftOver = c;
    return result;
  }
  if (charCount == 0 && c == u'\0' && !flush) {
    return 0;
  }
  Int32 result2 = ConvertWithLeftOverChar(chars, charCount, bytes, byteCount);
  _charLeftOver = c;
  return result2;
}

void OSEncoder___::Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
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
  if (bytes->get_Length() == 0 || (chars->get_Length() == 0 && (_charLeftOver == u'\0' || !flush))) {
    bytesUsed = 0;
    charsUsed = 0;
    completed = false;
    return;
  }
  {
    Char* ptr = chars;
    {
      Byte* ptr2 = &bytes[0];
      Char c;
      Char* chars2 = ((ptr == nullptr) ? (&c) : (ptr + charIndex));
      Convert(chars2, charCount, ptr2 + byteIndex, byteCount, flush, charsUsed, bytesUsed, completed);
    }
  }
}

void OSEncoder___::Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 num;
  for (num = charCount; num > 0; num /= 2) {
    Int32 byteCount2 = GetByteCount(chars, num, flush);
    if (byteCount2 <= byteCount) {
      break;
    }
  }
  if (num > 0) {
    bytesUsed = GetBytes(chars, num, bytes, byteCount, flush);
    charsUsed = num;
    completed = _charLeftOver == u'\0' && charCount == num;
  } else {
    bytesUsed = 0;
    charsUsed = 0;
    completed = false;
  }
}

} // namespace System::Console::System::Text::OSEncoderNamespace
