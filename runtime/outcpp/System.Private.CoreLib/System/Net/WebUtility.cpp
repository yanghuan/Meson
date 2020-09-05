#include "WebUtility-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Net/WebUtility-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Net::WebUtilityNamespace {
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Text;

void WebUtility::UrlDecoder::FlushBytes() {
  if (_charBuffer == nullptr) {
    _charBuffer = rt::newarr<Array<Char>>(_bufferSize);
  }
  _numChars += _encoding->GetChars(_byteBuffer, 0, _numBytes, _charBuffer, _numChars);
  _numBytes = 0;
}

WebUtility::UrlDecoder::UrlDecoder(Int32 bufferSize, Encoding encoding) {
  _bufferSize = bufferSize;
  _encoding = encoding;
  _charBuffer = nullptr;
  _numChars = 0;
  _numBytes = 0;
  _byteBuffer = nullptr;
}

void WebUtility::UrlDecoder::AddChar(Char ch) {
  if (_numBytes > 0) {
    FlushBytes();
  }
  if (_charBuffer == nullptr) {
    _charBuffer = rt::newarr<Array<Char>>(_bufferSize);
  }
  _charBuffer[_numChars++] = ch;
}

void WebUtility::UrlDecoder::AddByte(Byte b) {
  if (_byteBuffer == nullptr) {
    _byteBuffer = rt::newarr<Array<Byte>>(_bufferSize);
  }
  _byteBuffer[_numBytes++] = b;
}

String WebUtility::UrlDecoder::GetString() {
  if (_numBytes > 0) {
    FlushBytes();
  }
  return rt::newstr<String>(_charBuffer, 0, _numChars);
}

Char WebUtility::HtmlEntities::Lookup(ReadOnlySpan<Char> entity) {
  if (entity.get_Length() <= 8) {
    Char value;
    s_lookupTable->TryGetValue(ToUInt64Key(entity), value);
    return value;
  }
  return 0;
}

UInt64 WebUtility::HtmlEntities::ToUInt64Key(ReadOnlySpan<Char> entity) {
  UInt64 num = 0;
  for (Int32 i = 0; i < entity.get_Length(); i++) {
    if (entity[i] > 255) {
      return 0;
    }
    num = ((num << 8) | entity[i]);
  }
  return num;
}

void WebUtility::HtmlEntities::cctor() {
  s_lookupTable = rt::newobj<Dictionary<UInt64, Char>>(253);
}

String WebUtility::HtmlEncode(String value) {
  if (String::in::IsNullOrEmpty(value)) {
    return value;
  }
  ReadOnlySpan<Char> input = MemoryExtensions::AsSpan(value);
  Int32 num = IndexOfHtmlEncodingChars(input);
  if (num == -1) {
    return value;
  }
  ValueStringBuilder valueStringBuilder;
  if (value->get_Length() >= 80) {
    valueStringBuilder = ValueStringBuilder(value->get_Length() + 200);
  } else {
    Char as[256] = {};
    Span<Char> initialBuffer = as;
    valueStringBuilder = ValueStringBuilder(initialBuffer);
  }
  ValueStringBuilder output = valueStringBuilder;
  output.Append(input.Slice(0, num));
  HtmlEncode(input.Slice(num), output);
  return output.ToString();
}

void WebUtility::HtmlEncode(String value, TextWriter output) {
  if (output == nullptr) {
    rt::throw_exception<ArgumentNullException>("output");
  }
  if (String::in::IsNullOrEmpty(value)) {
    output->Write(value);
    return;
  }
  ReadOnlySpan<Char> input = MemoryExtensions::AsSpan(value);
  Int32 num = IndexOfHtmlEncodingChars(input);
  if (num == -1) {
    output->Write(value);
    return;
  }
  ValueStringBuilder valueStringBuilder;
  if (value->get_Length() >= 80) {
    valueStringBuilder = ValueStringBuilder(value->get_Length() + 200);
  } else {
    Char as[256] = {};
    Span<Char> initialBuffer = as;
    valueStringBuilder = ValueStringBuilder(initialBuffer);
  }
  ValueStringBuilder output2 = valueStringBuilder;
  output2.Append(input.Slice(0, num));
  HtmlEncode(input.Slice(num), output2);
  output->Write(output2.AsSpan());
  output2.Dispose();
}

void WebUtility::HtmlEncode(ReadOnlySpan<Char> input, ValueStringBuilder& output) {
  for (Int32 i = 0; i < input.get_Length(); i++) {
    Char c = input[i];
    if (c <= 62) {
      switch (c.get()) {
        case 60:
          output.Append("&lt;");
          break;
        case 62:
          output.Append("&gt;");
          break;
        case 34:
          output.Append("&quot;");
          break;
        case 39:
          output.Append("&#39;");
          break;
        case 38:
          output.Append("&amp;");
          break;
        default:
          output.Append(c);
          break;
      }
      continue;
    }
    Int32 num = -1;
    if (c >= 160 && c < 256) {
      num = c;
    } else if (Char::IsSurrogate(c)) {
      Int32 nextUnicodeScalarValueFromUtf16Surrogate = GetNextUnicodeScalarValueFromUtf16Surrogate(input, i);
      if (nextUnicodeScalarValueFromUtf16Surrogate >= 65536) {
        num = nextUnicodeScalarValueFromUtf16Surrogate;
      } else {
        c = (Char)nextUnicodeScalarValueFromUtf16Surrogate;
      }
    }

    if (num >= 0) {
      output.Append("&#");
      Span<Char> destination = output.AppendSpan(10);
      Int32 charsWritten;
      num.TryFormat(destination, charsWritten);
      output.set_Length(10 - charsWritten);
      output.Append(59);
    } else {
      output.Append(c);
    }
  }
}

String WebUtility::HtmlDecode(String value) {
  if (String::in::IsNullOrEmpty(value)) {
    return value;
  }
  ReadOnlySpan<Char> input = MemoryExtensions::AsSpan(value);
  Int32 num = IndexOfHtmlDecodingChars(input);
  if (num == -1) {
    return value;
  }
  ValueStringBuilder valueStringBuilder;
  if (value->get_Length() > 256) {
    valueStringBuilder = ValueStringBuilder(value->get_Length());
  } else {
    Char as[256] = {};
    Span<Char> initialBuffer = as;
    valueStringBuilder = ValueStringBuilder(initialBuffer);
  }
  ValueStringBuilder output = valueStringBuilder;
  output.Append(input.Slice(0, num));
  HtmlDecode(input.Slice(num), output);
  return output.ToString();
}

void WebUtility::HtmlDecode(String value, TextWriter output) {
  if (output == nullptr) {
    rt::throw_exception<ArgumentNullException>("output");
  }
  if (String::in::IsNullOrEmpty(value)) {
    output->Write(value);
    return;
  }
  ReadOnlySpan<Char> input = MemoryExtensions::AsSpan(value);
  Int32 num = IndexOfHtmlDecodingChars(input);
  if (num == -1) {
    output->Write(value);
    return;
  }
  ValueStringBuilder valueStringBuilder;
  if (value->get_Length() > 256) {
    valueStringBuilder = ValueStringBuilder(value->get_Length());
  } else {
    Char as[256] = {};
    Span<Char> initialBuffer = as;
    valueStringBuilder = ValueStringBuilder(initialBuffer);
  }
  ValueStringBuilder output2 = valueStringBuilder;
  output2.Append(input.Slice(0, num));
  HtmlDecode(input.Slice(num), output2);
  output->Write(output2.AsSpan());
  output2.Dispose();
}

void WebUtility::HtmlDecode(ReadOnlySpan<Char> input, ValueStringBuilder& output) {
  for (Int32 i = 0; i < input.get_Length(); i++) {
    Char c = input[i];
    if (c == 38) {
      ReadOnlySpan<Char> span = input.Slice(i + 1);
      Int32 num = MemoryExtensions::IndexOfAny(span, 59, 38);
      if (num >= 0 && span[num] == 59) {
        Int32 num2 = i + 1 + num;
        if (num > 1 && span[0] == 35) {
          UInt32 result;
          Boolean flag = (span[1] == 120 || span[1] == 88) ? UInt32::TryParse(span.Slice(2, num - 2), NumberStyles::AllowHexSpecifier, CultureInfo::in::get_InvariantCulture(), result) : UInt32::TryParse(span.Slice(1, num - 1), NumberStyles::Integer, CultureInfo::in::get_InvariantCulture(), result);
          if (flag) {
            flag = (result < 55296 || (57343 < result && result <= 1114111));
          }
          if (flag) {
            if (result <= 65535) {
              output.Append((Char)result);
            } else {
              Char leadingSurrogate;
              Char trailingSurrogate;
              ConvertSmpToUtf16(result, leadingSurrogate, trailingSurrogate);
              output.Append(leadingSurrogate);
              output.Append(trailingSurrogate);
            }
            i = num2;
            continue;
          }
        } else {
          ReadOnlySpan<Char> readOnlySpan = span.Slice(0, num);
          i = num2;
          Char c2 = HtmlEntities::Lookup(readOnlySpan);
          if (c2 == 0) {
            output.Append(38);
            output.Append(readOnlySpan);
            output.Append(59);
            continue;
          }
          c = c2;
        }
      }
    }
    output.Append(c);
  }
}

