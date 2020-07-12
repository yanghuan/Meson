#include "DynamicILGenerator-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILGeneratorNamespace {
void DynamicILGenerator___::GetCallableMethod(RuntimeModule module, DynamicMethod dm) {
};

LocalBuilder DynamicILGenerator___::DeclareLocal(Type localType, Boolean pinned) {
  return nullptr;
};

void DynamicILGenerator___::Emit(OpCode opcode, MethodInfo meth) {
};

void DynamicILGenerator___::Emit(OpCode opcode, ConstructorInfo con) {
};

void DynamicILGenerator___::Emit(OpCode opcode, Type type) {
};

void DynamicILGenerator___::Emit(OpCode opcode, FieldInfo field) {
};

void DynamicILGenerator___::Emit(OpCode opcode, String str) {
};

void DynamicILGenerator___::EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
};

void DynamicILGenerator___::EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes) {
};

void DynamicILGenerator___::EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes) {
};

void DynamicILGenerator___::Emit(OpCode opcode, SignatureHelper signature) {
};

void DynamicILGenerator___::BeginExceptFilterBlock() {
};

void DynamicILGenerator___::BeginCatchBlock(Type exceptionType) {
};

void DynamicILGenerator___::UsingNamespace(String ns) {
};

void DynamicILGenerator___::MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn) {
};

void DynamicILGenerator___::BeginScope() {
};

void DynamicILGenerator___::EndScope() {
};

Int32 DynamicILGenerator___::GetMemberRefToken(MethodBase methodInfo, Array<Type> optionalParameterTypes) {
  return Int32();
};

SignatureHelper DynamicILGenerator___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  return nullptr;
};

void DynamicILGenerator___::RecordTokenFixup() {
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeType rtType) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeFieldInfo runtimeField) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeFieldInfo runtimeField, RuntimeType rtType) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeConstructorInfo rtMeth) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeConstructorInfo rtMeth, RuntimeType rtType) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeMethodInfo rtMeth) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(RuntimeMethodInfo rtMeth, RuntimeType rtType) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenFor(DynamicMethod dm) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenForVarArgMethod(RuntimeMethodInfo rtMeth, SignatureHelper sig) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenForVarArgMethod(DynamicMethod dm, SignatureHelper sig) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenForString(String s) {
  return Int32();
};

Int32 DynamicILGenerator___::GetTokenForSig(Array<Byte> sig) {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILGeneratorNamespace
