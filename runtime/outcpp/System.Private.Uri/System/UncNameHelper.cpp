#include "UncNameHelper-dep.h"

#include <System.Private.Uri/System/DomainNameHelper-dep.h>

namespace System::Private::Uri::System::UncNameHelperNamespace {
String UncNameHelper::ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& loopback) {
  return DomainNameHelper::ParseCanonicalName(str, start, end, loopback);
}

Boolean UncNameHelper::IsValid(Char* name, Int32 start, Int32& returnedEnd, Boolean notImplicitFile) {
  Int32 num = returnedEnd;
  if (start == num) {
    return false;
  }
  Boolean flag = false;
  Int32 i;
  for (i = start; i < num; i++) {
    if (*(name + i) == '/' || *(name + i) == '\\' || (notImplicitFile && (*(name + i) == ':' || *(name + i) == '?' || *(name + i) == '#'))) {
      num = i;
      break;
    }
    if (*(name + i) == '.') {
      i++;
      break;
    }
    if (Char::IsLetter(*(name + i)) || *(name + i) == '-' || *(name + i) == '_') {
      flag = true;
    } else if (*(name + i) < '0' || *(name + i) > '9') {
      return false;
    }

  }
  if (!flag) {
    return false;
  }
  for (; i < num; i++) {
    if (*(name + i) == '/' || *(name + i) == '\\' || (notImplicitFile && (*(name + i) == ':' || *(name + i) == '?' || *(name + i) == '#'))) {
      num = i;
      break;
    }
    if (*(name + i) == '.') {
      if (!flag || (i - 1 >= start && *(name + i - 1) == '.')) {
        return false;
      }
      flag = false;
      continue;
    }
    if (*(name + i) == '-' || *(name + i) == '_') {
      if (!flag) {
        return false;
      }
      continue;
    }
    if (Char::IsLetter(*(name + i)) || (*(name + i) >= '0' && *(name + i) <= '9')) {
      if (!flag) {
        flag = true;
      }
      continue;
    }
    return false;
  }
  if (i - 1 >= start && *(name + i - 1) == '.') {
    flag = true;
  }
  if (!flag) {
    return false;
  }
  returnedEnd = num;
  return true;
}

} // namespace System::Private::Uri::System::UncNameHelperNamespace
