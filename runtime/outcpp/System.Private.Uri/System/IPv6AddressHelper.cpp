#include "IPv6AddressHelper-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/ValueTuple-dep.h>
#include <System.Private.Uri/System/IPv4AddressHelper-dep.h>
#include <System.Private.Uri/System/Uri-dep.h>

namespace System::Private::Uri::System::IPv6AddressHelperNamespace {
using namespace ::System::Private::CoreLib::System;

String IPv6AddressHelper::ParseCanonicalName(String str, Int32 start, Boolean& isLoopback, String& scopeId) {
  UInt16 as[8] = {};
  Span<UInt16> span = as;
  span.Clear();
  Parse(str, span, start, scopeId);
  isLoopback = IsLoopback(span);
  ValueTuple<Int32, Int32> tuple = FindCompressionRange(span);
  Int32 item = tuple.Item1;
  Int32 item2 = tuple.Item2;
  Boolean flag = ShouldHaveIpv4Embedded(span);
  Char is[48] = {};
  Span<Char> span2 = is;
  span2[0] = u'[';
  Int32 num = 1;
  for (Int32 i = 0; i < 8; i++) {
    Int32 charsWritten;
    if (flag && i == 6) {
      span2[num++] = u':';
      Boolean flag2 = (span[i] >> 8).TryFormat(span2.Slice(num), charsWritten);
      num += charsWritten;
      span2[num++] = u'.';
      flag2 = (span[i] & 255).TryFormat(span2.Slice(num), charsWritten);
      num += charsWritten;
      span2[num++] = u'.';
      flag2 = (span[i + 1] >> 8).TryFormat(span2.Slice(num), charsWritten);
      num += charsWritten;
      span2[num++] = u'.';
      flag2 = (span[i + 1] & 255).TryFormat(span2.Slice(num), charsWritten);
      num += charsWritten;
      break;
    }
    if (item == i) {
      span2[num++] = u':';
    }
    if (item <= i && item2 == 8) {
      span2[num++] = u':';
      break;
    }
    if (item > i || i >= item2) {
      if (i != 0) {
        span2[num++] = u':';
      }
      Boolean flag2 = span[i].TryFormat(span2.Slice(num), charsWritten, "x");
      num += charsWritten;
    }
  }
  span2[num++] = u']';
  return rt::newstr<String>(span2.Slice(0, num));
}

Boolean IPv6AddressHelper::IsLoopback(ReadOnlySpan<UInt16> numbers) {
  if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0 && numbers[4] == 0) {
    if (numbers[5] != 0 || numbers[6] != 0 || numbers[7] != 1) {
      if (numbers[6] == 32512 && numbers[7] == 1) {
        if (numbers[5] != 0) {
          return numbers[5] == UInt16::MaxValue;
        }
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

Boolean IPv6AddressHelper::InternalIsValid(Char* name, Int32 start, Int32& end, Boolean validateStrictAddress) {
  Int32 num = 0;
  Int32 num2 = 0;
  Boolean flag = false;
  Boolean flag2 = false;
  Boolean flag3 = false;
  Boolean flag4 = true;
  Int32 start2 = 1;
  if (*(name + start) == u':' && (start + 1 >= end || *(name + start + 1) != u':')) {
    return false;
  }
  Int32 i;
  for (i = start; i < end; i++) {
    if ((!flag3) ? Uri::in::IsHexDigit(*(name + i)) : (Boolean)(*(name + i) >= u'0' && *(name + i) <= u'9')) {
      num2++;
      flag4 = false;
      continue;
    }
    if (num2 > 4) {
      return false;
    }
    if (num2 != 0) {
      num++;
      start2 = i - num2;
    }
    Char c = *(name + i);
    if ((UInt32)c <= 46u) {
      if (c == u'%') {
        while (true) {
          if (++i == end) {
            return false;
          }
          if (*(name + i) == u']') {
            break;
          }
          if (*(name + i) != u'/') {
            continue;
          }
          goto IL_011c;
        }
        goto IL_00ee;
      }
      if (c != u'.') {
        goto IL_015c;
      }
      if (flag2) {
        return false;
      }
      i = end;
      if (!IPv4AddressHelper::IsValid(name, start2, i, true, false, false)) {
        return false;
      }
      num++;
      flag2 = true;
      i--;
    } else {
      if (c == u'/') {
        goto IL_011c;
      }
      if (c != u':') {
        if (c == u']') {
          goto IL_00ee;
        }
        goto IL_015c;
      }
      if (i > 0 && *(name + i - 1) == u':') {
        if (flag) {
          return false;
        }
        flag = true;
        flag4 = false;
      } else {
        flag4 = true;
      }
    }
    goto IL_015e;

  IL_011c:
    if (validateStrictAddress) {
      return false;
    }
    if (num == 0 || flag3) {
      return false;
    }
    flag3 = true;
    flag4 = true;
    goto IL_015e;

  IL_00ee:
    start = i;
    i = end;
    continue;

  IL_015e:
    num2 = 0;
    continue;

  IL_015c:
    return false;
  }
  if (flag3 && (num2 < 1 || num2 > 2)) {
    return false;
  }
  Int32 num3 = 8 + (flag3 ? 1 : 0);
  if (!flag4 && num2 <= 4 && (flag ? (Boolean)(num < num3) : (Boolean)(num == num3))) {
    if (i == end + 1) {
      end = start + 1;
      return true;
    }
    return false;
  }
  return false;
}

Boolean IPv6AddressHelper::IsValid(Char* name, Int32 start, Int32& end) {
  return InternalIsValid(name, start, end, false);
}

ValueTuple<Int32, Int32> IPv6AddressHelper::FindCompressionRange(ReadOnlySpan<UInt16> numbers) {
  Int32 num = 0;
  Int32 num2 = -1;
  Int32 num3 = 0;
  for (Int32 i = 0; i < numbers.get_Length(); i++) {
    if (numbers[i] == 0) {
      num3++;
      if (num3 > num) {
        num = num3;
        num2 = i - num3 + 1;
      }
    } else {
      num3 = 0;
    }
  }
  if (num <= 1) {
    return {-1, -1};
  }
  return {num2, num2 + num};
}

Boolean IPv6AddressHelper::ShouldHaveIpv4Embedded(ReadOnlySpan<UInt16> numbers) {
  if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0 && numbers[6] != 0) {
    if (numbers[4] == 0 && (numbers[5] == 0 || numbers[5] == UInt16::MaxValue)) {
      return true;
    }
    if (numbers[4] == UInt16::MaxValue && numbers[5] == 0) {
      return true;
    }
  }
  if (numbers[4] == 0) {
    return numbers[5] == 24318;
  }
  return false;
}

void IPv6AddressHelper::Parse(ReadOnlySpan<Char> address, Span<UInt16> numbers, Int32 start, String& scopeId) {
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 num3 = -1;
  Boolean flag = true;
  Int32 num4 = 0;
  if (address[start] == u'[') {
    start++;
  }
  Int32 i = start;
  while (i < address.get_Length() && address[i] != u']') {
    switch (address[i].get()) {
      case u'%':
        if (flag) {
          numbers[num2++] = (UInt16)num;
          flag = false;
        }
        start = i;
        for (i++; i < address.get_Length() && address[i] != u']' && address[i] != u'/'; i++) {
        }
        scopeId = rt::newstr<String>(address.Slice(start, i - start));
        for (; i < address.get_Length() && address[i] != u']'; i++) {
        }
        break;
      case u':':
        {
          numbers[num2++] = (UInt16)num;
          num = 0;
          i++;
          if (address[i] == u':') {
            num3 = num2;
            i++;
          } else if (num3 < 0 && num2 < 6) {
            break;
          }

          for (Int32 j = i; j < address.get_Length() && address[j] != u']' && address[j] != u':' && address[j] != u'%' && address[j] != u'/' && j < i + 4; j++) {
            if (address[j] == u'.') {
              for (; j < address.get_Length() && address[j] != u']' && address[j] != u'/' && address[j] != u'%'; j++) {
              }
              num = IPv4AddressHelper::ParseHostNumber(address, i, j);
              numbers[num2++] = (UInt16)(num >> 16);
              numbers[num2++] = (UInt16)num;
              i = j;
              num = 0;
              flag = false;
              break;
            }
          }
          break;
        }case u'/':
        if (flag) {
          numbers[num2++] = (UInt16)num;
          flag = false;
        }
        for (i++; address[i] != u']'; i++) {
          num4 = num4 * 10 + (address[i] - 48);
        }
        break;
      default:
        num = num * 16 + Uri::in::FromHex(address[i++]);
        break;
    }
  }
  if (flag) {
    numbers[num2++] = (UInt16)num;
  }
  if (num3 <= 0) {
    return;
  }
  Int32 num5 = 7;
  Int32 num6 = num2 - 1;
  if (num6 != num5) {
    for (Int32 num7 = num2 - num3; num7 > 0; num7--) {
      numbers[num5--] = numbers[num6];
      numbers[num6--] = 0;
    }
  }
}

} // namespace System::Private::Uri::System::IPv6AddressHelperNamespace
