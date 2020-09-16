#include "Encoding-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ASCIIEncoding-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/EncodingTable-dep.h>
#include <System.Private.CoreLib/System/Text/Latin1Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/NormalizationForm.h>
#include <System.Private.CoreLib/System/Text/TranscodingStream-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeEncoding-dep.h>
#include <System.Private.CoreLib/System/Text/UTF32Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/UTF7Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/UTF8Encoding-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

void Encoding___::DefaultEncoder___::ctor(Encoding encoding) {
  _encoding = encoding;
}

Object Encoding___::DefaultEncoder___::GetRealObject(StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Int32 Encoding___::DefaultEncoder___::GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush) {
  return _encoding->GetByteCount(chars, index, count);
}

Int32 Encoding___::DefaultEncoder___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  return _encoding->GetByteCount(chars, count);
}

Int32 Encoding___::DefaultEncoder___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush) {
  return _encoding->GetBytes(chars, charIndex, charCount, bytes, byteIndex);
}

Int32 Encoding___::DefaultEncoder___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  return _encoding->GetBytes(chars, charCount, bytes, byteCount);
}

void Encoding___::DefaultDecoder___::ctor(Encoding encoding) {
  _encoding = encoding;
}

Object Encoding___::DefaultDecoder___::GetRealObject(StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Int32 Encoding___::DefaultDecoder___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return GetCharCount(bytes, index, count, false);
}

Int32 Encoding___::DefaultDecoder___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  return _encoding->GetCharCount(bytes, index, count);
}

Int32 Encoding___::DefaultDecoder___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  return _encoding->GetCharCount(bytes, count);
}

Int32 Encoding___::DefaultDecoder___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return GetChars(bytes, byteIndex, byteCount, chars, charIndex, false);
}

Int32 Encoding___::DefaultDecoder___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
  return _encoding->GetChars(bytes, byteIndex, byteCount, chars, charIndex);
}

Int32 Encoding___::DefaultDecoder___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  return _encoding->GetChars(bytes, byteCount, chars, charCount);
}

Boolean Encoding___::EncodingCharBuffer___::get_MoreData() {
  return _bytes < _byteEnd;
}

Int32 Encoding___::EncodingCharBuffer___::get_BytesUsed() {
  return (Int32)(_bytes - _byteStart);
}

Int32 Encoding___::EncodingCharBuffer___::get_Count() {
  return _charCountResult;
}

void Encoding___::EncodingCharBuffer___::ctor(Encoding enc, DecoderNLS decoder, Char* charStart, Int32 charCount, Byte* byteStart, Int32 byteCount) {
  _enc = enc;
  _decoder = decoder;
  _chars = charStart;
  _charStart = charStart;
  _charEnd = charStart + charCount;
  _byteStart = byteStart;
  _bytes = byteStart;
  _byteEnd = byteStart + byteCount;
  if (_decoder == nullptr) {
    _fallbackBuffer = enc->get_DecoderFallback()->CreateFallbackBuffer();
  } else {
    _fallbackBuffer = _decoder->get_FallbackBuffer();
  }
  _fallbackBuffer->InternalInitialize(_bytes, _charEnd);
}

Boolean Encoding___::EncodingCharBuffer___::AddChar(Char ch, Int32 numBytes) {
  if (_chars != nullptr) {
    if (_chars >= _charEnd) {
      _bytes -= numBytes;
      _enc->ThrowCharsOverflow(_decoder, _bytes <= _byteStart);
      return false;
    }
    Char* chars = _chars;
    _chars = chars + 1;
    *chars = ch;
  }
  _charCountResult++;
  return true;
}

Boolean Encoding___::EncodingCharBuffer___::AddChar(Char ch) {
  return AddChar(ch, 1);
}

void Encoding___::EncodingCharBuffer___::AdjustBytes(Int32 count) {
  _bytes += count;
}

Byte Encoding___::EncodingCharBuffer___::GetNextByte() {
  if (_bytes >= _byteEnd) {
    return 0;
  }
  return *(_bytes++);
}

Boolean Encoding___::EncodingCharBuffer___::Fallback(Byte fallbackByte) {
  Array<Byte> byteBuffer = rt::newarr<Array<Byte>>(1);
  return Fallback(byteBuffer);
}

Boolean Encoding___::EncodingCharBuffer___::Fallback(Array<Byte> byteBuffer) {
  if (_chars != nullptr) {
    Char* chars = _chars;
    if (!_fallbackBuffer->InternalFallback(byteBuffer, _bytes, _chars)) {
      _bytes -= byteBuffer->get_Length();
      _fallbackBuffer->InternalReset();
      _enc->ThrowCharsOverflow(_decoder, _chars == _charStart);
      return false;
    }
    _charCountResult += (Int32)(_chars - chars);
  } else {
    _charCountResult += _fallbackBuffer->InternalFallback(byteBuffer, _bytes);
  }
  return true;
}

Boolean Encoding___::EncodingByteBuffer___::get_MoreData() {
  if (fallbackBuffer->get_Remaining() <= 0) {
    return _chars < _charEnd;
  }
  return true;
}

Int32 Encoding___::EncodingByteBuffer___::get_CharsUsed() {
  return (Int32)(_chars - _charStart);
}

