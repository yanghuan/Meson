#include "PathHelper-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/PathInternal-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::PathHelperNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text;

String PathHelper::Normalize(String path) {
  Char default[260] = {};
  Span<Char> initialBuffer = default;
  ValueStringBuilder builder = ValueStringBuilder(initialBuffer);
  GetFullPathName(MemoryExtensions::AsSpan(path), builder);
  String result = (MemoryExtensions::IndexOf(builder.AsSpan(), 126) >= 0) ? TryExpandShortFileName(builder, path) : (MemoryExtensions::Equals(MemoryExtensions, builder.AsSpan(), MemoryExtensions::AsSpan(path), StringComparison::Ordinal) ? path : builder.ToString());
  builder.Dispose();
  return result;
}

String PathHelper::Normalize(ValueStringBuilder& path) {
  Char default[260] = {};
  Span<Char> initialBuffer = default;
  ValueStringBuilder builder = ValueStringBuilder(initialBuffer);
  GetFullPathName(path.AsSpan(true), builder);
  String result = (MemoryExtensions::IndexOf(builder.AsSpan(), 126) >= 0) ? TryExpandShortFileName(builder, nullptr) : builder.ToString();
  builder.Dispose();
  return result;
}

void PathHelper::GetFullPathName(ReadOnlySpan<Char> path, ValueStringBuilder& builder) {
  UInt32 fullPathNameW;
  while ((fullPathNameW = Interop::Kernel32::GetFullPathNameW(MemoryMarshal::GetReference(path), (UInt32)builder.get_Capacity(), builder.GetPinnableReference(), IntPtr::Zero)) > builder.get_Capacity()) {
    builder.EnsureCapacity((Int32)fullPathNameW);
  }
  if (fullPathNameW == 0) {
    Int32 num = Marshal::GetLastWin32Error();
    if (num == 0) {
      num = 161;
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(num, path.ToString()));
  }
  builder.set_Length((Int32)fullPathNameW);
}

Int32 PathHelper::PrependDevicePathChars(ValueStringBuilder& content, Boolean isDosUnc, ValueStringBuilder& buffer) {
  Int32 length = content.get_Length();
  length += (isDosUnc ? 6 : 4);
  buffer.EnsureCapacity(length + 1);
  buffer.set_Length(0);
  if (isDosUnc) {
    buffer.Append("\\?\UNC\");
    buffer.Append(content.AsSpan(2));
    return 6;
  }
  buffer.Append("\\?\");
  buffer.Append(content.AsSpan());
  return 4;
}

String PathHelper::TryExpandShortFileName(ValueStringBuilder& outputBuilder, String originalPath) {
  Int32 rootLength = PathInternal::GetRootLength(outputBuilder.AsSpan());
  Boolean flag = PathInternal::IsDevice(outputBuilder.AsSpan());
  ValueStringBuilder buffer = ValueStringBuilder();
  Boolean flag2 = false;
  Int32 num = 0;
  Boolean flag3 = false;
  if (flag) {
    buffer.Append(outputBuilder.AsSpan());
    if (outputBuilder[2] == 46) {
      flag3 = true;
      buffer[2] = 63;
    }
  } else {
    flag2 = (!PathInternal::IsDevice(outputBuilder.AsSpan()) && outputBuilder.get_Length() > 1 && outputBuilder[0] == 92 && outputBuilder[1] == 92);
    num = PrependDevicePathChars(outputBuilder, flag2, buffer);
  }
  rootLength += num;
  Int32 length = buffer.get_Length();
  Boolean flag4 = false;
  Int32 num2 = buffer.get_Length() - 1;
  while (!flag4) {
    UInt32 longPathNameW = Interop::Kernel32::GetLongPathNameW(buffer.GetPinnableReference(true), outputBuilder.GetPinnableReference(), (UInt32)outputBuilder.get_Capacity());
    if (buffer[num2] == 0) {
      buffer[num2] = 92;
    }
    if (longPathNameW == 0) {
      Int32 lastWin32Error = Marshal::GetLastWin32Error();
      if (lastWin32Error != 2 && lastWin32Error != 3) {
        break;
      }
      num2--;
      while (num2 > rootLength && buffer[num2] != 92) {
        num2--;
      }
      if (num2 == rootLength) {
        break;
      }
      buffer[num2] = 0;
    } else if (longPathNameW > outputBuilder.get_Capacity()) {
      outputBuilder.EnsureCapacity((Int32)longPathNameW);
    } else {
      flag4 = true;
      outputBuilder.set_Length((Int32)longPathNameW);
      if (num2 < length - 1) {
        outputBuilder.Append(buffer.AsSpan(num2, buffer.get_Length() - num2));
      }
    }

  }
  ValueStringBuilder& reference = flag4 ? outputBuilder : buffer;
  if (flag3) {
    reference[2] = 46;
  }
  if (flag2) {
    reference[6] = 92;
  }
  ReadOnlySpan<Char> span = reference.AsSpan(num);
  String result = (originalPath != nullptr && MemoryExtensions::Equals(MemoryExtensions, span, MemoryExtensions::AsSpan(originalPath), StringComparison::Ordinal)) ? originalPath : span.ToString();
  buffer.Dispose();
  return result;
}

} // namespace System::Private::CoreLib::System::IO::PathHelperNamespace
