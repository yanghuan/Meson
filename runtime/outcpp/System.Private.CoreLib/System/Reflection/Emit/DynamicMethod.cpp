#include "DynamicMethod-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MulticastDelegate-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilderAccess.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicILGenerator-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicMethod-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EmptyCAHolder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/InternalModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetParameterCountException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/MethodImplAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/Signature-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicMethodNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Text;
using namespace System::Threading;

String DynamicMethod___::RTDynamicMethod___::get_Name() {
  return m_name;
}

Type DynamicMethod___::RTDynamicMethod___::get_DeclaringType() {
  return nullptr;
}

Type DynamicMethod___::RTDynamicMethod___::get_ReflectedType() {
  return nullptr;
}

Module DynamicMethod___::RTDynamicMethod___::get_Module() {
  return m_owner->m_module;
}

RuntimeMethodHandle DynamicMethod___::RTDynamicMethod___::get_MethodHandle() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotAllowedInDynamicMethod());
}

MethodAttributes DynamicMethod___::RTDynamicMethod___::get_Attributes() {
  return m_attributes;
}

CallingConventions DynamicMethod___::RTDynamicMethod___::get_CallingConvention() {
  return m_callingConvention;
}

Boolean DynamicMethod___::RTDynamicMethod___::get_IsSecurityCritical() {
  return m_owner->get_IsSecurityCritical();
}

Boolean DynamicMethod___::RTDynamicMethod___::get_IsSecuritySafeCritical() {
  return m_owner->get_IsSecuritySafeCritical();
}

Boolean DynamicMethod___::RTDynamicMethod___::get_IsSecurityTransparent() {
  return m_owner->get_IsSecurityTransparent();
}

Type DynamicMethod___::RTDynamicMethod___::get_ReturnType() {
  return m_owner->m_returnType;
}

ParameterInfo DynamicMethod___::RTDynamicMethod___::get_ReturnParameter() {
  return rt::newobj<RuntimeParameterInfo>((RTDynamicMethod)this, nullptr, m_owner->m_returnType, -1);
}

ICustomAttributeProvider DynamicMethod___::RTDynamicMethod___::get_ReturnTypeCustomAttributes() {
  return rt::newobj<EmptyCAHolder>();
}

void DynamicMethod___::RTDynamicMethod___::ctor(DynamicMethod owner, String name, MethodAttributes attributes, CallingConventions callingConvention) {
  m_owner = owner;
  m_name = name;
  m_attributes = attributes;
  m_callingConvention = callingConvention;
}

String DynamicMethod___::RTDynamicMethod___::ToString() {
  ValueStringBuilder sbParamList = ValueStringBuilder(100);
  sbParamList.Append(get_ReturnType()->FormatTypeName());
  sbParamList.Append(' ');
  sbParamList.Append(get_Name());
  sbParamList.Append('(');
  MethodBase::in::AppendParameters(sbParamList, GetParameterTypes(), get_CallingConvention());
  sbParamList.Append(')');
  return sbParamList.ToString();
}

MethodInfo DynamicMethod___::RTDynamicMethod___::GetBaseDefinition() {
  return (RTDynamicMethod)this;
}

Array<ParameterInfo> DynamicMethod___::RTDynamicMethod___::GetParameters() {
  Array<ParameterInfo> array = LoadParameters();
  Array<ParameterInfo> array2 = array;
  Array<ParameterInfo> array3 = rt::newarr<Array<ParameterInfo>>(array2->get_Length());
  Array<>::in::Copy(array2, array3, array2->get_Length());
  return array3;
}

MethodImplAttributes DynamicMethod___::RTDynamicMethod___::GetMethodImplementationFlags() {
  return MethodImplAttributes::NoInlining;
}

Object DynamicMethod___::RTDynamicMethod___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeMethodInfo(), "this");
}

Array<Object> DynamicMethod___::RTDynamicMethod___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (attributeType->IsAssignableFrom(typeof<MethodImplAttribute>())) {
    return rt::newarr<Array<Object>>(1);
  }
  return Array<>::in::Empty<Object>();
}

