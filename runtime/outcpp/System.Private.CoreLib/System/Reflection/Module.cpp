#include "Module-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/InvalidFilterCriteriaException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::ModuleNamespace {
Assembly Module___::get_Assembly() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Module___::get_FullyQualifiedName() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Module___::get_Name() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int32 Module___::get_MDStreamVersion() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Guid Module___::get_ModuleVersionId() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Module___::get_ScopeName() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

ModuleHandle Module___::get_ModuleHandle() {
  return GetModuleHandleImpl();
}

IEnumerable<CustomAttributeData> Module___::get_CustomAttributes() {
  return GetCustomAttributesData();
}

Int32 Module___::get_MetadataToken() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

void Module___::ctor() {
}

ModuleHandle Module___::GetModuleHandleImpl() {
  return ModuleHandle::EmptyHandle;
}

void Module___::GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Module___::IsResource() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Module___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

IList<CustomAttributeData> Module___::GetCustomAttributesData() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Object> Module___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Object> Module___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

MethodInfo Module___::GetMethod(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  return GetMethodImpl(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public, nullptr, CallingConventions::Any, nullptr, nullptr);
}

MethodInfo Module___::GetMethod(String name, Array<Type> types) {
  return GetMethod(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public, nullptr, CallingConventions::Any, types, nullptr);
}

MethodInfo Module___::GetMethod(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (types == nullptr) {
    rt::throw_exception<ArgumentNullException>("types");
  }
  for (Int32 i = 0; i < types->get_Length(); i++) {
    if (types[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("types");
    }
  }
  return GetMethodImpl(name, bindingAttr, binder, callConvention, types, modifiers);
}

MethodInfo Module___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<MethodInfo> Module___::GetMethods() {
  return GetMethods(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<MethodInfo> Module___::GetMethods(BindingFlags bindingFlags) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

FieldInfo Module___::GetField(String name) {
  return GetField(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

FieldInfo Module___::GetField(String name, BindingFlags bindingAttr) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<FieldInfo> Module___::GetFields() {
  return GetFields(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<FieldInfo> Module___::GetFields(BindingFlags bindingFlags) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Type> Module___::GetTypes() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Type Module___::GetType(String className) {
  return GetType(className, false, false);
}

Type Module___::GetType(String className, Boolean ignoreCase) {
  return GetType(className, false, ignoreCase);
}

Type Module___::GetType(String className, Boolean throwOnError, Boolean ignoreCase) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Type> Module___::FindTypes(TypeFilter filter, Object filterCriteria) {
  Array<Type> types = GetTypes();
  Int32 num = 0;
  for (Int32 i = 0; i < types->get_Length(); i++) {
    if (filter != nullptr && !filter(types[i], filterCriteria)) {
      types[i] = nullptr;
    } else {
      num++;
    }
  }
  if (num == types->get_Length()) {
    return types;
  }
  Array<Type> array = rt::newarr<Array<Type>>(num);
  num = 0;
  for (Int32 j = 0; j < types->get_Length(); j++) {
    if (types[j] != nullptr) {
      array[num++] = types[j];
    }
  }
  return array;
}

FieldInfo Module___::ResolveField(Int32 metadataToken) {
  return ResolveField(metadataToken, nullptr, nullptr);
}

FieldInfo Module___::ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

MemberInfo Module___::ResolveMember(Int32 metadataToken) {
  return ResolveMember(metadataToken, nullptr, nullptr);
}

MemberInfo Module___::ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

MethodBase Module___::ResolveMethod(Int32 metadataToken) {
  return ResolveMethod(metadataToken, nullptr, nullptr);
}

MethodBase Module___::ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Byte> Module___::ResolveSignature(Int32 metadataToken) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Module___::ResolveString(Int32 metadataToken) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Type Module___::ResolveType(Int32 metadataToken) {
  return ResolveType(metadataToken, nullptr, nullptr);
}

Type Module___::ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

void Module___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Module___::Equals(Object o) {
  return Object::in::Equals(o);
}

Int32 Module___::GetHashCode() {
  return Object::in::GetHashCode();
}

Boolean Module___::op_Equality(Module left, Module right) {
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

Boolean Module___::op_Inequality(Module left, Module right) {
  return !(left == right);
}

String Module___::ToString() {
  return get_ScopeName();
}

Boolean Module___::FilterTypeNameImpl(Type cls, Object filterCriteria, StringComparison comparison) {
  String text = rt::as<String>(filterCriteria);
  if (text == nullptr) {
    rt::throw_exception<InvalidFilterCriteriaException>(SR::get_InvalidFilterCriteriaException_CritString());
  }
}

void Module___::cctor() {
}

} // namespace System::Private::CoreLib::System::Reflection::ModuleNamespace