Int32 Encoding___::EncodingByteBuffer___::get_Count() {
  return _byteCountResult;
}

void Encoding___::EncodingByteBuffer___::ctor(Encoding inEncoding, EncoderNLS inEncoder, Byte* inByteStart, Int32 inByteCount, Char* inCharStart, Int32 inCharCount) {
  _enc = inEncoding;
  _encoder = inEncoder;
  _charStart = inCharStart;
  _chars = inCharStart;
  _charEnd = inCharStart + inCharCount;
  _bytes = inByteStart;
  _byteStart = inByteStart;
  _byteEnd = inByteStart + inByteCount;
  if (_encoder == nullptr) {
    fallbackBuffer = _enc->get_EncoderFallback()->CreateFallbackBuffer();
  } else {
    fallbackBuffer = _encoder->get_FallbackBuffer();
    if (_encoder->_throwOnOverflow && _encoder->get_InternalHasFallbackBuffer() && fallbackBuffer->get_Remaining() > 0) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_EncoderFallbackNotEmpty(), _encoder->get_Encoding()->get_EncodingName(), _encoder->get_Fallback()->GetType()));
    }
  }
  fallbackBuffer->InternalInitialize(_chars, _charEnd, _encoder, _bytes != nullptr);
}

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b, Int32 moreBytesExpected) {
  if (_bytes != nullptr) {
    if (_bytes >= _byteEnd - moreBytesExpected) {
      MovePrevious(true);
      return false;
    }
    *(_bytes++) = b;
  }
  _byteCountResult++;
  return true;
}

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b1) {
  return AddByte(b1, 0);
}

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b1, Byte b2) {
  return AddByte(b1, b2, 0);
}

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b1, Byte b2, Int32 moreBytesExpected) {
  if (AddByte(b1, 1 + moreBytesExpected)) {
    return AddByte(b2, moreBytesExpected);
  }
  return false;
}

void Encoding___::EncodingByteBuffer___::MovePrevious(Boolean bThrow) {
  if (fallbackBuffer->bFallingBack) {
    fallbackBuffer->MovePrevious();
  } else if (_chars > _charStart) {
    _chars--;
  }

  if (bThrow) {
    _enc->ThrowBytesOverflow(_encoder, _bytes == _byteStart);
  }
}

Char Encoding___::EncodingByteBuffer___::GetNextChar() {
  Char c = fallbackBuffer->InternalGetNextChar();
  if (c == '\0' && _chars < _charEnd) {
    Char* chars = _chars;
    _chars = chars + 1;
    c = *chars;
  }
  return c;
}

Encoding Encoding___::get_Default() {
  return s_defaultEncoding;
}

ReadOnlySpan<Byte> Encoding___::get_Preamble() {
  return GetPreamble();
}

String Encoding___::get_BodyName() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return _dataItem->get_BodyName();
}

String Encoding___::get_EncodingName() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return _dataItem->get_DisplayName();
}

String Encoding___::get_HeaderName() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return _dataItem->get_HeaderName();
}

String Encoding___::get_WebName() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return _dataItem->get_WebName();
}

Int32 Encoding___::get_WindowsCodePage() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return _dataItem->get_UIFamilyCodePage();
}

Boolean Encoding___::get_IsBrowserDisplay() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return (_dataItem->get_Flags() & 2) != 0;
}

Boolean Encoding___::get_IsBrowserSave() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return (_dataItem->get_Flags() & 512) != 0;
}

Boolean Encoding___::get_IsMailNewsDisplay() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return (_dataItem->get_Flags() & 1) != 0;
}

Boolean Encoding___::get_IsMailNewsSave() {
  if (_dataItem == nullptr) {
    GetDataItem();
  }
  return (_dataItem->get_Flags() & 256) != 0;
}

Boolean Encoding___::get_IsSingleByte() {
  return false;
}

EncoderFallback Encoding___::get_EncoderFallback() {
  return encoderFallback;
}

void Encoding___::set_EncoderFallback(EncoderFallback value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  encoderFallback = value;
}

DecoderFallback Encoding___::get_DecoderFallback() {
  return decoderFallback;
}

void Encoding___::set_DecoderFallback(DecoderFallback value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  decoderFallback = value;
}

Boolean Encoding___::get_IsReadOnly() {
  return _isReadOnly;
}

void Encoding___::set_IsReadOnly(Boolean value) {
  _isReadOnly = value;
}

Encoding Encoding___::get_ASCII() {
  return ASCIIEncoding::in::s_default;
}

Encoding Encoding___::get_Latin1() {
  return Latin1Encoding::in::s_default;
}

Int32 Encoding___::get_CodePage() {
  return _codePage;
}

Encoding Encoding___::get_Unicode() {
  return UnicodeEncoding::in::s_littleEndianDefault;
}

Encoding Encoding___::get_BigEndianUnicode() {
  return UnicodeEncoding::in::s_bigEndianDefault;
}

Encoding Encoding___::get_UTF7() {
  return UTF7Encoding::in::s_default;
}

Encoding Encoding___::get_UTF8() {
  return UTF8Encoding::in::s_default;
}

