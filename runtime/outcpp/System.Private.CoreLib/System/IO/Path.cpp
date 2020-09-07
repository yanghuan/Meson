#include "Path-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/IO/PathHelper-dep.h>
#include <System.Private.CoreLib/System/IO/PathInternal-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::PathNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text;

void Path::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void Path::__c___::ctor() {
}

void Path::__c___::_GetRandomFileName_b__16_0(Span<Char> span, IntPtr key) {
  Populate83FileNameFromRandomBytes((Byte*)(void*)key, 8, span);
}

void Path::__c___::_JoinInternal_b__37_0(Span<Char> destination, ValueTuple<IntPtr, Int32, IntPtr, Int32, Boolean> state) {
  Span<Char>((void*)state.Item1, state.Item2).CopyTo(destination);
  if (!state.Item5) {
    destination[state.Item2] = 92;
  }
  Span<Char>((void*)state.Item3, state.Item4).CopyTo(destination.Slice(state.Item2 + ((!state.Item5) ? 1 : 0)));
}

void Path::__c___::_JoinInternal_b__38_0(Span<Char> destination, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean> state) {
  Span<Char>((void*)state.Item1, state.Item2).CopyTo(destination);
  if (!state.Item7) {
    destination[state.Item2] = 92;
  }
  Span<Char>((void*)state.Item3, state.Item4).CopyTo(destination.Slice(state.Item2 + ((!state.Item7) ? 1 : 0)));
  if (!state.Rest.Item1) {
    destination[destination.get_Length() - state.Item6 - 1] = 92;
  }
  Span<Char>((void*)state.Item5, state.Item6).CopyTo(destination.Slice(destination.get_Length() - state.Item6));
}

void Path::__c___::_JoinInternal_b__39_0(Span<Char> destination, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean, Boolean> state) {
  Span<Char>((void*)state.Item1, state.Item2).CopyTo(destination);
  if (!state.Rest.Item2) {
    destination[state.Item2] = 92;
  }
  Span<Char>((void*)state.Item3, state.Item4).CopyTo(destination.Slice(state.Item2 + ((!state.Rest.Item2) ? 1 : 0)));
  if (!state.Rest.Item3) {
    destination[state.Item2 + state.Item4 + ((!state.Rest.Item2) ? 1 : 0)] = 92;
  }
  Span<Char>((void*)state.Item5, state.Item6).CopyTo(destination.Slice(state.Item2 + state.Item4 + ((!state.Rest.Item2) ? 1 : 0) + ((!state.Rest.Item3) ? 1 : 0)));
  if (!state.Rest.Item4) {
    destination[destination.get_Length() - state.Rest.Item1 - 1] = 92;
  }
  Span<Char>((void*)state.Item7, state.Rest.Item1).CopyTo(destination.Slice(destination.get_Length() - state.Rest.Item1));
}

ReadOnlySpan<Byte> Path::get_Base32Char() {
  return rt::newarr<Array<Byte>>(32);
}

StringComparison Path::get_StringComparison() {
  Boolean isCaseSensitive = get_IsCaseSensitive();
  return StringComparison::OrdinalIgnoreCase;
}

Boolean Path::get_IsCaseSensitive() {
  return false;
}

String Path::ChangeExtension(String path, String extension) {
  if (path == nullptr) {
    return nullptr;
  }
  Int32 num = path->get_Length();
  if (num == 0) {
    return String::in::Empty;
  }
  for (Int32 num2 = path->get_Length() - 1; num2 >= 0; num2--) {
    Char c = path[num2];
    if (c == 46) {
      num = num2;
      break;
    }
    if (PathInternal::IsDirectorySeparator(c)) {
      break;
    }
  }
  if (extension == nullptr) {
    return path->Substring(0, num);
  }
  ReadOnlySpan<Char> str = MemoryExtensions::AsSpan(path, 0, num);
  if (!extension->StartsWith(46)) {
    return String::in::Concat(str, ".", extension);
  }
  return String::in::Concat(str, extension);
}

String Path::GetDirectoryName(String path) {
  if (path == nullptr || PathInternal::IsEffectivelyEmpty(MemoryExtensions::AsSpan(path))) {
    return nullptr;
  }
  Int32 directoryNameOffset = GetDirectoryNameOffset(MemoryExtensions::AsSpan(path));
  if (directoryNameOffset < 0) {
    return nullptr;
  }
  return PathInternal::NormalizeDirectorySeparators(path->Substring(0, directoryNameOffset));
}

ReadOnlySpan<Char> Path::GetDirectoryName(ReadOnlySpan<Char> path) {
  if (PathInternal::IsEffectivelyEmpty(path)) {
    return ReadOnlySpan<Char>::get_Empty();
  }
  Int32 directoryNameOffset = GetDirectoryNameOffset(path);
  if (directoryNameOffset < 0) {
    return ReadOnlySpan<Char>::get_Empty();
  }
  return path.Slice(0, directoryNameOffset);
}

Int32 Path::GetDirectoryNameOffset(ReadOnlySpan<Char> path) {
  Int32 rootLength = PathInternal::GetRootLength(path);
  Int32 num = path.get_Length();
  if (num <= rootLength) {
    return -1;
  }
  while (num > rootLength && !PathInternal::IsDirectorySeparator(path[--num])) {
  }
  while (num > rootLength && PathInternal::IsDirectorySeparator(path[num - 1])) {
    num--;
  }
  return num;
}

String Path::GetExtension(String path) {
  if (path == nullptr) {
    return nullptr;
  }
  return GetExtension(MemoryExtensions::AsSpan(path)).ToString();
}

ReadOnlySpan<Char> Path::GetExtension(ReadOnlySpan<Char> path) {
  Int32 length = path.get_Length();
  for (Int32 num = length - 1; num >= 0; num--) {
    Char c = path[num];
    if (c == 46) {
      if (num != length - 1) {
        return path.Slice(num, length - num);
      }
      return ReadOnlySpan<Char>::get_Empty();
    }
    if (PathInternal::IsDirectorySeparator(c)) {
      break;
    }
  }
  return ReadOnlySpan<Char>::get_Empty();
}

String Path::GetFileName(String path) {
  if (path == nullptr) {
    return nullptr;
  }
  ReadOnlySpan<Char> fileName = GetFileName(MemoryExtensions::AsSpan(path));
  if (path->get_Length() == fileName.get_Length()) {
    return path;
  }
  return fileName.ToString();
}

ReadOnlySpan<Char> Path::GetFileName(ReadOnlySpan<Char> path) {
  Int32 length = GetPathRoot(path).get_Length();
  Int32 num = path.get_Length();
  while (--num >= 0) {
    if (num < length || PathInternal::IsDirectorySeparator(path[num])) {
      return path.Slice(num + 1, path.get_Length() - num - 1);
    }
  }
  return path;
}

String Path::GetFileNameWithoutExtension(String path) {
  if (path == nullptr) {
    return nullptr;
  }
  ReadOnlySpan<Char> fileNameWithoutExtension = GetFileNameWithoutExtension(MemoryExtensions::AsSpan(path));
  if (path->get_Length() == fileNameWithoutExtension.get_Length()) {
    return path;
  }
  return fileNameWithoutExtension.ToString();
}

ReadOnlySpan<Char> Path::GetFileNameWithoutExtension(ReadOnlySpan<Char> path) {
  ReadOnlySpan<Char> fileName = GetFileName(path);
  Int32 num = MemoryExtensions::LastIndexOf(fileName, 46);
  if (num != -1) {
    return fileName.Slice(0, num);
  }
  return fileName;
}

String Path::GetRandomFileName() {
  Byte as[8] = {};
  Byte* ptr = as;
  Interop::GetRandomBytes(ptr, 8);
  SpanAction<Char, IntPtr> is = __c::in::__9__16_0;
  return String::in::Create(12, (IntPtr)(void*)ptr, is != nullptr ? is : (__c::in::__9__16_0 = {__c::in::__9, &__c::in::_GetRandomFileName_b__16_0}));
}

Boolean Path::IsPathFullyQualified(String path) {
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path");
  }
  return IsPathFullyQualified(MemoryExtensions::AsSpan(path));
}

Boolean Path::IsPathFullyQualified(ReadOnlySpan<Char> path) {
  return !PathInternal::IsPartiallyQualified(path);
}

Boolean Path::HasExtension(String path) {
  if (path != nullptr) {
    return HasExtension(MemoryExtensions::AsSpan(path));
  }
  return false;
}