Array<Object> DynamicMethod___::RTDynamicMethod___::GetCustomAttributes(Boolean inherit) {
  return rt::newarr<Array<Object>>(1);
}

Boolean DynamicMethod___::RTDynamicMethod___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (attributeType->IsAssignableFrom(typeof<MethodImplAttribute>())) {
    return true;
  }
  return false;
}

Array<RuntimeParameterInfo> DynamicMethod___::RTDynamicMethod___::LoadParameters() {
  if (m_parameters == nullptr) {
    Array<Type> parameterTypes = m_owner->m_parameterTypes;
    Array<Type> array = parameterTypes;
    Array<RuntimeParameterInfo> array2 = rt::newarr<Array<RuntimeParameterInfo>>(array->get_Length());
    for (Int32 i = 0; i < array->get_Length(); i++) {
      array2[i] = rt::newobj<RuntimeParameterInfo>((RTDynamicMethod)this, nullptr, array[i], i);
    }
    if (m_parameters == nullptr) {
      m_parameters = array2;
    }
  }
  return m_parameters;
}

String DynamicMethod___::get_Name() {
  return m_dynMethod->get_Name();
}

Type DynamicMethod___::get_DeclaringType() {
  return m_dynMethod->get_DeclaringType();
}

Type DynamicMethod___::get_ReflectedType() {
  return m_dynMethod->get_ReflectedType();
}

Module DynamicMethod___::get_Module() {
  return m_dynMethod->get_Module();
}

RuntimeMethodHandle DynamicMethod___::get_MethodHandle() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotAllowedInDynamicMethod());
}

MethodAttributes DynamicMethod___::get_Attributes() {
  return m_dynMethod->get_Attributes();
}

CallingConventions DynamicMethod___::get_CallingConvention() {
  return m_dynMethod->get_CallingConvention();
}

Boolean DynamicMethod___::get_IsSecurityCritical() {
  return true;
}

Boolean DynamicMethod___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean DynamicMethod___::get_IsSecurityTransparent() {
  return false;
}

Type DynamicMethod___::get_ReturnType() {
  return m_dynMethod->get_ReturnType();
}

ParameterInfo DynamicMethod___::get_ReturnParameter() {
  return m_dynMethod->get_ReturnParameter();
}

ICustomAttributeProvider DynamicMethod___::get_ReturnTypeCustomAttributes() {
  return m_dynMethod->get_ReturnTypeCustomAttributes();
}

Boolean DynamicMethod___::get_InitLocals() {
  return m_fInitLocals;
}

void DynamicMethod___::set_InitLocals(Boolean value) {
  m_fInitLocals = value;
}

void DynamicMethod___::ctor(String name, Type returnType, Array<Type> parameterTypes) {
  Init(name, MethodAttributes::Public | MethodAttributes::Static, CallingConventions::Standard, returnType, parameterTypes, nullptr, nullptr, false, true);
}

void DynamicMethod___::ctor(String name, Type returnType, Array<Type> parameterTypes, Boolean restrictedSkipVisibility) {
  Init(name, MethodAttributes::Public | MethodAttributes::Static, CallingConventions::Standard, returnType, parameterTypes, nullptr, nullptr, restrictedSkipVisibility, true);
}

void DynamicMethod___::ctor(String name, Type returnType, Array<Type> parameterTypes, Module m) {
  if (m == nullptr) {
    rt::throw_exception<ArgumentNullException>("m");
  }
  Init(name, MethodAttributes::Public | MethodAttributes::Static, CallingConventions::Standard, returnType, parameterTypes, nullptr, m, false, false);
}

void DynamicMethod___::ctor(String name, Type returnType, Array<Type> parameterTypes, Module m, Boolean skipVisibility) {
  if (m == nullptr) {
    rt::throw_exception<ArgumentNullException>("m");
  }
  Init(name, MethodAttributes::Public | MethodAttributes::Static, CallingConventions::Standard, returnType, parameterTypes, nullptr, m, skipVisibility, false);
}

