#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnDeserializedAttributeNamespace {
CLASS(OnDeserializedAttribute) {
  public: void Ctor();
};
} // namespace OnDeserializedAttributeNamespace
using OnDeserializedAttribute = OnDeserializedAttributeNamespace::OnDeserializedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
