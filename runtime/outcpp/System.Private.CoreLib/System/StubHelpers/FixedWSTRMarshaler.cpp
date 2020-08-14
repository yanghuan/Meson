#include "FixedWSTRMarshaler-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::FixedWSTRMarshalerNamespace {
void FixedWSTRMarshaler::ConvertToNative(String strManaged, IntPtr nativeHome, Int32 length) {
  ReadOnlySpan<Char> readOnlySpan = strManaged;
  Span<Char> destination = Span<Char>((void*)nativeHome, length);
  Int32 num = Math::Min(readOnlySpan.get_Length(), length - 1);
  readOnlySpan.Slice(0, num).CopyTo(destination);
  destination[num] = 0;
}

} // namespace System::Private::CoreLib::System::StubHelpers::FixedWSTRMarshalerNamespace