Encoding Encoding___::get_UTF32() {
  return UTF32Encoding::in::s_default;
}

Encoding Encoding___::get_BigEndianUTF32() {
  return UTF32Encoding::in::s_bigEndianDefault;
}

void Encoding___::ctor() {
}

void Encoding___::ctor(Int32 codePage) {
  _isReadOnly = true;
  Object::in::ctor();
  if (codePage < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("codePage");
  }
  _codePage = codePage;
  SetDefaultFallbacks();
}

void Encoding___::ctor(Int32 codePage, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  _isReadOnly = true;
  Object::in::ctor();
  if (codePage < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("codePage");
  }
  _codePage = codePage;
  EncoderFallback as = encoderFallback;
  this->encoderFallback = (as != nullptr ? as : EncoderFallback::in::get_ReplacementFallback());
  DecoderFallback is = decoderFallback;
  this->decoderFallback = (is != nullptr ? is : DecoderFallback::in::get_ReplacementFallback());
}

void Encoding___::SetDefaultFallbacks() {
  encoderFallback = EncoderFallback::in::get_ReplacementFallback();
  decoderFallback = DecoderFallback::in::get_ReplacementFallback();
}

Array<Byte> Encoding___::Convert(Encoding srcEncoding, Encoding dstEncoding, Array<Byte> bytes) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes");
  }
  return Convert(srcEncoding, dstEncoding, bytes, 0, bytes->get_Length());
}

Array<Byte> Encoding___::Convert(Encoding srcEncoding, Encoding dstEncoding, Array<Byte> bytes, Int32 index, Int32 count) {
  if (srcEncoding == nullptr || dstEncoding == nullptr) {
    rt::throw_exception<ArgumentNullException>((srcEncoding == nullptr) ? "srcEncoding" : "dstEncoding", SR::get_ArgumentNull_Array());
  }
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  return dstEncoding->GetBytes(srcEncoding->GetChars(bytes, index, count));
}

void Encoding___::RegisterProvider(EncodingProvider provider) {
  EncodingProvider::in::AddProvider(provider);
}

Encoding Encoding___::GetEncoding(Int32 codepage) {
  Encoding encoding = FilterDisallowedEncodings(EncodingProvider::in::GetEncodingFromProvider(codepage));
  if (encoding != nullptr) {
    return encoding;
  }
  switch (codepage.get()) {
    case 0:
      return get_Default();
    case 1200:
      return get_Unicode();
    case 1201:
      return get_BigEndianUnicode();
    case 12000:
      return get_UTF32();
    case 12001:
      return get_BigEndianUTF32();
    case 65001:
      return get_UTF8();
    case 20127:
      return get_ASCII();
    case 28591:
      return get_Latin1();
    case 1:
    case 2:
    case 3:
    case 42:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_CodepageNotSupported(), codepage), "codepage");
    case 65000:
      {
        if (LocalAppContextSwitches::get_EnableUnsafeUTF7Encoding()) {
          return get_UTF7();
        }
        String p = String::in::Format(CultureInfo::in::get_InvariantCulture(), "https://aka.ms/dotnet-warnings/{0}", "SYSLIB0001");
        String message = SR::Format(SR::get_Encoding_UTF7_Disabled(), p);
        rt::throw_exception<NotSupportedException>(message);
      }default:
      if (codepage < 0 || codepage > 65535) {
        rt::throw_exception<ArgumentOutOfRangeException>("codepage", SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 65535));
      }
      rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_NoCodepageData(), codepage));
  }
}

Encoding Encoding___::GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  Encoding encoding = FilterDisallowedEncodings(EncodingProvider::in::GetEncodingFromProvider(codepage, encoderFallback, decoderFallback));
  if (encoding != nullptr) {
    return encoding;
  }
  encoding = GetEncoding(codepage);
  Encoding encoding2 = (Encoding)encoding->Clone();
  encoding2->set_EncoderFallback(encoderFallback);
  encoding2->set_DecoderFallback(decoderFallback);
  return encoding2;
}

Encoding Encoding___::GetEncoding(String name) {
  Encoding as = FilterDisallowedEncodings(EncodingProvider::in::GetEncodingFromProvider(name));
  return as != nullptr ? as : GetEncoding(EncodingTable::GetCodePageFromName(name));
}

Encoding Encoding___::GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  Encoding as = FilterDisallowedEncodings(EncodingProvider::in::GetEncodingFromProvider(name, encoderFallback, decoderFallback));
  return as != nullptr ? as : GetEncoding(EncodingTable::GetCodePageFromName(name), encoderFallback, decoderFallback);
}

Encoding Encoding___::FilterDisallowedEncodings(Encoding encoding) {
  if (LocalAppContextSwitches::get_EnableUnsafeUTF7Encoding()) {
    return encoding;
  }
  if (encoding == nullptr || encoding->get_CodePage() != 65000) {
    return encoding;
  }
  return nullptr;
}

Array<EncodingInfo> Encoding___::GetEncodings() {
  Dictionary<Int32, EncodingInfo> encodingListFromProviders = EncodingProvider::in::GetEncodingListFromProviders();
  if (encodingListFromProviders != nullptr) {
    return EncodingTable::GetEncodings(encodingListFromProviders);
  }
  return EncodingTable::GetEncodings();
}

