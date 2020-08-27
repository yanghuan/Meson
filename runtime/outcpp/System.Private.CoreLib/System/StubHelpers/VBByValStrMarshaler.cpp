#include "VBByValStrMarshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/AnsiCharMarshaler-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::VBByValStrMarshalerNamespace {
using namespace System::Runtime::InteropServices;

IntPtr VBByValStrMarshaler::ConvertToNative(String strManaged, Boolean fBestFit, Boolean fThrowOnUnmappableChar, Int32& cch) {
  if (strManaged == nullptr) {
    return IntPtr::Zero;
  }
  cch = strManaged->get_Length();
  Int32 cb = 4 + (cch + 1) * Marshal::SystemMaxDBCSCharSize;
  Byte* ptr = (Byte*)(void*)Marshal::AllocCoTaskMem(cb);
  Int32* ptr2 = (Int32*)ptr;
  ptr += 4;
  if (cch == 0) {
    *ptr = 0;
    *ptr2 = 0;
  } else {
    Int32 cbLength;
    Array<Byte> array = AnsiCharMarshaler::DoAnsiConversion(strManaged, fBestFit, fThrowOnUnmappableChar, cbLength);
    {
      Byte* src = &array[0];
      Buffer::Memcpy(ptr, src, cbLength);
    }
    *(ptr + cbLength) = 0;
    *ptr2 = cbLength;
  }
  return IntPtr(ptr);
}

String VBByValStrMarshaler::ConvertToManaged(IntPtr pNative, Int32 cch) {
  if (IntPtr::Zero == pNative) {
    return nullptr;
  }
  return rt::newobj<String>((SByte*)(void*)pNative, 0, cch);
}

void VBByValStrMarshaler::ClearNative(IntPtr pNative) {
  if (IntPtr::Zero != pNative) {
    Interop::Ole32::CoTaskMemFree((IntPtr)((Int64)pNative - 4));
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::VBByValStrMarshalerNamespace
