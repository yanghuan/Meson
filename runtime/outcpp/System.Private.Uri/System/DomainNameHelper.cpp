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
    if (str[num] >= 65 && str[num] <= 90) {
      text = str->Substring(start, end - start)->ToLowerInvariant();
      break;
    }
    if (str[num] == 58) {
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
    if (c > 127) {
      return false;
    }
    if (c < 97 && (c == 47 || c == 92 || (notImplicitFile && (c == 58 || c == 63 || c == 35)))) {
      ptr3 = ptr2;
      break;
    }
  }
  if (ptr3 == ptr) {
    return false;
  }
  while (true) {
    for (ptr2 = ptr; ptr2 < ptr3 && *ptr2 != 46; ptr2++) {
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
    if (c == 47 || c == 92 || (notImplicitFile && (c == 58 || c == 63 || c == 35))) {
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
    for (; ptr2 < ptr3 && *ptr2 != 46 && *ptr2 != 12290 && *ptr2 != 65294 && *ptr2 != 65377; ptr2++) {
      num++;
      if (*ptr2 > 255) {
        num++;
      }
      if (*ptr2 >= 160) {
        flag = true;
      }
    }
    if (ptr != ptr2 && (flag ? (num + 4) : num) <= 63) {
      Char* intPtr = ptr;
      ptr = intPtr + 1;
      if (*intPtr >= 160 || IsASCIILetterOrDigit(*(ptr - 1), notCanonical)) {
        while (ptr < ptr2) {
          Char* intPtr2 = ptr;
          ptr = intPtr2 + 1;
          if (*intPtr2 < 160 && !IsValidDomainLabelCharacter(*(ptr - 1), notCanonical)) {
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
  for (Char& c : hostname) {
    if (c > 127) {
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
  }
}

Boolean DomainNameHelper::IsIdnAce(String input, Int32 index) {
  if (input[index] == 120 && input[index + 1] == 110 && input[index + 2] == 45 && input[index + 3] == 45) {
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
        if (num2 + 3 < length && c == 120 && IsIdnAce(text, num2)) {
          flag2 = true;
        }
      }
      if (flag && c > 127) {
        flag = false;
        allAscii = false;
      }
      if (c == 46 || c == 12290 || c == 65294 || c == 65377) {
        flag4 = true;
        break;
      }
    }
    if (!flag) {
      String unicode = text->Substring(num, num2 - num);
      try {
        unicode = s_idnMapping->GetAscii(unicode);
      } catch (ArgumentException) {
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
  } while (num < length)
  return text2;
}

Boolean DomainNameHelper::IsASCIILetterOrDigit(Char character, Boolean& notCanonical) {
  switch (character.get()) {
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
      return true;
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
      notCanonical = true;
      return true;
    default:
      return false;
  }
}

Boolean DomainNameHelper::IsValidDomainLabelCharacter(Char character, Boolean& notCanonical) {
  switch (character.get()) {
    case 45:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 95:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
      return true;
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
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