Array<Byte> Encoding___::GetPreamble() {
  return Array<>::in::Empty<Byte>();
}

void Encoding___::GetDataItem() {
  if (_dataItem == nullptr) {
    _dataItem = EncodingTable::GetCodePageDataItem(_codePage);
    if (_dataItem == nullptr) {
      rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_NoCodepageData(), _codePage));
    }
  }
}

Object Encoding___::Clone() {
  Encoding encoding = (Encoding)MemberwiseClone();
  encoding->_isReadOnly = false;
  return encoding;
}

Int32 Encoding___::GetByteCount(Array<Char> chars) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  return GetByteCount(chars, 0, chars->get_Length());
}

Int32 Encoding___::GetByteCount(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  Array<Char> array = s->ToCharArray();
  return GetByteCount(array, 0, array->get_Length());
}

Int32 Encoding___::GetByteCount(String s, Int32 index, Int32 count) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s", SR::get_ArgumentNull_String());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (index > s->get_Length() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_IndexCount());
  }
  {
    Char* ptr = s;
    Char* ptr2 = ptr;
    return GetByteCount(ptr2 + index, count);
  }
}

Int32 Encoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Char> chars2 = ReadOnlySpan<Char>(chars, count).ToArray();
  return GetByteCount(chars2, 0, count);
}

Int32 Encoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  {
    Char* chars2 = &MemoryMarshal::GetNonNullPinnableReference(chars);
    return GetByteCount(chars2, chars.get_Length());
  }
}

Array<Byte> Encoding___::GetBytes(Array<Char> chars) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars", SR::get_ArgumentNull_Array());
  }
  return GetBytes(chars, 0, chars->get_Length());
}

Array<Byte> Encoding___::GetBytes(Array<Char> chars, Int32 index, Int32 count) {
  Array<Byte> array = rt::newarr<Array<Byte>>(GetByteCount(chars, index, count));
  GetBytes(chars, index, count, array, 0);
  return array;
}

Array<Byte> Encoding___::GetBytes(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s", SR::get_ArgumentNull_String());
  }
  Int32 byteCount = GetByteCount(s);
  Array<Byte> array = rt::newarr<Array<Byte>>(byteCount);
  Int32 bytes = GetBytes(s, 0, s->get_Length(), array, 0);
  return array;
}

Array<Byte> Encoding___::GetBytes(String s, Int32 index, Int32 count) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s", SR::get_ArgumentNull_String());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (index > s->get_Length() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_IndexCount());
  }
  {
    Char* ptr = s;
    Char* ptr2 = ptr;
    Int32 byteCount = GetByteCount(ptr2 + index, count);
    if (byteCount == 0) {
      return Array<>::in::Empty<Byte>();
    }
    Array<Byte> array = rt::newarr<Array<Byte>>(byteCount);
    {
      Byte* bytes = &array[0];
      Int32 bytes2 = GetBytes(ptr2 + index, count, bytes, byteCount);
    }
    return array;
  }
}

Int32 Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return GetBytes(s->ToCharArray(), charIndex, charCount, bytes, byteIndex);
}

Int32 Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (bytes == nullptr || chars == nullptr) {
    rt::throw_exception<ArgumentNullException>((bytes == nullptr) ? "bytes" : "chars", SR::get_ArgumentNull_Array());
  }
  if (charCount < 0 || byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((charCount < 0) ? "charCount" : "byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Char> chars2 = ReadOnlySpan<Char>(chars, charCount).ToArray();
  Array<Byte> array = rt::newarr<Array<Byte>>(byteCount);
  Int32 bytes2 = GetBytes(chars2, 0, charCount, array, 0);
  if (bytes2 < byteCount) {
    byteCount = bytes2;
  }
  ReadOnlySpan<Byte>(array, 0, byteCount).CopyTo(Span<Byte>(bytes, byteCount));
  return byteCount;
}

Int32 Encoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  {
    Char* chars2 = &MemoryMarshal::GetNonNullPinnableReference(chars);
    {
      Byte* bytes2 = &MemoryMarshal::GetNonNullPinnableReference(bytes);
      return GetBytes(chars2, chars.get_Length(), bytes2, bytes.get_Length());
    }
  }
}

Int32 Encoding___::GetCharCount(Array<Byte> bytes) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  return GetCharCount(bytes, 0, bytes->get_Length());
}

Int32 Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Byte> bytes2 = ReadOnlySpan<Byte>(bytes, count).ToArray();
  return GetCharCount(bytes2, 0, count);
}

Int32 Encoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  {
    Byte* bytes2 = &MemoryMarshal::GetNonNullPinnableReference(bytes);
    return GetCharCount(bytes2, bytes.get_Length());
  }
}

Array<Char> Encoding___::GetChars(Array<Byte> bytes) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  return GetChars(bytes, 0, bytes->get_Length());
}

Array<Char> Encoding___::GetChars(Array<Byte> bytes, Int32 index, Int32 count) {
  Array<Char> array = rt::newarr<Array<Char>>(GetCharCount(bytes, index, count));
  GetChars(bytes, index, count, array, 0);
  return array;
}

