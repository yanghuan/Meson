#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnDeserializedAttributeNamespace {
CLASS(OnDeserializedAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace OnDeserializedAttributeNamespace
using OnDeserializedAttribute = OnDeserializedAttributeNamespace::OnDeserializedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
