#include "BSTRMarshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/StubHelpers-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::BSTRMarshalerNamespace {
using namespace System::Runtime::InteropServices;

IntPtr BSTRMarshaler::ConvertToNative(String strManaged, IntPtr pNativeBuffer) {
  if (strManaged == nullptr) {
    return IntPtr::Zero;
  }
  Byte data;
  Boolean flag = strManaged->TryGetTrailByte(data);
  UInt32 num = (UInt32)(strManaged->get_Length() * 2);
  if (flag) {
    num++;
  }
  Byte* ptr;
  if (pNativeBuffer != IntPtr::Zero) {
    *(UInt32*)(void*)pNativeBuffer = num;
    ptr = (Byte*)(void*)pNativeBuffer + 4;
  } else {
    ptr = (Byte*)(void*)Interop::OleAut32::SysAllocStringByteLen(nullptr, num);
    if (ptr == nullptr) {
      rt::throw_exception<OutOfMemoryException>();
    }
  }
  {
    Char* ptr2 = rt::fixed(strManaged);
    Char* src = ptr2;
    Buffer::Memcpy(ptr, (Byte*)src, (strManaged->get_Length() + 1) * 2);
  }
  if (flag) {
    *(ptr + num - 1) = data;
  }
  return (IntPtr)ptr;
}

String BSTRMarshaler::ConvertToManaged(IntPtr bstr) {
  if (IntPtr::Zero == bstr) {
    return nullptr;
  }
  UInt32 num = Marshal::SysStringByteLen(bstr);
  StubHelpers::CheckStringLength(num);
  String text = ((num != 1) ? rt::newstr<String>((Char*)(void*)bstr, 0, (Int32)(num / 2u)) : String::in::FastAllocateString(0));
  if ((num & 1) == 1) {
    text->SetTrailByte(((Byte*)(void*)bstr)[num - 1]);
  }
  return text;
}

void BSTRMarshaler::ClearNative(IntPtr pNative) {
  if (IntPtr::Zero != pNative) {
    Interop::OleAut32::SysFreeString(pNative);
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::BSTRMarshalerNamespace