Int32 WebUtility::IndexOfHtmlEncodingChars(ReadOnlySpan<Char> input) {
  for (Int32 i = 0; i < input.get_Length(); i++) {
    Char c = input[i];
    if (c <= 62) {
      switch (c.get()) {
        case 34:
        case 38:
        case 39:
        case 60:
        case 62:
          return i;
      }
      continue;
    }
    if (c >= 160 && c < 256) {
      return i;
    }
    if (Char::IsSurrogate(c)) {
      return i;
    }
  }
  return -1;
}

void WebUtility::GetEncodedBytes(Array<Byte> originalBytes, Int32 offset, Int32 count, Array<Byte> expandedBytes) {
  Int32 num = 0;
  Int32 num2 = offset + count;
  for (Int32 i = offset; i < num2; i++) {
    Byte b = originalBytes[i];
    Char c = (Char)b;
    if (IsUrlSafeChar(c)) {
      expandedBytes[num++] = b;
      continue;
    }
    if (c == 32) {
      expandedBytes[num++] = 43;
      continue;
    }
    expandedBytes[num++] = 37;
    expandedBytes[num++] = (Byte)HexConverter::ToCharUpper(b >> 4);
    expandedBytes[num++] = (Byte)HexConverter::ToCharUpper(b);
  }
}

String WebUtility::UrlEncode(String value) {
  if (String::in::IsNullOrEmpty(value)) {
    return value;
  }
  Int32 num = 0;
  Int32 num2 = 0;
  for (Int32 i = 0; i < value->get_Length(); i++) {
    Char c = value[i];
    if (IsUrlSafeChar(c)) {
      num++;
    } else if (c == 32) {
      num2++;
    }

  }
  Int32 num3 = num + num2;
  if (num3 == value->get_Length()) {
    if (num2 != 0) {
      return value->Replace(32, 43);
    }
    return value;
  }
  Int32 byteCount = Encoding::in::get_UTF8()->GetByteCount(value);
  Int32 num4 = byteCount - num3;
  Int32 num5 = num4 * 2;
  Array<Byte> array = rt::newarr<Array<Byte>>(byteCount + num5);
  Encoding::in::get_UTF8()->GetBytes(value, 0, value->get_Length(), array, num5);
  GetEncodedBytes(array, num5, byteCount, array);
  return Encoding::in::get_UTF8()->GetString(array);
}

Array<Byte> WebUtility::UrlEncodeToBytes(Array<Byte> value, Int32 offset, Int32 count) {
  if (!ValidateUrlEncodingParameters(value, offset, count)) {
    return nullptr;
  }
  Boolean flag = false;
  Int32 num = 0;
  for (Int32 i = 0; i < count; i++) {
    Char c = (Char)value[offset + i];
    if (c == 32) {
      flag = true;
    } else if (!IsUrlSafeChar(c)) {
      num++;
    }

  }
  if (!flag && num == 0) {
    Array<Byte> array = rt::newarr<Array<Byte>>(count);
    Buffer::BlockCopy(value, offset, array, 0, count);
    return array;
  }
  Array<Byte> array2 = rt::newarr<Array<Byte>>(count + num * 2);
  GetEncodedBytes(value, offset, count, array2);
  return array2;
}

String WebUtility::UrlDecodeInternal(String value, Encoding encoding) {
  if (String::in::IsNullOrEmpty(value)) {
    return value;
  }
  Int32 length = value->get_Length();
  UrlDecoder urlDecoder = UrlDecoder(length, encoding);
  Boolean flag = false;
  Boolean flag2 = false;
  for (Int32 i = 0; i < length; i++) {
    Char c = value[i];
    switch (c.get()) {
      case 43:
        flag2 = true;
        c = 32;
        break;
      case 37:
        if (i < length - 2) {
          Int32 num = HexConverter::FromChar(value[i + 1]);
          Int32 num2 = HexConverter::FromChar(value[i + 2]);
          if ((num | num2) != 255) {
            Byte b = (Byte)((num << 4) | num2);
            i += 2;
            urlDecoder.AddByte(b);
            flag = true;
            continue;
          }
        }
        break;
    }
    if ((c & 65408) == 0) {
      urlDecoder.AddByte((Byte)c);
    } else {
      urlDecoder.AddChar(c);
    }
  }
  if (!flag) {
    if (flag2) {
      return value->Replace(43, 32);
    }
    return value;
  }
  return urlDecoder.GetString();
}

Array<Byte> WebUtility::UrlDecodeInternal(Array<Byte> bytes, Int32 offset, Int32 count) {
  if (!ValidateUrlEncodingParameters(bytes, offset, count)) {
    return nullptr;
  }
  Int32 num = 0;
  Array<Byte> array = rt::newarr<Array<Byte>>(count);
  for (Int32 i = 0; i < count; i++) {
    Int32 num2 = offset + i;
    Byte b = bytes[num2];
    switch (b.get()) {
      case 43:
        b = 32;
        break;
      case 37:
        if (i < count - 2) {
          Int32 num3 = HexConverter::FromChar(bytes[num2 + 1]);
          Int32 num4 = HexConverter::FromChar(bytes[num2 + 2]);
          if ((num3 | num4) != 255) {
            b = (Byte)((num3 << 4) | num4);
            i += 2;
          }
        }
        break;
    }
    array[num++] = b;
  }
  if (num < array->get_Length()) {
    Array<>::in::Resize(array, num);
  }
  return array;
}

String WebUtility::UrlDecode(String encodedValue) {
  return UrlDecodeInternal(encodedValue, Encoding::in::get_UTF8());
}

Array<Byte> WebUtility::UrlDecodeToBytes(Array<Byte> encodedValue, Int32 offset, Int32 count) {
  return UrlDecodeInternal(encodedValue, offset, count);
}

void WebUtility::ConvertSmpToUtf16(UInt32 smpChar, Char& leadingSurrogate, Char& trailingSurrogate) {
  Int32 num = (Int32)(smpChar - 65536);
  leadingSurrogate = (Char)(num / 1024 + 55296);
  trailingSurrogate = (Char)(num % 1024 + 56320);
}

Int32 WebUtility::GetNextUnicodeScalarValueFromUtf16Surrogate(ReadOnlySpan<Char> input, Int32& index) {
  if (input.get_Length() - index <= 1) {
    return 65533;
  }
  Char c = input[index];
  Char c2 = input[index + 1];
  if (!Char::IsSurrogatePair(c, c2)) {
    return 65533;
  }
  index++;
  return (c - 55296) * 1024 + (c2 - 56320) + 65536;
}

Boolean WebUtility::IsUrlSafeChar(Char ch) {
  if ((UInt32)(ch - 97) > 25u && (UInt32)(ch - 65) > 25u && ((UInt32)(ch - 32) > 25u || ((1 << ch - 32) & 67069698) == 0)) {
    return ch == 95;
  }
  return true;
}

Boolean WebUtility::ValidateUrlEncodingParameters(Array<Byte> bytes, Int32 offset, Int32 count) {
  if (bytes == nullptr && count == 0) {
    return false;
  }
  if (bytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("bytes");
  }
  if (offset < 0 || offset > bytes->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset");
  }
  if (count < 0 || offset + count > bytes->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("count");
  }
  return true;
}

Int32 WebUtility::IndexOfHtmlDecodingChars(ReadOnlySpan<Char> input) {
  for (Int32 i = 0; i < input.get_Length(); i++) {
    Char c = input[i];
    if (c == 38 || Char::IsSurrogate(c)) {
      return i;
    }
  }
  return -1;
}

} // namespace System::Private::CoreLib::System::Net::WebUtilityNamespace
