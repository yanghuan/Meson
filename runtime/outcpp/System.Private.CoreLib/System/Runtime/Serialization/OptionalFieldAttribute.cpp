#include "OptionalFieldAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::Serialization::OptionalFieldAttributeNamespace {
Int32 OptionalFieldAttribute___::get_VersionAdded() {
  return _versionAdded;
}

void OptionalFieldAttribute___::set_VersionAdded(Int32 value) {
  if (value < 1) {
    rt::throw_exception<ArgumentException>(SR::get_Serialization_OptionalFieldVersionValue());
  }
  _versionAdded = value;
}

void OptionalFieldAttribute___::ctor() {
  _versionAdded = 1;
  Attribute::ctor();
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::OptionalFieldAttributeNamespace
