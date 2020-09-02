#include "SignatureHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EnumBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/MdSigCallingConvention.h>
#include <System.Private.CoreLib/System/Reflection/MetadataTokenType.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SignatureHelperNamespace {
using namespace System::Buffers::Binary;
using namespace System::Text;

Int32 SignatureHelper___::get_ArgumentCount() {
  return m_argCount;
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, Type returnType, Array<Type> parameterTypes) {
  return GetMethodSigHelper(mod, CallingConventions::Standard, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, CallingConventions callingConvention, Type returnType, Int32 cGenericParam) {
  return GetMethodSigHelper(mod, callingConvention, cGenericParam, returnType, nullptr, nullptr, nullptr, nullptr, nullptr);
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, CallingConventions callingConvention, Type returnType) {
  return GetMethodSigHelper(mod, callingConvention, returnType, nullptr, nullptr, nullptr, nullptr, nullptr);
}

SignatureHelper SignatureHelper___::GetMethodSpecSigHelper(Module scope, Array<Type> inst) {
  SignatureHelper signatureHelper = rt::newobj<SignatureHelper>(scope, MdSigCallingConvention::GenericInst);
  signatureHelper->AddData(inst->get_Length());
  for (Type&& clsArgument : *inst) {
    signatureHelper->AddArgument(clsArgument);
  }
  return signatureHelper;
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(Module scope, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return GetMethodSigHelper(scope, callingConvention, 0, returnType, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers, parameterTypes, requiredParameterTypeCustomModifiers, optionalParameterTypeCustomModifiers);
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(Module scope, CallingConventions callingConvention, Int32 cGenericParam, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  if (returnType == nullptr) {
    returnType = typeof<void>();
  }
  MdSigCallingConvention mdSigCallingConvention = MdSigCallingConvention::Default;
  if ((callingConvention & CallingConventions::VarArgs) == CallingConventions::VarArgs) {
    mdSigCallingConvention = MdSigCallingConvention::Vararg;
  }
  if (cGenericParam > 0) {
    mdSigCallingConvention |= MdSigCallingConvention::Generic;
  }
  if ((callingConvention & CallingConventions::HasThis) == CallingConventions::HasThis) {
    mdSigCallingConvention |= MdSigCallingConvention::HasThis;
  }
  SignatureHelper signatureHelper = rt::newobj<SignatureHelper>(scope, mdSigCallingConvention, cGenericParam, returnType, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers);
  signatureHelper->AddArguments(parameterTypes, requiredParameterTypeCustomModifiers, optionalParameterTypeCustomModifiers);
  return signatureHelper;
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, CallingConvention unmanagedCallConv, Type returnType) {
  if ((Object)returnType == nullptr) {
    returnType = typeof<void>();
  }
  MdSigCallingConvention callingConvention;
  switch (unmanagedCallConv) {
    case CallingConvention::Cdecl:
      callingConvention = MdSigCallingConvention::C;
      break;
    case CallingConvention::Winapi:
    case CallingConvention::StdCall:
      callingConvention = MdSigCallingConvention::StdCall;
      break;
    case CallingConvention::ThisCall:
      callingConvention = MdSigCallingConvention::ThisCall;
      break;
    case CallingConvention::FastCall:
      callingConvention = MdSigCallingConvention::FastCall;
      break;
    default:
      rt::throw_exception<ArgumentException>(SR::get_Argument_UnknownUnmanagedCallConv(), "unmanagedCallConv");
  }
  return rt::newobj<SignatureHelper>(mod, callingConvention, returnType, nullptr, nullptr);
}

SignatureHelper SignatureHelper___::GetLocalVarSigHelper() {
  return GetLocalVarSigHelper(nullptr);
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(CallingConventions callingConvention, Type returnType) {
  return GetMethodSigHelper(nullptr, callingConvention, returnType);
}

SignatureHelper SignatureHelper___::GetMethodSigHelper(CallingConvention unmanagedCallingConvention, Type returnType) {
  return GetMethodSigHelper(nullptr, unmanagedCallingConvention, returnType);
}

SignatureHelper SignatureHelper___::GetLocalVarSigHelper(Module mod) {
  return rt::newobj<SignatureHelper>(mod, MdSigCallingConvention::LocalSig);
}

SignatureHelper SignatureHelper___::GetFieldSigHelper(Module mod) {
  return rt::newobj<SignatureHelper>(mod, MdSigCallingConvention::Field);
}

SignatureHelper SignatureHelper___::GetPropertySigHelper(Module mod, Type returnType, Array<Type> parameterTypes) {
  return GetPropertySigHelper(mod, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

SignatureHelper SignatureHelper___::GetPropertySigHelper(Module mod, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return GetPropertySigHelper(mod, (CallingConventions)0, returnType, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers, parameterTypes, requiredParameterTypeCustomModifiers, optionalParameterTypeCustomModifiers);
}

SignatureHelper SignatureHelper___::GetPropertySigHelper(Module mod, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  if (returnType == nullptr) {
    returnType = typeof<void>();
  }
  MdSigCallingConvention mdSigCallingConvention = MdSigCallingConvention::Property;
  if ((callingConvention & CallingConventions::HasThis) == CallingConventions::HasThis) {
    mdSigCallingConvention |= MdSigCallingConvention::HasThis;
  }
  SignatureHelper signatureHelper = rt::newobj<SignatureHelper>(mod, mdSigCallingConvention, returnType, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers);
  signatureHelper->AddArguments(parameterTypes, requiredParameterTypeCustomModifiers, optionalParameterTypeCustomModifiers);
  return signatureHelper;
}

SignatureHelper SignatureHelper___::GetTypeSigToken(Module module, Type type) {
  if (module == nullptr) {
    rt::throw_exception<ArgumentNullException>("module");
  }
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  return rt::newobj<SignatureHelper>(module, type);
}

void SignatureHelper___::ctor(Module mod, MdSigCallingConvention callingConvention) {
  Init(mod, callingConvention);
}

void SignatureHelper___::ctor(Module mod, MdSigCallingConvention callingConvention, Int32 cGenericParameters, Type returnType, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers) {
  Init(mod, callingConvention, cGenericParameters);
  if (callingConvention == MdSigCallingConvention::Field) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadFieldSig());
  }
  AddOneArgTypeHelper(returnType, requiredCustomModifiers, optionalCustomModifiers);
}

void SignatureHelper___::ctor(Module mod, MdSigCallingConvention callingConvention, Type returnType, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers) {
}

void SignatureHelper___::ctor(Module mod, Type type) {
  Init(mod);
  AddOneArgTypeHelper(type);
}

void SignatureHelper___::Init(Module mod) {
  m_signature = rt::newarr<Array<Byte>>(32);
  m_currSig = 0;
  m_module = (rt::as<ModuleBuilder>(mod));
  m_argCount = 0;
  m_sigDone = false;
  m_sizeLoc = -1;
  if (m_module == nullptr && mod != nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_NotSupported_MustBeModuleBuilder());
  }
}

void SignatureHelper___::Init(Module mod, MdSigCallingConvention callingConvention) {
  Init(mod, callingConvention, 0);
}

void SignatureHelper___::Init(Module mod, MdSigCallingConvention callingConvention, Int32 cGenericParam) {
  Init(mod);
  AddData((Int32)callingConvention);
  if (callingConvention == MdSigCallingConvention::Field || callingConvention == MdSigCallingConvention::GenericInst) {
    m_sizeLoc = -1;
    return;
  }
  if (cGenericParam > 0) {
    AddData(cGenericParam);
  }
  m_sizeLoc = m_currSig++;
}

void SignatureHelper___::AddOneArgTypeHelper(Type argument, Boolean pinned) {
  if (pinned) {
    AddElementType(CorElementType::ELEMENT_TYPE_PINNED);
  }
  AddOneArgTypeHelper(argument);
}

void SignatureHelper___::AddOneArgTypeHelper(Type clsArgument, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers) {
  if (optionalCustomModifiers != nullptr) {
    for (Type&& type : *optionalCustomModifiers) {
      if (type == nullptr) {
        rt::throw_exception<ArgumentNullException>("optionalCustomModifiers");
      }
      if (type->get_HasElementType()) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_ArraysInvalid(), "optionalCustomModifiers");
      }
      if (type->get_ContainsGenericParameters()) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_GenericsInvalid(), "optionalCustomModifiers");
      }
      AddElementType(CorElementType::ELEMENT_TYPE_CMOD_OPT);
      Int32 token = m_module->GetTypeToken(type).get_Token();
      AddToken(token);
    }
  }
  if (requiredCustomModifiers != nullptr) {
    for (Type&& type2 : *requiredCustomModifiers) {
      if (type2 == nullptr) {
        rt::throw_exception<ArgumentNullException>("requiredCustomModifiers");
      }
      if (type2->get_HasElementType()) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_ArraysInvalid(), "requiredCustomModifiers");
      }
      if (type2->get_ContainsGenericParameters()) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_GenericsInvalid(), "requiredCustomModifiers");
      }
      AddElementType(CorElementType::ELEMENT_TYPE_CMOD_REQD);
      Int32 token2 = m_module->GetTypeToken(type2).get_Token();
      AddToken(token2);
    }
  }
  AddOneArgTypeHelper(clsArgument);
}