void DynamicMethod___::ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Module m, Boolean skipVisibility) {
  if (m == nullptr) {
    rt::throw_exception<ArgumentNullException>("m");
  }
  Init(name, attributes, callingConvention, returnType, parameterTypes, nullptr, m, skipVisibility, false);
}

void DynamicMethod___::ctor(String name, Type returnType, Array<Type> parameterTypes, Type owner) {
  if (owner == nullptr) {
    rt::throw_exception<ArgumentNullException>("owner");
  }
  Init(name, MethodAttributes::Public | MethodAttributes::Static, CallingConventions::Standard, returnType, parameterTypes, owner, nullptr, false, false);
}

void DynamicMethod___::ctor(String name, Type returnType, Array<Type> parameterTypes, Type owner, Boolean skipVisibility) {
  if (owner == nullptr) {
    rt::throw_exception<ArgumentNullException>("owner");
  }
  Init(name, MethodAttributes::Public | MethodAttributes::Static, CallingConventions::Standard, returnType, parameterTypes, owner, nullptr, skipVisibility, false);
}

void DynamicMethod___::ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Type owner, Boolean skipVisibility) {
  if (owner == nullptr) {
    rt::throw_exception<ArgumentNullException>("owner");
  }
  Init(name, attributes, callingConvention, returnType, parameterTypes, owner, nullptr, skipVisibility, false);
}

void DynamicMethod___::CheckConsistency(MethodAttributes attributes, CallingConventions callingConvention) {
  if ((attributes & ~MethodAttributes::MemberAccessMask) != MethodAttributes::Static) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicMethodFlags());
  }
  if ((attributes & MethodAttributes::MemberAccessMask) != MethodAttributes::Public) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicMethodFlags());
  }
  if (callingConvention != CallingConventions::Standard && callingConvention != CallingConventions::VarArgs) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicMethodFlags());
  }
  if (callingConvention == CallingConventions::VarArgs) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicMethodFlags());
  }
}

RuntimeModule DynamicMethod___::GetDynamicMethodsModule() {
  if (s_anonymouslyHostedDynamicMethodsModule != nullptr) {
    return s_anonymouslyHostedDynamicMethodsModule;
  }
  {
    rt::lock(s_anonymouslyHostedDynamicMethodsModuleLock);
    if (s_anonymouslyHostedDynamicMethodsModule != nullptr) {
      return s_anonymouslyHostedDynamicMethodsModule;
    }
    AssemblyName name = rt::newobj<AssemblyName>("Anonymously Hosted DynamicMethods Assembly");
    StackCrawlMark stackMark = StackCrawlMark::LookForMe;
    AssemblyBuilder assemblyBuilder = AssemblyBuilder::in::InternalDefineDynamicAssembly(name, AssemblyBuilderAccess::Run, stackMark, nullptr);
    s_anonymouslyHostedDynamicMethodsModule = (InternalModuleBuilder)assemblyBuilder->get_ManifestModule();
  }
  return s_anonymouslyHostedDynamicMethodsModule;
}

