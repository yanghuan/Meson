#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace NonVersionableAttributeNamespace {
CLASS(NonVersionableAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace NonVersionableAttributeNamespace
using NonVersionableAttribute = NonVersionableAttributeNamespace::NonVersionableAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
