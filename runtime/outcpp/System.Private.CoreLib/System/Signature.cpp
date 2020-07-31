#include "Signature-dep.h"

namespace System::Private::CoreLib::System::SignatureNamespace {
CallingConventions Signature___::get_CallingConvention() {
  return CallingConventions::ExplicitThis;
}

Array<RuntimeType> Signature___::get_Arguments() {
  return Array<RuntimeType>();
}

RuntimeType Signature___::get_ReturnType() {
  return nullptr;
}

RuntimeType Signature___::get_FieldType() {
  return nullptr;
}

void Signature___::Ctor(IRuntimeMethodInfo method, Array<RuntimeType> arguments, RuntimeType returnType, CallingConventions callingConvention) {
}

void Signature___::Ctor(IRuntimeMethodInfo methodHandle, RuntimeType declaringType) {
}

void Signature___::Ctor(IRuntimeFieldInfo fieldHandle, RuntimeType declaringType) {
}

void Signature___::Ctor(void* pCorSig, Int32 cCorSig, RuntimeType declaringType) {
}

} // namespace System::Private::CoreLib::System::SignatureNamespace
