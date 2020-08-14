#include "DynamicILGenerator-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicILGenerator-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicResolver-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicScope-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OpCodes-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/StackBehaviour.h>
#include <System.Private.CoreLib/System/Reflection/Emit/VarArgMethod-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILGeneratorNamespace {
void DynamicILGenerator___::ctor(DynamicMethod method, Array<Byte> methodSignature, Int32 size) {
  m_scope = rt::newobj<DynamicScope>();
  m_methodSigToken = m_scope->GetTokenFor(methodSignature);
}

void DynamicILGenerator___::GetCallableMethod(RuntimeModule module, DynamicMethod dm) {
  dm->m_methodHandle = ModuleHandle::GetDynamicMethod(dm, module, m_methodBuilder->get_Name(), (Array<Byte>)m_scope[m_methodSigToken], rt::newobj<DynamicResolver>((DynamicILGenerator)this));
}

LocalBuilder DynamicILGenerator___::DeclareLocal(Type localType, Boolean pinned) {
  if (localType == nullptr) {
    rt::throw_exception<ArgumentNullException>("localType");
  }
  RuntimeType left = rt::as<RuntimeType>(localType);
  if (left == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType());
  }
  LocalBuilder result = rt::newobj<LocalBuilder>(m_localCount, localType, m_methodBuilder);
  m_localSignature->AddArgument(localType, pinned);
  m_localCount++;
  return result;
}

void DynamicILGenerator___::Emit(OpCode opcode, MethodInfo meth) {
  if (meth == nullptr) {
    rt::throw_exception<ArgumentNullException>("meth");
  }
  Int32 num = 0;
  Int32 num2 = 0;
  DynamicMethod dynamicMethod = rt::as<DynamicMethod>(meth);
  if (dynamicMethod == nullptr) {
    RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(meth);
    if (runtimeMethodInfo == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeMethodInfo(), "meth");
    }
    RuntimeType runtimeType = runtimeMethodInfo->GetRuntimeType();
    num2 = ((!(runtimeType != nullptr) || (!runtimeType->get_IsGenericType() && !runtimeType->get_IsArray())) ? GetTokenFor(runtimeMethodInfo) : GetTokenFor(runtimeMethodInfo, runtimeType));
  } else {
    if (opcode.Equals(OpCodes::in::Ldtoken) || opcode.Equals(OpCodes::in::Ldftn) || opcode.Equals(OpCodes::in::Ldvirtftn)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOpCodeOnDynamicMethod());
    }
    num2 = GetTokenFor(dynamicMethod);
  }
  EnsureCapacity(7);
  InternalEmit(opcode);
}

void DynamicILGenerator___::Emit(OpCode opcode, ConstructorInfo con) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  RuntimeConstructorInfo runtimeConstructorInfo = rt::as<RuntimeConstructorInfo>(con);
  if (runtimeConstructorInfo == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeMethodInfo(), "con");
  }
  RuntimeType runtimeType = runtimeConstructorInfo->GetRuntimeType();
  Int32 value = (!(runtimeType != nullptr) || (!runtimeType->get_IsGenericType() && !runtimeType->get_IsArray())) ? GetTokenFor(runtimeConstructorInfo) : GetTokenFor(runtimeConstructorInfo, runtimeType);
  EnsureCapacity(7);
  InternalEmit(opcode);
  UpdateStackSize(opcode, 1);
  PutInteger4(value);
}

void DynamicILGenerator___::Emit(OpCode opcode, Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType());
  }
  Int32 tokenFor = GetTokenFor(runtimeType);
  EnsureCapacity(7);
  InternalEmit(opcode);
  PutInteger4(tokenFor);
}

void DynamicILGenerator___::Emit(OpCode opcode, FieldInfo field) {
  if (field == nullptr) {
    rt::throw_exception<ArgumentNullException>("field");
  }
  RuntimeFieldInfo runtimeFieldInfo = rt::as<RuntimeFieldInfo>(field);
  if (runtimeFieldInfo == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeFieldInfo(), "field");
  }
  Int32 value = (!(field->get_DeclaringType() == nullptr)) ? GetTokenFor(runtimeFieldInfo, runtimeFieldInfo->GetRuntimeType()) : GetTokenFor(runtimeFieldInfo);
  EnsureCapacity(7);
  InternalEmit(opcode);
  PutInteger4(value);
}

void DynamicILGenerator___::Emit(OpCode opcode, String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  Int32 tokenForString = GetTokenForString(str);
  EnsureCapacity(7);
  InternalEmit(opcode);
  PutInteger4(tokenForString);
}

void DynamicILGenerator___::EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  Int32 num = 0;
}

void DynamicILGenerator___::EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes) {
  Int32 num = 0;
  Int32 num2 = 0;
  if (parameterTypes != nullptr) {
    num2 = parameterTypes->get_Length();
  }
  SignatureHelper methodSigHelper = SignatureHelper::in::GetMethodSigHelper(unmanagedCallConv, returnType);
  if (parameterTypes != nullptr) {
    for (Int32 i = 0; i < num2; i++) {
      methodSigHelper->AddArgument(parameterTypes[i]);
    }
  }
}

void DynamicILGenerator___::EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes) {
  if (methodInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("methodInfo");
  }
  if (!opcode.Equals(OpCodes::in::Call) && !opcode.Equals(OpCodes::in::Callvirt) && !opcode.Equals(OpCodes::in::Newobj)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotMethodCallOpcode(), "opcode");
  }
  if (methodInfo->get_ContainsGenericParameters()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_GenericsInvalid(), "methodInfo");
  }
  if (methodInfo->get_DeclaringType() != nullptr && methodInfo->get_DeclaringType()->get_ContainsGenericParameters()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_GenericsInvalid(), "methodInfo");
  }
  Int32 num = 0;
  Int32 memberRefToken = GetMemberRefToken(methodInfo, optionalParameterTypes);
  EnsureCapacity(7);
  InternalEmit(opcode);
}

void DynamicILGenerator___::Emit(OpCode opcode, SignatureHelper signature) {
  if (signature == nullptr) {
    rt::throw_exception<ArgumentNullException>("signature");
  }
  Int32 num = 0;
  EnsureCapacity(7);
  InternalEmit(opcode);
  if (opcode.get_StackBehaviourPop() == StackBehaviour::Varpop) {
    num -= signature->get_ArgumentCount();
    num--;
    UpdateStackSize(opcode, num);
  }
  Int32 tokenForSig = GetTokenForSig(signature->GetSignature(true));
  PutInteger4(tokenForSig);
}

void DynamicILGenerator___::BeginExceptFilterBlock() {
}

void DynamicILGenerator___::BeginCatchBlock(Type exceptionType) {
}

void DynamicILGenerator___::UsingNamespace(String ns) {
  rt::throw_exception<NotSupportedException>(SR::get_InvalidOperation_NotAllowedInDynamicMethod());
}

void DynamicILGenerator___::MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn) {
  rt::throw_exception<NotSupportedException>(SR::get_InvalidOperation_NotAllowedInDynamicMethod());
}

void DynamicILGenerator___::BeginScope() {
  rt::throw_exception<NotSupportedException>(SR::get_InvalidOperation_NotAllowedInDynamicMethod());
}

void DynamicILGenerator___::EndScope() {
  rt::throw_exception<NotSupportedException>(SR::get_InvalidOperation_NotAllowedInDynamicMethod());
}

Int32 DynamicILGenerator___::GetMemberRefToken(MethodBase methodInfo, Array<Type> optionalParameterTypes) {
}

SignatureHelper DynamicILGenerator___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  SignatureHelper methodSigHelper = SignatureHelper::in::GetMethodSigHelper(call, returnType);
  if (parameterTypes != nullptr) {
  }
  if (optionalParameterTypes != nullptr && optionalParameterTypes->get_Length() != 0) {
    methodSigHelper->AddSentinel();
  }
  return methodSigHelper;
}

void DynamicILGenerator___::RecordTokenFixup() {
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeType rtType) {
  return m_scope->GetTokenFor(rtType->get_TypeHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeFieldInfo runtimeField) {
  return m_scope->GetTokenFor(runtimeField->get_FieldHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeFieldInfo runtimeField, RuntimeType rtType) {
  return m_scope->GetTokenFor(runtimeField->get_FieldHandle(), rtType->get_TypeHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeConstructorInfo rtMeth) {
  return m_scope->GetTokenFor(rtMeth->get_MethodHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeConstructorInfo rtMeth, RuntimeType rtType) {
  return m_scope->GetTokenFor(rtMeth->get_MethodHandle(), rtType->get_TypeHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeMethodInfo rtMeth) {
  return m_scope->GetTokenFor(rtMeth->get_MethodHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(RuntimeMethodInfo rtMeth, RuntimeType rtType) {
  return m_scope->GetTokenFor(rtMeth->get_MethodHandle(), rtType->get_TypeHandle());
}

Int32 DynamicILGenerator___::GetTokenFor(DynamicMethod dm) {
  return m_scope->GetTokenFor(dm);
}

Int32 DynamicILGenerator___::GetTokenForVarArgMethod(RuntimeMethodInfo rtMeth, SignatureHelper sig) {
  VarArgMethod varArgMethod = rt::newobj<VarArgMethod>(rtMeth, sig);
  return m_scope->GetTokenFor(varArgMethod);
}

Int32 DynamicILGenerator___::GetTokenForVarArgMethod(DynamicMethod dm, SignatureHelper sig) {
  VarArgMethod varArgMethod = rt::newobj<VarArgMethod>(dm, sig);
  return m_scope->GetTokenFor(varArgMethod);
}

Int32 DynamicILGenerator___::GetTokenForString(String s) {
  return m_scope->GetTokenFor(s);
}

Int32 DynamicILGenerator___::GetTokenForSig(Array<Byte> sig) {
  return m_scope->GetTokenFor(sig);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILGeneratorNamespace
