#include "ReflectionContext-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/IntrospectionExtensions-dep.h>

namespace System::Private::CoreLib::System::Reflection::ReflectionContextNamespace {
void ReflectionContext___::ctor() {
}

TypeInfo ReflectionContext___::GetTypeForObject(Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  return MapType(IntrospectionExtensions::GetTypeInfo(value->GetType()));
}

} // namespace System::Private::CoreLib::System::Reflection::ReflectionContextNamespace
