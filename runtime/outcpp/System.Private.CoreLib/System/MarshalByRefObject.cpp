#include "MarshalByRefObject-dep.h"

#include <System.Private.CoreLib/System/MarshalByRefObject-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::MarshalByRefObjectNamespace {
void MarshalByRefObject___::ctor() {
}

Object MarshalByRefObject___::GetLifetimeService() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_Remoting());
}

Object MarshalByRefObject___::InitializeLifetimeService() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_Remoting());
}

MarshalByRefObject MarshalByRefObject___::MemberwiseClone(Boolean cloneIdentity) {
  return (MarshalByRefObject)MemberwiseClone();
}

} // namespace System::Private::CoreLib::System::MarshalByRefObjectNamespace
