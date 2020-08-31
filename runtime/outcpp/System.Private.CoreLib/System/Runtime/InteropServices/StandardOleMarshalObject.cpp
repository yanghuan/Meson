#include "StandardOleMarshalObject-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/StandardOleMarshalObject-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

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

void StandardOleMarshalObject___::cctor() {
  CLSID_StdMarshal = Guid("00000017-0000-0000-c000-000000000046");
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::StandardOleMarshalObjectNamespace
