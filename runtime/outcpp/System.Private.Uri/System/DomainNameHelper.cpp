#include "DomainNameHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Globalization/IdnMapping-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/UriFormatException-dep.h>
#include <System.Private.Uri/System/UriHelper-dep.h>

namespace System::Private::Uri::System::DomainNameHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Globalization;

String DomainNameHelper::ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& loopback) {
  String text = nullptr;
  for (Int32 num = end - 1; num >= start; num--) {
    if (str[num] >= 'A' && str[num] <= 'Z') {
      text = str->Substring(start, end - start)->ToLowerInvariant();
      break;
    }
    if (str[num] == ':') {
      end = num;
    }
  }
  if (text == nullptr) {
    text = str->Substring(start, end - start);
  }
  if (text == "localhost" || text == "loopback") {
    loopback = true;
    return "localhost";
  }
  return text;
}

Boolean DomainNameHelper::IsValid(Char* name, Int32 pos, Int32& returnedEnd, Boolean& notCanonical, Boolean notImplicitFile) {
  Char* ptr = name + pos;
  Char* ptr2 = ptr;
  Char* ptr3;
  for (ptr3 = name + returnedEnd; ptr2 < ptr3; ptr2++) {
    Char c = *ptr2;
    if (c > '') {
      return false;
    }
    if (c < 'a' && (c == '/' || c == '\\' || (notImplicitFile && (c == ':' || c == '?' || c == '#')))) {
      ptr3 = ptr2;
      break;
    }
  }
  if (ptr3 == ptr) {
    return false;
  }
  while (true) {
    for (ptr2 = ptr; ptr2 < ptr3 && *ptr2 != '.'; ptr2++) {
    }
    if (ptr != ptr2 && ptr2 - ptr <= 63) {
      Char* intPtr = ptr;
      ptr = intPtr + 1;
      if (IsASCIILetterOrDigit(*intPtr, notCanonical)) {
        while (ptr < ptr2) {
          Char* intPtr2 = ptr;
          ptr = intPtr2 + 1;
          if (!IsValidDomainLabelCharacter(*intPtr2, notCanonical)) {
            return false;
          }
        }
        ptr++;
        if (ptr >= ptr3) {
          break;
        }
        continue;
      }
    }
    return false;
  }
  returnedEnd = (Int32)(ptr3 - name);
  return true;
}

Boolean DomainNameHelper::IsValidByIri(Char* name, Int32 pos, Int32& returnedEnd, Boolean& notCanonical, Boolean notImplicitFile) {
  Char* ptr = name + pos;
  Char* ptr2 = ptr;
  Char* ptr3 = name + returnedEnd;
  Int32 num = 0;
  for (; ptr2 < ptr3; ptr2++) {
    Char c = *ptr2;
    if (c == '/' || c == '\\' || (notImplicitFile && (c == ':' || c == '?' || c == '#'))) {
      ptr3 = ptr2;
      break;
    }
  }
  if (ptr3 == ptr) {
    return false;
  }
  while (true) {
    ptr2 = ptr;
    num = 0;
    Boolean flag = false;
    for (; ptr2 < ptr3 && *ptr2 != '.' && *ptr2 != '' && *ptr2 != '' && *ptr2 != 'a'; ptr2++) {
      num++;
      if (*ptr2 > 'ÿ') {
        num++;
      }
      if (*ptr2 >= ' ') {
        flag = true;
      }
    }
    if (ptr != ptr2 && (flag ? (num + 4) : num) <= 63) {
      Char* intPtr = ptr;
      ptr = intPtr + 1;
      if (*intPtr >= ' ' || IsASCIILetterOrDigit(*(ptr - 1), notCanonical)) {
        while (ptr < ptr2) {
          Char* intPtr2 = ptr;
          ptr = intPtr2 + 1;
          if (*intPtr2 < ' ' && !IsValidDomainLabelCharacter(*(ptr - 1), notCanonical)) {
            return false;
          }
        }
        ptr++;
        if (ptr >= ptr3) {
          break;
        }
        continue;
      }
    }
    return false;
  }
  returnedEnd = (Int32)(ptr3 - name);
  return true;
}

