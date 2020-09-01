#include "ComActivationContext-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/ComActivationContext-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivationContextNamespace {
using namespace System;
using namespace System::Runtime::InteropServices;

ComActivationContext ComActivationContext::Create(ComActivationContextInternal& cxtInt) {
  ComActivationContext result;
  result.ClassId = cxtInt.ClassId;
  result.InterfaceId = cxtInt.InterfaceId;
  result.AssemblyPath = Marshal::PtrToStringUni(IntPtr(cxtInt.AssemblyPathBuffer));
  result.AssemblyName = Marshal::PtrToStringUni(IntPtr(cxtInt.AssemblyNameBuffer));
  result.TypeName = Marshal::PtrToStringUni(IntPtr(cxtInt.TypeNameBuffer));
  return result;
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivationContextNamespace
