#include "AnsiBSTRMarshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/AnsiCharMarshaler-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::AnsiBSTRMarshalerNamespace {
IntPtr AnsiBSTRMarshaler::ConvertToNative(Int32 flags, String strManaged) {
  if (strManaged == nullptr) {
    return IntPtr::Zero;
  }
  Array<Byte> str = nullptr;
  Int32 cbLength = 0;
  if (strManaged->get_Length() > 0) {
    str = AnsiCharMarshaler::DoAnsiConversion(strManaged, (flags & 255) != 0, flags >> 8 != 0, cbLength);
  }
  return Interop::OleAut32::SysAllocStringByteLen(str, (UInt32)cbLength);
}

String AnsiBSTRMarshaler::ConvertToManaged(IntPtr bstr) {
  if (IntPtr::Zero == bstr) {
    return nullptr;
  }
  return rt::newstr<String>((SByte*)(void*)bstr);
}

void AnsiBSTRMarshaler::ClearNative(IntPtr pNative) {
  if (IntPtr::Zero != pNative) {
    Interop::OleAut32::SysFreeString(pNative);
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::AnsiBSTRMarshalerNamespace
