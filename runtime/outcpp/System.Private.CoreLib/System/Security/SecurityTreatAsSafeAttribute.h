#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
namespace SecurityTreatAsSafeAttributeNamespace {
CLASS(SecurityTreatAsSafeAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace SecurityTreatAsSafeAttributeNamespace
using SecurityTreatAsSafeAttribute = SecurityTreatAsSafeAttributeNamespace::SecurityTreatAsSafeAttribute;
} // namespace System::Private::CoreLib::System::Security
