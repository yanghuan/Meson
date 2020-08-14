#include "ComparerHelpers-dep.h"

#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::ComparerHelpersNamespace {
Object ComparerHelpers::CreateDefaultComparer(Type type) {
  Object obj = nullptr;
  RuntimeType runtimeType = (RuntimeType)type;
}

Object ComparerHelpers::TryCreateNullableComparer(RuntimeType nullableType) {
  RuntimeType runtimeType = (RuntimeType)nullableType->GetGenericArguments()[0];
}

Object ComparerHelpers::TryCreateEnumComparer(RuntimeType enumType) {
  TypeCode typeCode = Type::in::GetTypeCode(Enum::in::GetUnderlyingType(enumType));
  if ((UInt32)(typeCode - 5) <= 7u) {
  }
  return nullptr;
}

Object ComparerHelpers::CreateDefaultEqualityComparer(Type type) {
  Object obj = nullptr;
  RuntimeType runtimeType = (RuntimeType)type;
}

Object ComparerHelpers::TryCreateNullableEqualityComparer(RuntimeType nullableType) {
  RuntimeType runtimeType = (RuntimeType)nullableType->GetGenericArguments()[0];
}

Object ComparerHelpers::TryCreateEnumEqualityComparer(RuntimeType enumType) {
  TypeCode typeCode = Type::in::GetTypeCode(Enum::in::GetUnderlyingType(enumType));
  if ((UInt32)(typeCode - 5) <= 7u) {
  }
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Collections::Generic::ComparerHelpersNamespace