Int32 Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (chars == nullptr || bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>((chars == nullptr) ? "chars" : "bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0 || charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((byteCount < 0) ? "byteCount" : "charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Array<Byte> bytes2 = ReadOnlySpan<Byte>(bytes, byteCount).ToArray();
  Array<Char> array = rt::newarr<Array<Char>>(charCount);
  Int32 chars2 = GetChars(bytes2, 0, byteCount, array, 0);
  if (chars2 < charCount) {
    charCount = chars2;
  }
  ReadOnlySpan<Char>(array, 0, charCount).CopyTo(Span<Char>(chars, charCount));
  return charCount;
}

Int32 Encoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  {
    Byte* bytes2 = &MemoryMarshal::GetNonNullPinnableReference(bytes);
    {
      Char* chars2 = &MemoryMarshal::GetNonNullPinnableReference(chars);
      return GetChars(bytes2, bytes.get_Length(), chars2, chars.get_Length());
    }
  }
}

String Encoding___::GetString(Byte* bytes, Int32 byteCount) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  if (byteCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return String::in::CreateStringFromEncoding(bytes, byteCount, (Encoding)this);
}

String Encoding___::GetString(ReadOnlySpan<Byte> bytes) {
  {
    Byte* bytes2 = &MemoryMarshal::GetNonNullPinnableReference(bytes);
    return String::in::CreateStringFromEncoding(bytes2, bytes.get_Length(), (Encoding)this);
  }
}

Boolean Encoding___::IsAlwaysNormalized() {
  return IsAlwaysNormalized(NormalizationForm::FormC);
}

Boolean Encoding___::IsAlwaysNormalized(NormalizationForm form) {
  return false;
}

Decoder Encoding___::GetDecoder() {
  return rt::newobj<DefaultDecoder>((Encoding)this);
}

Encoder Encoding___::GetEncoder() {
  return rt::newobj<DefaultEncoder>((Encoding)this);
}

String Encoding___::GetString(Array<Byte> bytes) {
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes", SR::get_ArgumentNull_Array());
  }
  return GetString(bytes, 0, bytes->get_Length());
}

String Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  return rt::newstr<String>(GetChars(bytes, index, count));
}

Boolean Encoding___::Equals(Object value) {
  Encoding encoding = rt::as<Encoding>(value);
  if (encoding != nullptr && _codePage == encoding->_codePage && get_EncoderFallback()->Equals(encoding->get_EncoderFallback())) {
    return get_DecoderFallback()->Equals(encoding->get_DecoderFallback());
  }
  return false;
}

Int32 Encoding___::GetHashCode() {
  return _codePage + get_EncoderFallback()->GetHashCode() + get_DecoderFallback()->GetHashCode();
}

Stream Encoding___::CreateTranscodingStream(Stream innerStream, Encoding innerStreamEncoding, Encoding outerStreamEncoding, Boolean leaveOpen) {
  if (innerStream == nullptr) {
    rt::throw_exception<ArgumentNullException>("innerStream");
  }
  if (innerStreamEncoding == nullptr) {
    rt::throw_exception<ArgumentNullException>("innerStreamEncoding");
  }
  if (outerStreamEncoding == nullptr) {
    rt::throw_exception<ArgumentNullException>("outerStreamEncoding");
  }
  return rt::newobj<TranscodingStream>(innerStream, innerStreamEncoding, outerStreamEncoding, leaveOpen);
}

void Encoding___::ThrowBytesOverflow() {
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_EncodingConversionOverflowBytes(), get_EncodingName(), get_EncoderFallback()->GetType()), "bytes");
}

void Encoding___::ThrowBytesOverflow(EncoderNLS encoder, Boolean nothingEncoded) {
  if (encoder == nullptr || encoder->_throwOnOverflow || nothingEncoded) {
    if (encoder != nullptr && encoder->get_InternalHasFallbackBuffer()) {
      encoder->get_FallbackBuffer()->InternalReset();
    }
    ThrowBytesOverflow();
  }
  encoder->ClearMustFlush();
}

void Encoding___::ThrowConversionOverflow() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_ConversionOverflow());
}

void Encoding___::ThrowCharsOverflow() {
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_EncodingConversionOverflowChars(), get_EncodingName(), get_DecoderFallback()->GetType()), "chars");
}

void Encoding___::ThrowCharsOverflow(DecoderNLS decoder, Boolean nothingDecoded) {
  if (decoder == nullptr || decoder->_throwOnOverflow || nothingDecoded) {
    if (decoder != nullptr && decoder->get_InternalHasFallbackBuffer()) {
      decoder->get_FallbackBuffer()->InternalReset();
    }
    ThrowCharsOverflow();
  }
  decoder->ClearMustFlush();
}

OperationStatus Encoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

OperationStatus Encoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Encoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 Encoding___::GetByteCount(Char* pChars, Int32 charCount, EncoderNLS encoder) {
  Int32 num = 0;
  Int32 charsConsumed = 0;
  if (!encoder->get_HasLeftoverData()) {
    num = GetByteCountFast(pChars, charCount, encoder->get_Fallback(), charsConsumed);
    if (charsConsumed == charCount) {
      return num;
    }
  }
  num += GetByteCountWithFallback(pChars, charCount, charsConsumed, encoder);
  if (num < 0) {
    ThrowConversionOverflow();
  }
  return num;
}