void SignatureHelper___::AddOneArgTypeHelper(Type clsArgument) {
  AddOneArgTypeHelperWorker(clsArgument, false);
}

void SignatureHelper___::AddOneArgTypeHelperWorker(Type clsArgument, Boolean lastWasGenericInst) {
  if (clsArgument->get_IsGenericParameter()) {
    if (clsArgument->get_DeclaringMethod() != nullptr) {
      AddElementType(CorElementType::ELEMENT_TYPE_MVAR);
    } else {
      AddElementType(CorElementType::ELEMENT_TYPE_VAR);
    }
    AddData(clsArgument->get_GenericParameterPosition());
    return;
  }
  if (clsArgument->get_IsGenericType() && (!clsArgument->get_IsGenericTypeDefinition() || !lastWasGenericInst)) {
    AddElementType(CorElementType::ELEMENT_TYPE_GENERICINST);
    AddOneArgTypeHelperWorker(clsArgument->GetGenericTypeDefinition(), true);
    Array<Type> genericArguments = clsArgument->GetGenericArguments();
    AddData(genericArguments->get_Length());
    Array<Type> array = genericArguments;
    for (Type&& clsArgument2 : *array) {
      AddOneArgTypeHelper(clsArgument2);
    }
    return;
  }
  if (rt::is<TypeBuilder>(clsArgument)) {
    TypeBuilder typeBuilder = (TypeBuilder)clsArgument;
    TypeToken clsToken = (!typeBuilder->get_Module()->Equals(m_module)) ? m_module->GetTypeToken(clsArgument) : typeBuilder->get_TypeToken();
    if (clsArgument->get_IsValueType()) {
      InternalAddTypeToken(clsToken, CorElementType::ELEMENT_TYPE_VALUETYPE);
    } else {
      InternalAddTypeToken(clsToken, CorElementType::ELEMENT_TYPE_CLASS);
    }
    return;
  }
  if (rt::is<EnumBuilder>(clsArgument)) {
    TypeBuilder typeBuilder2 = ((EnumBuilder)clsArgument)->m_typeBuilder;
    TypeToken clsToken2 = (!typeBuilder2->get_Module()->Equals(m_module)) ? m_module->GetTypeToken(clsArgument) : typeBuilder2->get_TypeToken();
    if (clsArgument->get_IsValueType()) {
      InternalAddTypeToken(clsToken2, CorElementType::ELEMENT_TYPE_VALUETYPE);
    } else {
      InternalAddTypeToken(clsToken2, CorElementType::ELEMENT_TYPE_CLASS);
    }
    return;
  }
  if (clsArgument->get_IsByRef()) {
    AddElementType(CorElementType::ELEMENT_TYPE_BYREF);
    clsArgument = clsArgument->GetElementType();
    AddOneArgTypeHelper(clsArgument);
    return;
  }
  if (clsArgument->get_IsPointer()) {
    AddElementType(CorElementType::ELEMENT_TYPE_PTR);
    AddOneArgTypeHelper(clsArgument->GetElementType());
    return;
  }
  if (clsArgument->get_IsArray()) {
    if (clsArgument->get_IsSZArray()) {
      AddElementType(CorElementType::ELEMENT_TYPE_SZARRAY);
      AddOneArgTypeHelper(clsArgument->GetElementType());
      return;
    }
    AddElementType(CorElementType::ELEMENT_TYPE_ARRAY);
    AddOneArgTypeHelper(clsArgument->GetElementType());
    Int32 arrayRank = clsArgument->GetArrayRank();
    AddData(arrayRank);
    AddData(0);
    AddData(arrayRank);
    for (Int32 j = 0; j < arrayRank; j++) {
      AddData(0);
    }
    return;
  }
  CorElementType corElementType = CorElementType::ELEMENT_TYPE_MAX;
  if (rt::is<RuntimeType>(clsArgument)) {
    corElementType = RuntimeTypeHandle::GetCorElementType((RuntimeType)clsArgument);
    if (corElementType == CorElementType::ELEMENT_TYPE_CLASS) {
      if (clsArgument == typeof<Object>()) {
        corElementType = CorElementType::ELEMENT_TYPE_OBJECT;
      } else if (clsArgument == typeof<String>()) {
        corElementType = CorElementType::ELEMENT_TYPE_STRING;
      }

    }
  }
  if (IsSimpleType(corElementType)) {
    AddElementType(corElementType);
  } else if (m_module == nullptr) {
    InternalAddRuntimeType(clsArgument);
  } else if (clsArgument->get_IsValueType()) {
    InternalAddTypeToken(m_module->GetTypeToken(clsArgument), CorElementType::ELEMENT_TYPE_VALUETYPE);
  } else {
    InternalAddTypeToken(m_module->GetTypeToken(clsArgument), CorElementType::ELEMENT_TYPE_CLASS);
  }


}

void SignatureHelper___::AddData(Int32 data) {
  if (m_currSig + 4 > m_signature->get_Length()) {
    m_signature = ExpandArray(m_signature);
  }
  if (data <= 127) {
    m_signature[m_currSig++] = (Byte)data;
    return;
  }
  if (data <= 16383) {
    BinaryPrimitives::WriteInt16BigEndian(MemoryExtensions::AsSpan(m_signature, m_currSig), (Int16)(data | 32768));
    m_currSig += 2;
    return;
  }
  if (data <= 536870911) {
    BinaryPrimitives::WriteInt32BigEndian(MemoryExtensions::AsSpan(m_signature, m_currSig), (Int32)(data | 3221225472u));
    m_currSig += 4;
    return;
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_LargeInteger());
}

void SignatureHelper___::AddElementType(CorElementType cvt) {
  if (m_currSig + 1 > m_signature->get_Length()) {
    m_signature = ExpandArray(m_signature);
  }
  m_signature[m_currSig++] = (Byte)cvt;
}

void SignatureHelper___::AddToken(Int32 token) {
  Int32 num = token & 16777215;
  MetadataTokenType metadataTokenType = (MetadataTokenType)(token & -16777216);
  if (num > 67108863) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_LargeInteger());
  }
  num <<= 2;
  switch (metadataTokenType) {
    case MetadataTokenType::TypeRef:
      num |= 1;
      break;
    case MetadataTokenType::TypeSpec:
      num |= 2;
      break;
  }
  AddData(num);
}

