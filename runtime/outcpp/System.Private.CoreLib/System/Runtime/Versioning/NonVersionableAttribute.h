#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace NonVersionableAttributeNamespace {
CLASS(NonVersionableAttribute) {
  public: void Ctor();
};
} // namespace NonVersionableAttributeNamespace
using NonVersionableAttribute = NonVersionableAttributeNamespace::NonVersionableAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
