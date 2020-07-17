#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
namespace UnverifiableCodeAttributeNamespace {
CLASS(UnverifiableCodeAttribute) {
  public: void Ctor();
};
} // namespace UnverifiableCodeAttributeNamespace
using UnverifiableCodeAttribute = UnverifiableCodeAttributeNamespace::UnverifiableCodeAttribute;
} // namespace System::Private::CoreLib::System::Security
