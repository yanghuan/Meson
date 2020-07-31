#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OnSerializingAttributeNamespace {
CLASS(OnSerializingAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace OnSerializingAttributeNamespace
using OnSerializingAttribute = OnSerializingAttributeNamespace::OnSerializingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
