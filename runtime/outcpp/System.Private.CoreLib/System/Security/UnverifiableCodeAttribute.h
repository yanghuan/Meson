#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
namespace UnverifiableCodeAttributeNamespace {
CLASS(UnverifiableCodeAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace UnverifiableCodeAttributeNamespace
using UnverifiableCodeAttribute = UnverifiableCodeAttributeNamespace::UnverifiableCodeAttribute;
} // namespace System::Private::CoreLib::System::Security
