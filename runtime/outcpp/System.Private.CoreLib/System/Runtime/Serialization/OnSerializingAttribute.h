#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnSerializingAttributeNamespace {
CLASS(OnSerializingAttribute) {
  public: void Ctor();
};
} // namespace OnSerializingAttributeNamespace
using OnSerializingAttribute = OnSerializingAttributeNamespace::OnSerializingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
