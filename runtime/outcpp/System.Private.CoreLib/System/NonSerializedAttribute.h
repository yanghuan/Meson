#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace NonSerializedAttributeNamespace {
CLASS(NonSerializedAttribute) {
  public: void Ctor();
};
} // namespace NonSerializedAttributeNamespace
using NonSerializedAttribute = NonSerializedAttributeNamespace::NonSerializedAttribute;
} // namespace System::Private::CoreLib::System
