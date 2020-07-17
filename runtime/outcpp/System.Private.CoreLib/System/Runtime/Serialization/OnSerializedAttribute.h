#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnSerializedAttributeNamespace {
CLASS(OnSerializedAttribute) {
  public: void Ctor();
};
} // namespace OnSerializedAttributeNamespace
using OnSerializedAttribute = OnSerializedAttributeNamespace::OnSerializedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
