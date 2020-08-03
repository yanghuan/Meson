#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace NonSerializedAttributeNamespace {
CLASS(NonSerializedAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace NonSerializedAttributeNamespace
using NonSerializedAttribute = NonSerializedAttributeNamespace::NonSerializedAttribute;
} // namespace System::Private::CoreLib::System
