#pragma once

#include <System.Private.CoreLib/System/Security/Permissions/SecurityAttribute.h>

namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction : int32_t;
namespace CodeAccessSecurityAttributeNamespace {
CLASS(CodeAccessSecurityAttribute) : public SecurityAttribute::in {
  public: void ctor(SecurityAction action);
};
} // namespace CodeAccessSecurityAttributeNamespace
using CodeAccessSecurityAttribute = CodeAccessSecurityAttributeNamespace::CodeAccessSecurityAttribute;
} // namespace System::Private::CoreLib::System::Security::Permissions