Boolean Path::HasExtension(ReadOnlySpan<Char> path) {
  for (Int32 num = path.get_Length() - 1; num >= 0; num--) {
    Char c = path[num];
    if (c == 46) {
      return num != path.get_Length() - 1;
    }
    if (PathInternal::IsDirectorySeparator(c)) {
      break;
    }
  }
  return false;
}

String Path::Combine(String path1, String path2) {
  if (path1 == nullptr || path2 == nullptr) {
    rt::throw_exception<ArgumentNullException>((path1 == nullptr) ? "path1" : "path2");
  }
  return CombineInternal(path1, path2);
}

String Path::Combine(String path1, String path2, String path3) {
  if (path1 == nullptr || path2 == nullptr || path3 == nullptr) {
    rt::throw_exception<ArgumentNullException>((path1 == nullptr) ? "path1" : ((path2 == nullptr) ? "path2" : "path3"));
  }
  return CombineInternal(path1, path2, path3);
}

String Path::Combine(String path1, String path2, String path3, String path4) {
  if (path1 == nullptr || path2 == nullptr || path3 == nullptr || path4 == nullptr) {
    rt::throw_exception<ArgumentNullException>((path1 == nullptr) ? "path1" : ((path2 == nullptr) ? "path2" : ((path3 == nullptr) ? "path3" : "path4")));
  }
  return CombineInternal(path1, path2, path3, path4);
}

String Path::Combine(Array<String> paths) {
  if (paths == nullptr) {
    rt::throw_exception<ArgumentNullException>("paths");
  }
  Int32 num = 0;
  Int32 num2 = 0;
  for (Int32 i = 0; i < paths->get_Length(); i++) {
    if (paths[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("paths");
    }
    if (paths[i]->get_Length() != 0) {
      if (IsPathRooted(paths[i])) {
        num2 = i;
        num = paths[i]->get_Length();
      } else {
        num += paths[i]->get_Length();
      }
      Char c = paths[i][paths[i]->get_Length() - 1];
      if (!PathInternal::IsDirectorySeparator(c)) {
        num++;
      }
    }
  }
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  valueStringBuilder.EnsureCapacity(num);
  for (Int32 j = num2; j < paths->get_Length(); j++) {
    if (paths[j]->get_Length() == 0) {
      continue;
    }
    if (valueStringBuilder.get_Length() == 0) {
      valueStringBuilder.Append(paths[j]);
      continue;
    }
    Char c2 = valueStringBuilder[valueStringBuilder.get_Length() - 1];
    if (!PathInternal::IsDirectorySeparator(c2)) {
      valueStringBuilder.Append(92);
    }
    valueStringBuilder.Append(paths[j]);
  }
  return valueStringBuilder.ToString();
}

String Path::Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2) {
  if (path1.get_Length() == 0) {
    return path2.ToString();
  }
  if (path2.get_Length() == 0) {
    return path1.ToString();
  }
  return JoinInternal(path1, path2);
}

String Path::Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3) {
  if (path1.get_Length() == 0) {
    return Join(path2, path3);
  }
  if (path2.get_Length() == 0) {
    return Join(path1, path3);
  }
  if (path3.get_Length() == 0) {
    return Join(path1, path2);
  }
  return JoinInternal(path1, path2, path3);
}

String Path::Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3, ReadOnlySpan<Char> path4) {
  if (path1.get_Length() == 0) {
    return Join(path2, path3, path4);
  }
  if (path2.get_Length() == 0) {
    return Join(path1, path3, path4);
  }
  if (path3.get_Length() == 0) {
    return Join(path1, path2, path4);
  }
  if (path4.get_Length() == 0) {
    return Join(path1, path2, path3);
  }
  return JoinInternal(path1, path2, path3, path4);
}

String Path::Join(String path1, String path2) {
  return Join(MemoryExtensions::AsSpan(path1), MemoryExtensions::AsSpan(path2));
}

String Path::Join(String path1, String path2, String path3) {
  return Join(MemoryExtensions::AsSpan(path1), MemoryExtensions::AsSpan(path2), MemoryExtensions::AsSpan(path3));
}

String Path::Join(String path1, String path2, String path3, String path4) {
  return Join(MemoryExtensions::AsSpan(path1), MemoryExtensions::AsSpan(path2), MemoryExtensions::AsSpan(path3), MemoryExtensions::AsSpan(path4));
}

String Path::Join(Array<String> paths) {
  if (paths == nullptr) {
    rt::throw_exception<ArgumentNullException>("paths");
  }
  if (paths->get_Length() == 0) {
    return String::in::Empty;
  }
  Int32 num = 0;
  for (String&& text : *paths) {
    num += ((text != nullptr) ? text->get_Length() : 0);
  }
  num += paths->get_Length() - 1;
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  valueStringBuilder.EnsureCapacity(num);
  for (String&& text2 : *paths) {
    if (String::in::IsNullOrEmpty(text2)) {
      continue;
    }
    if (valueStringBuilder.get_Length() == 0) {
      valueStringBuilder.Append(text2);
      continue;
    }
    if (!PathInternal::IsDirectorySeparator(valueStringBuilder[valueStringBuilder.get_Length() - 1]) && !PathInternal::IsDirectorySeparator(text2[0])) {
      valueStringBuilder.Append(92);
    }
    valueStringBuilder.Append(text2);
  }
  return valueStringBuilder.ToString();
}

Boolean Path::TryJoin(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, Span<Char> destination, Int32& charsWritten) {
  charsWritten = 0;
  if (path1.get_Length() == 0 && path2.get_Length() == 0) {
    return true;
  }
  if (path1.get_Length() == 0 || path2.get_Length() == 0) {
    ReadOnlySpan<Char>& reference = path1.get_Length() == 0 ? path2 : path1;
    if (destination.get_Length() < reference.get_Length()) {
      return false;
    }
    reference.CopyTo(destination);
    charsWritten = reference.get_Length();
    return true;
  }
  Boolean flag = !EndsInDirectorySeparator(path1) && !PathInternal::StartsWithDirectorySeparator(path2);
  Int32 num = path1.get_Length() + path2.get_Length() + (flag ? 1 : 0);
  if (destination.get_Length() < num) {
    return false;
  }
  path1.CopyTo(destination);
  if (flag) {
    destination[path1.get_Length()] = DirectorySeparatorChar;
  }
  path2.CopyTo(destination.Slice(path1.get_Length() + (flag ? 1 : 0)));
  charsWritten = num;
  return true;
}

Boolean Path::TryJoin(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3, Span<Char> destination, Int32& charsWritten) {
  charsWritten = 0;
  if (path1.get_Length() == 0 && path2.get_Length() == 0 && path3.get_Length() == 0) {
    return true;
  }
  if (path1.get_Length() == 0) {
    return TryJoin(path2, path3, destination, charsWritten);
  }
  if (path2.get_Length() == 0) {
    return TryJoin(path1, path3, destination, charsWritten);
  }
  if (path3.get_Length() == 0) {
    return TryJoin(path1, path2, destination, charsWritten);
  }
  Int32 num = (!EndsInDirectorySeparator(path1) && !PathInternal::StartsWithDirectorySeparator(path2)) ? 1 : 0;
  Boolean flag = !EndsInDirectorySeparator(path2) && !PathInternal::StartsWithDirectorySeparator(path3);
  if (flag) {
    num++;
  }
  Int32 num2 = path1.get_Length() + path2.get_Length() + path3.get_Length() + num;
  if (destination.get_Length() < num2) {
    return false;
  }
  Boolean flag2 = TryJoin(path1, path2, destination, charsWritten);
  if (flag) {
    destination[charsWritten++] = DirectorySeparatorChar;
  }
  path3.CopyTo(destination.Slice(charsWritten));
  charsWritten += path3.get_Length();
  return true;
}

String Path::CombineInternal(String first, String second) {
  if (String::in::IsNullOrEmpty(first)) {
    return second;
  }
  if (String::in::IsNullOrEmpty(second)) {
    return first;
  }
  if (IsPathRooted(MemoryExtensions::AsSpan(second))) {
    return second;
  }
  return JoinInternal(MemoryExtensions::AsSpan(first), MemoryExtensions::AsSpan(second));
}

