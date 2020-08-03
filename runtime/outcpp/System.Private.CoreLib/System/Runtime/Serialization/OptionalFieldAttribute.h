#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OptionalFieldAttributeNamespace {
CLASS(OptionalFieldAttribute) : public Attribute::in {
  public: Int32 get_VersionAdded();
  public: void set_VersionAdded(Int32 value);
  public: void Ctor();
  private: Int32 _versionAdded;
};
} // namespace OptionalFieldAttributeNamespace
using OptionalFieldAttribute = OptionalFieldAttributeNamespace::OptionalFieldAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