void SignatureHelper___::InternalAddTypeToken(TypeToken clsToken, CorElementType CorType) {
  AddElementType(CorType);
  AddToken(clsToken.get_Token());
}

void SignatureHelper___::InternalAddRuntimeType(Type type) {
  AddElementType(CorElementType::ELEMENT_TYPE_INTERNAL);
  IntPtr value = type->GetTypeHandleInternal().get_Value();
  if (m_currSig + sizeof(void*) > m_signature->get_Length()) {
    m_signature = ExpandArray(m_signature);
  }
  Byte* ptr = (Byte*)(&value);
  for (Int32 i = 0; i < sizeof(void*); i++) {
    m_signature[m_currSig++] = *(ptr + i);
  }
}

Array<Byte> SignatureHelper___::ExpandArray(Array<Byte> inArray) {
  return ExpandArray(inArray, inArray->get_Length() * 2);
}

Array<Byte> SignatureHelper___::ExpandArray(Array<Byte> inArray, Int32 requiredLength) {
  if (requiredLength < inArray->get_Length()) {
    requiredLength = inArray->get_Length() * 2;
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(requiredLength);
  Buffer::BlockCopy(inArray, 0, array, 0, inArray->get_Length());
  return array;
}

void SignatureHelper___::IncrementArgCounts() {
  if (m_sizeLoc != -1) {
    m_argCount++;
  }
}

void SignatureHelper___::SetNumberOfSignatureElements(Boolean forceCopy) {
  Int32 currSig = m_currSig;
  if (m_sizeLoc != -1) {
    if (m_argCount < 128 && !forceCopy) {
      m_signature[m_sizeLoc] = (Byte)m_argCount;
      return;
    }
    Int32 num = (m_argCount < 128) ? 1 : ((m_argCount >= 16384) ? 4 : 2);
    Array<Byte> array = rt::newarr<Array<Byte>>(m_currSig + num - 1);
    array[0] = m_signature[0];
    Buffer::BlockCopy(m_signature, m_sizeLoc + 1, array, m_sizeLoc + num, currSig - (m_sizeLoc + 1));
    m_signature = array;
    m_currSig = m_sizeLoc;
    AddData(m_argCount);
    m_currSig = currSig + (num - 1);
  }
}

Boolean SignatureHelper___::IsSimpleType(CorElementType type) {
  if ((Int32)type <= 14) {
    return true;
  }
  if (type == CorElementType::ELEMENT_TYPE_TYPEDBYREF || type == CorElementType::ELEMENT_TYPE_I || type == CorElementType::ELEMENT_TYPE_U || type == CorElementType::ELEMENT_TYPE_OBJECT) {
    return true;
  }
  return false;
}

Array<Byte> SignatureHelper___::InternalGetSignature(Int32& length) {
  if (!m_sigDone) {
    m_sigDone = true;
    SetNumberOfSignatureElements(false);
  }
  length = m_currSig;
  return m_signature;
}

Array<Byte> SignatureHelper___::InternalGetSignatureArray() {
  Int32 argCount = m_argCount;
  Int32 currSig = m_currSig;
  Int32 num = currSig;
  num = ((argCount < 127) ? (num + 1) : ((argCount >= 16383) ? (num + 4) : (num + 2)));
  Array<Byte> array = rt::newarr<Array<Byte>>(num);
  Int32 dstOffset = 0;
  array[dstOffset++] = m_signature[0];
  if (argCount <= 127) {
    array[dstOffset++] = (Byte)(argCount & 255);
  } else if (argCount <= 16383) {
    array[dstOffset++] = (Byte)((argCount >> 8) | 128);
    array[dstOffset++] = (Byte)(argCount & 255);
  } else {
    if (argCount > 536870911) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_LargeInteger());
    }
    array[dstOffset++] = (Byte)((argCount >> 24) | 192);
    array[dstOffset++] = (Byte)((argCount >> 16) & 255);
    array[dstOffset++] = (Byte)((argCount >> 8) & 255);
    array[dstOffset++] = (Byte)(argCount & 255);
  }

  Buffer::BlockCopy(m_signature, 2, array, dstOffset, currSig - 2);
  array[num - 1] = 0;
  return array;
}

