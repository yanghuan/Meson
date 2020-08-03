#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
namespace SecuritySafeCriticalAttributeNamespace {
CLASS(SecuritySafeCriticalAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace SecuritySafeCriticalAttributeNamespace
using SecuritySafeCriticalAttribute = SecuritySafeCriticalAttributeNamespace::SecuritySafeCriticalAttribute;
} // namespace System::Private::CoreLib::System::Security
