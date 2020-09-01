#include "MethodBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/SymbolStore/ISymbolWriter.h>
#include <System.Private.CoreLib/System/Diagnostics/SymbolStore/SymbolToken-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/ConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/__ExceptionInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EmptyCAHolder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ExceptionHandler-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/LocalSymInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodImplAttributes.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/MethodImplAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DllImportAttribute-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::MethodBuilderNamespace {
using namespace System::Diagnostics::SymbolStore;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

Int32 MethodBuilder___::get_ExceptionHandlerCount() {
  if (m_exceptions == nullptr) {
    return 0;
  }
  return m_exceptions->get_Length();
}

String MethodBuilder___::get_Name() {
  return m_strName;
}

Int32 MethodBuilder___::get_MetadataTokenInternal() {
  return GetToken().get_Token();
}

Module MethodBuilder___::get_Module() {
  return m_containingType->get_Module();
}

Type MethodBuilder___::get_DeclaringType() {
  if (m_containingType->m_isHiddenGlobalType) {
    return nullptr;
  }
  return m_containingType;
}

ICustomAttributeProvider MethodBuilder___::get_ReturnTypeCustomAttributes() {
  return rt::newobj<EmptyCAHolder>();
}

Type MethodBuilder___::get_ReflectedType() {
  return get_DeclaringType();
}

MethodAttributes MethodBuilder___::get_Attributes() {
  return m_iAttributes;
}

CallingConventions MethodBuilder___::get_CallingConvention() {
  return m_callingConvention;
}

RuntimeMethodHandle MethodBuilder___::get_MethodHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Boolean MethodBuilder___::get_IsSecurityCritical() {
  return true;
}

Boolean MethodBuilder___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean MethodBuilder___::get_IsSecurityTransparent() {
  return false;
}

Type MethodBuilder___::get_ReturnType() {
  return m_returnType;
}

ParameterInfo MethodBuilder___::get_ReturnParameter() {
  if (!m_bIsBaked || m_containingType == nullptr || m_containingType->get_BakedRuntimeType() == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TypeNotCreated());
  }
  MethodInfo method = m_containingType->GetMethod(m_strName, m_parameterTypes);
  return method->get_ReturnParameter();
}

Boolean MethodBuilder___::get_IsGenericMethodDefinition() {
  return m_bIsGenMethDef;
}

Boolean MethodBuilder___::get_ContainsGenericParameters() {
  rt::throw_exception<NotSupportedException>();
}

Boolean MethodBuilder___::get_IsGenericMethod() {
  return m_inst != nullptr;
}

Boolean MethodBuilder___::get_InitLocals() {
  ThrowIfGeneric();
  return m_fInitLocals;
}

void MethodBuilder___::set_InitLocals(Boolean value) {
  ThrowIfGeneric();
  m_fInitLocals = value;
}

String MethodBuilder___::get_Signature() {
  return GetMethodSignature()->ToString();
}

void MethodBuilder___::ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, ModuleBuilder mod, TypeBuilder type) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  if (name[0] == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IllegalName(), "name");
  }
  if (mod == nullptr) {
    rt::throw_exception<ArgumentNullException>("mod");
  }
  if (parameterTypes != nullptr) {
    for (Type& left : rt::each(parameterTypes)) {
      if (left == nullptr) {
        rt::throw_exception<ArgumentNullException>("parameterTypes");
      }
    }
  }
  m_strName = name;
  m_module = mod;
  m_containingType = type;
  Type as = returnType;
  m_returnType = (as != nullptr ? as : typeof<void>());
  if ((attributes & MethodAttributes::Static) == 0) {
    callingConvention |= CallingConventions::HasThis;
  } else if ((attributes & MethodAttributes::Virtual) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_NoStaticVirtual());
  }

  m_callingConvention = callingConvention;
  if (parameterTypes != nullptr) {
    m_parameterTypes = rt::newarr<Array<Type>>(parameterTypes->get_Length());
    Array<>::in::Copy(parameterTypes, m_parameterTypes, parameterTypes->get_Length());
  } else {
    m_parameterTypes = nullptr;
  }
  m_returnTypeRequiredCustomModifiers = returnTypeRequiredCustomModifiers;
  m_returnTypeOptionalCustomModifiers = returnTypeOptionalCustomModifiers;
  m_parameterTypeRequiredCustomModifiers = parameterTypeRequiredCustomModifiers;
  m_parameterTypeOptionalCustomModifiers = parameterTypeOptionalCustomModifiers;
  m_iAttributes = attributes;
  m_bIsBaked = false;
  m_fInitLocals = true;
  m_localSymInfo = rt::newobj<LocalSymInfo>();
  m_ubBody = nullptr;
  m_ilGenerator = nullptr;
  m_dwMethodImplFlags = MethodImplAttributes::IL;
}

void MethodBuilder___::CheckContext(Array<Array<Type>> typess) {
  m_module->CheckContext(typess);
}

void MethodBuilder___::CheckContext(Array<Type> types) {
  m_module->CheckContext(types);
}

void MethodBuilder___::CreateMethodBodyHelper(ILGenerator il) {
  if (il == nullptr) {
    rt::throw_exception<ArgumentNullException>("il");
  }
  Int32 num = 0;
  ModuleBuilder module = m_module;
  m_containingType->ThrowIfCreated();
  if (m_bIsBaked) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_MethodHasBody());
  }
  if (il->m_methodBuilder != (MethodBuilder)this && il->m_methodBuilder != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_BadILGeneratorUsage());
  }
  ThrowIfShouldNotHaveBody();
  if (il->m_ScopeTree->m_iOpenScopeCount != 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_OpenLocalVariableScope());
  }
  m_ubBody = il->BakeByteArray();
  m_mdMethodFixups = il->GetTokenFixups();
  Array<__ExceptionInfo> exceptions = il->GetExceptions();
  Int32 num2 = CalculateNumberOfExceptions(exceptions);
  if (num2 > 0) {
    m_exceptions = rt::newarr<Array<ExceptionHandler>>(num2);
    for (Int32 i = 0; i < exceptions->get_Length(); i++) {
      Array<Int32> filterAddresses = exceptions[i]->GetFilterAddresses();
      Array<Int32> catchAddresses = exceptions[i]->GetCatchAddresses();
      Array<Int32> catchEndAddresses = exceptions[i]->GetCatchEndAddresses();
      Array<Type> catchClass = exceptions[i]->GetCatchClass();
      Int32 numberOfCatches = exceptions[i]->GetNumberOfCatches();
      Int32 startAddress = exceptions[i]->GetStartAddress();
      Int32 endAddress = exceptions[i]->GetEndAddress();
      Array<Int32> exceptionTypes = exceptions[i]->GetExceptionTypes();
      for (Int32 j = 0; j < numberOfCatches; j++) {
        Int32 exceptionTypeToken = 0;
        if (catchClass[j] != nullptr) {
          exceptionTypeToken = module->GetTypeTokenInternal(catchClass[j]).get_Token();
        }
        switch (exceptionTypes[j].get()) {
          case 0:
          case 1:
          case 4:
            m_exceptions[num++] = ExceptionHandler(startAddress, endAddress, filterAddresses[j], catchAddresses[j], catchEndAddresses[j], exceptionTypes[j], exceptionTypeToken);
            break;
          case 2:
            m_exceptions[num++] = ExceptionHandler(startAddress, exceptions[i]->GetFinallyEndAddress(), filterAddresses[j], catchAddresses[j], catchEndAddresses[j], exceptionTypes[j], exceptionTypeToken);
            break;
        }
      }
    }
  }
  m_bIsBaked = true;
  if (module->GetSymWriter() != nullptr) {
    SymbolToken method = SymbolToken(get_MetadataTokenInternal());
    ISymbolWriter symWriter = module->GetSymWriter();
    symWriter->OpenMethod(method);
    symWriter->OpenScope(0);
    if (m_localSymInfo != nullptr) {
      m_localSymInfo->EmitLocalSymInfo(symWriter);
    }
    il->m_ScopeTree->EmitScopeTree(symWriter);
    il->m_LineNumberInfo->EmitLineNumberInfo(symWriter);
    symWriter->CloseScope(il->get_ILOffset());
    symWriter->CloseMethod();
  }
}

void MethodBuilder___::ReleaseBakedStructures() {
  if (m_bIsBaked) {
    m_ubBody = nullptr;
    m_localSymInfo = nullptr;
    m_mdMethodFixups = nullptr;
    m_localSignature = nullptr;
    m_exceptions = nullptr;
  }
}

Array<Type> MethodBuilder___::GetParameterTypes() {
  Array<Type> as = m_parameterTypes;
  return as != nullptr ? as : (m_parameterTypes = Array<>::in::Empty<Type>());
}

