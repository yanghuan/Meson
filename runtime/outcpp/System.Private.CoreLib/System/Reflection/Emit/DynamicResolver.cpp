#include "DynamicResolver-dep.h"

#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidProgramException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicMethod-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicResolver-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/VarArgMethod-dep.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicResolverNamespace {
void DynamicResolver___::DestroyScout___::Finalize() {
  if (!m_methodHandle.IsNullHandle()) {
    if (RuntimeMethodHandle::GetResolver(m_methodHandle) != nullptr) {
      GC::ReRegisterForFinalize((DestroyScout)this);
    } else {
      RuntimeMethodHandle::Destroy(m_methodHandle);
    }
  }
}

void DynamicResolver___::DestroyScout___::ctor() {
}

void DynamicResolver___::ctor(DynamicILGenerator ilGenerator) {
  m_stackSize = ilGenerator->GetMaxStackSize();
  m_exceptions = ilGenerator->GetExceptions();
  m_code = ilGenerator->BakeByteArray();
  m_localSignature = ilGenerator->m_localSignature->InternalGetSignatureArray();
  m_scope = ilGenerator->m_scope;
  m_method = (DynamicMethod)ilGenerator->m_methodBuilder;
  m_method->m_resolver = (DynamicResolver)this;
}

void DynamicResolver___::ctor(DynamicILInfo dynamicILInfo) {
  m_stackSize = dynamicILInfo->get_MaxStackSize();
  m_code = dynamicILInfo->get_Code();
  m_localSignature = dynamicILInfo->get_LocalSignature();
  m_exceptionHeader = dynamicILInfo->get_Exceptions();
  m_scope = dynamicILInfo->get_DynamicScope();
  m_method = dynamicILInfo->get_DynamicMethod();
  m_method->m_resolver = (DynamicResolver)this;
}

void DynamicResolver___::Finalize() {
  DynamicMethod method = m_method;
  if (!(method == nullptr) && method->m_methodHandle != nullptr) {
    DestroyScout destroyScout;
    try {
      destroyScout = rt::newobj<DestroyScout>();
    } catch (...) {
      GC::ReRegisterForFinalize((DynamicResolver)this);
      return;
    }
    destroyScout->m_methodHandle = method->m_methodHandle->get_Value();
  }
}

RuntimeType DynamicResolver___::GetJitContext(Int32& securityControlFlags) {
  SecurityControlFlags securityControlFlags2 = SecurityControlFlags::Default;
  if (m_method->m_restrictedSkipVisibility) {
    securityControlFlags2 |= SecurityControlFlags::RestrictedSkipVisibilityChecks;
  } else if (m_method->m_skipVisibility) {
    securityControlFlags2 |= SecurityControlFlags::SkipVisibilityChecks;
  }

  RuntimeType typeOwner = m_method->m_typeOwner;
  securityControlFlags = (Int32)securityControlFlags2;
  return typeOwner;
}

Int32 DynamicResolver___::CalculateNumberOfExceptions(Array<__ExceptionInfo> excp) {
  Int32 num = 0;
  if (excp == nullptr) {
    return 0;
  }
  for (Int32 i = 0; i < excp->get_Length(); i++) {
    num += excp[i]->GetNumberOfCatches();
  }
  return num;
}

Array<Byte> DynamicResolver___::GetCodeInfo(Int32& stackSize, Int32& initLocals, Int32& EHCount) {
  stackSize = m_stackSize;
  if (m_exceptionHeader != nullptr && m_exceptionHeader->get_Length() != 0) {
    if (m_exceptionHeader->get_Length() < 4) {
      rt::throw_exception<FormatException>();
    }
    Byte b = m_exceptionHeader[0];
    if ((b & 64u) != 0) {
      Int32 num = m_exceptionHeader[3] << 16;
      num |= m_exceptionHeader[2] << 8;
      num |= m_exceptionHeader[1];
      EHCount = (num - 4) / 24;
    } else {
      EHCount = (m_exceptionHeader[1] - 2) / 12;
    }
  } else {
    EHCount = CalculateNumberOfExceptions(m_exceptions);
  }
  initLocals = (m_method->get_InitLocals() ? 1 : 0);
  return m_code;
}

Array<Byte> DynamicResolver___::GetLocalsSignature() {
  return m_localSignature;
}

Array<Byte> DynamicResolver___::GetRawEHInfo() {
  return m_exceptionHeader;
}

void DynamicResolver___::GetEHInfo(Int32 excNumber, void* exc) {
  for (Int32 i = 0; i < m_exceptions->get_Length(); i++) {
    Int32 numberOfCatches = m_exceptions[i]->GetNumberOfCatches();
    if (excNumber < numberOfCatches) {
      ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->Flags = m_exceptions[i]->GetExceptionTypes()[excNumber];
      ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->TryOffset = m_exceptions[i]->GetStartAddress();
      if ((((Resolver::in::CORINFO_EH_CLAUSE*)exc)->Flags & 2) != 2) {
        ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->TryLength = m_exceptions[i]->GetEndAddress() - ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->TryOffset;
      } else {
        ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->TryLength = m_exceptions[i]->GetFinallyEndAddress() - ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->TryOffset;
      }
      ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->HandlerOffset = m_exceptions[i]->GetCatchAddresses()[excNumber];
      ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->HandlerLength = m_exceptions[i]->GetCatchEndAddresses()[excNumber] - ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->HandlerOffset;
      ((Resolver::in::CORINFO_EH_CLAUSE*)exc)->ClassTokenOrFilterOffset = m_exceptions[i]->GetFilterAddresses()[excNumber];
      break;
    }
    excNumber -= numberOfCatches;
  }
}

String DynamicResolver___::GetStringLiteral(Int32 token) {
  return m_scope->GetString(token);
}

void DynamicResolver___::ResolveToken(Int32 token, IntPtr& typeHandle, IntPtr& methodHandle, IntPtr& fieldHandle) {
  typeHandle = rt::default__;
  methodHandle = rt::default__;
  fieldHandle = rt::default__;
  Object obj = m_scope[token];
  if (obj == nullptr) {
    rt::throw_exception<InvalidProgramException>();
  }
  if (rt::is<RuntimeTypeHandle>(obj)) {
    typeHandle = ((RuntimeTypeHandle)obj).get_Value();
    return;
  }
  if (rt::is<RuntimeMethodHandle>(obj)) {
    methodHandle = ((RuntimeMethodHandle)obj).get_Value();
    return;
  }
  if (rt::is<RuntimeFieldHandle>(obj)) {
    fieldHandle = ((RuntimeFieldHandle)obj).get_Value();
    return;
  }
  DynamicMethod dynamicMethod = rt::as<DynamicMethod>(obj);
  if (dynamicMethod != nullptr) {
    methodHandle = dynamicMethod->GetMethodDescriptor().get_Value();
    return;
  }
  GenericMethodInfo genericMethodInfo = rt::as<GenericMethodInfo>(obj);
  if (genericMethodInfo != nullptr) {
    methodHandle = genericMethodInfo->m_methodHandle.get_Value();
    typeHandle = genericMethodInfo->m_context.get_Value();
    return;
  }
  GenericFieldInfo genericFieldInfo = rt::as<GenericFieldInfo>(obj);
  if (genericFieldInfo != nullptr) {
    fieldHandle = genericFieldInfo->m_fieldHandle.get_Value();
    typeHandle = genericFieldInfo->m_context.get_Value();
    return;
  }
  VarArgMethod varArgMethod = rt::as<VarArgMethod>(obj);
  if (varArgMethod != nullptr) {
    if (varArgMethod->m_dynamicMethod == nullptr) {
      methodHandle = varArgMethod->m_method->get_MethodHandle().get_Value();
      typeHandle = varArgMethod->m_method->GetDeclaringTypeInternal()->GetTypeHandleInternal().get_Value();
    } else {
      methodHandle = varArgMethod->m_dynamicMethod->GetMethodDescriptor().get_Value();
    }
  }
}

Array<Byte> DynamicResolver___::ResolveSignature(Int32 token, Int32 fromMethod) {
  return m_scope->ResolveSignature(token, fromMethod);
}

MethodInfo DynamicResolver___::GetDynamicMethod() {
  return m_method->GetMethodInfo();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicResolverNamespace
