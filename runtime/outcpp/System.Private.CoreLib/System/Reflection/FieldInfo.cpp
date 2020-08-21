#include "FieldInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::FieldInfoNamespace {
MemberTypes FieldInfo___::get_MemberType() {
  return MemberTypes::Field;
}

Boolean FieldInfo___::get_IsInitOnly() {
  return (get_Attributes() & FieldAttributes::InitOnly) != 0;
}

Boolean FieldInfo___::get_IsLiteral() {
  return (get_Attributes() & FieldAttributes::Literal) != 0;
}

Boolean FieldInfo___::get_IsNotSerialized() {
  return (get_Attributes() & FieldAttributes::NotSerialized) != 0;
}

Boolean FieldInfo___::get_IsPinvokeImpl() {
  return (get_Attributes() & FieldAttributes::PinvokeImpl) != 0;
}

Boolean FieldInfo___::get_IsSpecialName() {
  return (get_Attributes() & FieldAttributes::SpecialName) != 0;
}

Boolean FieldInfo___::get_IsStatic() {
  return (get_Attributes() & FieldAttributes::Static) != 0;
}

Boolean FieldInfo___::get_IsAssembly() {
  return (get_Attributes() & FieldAttributes::FieldAccessMask) == FieldAttributes::Assembly;
}

Boolean FieldInfo___::get_IsFamily() {
  return (get_Attributes() & FieldAttributes::FieldAccessMask) == FieldAttributes::Family;
}

Boolean FieldInfo___::get_IsFamilyAndAssembly() {
  return (get_Attributes() & FieldAttributes::FieldAccessMask) == FieldAttributes::FamANDAssem;
}

Boolean FieldInfo___::get_IsFamilyOrAssembly() {
  return (get_Attributes() & FieldAttributes::FieldAccessMask) == FieldAttributes::FamORAssem;
}

Boolean FieldInfo___::get_IsPrivate() {
  return (get_Attributes() & FieldAttributes::FieldAccessMask) == FieldAttributes::Private;
}

Boolean FieldInfo___::get_IsPublic() {
  return (get_Attributes() & FieldAttributes::FieldAccessMask) == FieldAttributes::Public;
}

Boolean FieldInfo___::get_IsSecurityCritical() {
  return true;
}

Boolean FieldInfo___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean FieldInfo___::get_IsSecurityTransparent() {
  return false;
}

FieldInfo FieldInfo___::GetFieldFromHandle(RuntimeFieldHandle handle) {
  if (handle.IsNullHandle()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidHandle(), "handle");
  }
  FieldInfo fieldInfo = RuntimeType::in::GetFieldInfo(handle.GetRuntimeFieldInfo());
  Type declaringType = fieldInfo->get_DeclaringType();
  if (declaringType != nullptr && declaringType->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_FieldDeclaringTypeGeneric(), fieldInfo->get_Name(), declaringType->GetGenericTypeDefinition()));
  }
  return fieldInfo;
}

FieldInfo FieldInfo___::GetFieldFromHandle(RuntimeFieldHandle handle, RuntimeTypeHandle declaringType) {
  if (handle.IsNullHandle()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidHandle());
  }
  return RuntimeType::in::GetFieldInfo(declaringType.GetRuntimeType(), handle.GetRuntimeFieldInfo());
}

void FieldInfo___::ctor() {
}

Boolean FieldInfo___::Equals(Object obj) {
  return MemberInfo::in::Equals(obj);
}

Int32 FieldInfo___::GetHashCode() {
  return MemberInfo::in::GetHashCode();
}

Boolean FieldInfo___::op_Equality(FieldInfo left, FieldInfo right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  if ((Object)left != nullptr) {
    return left->Equals(right);
  }
  return false;
}

Boolean FieldInfo___::op_Inequality(FieldInfo left, FieldInfo right) {
  return !(left == right);
}

void FieldInfo___::SetValue(Object obj, Object value) {
  SetValue(obj, value, BindingFlags::Default, Type::in::get_DefaultBinder(), nullptr);
}

void FieldInfo___::SetValueDirect(TypedReference obj, Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_AbstractNonCLS());
}

Object FieldInfo___::GetValueDirect(TypedReference obj) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_AbstractNonCLS());
}

Object FieldInfo___::GetRawConstantValue() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_AbstractNonCLS());
}

Array<Type> FieldInfo___::GetOptionalCustomModifiers() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Type> FieldInfo___::GetRequiredCustomModifiers() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

} // namespace System::Private::CoreLib::System::Reflection::FieldInfoNamespace
