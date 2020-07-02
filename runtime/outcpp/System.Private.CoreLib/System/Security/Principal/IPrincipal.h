#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security::Principal {
FORWARD(IIdentity)
namespace IPrincipalNamespace {
CLASS(IPrincipal) {
  public: IIdentity get_Identity();
  public: Boolean IsInRole(String role);
};
} // namespace IPrincipalNamespace
using IPrincipal = IPrincipalNamespace::IPrincipal;
} // namespace System::Private::CoreLib::System::Security::Principal