void SignatureHelper___::AddArgument(Type clsArgument) {
  AddArgument(clsArgument, nullptr, nullptr);
}

void SignatureHelper___::AddArgument(Type argument, Boolean pinned) {
  if (argument == nullptr) {
    rt::throw_exception<ArgumentNullException>("argument");
  }
  IncrementArgCounts();
  AddOneArgTypeHelper(argument, pinned);
}

void SignatureHelper___::AddArguments(Array<Type> arguments, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers) {
  if (requiredCustomModifiers != nullptr && (arguments == nullptr || requiredCustomModifiers->get_Length() != arguments->get_Length())) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_MismatchedArrays(), "requiredCustomModifiers", "arguments"));
  }
  if (optionalCustomModifiers != nullptr && (arguments == nullptr || optionalCustomModifiers->get_Length() != arguments->get_Length())) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_MismatchedArrays(), "optionalCustomModifiers", "arguments"));
  }
  if (arguments != nullptr) {
    for (Int32 i = 0; i < arguments->get_Length(); i++) {
      AddArgument(arguments[i], (requiredCustomModifiers != nullptr) ? requiredCustomModifiers[i] : nullptr, (optionalCustomModifiers != nullptr) ? optionalCustomModifiers[i] : nullptr);
    }
  }
}

