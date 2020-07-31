#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security::Principal {
namespace IIdentityNamespace {
CLASS(IIdentity) : public Object::in {
  public: String get_Name();
  public: String get_AuthenticationType();
  public: Boolean get_IsAuthenticated();
};
} // namespace IIdentityNamespace
using IIdentity = IIdentityNamespace::IIdentity;
} // namespace System::Private::CoreLib::System::Security::Principal
