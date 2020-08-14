#include "Associates-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/Associates-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataTokenType.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
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
}

void Associates::AssignAssociates(MetadataImport scope, Int32 mdPropEvent, RuntimeType declaringType, RuntimeType reflectedType, RuntimeMethodInfo& addOn, RuntimeMethodInfo& removeOn, RuntimeMethodInfo& fireOn, RuntimeMethodInfo& getter, RuntimeMethodInfo& setter, Array<MethodInfo>& other, Boolean& composedOfAllPrivateMethods, BindingFlags& bindingFlags) {
  addOn = (removeOn = (fireOn = (getter = (setter = nullptr))));
  Attributes attributes = Attributes::ComposedOfAllVirtualMethods | Attributes::ComposedOfAllPrivateMethods | Attributes::ComposedOfNoPublicMembers | Attributes::ComposedOfNoStaticMembers;
  while (RuntimeTypeHandle::IsGenericVariable(reflectedType)) {
    reflectedType = (RuntimeType)reflectedType->get_BaseType();
  }
  Boolean isInherited = declaringType != reflectedType;
  List<MethodInfo> list = nullptr;
}

} // namespace System::Private::CoreLib::System::Reflection::AssociatesNamespace
