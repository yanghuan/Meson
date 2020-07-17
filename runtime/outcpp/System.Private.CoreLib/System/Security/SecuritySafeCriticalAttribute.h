#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
namespace SecuritySafeCriticalAttributeNamespace {
CLASS(SecuritySafeCriticalAttribute) {
  public: void Ctor();
};
} // namespace SecuritySafeCriticalAttributeNamespace
using SecuritySafeCriticalAttribute = SecuritySafeCriticalAttributeNamespace::SecuritySafeCriticalAttribute;
} // namespace System::Private::CoreLib::System::Security
