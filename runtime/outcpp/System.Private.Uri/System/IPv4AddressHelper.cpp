#include "IPv4AddressHelper-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::Uri::System::IPv4AddressHelperNamespace {
using namespace ::System::Private::CoreLib::System;

String IPv4AddressHelper::ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& isLoopback) {
  Byte as[4] = {};
  Byte* ptr = as;
  isLoopback = Parse(str, ptr, start, end);
  Char is[15] = {};
  Span<Char> span = is;
  Int32 num = 0;
  Int32 charsWritten;
  for (Int32 i = 0; i < 3; i++) {
    *(ptr + i).TryFormat(span.Slice(num), charsWritten);
    Int32 num2 = num + charsWritten;
    span[num2] = u'.';
    num = num2 + 1;
  }
  ptr[3].TryFormat(span.Slice(num), charsWritten);
  return rt::newstr<String>(span.Slice(0, num + charsWritten));
}

Boolean IPv4AddressHelper::Parse(String name, Byte* numbers, Int32 start, Int32 end) {
  {
    Char* ptr = rt::fixed(name);
    Char* name2 = ptr;
    Int32 end2 = end;
    Int64 num = ParseNonCanonical(name2, start, end2, true);
    *numbers = (Byte)(num >> 24);
    numbers[1] = (Byte)(num >> 16);
    numbers[2] = (Byte)(num >> 8);
    numbers[3] = (Byte)num;
  }
  return *numbers == 127;
}

Int32 IPv4AddressHelper::ParseHostNumber(ReadOnlySpan<Char> str, Int32 start, Int32 end) {
  Byte as[4] = {};
  Byte* ptr = as;
  ParseCanonical(str, ptr, start, end);
  return (*ptr << 24) + (ptr[1] << 16) + (ptr[2] << 8) + ptr[3];
}

Boolean IPv4AddressHelper::IsValid(Char* name, Int32 start, Int32& end, Boolean allowIPv6, Boolean notImplicitFile, Boolean unknownScheme) {
  if (allowIPv6 || unknownScheme) {
    return IsValidCanonical(name, start, end, allowIPv6, notImplicitFile);
  }
  return ParseNonCanonical(name, start, end, notImplicitFile) != -1;
}

Boolean IPv4AddressHelper::ParseCanonical(ReadOnlySpan<Char> name, Byte* numbers, Int32 start, Int32 end) {
  for (Int32 i = 0; i < 4; i++) {
    Int32 num = 0;
    Char c;
    while (start < end && (c = name[start]) != u'.' && c != u':') {
      num = num * 10 + c - 48;
      start++;
    }
    *(numbers + i) = (Byte)num;
    start++;
  }
  return *numbers == 127;
}

Boolean IPv4AddressHelper::IsValidCanonical(Char* name, Int32 start, Int32& end, Boolean allowIPv6, Boolean notImplicitFile) {
  Int32 num = 0;
  Int32 num2 = 0;
  Boolean flag = false;
  Boolean flag2 = false;
  while (start < end) {
    Char c = *(name + start);
    if (allowIPv6) {
      if (c == u']' || c == u'/' || c == u'%') {
        break;
      }
    } else if (c == u'/' || c == u'\\' || (notImplicitFile && (c == u':' || c == u'?' || c == u'#'))) {
      break;
    }

    if (c <= u'9' && c >= u'0') {
      if (!flag && c == u'0') {
        if (start + 1 < end && *(name + start + 1) == u'0') {
          return false;
        }
        flag2 = true;
      }
      flag = true;
      num2 = num2 * 10 + (*(name + start) - 48);
      if (num2 > 255) {
        return false;
      }
    } else {
      if (c != u'.') {
        return false;
      }
      if (!flag || (num2 > 0 && flag2)) {
        return false;
      }
      num++;
      flag = false;
      num2 = 0;
      flag2 = false;
    }
    start++;
  }
  Boolean flag3 = num == 3 && flag;
  if (flag3) {
    end = start;
  }
  return flag3;
}

Int64 IPv4AddressHelper::ParseNonCanonical(Char* name, Int32 start, Int32& end, Boolean notImplicitFile) {
  Int32 num = 10;
  Int64 as[4] = {};
  Int64* ptr = as;
  Int64 num2 = 0;
  Boolean flag = false;
  Int32 num3 = 0;
  Int32 i;
  for (i = start; i < end; i++) {
    Char c = *(name + i);
    num2 = 0;
    num = 10;
    if (c == u'0') {
      num = 8;
      i++;
      flag = true;
      if (i < end) {
        c = *(name + i);
        if (c == u'x' || c == u'X') {
          num = 16;
          i++;
          flag = false;
        }
      }
    }
    for (; i < end; i++) {
      c = *(name + i);
      Int32 num4;
      if ((num == 10 || num == 16) && u'0' <= c && c <= u'9') {
        num4 = c - 48;
      } else if (num == 8 && u'0' <= c && c <= u'7') {
        num4 = c - 48;
      } else if (num == 16 && u'a' <= c && c <= u'f') {
        num4 = c + 10 - 97;
      } else {
        if (num != 16 || u'A' > c || c > u'F') {
          break;
        }
        num4 = c + 10 - 65;
      }


      num2 = num2 * num + num4;
      if (num2 > UInt32::MaxValue) {
        return -1;
      }
      flag = true;
    }
    if (i >= end || *(name + i) != u'.') {
      break;
    }
    if (num3 >= 3 || !flag || num2 > 255) {
      return -1;
    }
    *(ptr + num3) = num2;
    num3++;
    flag = false;
  }
  if (!flag) {
    return -1;
  }
  if (i < end) {
    Char c;
    if ((c = *(name + i)) != u'/' && c != u'\\' && (!notImplicitFile || (c != u':' && c != u'?' && c != u'#'))) {
      return -1;
    }
    end = i;
  }
  *(ptr + num3) = num2;
  switch (num3.get()) {
    case 0:
      if (*ptr > UInt32::MaxValue) {
        return -1;
      }
      return *ptr;
    case 1:
      if (ptr[1] > 16777215) {
        return -1;
      }
      return (*ptr << 24) | (ptr[1] & 16777215);
    case 2:
      if (ptr[2] > 65535) {
        return -1;
      }
      return (*ptr << 24) | ((ptr[1] & 255) << 16) | (ptr[2] & 65535);
    case 3:
      if (ptr[3] > 255) {
        return -1;
      }
      return (*ptr << 24) | ((ptr[1] & 255) << 16) | ((ptr[2] & 255) << 8) | (ptr[3] & 255);
    default:
      return -1;
  }
}

} // namespace System::Private::Uri::System::IPv4AddressHelperNamespace