void DynamicMethod___::Init(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> signature, Type owner, Module m, Boolean skipVisibility, Boolean transparentMethod) {
  CheckConsistency(attributes, callingConvention);
  if (signature != nullptr) {
    m_parameterTypes = rt::newarr<Array<RuntimeType>>(signature->get_Length());
    for (Int32 i = 0; i < signature->get_Length(); i++) {
      if (signature[i] == nullptr) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidTypeInSignature());
      }
      m_parameterTypes[i] = rt::as<RuntimeType>(signature[i]->get_UnderlyingSystemType());
      if (m_parameterTypes[i] == nullptr || m_parameterTypes[i] == typeof<void>()) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidTypeInSignature());
      }
    }
  } else {
    m_parameterTypes = Array<>::in::Empty<RuntimeType>();
  }
  m_returnType = ((returnType == nullptr) ? ((RuntimeType)typeof<void>()) : (rt::as<RuntimeType>(returnType->get_UnderlyingSystemType())));
  if (m_returnType == nullptr) {
    rt::throw_exception<NotSupportedException>(SR::get_Arg_InvalidTypeInRetType());
  }
  if (transparentMethod) {
    m_module = GetDynamicMethodsModule();
    if (skipVisibility) {
      m_restrictedSkipVisibility = true;
    }
  } else {
    if (m != nullptr) {
      m_module = m->get_ModuleHandle().GetRuntimeModule();
    } else {
      RuntimeType runtimeType = nullptr;
      if (owner != nullptr) {
        runtimeType = rt::as<RuntimeType>(owner->get_UnderlyingSystemType());
      }
      if (runtimeType != nullptr) {
        if (runtimeType->get_HasElementType() || runtimeType->get_ContainsGenericParameters() || runtimeType->get_IsGenericParameter() || runtimeType->get_IsInterface()) {
          rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidTypeForDynamicMethod());
        }
        m_typeOwner = runtimeType;
        m_module = runtimeType->GetRuntimeModule();
      }
    }
    m_skipVisibility = skipVisibility;
  }
  m_ilGenerator = nullptr;
  m_fInitLocals = true;
  m_methodHandle = nullptr;
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  m_dynMethod = rt::newobj<RTDynamicMethod>((DynamicMethod)this, name, attributes, callingConvention);
}

Delegate DynamicMethod___::CreateDelegate(Type delegateType) {
  if (m_restrictedSkipVisibility) {
    GetMethodDescriptor();
    IRuntimeMethodInfo methodHandle = m_methodHandle;
    RuntimeHelpers::_CompileMethod((methodHandle != nullptr) ? methodHandle->get_Value() : RuntimeMethodHandleInternal::get_EmptyHandle());
    GC::KeepAlive(methodHandle);
  }
  MulticastDelegate multicastDelegate = (MulticastDelegate)Delegate::in::CreateDelegateNoSecurityCheck(delegateType, nullptr, GetMethodDescriptor());
  multicastDelegate->StoreDynamicMethod(GetMethodInfo());
  return multicastDelegate;
}

Delegate DynamicMethod___::CreateDelegate(Type delegateType, Object target) {
  if (m_restrictedSkipVisibility) {
    GetMethodDescriptor();
    IRuntimeMethodInfo methodHandle = m_methodHandle;
    RuntimeHelpers::_CompileMethod((methodHandle != nullptr) ? methodHandle->get_Value() : RuntimeMethodHandleInternal::get_EmptyHandle());
    GC::KeepAlive(methodHandle);
  }
  MulticastDelegate multicastDelegate = (MulticastDelegate)Delegate::in::CreateDelegateNoSecurityCheck(delegateType, target, GetMethodDescriptor());
  multicastDelegate->StoreDynamicMethod(GetMethodInfo());
  return multicastDelegate;
}

RuntimeMethodHandle DynamicMethod___::GetMethodDescriptor() {
  if (m_methodHandle == nullptr) {
    {
      rt::lock((DynamicMethod)this);
      if (m_methodHandle == nullptr) {
        if (m_DynamicILInfo != nullptr) {
          m_DynamicILInfo->GetCallableMethod(m_module, (DynamicMethod)this);
        } else {
          if (m_ilGenerator == nullptr || m_ilGenerator->get_ILOffset() == 0) {
            rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_InvalidOperation_BadEmptyMethodBody(), get_Name()));
          }
          m_ilGenerator->GetCallableMethod(m_module, (DynamicMethod)this);
        }
      }
    }
  }
  return RuntimeMethodHandle(m_methodHandle);
}

String DynamicMethod___::ToString() {
  return m_dynMethod->ToString();
}

MethodInfo DynamicMethod___::GetBaseDefinition() {
  return (DynamicMethod)this;
}