Type MethodBuilder___::GetMethodBaseReturnType(MethodBase method) {
  MethodInfo methodInfo = rt::as<MethodInfo>(method);
  if ((Object)methodInfo != nullptr) {
    return methodInfo->get_ReturnType();
  }
  ConstructorInfo constructorInfo = rt::as<ConstructorInfo>(method);
  if ((Object)constructorInfo != nullptr) {
    return constructorInfo->GetReturnType();
  }
  return nullptr;
}

void MethodBuilder___::SetToken(MethodToken token) {
  m_tkMethod = token;
}

Array<Byte> MethodBuilder___::GetBody() {
  return m_ubBody;
}

Array<Int32> MethodBuilder___::GetTokenFixups() {
  return m_mdMethodFixups;
}

SignatureHelper MethodBuilder___::GetMethodSignature() {
  if (m_parameterTypes == nullptr) {
    m_parameterTypes = Array<>::in::Empty<Type>();
  }
  m_signature = SignatureHelper::in::GetMethodSigHelper(m_module, m_callingConvention, (m_inst != nullptr) ? m_inst->get_Length() : 0, m_returnType, m_returnTypeRequiredCustomModifiers, m_returnTypeOptionalCustomModifiers, m_parameterTypes, m_parameterTypeRequiredCustomModifiers, m_parameterTypeOptionalCustomModifiers);
  return m_signature;
}

Array<Byte> MethodBuilder___::GetLocalSignature(Int32& signatureLength) {
  if (m_localSignature != nullptr) {
    signatureLength = m_localSignature->get_Length();
    return m_localSignature;
  }
  if (m_ilGenerator != nullptr && m_ilGenerator->m_localCount != 0) {
    return m_ilGenerator->m_localSignature->InternalGetSignature(signatureLength);
  }
  return SignatureHelper::in::GetLocalVarSigHelper(m_module)->InternalGetSignature(signatureLength);
}

Int32 MethodBuilder___::GetMaxStack() {
  if (m_ilGenerator != nullptr) {
    return m_ilGenerator->GetMaxStackSize() + get_ExceptionHandlerCount();
  }
  return 16;
}

Array<ExceptionHandler> MethodBuilder___::GetExceptionHandlers() {
  return m_exceptions;
}

Int32 MethodBuilder___::CalculateNumberOfExceptions(Array<__ExceptionInfo> excp) {
  Int32 num = 0;
  if (excp == nullptr) {
    return 0;
  }
  for (Int32 i = 0; i < excp->get_Length(); i++) {
    num += excp[i]->GetNumberOfCatches();
  }
  return num;
}

Boolean MethodBuilder___::IsTypeCreated() {
  if (m_containingType != nullptr) {
    return m_containingType->IsCreated();
  }
  return false;
}

TypeBuilder MethodBuilder___::GetTypeBuilder() {
  return m_containingType;
}

ModuleBuilder MethodBuilder___::GetModuleBuilder() {
  return m_module;
}

Boolean MethodBuilder___::Equals(Object obj) {
  if (!rt::is<MethodBuilder>(obj)) {
    return false;
  }
  if (!m_strName->Equals(((MethodBuilder)obj)->m_strName)) {
    return false;
  }
  if (m_iAttributes != ((MethodBuilder)obj)->m_iAttributes) {
    return false;
  }
  SignatureHelper methodSignature = ((MethodBuilder)obj)->GetMethodSignature();
  if (methodSignature->Equals(GetMethodSignature())) {
    return true;
  }
  return false;
}

Int32 MethodBuilder___::GetHashCode() {
  return m_strName->GetHashCode();
}

String MethodBuilder___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(1000);
  stringBuilder->Append("Name: ")->Append(m_strName)->AppendLine(" ");
  stringBuilder->Append("Attributes: ")->Append((Int32)m_iAttributes)->AppendLine();
  stringBuilder->Append("Method Signature: ")->Append(GetMethodSignature())->AppendLine();
  stringBuilder->AppendLine();
  return stringBuilder->ToString();
}

Object MethodBuilder___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

MethodImplAttributes MethodBuilder___::GetMethodImplementationFlags() {
  return m_dwMethodImplFlags;
}

MethodInfo MethodBuilder___::GetBaseDefinition() {
  return (MethodBuilder)this;
}

Array<ParameterInfo> MethodBuilder___::GetParameters() {
  if (!m_bIsBaked || m_containingType == nullptr || m_containingType->get_BakedRuntimeType() == nullptr) {
    rt::throw_exception<NotSupportedException>(SR::get_InvalidOperation_TypeNotCreated());
  }
  MethodInfo method = m_containingType->GetMethod(m_strName, m_parameterTypes);
  return method->GetParameters();
}

