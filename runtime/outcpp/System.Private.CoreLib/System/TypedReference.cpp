#include "TypedReference-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/MissingMemberException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeFieldInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TypedReference-dep.h>

namespace System::Private::CoreLib::System::TypedReferenceNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Reflection;

Boolean TypedReference::get_IsNull() {
  if (Unsafe::IsNullRef(_value.get_Value())) {
    return _type == IntPtr::Zero;
  }
  return false;
}

TypedReference TypedReference::MakeTypedReference(Object target, Array<FieldInfo> flds) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  if (flds == nullptr) {
    rt::throw_exception<ArgumentNullException>("flds");
  }
  if (flds->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayZeroError(), "flds");
  }
  Array<IntPtr> array = rt::newarr<Array<IntPtr>>(flds->get_Length());
  RuntimeType runtimeType = (RuntimeType)target->GetType();
  for (Int32 i = 0; i < flds->get_Length(); i++) {
    RuntimeFieldInfo runtimeFieldInfo = rt::as<RuntimeFieldInfo>(flds[i]);
    if (runtimeFieldInfo == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeFieldInfo());
    }
    if (runtimeFieldInfo->get_IsStatic()) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_TypedReferenceInvalidField(), runtimeFieldInfo->get_Name()));
    }
    if (runtimeType != runtimeFieldInfo->GetDeclaringTypeInternal() && !runtimeType->IsSubclassOf(runtimeFieldInfo->GetDeclaringTypeInternal())) {
      rt::throw_exception<MissingMemberException>(SR::get_MissingMemberTypeRef());
    }
    RuntimeType runtimeType2 = (RuntimeType)runtimeFieldInfo->get_FieldType();
    if (runtimeType2->get_IsPrimitive()) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_TypeRefPrimitve(), runtimeFieldInfo->get_Name()));
    }
    if (i < flds->get_Length() - 1 && !runtimeType2->get_IsValueType()) {
      rt::throw_exception<MissingMemberException>(SR::get_MissingMemberNestErr());
    }
    array[i] = runtimeFieldInfo->get_FieldHandle().get_Value();
    runtimeType = runtimeType2;
  }
  TypedReference result;
  InternalMakeTypedReference(&result, target, array, runtimeType);
  return result;
}

Int32 TypedReference::GetHashCode() {
  if (_type == IntPtr::Zero) {
    return 0;
  }
}

Boolean TypedReference::Equals(Object o) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NYI());
}

Object TypedReference::ToObject(TypedReference value) {
  return InternalToObject(&value);
}

Type TypedReference::GetTargetType(TypedReference value) {
}

RuntimeTypeHandle TypedReference::TargetTypeToken(TypedReference value) {
}

void TypedReference::SetTypedReference(TypedReference target, Object value) {
  rt::throw_exception<NotSupportedException>();
}

} // namespace System::Private::CoreLib::System::TypedReferenceNamespace