Array<ParameterInfo> DynamicMethod___::GetParameters() {
  return m_dynMethod->GetParameters();
}

MethodImplAttributes DynamicMethod___::GetMethodImplementationFlags() {
  return m_dynMethod->GetMethodImplementationFlags();
}

Object DynamicMethod___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  if ((get_CallingConvention() & CallingConventions::VarArgs) == CallingConventions::VarArgs) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_CallToVarArg());
  }
  GetMethodDescriptor();
  Signature signature = rt::newobj<Signature>(m_methodHandle, m_parameterTypes, m_returnType, get_CallingConvention());
  Int32 num = signature->get_Arguments()->get_Length();
  Int32 num2 = ((parameters != nullptr) ? parameters->get_Length() : 0);
  if (num != num2) {
    rt::throw_exception<TargetParameterCountException>(SR::get_Arg_ParmCnt());
  }
  Boolean wrapExceptions = (invokeAttr & BindingFlags::DoNotWrapExceptions) == 0;
  Object result;
  if (num2 > 0) {
    Array<Object> array = CheckArguments(parameters, binder, invokeAttr, culture, signature);
    result = RuntimeMethodHandle::InvokeMethod(nullptr, array, signature, false, wrapExceptions);
    for (Int32 i = 0; i < array->get_Length(); i++) {
      parameters[i] = array[i];
    }
  } else {
    result = RuntimeMethodHandle::InvokeMethod(nullptr, nullptr, signature, false, wrapExceptions);
  }
  GC::KeepAlive((DynamicMethod)this);
  return result;
}

Array<Object> DynamicMethod___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_dynMethod->GetCustomAttributes(attributeType, inherit);
}

Array<Object> DynamicMethod___::GetCustomAttributes(Boolean inherit) {
  return m_dynMethod->GetCustomAttributes(inherit);
}

Boolean DynamicMethod___::IsDefined(Type attributeType, Boolean inherit) {
  return m_dynMethod->IsDefined(attributeType, inherit);
}

ParameterBuilder DynamicMethod___::DefineParameter(Int32 position, ParameterAttributes attributes, String parameterName) {
  if (position < 0 || position > m_parameterTypes->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_ArgumentOutOfRange_ParamSequence());
  }
  position--;
  if (position >= 0) {
    Array<RuntimeParameterInfo> array = m_dynMethod->LoadParameters();
    array[position]->SetName(parameterName);
    array[position]->SetAttributes(attributes);
  }
  return nullptr;
}

DynamicILInfo DynamicMethod___::GetDynamicILInfo() {
  if (m_DynamicILInfo == nullptr) {
    CallingConventions callingConvention = get_CallingConvention();
    Type returnType = get_ReturnType();
    Array<Type> parameterTypes = m_parameterTypes;
    Array<Byte> signature = SignatureHelper::in::GetMethodSigHelper(nullptr, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr)->GetSignature(true);
    m_DynamicILInfo = rt::newobj<DynamicILInfo>((DynamicMethod)this, signature);
  }
  return m_DynamicILInfo;
}

ILGenerator DynamicMethod___::GetILGenerator() {
  return GetILGenerator(64);
}

ILGenerator DynamicMethod___::GetILGenerator(Int32 streamSize) {
  if (m_ilGenerator == nullptr) {
    CallingConventions callingConvention = get_CallingConvention();
    Type returnType = get_ReturnType();
    Array<Type> parameterTypes = m_parameterTypes;
    Array<Byte> signature = SignatureHelper::in::GetMethodSigHelper(nullptr, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr)->GetSignature(true);
    m_ilGenerator = rt::newobj<DynamicILGenerator>((DynamicMethod)this, signature, streamSize);
  }
  return m_ilGenerator;
}

MethodInfo DynamicMethod___::GetMethodInfo() {
  return m_dynMethod;
}

void DynamicMethod___::cctor() {
  s_anonymouslyHostedDynamicMethodsModuleLock = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicMethodNamespace
