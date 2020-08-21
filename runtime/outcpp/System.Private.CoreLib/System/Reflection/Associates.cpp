#include "Associates-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/Associates-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataEnumResult-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataTokenType.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
#include <System.Private.CoreLib/System/Reflection/MethodSemanticsAttributes.h>
#include <System.Private.CoreLib/System/Reflection/TypeAttributes.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssociatesNamespace {
using namespace System::Collections::Generic;

Boolean Associates::IncludeAccessor(MethodInfo associate, Boolean nonPublic) {
  if ((Object)associate == nullptr) {
    return false;
  }
  if (nonPublic) {
    return true;
  }
  if (associate->get_IsPublic()) {
    return true;
  }
  return false;
}

RuntimeMethodInfo Associates::AssignAssociates(Int32 tkMethod, RuntimeType declaredType, RuntimeType reflectedType) {
  if (MetadataToken::IsNullToken(tkMethod)) {
    return nullptr;
  }
  Boolean flag = declaredType != reflectedType;
  Array<IntPtr> array = nullptr;
  Int32 typeInstCount = 0;
  Array<RuntimeType> instantiationInternal = declaredType->GetTypeHandleInternal().GetInstantiationInternal();
  if (instantiationInternal != nullptr) {
    typeInstCount = instantiationInternal->get_Length();
    array = rt::newarr<Array<IntPtr>>(instantiationInternal->get_Length());
    for (Int32 i = 0; i < instantiationInternal->get_Length(); i++) {
      array[i] = instantiationInternal[i]->GetTypeHandleInternal().get_Value();
    }
  }
  RuntimeMethodHandleInternal runtimeMethodHandleInternal = ModuleHandle::ResolveMethodHandleInternalCore(RuntimeTypeHandle::GetModule(declaredType), tkMethod, array, typeInstCount, nullptr, 0);
  if (flag) {
    MethodAttributes attributes = RuntimeMethodHandle::GetAttributes(runtimeMethodHandleInternal);
    if ((attributes & MethodAttributes::MemberAccessMask) == MethodAttributes::Private) {
      return nullptr;
    }
    if ((attributes & MethodAttributes::Virtual) != 0 && (RuntimeTypeHandle::GetAttributes(declaredType) & TypeAttributes::ClassSemanticsMask) == 0) {
      Int32 slot = RuntimeMethodHandle::GetSlot(runtimeMethodHandleInternal);
      runtimeMethodHandleInternal = RuntimeTypeHandle::GetMethodAt(reflectedType, slot);
    }
  }
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(RuntimeType::in::GetMethodBase(reflectedType, runtimeMethodHandleInternal));
  RuntimeMethodInfo as = runtimeMethodInfo;
  return as != nullptr ? as : (rt::as<RuntimeMethodInfo>(reflectedType->get_Module()->ResolveMethod(tkMethod, nullptr, nullptr)));
}

void Associates::AssignAssociates(MetadataImport scope, Int32 mdPropEvent, RuntimeType declaringType, RuntimeType reflectedType, RuntimeMethodInfo& addOn, RuntimeMethodInfo& removeOn, RuntimeMethodInfo& fireOn, RuntimeMethodInfo& getter, RuntimeMethodInfo& setter, Array<MethodInfo>& other, Boolean& composedOfAllPrivateMethods, BindingFlags& bindingFlags) {
  addOn = (removeOn = (fireOn = (getter = (setter = nullptr))));
  Attributes attributes = Attributes::ComposedOfAllVirtualMethods | Attributes::ComposedOfAllPrivateMethods | Attributes::ComposedOfNoPublicMembers | Attributes::ComposedOfNoStaticMembers;
  while (RuntimeTypeHandle::IsGenericVariable(reflectedType)) {
    reflectedType = (RuntimeType)reflectedType->get_BaseType();
  }
  Boolean isInherited = declaringType != reflectedType;
  List<MethodInfo> list = nullptr;
  MetadataEnumResult result;
  scope.Enum(MetadataTokenType::MethodDef, mdPropEvent, result);
  Int32 num = result.get_Length() / 2;
  for (Int32 i = 0; i < num; i++) {
    Int32 tkMethod = result[i * 2];
    MethodSemanticsAttributes methodSemanticsAttributes = (MethodSemanticsAttributes)result[i * 2 + 1];
    RuntimeMethodInfo runtimeMethodInfo = AssignAssociates(tkMethod, declaringType, reflectedType);
    if (runtimeMethodInfo == nullptr) {
      continue;
    }
    MethodAttributes attributes2 = runtimeMethodInfo->get_Attributes();
    Boolean flag = (attributes2 & MethodAttributes::MemberAccessMask) == MethodAttributes::Private;
    Boolean flag2 = (attributes2 & MethodAttributes::Virtual) != 0;
    MethodAttributes methodAttributes = attributes2 & MethodAttributes::MemberAccessMask;
    Boolean flag3 = methodAttributes == MethodAttributes::Public;
    Boolean flag4 = (attributes2 & MethodAttributes::Static) != 0;
    if (flag3) {
      attributes &= ~Attributes::ComposedOfNoPublicMembers;
      attributes &= ~Attributes::ComposedOfAllPrivateMethods;
    } else if (!flag) {
      attributes &= ~Attributes::ComposedOfAllPrivateMethods;
    }

    if (flag4) {
      attributes &= ~Attributes::ComposedOfNoStaticMembers;
    }
    if (!flag2) {
      attributes &= ~Attributes::ComposedOfAllVirtualMethods;
    }
    switch (methodSemanticsAttributes) {
      case MethodSemanticsAttributes::Setter:
        setter = runtimeMethodInfo;
        continue;
      case MethodSemanticsAttributes::Getter:
        getter = runtimeMethodInfo;
        continue;
      case MethodSemanticsAttributes::Fire:
        fireOn = runtimeMethodInfo;
        continue;
      case MethodSemanticsAttributes::AddOn:
        addOn = runtimeMethodInfo;
        continue;
      case MethodSemanticsAttributes::RemoveOn:
        removeOn = runtimeMethodInfo;
        continue;
    }
    if (list == nullptr) {
      list = rt::newobj<List<MethodInfo>>(num);
    }
    list->Add(runtimeMethodInfo);
  }
  Boolean isPublic = (attributes & Attributes::ComposedOfNoPublicMembers) == 0;
  Boolean isStatic = (attributes & Attributes::ComposedOfNoStaticMembers) == 0;
  bindingFlags = RuntimeType::in::FilterPreCalculate(isPublic, isInherited, isStatic);
  composedOfAllPrivateMethods = ((attributes & Attributes::ComposedOfAllPrivateMethods) != 0);
  other = ((list != nullptr) ? list->ToArray() : nullptr);
}

} // namespace System::Private::CoreLib::System::Reflection::AssociatesNamespace
