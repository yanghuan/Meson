#include "UTF8Marshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::UTF8MarshalerNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text;

IntPtr UTF8Marshaler::ConvertToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer) {
  if (strManaged == nullptr) {
    return IntPtr::Zero;
  }
  Byte* ptr = (Byte*)(void*)pNativeBuffer;
  Int32 cbNativeBuffer;
  if (ptr != nullptr) {
    cbNativeBuffer = (strManaged->get_Length() + 1) * 3;
    cbNativeBuffer = strManaged->GetBytesFromEncoding(ptr, cbNativeBuffer, Encoding::in::get_UTF8());
  } else {
    cbNativeBuffer = Encoding::in::get_UTF8()->GetByteCount(strManaged);
    ptr = (Byte*)(void*)Marshal::AllocCoTaskMem(cbNativeBuffer + 1);
    strManaged->GetBytesFromEncoding(ptr, cbNativeBuffer, Encoding::in::get_UTF8());
  }
  *(ptr + cbNativeBuffer) = 0;
  return (IntPtr)ptr;
}

String UTF8Marshaler::ConvertToManaged(IntPtr cstr) {
  if (IntPtr::Zero == cstr) {
    return nullptr;
  }
  Byte* ptr = (Byte*)(void*)cstr;
  Int32 byteLength = String::in::strlen(ptr);
  return String::in::CreateStringFromEncoding(ptr, byteLength, Encoding::in::get_UTF8());
}

void UTF8Marshaler::ClearNative(IntPtr pNative) {
  if (pNative != IntPtr::Zero) {
    Interop::Ole32::CoTaskMemFree(pNative);
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::UTF8MarshalerNamespace
