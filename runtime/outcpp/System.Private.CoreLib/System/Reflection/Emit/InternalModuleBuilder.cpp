#include "InternalModuleBuilder-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/InternalModuleBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::InternalModuleBuilderNamespace {
void InternalModuleBuilder___::ctor() {
}

Boolean InternalModuleBuilder___::Equals(Object obj) {
  if (obj == nullptr) {
    return false;
  }
  if (rt::is<InternalModuleBuilder>(obj)) {
    return (InternalModuleBuilder)this == obj;
  }
  return obj->Equals((InternalModuleBuilder)this);
}

Int32 InternalModuleBuilder___::GetHashCode() {
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::InternalModuleBuilderNamespace
