#include "UriHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/Text/SpanRuneEnumerator-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.Uri/System/HexConverter-dep.h>
#include <System.Private.Uri/System/IriHelper-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.Uri/System/Uri-dep.h>
#include <System.Private.Uri/System/UriFormatException-dep.h>
#include <System.Private.Uri/System/UriHelper-dep.h>

namespace System::Private::Uri::System::UriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
using namespace ::System::Private::CoreLib::System::Text;
using namespace System::Text;

void UriHelper::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void UriHelper::__c___::ctor() {
}

void UriHelper::__c___::_StripBidiControlCharacters_b__27_0(Span<Char> buffer, ValueTuple<IntPtr, Int32> state) {
  ReadOnlySpan<Char> readOnlySpan = ReadOnlySpan<Char>((void*)state.Item1, state.Item2);
  Int32 num = 0;
  ReadOnlySpan<Char> readOnlySpan2 = readOnlySpan;
  for (Char&& c : *readOnlySpan2) {
    if ((UInt32)(c - 8206) > 32u || !IsBidiControlCharacter(c)) {
      buffer[num++] = c;
    }
  }
}

ReadOnlySpan<Boolean> UriHelper::get_UnreservedReservedTable() {
  return rt::newarr<Array<Boolean>>(128);
}

ReadOnlySpan<Boolean> UriHelper::get_UnreservedTable() {
  return rt::newarr<Array<Boolean>>(128);
}

Boolean UriHelper::TestForSubPath(Char* selfPtr, Int32 selfLength, Char* otherPtr, Int32 otherLength, Boolean ignoreCase) {
  Int32 i = 0;
  Boolean flag = true;
  for (; i < selfLength && i < otherLength; i++) {
    Char c = *(selfPtr + i);
    Char c2 = *(otherPtr + i);
    switch (c.get()) {
      case '#':
      case '?':
        return true;
      case '/':
        if (c2 != '/') {
          return false;
        }
        if (!flag) {
          return false;
        }
        flag = true;
        continue;
      default:
        if (c2 == '?' || c2 == '#') {
          break;
        }
        if (!ignoreCase) {
          if (c != c2) {
            flag = false;
          }
        } else if (Char::ToLowerInvariant(c) != Char::ToLowerInvariant(c2)) {
          flag = false;
        }

        continue;
    }
    break;
  }
  for (; i < selfLength; i++) {
    Char c;
    if ((c = *(selfPtr + i)) != '?') {
      switch (c.get()) {
        case '#':
          break;
        case '/':
          return false;
        default:
          continue;
      }
    }
    return true;
  }
  return true;
}

String UriHelper::EscapeString(String stringToEscape, Boolean checkExistingEscaped, ReadOnlySpan<Boolean> unreserved, Char forceEscape1, Char forceEscape2) {
  if (stringToEscape == nullptr) {
    rt::throw_exception<ArgumentNullException>("stringToEscape");
  }
  if (stringToEscape->get_Length() == 0) {
    return String::in::Empty;
  }
  ReadOnlySpan<Boolean> readOnlySpan;
  if ((forceEscape1 | forceEscape2) == 0) {
    readOnlySpan = unreserved;
  } else {
    Byte as[128] = {};
    Span<Boolean> span = Span<Boolean>(as, 128);
    Span<Boolean> span2 = span;
    unreserved.CopyTo(span2);
    span2[forceEscape1] = false;
    span2[forceEscape2] = false;
    readOnlySpan = span2;
  }
  Int32 i;
  for (i = 0; i < stringToEscape->get_Length(); i++) {
    Char index;
    if ((index = stringToEscape[i]) > '') {
      break;
    }
    if (!readOnlySpan[index]) {
      break;
    }
  }
  if (i == stringToEscape->get_Length()) {
    return stringToEscape;
  }
  Char as[256] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder vsb = ValueStringBuilder(initialBuffer);
  vsb.Append(MemoryExtensions::AsSpan(stringToEscape, 0, i));
  EscapeStringToBuilder(MemoryExtensions::AsSpan(stringToEscape, i), vsb, readOnlySpan, checkExistingEscaped);
  return vsb.ToString();
}

Array<Char> UriHelper::EscapeString(ReadOnlySpan<Char> stringToEscape, Array<Char> dest, Int32& destPos, Boolean checkExistingEscaped, Char forceEscape1, Char forceEscape2) {
  auto EnsureCapacity = [](Array<Char> dest, Int32 destSize, Int32 requiredSize) -> void {
    if (dest == nullptr || dest->get_Length() - destSize < requiredSize) {
      Array<>::in::Resize(dest, destSize + requiredSize + 120);
    }
  };
  ReadOnlySpan<Boolean> readOnlySpan;
  if ((forceEscape1 | forceEscape2) == 0) {
    readOnlySpan = get_UnreservedReservedTable();
  } else {
    Byte as[128] = {};
    Span<Boolean> span = Span<Boolean>(as, 128);
    Span<Boolean> span2 = span;
    get_UnreservedReservedTable().CopyTo(span2);
    span2[forceEscape1] = false;
    span2[forceEscape2] = false;
    readOnlySpan = span2;
  }
  Int32 i;
  for (i = 0; i < stringToEscape.get_Length(); i++) {
    Char index;
    if ((index = stringToEscape[i]) > '') {
      break;
    }
    if (!readOnlySpan[index]) {
      break;
    }
  }
  if (i == stringToEscape.get_Length()) {
    if (dest != nullptr) {
      EnsureCapacity(dest, destPos, stringToEscape.get_Length());
      stringToEscape.CopyTo(MemoryExtensions::AsSpan(dest, destPos));
      destPos += stringToEscape.get_Length();
    }
    return dest;
  }
  Char as[256] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder vsb = ValueStringBuilder(initialBuffer);
  vsb.Append(stringToEscape.Slice(0, i));
  EscapeStringToBuilder(stringToEscape.Slice(i), vsb, readOnlySpan, checkExistingEscaped);
  EnsureCapacity(dest, destPos, vsb.get_Length());
  Int32 charsWritten;
  vsb.TryCopyTo(MemoryExtensions::AsSpan(dest, destPos), charsWritten);
  destPos += charsWritten;
  return dest;
}

void UriHelper::EscapeStringToBuilder(ReadOnlySpan<Char> stringToEscape, ValueStringBuilder& vsb, ReadOnlySpan<Boolean> noEscape, Boolean checkExistingEscaped) {
  Byte as[4] = {};
  Span<Byte> span = Span<Byte>(as, 4);
  Span<Byte> destination = span;
  SpanRuneEnumerator spanRuneEnumerator = MemoryExtensions::EnumerateRunes(stringToEscape);
  while (spanRuneEnumerator.MoveNext()) {
    Rune current = spanRuneEnumerator.get_Current();
    if (!current.get_IsAscii()) {
      Int32 bytesWritten;
      current.TryEncodeToUtf8(destination, bytesWritten);
      Span<Byte> span2 = destination.Slice(0, bytesWritten);
      for (Byte&& value : *span2) {
        vsb.Append('%');
        HexConverter::ToCharsBuffer(value, vsb.AppendSpan(2));
      }
      continue;
    }
    Byte b = (Byte)current.get_Value();
    if (noEscape[b]) {
      vsb.Append((Char)b);
      continue;
    }
    if (checkExistingEscaped && b == 37) {
      SpanRuneEnumerator spanRuneEnumerator2 = spanRuneEnumerator;
      if (spanRuneEnumerator2.MoveNext()) {
        Rune current2 = spanRuneEnumerator2.get_Current();
        if (current2.get_IsAscii() && IsHexDigit((Char)current2.get_Value()) && spanRuneEnumerator2.MoveNext()) {
          Rune current3 = spanRuneEnumerator2.get_Current();
          if (current3.get_IsAscii() && IsHexDigit((Char)current3.get_Value())) {
            vsb.Append('%');
            vsb.Append((Char)current2.get_Value());
            vsb.Append((Char)current3.get_Value());
            spanRuneEnumerator = spanRuneEnumerator2;
            continue;
          }
        }
      }
    }
    vsb.Append('%');
    HexConverter::ToCharsBuffer(b, vsb.AppendSpan(2));
  }
}

Array<Char> UriHelper::UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  {
    Char* ptr = input;
    Char* pStr = ptr;
    return UnescapeString(pStr, start, end, dest, destPosition, rsvd1, rsvd2, rsvd3, unescapeMode, syntax, isQuery);
  }
}

Array<Char> UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  ValueStringBuilder dest2 = ValueStringBuilder(dest->get_Length());
  dest2.Append(MemoryExtensions::AsSpan(dest, (Array<Char>)0, destPosition));
  UnescapeString(pStr, start, end, dest2, rsvd1, rsvd2, rsvd3, unescapeMode, syntax, isQuery);
  if (dest2.get_Length() > dest->get_Length()) {
    dest = dest2.AsSpan().ToArray();
  } else {
    dest2.AsSpan(destPosition).TryCopyTo(MemoryExtensions::AsSpan(dest, destPosition));
  }
  destPosition = dest2.get_Length();
  dest2.Dispose();
  return dest;
}

void UriHelper::UnescapeString(String input, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  {
    Char* ptr = input;
    Char* pStr = ptr;
    UnescapeString(pStr, start, end, dest, rsvd1, rsvd2, rsvd3, unescapeMode, syntax, isQuery);
  }
}

void UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  Array<Byte> array = nullptr;
  Boolean flag = false;
  Int32 i = start;
  Boolean flag2 = Uri::in::IriParsingStatic(syntax) && (unescapeMode & UnescapeMode::EscapeUnescape) == UnescapeMode::EscapeUnescape;
  Array<Char> array2 = nullptr;
  if ((unescapeMode & UnescapeMode::EscapeUnescape) == 0) {
    while (start < end) {
      dest.Append(*(pStr + start++));
    }
    return;
  }
  do {

  IL_003c:
    Char c = '\0';
    for (; i < end; i++) {
      if ((c = *(pStr + i)) == '%') {
        if ((unescapeMode & UnescapeMode::Unescape) == 0) {
          flag = true;
          break;
        }
        if (i + 2 < end) {
          c = DecodeHexChars(*(pStr + i + 1), *(pStr + i + 2));
          if (unescapeMode < UnescapeMode::UnescapeAll) {
            switch (c.get()) {
              case 'ÿ':
                if ((unescapeMode & UnescapeMode::Escape) == 0) {
                  continue;
                }
                flag = true;
                break;
              case '%':
                i += 2;
                continue;
              default:
                if (c == rsvd1 || c == rsvd2 || c == rsvd3) {
                  i += 2;
                  continue;
                }
                if ((unescapeMode & UnescapeMode::V1ToStringFlag) == 0 && IsNotSafeForUnescape(c)) {
                  i += 2;
                  continue;
                }
                if (flag2 && ((c <= '' && IsNotSafeForUnescape(c)) || (c > '' && !IriHelper::CheckIriUnicodeRange(c, isQuery)))) {
                  i += 2;
                  continue;
                }
                break;
            }
            break;
          }
          if (c != 'ÿ') {
            break;
          }
          if (unescapeMode >= UnescapeMode::UnescapeAllOrThrow) {
            rt::throw_exception<UriFormatException>(SR::get_net_uri_BadString());
          }
        } else {
          if (unescapeMode < UnescapeMode::UnescapeAll) {
            flag = true;
            break;
          }
          if (unescapeMode >= UnescapeMode::UnescapeAllOrThrow) {
            rt::throw_exception<UriFormatException>(SR::get_net_uri_BadString());
          }
        }
      } else if ((unescapeMode & (UnescapeMode::Unescape | UnescapeMode::UnescapeAll)) != (UnescapeMode::Unescape | UnescapeMode::UnescapeAll) && (unescapeMode & UnescapeMode::Escape) != 0) {
        if (c == rsvd1 || c == rsvd2 || c == rsvd3) {
          flag = true;
          break;
        }
        if ((unescapeMode & UnescapeMode::V1ToStringFlag) == 0 && (c <= '' || (c >= '' && c <= ''))) {
          flag = true;
          break;
        }
      }

    }
    while (start < i) {
      dest.Append(*(pStr + start++));
    }
    if (i == end) {
      continue;
    }
    if (flag) {
      EscapeAsciiChar((Byte)*(pStr + i), dest);
      flag = false;
      start = ++i;
      goto IL_003c;
    }
    if (c <= '') {
      dest.Append(c);
      i += 3;
      start = i;
      goto IL_003c;
    }
    Int32 byteCount = 1;
    if (array == nullptr) {
      array = rt::newarr<Array<Byte>>(end - i);
    }
    array[0] = (Byte)c;
    for (i += 3; i < end; i += 3) {
      if ((c = *(pStr + i)) != '%') {
        break;
      }
      if (i + 2 >= end) {
        break;
      }
      c = DecodeHexChars(*(pStr + i + 1), *(pStr + i + 2));
      if (c == 'ÿ' || c < '') {
        break;
      }
      array[byteCount++] = (Byte)c;
    }
    if (array2 == nullptr || array2->get_Length() < array->get_Length()) {
      array2 = rt::newarr<Array<Char>>(array->get_Length());
    }
    Int32 chars = s_noFallbackCharUTF8->GetChars(array, 0, byteCount, array2, 0);
    start = i;
    MatchUTF8Sequence(dest, MemoryExtensions::AsSpan(array2, (Array<Char>)0, chars), chars, array, byteCount, isQuery, flag2);
  } while (i != end)
}

void UriHelper::MatchUTF8Sequence(ValueStringBuilder& dest, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing) {
  Byte as[4] = {};
  Span<Byte> span = Span<Byte>(as, 4);
  Span<Byte> span2 = span;
  Int32 num = 0;
  {
    Char* ptr = unescapedChars;
    for (Int32 i = 0; i < charCount; i++) {
      Boolean flag = Char::IsHighSurrogate(*(ptr + i));
      Span<Byte> bytes2 = span2;
    }
  }
  while (num < byteCount) {
    EscapeAsciiChar(bytes[num++], dest);
  }
}

void UriHelper::EscapeAsciiChar(Byte b, ValueStringBuilder& to) {
  to.Append('%');
  HexConverter::ToCharsBuffer(b, to.AppendSpan(2));
}

Char UriHelper::DecodeHexChars(Int32 first, Int32 second) {
  Int32 num = HexConverter::FromChar(first);
  Int32 num2 = HexConverter::FromChar(second);
  if ((num | num2) == 255) {
    return 'ÿ';
  }
  return (Char)((num << 4) | num2);
}

Boolean UriHelper::IsNotSafeForUnescape(Char ch) {
  if (ch <= '' || (ch >= '' && ch <= '')) {
    return true;
  }
  return ";/?:@&=+$,#[]!'()*%\\#"->Contains(ch);
}

Boolean UriHelper::IsGenDelim(Char ch) {
  if (ch != ':' && ch != '/' && ch != '?' && ch != '#' && ch != '[' && ch != ']') {
    return ch == '@';
  }
  return true;
}

Boolean UriHelper::IsLWS(Char ch) {
  if (ch <= ' ') {
    if (ch != ' ' && ch != '\n' && ch != '\r') {
      return ch == '	';
    }
    return true;
  }
  return false;
}

Boolean UriHelper::IsAsciiLetter(Char character) {
  return ((UInt32)(character - 65) & -33) < 26;
}

Boolean UriHelper::IsAsciiLetterOrDigit(Char character) {
  if (((UInt32)(character - 65) & -33) >= 26) {
    return (UInt32)(character - 48) < 10u;
  }
  return true;
}

Boolean UriHelper::IsHexDigit(Char character) {
  return HexConverter::IsHexChar(character);
}

Boolean UriHelper::IsBidiControlCharacter(Char ch) {
  if (ch != '' && ch != '' && ch != '*' && ch != '+' && ch != ',' && ch != '-') {
    return ch == '.';
  }
  return true;
}

String UriHelper::StripBidiControlCharacters(ReadOnlySpan<Char> strToClean, String backingString) {
  Int32 num = 0;
  ReadOnlySpan<Char> readOnlySpan = strToClean;
  for (Char&& c : *readOnlySpan) {
    if ((UInt32)(c - 8206) <= 32u && IsBidiControlCharacter(c)) {
      num++;
    }
  }
  if (num == 0) {
    String as = backingString;
    return as != nullptr ? as : rt::newstr<String>(strToClean);
  }
  if (num == strToClean.get_Length()) {
    return String::in::Empty;
  }
  {
    Char* value = &MemoryMarshal::GetReference(strToClean);
    SpanAction<Char, ValueTuple<IntPtr, Int32>> as = __c::in::__9__27_0;
    return String::in::Create(strToClean.get_Length() - num, {(IntPtr)(void*)value, strToClean.get_Length()}, as != nullptr ? as : (__c::in::__9__27_0 = rt::newobj<SpanAction<Char, ValueTuple<IntPtr, Int32>>>(&_StripBidiControlCharacters_b__27_0)));
  }
}

void UriHelper::cctor() {
  s_noFallbackCharUTF8 = Encoding::in::GetEncoding(Encoding::in::get_UTF8()->get_CodePage(), rt::newobj<EncoderReplacementFallback>(""), rt::newobj<DecoderReplacementFallback>(""));
  s_WSchars = rt::newarr<Array<Char>>(4);
}

void UriHelper::_EscapeString_g__EnsureCapacity3_0(Array<Char> dest, Int32 destSize, Int32 requiredSize) {
  if (dest == nullptr || dest->get_Length() - destSize < requiredSize) {
    Array<>::in::Resize(dest, destSize + requiredSize + 120);
  }
}

} // namespace System::Private::Uri::System::UriHelperNamespace
