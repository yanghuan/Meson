#include "FixedWSTRMarshaler-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::FixedWSTRMarshalerNamespace {
void FixedWSTRMarshaler::ConvertToNative(String strManaged, IntPtr nativeHome, Int32 length) {
  ReadOnlySpan<Char> readOnlySpan = strManaged;
  Span<Char> destination = Span<Char>((void*)nativeHome, length);
  Int32 num = Math::Min(readOnlySpan.get_Length(), length - 1);
  readOnlySpan.Slice(0, num).CopyTo(destination);
  destination[num] = u'\0';
}

String FixedWSTRMarshaler::ConvertToManaged(IntPtr nativeHome, Int32 length) {
  Int32 num = SpanHelpers::IndexOf(*(Char*)(void*)nativeHome, u'\0', length);
  if (num != -1) {
    length = num;
  }
  return rt::newstr<String>((Char*)(void*)nativeHome, 0, length);
}

} // namespace System::Private::CoreLib::System::StubHelpers::FixedWSTRMarshalerNamespace