void SignatureHelper___::AddArgument(Type argument, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers) {
  if (m_sigDone) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_SigIsFinalized());
  }
  if (argument == nullptr) {
    rt::throw_exception<ArgumentNullException>("argument");
  }
  IncrementArgCounts();
  AddOneArgTypeHelper(argument, requiredCustomModifiers, optionalCustomModifiers);
}

void SignatureHelper___::AddSentinel() {
  AddElementType(CorElementType::ELEMENT_TYPE_SENTINEL);
}

Boolean SignatureHelper___::Equals(Object obj) {
  if (!rt::is<SignatureHelper>(obj)) {
    return false;
  }
  SignatureHelper signatureHelper = (SignatureHelper)obj;
  if (!signatureHelper->m_module->Equals(m_module) || signatureHelper->m_currSig != m_currSig || signatureHelper->m_sizeLoc != m_sizeLoc || signatureHelper->m_sigDone != m_sigDone) {
    return false;
  }
  for (Int32 i = 0; i < m_currSig; i++) {
    if (m_signature[i] != signatureHelper->m_signature[i]) {
      return false;
    }
  }
  return true;
}

Int32 SignatureHelper___::GetHashCode() {
  Int32 num = m_module->GetHashCode() + m_currSig + m_sizeLoc;
  if (m_sigDone) {
    num++;
  }
  for (Int32 i = 0; i < m_currSig; i++) {
    num += m_signature[i].GetHashCode();
  }
  return num;
}

Array<Byte> SignatureHelper___::GetSignature() {
  return GetSignature(false);
}

Array<Byte> SignatureHelper___::GetSignature(Boolean appendEndOfSig) {
  if (!m_sigDone) {
    if (appendEndOfSig) {
      AddElementType(CorElementType::ELEMENT_TYPE_END);
    }
    SetNumberOfSignatureElements(true);
    m_sigDone = true;
  }
  if (m_signature->get_Length() > m_currSig) {
    Array<Byte> array = rt::newarr<Array<Byte>>(m_currSig);
    Array<>::in::Copy(m_signature, array, m_currSig);
    m_signature = array;
  }
  return m_signature;
}

String SignatureHelper___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  stringBuilder->Append("Length: ")->Append(m_currSig)->AppendLine();
  if (m_sizeLoc != -1) {
    stringBuilder->Append("Arguments: ")->Append(m_signature[m_sizeLoc])->AppendLine();
  } else {
    stringBuilder->AppendLine("Field Signature");
  }
  stringBuilder->AppendLine("Signature: ");
  for (Int32 i = 0; i <= m_currSig; i++) {
    stringBuilder->Append(m_signature[i])->Append("  ");
  }
  stringBuilder->AppendLine();
  return stringBuilder->ToString();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SignatureHelperNamespace
