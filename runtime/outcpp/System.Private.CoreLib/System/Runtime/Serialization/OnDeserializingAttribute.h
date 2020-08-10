#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnDeserializingAttributeNamespace {
CLASS(OnDeserializingAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace OnDeserializingAttributeNamespace
using OnDeserializingAttribute = OnDeserializingAttributeNamespace::OnDeserializingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
