#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
enum class SecurityCriticalScope : int32_t;
namespace SecurityCriticalAttributeNamespace {
CLASS(SecurityCriticalAttribute) : public Attribute::in {
  public: SecurityCriticalScope get_Scope() { return Scope; }
  public: void ctor();
  public: void ctor(SecurityCriticalScope scope);
  private: SecurityCriticalScope Scope;
};
} // namespace SecurityCriticalAttributeNamespace
using SecurityCriticalAttribute = SecurityCriticalAttributeNamespace::SecurityCriticalAttribute;
} // namespace System::Private::CoreLib::System::Security
