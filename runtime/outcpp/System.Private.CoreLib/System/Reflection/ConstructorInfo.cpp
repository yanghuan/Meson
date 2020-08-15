#include "ConstructorInfo-dep.h"

#include <System.Private.CoreLib/System/NotImplementedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>

namespace System::Private::CoreLib::System::Reflection::ConstructorInfoNamespace {
MemberTypes ConstructorInfo___::get_MemberType() {
  return MemberTypes::Constructor;
}

Type ConstructorInfo___::GetReturnType() {
  rt::throw_exception<NotImplementedException>();
}

void ConstructorInfo___::ctor() {
}

Object ConstructorInfo___::Invoke(Array<Object> parameters) {
  return Invoke(BindingFlags::Default, nullptr, parameters, nullptr);
}

Boolean ConstructorInfo___::Equals(Object obj) {
  return MethodBase::Equals(obj);
}

Int32 ConstructorInfo___::GetHashCode() {
  return MethodBase::GetHashCode();
}

Boolean ConstructorInfo___::op_Equality(ConstructorInfo left, ConstructorInfo right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  auto& default = left;
  auto& extern = default == nullptr ? nullptr : default->Equals(right);
  return extern != nullptr ? extern : false;
}

Boolean ConstructorInfo___::op_Inequality(ConstructorInfo left, ConstructorInfo right) {
  return !(left == right);
}

void ConstructorInfo___::cctor() {
  ConstructorName = ".ctor";
  TypeConstructorName = ".cctor";
}

} // namespace System::Private::CoreLib::System::Reflection::ConstructorInfoNamespace
