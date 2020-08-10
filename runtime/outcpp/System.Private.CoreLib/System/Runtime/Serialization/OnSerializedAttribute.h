#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnSerializedAttributeNamespace {
CLASS(OnSerializedAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace OnSerializedAttributeNamespace
using OnSerializedAttribute = OnSerializedAttributeNamespace::OnSerializedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
