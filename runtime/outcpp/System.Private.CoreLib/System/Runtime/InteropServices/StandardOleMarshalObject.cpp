#include "StandardOleMarshalObject-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/StandardOleMarshalObject-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::StandardOleMarshalObjectNamespace {
void StandardOleMarshalObject___::ctor() {
}

IntPtr StandardOleMarshalObject___::GetStdMarshaler(Guid& riid, Int32 dwDestContext, Int32 mshlflags) {
  IntPtr iUnknownForObject = Marshal::GetIUnknownForObject((StandardOleMarshalObject)this);
  if (iUnknownForObject != IntPtr::Zero) {
    try {
      IntPtr ppMarshal = IntPtr::Zero;
      if (Interop::Ole32::CoGetStandardMarshal(riid, iUnknownForObject, dwDestContext, IntPtr::Zero, mshlflags, ppMarshal) == 0) {
        return ppMarshal;
      }
    } catch (...) {
    } finally: {
      Marshal::Release(iUnknownForObject);
    }
  }
  rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_StandardOleMarshalObjectGetMarshalerFailed(), riid));
}

Int32 StandardOleMarshalObject___::GetUnmarshalClassOfIMarshal(Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Guid& pCid) {
  pCid = CLSID_StdMarshal;
  return 0;
}

Int32 StandardOleMarshalObject___::GetMarshalSizeMaxOfIMarshal(Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Int32& pSize) {
  IntPtr stdMarshaler = GetStdMarshaler(riid, dwDestContext, mshlflags);
  try {
    IntPtr intPtr = *(IntPtr*)stdMarshaler.ToPointer();
    IntPtr ptr = *(IntPtr*)((Byte*)intPtr.ToPointer() + 4 * (Int64)sizeof(IntPtr));
    GetMarshalSizeMaxDelegate getMarshalSizeMaxDelegate = (GetMarshalSizeMaxDelegate)Marshal::GetDelegateForFunctionPointer(ptr, typeof<GetMarshalSizeMaxDelegate>());
    return getMarshalSizeMaxDelegate(stdMarshaler, riid, pv, dwDestContext, pvDestContext, mshlflags, pSize);
  } catch (...) {
  } finally: {
    Marshal::Release(stdMarshaler);
  }
}

Int32 StandardOleMarshalObject___::MarshalInterfaceOfIMarshal(IntPtr pStm, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags) {
  IntPtr stdMarshaler = GetStdMarshaler(riid, dwDestContext, mshlflags);
  try {
    IntPtr intPtr = *(IntPtr*)stdMarshaler.ToPointer();
    IntPtr ptr = *(IntPtr*)((Byte*)intPtr.ToPointer() + 5 * (Int64)sizeof(IntPtr));
    MarshalInterfaceDelegate marshalInterfaceDelegate = (MarshalInterfaceDelegate)Marshal::GetDelegateForFunctionPointer(ptr, typeof<MarshalInterfaceDelegate>());
    return marshalInterfaceDelegate(stdMarshaler, pStm, riid, pv, dwDestContext, pvDestContext, mshlflags);
  } catch (...) {
  } finally: {
    Marshal::Release(stdMarshaler);
  }
}

Int32 StandardOleMarshalObject___::UnmarshalInterfaceOfIMarshal(IntPtr pStm, Guid& riid, IntPtr& ppv) {
  ppv = IntPtr::Zero;
  return -2147467263;
}

Int32 StandardOleMarshalObject___::ReleaseMarshalDataOfIMarshal(IntPtr pStm) {
  return -2147467263;
}

Int32 StandardOleMarshalObject___::DisconnectObjectOfIMarshal(Int32 dwReserved) {
  return -2147467263;
}

void StandardOleMarshalObject___::cctor() {
  CLSID_StdMarshal = Guid("00000017-0000-0000-c000-000000000046");
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::StandardOleMarshalObjectNamespace
