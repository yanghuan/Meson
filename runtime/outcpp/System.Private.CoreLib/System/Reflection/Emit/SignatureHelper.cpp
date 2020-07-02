#include "SignatureHelper-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SignatureHelperNamespace {
Int32 SignatureHelper___::get_ArgumentCount() {
  return Int32();
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, CallingConventions callingConvention, Type returnType, Int32 cGenericParam) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, CallingConventions callingConvention, Type returnType) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSpecSigHelper(Module scope, Array<Type> inst) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(Module scope, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(Module scope, CallingConventions callingConvention, Int32 cGenericParam, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(Module mod, CallingConvention unmanagedCallConv, Type returnType) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetLocalVarSigHelper() {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(CallingConventions callingConvention, Type returnType) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetMethodSigHelper(CallingConvention unmanagedCallingConvention, Type returnType) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetLocalVarSigHelper(Module mod) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetFieldSigHelper(Module mod) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetPropertySigHelper(Module mod, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetPropertySigHelper(Module mod, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetPropertySigHelper(Module mod, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return nullptr;
};
SignatureHelper SignatureHelper___::GetTypeSigToken(Module module, Type type) {
  return nullptr;
};
void SignatureHelper___::Init(Module mod) {
  return void();
};
void SignatureHelper___::Init(Module mod, MdSigCallingConvention callingConvention) {
  return void();
};
void SignatureHelper___::Init(Module mod, MdSigCallingConvention callingConvention, Int32 cGenericParam) {
  return void();
};
void SignatureHelper___::AddOneArgTypeHelper(Type argument, Boolean pinned) {
  return void();
};
void SignatureHelper___::AddOneArgTypeHelper(Type clsArgument, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers) {
  return void();
};
void SignatureHelper___::AddOneArgTypeHelper(Type clsArgument) {
  return void();
};
void SignatureHelper___::AddOneArgTypeHelperWorker(Type clsArgument, Boolean lastWasGenericInst) {
  return void();
};
void SignatureHelper___::AddData(Int32 data) {
  return void();
};
void SignatureHelper___::AddElementType(CorElementType cvt) {
  return void();
};
void SignatureHelper___::AddToken(Int32 token) {
  return void();
};
void SignatureHelper___::InternalAddTypeToken(TypeToken clsToken, CorElementType CorType) {
  return void();
};
void SignatureHelper___::InternalAddRuntimeType(Type type) {
  return void();
};
Array<Byte> SignatureHelper___::ExpandArray(Array<Byte> inArray) {
  return Array<Byte>();
};
Array<Byte> SignatureHelper___::ExpandArray(Array<Byte> inArray, Int32 requiredLength) {
  return Array<Byte>();
};
void SignatureHelper___::IncrementArgCounts() {
  return void();
};
void SignatureHelper___::SetNumberOfSignatureElements(Boolean forceCopy) {
  return void();
};
Boolean SignatureHelper___::IsSimpleType(CorElementType type) {
  return Boolean();
};
Array<Byte> SignatureHelper___::InternalGetSignature(Int32& length) {
  return Array<Byte>();
};
Array<Byte> SignatureHelper___::InternalGetSignatureArray() {
  return Array<Byte>();
};
void SignatureHelper___::AddArgument(Type clsArgument) {
  return void();
};
void SignatureHelper___::AddArgument(Type argument, Boolean pinned) {
  return void();
};
void SignatureHelper___::AddArguments(Array<Type> arguments, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers) {
  return void();
};
void SignatureHelper___::AddArgument(Type argument, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers) {
  return void();
};
void SignatureHelper___::AddSentinel() {
  return void();
};
Boolean SignatureHelper___::Equals(Object obj) {
  return Boolean();
};
Int32 SignatureHelper___::GetHashCode() {
  return Int32();
};
Array<Byte> SignatureHelper___::GetSignature() {
  return Array<Byte>();
};
Array<Byte> SignatureHelper___::GetSignature(Boolean appendEndOfSig) {
  return Array<Byte>();
};
String SignatureHelper___::ToString() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::SignatureHelperNamespace
