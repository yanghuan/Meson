#include "Nullable-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>

namespace System::Private::CoreLib::System::NullableNamespace {
Type Nullable<>::GetUnderlyingType(Type nullableType) {
  if ((Object)nullableType == nullptr) {
    rt::throw_exception<ArgumentNullException>("nullableType");
  }
  if (nullableType->get_IsGenericType() && !nullableType->get_IsGenericTypeDefinition()) {
    Type genericTypeDefinition = nullableType->GetGenericTypeDefinition();
    if ((Object)genericTypeDefinition == rt::typeof<Nullable<T>>()) {
      return nullableType->GetGenericArguments()[0];
    }
  }
  return nullptr;
}

} // namespace System::Private::CoreLib::System::NullableNamespace
