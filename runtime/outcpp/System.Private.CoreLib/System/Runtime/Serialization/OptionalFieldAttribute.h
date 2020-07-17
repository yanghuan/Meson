#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace OptionalFieldAttributeNamespace {
CLASS(OptionalFieldAttribute) {
  public: Int32 get_VersionAdded();
  public: void set_VersionAdded(Int32 value);
  public: void Ctor();
  private: Int32 _versionAdded;
};
} // namespace OptionalFieldAttributeNamespace
using OptionalFieldAttribute = OptionalFieldAttributeNamespace::OptionalFieldAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
