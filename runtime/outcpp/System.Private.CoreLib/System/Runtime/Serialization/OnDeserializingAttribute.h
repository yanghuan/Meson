#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnDeserializingAttributeNamespace {
CLASS(OnDeserializingAttribute) {
  public: void Ctor();
};
} // namespace OnDeserializingAttributeNamespace
using OnDeserializingAttribute = OnDeserializingAttributeNamespace::OnDeserializingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
