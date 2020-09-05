#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(IPermission)
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction : int32_t;
namespace SecurityAttributeNamespace {
CLASS(SecurityAttribute) : public Attribute::in {
  public: SecurityAction get_Action() { return Action; }
  public: void set_Action(SecurityAction value) { Action = value; }
  public: Boolean get_Unrestricted() { return Unrestricted; }
  public: void set_Unrestricted(Boolean value) { Unrestricted = value; }
  public: void ctor(SecurityAction action);
  public: IPermission CreatePermission();
  private: SecurityAction Action;
  private: Boolean Unrestricted;
};
} // namespace SecurityAttributeNamespace
using SecurityAttribute = SecurityAttributeNamespace::SecurityAttribute;
} // namespace System::Private::CoreLib::System::Security::Permissions
