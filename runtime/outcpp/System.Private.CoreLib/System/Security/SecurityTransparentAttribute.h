#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
namespace SecurityTransparentAttributeNamespace {
CLASS(SecurityTransparentAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace SecurityTransparentAttributeNamespace
using SecurityTransparentAttribute = SecurityTransparentAttributeNamespace::SecurityTransparentAttribute;
} // namespace System::Private::CoreLib::System::Security
