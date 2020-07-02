#include "ILGenerator-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::ILGeneratorNamespace {
Int32 ILGenerator___::get_CurrExcStackCount() {
  return Int32();
};
Array<__ExceptionInfo> ILGenerator___::get_CurrExcStack() {
  return Array<__ExceptionInfo>();
};
Int32 ILGenerator___::get_ILOffset() {
  return Int32();
};
void ILGenerator___::RecordTokenFixup() {
  return void();
};
void ILGenerator___::InternalEmit(OpCode opcode) {
  return void();
};
void ILGenerator___::UpdateStackSize(OpCode opcode, Int32 stackchange) {
  return void();
};
Int32 ILGenerator___::GetMethodToken(MethodBase method, Array<Type> optionalParameterTypes, Boolean useMethodDef) {
  return Int32();
};
SignatureHelper ILGenerator___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  return nullptr;
};
SignatureHelper ILGenerator___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes, Int32 cGenericParameters) {
  return nullptr;
};
Array<Byte> ILGenerator___::BakeByteArray() {
  return Array<Byte>();
};
Array<__ExceptionInfo> ILGenerator___::GetExceptions() {
  return Array<__ExceptionInfo>();
};
void ILGenerator___::EnsureCapacity(Int32 size) {
  return void();
};
void ILGenerator___::IncreaseCapacity(Int32 size) {
  return void();
};
void ILGenerator___::PutInteger4(Int32 value) {
  return void();
};
Int32 ILGenerator___::GetLabelPos(Label lbl) {
  return Int32();
};
void ILGenerator___::AddFixup(Label lbl, Int32 pos, Int32 instSize) {
  return void();
};
Int32 ILGenerator___::GetMaxStackSize() {
  return Int32();
};
void ILGenerator___::SortExceptions(Array<__ExceptionInfo> exceptions) {
  return void();
};
Array<Int32> ILGenerator___::GetTokenFixups() {
  return Array<Int32>();
};
void ILGenerator___::Emit(OpCode opcode) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Byte arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, SByte arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Int16 arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Int32 arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, MethodInfo meth) {
  return void();
};
void ILGenerator___::EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  return void();
};
void ILGenerator___::EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes) {
  return void();
};
void ILGenerator___::EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, SignatureHelper signature) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, ConstructorInfo con) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Type cls) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Int64 arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Single arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Double arg) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Label label) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, Array<Label> labels) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, FieldInfo field) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, String str) {
  return void();
};
void ILGenerator___::Emit(OpCode opcode, LocalBuilder local) {
  return void();
};
Label ILGenerator___::BeginExceptionBlock() {
  return Label();
};
void ILGenerator___::EndExceptionBlock() {
  return void();
};
void ILGenerator___::BeginExceptFilterBlock() {
  return void();
};
void ILGenerator___::BeginCatchBlock(Type exceptionType) {
  return void();
};
void ILGenerator___::BeginFaultBlock() {
  return void();
};
void ILGenerator___::BeginFinallyBlock() {
  return void();
};
Label ILGenerator___::DefineLabel() {
  return Label();
};
void ILGenerator___::MarkLabel(Label loc) {
  return void();
};
void ILGenerator___::ThrowException(Type excType) {
  return void();
};
Type ILGenerator___::GetConsoleType() {
  return nullptr;
};
void ILGenerator___::EmitWriteLine(String value) {
  return void();
};
void ILGenerator___::EmitWriteLine(LocalBuilder localBuilder) {
  return void();
};
void ILGenerator___::EmitWriteLine(FieldInfo fld) {
  return void();
};
LocalBuilder ILGenerator___::DeclareLocal(Type localType) {
  return nullptr;
};
LocalBuilder ILGenerator___::DeclareLocal(Type localType, Boolean pinned) {
  return nullptr;
};
void ILGenerator___::UsingNamespace(String usingNamespace) {
  return void();
};
void ILGenerator___::MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn) {
  return void();
};
void ILGenerator___::BeginScope() {
  return void();
};
void ILGenerator___::EndScope() {
  return void();
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::ILGeneratorNamespace
