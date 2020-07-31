#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace SerializableAttributeNamespace {
CLASS(SerializableAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace SerializableAttributeNamespace
using SerializableAttribute = SerializableAttributeNamespace::SerializableAttribute;
} // namespace System::Private::CoreLib::System