Int32 Encoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 Encoding___::GetByteCountWithFallback(Char* pCharsOriginal, Int32 originalCharCount, Int32 charsConsumedSoFar) {
  return GetByteCountWithFallback(ReadOnlySpan<Char>(pCharsOriginal, originalCharCount).Slice(charsConsumedSoFar), originalCharCount, nullptr);
}

Int32 Encoding___::GetByteCountWithFallback(Char* pOriginalChars, Int32 originalCharCount, Int32 charsConsumedSoFar, EncoderNLS encoder) {
  ReadOnlySpan<Char> readOnlySpan = ReadOnlySpan<Char>(pOriginalChars, originalCharCount).Slice(charsConsumedSoFar);
  Int32 charsConsumed;
  Int32 num = encoder->DrainLeftoverDataForGetByteCount(readOnlySpan, charsConsumed);
  readOnlySpan = readOnlySpan.Slice(charsConsumed);
  num += GetByteCountFast((Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(readOnlySpan)), readOnlySpan.get_Length(), encoder->get_Fallback(), charsConsumed);
  if (num < 0) {
    ThrowConversionOverflow();
  }
  readOnlySpan = readOnlySpan.Slice(charsConsumed);
  if (!readOnlySpan.get_IsEmpty()) {
    num += GetByteCountWithFallback(readOnlySpan, originalCharCount, encoder);
    if (num < 0) {
      ThrowConversionOverflow();
    }
  }
  return num;
}

Int32 Encoding___::GetByteCountWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, EncoderNLS encoder) {
  {
    Char* ptr = &MemoryMarshal::GetReference(chars);
    EncoderFallbackBuffer encoderFallbackBuffer = EncoderFallbackBuffer::in::CreateAndInitialize((Encoding)this, encoder, originalCharsLength);
    Int32 num = 0;
    Rune result;
    Int32 charsConsumed;
    while (Rune::DecodeFromUtf16(chars, result, charsConsumed) != OperationStatus::NeedMoreData || encoder == nullptr || encoder->get_MustFlush()) {
      Int32 num2 = encoderFallbackBuffer->InternalFallbackGetByteCount(chars, charsConsumed);
      num += num2;
      if (num < 0) {
        ThrowConversionOverflow();
      }
      chars = chars.Slice(charsConsumed);
      if (!chars.get_IsEmpty()) {
        num2 = GetByteCountFast((Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(chars)), chars.get_Length(), nullptr, charsConsumed);
        num += num2;
        if (num < 0) {
          ThrowConversionOverflow();
        }
        chars = chars.Slice(charsConsumed);
      }
      if (chars.get_IsEmpty()) {
        break;
      }
    }
    return num;
  }
}

Int32 Encoding___::GetBytes(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount, EncoderNLS encoder) {
  Int32 num = 0;
  Int32 charsConsumed = 0;
  if (!encoder->get_HasLeftoverData()) {
    num = GetBytesFast(pChars, charCount, pBytes, byteCount, charsConsumed);
    if (charsConsumed == charCount) {
      encoder->_charsUsed = charCount;
      return num;
    }
  }
  return GetBytesWithFallback(pChars, charCount, pBytes, byteCount, charsConsumed, num, encoder);
}

Int32 Encoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 Encoding___::GetBytesWithFallback(Char* pOriginalChars, Int32 originalCharCount, Byte* pOriginalBytes, Int32 originalByteCount, Int32 charsConsumedSoFar, Int32 bytesWrittenSoFar) {
  return GetBytesWithFallback(ReadOnlySpan<Char>(pOriginalChars, originalCharCount).Slice(charsConsumedSoFar), originalCharCount, Span<Byte>(pOriginalBytes, originalByteCount).Slice(bytesWrittenSoFar), originalByteCount, nullptr);
}

Int32 Encoding___::GetBytesWithFallback(Char* pOriginalChars, Int32 originalCharCount, Byte* pOriginalBytes, Int32 originalByteCount, Int32 charsConsumedSoFar, Int32 bytesWrittenSoFar, EncoderNLS encoder) {
  ReadOnlySpan<Char> readOnlySpan = ReadOnlySpan<Char>(pOriginalChars, originalCharCount).Slice(charsConsumedSoFar);
  Span<Byte> span = Span<Byte>(pOriginalBytes, originalByteCount).Slice(bytesWrittenSoFar);
  Int32 charsConsumed;
  Int32 bytesWritten;
  Boolean flag = encoder->TryDrainLeftoverDataForGetBytes(readOnlySpan, span, charsConsumed, bytesWritten);
  readOnlySpan = readOnlySpan.Slice(charsConsumed);
  span = span.Slice(bytesWritten);
  if (!flag) {
    ThrowBytesOverflow(encoder, span.get_Length() == originalByteCount);
  } else {
    bytesWritten = GetBytesFast((Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(readOnlySpan)), readOnlySpan.get_Length(), (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(span)), span.get_Length(), charsConsumed);
    readOnlySpan = readOnlySpan.Slice(charsConsumed);
    span = span.Slice(bytesWritten);
    if (!readOnlySpan.get_IsEmpty()) {
      encoder->_charsUsed = originalCharCount;
      return GetBytesWithFallback(readOnlySpan, originalCharCount, span, originalByteCount, encoder);
    }
  }
  encoder->_charsUsed = originalCharCount - readOnlySpan.get_Length();
  return originalByteCount - span.get_Length();
}

