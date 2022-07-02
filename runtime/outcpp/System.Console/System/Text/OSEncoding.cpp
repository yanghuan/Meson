#include "OSEncoding-dep.h"

#include <System.Console/Interop-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Console/System/Text/DecoderDBCS-dep.h>
#include <System.Console/System/Text/OSEncoder-dep.h>
#include <System.Console/System/Text/OSEncoding-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Console::System::Text::OSEncodingNamespace {
using namespace ::System::Private::CoreLib::System;

String OSEncoding___::get_EncodingName() {
  if (_encodingName == nullptr) {
    _encodingName = "Codepage - " + _codePage;
  }
  return _encodingName;
}

String OSEncoding___::get_WebName() {
  return get_EncodingName();
}

void OSEncoding___::ctor(Int32 codePage) {
  _codePage = codePage;
}

Int32 OSEncoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
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
    return WideCharToMultiByte(_codePage, ptr + index, count, nullptr, 0);
  }
}

Int32 OSEncoding___::GetByteCount(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if (s->get_Length() == 0) {
    return 0;
  }
  {
    Char* ptr = rt::fixed(s);
    Char* pChars = ptr;
    return WideCharToMultiByte(_codePage, pChars, s->get_Length(), nullptr, 0);
  }
}

Int32 OSEncoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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
  if (charCount == 0) {
    return 0;
  }
  if (bytes->get_Length() == 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_Argument_EncodingConversionOverflowBytes());
  }
  {
    Char* ptr = rt::fixed(s);
    Char* ptr2 = ptr;
    {
      Byte* ptr3 = rt::fixed(&bytes[0]);
      return WideCharToMultiByte(_codePage, ptr2 + charIndex, charCount, ptr3 + byteIndex, bytes->get_Length() - byteIndex);
    }
  }
}

Int32 OSEncoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
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
  if (bytes->get_Length() == 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_Argument_EncodingConversionOverflowBytes());
  }
  {
    Char* ptr = rt::fixed(chars);
    {
      Byte* ptr2 = rt::fixed(&bytes[0]);
      return WideCharToMultiByte(_codePage, ptr + charIndex, charCount, ptr2 + byteIndex, bytes->get_Length() - byteIndex);
    }
  }
}

Int32 OSEncoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
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
    return MultiByteToWideChar(_codePage, ptr + index, count, nullptr, 0);
  }
}

Int32 OSEncoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
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
  if (chars->get_Length() == 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_Argument_EncodingConversionOverflowChars());
  }
  {
    Byte* ptr = rt::fixed(bytes);
    {
      Char* ptr2 = rt::fixed(&chars[0]);
      return MultiByteToWideChar(_codePage, ptr + byteIndex, byteCount, ptr2 + charIndex, chars->get_Length() - charIndex);
    }
  }
}

Int32 OSEncoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount * 14;
  if (num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 OSEncoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = byteCount * 4;
  if (num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_GetCharCountOverflow());
  }
  return (Int32)num;
}

Encoder OSEncoding___::GetEncoder() {
  return rt::newobj<OSEncoder>((OSEncoding)this);
}

Decoder OSEncoding___::GetDecoder() {
  switch (get_CodePage().get()) {
    case 932:
    case 936:
    case 949:
    case 950:
    case 1361:
    case 10001:
    case 10002:
    case 10003:
    case 10008:
    case 20000:
    case 20001:
    case 20002:
    case 20003:
    case 20004:
    case 20005:
    case 20261:
    case 20932:
    case 20936:
    case 51949:
      return rt::newobj<DecoderDBCS>((OSEncoding)this);
    default:
      return Encoding::in::GetDecoder();
  }
}

Int32 OSEncoding___::WideCharToMultiByte(Int32 codePage, Char* pChars, Int32 count, Byte* pBytes, Int32 byteCount) {
  Int32 num = Interop::Kernel32::WideCharToMultiByte((UInt32)codePage, 0u, pChars, count, pBytes, byteCount, IntPtr::Zero, IntPtr::Zero);
  if (num <= 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
  }
  return num;
}

Int32 OSEncoding___::MultiByteToWideChar(Int32 codePage, Byte* pBytes, Int32 byteCount, Char* pChars, Int32 count) {
  Int32 num = Interop::Kernel32::MultiByteToWideChar((UInt32)codePage, 0u, pBytes, byteCount, pChars, count);
  if (num <= 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex());
  }
  return num;
}

} // namespace System::Console::System::Text::OSEncodingNamespace
