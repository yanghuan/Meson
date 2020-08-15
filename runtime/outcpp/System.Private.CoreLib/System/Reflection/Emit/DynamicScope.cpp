#include "DynamicScope-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicScope-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicScopeNamespace {
using namespace System::Collections::Generic;

Object DynamicScope___::get_Item(Int32 token) {
  token &= 16777215;
  if (token < 0 || token > m_tokens->get_Count()) {
    return nullptr;
  }
  return m_tokens[token];
}

Int32 DynamicScope___::GetTokenFor(VarArgMethod varArgMethod) {
  m_tokens->Add(varArgMethod);
  return (m_tokens->get_Count() - 1) | 167772160;
}

String DynamicScope___::GetString(Int32 token) {
  return rt::as<String>((DynamicScope)this[token]);
}

Array<Byte> DynamicScope___::ResolveSignature(Int32 token, Int32 fromMethod) {
  if (fromMethod == 0) {
    return (Array<Byte>)(DynamicScope)this[token];
  }
  auto& default = (rt::as<VarArgMethod>((DynamicScope)this[token]));
  return default == nullptr ? nullptr : default->m_signature->GetSignature(true);
}

Int32 DynamicScope___::GetTokenFor(RuntimeMethodHandle method) {
  IRuntimeMethodInfo methodInfo = method.GetMethodInfo();
  if (methodInfo != nullptr) {
    RuntimeMethodHandleInternal value = methodInfo->get_Value();
    if (!RuntimeMethodHandle::IsDynamicMethod(value)) {
      RuntimeType declaringType = RuntimeMethodHandle::GetDeclaringType(value);
      if (declaringType != nullptr && RuntimeTypeHandle::HasInstantiation(declaringType)) {
        MethodBase methodBase = RuntimeType::in::GetMethodBase(methodInfo);
        Type genericTypeDefinition = methodBase->get_DeclaringType()->GetGenericTypeDefinition();
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_MethodDeclaringTypeGenericLcg(), methodBase, genericTypeDefinition));
      }
    }
  }
  m_tokens->Add(method);
  return (m_tokens->get_Count() - 1) | 100663296;
}

Int32 DynamicScope___::GetTokenFor(RuntimeMethodHandle method, RuntimeTypeHandle typeContext) {
  m_tokens->Add(rt::newobj<GenericMethodInfo>(method, typeContext));
  return (m_tokens->get_Count() - 1) | 100663296;
}

Int32 DynamicScope___::GetTokenFor(DynamicMethod method) {
  m_tokens->Add(method);
  return (m_tokens->get_Count() - 1) | 100663296;
}

Int32 DynamicScope___::GetTokenFor(RuntimeFieldHandle field) {
  m_tokens->Add(field);
  return (m_tokens->get_Count() - 1) | 67108864;
}

Int32 DynamicScope___::GetTokenFor(RuntimeFieldHandle field, RuntimeTypeHandle typeContext) {
  m_tokens->Add(rt::newobj<GenericFieldInfo>(field, typeContext));
  return (m_tokens->get_Count() - 1) | 67108864;
}

Int32 DynamicScope___::GetTokenFor(RuntimeTypeHandle type) {
  m_tokens->Add(type);
  return (m_tokens->get_Count() - 1) | 33554432;
}

Int32 DynamicScope___::GetTokenFor(String literal) {
  m_tokens->Add(literal);
  return (m_tokens->get_Count() - 1) | 1879048192;
}

Int32 DynamicScope___::GetTokenFor(Array<Byte> signature) {
  m_tokens->Add(signature);
  return (m_tokens->get_Count() - 1) | 285212672;
}

void DynamicScope___::ctor() {
  m_tokens = rt::newobj<List<Object>>();
  Object::ctor();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicScopeNamespace
