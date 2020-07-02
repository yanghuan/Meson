#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security::Principal {
namespace IIdentityNamespace {
CLASS(IIdentity) {
  public: String get_Name();
  public: String get_AuthenticationType();
  public: Boolean get_IsAuthenticated();
};
} // namespace IIdentityNamespace
using IIdentity = IIdentityNamespace::IIdentity;
} // namespace System::Private::CoreLib::System::Security::Principal
