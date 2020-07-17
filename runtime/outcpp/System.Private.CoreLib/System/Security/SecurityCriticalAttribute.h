#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
enum class SecurityCriticalScope;
namespace SecurityCriticalAttributeNamespace {
CLASS(SecurityCriticalAttribute) {
  public: SecurityCriticalScope get_Scope() { return Scope; }
  public: void Ctor();
  public: void Ctor(SecurityCriticalScope scope);
  private: SecurityCriticalScope Scope;
};
} // namespace SecurityCriticalAttributeNamespace
using SecurityCriticalAttribute = SecurityCriticalAttributeNamespace::SecurityCriticalAttribute;
} // namespace System::Private::CoreLib::System::Security
