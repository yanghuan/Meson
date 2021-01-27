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
  __9 = rt::newobj<__c>();
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
      case u'#':
      case u'?':
        return true;
      case u'/':
        if (c2 != u'/') {
          return false;
        }
        if (!flag) {
          return false;
        }
        flag = true;
        continue;
      default:
        if (c2 == u'?' || c2 == u'#') {
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
    if ((c = *(selfPtr + i)) != u'?') {
      switch (c.get()) {
        case u'#':
          break;
        case u'/':
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
    Boolean as[128] = {};
    Span<Boolean> span = as;
    unreserved.CopyTo(span);
    span[forceEscape1] = false;
    span[forceEscape2] = false;
    readOnlySpan = span;
  }
  Int32 i;
  for (i = 0; i < stringToEscape->get_Length(); i++) {
    Char index;
    if ((index = stringToEscape[i]) > u'\x007f') {
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
    Boolean as[128] = {};
    Span<Boolean> span = as;
    get_UnreservedReservedTable().CopyTo(span);
    span[forceEscape1] = false;
    span[forceEscape2] = false;
    readOnlySpan = span;
  }
  Int32 i;
  for (i = 0; i < stringToEscape.get_Length(); i++) {
    Char index;
    if ((index = stringToEscape[i]) > u'\x007f') {
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
  Span<Byte> destination = as;
  SpanRuneEnumerator spanRuneEnumerator = MemoryExtensions::EnumerateRunes(stringToEscape);
  while (spanRuneEnumerator.MoveNext()) {
    Rune current = spanRuneEnumerator.get_Current();
    if (!current.get_IsAscii()) {
      Int32 bytesWritten;
      current.TryEncodeToUtf8(destination, bytesWritten);
      Span<Byte> span = destination.Slice(0, bytesWritten);
      for (Byte&& value : *span) {
        vsb.Append(u'%');
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
            vsb.Append(u'%');
            vsb.Append((Char)current2.get_Value());
            vsb.Append((Char)current3.get_Value());
            spanRuneEnumerator = spanRuneEnumerator2;
            continue;
          }
        }
      }
    }
    vsb.Append(u'%');
    HexConverter::ToCharsBuffer(b, vsb.AppendSpan(2));
  }
}

Array<Char> UriHelper::UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  {
    Char* ptr = rt::fixed(input);
    Char* pStr = ptr;
    return UnescapeString(pStr, start, end, dest, destPosition, rsvd1, rsvd2, rsvd3, unescapeMode, syntax, isQuery);
  }
}

Array<Char> UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  ValueStringBuilder dest2 = ValueStringBuilder(dest->get_Length());
  dest2.Append(MemoryExtensions::AsSpan(dest, 0, destPosition));
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
    Char* ptr = rt::fixed(input);
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
    Char c = u'\0';
    for (; i < end; i++) {
      if ((c = *(pStr + i)) == u'%') {
        if ((unescapeMode & UnescapeMode::Unescape) == 0) {
          flag = true;
          break;
        }
        if (i + 2 < end) {
          c = DecodeHexChars(*(pStr + i + 1), *(pStr + i + 2));
          if (unescapeMode < UnescapeMode::UnescapeAll) {
            switch (c.get()) {
              case u'\xffff':
                if ((unescapeMode & UnescapeMode::Escape) == 0) {
                  continue;
                }
                flag = true;
                break;
              case u'%':
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
                if (flag2 && ((c <= u'\x009f' && IsNotSafeForUnescape(c)) || (c > u'\x009f' && !IriHelper::CheckIriUnicodeRange(c, isQuery)))) {
                  i += 2;
                  continue;
                }
                break;
            }
            break;
          }
          if (c != u'\xffff') {
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
        if ((unescapeMode & UnescapeMode::V1ToStringFlag) == 0 && (c <= u'\x001f' || (c >= u'\x007f' && c <= u'\x009f'))) {
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
    if (c <= u'\x007f') {
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
      if ((c = *(pStr + i)) != u'%') {
        break;
      }
      if (i + 2 >= end) {
        break;
      }
      c = DecodeHexChars(*(pStr + i + 1), *(pStr + i + 2));
      if (c == u'\xffff' || c < u'\x0080') {
        break;
      }
      array[byteCount++] = (Byte)c;
    }
    if (array2 == nullptr || array2->get_Length() < array->get_Length()) {
      array2 = rt::newarr<Array<Char>>(array->get_Length());
    }
    Int32 chars = s_noFallbackCharUTF8->GetChars(array, 0, byteCount, array2, 0);
    start = i;
    MatchUTF8Sequence(dest, MemoryExtensions::AsSpan(array2, 0, chars), chars, array, byteCount, isQuery, flag2);
  } while (i != end);
}

void UriHelper::MatchUTF8Sequence(ValueStringBuilder& dest, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing) {
  Byte as[4] = {};
  Span<Byte> span = as;
  Int32 num = 0;
  {
    Char* ptr = rt::fixed(unescapedChars);
    for (Int32 i = 0; i < charCount; i++) {
      Boolean flag = Char::IsHighSurrogate(*(ptr + i));
      Span<Byte> bytes2 = span;
      Int32 bytes3 = Encoding::in::get_UTF8()->GetBytes(unescapedChars.Slice(i, (!flag) ? 1 : 2), bytes2);
      bytes2 = bytes2.Slice(0, bytes3);
      Boolean flag2 = false;
      if (iriParsing) {
        Boolean isSurrogatePair;
        flag2 = (flag ? IriHelper::CheckIriUnicodeRange(unescapedChars[i], unescapedChars[i + 1], isSurrogatePair, isQuery) : IriHelper::CheckIriUnicodeRange(unescapedChars[i], isQuery));
      }
      while (true) {
        if (bytes[num] != bytes2[0]) {
          EscapeAsciiChar(bytes[num++], dest);
          continue;
        }
        Boolean flag3 = true;
        Int32 j;
        for (j = 0; j < bytes2.get_Length(); j++) {
          if (bytes[num + j] != bytes2[j]) {
            flag3 = false;
            break;
          }
        }
        if (flag3) {
          break;
        }
        for (Int32 k = 0; k < j; k++) {
          EscapeAsciiChar(bytes[num++], dest);
        }
      }
      num += bytes2.get_Length();
      if (iriParsing) {
        if (!flag2) {
          for (Int32 l = 0; l < bytes2.get_Length(); l++) {
            EscapeAsciiChar(bytes2[l], dest);
          }
        } else {
          dest.Append(*(ptr + i));
          if (flag) {
            dest.Append(*(ptr + i + 1));
          }
        }
      } else {
        dest.Append(*(ptr + i));
        if (flag) {
          dest.Append(*(ptr + i + 1));
        }
      }
      if (flag) {
        i++;
      }
    }
  }
  while (num < byteCount) {
    EscapeAsciiChar(bytes[num++], dest);
  }
}

void UriHelper::EscapeAsciiChar(Byte b, ValueStringBuilder& to) {
  to.Append(u'%');
  HexConverter::ToCharsBuffer(b, to.AppendSpan(2));
}

Char UriHelper::DecodeHexChars(Int32 first, Int32 second) {
  Int32 num = HexConverter::FromChar(first);
  Int32 num2 = HexConverter::FromChar(second);
  if ((num | num2) == 255) {
    return u'\xffff';
  }
  return (Char)((num << 4) | num2);
}

Boolean UriHelper::IsNotSafeForUnescape(Char ch) {
  if (ch <= u'\x001f' || (ch >= u'\x007f' && ch <= u'\x009f')) {
    return true;
  }
  return ";/?:@&=+$,#[]!'()*%\\#"->Contains(ch);
}

Boolean UriHelper::IsGenDelim(Char ch) {
  if (ch != u':' && ch != u'/' && ch != u'?' && ch != u'#' && ch != u'[' && ch != u']') {
    return ch == u'@';
  }
  return true;
}

Boolean UriHelper::IsLWS(Char ch) {
  if (ch <= u' ') {
    if (ch != u' ' && ch != u'\n' && ch != u'\r') {
      return ch == u'	';
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
  if (ch != u'\x200e' && ch != u'\x200f' && ch != u'\x202a' && ch != u'\x202b' && ch != u'\x202c' && ch != u'\x202d') {
    return ch == u'\x202e';
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
    Char* value = rt::fixed(&MemoryMarshal::GetReference(strToClean));
    SpanAction<Char, ValueTuple<IntPtr, Int32>> as = __c::in::__9__27_0;
    return String::in::Create(strToClean.get_Length() - num, {(IntPtr)value, strToClean.get_Length()}, as != nullptr ? as : (__c::in::__9__27_0 = {__c::in::__9, &__c::in::_StripBidiControlCharacters_b__27_0}));
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
