#include "DecoderDBCS-dep.h"

#include <System.Console/Interop-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Console/System/Text/OSEncoding-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Console::System::Text::DecoderDBCSNamespace {
using namespace ::System::Private::CoreLib::System;

void DecoderDBCS___::ctor(Encoding encoding) {
  _leadByteRanges = rt::newarr<Array<Byte>>(10);
  Decoder::in::ctor();
  _encoding = encoding;
  _rangesCount = Interop::Kernel32::GetLeadByteRanges(_encoding->get_CodePage(), _leadByteRanges);
  Reset();
}

Boolean DecoderDBCS___::IsLeadByte(Byte b) {
  if (b < _leadByteRanges[0]) {
    return false;
  }
  for (Int32 i = 0; i < _rangesCount; i += 2) {
    if (b >= _leadByteRanges[i] && b <= _leadByteRanges[i + 1]) {
      return true;
    }
  }
  return false;
}

void DecoderDBCS___::Reset() {
  _leftOverLeadByte = 0;
}

Int32 DecoderDBCS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return GetCharCount(bytes, index, count, false);
}

Int32 DecoderDBCS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (bytes->get_Length() - index < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytes", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count == 0 && (_leftOverLeadByte == 0 || !flush)) {
    return 0;
  }
  {
    Byte* ptr = bytes;
    Byte b;
    Byte* bytes2 = (ptr == nullptr) ? (&b) : (ptr + index);
    return GetCharCount(bytes2, count, flush);
  }
}

Int32 DecoderDBCS___::ConvertWithLeftOverByte(Byte* bytes, Int32 count, Char* chars, Int32 charCount) {
  Byte as[2] = {};
  Byte* ptr = as;
  *ptr = _leftOverLeadByte;
  Int32 num = 0;
  if (count > 0) {
    ptr[1] = *bytes;
    num++;
  }
  Int32 num2 = OSEncoding::in::MultiByteToWideChar(_encoding->get_CodePage(), ptr, num + 1, chars, charCount);
  if (count - num > 0) {
    num2 += OSEncoding::in::MultiByteToWideChar(_encoding->get_CodePage(), bytes + num, count - num, (Char*)(IntPtr)((chars == nullptr) ? ((IntPtr)(?)0) : ((IntPtr)(IntPtr)(chars + num2))), (chars != nullptr) ? (charCount - num2) : 0);
  }
  return num2;
}

Int32 DecoderDBCS___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Boolean flag = count > 0 && !flush && IsLastByteALeadByte(bytes, count);
  if (flag) {
    count--;
  }
  if (_leftOverLeadByte == 0) {
    if (count <= 0) {
      return 0;
    }
    return OSEncoding::in::MultiByteToWideChar(_encoding->get_CodePage(), bytes, count, nullptr, 0);
  }
  if (count == 0 && !flag && !flush) {
    return 0;
  }
  return ConvertWithLeftOverByte(bytes, count, nullptr, 0);
}

Int32 DecoderDBCS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return GetChars(bytes, byteIndex, byteCount, chars, charIndex, false);
}

Int32 DecoderDBCS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
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
  if (chars->get_Length() == 0) {
    return 0;
  }
  if (byteCount == 0 && (_leftOverLeadByte == 0 || !flush)) {
    return 0;
  }
  {
    Char* ptr2 = &chars[0];
    {
      Byte* ptr = bytes;
      Byte b;
      Byte* bytes2 = (ptr == nullptr) ? (&b) : (ptr + byteIndex);
      return GetChars(bytes2, byteCount, ptr2 + charIndex, chars->get_Length() - charIndex, flush);
    }
  }
}

Int32 DecoderDBCS___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (charCount == 0) {
    return 0;
  }
  Byte b = (Byte)((byteCount > 0 && !flush && IsLastByteALeadByte(bytes, byteCount)) ? bytes[byteCount - 1] : 0);
  if (b != 0) {
    byteCount--;
  }
  if (_leftOverLeadByte == 0) {
    if (byteCount <= 0) {
      _leftOverLeadByte = b;
      return 0;
    }
    Int32 result = OSEncoding::in::MultiByteToWideChar(_encoding->get_CodePage(), bytes, byteCount, chars, charCount);
    _leftOverLeadByte = b;
    return result;
  }
  if (byteCount == 0 && b == 0 && !flush) {
    return 0;
  }
  Int32 result2 = ConvertWithLeftOverByte(bytes, byteCount, chars, charCount);
  _leftOverLeadByte = b;
  return result2;
}

void DecoderDBCS___::Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
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
  if (charCount == 0 || (bytes->get_Length() == 0 && (_leftOverLeadByte == 0 || !flush))) {
    bytesUsed = 0;
    charsUsed = 0;
    completed = false;
    return;
  }
  {
    Char* ptr2 = &chars[0];
    {
      Byte* ptr = bytes;
      Byte b;
      Byte* bytes2 = (ptr == nullptr) ? (&b) : (ptr + byteIndex);
      Convert(bytes2, byteCount, ptr2 + charIndex, charCount, flush, bytesUsed, charsUsed, completed);
    }
  }
}

void DecoderDBCS___::Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 num;
  for (num = byteCount; num > 0; num /= 2) {
    Int32 charCount2 = GetCharCount(bytes, num, flush);
    if (charCount2 <= charCount) {
      break;
    }
  }
  if (num > 0) {
    charsUsed = GetChars(bytes, num, chars, charCount, flush);
    bytesUsed = num;
    completed = (_leftOverLeadByte == 0 && byteCount == num);
  } else {
    bytesUsed = 0;
    charsUsed = 0;
    completed = false;
  }
}

Boolean DecoderDBCS___::IsLastByteALeadByte(Byte* bytes, Int32 count) {
  if (!IsLeadByte(bytes[count - 1])) {
    return false;
  }
  Int32 i = 0;
  if (_leftOverLeadByte != 0) {
    i++;
  }
  for (; i < count; i++) {
    if (IsLeadByte(bytes[i])) {
      i++;
      if (i >= count) {
        return true;
      }
    }
  }
  return false;
}

} // namespace System::Console::System::Text::DecoderDBCSNamespace
