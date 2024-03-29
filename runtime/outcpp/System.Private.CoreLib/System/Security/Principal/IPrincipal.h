#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security::Principal {
FORWARD(IIdentity)
namespace IPrincipalNamespace {
CLASS(IPrincipal) : public object {
  public: IIdentity get_Identity();
  public: Boolean IsInRole(String role);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IPrincipalNamespace
using IPrincipal = IPrincipalNamespace::IPrincipal;
} // namespace System::Private::CoreLib::System::Security::Principal
