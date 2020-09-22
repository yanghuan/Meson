#include "IriHelper-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.Uri/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.Uri/System/UriHelper-dep.h>

namespace System::Private::Uri::System::IriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
using namespace System::Text;

Boolean IriHelper::CheckIriUnicodeRange(Char unicode, Boolean isQuery) {
  if ((unicode < ' ' || unicode > 'ÿ') && (unicode < '\0' || unicode > 'Ï') && (unicode < 'ð' || unicode > 'ï')) {
    if (isQuery && unicode >= '\0') {
      return unicode <= 'ÿ';
    }
    return false;
  }
  return true;
}

Boolean IriHelper::CheckIriUnicodeRange(Char highSurr, Char lowSurr, Boolean& isSurrogatePair, Boolean isQuery) {
  Rune result;
  if (Rune::TryCreate(highSurr, lowSurr, result)) {
    isSurrogatePair = true;
    if ((result.get_Value() & 65535) < 65534 && (UInt32)(result.get_Value() - 917504) >= 4096u) {
      if (!isQuery) {
        return result.get_Value() < 983040;
      }
      return true;
    }
    return false;
  }
  isSurrogatePair = false;
  return false;
}

Boolean IriHelper::CheckIsReserved(Char ch, UriComponents component) {
  if ((UriComponents::AbsoluteUri & component) == 0) {
    if (component == (UriComponents)0) {
      return UriHelper::IsGenDelim(ch);
    }
    return false;
  }
  return ";/?:@&=+$,#[]!'()*"->Contains(ch);
}

String IriHelper::EscapeUnescapeIri(Char* pInput, Int32 start, Int32 end, UriComponents component) {
  Int32 initialCapacity = end - start;
  ValueStringBuilder dest = ValueStringBuilder(initialCapacity);
  Array<Byte> array = nullptr;
  Int32 i = start;
  Byte as[4] = {};
  Span<Byte> span = Span<Byte>(as, 4);
  Span<Byte> destination = span;
  for (; i < end; i++) {
    Char c;
    if ((c = *(pInput + i)) == '%') {
      if (i + 2 < end) {
        c = UriHelper::DecodeHexChars(*(pInput + i + 1), *(pInput + i + 2));
        if (c == 'ÿ' || c == '%' || CheckIsReserved(c, component) || UriHelper::IsNotSafeForUnescape(c)) {
          dest.Append(*(pInput + i++));
          dest.Append(*(pInput + i++));
          dest.Append(*(pInput + i));
          continue;
        }
        if (c <= '') {
          dest.Append(c);
          i += 2;
          continue;
        }
        Int32 num = i;
        Int32 byteCount = 1;
        if (array == nullptr) {
          array = rt::newarr<Array<Byte>>(end - i);
        }
        array[0] = (Byte)c;
        for (i += 3; i < end; i += 3) {
          if ((c = *(pInput + i)) != '%') {
            break;
          }
          if (i + 2 >= end) {
            break;
          }
          c = UriHelper::DecodeHexChars(*(pInput + i + 1), *(pInput + i + 2));
          if (c == 'ÿ' || c < '') {
            break;
          }
          array[byteCount++] = (Byte)c;
        }
        i--;
        Encoding encoding = Encoding::in::GetEncoding(Encoding::in::get_UTF8()->get_CodePage(), rt::newobj<EncoderReplacementFallback>(""), rt::newobj<DecoderReplacementFallback>(""));
        Array<Char> array2 = rt::newarr<Array<Char>>(array->get_Length());
        Int32 chars = encoding->GetChars(array, 0, byteCount, array2, 0);
        if (chars != 0) {
          UriHelper::MatchUTF8Sequence(dest, array2, chars, array, byteCount, component == UriComponents::Query, true);
          continue;
        }
        for (Int32 j = num; j <= i; j++) {
          dest.Append(*(pInput + j));
        }
      } else {
        dest.Append(*(pInput + i));
      }
    } else if (c > '') {
      Boolean isSurrogatePair = false;
      Char c2 = '\0';
      Boolean flag;
      if (Char::IsHighSurrogate(c) && i + 1 < end) {
        c2 = *(pInput + i + 1);
        flag = CheckIriUnicodeRange(c, c2, isSurrogatePair, component == UriComponents::Query);
      } else {
        flag = CheckIriUnicodeRange(c, component == UriComponents::Query);
      }
      if (flag) {
        dest.Append(c);
        if (isSurrogatePair) {
          dest.Append(c2);
        }
      } else {
        Rune result;
        if (isSurrogatePair) {
          result = Rune(c, c2);
        } else if (!Rune::TryCreate(c, result)) {
          result = Rune::get_ReplacementChar();
        }

        Int32 length = result.EncodeToUtf8(destination);
        Span<Byte> span2 = destination.Slice(0, length);
        Span<Byte> span3 = span2;
        for (Byte&& b : *span3) {
          UriHelper::EscapeAsciiChar(b, dest);
        }
      }
      if (isSurrogatePair) {
        i++;
      }
    } else {
      dest.Append(*(pInput + i));
    }

  }
  return dest.ToString();
}

} // namespace System::Private::Uri::System::IriHelperNamespace
