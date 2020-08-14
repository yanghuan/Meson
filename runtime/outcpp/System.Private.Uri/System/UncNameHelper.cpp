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
    if (name[i] == 47 || name[i] == 92 || (notImplicitFile && (name[i] == 58 || name[i] == 63 || name[i] == 35))) {
      num = i;
      break;
    }
    if (name[i] == 46) {
      i++;
      break;
    }
    if (Char::IsLetter(name[i]) || name[i] == 45 || name[i] == 95) {
      flag = true;
    } else if (name[i] < 48 || name[i] > 57) {
      return false;
    }

  }
  if (!flag) {
    return false;
  }
  for (; i < num; i++) {
    if (name[i] == 47 || name[i] == 92 || (notImplicitFile && (name[i] == 58 || name[i] == 63 || name[i] == 35))) {
      num = i;
      break;
    }
    if (name[i] == 46) {
      if (!flag || (i - 1 >= start && name[i - 1] == 46)) {
        return false;
      }
      flag = false;
    }
    if (name[i] == 45 || name[i] == 95) {
      if (!flag) {
        return false;
      }
    }
    if (Char::IsLetter(name[i]) || (name[i] >= 48 && name[i] <= 57)) {
      if (!flag) {
        flag = true;
      }
    }
    return false;
  }
  if (i - 1 >= start && name[i - 1] == 46) {
    flag = true;
  }
  if (!flag) {
    return false;
  }
  returnedEnd = num;
  return true;
}

} // namespace System::Private::Uri::System::UncNameHelperNamespace
