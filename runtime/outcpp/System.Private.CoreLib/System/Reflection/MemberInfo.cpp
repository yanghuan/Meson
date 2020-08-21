#include "MemberInfo-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotImplementedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/MemberInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::MemberInfoNamespace {
Module MemberInfo___::get_Module() {
  Type type = rt::as<Type>((MemberInfo)this);
  if ((Object)type != nullptr) {
    return type->get_Module();
  }
  rt::throw_exception(NotImplemented::get_ByDesign());
}

IEnumerable<CustomAttributeData> MemberInfo___::get_CustomAttributes() {
  return GetCustomAttributesData();
}

Boolean MemberInfo___::get_IsCollectible() {
  return true;
}

Int32 MemberInfo___::get_MetadataToken() {
  rt::throw_exception<InvalidOperationException>();
}

Boolean MemberInfo___::CacheEquals(Object o) {
  rt::throw_exception<NotImplementedException>();
}

void MemberInfo___::ctor() {
}

Boolean MemberInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

IList<CustomAttributeData> MemberInfo___::GetCustomAttributesData() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean MemberInfo___::Equals(Object obj) {
  return Object::in::Equals(obj);
}

Int32 MemberInfo___::GetHashCode() {
  return Object::in::GetHashCode();
}

Boolean MemberInfo___::op_Equality(MemberInfo left, MemberInfo right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  auto& as = left;
  auto& as = as == nullptr ? nullptr : as->Equals(right);
  return as != nullptr ? as : false;
}

Boolean MemberInfo___::op_Inequality(MemberInfo left, MemberInfo right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Reflection::MemberInfoNamespace