String Path::CombineInternal(String first, String second, String third) {
  if (String::in::IsNullOrEmpty(first)) {
    return CombineInternal(second, third);
  }
  if (String::in::IsNullOrEmpty(second)) {
    return CombineInternal(first, third);
  }
  if (String::in::IsNullOrEmpty(third)) {
    return CombineInternal(first, second);
  }
  if (IsPathRooted(MemoryExtensions::AsSpan(third))) {
    return third;
  }
  if (IsPathRooted(MemoryExtensions::AsSpan(second))) {
    return CombineInternal(second, third);
  }
  return JoinInternal(MemoryExtensions::AsSpan(first), MemoryExtensions::AsSpan(second), MemoryExtensions::AsSpan(third));
}

String Path::CombineInternal(String first, String second, String third, String fourth) {
  if (String::in::IsNullOrEmpty(first)) {
    return CombineInternal(second, third, fourth);
  }
  if (String::in::IsNullOrEmpty(second)) {
    return CombineInternal(first, third, fourth);
  }
  if (String::in::IsNullOrEmpty(third)) {
    return CombineInternal(first, second, fourth);
  }
  if (String::in::IsNullOrEmpty(fourth)) {
    return CombineInternal(first, second, third);
  }
  if (IsPathRooted(MemoryExtensions::AsSpan(fourth))) {
    return fourth;
  }
  if (IsPathRooted(MemoryExtensions::AsSpan(third))) {
    return CombineInternal(third, fourth);
  }
  if (IsPathRooted(MemoryExtensions::AsSpan(second))) {
    return CombineInternal(second, third, fourth);
  }
  return JoinInternal(MemoryExtensions::AsSpan(first), MemoryExtensions::AsSpan(second), MemoryExtensions::AsSpan(third), MemoryExtensions::AsSpan(fourth));
}

String Path::JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second) {
  Boolean flag = PathInternal::IsDirectorySeparator(first[first.get_Length() - 1]) || PathInternal::IsDirectorySeparator(second[0]);
  {
    Char* value = &MemoryMarshal::GetReference(first);
    {
      Char* value2 = &MemoryMarshal::GetReference(second);
      SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, Boolean>> as = __c::in::__9__37_0;
      return String::in::Create(first.get_Length() + second.get_Length() + ((!flag) ? 1 : 0), {(IntPtr)(void*)value, first.get_Length(), (IntPtr)(void*)value2, second.get_Length(), flag}, as != nullptr ? as : (__c::in::__9__37_0 = rt::newobj<SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, Boolean>>>(&_JoinInternal_b__37_0)));
    }
  }
}

String Path::JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second, ReadOnlySpan<Char> third) {
  Boolean flag = PathInternal::IsDirectorySeparator(first[first.get_Length() - 1]) || PathInternal::IsDirectorySeparator(second[0]);
  Boolean flag2 = PathInternal::IsDirectorySeparator(second[second.get_Length() - 1]) || PathInternal::IsDirectorySeparator(third[0]);
  {
    Char* value = &MemoryMarshal::GetReference(first);
    {
      Char* value2 = &MemoryMarshal::GetReference(second);
      {
        Char* value3 = &MemoryMarshal::GetReference(third);
        SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean>> as = __c::in::__9__38_0;
        return String::in::Create(first.get_Length() + second.get_Length() + third.get_Length() + ((!flag) ? 1 : 0) + ((!flag2) ? 1 : 0), {(IntPtr)(void*)value, first.get_Length(), (IntPtr)(void*)value2, second.get_Length(), (IntPtr)(void*)value3, third.get_Length(), flag, flag2}, as != nullptr ? as : (__c::in::__9__38_0 = rt::newobj<SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean>>>(&_JoinInternal_b__38_0)));
      }
    }
  }
}

String Path::JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second, ReadOnlySpan<Char> third, ReadOnlySpan<Char> fourth) {
  Boolean flag = PathInternal::IsDirectorySeparator(first[first.get_Length() - 1]) || PathInternal::IsDirectorySeparator(second[0]);
  Boolean flag2 = PathInternal::IsDirectorySeparator(second[second.get_Length() - 1]) || PathInternal::IsDirectorySeparator(third[0]);
  Boolean flag3 = PathInternal::IsDirectorySeparator(third[third.get_Length() - 1]) || PathInternal::IsDirectorySeparator(fourth[0]);
  {
    Char* value = &MemoryMarshal::GetReference(first);
    {
      Char* value2 = &MemoryMarshal::GetReference(second);
      {
        Char* value3 = &MemoryMarshal::GetReference(third);
        {
          Char* value4 = &MemoryMarshal::GetReference(fourth);
          SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean, Boolean>> as = __c::in::__9__39_0;
          return String::in::Create(first.get_Length() + second.get_Length() + third.get_Length() + fourth.get_Length() + ((!flag) ? 1 : 0) + ((!flag2) ? 1 : 0) + ((!flag3) ? 1 : 0), {(IntPtr)(void*)value, first.get_Length(), (IntPtr)(void*)value2, second.get_Length(), (IntPtr)(void*)value3, third.get_Length(), (IntPtr)(void*)value4, fourth.get_Length(), flag, flag2, flag3}, as != nullptr ? as : (__c::in::__9__39_0 = rt::newobj<SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean, Boolean>>>(&_JoinInternal_b__39_0)));
        }
      }
    }
  }
}

void Path::Populate83FileNameFromRandomBytes(Byte* bytes, Int32 byteCount, Span<Char> chars) {
  Byte b = *bytes;
  Byte b2 = bytes[1];
  Byte b3 = bytes[2];
  Byte b4 = bytes[3];
  Byte b5 = bytes[4];
  chars[11] = (Char)get_Base32Char()[bytes[7] & 31];
  chars[0] = (Char)get_Base32Char()[b & 31];
  chars[1] = (Char)get_Base32Char()[b2 & 31];
  chars[2] = (Char)get_Base32Char()[b3 & 31];
  chars[3] = (Char)get_Base32Char()[b4 & 31];
  chars[4] = (Char)get_Base32Char()[b5 & 31];
  chars[5] = (Char)get_Base32Char()[((b & 224) >> 5) | ((b4 & 96) >> 2)];
  chars[6] = (Char)get_Base32Char()[((b2 & 224) >> 5) | ((b5 & 96) >> 2)];
  b3 = (Byte)(b3 >> 5);
  if ((b4 & 128) != 0) {
    b3 = (Byte)(b3 | 8);
  }
  if ((b5 & 128) != 0) {
    b3 = (Byte)(b3 | 16);
  }
  chars[7] = (Char)get_Base32Char()[b3];
  chars[8] = 46;
  chars[9] = (Char)get_Base32Char()[bytes[5] & 31];
  chars[10] = (Char)get_Base32Char()[bytes[6] & 31];
}

String Path::GetRelativePath(String relativeTo, String path) {
  return GetRelativePath(relativeTo, path, get_StringComparison());
}

String Path::GetRelativePath(String relativeTo, String path, StringComparison comparisonType) {
  if (relativeTo == nullptr) {
    rt::throw_exception<ArgumentNullException>("relativeTo");
  }
  if (PathInternal::IsEffectivelyEmpty(MemoryExtensions::AsSpan(relativeTo))) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_PathEmpty(), "relativeTo");
  }
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path");
  }
  if (PathInternal::IsEffectivelyEmpty(MemoryExtensions::AsSpan(path))) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_PathEmpty(), "path");
  }
  relativeTo = GetFullPath(relativeTo);
  path = GetFullPath(path);
  if (!PathInternal::AreRootsEqual(relativeTo, path, comparisonType)) {
    return path;
  }
  Int32 num = PathInternal::GetCommonPathLength(relativeTo, path, comparisonType == StringComparison::OrdinalIgnoreCase);
  if (num == 0) {
    return path;
  }
  Int32 num2 = relativeTo->get_Length();
  if (EndsInDirectorySeparator(MemoryExtensions::AsSpan(relativeTo))) {
    num2--;
  }
  Boolean flag = EndsInDirectorySeparator(MemoryExtensions::AsSpan(path));
  Int32 num3 = path->get_Length();
  if (flag) {
    num3--;
  }
  if (num2 == num3 && num >= num2) {
    return ".";
  }
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  valueStringBuilder.EnsureCapacity(Math::Max(relativeTo->get_Length(), path->get_Length()));
  if (num < num2) {
    valueStringBuilder.Append("..");
    for (Int32 i = num + 1; i < num2; i++) {
      if (PathInternal::IsDirectorySeparator(relativeTo[i])) {
        valueStringBuilder.Append(DirectorySeparatorChar);
        valueStringBuilder.Append("..");
      }
    }
  } else if (PathInternal::IsDirectorySeparator(path[num])) {
    num++;
  }

  Int32 num4 = num3 - num;
  if (flag) {
    num4++;
  }
  if (num4 > 0) {
    if (valueStringBuilder.get_Length() > 0) {
      valueStringBuilder.Append(DirectorySeparatorChar);
    }
    valueStringBuilder.Append(MemoryExtensions::AsSpan(path, num, num4));
  }
  return valueStringBuilder.ToString();
}

String Path::TrimEndingDirectorySeparator(String path) {
  return PathInternal::TrimEndingDirectorySeparator(path);
}

ReadOnlySpan<Char> Path::TrimEndingDirectorySeparator(ReadOnlySpan<Char> path) {
  return PathInternal::TrimEndingDirectorySeparator(path);
}

Boolean Path::EndsInDirectorySeparator(ReadOnlySpan<Char> path) {
  return PathInternal::EndsInDirectorySeparator(path);
}

Boolean Path::EndsInDirectorySeparator(String path) {
  return PathInternal::EndsInDirectorySeparator(path);
}

Array<Char> Path::GetInvalidFileNameChars() {
  return rt::newarr<Array<Char>>(41);
}

Array<Char> Path::GetInvalidPathChars() {
  return rt::newarr<Array<Char>>(33);
}

String Path::GetFullPath(String path) {
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path");
  }
  if (PathInternal::IsEffectivelyEmpty(MemoryExtensions::AsSpan(path))) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_PathEmpty(), "path");
  }
  if (path->Contains(0)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidPathChars(), "path");
  }
  if (PathInternal::IsExtended(MemoryExtensions::AsSpan(path))) {
    return path;
  }
  return PathHelper::Normalize(path);
}

String Path::GetFullPath(String path, String basePath) {
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path");
  }
  if (basePath == nullptr) {
    rt::throw_exception<ArgumentNullException>("basePath");
  }
  if (!IsPathFullyQualified(basePath)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_BasePathNotFullyQualified(), "basePath");
  }
  if (basePath->Contains(0) || path->Contains(0)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidPathChars());
  }
  if (IsPathFullyQualified(path)) {
    return GetFullPath(path);
  }
  if (PathInternal::IsEffectivelyEmpty(MemoryExtensions::AsSpan(path))) {
    return basePath;
  }
  Int32 length = path->get_Length();
  String text = (length >= 1 && PathInternal::IsDirectorySeparator(path[0])) ? Join(GetPathRoot(MemoryExtensions::AsSpan(basePath)), MemoryExtensions::AsSpan(path, 1)) : ((length < 2 || !PathInternal::IsValidDriveChar(path[0]) || path[1] != 58) ? JoinInternal(MemoryExtensions::AsSpan(basePath), MemoryExtensions::AsSpan(path)) : ((!MemoryExtensions::EqualsOrdinal(GetVolumeName(MemoryExtensions::AsSpan(path)), GetVolumeName(MemoryExtensions::AsSpan(basePath)))) ? ((!PathInternal::IsDevice(MemoryExtensions::AsSpan(basePath))) ? path->Insert(2, "\\") : ((length == 2) ? JoinInternal(MemoryExtensions::AsSpan(basePath, 0, 4), MemoryExtensions::AsSpan(path), MemoryExtensions::AsSpan("\\")) : JoinInternal(MemoryExtensions::AsSpan(basePath, 0, 4), MemoryExtensions::AsSpan(path, 0, 2), MemoryExtensions::AsSpan("\\"), MemoryExtensions::AsSpan(path, 2)))) : Join(MemoryExtensions::AsSpan(basePath), MemoryExtensions::AsSpan(path, 2))));
  if (!PathInternal::IsDevice(MemoryExtensions::AsSpan(text))) {
    return GetFullPath(text);
  }
  return PathInternal::RemoveRelativeSegments(text, PathInternal::GetRootLength(MemoryExtensions::AsSpan(text)));
}

String Path::GetTempPath() {
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder builder = ValueStringBuilder(initialBuffer);
  GetTempPath(builder);
  String result = PathHelper::Normalize(builder);
  builder.Dispose();
  return result;
}

void Path::GetTempPath(ValueStringBuilder& builder) {
  UInt32 tempPathW;
  while ((tempPathW = Interop::Kernel32::GetTempPathW(builder.get_Capacity(), builder.GetPinnableReference())) > builder.get_Capacity()) {
    builder.EnsureCapacity((Int32)tempPathW);
  }
  if (tempPathW == 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  builder.set_Length((Int32)tempPathW);
}

String Path::GetTempFileName() {
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder builder = ValueStringBuilder(initialBuffer);
  GetTempPath(builder);
  Char is[260] = {};
  initialBuffer = is;
  ValueStringBuilder path = ValueStringBuilder(initialBuffer);
  UInt32 tempFileNameW = Interop::Kernel32::GetTempFileNameW(builder.GetPinnableReference(), "tmp", 0u, path.GetPinnableReference());
  builder.Dispose();
  if (tempFileNameW == 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  path.set_Length(MemoryExtensions::IndexOf(path.get_RawChars(), 0));
  String result = PathHelper::Normalize(path);
  path.Dispose();
  return result;
}

Boolean Path::IsPathRooted(String path) {
  if (path != nullptr) {
    return IsPathRooted(MemoryExtensions::AsSpan(path));
  }
  return false;
}

Boolean Path::IsPathRooted(ReadOnlySpan<Char> path) {
  Int32 length = path.get_Length();
  if (length < 1 || !PathInternal::IsDirectorySeparator(path[0])) {
    if (length >= 2 && PathInternal::IsValidDriveChar(path[0])) {
      return path[1] == 58;
    }
    return false;
  }
  return true;
}

String Path::GetPathRoot(String path) {
  if (PathInternal::IsEffectivelyEmpty(MemoryExtensions::AsSpan(path))) {
    return nullptr;
  }
  ReadOnlySpan<Char> pathRoot = GetPathRoot(MemoryExtensions::AsSpan(path));
  if (path->get_Length() == pathRoot.get_Length()) {
    return PathInternal::NormalizeDirectorySeparators(path);
  }
  return PathInternal::NormalizeDirectorySeparators(pathRoot.ToString());
}

ReadOnlySpan<Char> Path::GetPathRoot(ReadOnlySpan<Char> path) {
  if (PathInternal::IsEffectivelyEmpty(path)) {
    return ReadOnlySpan<Char>::get_Empty();
  }
  Int32 rootLength = PathInternal::GetRootLength(path);
  if (rootLength > 0) {
    return path.Slice(0, rootLength);
  }
  return ReadOnlySpan<Char>::get_Empty();
}

ReadOnlySpan<Char> Path::GetVolumeName(ReadOnlySpan<Char> path) {
  ReadOnlySpan<Char> pathRoot = GetPathRoot(path);
  if (pathRoot.get_Length() == 0) {
    return pathRoot;
  }
  Int32 num = GetUncRootLength(path);
  if (num == -1) {
    num = (PathInternal::IsDevice(path) ? 4 : 0);
  }
  ReadOnlySpan<Char> readOnlySpan = pathRoot.Slice(num);
  if (!EndsInDirectorySeparator(readOnlySpan)) {
    return readOnlySpan;
  }
  return readOnlySpan.Slice(0, readOnlySpan.get_Length() - 1);
}

Int32 Path::GetUncRootLength(ReadOnlySpan<Char> path) {
  Boolean flag = PathInternal::IsDevice(path);
  if (!flag && MemoryExtensions::EqualsOrdinal(path.Slice(0, 2), MemoryExtensions::AsSpan("\\\\"))) {
    return 2;
  }
  if (flag && path.get_Length() >= 8 && (MemoryExtensions::EqualsOrdinal(path.Slice(0, 8), MemoryExtensions::AsSpan("\\\\?\\UNC\\")) || MemoryExtensions::EqualsOrdinal(path.Slice(5, 4), MemoryExtensions::AsSpan("UNC\\")))) {
    return 8;
  }
  return -1;
}

void Path::cctor() {
  DirectorySeparatorChar = 92;
  AltDirectorySeparatorChar = 47;
  VolumeSeparatorChar = 58;
  PathSeparator = 59;
  InvalidPathChars = GetInvalidPathChars();
}

} // namespace System::Private::CoreLib::System::IO::PathNamespace
