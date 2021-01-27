#include "PathInternal-dep.h"

#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>

namespace System::Private::CoreLib::System::IO::PathInternalNamespace {
using namespace System::Text;

Boolean PathInternal::StartsWithDirectorySeparator(ReadOnlySpan<Char> path) {
  if (path.get_Length() > 0) {
    return IsDirectorySeparator(path[0]);
  }
  return false;
}

Boolean PathInternal::IsRoot(ReadOnlySpan<Char> path) {
  return path.get_Length() == GetRootLength(path);
}

Int32 PathInternal::GetCommonPathLength(String first, String second, Boolean ignoreCase) {
  Int32 num = EqualStartingCharacterCount(first, second, ignoreCase);
  if (num == 0) {
    return num;
  }
  if (num == first->get_Length() && (num == second->get_Length() || IsDirectorySeparator(second[num]))) {
    return num;
  }
  if (num == second->get_Length() && IsDirectorySeparator(first[num])) {
    return num;
  }
  while (num > 0 && !IsDirectorySeparator(first[num - 1])) {
    num--;
  }
  return num;
}

Int32 PathInternal::EqualStartingCharacterCount(String first, String second, Boolean ignoreCase) {
  if (String::in::IsNullOrEmpty(first) || String::in::IsNullOrEmpty(second)) {
    return 0;
  }
  Int32 num = 0;
  {
    Char* ptr = rt::fixed(first);
    Char* ptr2 = ptr;
    {
      Char* ptr3 = rt::fixed(second);
      Char* ptr4 = ptr3;
      Char* ptr5 = ptr2;
      Char* ptr6 = ptr4;
      Char* ptr7 = ptr5 + first->get_Length();
      Char* ptr8 = ptr6 + second->get_Length();
      while (ptr5 != ptr7 && ptr6 != ptr8 && (*ptr5 == *ptr6 || (ignoreCase && Char::ToUpperInvariant(*ptr5) == Char::ToUpperInvariant(*ptr6)))) {
        num++;
        ptr5++;
        ptr6++;
      }
    }
  }
  return num;
}

Boolean PathInternal::AreRootsEqual(String first, String second, StringComparison comparisonType) {
  Int32 rootLength = GetRootLength(MemoryExtensions::AsSpan(first));
  Int32 rootLength2 = GetRootLength(MemoryExtensions::AsSpan(second));
  if (rootLength == rootLength2) {
    return String::in::Compare(first, 0, second, 0, rootLength, comparisonType) == 0;
  }
  return false;
}

String PathInternal::RemoveRelativeSegments(String path, Int32 rootLength) {
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder sb = ValueStringBuilder(initialBuffer);
  if (RemoveRelativeSegments(MemoryExtensions::AsSpan(path), rootLength, sb)) {
    path = sb.ToString();
  }
  sb.Dispose();
  return path;
}

Boolean PathInternal::RemoveRelativeSegments(ReadOnlySpan<Char> path, Int32 rootLength, ValueStringBuilder& sb) {
  Boolean flag = false;
  Int32 num = rootLength;
  if (IsDirectorySeparator(path[num - 1])) {
    num--;
  }
  if (num > 0) {
    sb.Append(path.Slice(0, num));
  }
  for (Int32 i = num; i < path.get_Length(); i++) {
    Char c = path[i];
    if (IsDirectorySeparator(c) && i + 1 < path.get_Length()) {
      if (IsDirectorySeparator(path[i + 1])) {
        continue;
      }
      if ((i + 2 == path.get_Length() || IsDirectorySeparator(path[i + 2])) && path[i + 1] == u'.') {
        i++;
        continue;
      }
      if (i + 2 < path.get_Length() && (i + 3 == path.get_Length() || IsDirectorySeparator(path[i + 3])) && path[i + 1] == u'.' && path[i + 2] == u'.') {
        Int32 num2;
        for (num2 = sb.get_Length() - 1; num2 >= num; num2--) {
          if (IsDirectorySeparator(sb[num2])) {
            sb.set_Length(((i + 3 >= path.get_Length() && num2 == num) ? (num2 + 1) : num2));
            break;
          }
        }
        if (num2 < num) {
          sb.set_Length(num);
        }
        i += 2;
        continue;
      }
    }
    if (c != u'\\' && c == u'/') {
      c = u'\\';
      flag = true;
    }
    sb.Append(c);
  }
  if (!flag && sb.get_Length() == path.get_Length()) {
    return false;
  }
  if (num != rootLength && sb.get_Length() < rootLength) {
    sb.Append(path[rootLength - 1]);
  }
  return true;
}

String PathInternal::TrimEndingDirectorySeparator(String path) {
  if (!EndsInDirectorySeparator(path) || IsRoot(MemoryExtensions::AsSpan(path))) {
    return path;
  }
  return path->Substring(0, path->get_Length() - 1);
}

Boolean PathInternal::EndsInDirectorySeparator(String path) {
  if (!String::in::IsNullOrEmpty(path)) {
    return IsDirectorySeparator(path[path->get_Length() - 1]);
  }
  return false;
}

ReadOnlySpan<Char> PathInternal::TrimEndingDirectorySeparator(ReadOnlySpan<Char> path) {
  if (!EndsInDirectorySeparator(path) || IsRoot(path)) {
    return path;
  }
  return path.Slice(0, path.get_Length() - 1);
}

Boolean PathInternal::EndsInDirectorySeparator(ReadOnlySpan<Char> path) {
  if (path.get_Length() > 0) {
    return IsDirectorySeparator(path[path.get_Length() - 1]);
  }
  return false;
}

Boolean PathInternal::IsValidDriveChar(Char value) {
  if (value < u'A' || value > u'Z') {
    if (value >= u'a') {
      return value <= u'z';
    }
    return false;
  }
  return true;
}

Boolean PathInternal::EndsWithPeriodOrSpace(String path) {
  if (String::in::IsNullOrEmpty(path)) {
    return false;
  }
  Char c = path[path->get_Length() - 1];
  if (c != u' ') {
    return c == u'.';
  }
  return true;
}

String PathInternal::EnsureExtendedPrefixIfNeeded(String path) {
  if (path != nullptr && (path->get_Length() >= 260 || EndsWithPeriodOrSpace(path))) {
    return EnsureExtendedPrefix(path);
  }
  return path;
}

String PathInternal::EnsureExtendedPrefix(String path) {
  if (IsPartiallyQualified(MemoryExtensions::AsSpan(path)) || IsDevice(MemoryExtensions::AsSpan(path))) {
    return path;
  }
  if (path->StartsWith("\\\\", StringComparison::OrdinalIgnoreCase)) {
    return path->Insert(2, "?\\UNC\\");
  }
  return "\\\\?\\" + path;
}

Boolean PathInternal::IsDevice(ReadOnlySpan<Char> path) {
  if (!IsExtended(path)) {
    if (path.get_Length() >= 4 && IsDirectorySeparator(path[0]) && IsDirectorySeparator(path[1]) && (path[2] == u'.' || path[2] == u'?')) {
      return IsDirectorySeparator(path[3]);
    }
    return false;
  }
  return true;
}

Boolean PathInternal::IsDeviceUNC(ReadOnlySpan<Char> path) {
  if (path.get_Length() >= 8 && IsDevice(path) && IsDirectorySeparator(path[7]) && path[4] == u'U' && path[5] == u'N') {
    return path[6] == u'C';
  }
  return false;
}

Boolean PathInternal::IsExtended(ReadOnlySpan<Char> path) {
  if (path.get_Length() >= 4 && path[0] == u'\\' && (path[1] == u'\\' || path[1] == u'?') && path[2] == u'?') {
    return path[3] == u'\\';
  }
  return false;
}

Int32 PathInternal::GetRootLength(ReadOnlySpan<Char> path) {
  Int32 length = path.get_Length();
  Int32 i = 0;
  Boolean flag = IsDevice(path);
  Boolean flag2 = flag && IsDeviceUNC(path);
  if ((!flag || flag2) && length > 0 && IsDirectorySeparator(path[0])) {
    if (flag2 || (length > 1 && IsDirectorySeparator(path[1]))) {
      i = (flag2 ? 8 : 2);
      Int32 num = 2;
      for (; i < length; i++) {
        if (IsDirectorySeparator(path[i]) && --num <= 0) {
          break;
        }
      }
    } else {
      i = 1;
    }
  } else if (flag) {
    for (i = 4; i < length && !IsDirectorySeparator(path[i]); i++) {
    }
    if (i < length && i > 4 && IsDirectorySeparator(path[i])) {
      i++;
    }
  } else if (length >= 2 && path[1] == u':' && IsValidDriveChar(path[0])) {
    i = 2;
    if (length > 2 && IsDirectorySeparator(path[2])) {
      i++;
    }
  }


  return i;
}

Boolean PathInternal::IsPartiallyQualified(ReadOnlySpan<Char> path) {
  if (path.get_Length() < 2) {
    return true;
  }
  if (IsDirectorySeparator(path[0])) {
    if (path[1] != u'?') {
      return !IsDirectorySeparator(path[1]);
    }
    return false;
  }
  if (path.get_Length() >= 3 && path[1] == u':' && IsDirectorySeparator(path[2])) {
    return !IsValidDriveChar(path[0]);
  }
  return true;
}

Boolean PathInternal::IsDirectorySeparator(Char c) {
  if (c != u'\\') {
    return c == u'/';
  }
  return true;
}

String PathInternal::NormalizeDirectorySeparators(String path) {
  if (String::in::IsNullOrEmpty(path)) {
    return path;
  }
  Boolean flag = true;
  for (Int32 i = 0; i < path->get_Length(); i++) {
    Char c = path[i];
    if (IsDirectorySeparator(c) && (c != u'\\' || (i > 0 && i + 1 < path->get_Length() && IsDirectorySeparator(path[i + 1])))) {
      flag = false;
      break;
    }
  }
  if (flag) {
    return path;
  }
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  Int32 num = 0;
  if (IsDirectorySeparator(path[num])) {
    num++;
    valueStringBuilder.Append(u'\\');
  }
  for (Int32 j = num; j < path->get_Length(); j++) {
    Char c = path[j];
    if (IsDirectorySeparator(c)) {
      if (j + 1 < path->get_Length() && IsDirectorySeparator(path[j + 1])) {
        continue;
      }
      c = u'\\';
    }
    valueStringBuilder.Append(c);
  }
  return valueStringBuilder.ToString();
}

Boolean PathInternal::IsEffectivelyEmpty(ReadOnlySpan<Char> path) {
  if (path.get_IsEmpty()) {
    return true;
  }
  ReadOnlySpan<Char> readOnlySpan = path;
  for (Char&& c : *readOnlySpan) {
    if (c != u' ') {
      return false;
    }
  }
  return true;
}

} // namespace System::Private::CoreLib::System::IO::PathInternalNamespace
