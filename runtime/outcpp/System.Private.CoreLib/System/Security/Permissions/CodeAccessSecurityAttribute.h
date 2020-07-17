#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction;
namespace CodeAccessSecurityAttributeNamespace {
CLASS(CodeAccessSecurityAttribute) {
  protected: void Ctor(SecurityAction action);
};
} // namespace CodeAccessSecurityAttributeNamespace
using CodeAccessSecurityAttribute = CodeAccessSecurityAttributeNamespace::CodeAccessSecurityAttribute;
} // namespace System::Private::CoreLib::System::Security::Permissions
