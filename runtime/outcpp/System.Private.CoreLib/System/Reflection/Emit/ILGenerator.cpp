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
};
void ILGenerator___::InternalEmit(OpCode opcode) {
};
void ILGenerator___::UpdateStackSize(OpCode opcode, Int32 stackchange) {
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
};
void ILGenerator___::IncreaseCapacity(Int32 size) {
};
void ILGenerator___::PutInteger4(Int32 value) {
};
Int32 ILGenerator___::GetLabelPos(Label lbl) {
  return Int32();
};
void ILGenerator___::AddFixup(Label lbl, Int32 pos, Int32 instSize) {
};
Int32 ILGenerator___::GetMaxStackSize() {
  return Int32();
};
void ILGenerator___::SortExceptions(Array<__ExceptionInfo> exceptions) {
};
Array<Int32> ILGenerator___::GetTokenFixups() {
  return Array<Int32>();
};
void ILGenerator___::Emit(OpCode opcode) {
};
void ILGenerator___::Emit(OpCode opcode, Byte arg) {
};
void ILGenerator___::Emit(OpCode opcode, SByte arg) {
};
void ILGenerator___::Emit(OpCode opcode, Int16 arg) {
};
void ILGenerator___::Emit(OpCode opcode, Int32 arg) {
};
void ILGenerator___::Emit(OpCode opcode, MethodInfo meth) {
};
void ILGenerator___::EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
};
void ILGenerator___::EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes) {
};
void ILGenerator___::EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes) {
};
void ILGenerator___::Emit(OpCode opcode, SignatureHelper signature) {
};
void ILGenerator___::Emit(OpCode opcode, ConstructorInfo con) {
};
void ILGenerator___::Emit(OpCode opcode, Type cls) {
};
void ILGenerator___::Emit(OpCode opcode, Int64 arg) {
};
void ILGenerator___::Emit(OpCode opcode, Single arg) {
};
void ILGenerator___::Emit(OpCode opcode, Double arg) {
};
void ILGenerator___::Emit(OpCode opcode, Label label) {
};
void ILGenerator___::Emit(OpCode opcode, Array<Label> labels) {
};
void ILGenerator___::Emit(OpCode opcode, FieldInfo field) {
};
void ILGenerator___::Emit(OpCode opcode, String str) {
};
void ILGenerator___::Emit(OpCode opcode, LocalBuilder local) {
};
Label ILGenerator___::BeginExceptionBlock() {
  return Label();
};
void ILGenerator___::EndExceptionBlock() {
};
void ILGenerator___::BeginExceptFilterBlock() {
};
void ILGenerator___::BeginCatchBlock(Type exceptionType) {
};
void ILGenerator___::BeginFaultBlock() {
};
void ILGenerator___::BeginFinallyBlock() {
};
Label ILGenerator___::DefineLabel() {
  return Label();
};
void ILGenerator___::MarkLabel(Label loc) {
};
void ILGenerator___::ThrowException(Type excType) {
};
Type ILGenerator___::GetConsoleType() {
  return nullptr;
};
void ILGenerator___::EmitWriteLine(String value) {
};
void ILGenerator___::EmitWriteLine(LocalBuilder localBuilder) {
};
void ILGenerator___::EmitWriteLine(FieldInfo fld) {
};
LocalBuilder ILGenerator___::DeclareLocal(Type localType) {
  return nullptr;
};
LocalBuilder ILGenerator___::DeclareLocal(Type localType, Boolean pinned) {
  return nullptr;
};
void ILGenerator___::UsingNamespace(String usingNamespace) {
};
void ILGenerator___::MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn) {
};
void ILGenerator___::BeginScope() {
};
void ILGenerator___::EndScope() {
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::ILGeneratorNamespace
