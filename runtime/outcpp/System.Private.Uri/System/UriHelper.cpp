#include "UriHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/Text/SpanRuneEnumerator-dep.h>
#include <System.Private.Uri/System/HexConverter-dep.h>
#include <System.Private.Uri/System/Uri-dep.h>

namespace System::Private::Uri::System::UriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;

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
    Char c = selfPtr[i];
    Char c2 = otherPtr[i];
  }
  for (; i < selfLength; i++) {
    Char c;
    if ((c = selfPtr[i]) != 63) {
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
  ReadOnlySpan<Boolean> readOnlySpan = Span<T>();
}

Array<Char> UriHelper::EscapeString(ReadOnlySpan<Char> stringToEscape, Array<Char> dest, Int32& destPos, Boolean checkExistingEscaped, Char forceEscape1, Char forceEscape2) {
  ReadOnlySpan<Boolean> readOnlySpan = Span<T>();
}

void UriHelper::EscapeStringToBuilder(ReadOnlySpan<Char> stringToEscape, ValueStringBuilder& vsb, ReadOnlySpan<Boolean> noEscape, Boolean checkExistingEscaped) {
  Byte default[4] = {};
  Span<Byte> span = Span<Byte>(default, 4);
  Span<Byte> destination = span;
  SpanRuneEnumerator spanRuneEnumerator = MemoryExtensions::EnumerateRunes(stringToEscape);
  while (spanRuneEnumerator.MoveNext()) {
    Rune current = spanRuneEnumerator.get_Current();
    if (!current.get_IsAscii()) {
    }
    Byte b = (Byte)current.get_Value();
    if (noEscape[b]) {
      vsb.Append((Char)b);
    }
    if (checkExistingEscaped && b == 37) {
      SpanRuneEnumerator spanRuneEnumerator2 = spanRuneEnumerator;
      if (spanRuneEnumerator2.MoveNext()) {
        Rune current2 = spanRuneEnumerator2.get_Current();
        if (current2.get_IsAscii() && IsHexDigit((Char)current2.get_Value()) && spanRuneEnumerator2.MoveNext()) {
          Rune current3 = spanRuneEnumerator2.get_Current();
          if (current3.get_IsAscii() && IsHexDigit((Char)current3.get_Value())) {
            vsb.Append(37);
            vsb.Append((Char)current2.get_Value());
            vsb.Append((Char)current3.get_Value());
            spanRuneEnumerator = spanRuneEnumerator2;
          }
        }
      }
    }
    vsb.Append(37);
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
    Char* ptr = input;
    Char* pStr = ptr;
    UnescapeString(pStr, start, end, dest, rsvd1, rsvd2, rsvd3, unescapeMode, syntax, isQuery);
  }
}

void UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  Array<Byte> array = nullptr;
  Boolean flag = false;
  Int32 i = start;
}

void UriHelper::MatchUTF8Sequence(ValueStringBuilder& dest, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing) {
  Byte default[4] = {};
  Span<Byte> span = Span<Byte>(default, 4);
  Span<Byte> span2 = span;
  Int32 num = 0;
  {
    Char* ptr = unescapedChars;
    for (Int32 i = 0; i < charCount; i++) {
      Boolean flag = Char::IsHighSurrogate(ptr[i]);
      Span<Byte> bytes2 = span2;
    }
  }
  while (num < byteCount) {
    EscapeAsciiChar(bytes[num++], dest);
  }
}

void UriHelper::EscapeAsciiChar(Byte b, ValueStringBuilder& to) {
  to.Append(37);
  HexConverter::ToCharsBuffer(b, to.AppendSpan(2));
}

Char UriHelper::DecodeHexChars(UInt32 first, UInt32 second) {
  first -= 48;
  if (first > 9) {
  }
  second -= 48;
  if (second > 9) {
  }
}

Boolean UriHelper::IsNotSafeForUnescape(Char ch) {
  if (ch <= 31 || (ch >= 127 && ch <= 159)) {
    return true;
  }
  return ";/?:@&=+$,#[]!'()*%\#"->Contains(ch);
}

Boolean UriHelper::IsGenDelim(Char ch) {
  if (ch != 58 && ch != 47 && ch != 63 && ch != 35 && ch != 91 && ch != 93) {
    return ch == 64;
  }
  return true;
}

Boolean UriHelper::IsLWS(Char ch) {
  if (ch <= 32) {
    if (ch != 32 && ch != 10 && ch != 13) {
      return ch == 9;
    }
    return true;
  }
  return false;
}

Boolean UriHelper::IsAsciiLetter(Char character) {
}

Boolean UriHelper::IsAsciiLetterOrDigit(Char character) {
}

Boolean UriHelper::IsHexDigit(Char character) {
}

Boolean UriHelper::IsBidiControlCharacter(Char ch) {
  if (ch != 8206 && ch != 8207 && ch != 8234 && ch != 8235 && ch != 8236 && ch != 8237) {
    return ch == 8238;
  }
  return true;
}

String UriHelper::StripBidiControlCharacters(ReadOnlySpan<Char> strToClean, String backingString) {
  Int32 num = 0;
  ReadOnlySpan<Char> readOnlySpan = strToClean;
}

void UriHelper::cctor() {
  s_noFallbackCharUTF8 = Encoding::in::GetEncoding(Encoding::in::get_UTF8()->get_CodePage(), rt::newobj<EncoderReplacementFallback>(""), rt::newobj<DecoderReplacementFallback>(""));
  s_WSchars = rt::newarr<Array<Char>>(4);
}

} // namespace System::Private::Uri::System::UriHelperNamespace
