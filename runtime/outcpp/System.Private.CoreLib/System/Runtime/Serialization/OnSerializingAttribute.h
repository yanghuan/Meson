#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnSerializingAttributeNamespace {
CLASS(OnSerializingAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace OnSerializingAttributeNamespace
using OnSerializingAttribute = OnSerializingAttributeNamespace::OnSerializingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
