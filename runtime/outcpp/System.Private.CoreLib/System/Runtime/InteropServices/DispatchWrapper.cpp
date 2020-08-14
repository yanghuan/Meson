#include "DispatchWrapper-dep.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::DispatchWrapperNamespace {
void DispatchWrapper___::ctor(Object obj) {
  if (obj != nullptr) {
    IntPtr iDispatchForObject = Marshal::GetIDispatchForObject(obj);
    Marshal::Release(iDispatchForObject);
    WrappedObject = obj;
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::DispatchWrapperNamespace