Array<Object> MethodBuilder___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<Object> MethodBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Boolean MethodBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

MethodInfo MethodBuilder___::GetGenericMethodDefinition() {
  if (!get_IsGenericMethod()) {
    rt::throw_exception<InvalidOperationException>();
  }
  return (MethodBuilder)this;
}

Array<Type> MethodBuilder___::GetGenericArguments() {
  Array<Type> inst = m_inst;
  Array<Type> as = inst;
  return as != nullptr ? as : Array<>::in::Empty<Type>();
}

MethodInfo MethodBuilder___::MakeGenericMethod(Array<Type> typeArguments) {
  return MethodBuilderInstantiation::in::MakeGenericMethod((MethodBuilder)this, typeArguments);
}

Array<GenericTypeParameterBuilder> MethodBuilder___::DefineGenericParameters(Array<String> names) {
  if (names == nullptr) {
    rt::throw_exception<ArgumentNullException>("names");
  }
  if (names->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_EmptyArray(), "names");
  }
  if (m_inst != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_GenericParametersAlreadySet());
  }
  for (Int32 i = 0; i < names->get_Length(); i++) {
    if (names[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("names");
    }
  }
  if (m_tkMethod.get_Token() != 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_MethodBuilderBaked());
  }
  m_bIsGenMethDef = true;
  m_inst = rt::newarr<Array<GenericTypeParameterBuilder>>(names->get_Length());
  for (Int32 j = 0; j < names->get_Length(); j++) {
    m_inst[j] = rt::newobj<GenericTypeParameterBuilder>(rt::newobj<TypeBuilder>(names[j], j, (MethodBuilder)this));
  }
  return m_inst;
}

void MethodBuilder___::ThrowIfGeneric() {
  if (get_IsGenericMethod() && !get_IsGenericMethodDefinition()) {
    rt::throw_exception<InvalidOperationException>();
  }
}

MethodToken MethodBuilder___::GetToken() {
  if (m_tkMethod.get_Token() != 0) {
    return m_tkMethod;
  }
  MethodBuilder methodBuilder = nullptr;
  MethodToken result = MethodToken(0);
  {
    rt::lock(m_containingType->m_listMethods);
    if (m_tkMethod.get_Token() != 0) {
      return m_tkMethod;
    }
    Int32 i;
    for (i = m_containingType->m_lastTokenizedMethod + 1; i < m_containingType->m_listMethods->get_Count(); i++) {
      methodBuilder = m_containingType->m_listMethods[i];
      result = methodBuilder->GetTokenNoLock();
      if (methodBuilder == (MethodBuilder)this) {
        break;
      }
    }
    m_containingType->m_lastTokenizedMethod = i;
    return result;
  }
}

MethodToken MethodBuilder___::GetTokenNoLock() {
  Int32 length;
  Array<Byte> signature = GetMethodSignature()->InternalGetSignature(length);
  ModuleBuilder module = m_module;
  Int32 num = TypeBuilder::in::DefineMethod(QCallModule(module), m_containingType->get_MetadataTokenInternal(), m_strName, signature, length, get_Attributes());
  m_tkMethod = MethodToken(num);
  if (m_inst != nullptr) {
    Array<GenericTypeParameterBuilder> inst = m_inst;
    for (GenericTypeParameterBuilder& genericTypeParameterBuilder : rt::each(inst)) {
      if (!genericTypeParameterBuilder->m_type->IsCreated()) {
        genericTypeParameterBuilder->m_type->CreateType();
      }
    }
  }
  TypeBuilder::in::SetMethodImpl(QCallModule(module), num, m_dwMethodImplFlags);
  return m_tkMethod;
}

void MethodBuilder___::SetParameters(Array<Type> parameterTypes) {
  CheckContext(parameterTypes);
  SetSignature(nullptr, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

void MethodBuilder___::SetReturnType(Type returnType) {
  CheckContext(returnType);
  SetSignature(returnType, nullptr, nullptr, nullptr, nullptr, nullptr);
}

void MethodBuilder___::SetSignature(Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  if (m_tkMethod.get_Token() == 0) {
    CheckContext(returnType);
    CheckContext(rt::newarr<Array<Array<Type>>>(3, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes));
    CheckContext(parameterTypeRequiredCustomModifiers);
    CheckContext(parameterTypeOptionalCustomModifiers);
    ThrowIfGeneric();
    if (returnType != nullptr) {
      m_returnType = returnType;
    }
    if (parameterTypes != nullptr) {
      m_parameterTypes = rt::newarr<Array<Type>>(parameterTypes->get_Length());
      Array<>::in::Copy(parameterTypes, m_parameterTypes, parameterTypes->get_Length());
    }
    m_returnTypeRequiredCustomModifiers = returnTypeRequiredCustomModifiers;
    m_returnTypeOptionalCustomModifiers = returnTypeOptionalCustomModifiers;
    m_parameterTypeRequiredCustomModifiers = parameterTypeRequiredCustomModifiers;
    m_parameterTypeOptionalCustomModifiers = parameterTypeOptionalCustomModifiers;
  }
}

ParameterBuilder MethodBuilder___::DefineParameter(Int32 position, ParameterAttributes attributes, String strParamName) {
  if (position < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_ArgumentOutOfRange_ParamSequence());
  }
  ThrowIfGeneric();
  m_containingType->ThrowIfCreated();
  if (position > 0 && (m_parameterTypes == nullptr || position > m_parameterTypes->get_Length())) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_ArgumentOutOfRange_ParamSequence());
  }
  attributes &= ~(ParameterAttributes::HasDefault | ParameterAttributes::HasFieldMarshal | ParameterAttributes::Reserved3 | ParameterAttributes::Reserved4);
  return rt::newobj<ParameterBuilder>((MethodBuilder)this, position, attributes, strParamName);
}

void MethodBuilder___::SetImplementationFlags(MethodImplAttributes attributes) {
  ThrowIfGeneric();
  m_containingType->ThrowIfCreated();
  m_dwMethodImplFlags = attributes;
  m_canBeRuntimeImpl = true;
  ModuleBuilder module = m_module;
  TypeBuilder::in::SetMethodImpl(QCallModule(module), get_MetadataTokenInternal(), attributes);
}

ILGenerator MethodBuilder___::GetILGenerator() {
  ThrowIfGeneric();
  ThrowIfShouldNotHaveBody();
  ILGenerator as = m_ilGenerator;
  return as != nullptr ? as : (m_ilGenerator = rt::newobj<ILGenerator>((MethodBuilder)this));
}

ILGenerator MethodBuilder___::GetILGenerator(Int32 size) {
  ThrowIfGeneric();
  ThrowIfShouldNotHaveBody();
  ILGenerator as = m_ilGenerator;
  return as != nullptr ? as : (m_ilGenerator = rt::newobj<ILGenerator>((MethodBuilder)this, size));
}

void MethodBuilder___::ThrowIfShouldNotHaveBody() {
  if ((m_dwMethodImplFlags & MethodImplAttributes::CodeTypeMask) != 0 || (m_dwMethodImplFlags & MethodImplAttributes::ManagedMask) != 0 || (m_iAttributes & MethodAttributes::PinvokeImpl) != 0 || m_isDllImport) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ShouldNotHaveMethodBody());
  }
}

Module MethodBuilder___::GetModule() {
  return GetModuleBuilder();
}

void MethodBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if ((Object)con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  ThrowIfGeneric();
  TypeBuilder::in::DefineCustomAttribute(m_module, get_MetadataTokenInternal(), m_module->GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
  if (IsKnownCA(con)) {
    ParseCA(con);
  }
}

void MethodBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  ThrowIfGeneric();
  customBuilder->CreateCustomAttribute(m_module, get_MetadataTokenInternal());
  if (IsKnownCA(customBuilder->m_con)) {
    ParseCA(customBuilder->m_con);
  }
}

Boolean MethodBuilder___::IsKnownCA(ConstructorInfo con) {
  Type declaringType = con->get_DeclaringType();
  if (!(declaringType == typeof<MethodImplAttribute>())) {
    return declaringType == typeof<DllImportAttribute>();
  }
  return true;
}

void MethodBuilder___::ParseCA(ConstructorInfo con) {
  Type declaringType = con->get_DeclaringType();
  if (declaringType == typeof<MethodImplAttribute>()) {
    m_canBeRuntimeImpl = true;
  } else if (declaringType == typeof<DllImportAttribute>()) {
    m_canBeRuntimeImpl = true;
    m_isDllImport = true;
  }

}

} // namespace System::Private::CoreLib::System::Reflection::Emit::MethodBuilderNamespace
