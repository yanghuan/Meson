#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
namespace SecurityTransparentAttributeNamespace {
CLASS(SecurityTransparentAttribute) {
  public: void Ctor();
};
} // namespace SecurityTransparentAttributeNamespace
using SecurityTransparentAttribute = SecurityTransparentAttributeNamespace::SecurityTransparentAttribute;
} // namespace System::Private::CoreLib::System::Security