Int32 Encoding___::GetBytesWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, Span<Byte> bytes, Int32 originalBytesLength, EncoderNLS encoder) {
  {
    Char* ptr2 = &MemoryMarshal::GetReference(chars);
    {
      Byte* ptr = &MemoryMarshal::GetReference(bytes);
      EncoderFallbackBuffer encoderFallbackBuffer = EncoderFallbackBuffer::in::CreateAndInitialize((Encoding)this, encoder, originalCharsLength);
      do {
        Rune result;
        Int32 charsConsumed;
        OperationStatus operationStatus = Rune::DecodeFromUtf16(chars, result, charsConsumed);
        if (operationStatus != OperationStatus::NeedMoreData) {
          Int32 bytesWritten;
          if (operationStatus != OperationStatus::InvalidData && EncodeRune(result, bytes, bytesWritten) == OperationStatus::DestinationTooSmall) {
            break;
          }
        } else if (encoder != nullptr && !encoder->get_MustFlush()) {
          encoder->_charLeftOver = chars[0];
          chars = ReadOnlySpan<Char>::get_Empty();
          break;
        }

        Int32 bytesWritten2;
        Boolean flag = encoderFallbackBuffer->TryInternalFallbackGetBytes(chars, bytes, charsConsumed, bytesWritten2);
        chars = chars.Slice(charsConsumed);
        bytes = bytes.Slice(bytesWritten2);
        if (!flag) {
          break;
        }
        if (!chars.get_IsEmpty()) {
          bytesWritten2 = GetBytesFast((Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(chars)), chars.get_Length(), (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(bytes)), bytes.get_Length(), charsConsumed);
          chars = chars.Slice(charsConsumed);
          bytes = bytes.Slice(bytesWritten2);
        }
      } while (!chars.get_IsEmpty())
      if (!chars.get_IsEmpty() || encoderFallbackBuffer->get_Remaining() > 0) {
        ThrowBytesOverflow(encoder, bytes.get_Length() == originalBytesLength);
      }
      if (encoder != nullptr) {
        encoder->_charsUsed = originalCharsLength - chars.get_Length();
      }
      return originalBytesLength - bytes.get_Length();
    }
  }
}

Int32 Encoding___::GetCharCount(Byte* pBytes, Int32 byteCount, DecoderNLS decoder) {
  Int32 num = 0;
  Int32 bytesConsumed = 0;
  if (!decoder->get_HasLeftoverData()) {
    num = GetCharCountFast(pBytes, byteCount, decoder->get_Fallback(), bytesConsumed);
    if (bytesConsumed == byteCount) {
      return num;
    }
  }
  num += GetCharCountWithFallback(pBytes, byteCount, bytesConsumed, decoder);
  if (num < 0) {
    ThrowConversionOverflow();
  }
  return num;
}

Int32 Encoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 Encoding___::GetCharCountWithFallback(Byte* pBytesOriginal, Int32 originalByteCount, Int32 bytesConsumedSoFar) {
  return GetCharCountWithFallback(ReadOnlySpan<Byte>(pBytesOriginal, originalByteCount).Slice(bytesConsumedSoFar), originalByteCount, nullptr);
}

Int32 Encoding___::GetCharCountWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Int32 bytesConsumedSoFar, DecoderNLS decoder) {
  ReadOnlySpan<Byte> readOnlySpan = ReadOnlySpan<Byte>(pOriginalBytes, originalByteCount).Slice(bytesConsumedSoFar);
  Int32 num = 0;
  Int32 bytesConsumed;
  if (decoder->get_HasLeftoverData()) {
    num = decoder->DrainLeftoverDataForGetCharCount(readOnlySpan, bytesConsumed);
    readOnlySpan = readOnlySpan.Slice(bytesConsumed);
  }
  num += GetCharCountFast((Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(readOnlySpan)), readOnlySpan.get_Length(), decoder->get_Fallback(), bytesConsumed);
  if (num < 0) {
    ThrowConversionOverflow();
  }
  readOnlySpan = readOnlySpan.Slice(bytesConsumed);
  if (!readOnlySpan.get_IsEmpty()) {
    num += GetCharCountWithFallback(readOnlySpan, originalByteCount, decoder);
    if (num < 0) {
      ThrowConversionOverflow();
    }
  }
  return num;
}

