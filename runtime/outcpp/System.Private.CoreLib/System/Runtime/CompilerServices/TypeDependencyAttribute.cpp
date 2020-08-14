#include "TypeDependencyAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/TypeDependencyAttribute-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::TypeDependencyAttributeNamespace {
void TypeDependencyAttribute___::ctor(String typeName) {
  if (typeName == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeName");
  }
  this->typeName = typeName;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::TypeDependencyAttributeNamespace
