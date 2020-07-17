#include "DynamicILInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILInfoNamespace {
Array<Byte> DynamicILInfo___::get_LocalSignature() {
  return Array<Byte>();
};

Array<Byte> DynamicILInfo___::get_Exceptions() {
  return Array<Byte>();
};

Array<Byte> DynamicILInfo___::get_Code() {
  return Array<Byte>();
};

Int32 DynamicILInfo___::get_MaxStackSize() {
  return Int32();
};

DynamicMethod DynamicILInfo___::get_DynamicMethod() {
  return nullptr;
};

DynamicScope DynamicILInfo___::get_DynamicScope() {
  return nullptr;
};

void DynamicILInfo___::Ctor(DynamicMethod method, Array<Byte> methodSignature) {
};

void DynamicILInfo___::GetCallableMethod(RuntimeModule module, DynamicMethod dm) {
};

void DynamicILInfo___::SetCode(Array<Byte> code, Int32 maxStackSize) {
};

void DynamicILInfo___::SetCode(Byte* code, Int32 codeSize, Int32 maxStackSize) {
};

void DynamicILInfo___::SetExceptions(Array<Byte> exceptions) {
};

void DynamicILInfo___::SetExceptions(Byte* exceptions, Int32 exceptionsSize) {
};

void DynamicILInfo___::SetLocalSignature(Array<Byte> localSignature) {
};

void DynamicILInfo___::SetLocalSignature(Byte* localSignature, Int32 signatureSize) {
};

Int32 DynamicILInfo___::GetTokenFor(RuntimeMethodHandle method) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(DynamicMethod method) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(RuntimeMethodHandle method, RuntimeTypeHandle contextType) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(RuntimeFieldHandle field) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(RuntimeFieldHandle field, RuntimeTypeHandle contextType) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(RuntimeTypeHandle type) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(String literal) {
  return Int32();
};

Int32 DynamicILInfo___::GetTokenFor(Array<Byte> signature) {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILInfoNamespace
