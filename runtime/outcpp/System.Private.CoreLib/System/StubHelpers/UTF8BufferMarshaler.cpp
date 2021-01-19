#include "UTF8BufferMarshaler-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::UTF8BufferMarshalerNamespace {
using namespace System::Text;

IntPtr UTF8BufferMarshaler::ConvertToNative(StringBuilder sb, IntPtr pNativeBuffer, Int32 flags) {
  if (sb == nullptr) {
    return IntPtr::Zero;
  }
  String text = sb->ToString();
  Int32 byteCount = Encoding::in::get_UTF8()->GetByteCount(text);
  Byte* ptr = (Byte*)(void*)pNativeBuffer;
  byteCount = text->GetBytesFromEncoding(ptr, byteCount, Encoding::in::get_UTF8());
  *(ptr + byteCount) = 0;
  return (IntPtr)ptr;
}

void UTF8BufferMarshaler::ConvertToManaged(StringBuilder sb, IntPtr pNative) {
  if (!(pNative == IntPtr::Zero)) {
    Byte* ptr = (Byte*)(void*)pNative;
    Int32 length = String::in::strlen(ptr);
    sb->ReplaceBufferUtf8Internal(ReadOnlySpan<Byte>(ptr, length));
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::UTF8BufferMarshalerNamespace
