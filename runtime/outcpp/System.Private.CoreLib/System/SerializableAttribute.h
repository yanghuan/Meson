#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace SerializableAttributeNamespace {
CLASS(SerializableAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace SerializableAttributeNamespace
using SerializableAttribute = SerializableAttributeNamespace::SerializableAttribute;
} // namespace System::Private::CoreLib::System