String DomainNameHelper::IdnEquivalent(String hostname) {
  if (hostname->get_Length() == 0) {
    return hostname;
  }
  Boolean flag = true;
  for (Char&& c : *hostname) {
    if (c > '') {
      flag = false;
      break;
    }
  }
  if (flag) {
    return hostname->ToLowerInvariant();
  }
  String unicode = UriHelper::StripBidiControlCharacters(hostname, hostname);
  try {
    String ascii = s_idnMapping->GetAscii(unicode);
    if (ContainsCharactersUnsafeForNormalizedHost(ascii)) {
      rt::throw_exception<UriFormatException>(SR::get_net_uri_BadUnicodeHostForIdn());
    }
    return ascii;
  } catch (ArgumentException) {
    rt::throw_exception<UriFormatException>(SR::get_net_uri_BadUnicodeHostForIdn());
  }
}

Boolean DomainNameHelper::IsIdnAce(String input, Int32 index) {
  if (input[index] == 'x' && input[index + 1] == 'n' && input[index + 2] == '-' && input[index + 3] == '-') {
    return true;
  }
  return false;
}

String DomainNameHelper::UnicodeEquivalent(Char* hostname, Int32 start, Int32 end, Boolean& allAscii, Boolean& atLeastOneValidIdn) {
  allAscii = true;
  atLeastOneValidIdn = false;
  String result = nullptr;
  if (end <= start) {
    return result;
  }
  String text = UriHelper::StripBidiControlCharacters(ReadOnlySpan<Char>(hostname + start, end - start));
  String text2 = nullptr;
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 length = text->get_Length();
  Boolean flag = true;
  Boolean flag2 = false;
  Boolean flag3 = false;
  Boolean flag4 = false;
  do {
    flag = true;
    flag2 = false;
    flag3 = false;
    flag4 = false;
    for (num2 = num; num2 < length; num2++) {
      Char c = text[num2];
      if (!flag3) {
        flag3 = true;
        if (num2 + 3 < length && c == 'x' && IsIdnAce(text, num2)) {
          flag2 = true;
        }
      }
      if (flag && c > '') {
        flag = false;
        allAscii = false;
      }
      if (c == '.' || c == '' || c == '' || c == 'a') {
        flag4 = true;
        break;
      }
    }
    if (!flag) {
      String unicode = text->Substring(num, num2 - num);
      try {
        unicode = s_idnMapping->GetAscii(unicode);
      } catch (ArgumentException) {
        rt::throw_exception<UriFormatException>(SR::get_net_uri_BadUnicodeHostForIdn());
      }
      text2 += s_idnMapping->GetUnicode(unicode);
      if (flag4) {
        text2 += ".";
      }
    } else {
      Boolean flag5 = false;
      if (flag2) {
        try {
          text2 += s_idnMapping->GetUnicode(text, num, num2 - num);
          if (flag4) {
            text2 += ".";
          }
          flag5 = true;
          atLeastOneValidIdn = true;
        } catch (ArgumentException) {
        }
      }
      if (!flag5) {
        text2 += text->Substring(num, num2 - num)->ToLowerInvariant();
        if (flag4) {
          text2 += ".";
        }
      }
    }
    num = num2 + (flag4 ? 1 : 0);
  } while (num < length);
  return text2;
}

Boolean DomainNameHelper::IsASCIILetterOrDigit(Char character, Boolean& notCanonical) {
  switch (character.get()) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      return true;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      notCanonical = true;
      return true;
    default:
      return false;
  }
}

Boolean DomainNameHelper::IsValidDomainLabelCharacter(Char character, Boolean& notCanonical) {
  switch (character.get()) {
    case '-':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '_':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      return true;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      notCanonical = true;
      return true;
    default:
      return false;
  }
}

Boolean DomainNameHelper::ContainsCharactersUnsafeForNormalizedHost(String host) {
  return host->IndexOfAny(s_UnsafeForNormalizedHost) != -1;
}

void DomainNameHelper::cctor() {
  s_idnMapping = rt::newobj<IdnMapping>();
  s_UnsafeForNormalizedHost = rt::newarr<Array<Char>>(8);
}

} // namespace System::Private::Uri::System::DomainNameHelperNamespace
