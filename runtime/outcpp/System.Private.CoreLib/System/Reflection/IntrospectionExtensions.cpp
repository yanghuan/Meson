#include "IntrospectionExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/IReflectableType.h>
#include <System.Private.CoreLib/System/Reflection/TypeDelegator-dep.h>

namespace System::Private::CoreLib::System::Reflection::IntrospectionExtensionsNamespace {
TypeInfo IntrospectionExtensions::GetTypeInfo(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  IReflectableType reflectableType = rt::as<IReflectableType>(type);
  if (reflectableType != nullptr) {
    return reflectableType->GetTypeInfo();
  }
  return rt::newobj<TypeDelegator>(type);
}

} // namespace System::Private::CoreLib::System::Reflection::IntrospectionExtensionsNamespace
