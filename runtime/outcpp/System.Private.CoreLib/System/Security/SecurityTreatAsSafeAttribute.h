#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
namespace SecurityTreatAsSafeAttributeNamespace {
CLASS(SecurityTreatAsSafeAttribute) {
  public: void Ctor();
};
} // namespace SecurityTreatAsSafeAttributeNamespace
using SecurityTreatAsSafeAttribute = SecurityTreatAsSafeAttributeNamespace::SecurityTreatAsSafeAttribute;
} // namespace System::Private::CoreLib::System::Security
