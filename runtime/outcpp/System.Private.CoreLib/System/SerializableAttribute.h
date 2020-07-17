#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace SerializableAttributeNamespace {
CLASS(SerializableAttribute) {
  public: void Ctor();
};
} // namespace SerializableAttributeNamespace
using SerializableAttribute = SerializableAttributeNamespace::SerializableAttribute;
} // namespace System::Private::CoreLib::System
