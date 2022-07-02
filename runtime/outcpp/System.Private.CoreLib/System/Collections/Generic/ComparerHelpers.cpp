#include "ComparerHelpers-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/ByteEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/EnumComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/EnumEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/GenericComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/GenericEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/NullableComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/NullableEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/ObjectComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/ObjectEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/IComparable.h>
#include <System.Private.CoreLib/System/IEquatable.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::ComparerHelpersNamespace {
Object ComparerHelpers::CreateDefaultComparer(Type type) {
  Object obj = nullptr;
  RuntimeType runtimeType = (RuntimeType)type;
  if (typeof<IComparable<T>>()->MakeGenericType(type)->IsAssignableFrom(type)) {
    obj = RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<GenericComparer<Int32>>(), runtimeType);
  } else if (type->get_IsGenericType()) {
    if (type->GetGenericTypeDefinition() == typeof<Nullable<T>>()) {
      obj = TryCreateNullableComparer(runtimeType);
    }
  } else if (type->get_IsEnum()) {
    obj = TryCreateEnumComparer(runtimeType);
  }


  Object as = obj;
  return as != nullptr ? as : RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<ObjectComparer<Object>>(), runtimeType);
}

Object ComparerHelpers::TryCreateNullableComparer(RuntimeType nullableType) {
  RuntimeType runtimeType = (RuntimeType)nullableType->GetGenericArguments()[0];
  if (typeof<IComparable<T>>()->MakeGenericType(runtimeType)->IsAssignableFrom(runtimeType)) {
    return RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<NullableComparer<Int32>>(), runtimeType);
  }
  return nullptr;
}

Object ComparerHelpers::TryCreateEnumComparer(RuntimeType enumType) {
  TypeCode typeCode = Type::in::GetTypeCode(Enum::in::GetUnderlyingType(enumType));
  if ((UInt32)(typeCode - 5) <= 7u) {
    return RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<EnumComparer<T>>(), enumType);
  }
  return nullptr;
}

Object ComparerHelpers::CreateDefaultEqualityComparer(Type type) {
  Object obj = nullptr;
  RuntimeType runtimeType = (RuntimeType)type;
  if (type == typeof<Byte>()) {
    obj = rt::newobj<ByteEqualityComparer>();
  } else if (type->IsAssignableTo(typeof<IEquatable<T>>()->MakeGenericType(type))) {
    obj = RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<GenericEqualityComparer<Int32>>(), runtimeType);
  } else if (type->get_IsGenericType()) {
    if (type->GetGenericTypeDefinition() == typeof<Nullable<T>>()) {
      obj = TryCreateNullableEqualityComparer(runtimeType);
    }
  } else if (type->get_IsEnum()) {
    obj = TryCreateEnumEqualityComparer(runtimeType);
  }



  Object as = obj;
  return as != nullptr ? as : RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<ObjectEqualityComparer<Object>>(), runtimeType);
}

Object ComparerHelpers::TryCreateNullableEqualityComparer(RuntimeType nullableType) {
  RuntimeType runtimeType = (RuntimeType)nullableType->GetGenericArguments()[0];
  if (typeof<IEquatable<T>>()->MakeGenericType(runtimeType)->IsAssignableFrom(runtimeType)) {
    return RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<NullableEqualityComparer<Int32>>(), runtimeType);
  }
  return nullptr;
}

Object ComparerHelpers::TryCreateEnumEqualityComparer(RuntimeType enumType) {
  TypeCode typeCode = Type::in::GetTypeCode(Enum::in::GetUnderlyingType(enumType));
  if ((UInt32)(typeCode - 5) <= 7u) {
    return RuntimeTypeHandle::CreateInstanceForAnotherGenericParameter((RuntimeType)typeof<EnumEqualityComparer<T>>(), enumType);
  }
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Collections::Generic::ComparerHelpersNamespace
