#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Security/Permissions/SecurityAttribute.h>

namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction;
namespace CodeAccessSecurityAttributeNamespace {
CLASS(CodeAccessSecurityAttribute) : public SecurityAttribute::in {
  protected: void Ctor(SecurityAction action);
};
} // namespace CodeAccessSecurityAttributeNamespace
using CodeAccessSecurityAttribute = CodeAccessSecurityAttributeNamespace::CodeAccessSecurityAttribute;
} // namespace System::Private::CoreLib::System::Security::Permissions