Int32 Encoding___::GetCharCountWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, DecoderNLS decoder) {
  {
    Byte* ptr = &MemoryMarshal::GetReference(bytes);
    DecoderFallbackBuffer decoderFallbackBuffer = DecoderFallbackBuffer::in::CreateAndInitialize((Encoding)this, decoder, originalBytesLength);
    Int32 num = 0;
    Rune value;
    Int32 bytesConsumed;
    while (DecodeFirstRune(bytes, value, bytesConsumed) != OperationStatus::NeedMoreData || decoder == nullptr || decoder->get_MustFlush()) {
      Int32 num2 = decoderFallbackBuffer->InternalFallbackGetCharCount(bytes, bytesConsumed);
      num += num2;
      if (num < 0) {
        ThrowConversionOverflow();
      }
      bytes = bytes.Slice(bytesConsumed);
      if (!bytes.get_IsEmpty()) {
        num2 = GetCharCountFast((Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(bytes)), bytes.get_Length(), nullptr, bytesConsumed);
        num += num2;
        if (num < 0) {
          ThrowConversionOverflow();
        }
        bytes = bytes.Slice(bytesConsumed);
      }
      if (bytes.get_IsEmpty()) {
        break;
      }
    }
    return num;
  }
}

Int32 Encoding___::GetChars(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount, DecoderNLS decoder) {
  Int32 num = 0;
  Int32 bytesConsumed = 0;
  if (!decoder->get_HasLeftoverData()) {
    num = GetCharsFast(pBytes, byteCount, pChars, charCount, bytesConsumed);
    if (bytesConsumed == byteCount) {
      decoder->_bytesUsed = byteCount;
      return num;
    }
  }
  return GetCharsWithFallback(pBytes, byteCount, pChars, charCount, bytesConsumed, num, decoder);
}

Int32 Encoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 Encoding___::GetCharsWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Char* pOriginalChars, Int32 originalCharCount, Int32 bytesConsumedSoFar, Int32 charsWrittenSoFar) {
  return GetCharsWithFallback(ReadOnlySpan<Byte>(pOriginalBytes, originalByteCount).Slice(bytesConsumedSoFar), originalByteCount, Span<Char>(pOriginalChars, originalCharCount).Slice(charsWrittenSoFar), originalCharCount, nullptr);
}

Int32 Encoding___::GetCharsWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Char* pOriginalChars, Int32 originalCharCount, Int32 bytesConsumedSoFar, Int32 charsWrittenSoFar, DecoderNLS decoder) {
  ReadOnlySpan<Byte> readOnlySpan = ReadOnlySpan<Byte>(pOriginalBytes, originalByteCount).Slice(bytesConsumedSoFar);
  Span<Char> span = Span<Char>(pOriginalChars, originalCharCount).Slice(charsWrittenSoFar);
  Int32 bytesConsumed;
  Int32 start;
  if (decoder->get_HasLeftoverData()) {
    start = decoder->DrainLeftoverDataForGetChars(readOnlySpan, span, bytesConsumed);
    readOnlySpan = readOnlySpan.Slice(bytesConsumed);
    span = span.Slice(start);
  }
  start = GetCharsFast((Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(readOnlySpan)), readOnlySpan.get_Length(), (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(span)), span.get_Length(), bytesConsumed);
  readOnlySpan = readOnlySpan.Slice(bytesConsumed);
  span = span.Slice(start);
  decoder->_bytesUsed = originalByteCount;
  if (readOnlySpan.get_IsEmpty()) {
    return originalCharCount - span.get_Length();
  }
  return GetCharsWithFallback(readOnlySpan, originalByteCount, span, originalCharCount, decoder);
}

Int32 Encoding___::GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder) {
  {
    Byte* ptr2 = &MemoryMarshal::GetReference(bytes);
    {
      Char* ptr = &MemoryMarshal::GetReference(chars);
      DecoderFallbackBuffer decoderFallbackBuffer = DecoderFallbackBuffer::in::CreateAndInitialize((Encoding)this, decoder, originalBytesLength);
      do {
        Rune value;
        Int32 bytesConsumed;
        OperationStatus operationStatus = DecodeFirstRune(bytes, value, bytesConsumed);
        if (operationStatus != OperationStatus::NeedMoreData) {
          if (operationStatus != OperationStatus::InvalidData) {
            break;
          }
        } else if (decoder != nullptr && !decoder->get_MustFlush()) {
          decoder->SetLeftoverData(bytes);
          bytes = ReadOnlySpan<Byte>::get_Empty();
          break;
        }

        Int32 charsWritten;
        if (!decoderFallbackBuffer->TryInternalFallbackGetChars(bytes, bytesConsumed, chars, charsWritten)) {
          break;
        }
        bytes = bytes.Slice(bytesConsumed);
        chars = chars.Slice(charsWritten);
        if (!bytes.get_IsEmpty()) {
          charsWritten = GetCharsFast((Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(bytes)), bytes.get_Length(), (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(chars)), chars.get_Length(), bytesConsumed);
          bytes = bytes.Slice(bytesConsumed);
          chars = chars.Slice(charsWritten);
        }
      } while (!bytes.get_IsEmpty())
      if (!bytes.get_IsEmpty()) {
        ThrowCharsOverflow(decoder, chars.get_Length() == originalCharsLength);
      }
      if (decoder != nullptr) {
        decoder->_bytesUsed = originalBytesLength - bytes.get_Length();
      }
      return originalCharsLength - chars.get_Length();
    }
  }
}

void Encoding___::cctor() {
  s_defaultEncoding = rt::newobj<UTF8Encoding::in::UTF8EncodingSealed>(false);
}

} // namespace System::Private::CoreLib::System::Text::EncodingNamespace
