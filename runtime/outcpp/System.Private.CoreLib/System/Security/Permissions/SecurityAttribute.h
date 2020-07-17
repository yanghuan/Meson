#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(IPermission)
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction;
namespace SecurityAttributeNamespace {
CLASS(SecurityAttribute) {
  public: SecurityAction get_Action() { return Action; }
  public: void set_Action(SecurityAction value) { Action = value; }
  public: Boolean get_Unrestricted() { return Unrestricted; }
  public: void set_Unrestricted(Boolean value) { Unrestricted = value; }
  protected: void Ctor(SecurityAction action);
  public: IPermission CreatePermission();
  private: SecurityAction Action;
  private: Boolean Unrestricted;
};
} // namespace SecurityAttributeNamespace
using SecurityAttribute = SecurityAttributeNamespace::SecurityAttribute;
} // namespace System::Private::CoreLib::System::Security::Permissions
